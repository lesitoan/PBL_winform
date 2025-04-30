#pragma once
#include "HandleFile.h"
#include "CustomerCodeDetails.h"
#include "BaseRepository.h"
#include "ENV.h"

#ifndef CUSTOMERCODEDETAILSREPOSITORY_H
#define CUSTOMERCODEDETAILSREPOSITORY_H
using namespace System;
using namespace System::IO;

public
ref class CustomerCodeDetailsRepository : public BaseRepository<CustomerCodeDetails ^> {
  private:
    static CustomerCodeDetailsRepository() {
        InitializeRepository(ENV::CUSTOMER_CODE_DETAIL_FILE);
    }

  public:
    static array<CustomerCodeDetails ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return cache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static void InsertOne(CustomerCodeDetails ^ customerCodeDetails) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                cache = gcnew array<CustomerCodeDetails ^>(0);
            }

            array<CustomerCodeDetails ^> ^ newCustomerCodeDetailsCache =
                gcnew array<CustomerCodeDetails ^>(cache->Length + 1);

            for (int i = 0; i < cache->Length; i++) {
                newCustomerCodeDetailsCache[i] = cache[i];
            }
            newCustomerCodeDetailsCache[cache->Length] =
                customerCodeDetails;
            cache = newCustomerCodeDetailsCache;
            HandleFile::WriteArrayToFile<CustomerCodeDetails ^>(cache,
                                                                fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }

    static void UpdateById(String ^ id, CustomerCodeDetails ^ customerCodeDetails) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id == id) {
                    cache[i] = customerCodeDetails;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<CustomerCodeDetails ^>(cache,
                                                                fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateTransactionById error !!!", ex);
        }
    }

    static void DeleteById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }
            List<CustomerCodeDetails ^> ^ customerCodeDetailsList =
                gcnew List<CustomerCodeDetails ^>();
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id != id) {
                    customerCodeDetailsList->Add(cache[i]);
                }
            }
            cache = customerCodeDetailsList->ToArray();
            HandleFile::WriteArrayToFile<CustomerCodeDetails ^>(cache,
                                                                fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteTransactionById error !!!", ex);
        }
    }

    static array<CustomerCodeDetails ^> ^ GetCustomerCodeDetailsByCustomerCodeId(String ^ customerCodeId) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return nullptr;
            }
            List<CustomerCodeDetails ^> ^ customerCodeDetailsList =
                gcnew List<CustomerCodeDetails ^>();
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->CustomerCodeId == customerCodeId) {
                    customerCodeDetailsList->Add(cache[i]);
                }
            }
            if (customerCodeDetailsList->Count == 0) {
                return nullptr;
            }
            array<CustomerCodeDetails ^> ^ result =
                gcnew array<CustomerCodeDetails ^>(customerCodeDetailsList->Count);
            for (int i = 0; i < customerCodeDetailsList->Count; i++) {
                result[i] = customerCodeDetailsList[i];
            }
            return result;

        } catch (Exception ^ ex) {
            throw gcnew Exception("GetCustomerCodeDetailsByCustomerCodeId error !!!", ex);
        }
    }

};


#endif // !CUSTOMERCODEDETAILSREPOSITORY_H
