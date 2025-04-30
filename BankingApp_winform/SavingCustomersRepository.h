#pragma once
#include "HandleFile.h"
#include "SavingCustomers.h"
#include "BaseRepository.h"
#include "ENV.h"

#ifndef SAVINGCUSTOMER_H
#define SAVINGCUSTOMER_H
using namespace System;
using namespace System::IO;

public
ref class SavingCustomersRepository : public BaseRepository<SavingCustomers ^> {
  private:

    static SavingCustomersRepository() {
        InitializeRepository(ENV::SAVING_CUSTOMER_FILE);
    }

  public:
    static array<SavingCustomers ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return cache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static array<SavingCustomers ^> ^
        GetSavingCustomersByUserId(String ^ userId) {
            try {
                CheckLastUpdateTime();
                if (cache == nullptr) {
                    return nullptr;
                }
                List<SavingCustomers ^> ^ savingCustomersList =
                    gcnew List<SavingCustomers ^>();
                for (int i = 0; i < cache->Length; i++) {
                    if (cache[i]->UserId == userId) {
                        savingCustomersList->Add(cache[i]);
                    }
                }
                return savingCustomersList->ToArray();
            } catch (Exception ^ ex) {
                throw gcnew Exception("GetSavingCustomersByUserId error !!!", ex);
            }
        }

    static void InsertOne(SavingCustomers ^ savingCustomer) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                cache = gcnew array<SavingCustomers ^>(0);
            }
            
            array<SavingCustomers ^> ^ temp = gcnew array<SavingCustomers ^>(cache->Length + 1);

            for (int i = 0; i < cache->Length; i++) {
                temp[i] = cache[i];
            }
            temp[cache->Length] = savingCustomer;
            cache = temp;
            HandleFile::WriteArrayToFile<SavingCustomers ^>(cache,
                                                            fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne error !!!", ex);
        }
    }

    static void UpdateById(String ^ id, SavingCustomers ^ savingCustomer) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id == id) {
                    cache[i] = savingCustomer;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<SavingCustomers ^>(cache,
                                                            fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("Update error !!!", ex);
        }
    }
};


#endif // !SAVINGCUSTOMER_h
