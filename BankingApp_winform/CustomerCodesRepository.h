#pragma once
#include "HandleFile.h"
#include "SavingCustomers.h"
#include "SavingCustomersRepository.h"
#include "User.h"
#include "UserRepository.h"
#include "Validate.h"

#ifndef CUSTOMERCODESREPOSITORY_H
#define CUSTOMERCODESREPOSITORY_H

using namespace System;
using namespace System::IO;

public
ref class CustomerCodesRepository {
  private:
    static array<CustomerCodes ^> ^ customerCodesCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;

    static CustomerCodesRepository() {
        customerCodesCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "customercodes.dat";
    }
    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime = HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                customerCodesCache =
                    HandleFile::ReadArrayFromFile<CustomerCodes ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<CustomerCodes ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return customerCodesCache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }
        // static void InsertOne(CustomerCodes ^ customerCodes) {
        //     try {
        //         CheckLastUpdateTime();
        //         if (customerCodesCache == nullptr) {
        //             customerCodesCache = gcnew array<CustomerCodes ^>(0);
        //         }
        //         array<CustomerCodes ^> ^ newCustomerCodesCache =
        //             gcnew array<CustomerCodes ^>(customerCodesCache->Length + 1);
        //         for (int i = 0; i < customerCodesCache->Length; i++) {
        //             newCustomerCodesCache[i] = customerCodesCache[i];
        //         }
        //         newCustomerCodesCache[customerCodesCache->Length] = customerCodes;
        //         customerCodesCache = newCustomerCodesCache;
        //         HandleFile::WriteArrayToFile<CustomerCodes ^>(customerCodesCache,
        //                                                       fileName);
        //         // update lại thời gian chỉnh sửa file
        //         HandleFile::UpdateFilehistoryUpdate(fileName);
        //     } catch (Exception ^ ex) {
        //         throw gcnew Exception("InsertOne transaction error !!!", ex);
        //     }
        // }

        static CustomerCodes^ FindCustomerCodeById(String ^ id) {
              try {
                  CheckLastUpdateTime();
                  if (customerCodesCache == nullptr) {
                      return nullptr;
                  }
                  for (int i = 0; i < customerCodesCache->Length; i++) {
                      if (customerCodesCache[i]->Id == id) {
                          return customerCodesCache[i];
                      }
                  }
                  return nullptr;
              } catch (Exception ^ ex) {
                  throw gcnew Exception("findCustomerCodeById error !!!", ex);
              }
          }

        static void DeleteCache() {
        customerCodesCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "customercodes.dat";
    }
};
#endif // CUSTOMERCODESREPOSITORY_H
