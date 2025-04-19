#pragma once
#include "HandleFile.h"
#include "SavingCustomers.h"

#ifndef SAVINGCUSTOMER_H
#define SAVINGCUSTOMER_H
using namespace System;
using namespace System::IO;

public
ref class SavingCustomersRepository {
  private:
    static array<SavingCustomers ^> ^ savingCustomersCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;

    static SavingCustomersRepository() {
        savingCustomersCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "savingcustomers.dat";
    }

    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime =
                HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                savingCustomersCache =
                    HandleFile::ReadArrayFromFile<SavingCustomers ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<SavingCustomers ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return savingCustomersCache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static array<SavingCustomers ^> ^
        GetSavingCustomersByAccNum(String ^ accNum) {
            try {
                CheckLastUpdateTime();
                if (savingCustomersCache == nullptr) {
                    return nullptr;
                }
                List<SavingCustomers ^> ^ savingCustomersList =
                    gcnew List<SavingCustomers ^>();
                for (int i = 0; i < savingCustomersCache->Length; i++) {
                    if (savingCustomersCache[i]->UserAccountNumber == accNum) {
                        savingCustomersList->Add(savingCustomersCache[i]);
                    }
                }
                return savingCustomersList->ToArray();
            } catch (Exception ^ ex) {
                throw gcnew Exception("GetSavingCustomersByAccNum error !!!", ex);
            }
        }

    static void InsertOne(SavingCustomers ^ savingCustomer) {
        try {
            CheckLastUpdateTime();
            if (savingCustomersCache == nullptr) {
                savingCustomersCache = gcnew array<SavingCustomers ^>(0);
            }
            
            array<SavingCustomers ^> ^ temp = gcnew array<SavingCustomers ^>(savingCustomersCache->Length + 1);

            for (int i = 0; i < savingCustomersCache->Length; i++) {
                temp[i] = savingCustomersCache[i];
            }
            temp[savingCustomersCache->Length] = savingCustomer;
            savingCustomersCache = temp;
            HandleFile::WriteArrayToFile<SavingCustomers ^>(savingCustomersCache,
                                                            fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne error !!!", ex);
        }
    }

    static void DeleteCache() {
        try {
            savingCustomersCache = nullptr;
            lastReadTime = DateTime::MinValue;
            fileName = "savingcustomers.dat";
        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteCache error !!!", ex);
        }
    }
};


#endif // !SAVINGCUSTOMER_h
