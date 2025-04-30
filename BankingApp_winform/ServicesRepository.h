#pragma once
#include "BaseRepository.h"
#include "HandleFile.h"
#include "Services.h"
#include "ENV.h"

#ifndef SERVICESREPOSITORY_H
#define SERVICESREPOSITORY_H
using namespace System;
using namespace System::IO;

public
ref class ServicesRepository : public BaseRepository<Services ^> {
  private:
    static ServicesRepository() {
        InitializeRepository(ENV::SERVICE_FILE);
    }

  public:
    static array<Services ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return cache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    } static void DeleteById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }
            List<Services ^> ^ servicesList = gcnew List<Services ^>();
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id != id) {
                    servicesList->Add(cache[i]);
                }
            }
            if (servicesList->Count == cache->Length) {
                return;
            }

            cache = servicesList->ToArray();
            HandleFile::WriteArrayToFile<Services ^>(cache, fileName);

        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteById error !!!", ex);
        }
    }

    static Services ^ FindServiceByName(String ^ name) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return nullptr;
            }

            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Name->ToLower() == name->ToLower()) {
                    return cache[i];
                }
            }
            return nullptr;
        } catch (Exception ^ ex) {
            throw gcnew Exception("FindServiceByName error !!!", ex);
        }
    }

        static void InsertService(Services ^ service) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                cache = gcnew array<Services ^>(1);
                cache[0] = service;
            } else {
                array<Services ^> ^ newServices =
                    gcnew array<Services ^>(cache->Length + 1);
                for (int i = 0; i < cache->Length; i++) {
                    newServices[i] = cache[i];
                }
                newServices[cache->Length] = service;
                cache = newServices;
            }
            HandleFile::WriteArrayToFile<Services ^>(cache, fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertService error !!!", ex);
        }
    }
};

#endif // SERVICESREPOSITORY_H
