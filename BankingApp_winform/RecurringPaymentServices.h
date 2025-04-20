#pragma once
#include "RecurringPayments.h"
#include "User.h"
#include "RecurringPaymentsRepository.h"
#include "UserRepository.h"
#include "CustomerCodes.h"
#include "CustomerCodesRepository.h"
#include "CustomerCodeDetails.h"
#include "CustomerCodeDetailsRepository.h"
#include "NotificationServices.h"
#include "TransactionServices.h"

#ifndef RECURRINGPAYMENTSERVICES_H
#define RECURRINGPAYMENTSERVICES_H
using namespace System;
using namespace System::IO;

public
ref class RecurringPaymentServices {
  public:
    static RecurringPayments ^ GetRecurringPaymentByCustomerCodeId(String ^ customerCodeId) {
        try {
            if (customerCodeId == "") {
                throw gcnew Exception(L"Không có thông tin mã khách hàng");
            }
            array<RecurringPayments ^> ^ recurringPayments = RecurringPaymentsRepository::GetAll();
            if (recurringPayments == nullptr || recurringPayments->Length == 0) {
                return nullptr;
            }
            for (int i = 0; i < recurringPayments->Length; i++) {
                if (recurringPayments[i]->CustomerCodeId == customerCodeId) {
                    return recurringPayments[i];
                }
            }
            return nullptr;
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void PayRecurringPayment(RecurringPayments ^ recurringPayments, CustomerCodeDetails^ customerCodeDetail) {
        try {

            User ^ user = UserRepository::FindUserByAccNumber(recurringPayments->UserAccountNumber);
            if (user == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin khách hàng");
            }
            CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeById(recurringPayments->CustomerCodeId);
            if (customerCode == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin mã khách hàng");
            }
            User ^ company = UserRepository::FindUserByAccNumber(customerCode->CompanyAccountNumber);
            if (company == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin công ty");
            }

            // kiểm tra số dư khách hàng, nếu không đủ thì gửi thông báo
            if (user->getBalance() < customerCodeDetail->Amount) {
                String ^ content = L"Thanh toán định kì tại công ty " + company->FullName + L" (" +
                                   customerCodeDetail->Amount + L") " + L" chưa hoàn thành, " +
                                   L"hãy nộp thêm tiền vào tài khoản để tiến hành giao dịch";

                NotificationsServices::InsertNotification(recurringPayments->UserAccountNumber, content);
                return;
            }

            // update code detail
            customerCodeDetail->Status = 1; // đã thanh toán
            customerCodeDetail->PaymentDate = DateTime::Now.ToString("dd/MM/yyyy");
            customerCodeDetail->PaymentUserAccountNumber = recurringPayments->UserAccountNumber;
            CustomerCodeDetailsRepository::UpdateById(customerCodeDetail->Id, customerCodeDetail);

            // update số dư của khách hàng
            user->setBalance(user->getBalance() - customerCodeDetail->Amount);
            UserRepository::UpdateUserByAccNumber(user->getAccountNumber(), user);

            // update số dư của công ty
            company->setBalance(company->getBalance() + customerCodeDetail->Amount);
            UserRepository::UpdateUserByAccNumber(company->getAccountNumber(), company);

            // thêm lịch sử
            TransactionServices::InsertTransaction(recurringPayments->UserAccountNumber,
                customerCode->CompanyAccountNumber, customerCodeDetail->Amount,
                L"Thanh toán định kì cho mã khách hàng " + customerCode->Code);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }
    
};


#endif // !RECURRINGPAYMENTSERVICES_H
