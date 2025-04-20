#pragma once
#include "CustomerCodeDetails.h"
#include "CustomerCodeDetailsRepository.h"

#ifndef CUSTOMERCODEDETAILSERVICES_H
#define CUSTOMERCODEDETAILSERVICES_H
using namespace System;
using namespace System::IO;

public
ref class CustomerCodeDetailServices {
  public:
    static void DeleteCodeDetail(String ^ id) {
        try {
            if (id == "") {
                throw gcnew Exception(L"Không có thông tin mã khách hàng");
            }
            CustomerCodeDetailsRepository::DeleteById(id);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static array<CustomerCodeDetails ^> ^ GetAllCodeDetails() {
        try {
            return CustomerCodeDetailsRepository::GetAll();
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static CustomerCodeDetails^ InsertCodeDetail(String^ _amount, String^ _days, String^ customerCodeId) {
        try {
            if (_amount == "" ||_days == "") {
                throw gcnew Exception(L"Vui lòng nhập số tiền và thời gian");
            }
            double amount = Convert::ToDouble(_amount);
            int days = Convert::ToInt32(_days);

            if (amount <= 0 || days <= 0) {
                throw gcnew Exception(L"Số tiền hoặc thời gian không hợp lệ");
            }

            if (customerCodeId == "") {
                throw gcnew Exception(L"Không có thông tin mã khách hàng");
            }

            // mỗi mã khách hàng trong 1 tháng chỉ được tạo 1 hóa đơn
            array<CustomerCodeDetails ^> ^ codeDetails =
                CustomerCodeDetailsRepository::GetCustomerCodeDetailsByCustomerCodeId(customerCodeId);

            if (codeDetails != nullptr) {
                for (int i = 0; i < codeDetails->Length; i++) {
                    if (codeDetails[i]->Status == 0) {
                        throw gcnew Exception(L"Mã khách hàng đã có hóa đơn chưa thanh toán");
                    }
                }
            }
            // tạo hóa đơn mới
            String ^ codeDetailId = Utils::createUniqueID("CCD");
            DateTime expiredDate = DateTime::Now.AddDays(days);
            CustomerCodeDetails ^ codeDetail = gcnew CustomerCodeDetails(
                codeDetailId, customerCodeId, amount, expiredDate);

            // thêm hóa đơn vào danh sách
            CustomerCodeDetailsRepository::InsertOne(codeDetail);

            return codeDetail;
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !CUSTOMERCODEDETAILSERVICES_H
