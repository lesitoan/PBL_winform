#pragma once
#include "ServicesRepository.h"
#include "UserRepository.h"
#include "CustomerCodesRepository.h"
#include "UserServices.h"

#ifndef SERVICESERVICES_H
#define SERVICESERVICES_H

using namespace System;
using namespace System::IO;

public
ref class ServiceServices {
  public:
    static void InsertService(String ^ name) {
        try {
            if (name == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            }
            // kieemr tra xem dịch vụ đã tồn tại chưa
            Services ^ currentService = ServicesRepository::FindServiceByName(name);
            if (currentService != nullptr) {
                throw gcnew Exception(L"Dịch vụ đã tồn tại");
            }

            Services ^ newService = gcnew Services(name);
            ServicesRepository::InsertService(newService);
            
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
    static array<Services ^> ^ GetAllServices() {
        try {
            return ServicesRepository::GetAll();
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void PayCustomerCode(String ^ customerCodeString, String ^ companyAccountNumber,
        String ^ userId, String^ pin) {
       try {
           if (customerCodeString == "" || companyAccountNumber == "" ||
               userId == "" || pin == "") {
               throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
           }
           // kiểm tra mã dịch vụ đã tồn tại chưa
           CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeByCodeString(customerCodeString);
           if (customerCode == nullptr) {
               throw gcnew Exception(L"Mã dịch vụ không tồn tại");
           } else if (customerCode->Status == 0) {
               throw gcnew Exception(L"Mã dịch vụ không còn hoạt động");
           }

           // kiểm tra xem có hóa đơn chưa thanh toán không
           array<CustomerCodeDetails ^> ^ codeDetails = 
               CustomerCodeDetailsRepository::GetCustomerCodeDetailsByCustomerCodeId(customerCode->Id);
           if (codeDetails == nullptr || codeDetails->Length == 0) {
               throw gcnew Exception(L"Khách hàng chưa có hóa đơn cần thanh toán");
           }
           CustomerCodeDetails ^ currentCodeDetail = nullptr;
           for (int i = 0; i < codeDetails->Length; i++) {
               if (codeDetails[i]->CustomerCodeId == customerCode->Id &&
                   codeDetails[i]->Status == 0 &&
                   codeDetails[i]->ExpiredDate > DateTime::Now) {
                   currentCodeDetail = codeDetails[i];
                   break;
               }
           }
           if (currentCodeDetail == nullptr) {
               throw gcnew Exception(L"Khách hàng chưa có hóa đơn cần thanh toán");
           }

           // chuyển tiền
           UserService::TransferMoney(userId, companyAccountNumber,
                                      currentCodeDetail->Amount, Convert::ToInt32(pin), L"Thanh toán mã hóa đơn: " + customerCodeString);

           // cập nhật hóa đơn
           currentCodeDetail->Status = 1; // đã thanh toán
           currentCodeDetail->PaymentDate = DateTime::Now;
           currentCodeDetail->PaymentUserId = userId;
           CustomerCodeDetailsRepository::UpdateById(currentCodeDetail->Id, currentCodeDetail);


       } catch (Exception ^ ex) {
           throw ex;
       }
    }

    static void DeleteServiceById(String ^ id) {
        try {
            if (id == "") {
                throw gcnew Exception(L"Không có thông tin dịch vụ");
            }
            // chỉ xóa khi không có công ty nào sử dụng dịch vụ này
            array<User ^> ^ users = UserRepository::GetUsers();
            if (users == nullptr || users->Length == 0) {
                return;
            }
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getServiceId() == id) {
                    throw gcnew Exception(L"Dịch vụ này đang được sử dụng, không thể xóa");
                }
            }
            ServicesRepository::DeleteById(id);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};
#endif // !SERVICESERVICES_H
