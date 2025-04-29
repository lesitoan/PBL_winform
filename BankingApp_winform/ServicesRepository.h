#pragma once
#include "HandleFile.h"
#include "Services.h"
#include "BaseRepository.h"

#ifndef SERVICESREPOSITORY_H
#define SERVICESREPOSITORY_H
using namespace System;
using namespace System::IO;


//public
//ref class ServicesRepository : public BaseRepository<Services ^> {
// private:
//   static ServicesRepository() {
//       BaseRepository::InitializeRepository("services.dat");
//   }
//
// public:
//   static Services ^ FindServiceByName(String ^ name) {
//       try {
//           CheckLastUpdateTime();
//           if (cache == nullptr) {
//               return nullptr;
//           }
//
//           for (int i = 0; i < cache->Length; i++) {
//               if (cache[i]->Name->ToLower() == name->ToLower()) {
//                   return cache[i];
//               }
//           }
//           return nullptr;
//       } catch (Exception ^ ex) {
//           throw gcnew Exception("FindServiceByName error !!!", ex);
//       }
//   }
//};

public
ref class ServicesRepository {
  private:
    static array<Services ^> ^ servicesCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;

    static ServicesRepository() {
        servicesCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "services.dat";
    }

    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime = HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                servicesCache = HandleFile::ReadArrayFromFile<Services ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<Services ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return servicesCache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

        static void DeleteById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (servicesCache == nullptr) {
                return;
            }
            List<Services ^> ^ servicesList = gcnew List<Services ^>();
            for (int i = 0; i < servicesCache->Length; i++) {
                if (servicesCache[i]->Id != id) {
                    servicesList->Add(servicesCache[i]);
                }
            }
            if (servicesList->Count == servicesCache->Length) {
                return;
            }

            servicesCache = servicesList->ToArray();
            HandleFile::WriteArrayToFile<Services ^>(servicesCache, fileName);

        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteById error !!!", ex);
        }
    }

    static Services ^ FindServiceByName(String ^ name) {
        try {
            CheckLastUpdateTime();
            if (servicesCache == nullptr) {
                return nullptr;
            }

            for (int i = 0; i < servicesCache->Length; i++) {
                if (servicesCache[i]->Name->ToLower() == name->ToLower()) {
                    return servicesCache[i];
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
            if (servicesCache == nullptr) {
                servicesCache = gcnew array<Services ^>(1);
                servicesCache[0] = service;
            } else {
                array<Services ^> ^ newServices =
                    gcnew array<Services ^>(servicesCache->Length + 1);
                for (int i = 0; i < servicesCache->Length; i++) {
                    newServices[i] = servicesCache[i];
                }
                newServices[servicesCache->Length] = service;
                servicesCache = newServices;
            }
            HandleFile::WriteArrayToFile<Services ^>(servicesCache, fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertService error !!!", ex);
        }
    }

    static void DeleteCache() {
        try {
            servicesCache = nullptr;
            lastReadTime = DateTime::MinValue;
            fileName = "services.dat";
        } catch (Exception ^ ex) {
            throw gcnew Exception("Logout error !!!", ex);
        }
    }
};

#endif // SERVICESREPOSITORY_H

