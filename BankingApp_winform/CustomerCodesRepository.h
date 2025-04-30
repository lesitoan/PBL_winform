#pragma once
#include "CustomerCodeDetailsRepository.h"
#include "HandleFile.h"
#include "SavingCustomers.h"
#include "SavingCustomersRepository.h"
#include "User.h"
#include "UserRepository.h"
#include "Validate.h"
#include "CustomerCodes.h"
#include "BaseRepository.h"
#include "ENV.h"

#ifndef CUSTOMERCODESREPOSITORY_H
#define CUSTOMERCODESREPOSITORY_H

using namespace System;
using namespace System::IO;

public
ref class CustomerCodesRepository : public BaseRepository<CustomerCodes ^> {
  private:

    static CustomerCodesRepository() {
        InitializeRepository(ENV::CUSTOMER_CODE_FILE);
    }

  public:
    static array<CustomerCodes ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return cache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }
    static CustomerCodes^ FindCustomerCodeByCodeString(String ^ codeString) {
              try {
                  CheckLastUpdateTime();
                  if (cache == nullptr) {
                      return nullptr;
                  }
                  for (int i = 0; i < cache->Length; i++) {
                      if (cache[i]->Code == codeString) {
                          return cache[i];
                      }
                  }
                  return nullptr;
              } catch (Exception ^ ex) {
                  throw gcnew Exception("findCustomerCodeByCodeString error !!!", ex);
              }
          }

        static CustomerCodes
        ^ InsertOne(String ^ CodeString, String ^ CompanyId) {
              try {
                  CheckLastUpdateTime();
                  if (cache == nullptr) {
                      cache = gcnew array<CustomerCodes ^>(0);
                  }
                  if (CodeString == nullptr || CodeString == "") {
                      throw gcnew Exception(L"Mã khách hàng " + CodeString + L" không hợp lệ.");
                  }
                  // kiểm tra mã khách hàng đã tồn tại chưa
                  CustomerCodes ^ existingCode = FindCustomerCodeByCodeString(CodeString);
                  if (existingCode != nullptr) {
                      throw gcnew Exception(L"Mã khách hàng " + CodeString + L" đã tồn tại.");
                  }

                  CustomerCodes ^ item =
                      gcnew CustomerCodes(CompanyId, CodeString);

                  array<CustomerCodes ^> ^ newCustomerCodes =
                      gcnew array<CustomerCodes ^>(cache->Length + 1);
                  for (int i = 0; i < cache->Length; i++) {
                      newCustomerCodes[i] = cache[i];
                  }
                  newCustomerCodes[cache->Length] = item;
                  cache = newCustomerCodes;
                  HandleFile::WriteArrayToFile<CustomerCodes ^>(cache,
                                                                fileName);
                  return item;

              } catch (Exception ^ ex) {
                  MessageBox::Show(ex->Message, L"Lỗi", MessageBoxButtons::OK,
                                   MessageBoxIcon::Error);
                  return nullptr;
              }
          }

        static CustomerCodes
        ^ FindCustomerCodeById(String ^ id) {
              try {
                  CheckLastUpdateTime();
                  if (cache == nullptr) {
                      return nullptr;
                  }
                  for (int i = 0; i < cache->Length; i++) {
                      if (cache[i]->Id == id) {
                          return cache[i];
                      }
                  }
                  return nullptr;
              } catch (Exception ^ ex) {
                  throw gcnew Exception("findCustomerCodeById error !!!", ex);
              }
          }

        static void DeleteById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }

            // Tìm mã khách hàng theo ID
            CustomerCodes ^ customerCode = FindCustomerCodeById(id);
            if (customerCode == nullptr) {
                throw gcnew Exception(L"Mã khách hàng không tồn tại");
            }
            // chỉ xóa khi chưa có lịch sử thanh toán => nếu có thì chỉ khóa
            array<CustomerCodeDetails ^> ^ currCodeDetails = CustomerCodeDetailsRepository::GetCustomerCodeDetailsByCustomerCodeId(id);
            if (currCodeDetails == nullptr || currCodeDetails->Length == 0) {
                array<CustomerCodes ^> ^ newCustomerCodes =
                    gcnew array<CustomerCodes ^>(cache->Length - 1);

                for (int i = 0; i < cache->Length; i++) {
                    if (cache[i]->Id != id) {
                        newCustomerCodes[i] = cache[i];
                    }
                }

                cache = newCustomerCodes;
                HandleFile::WriteArrayToFile<CustomerCodes ^>(cache, fileName);
                return;
            }

            //
            System::Windows::Forms::DialogResult result;
            result = MessageBox::Show(L"Mã khách hàng này không thể xóa\n" + L"do tồn tại lịch sử giao dịch. bạn có\n" + L"muốn khóa mã này không ?", L"Log Out",
                                      MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (result == System::Windows::Forms::DialogResult::No)
                return;
            customerCode->Status = 0; // khóa mã khách hàng
            UpdateCustomerCodeById(id, customerCode);

        } catch (Exception ^ ex) {
            MessageBox::Show(ex->ToString());
            throw gcnew Exception("DeleteById error !!!", ex);
        }
    }

    static void UpdateCustomerCodeById(String ^ id, CustomerCodes ^ customerCode) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id == id) {
                    cache[i] = customerCode;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<CustomerCodes ^>(cache,
                                                          fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateCustomerCodeById error !!!", ex);
        }
    }
};
#endif // CUSTOMERCODESREPOSITORY_H
