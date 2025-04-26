#pragma once
#include "AuthServices.h"
#include "CustomerCodesRepository.h"

#ifndef CUSTOMERCODESERVICES_H
#define CUSTOMERCODESERVICES_H

public
ref class CustomerCodeServices {
  public:
    static void addCustomerCodes(String ^ input, String ^ pin) {
        try {
            AuthServices::isLogin(pin);

            if (input == "") {
                throw gcnew Exception(L"Vui lòng nhập mã khách hàng");
            }
            array<String ^> ^ customerCodesString = CreateArrayCustomerCodeString(input);
            if (customerCodesString == nullptr || customerCodesString->Length == 0) {
                return;
            }

            String ^ companyId = GlobalData::GetCurrentUser()->Id;
            for (int i = 0; i < customerCodesString->Length; i++) {
                CustomerCodes ^ newCustomerCode = CustomerCodesRepository::InsertOne(customerCodesString[i], companyId);
                if (newCustomerCode != nullptr) {
                    MessageBox::Show(L"Thêm mã khách hàng: " + newCustomerCode->Code + L" thành công");
                }
            }

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static array<String ^> ^ CreateArrayCustomerCodeString(String ^ input) {
        try {

            List<String ^> ^ items = gcnew List<String ^>();

            array<String ^> ^ lines = input->Split(
                gcnew array<wchar_t>{'\n'}, StringSplitOptions::RemoveEmptyEntries);

            for (int i = 0; i < lines->Length; i++) {
                lines[i] = lines[i]->Trim(); // Xóa khoảng trắng đầu/cuối dòng
            }

            if (lines->Length == 0) {
                throw;
            }

            for (int i = 0; i < lines->Length; i++) {
                // validate code, price, day
                if (lines[i]->Length < 5 || lines[i]->Length > 10) {
                    MessageBox::Show(L"Mã khách hàng: " + lines[i] +
                                     L" phải lớn hơn 5 kí tự và nhỏ hơn 10 kí tự");
                    continue;
                } else if (!Regex::IsMatch(lines[i], "^[a-zA-Z0-9]+$")) {
                    MessageBox::Show(L"Mã khách hàng: " + lines[i] +
                                     L" không hợp lệ, chỉ chứa chữ cái và số");
                    continue;
                }
                items->Add(lines[i]);
            }

            if (items->Count == 0) {
                throw;
            }

            return items->ToArray();

        } catch (Exception ^ ex) {
            return gcnew array<String ^>(0);
        }
    }

        static array<CustomerCodes ^> ^
        GetCustomerCodesByCompanyId(String ^ companyId) {
            try {
                array<CustomerCodes ^> ^ customerCodes = CustomerCodesRepository::GetAll();

                if (customerCodes == nullptr || customerCodes->Length == 0) {
                    throw;
                }
                List<CustomerCodes ^> ^ customerCodesList = gcnew List<CustomerCodes ^>();
                for (int i = 0; i < customerCodes->Length; i++) {
                    if (customerCodes[i]->CompanyId == companyId) {
                        customerCodesList->Add(customerCodes[i]);
                    }
                }
                if (customerCodesList->Count == 0) {
                    throw;
                }
                return customerCodesList->ToArray();
            } catch (Exception ^ ex) {
                return gcnew array<CustomerCodes ^>(0);
            }
        }

        static void DeleteCustomerCode(String ^ id) {
        try {
            if (id == nullptr || id == "") {
                throw gcnew Exception(L"Mã khách hàng không hợp lệ");
            }
            // chỉ xóa khi chưa có lịch sử thanh toán => nếu có thì chỉ khóa
            CustomerCodesRepository::DeleteById(id);


        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !CUSTOMERCODESERVICES_H
