#pragma once
#include "HandleFile.h"
#include "CustomerCodeDetails.h"

#ifndef CUSTOMERCODEDETAILSREPOSITORY_H
#define CUSTOMERCODEDETAILSREPOSITORY_H
using namespace System;
using namespace System::IO;

public
ref class CustomerCodeDetailsRepository {
  private:
    static array<CustomerCodeDetails ^> ^ customerCodeDetailsCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;
    static CustomerCodeDetailsRepository() {
        customerCodeDetailsCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "customerCodeDetails.dat";
    }
    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime =
                HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                customerCodeDetailsCache =
                    HandleFile::ReadArrayFromFile<CustomerCodeDetails ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<CustomerCodeDetails ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return customerCodeDetailsCache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static void InsertOne(CustomerCodeDetails ^ customerCodeDetails) {
        try {
            CheckLastUpdateTime();
            if (customerCodeDetailsCache == nullptr) {
                customerCodeDetailsCache = gcnew array<CustomerCodeDetails ^>(0);
            }

            array<CustomerCodeDetails ^> ^ newCustomerCodeDetailsCache =
                gcnew array<CustomerCodeDetails ^>(customerCodeDetailsCache->Length + 1);

            for (int i = 0; i < customerCodeDetailsCache->Length; i++) {
                newCustomerCodeDetailsCache[i] = customerCodeDetailsCache[i];
            }
            newCustomerCodeDetailsCache[customerCodeDetailsCache->Length] =
                customerCodeDetails;
            customerCodeDetailsCache = newCustomerCodeDetailsCache;
            HandleFile::WriteArrayToFile<CustomerCodeDetails ^>(customerCodeDetailsCache,
                                                                fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }

    static void UpdateById(String ^ id, CustomerCodeDetails ^ customerCodeDetails) {
        try {
            CheckLastUpdateTime();
            if (customerCodeDetailsCache == nullptr) {
                return;
            }
            for (int i = 0; i < customerCodeDetailsCache->Length; i++) {
                if (customerCodeDetailsCache[i]->Id == id) {
                    customerCodeDetailsCache[i] = customerCodeDetails;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<CustomerCodeDetails ^>(customerCodeDetailsCache,
                                                                fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateTransactionById error !!!", ex);
        }
    }

    static void DeleteById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (customerCodeDetailsCache == nullptr) {
                return;
            }
            List<CustomerCodeDetails ^> ^ customerCodeDetailsList =
                gcnew List<CustomerCodeDetails ^>();
            for (int i = 0; i < customerCodeDetailsCache->Length; i++) {
                if (customerCodeDetailsCache[i]->Id != id) {
                    customerCodeDetailsList->Add(customerCodeDetailsCache[i]);
                }
            }
            customerCodeDetailsCache = customerCodeDetailsList->ToArray();
            HandleFile::WriteArrayToFile<CustomerCodeDetails ^>(customerCodeDetailsCache,
                                                                fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteTransactionById error !!!", ex);
        }
    }

    static array<CustomerCodeDetails ^> ^ GetCustomerCodeDetailsByCustomerCodeId(String ^ customerCodeId) {
        try {
            CheckLastUpdateTime();
            if (customerCodeDetailsCache == nullptr) {
                return nullptr;
            }
            List<CustomerCodeDetails ^> ^ customerCodeDetailsList =
                gcnew List<CustomerCodeDetails ^>();
            for (int i = 0; i < customerCodeDetailsCache->Length; i++) {
                if (customerCodeDetailsCache[i]->CustomerCodeId == customerCodeId) {
                    customerCodeDetailsList->Add(customerCodeDetailsCache[i]);
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

    static void DeleteCache() {
        customerCodeDetailsCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "customerCodeDetails.dat";
    }

};


#endif // !CUSTOMERCODEDETAILSREPOSITORY_H
