#pragma once
#include "Notifications.h"
#include "HandleFile.h"
#include "BaseRepository.h"
#include "ENV.h"


#ifndef NOTIFICATIONSREPOSITORY_H
#define NOTIFICATIONSREPOSITORY_H
using namespace System;
using namespace System::IO;

public
ref class NotificationsRepository : public BaseRepository<Notifications ^> {
  private:
    static NotificationsRepository() {
        InitializeRepository(ENV::NOTIFICATION_FILE);
    }

  public:
    static array<Notifications ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return cache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static void InsertOne(Notifications ^ notifications) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                cache = gcnew array<Notifications ^>(0);
            }
            array<Notifications ^> ^ newcache =
                gcnew array<Notifications ^>(cache->Length + 1);
            for (int i = 0; i < cache->Length; i++) {
                newcache[i] = cache[i];
            }
            newcache[cache->Length] = notifications;
            cache = newcache;
            HandleFile::WriteArrayToFile<Notifications ^>(cache,
                                                          fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }

    static void UpdateById(String ^ id, Notifications^ notification) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id == id) {
                    cache[i] = notification;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<Notifications ^>(cache,
                                                          fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateById transaction error !!!", ex);
        }
    }

};

#endif // !NOTIFICATION
