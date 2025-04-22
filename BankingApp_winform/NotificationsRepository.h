#pragma once
#include "Notifications.h"
#include "HandleFile.h"

#ifndef NOTIFICATIONSREPOSITORY_H
#define NOTIFICATIONSREPOSITORY_H
using namespace System;
using namespace System::IO;

public
ref class NotificationsRepository {
  private:
    static array<Notifications ^> ^ notificationsCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;
    static NotificationsRepository() {
        notificationsCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "notifications.dat";
    }
    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime = HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                notificationsCache =
                    HandleFile::ReadArrayFromFile<Notifications ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<Notifications ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return notificationsCache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static void InsertOne(Notifications ^ notifications) {
        try {
            CheckLastUpdateTime();
            if (notificationsCache == nullptr) {
                notificationsCache = gcnew array<Notifications ^>(0);
            }
            array<Notifications ^> ^ newNotificationsCache =
                gcnew array<Notifications ^>(notificationsCache->Length + 1);
            for (int i = 0; i < notificationsCache->Length; i++) {
                newNotificationsCache[i] = notificationsCache[i];
            }
            newNotificationsCache[notificationsCache->Length] = notifications;
            notificationsCache = newNotificationsCache;
            HandleFile::WriteArrayToFile<Notifications ^>(notificationsCache,
                                                          fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }

    static void UpdateById(String ^ id, Notifications^ notification) {
        try {
            CheckLastUpdateTime();
            if (notificationsCache == nullptr) {
                return;
            }
            for (int i = 0; i < notificationsCache->Length; i++) {
                if (notificationsCache[i]->NotificationId == id) {
                    notificationsCache[i] = notification;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<Notifications ^>(notificationsCache,
                                                          fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateById transaction error !!!", ex);
        }
    }

    static void DeleteCache() {
        try {
            notificationsCache = nullptr;
            lastReadTime = DateTime::MinValue;
            fileName = "notifications.dat";
        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteCache error !!!", ex);
        }
    };

};

#endif // !NOTIFICATION
