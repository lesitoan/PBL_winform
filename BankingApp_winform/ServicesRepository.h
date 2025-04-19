#pragma once
#include "HandleFile.h"
#include "Services.h"

#ifndef SERVICESREPOSITORY_H
#define SERVICESREPOSITORY_H
using namespace System;
using namespace System::IO;

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