#pragma once
#include "CustomerCodeDetails.h"
#include "CustomerCodeDetailsRepository.h"
#include "CustomerCodes.h"
#include "CustomerCodesRepository.h"
#include "NotificationServices.h"
#include "RecurringPayments.h"
#include "RecurringPaymentsRepository.h"
#include "TransactionServices.h"
#include "User.h"
#include "UserRepository.h"
#include "UserServices.h"

#ifndef RECURRINGPAYMENTSERVICES_H
#define RECURRINGPAYMENTSERVICES_H
using namespace System;
using namespace System::IO;

public
ref class RecurringPaymentDTO {
  private:
    RecurringPayments ^ recurringPayment;
    User ^ user;
    CustomerCodes ^ customerCode;

  public:
    RecurringPaymentDTO(RecurringPayments ^ recurringPayment, User ^ user, CustomerCodes ^ customerCode) {
        this->recurringPayment = recurringPayment;
        this->user = user;
        this->customerCode = customerCode;
    }
    property RecurringPayments ^ DataRecurringPayment {
        RecurringPayments ^ get() { return recurringPayment; }
    } property User ^
        DataUser {
            User ^ get() { return user; }
        } property CustomerCodes ^
        DataCustomerCodes {
            CustomerCodes ^ get() { return customerCode; }
        }
};

public
ref class RecurringPaymentServices {
  public:
    static array<RecurringPaymentDTO ^> ^ GetRecurringPaymentByCompanyId(String ^ companyId) {
        try {
            array<RecurringPayments ^> ^ recurringPayments = RecurringPaymentsRepository::GetAll();

            List<RecurringPaymentDTO ^> ^ recurringPaymentDTOs = gcnew List<RecurringPaymentDTO ^>();
            for (int i = 0; i < recurringPayments->Length; i++) {
                CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeById(recurringPayments[i]->CustomerCodeId);
                if (customerCode == nullptr || customerCode->CompanyId != companyId) {
                    continue;
                }

                User ^ user = UserRepository::FindById(recurringPayments[i]->UserId);
                if (user == nullptr) {
                    continue;
                }

                RecurringPaymentDTO ^ recurringPaymentDTO =
                    gcnew RecurringPaymentDTO(recurringPayments[i], user, customerCode);
                recurringPaymentDTOs->Add(recurringPaymentDTO);
            }
            return recurringPaymentDTOs->ToArray();
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

        static RecurringPayments
        ^ GetRecurringPaymentByCustomerCodeId(String ^ customerCodeId) {
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

        static array<RecurringPayments ^> ^
        GetRecurringPaymentsByUserId(String ^ userId) {
            try {
                if (userId == "") {
                    throw gcnew Exception(L"Không có thông tin tài khoản");
                }
                array<RecurringPayments ^> ^ recurringPayments = RecurringPaymentsRepository::GetAll();
                if (recurringPayments == nullptr || recurringPayments->Length == 0) {
                    return nullptr;
                }
                List<RecurringPayments ^> ^ filteredRecurringPayments = gcnew List<RecurringPayments ^>();
                for (int i = 0; i < recurringPayments->Length; i++) {
                    if (recurringPayments[i]->UserId == userId) {
                        filteredRecurringPayments->Add(recurringPayments[i]);
                    }
                }
                if (filteredRecurringPayments->Count == 0) {
                    return nullptr;
                }
                return filteredRecurringPayments->ToArray();
            } catch (Exception ^ ex) {
                throw ex;
            }
        }

        static void PayRecurringPayment(RecurringPayments ^ recurringPayments, CustomerCodeDetails ^ customerCodeDetail) {
        try {

            User ^ user = UserRepository::FindById(recurringPayments->UserId);
            if (user == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin khách hàng");
            }
            CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeById(recurringPayments->CustomerCodeId);
            if (customerCode == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin mã khách hàng");
            }

            User ^ company = UserRepository::FindById(customerCode->CompanyId);
            if (company == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin công ty");
            }

            // kiểm tra số dư khách hàng, nếu không đủ thì gửi thông báo
            if (user->getBalance() < customerCodeDetail->Amount) {
                String ^ content = L"Thanh toán định kì tại công ty " + company->FullName + L" (" +
                                   customerCodeDetail->Amount + L") " + L" chưa hoàn thành, " +
                                   L"hãy nộp thêm tiền vào tài khoản để tiến hành giao dịch";

                NotificationsServices::InsertNotification(recurringPayments->UserId, content);
                throw gcnew Exception(L"Khách hàng không đủ số dư để thanh toán định kì hóa đơn này");
            }

            // update code detail
            customerCodeDetail->Status = 1; // đã thanh toán
            customerCodeDetail->PaymentDate = DateTime::Now;
            customerCodeDetail->PaymentUserId = recurringPayments->UserId;
            CustomerCodeDetailsRepository::UpdateById(customerCodeDetail->Id, customerCodeDetail);

            UserService::TransferMoney(user->AccountNumber, company->AccountNumber, customerCodeDetail->Amount, 0, L"Thanh toán định kì hóa đơn: " + customerCode->Code, "service");

        } catch (Exception ^ ex) {

            throw ex;
        }
    }

    static void RegisterRecurringPayment(String ^ customerCodeString, String ^ userId) {
        try {
            if (customerCodeString == "" || userId == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            }

            // kiểm tra mã dịch vụ đã tồn tại chưa
            CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeByCodeString(customerCodeString);
            if (customerCode == nullptr) {
                throw gcnew Exception(L"Mã dịch vụ không tồn tại");
            } else if (customerCode->Status == 0) {
                throw gcnew Exception(L"Mã dịch vụ không còn hoạt động");
            }

            // kiểm tra  mã thanh toán đã được đăng kí chưa
            RecurringPayments ^ recurringPayments = RecurringPaymentServices::GetRecurringPaymentByCustomerCodeId(customerCode->Id);
            if (recurringPayments != nullptr) {
                throw gcnew Exception(L"Mã khách hàng này đã được đăng kí định kì rồi");
            }

            // kiểm tra khách hàng đã đăng kí mã nào nào công ty này chưa
            array<RecurringPayments ^> ^ myRecurringPayments = RecurringPaymentServices::GetRecurringPaymentsByUserId(userId);
            if (myRecurringPayments != nullptr) {
                for (int i = 0; i < myRecurringPayments->Length; i++) {
                    if (myRecurringPayments[i]->CustomerCodeId == customerCode->Id) {
                        throw gcnew Exception(L"Mã khách hàng này đã được đăng kí định kì rồi");
                    }
                }
            }

            RecurringPayments ^ newRecurringPayment =
                gcnew RecurringPayments(userId, customerCode->Id, Convert::ToInt32(DateTime::Now.Day));

            RecurringPaymentsRepository::InsertOne(newRecurringPayment);

            User ^ client = UserRepository::FindById(userId);

            // thêm thông báo cho khách hàng và công ty
            String ^ content = L"Đăng kí thanh toán định kì cho mã khách hàng " + customerCode->Code + L" thành công";
            NotificationsServices::InsertNotification(userId, content);

            content = L"Khách hàng " + client->FullName + L" đã đăng kí thanh toán định kì cho mã khách hàng " + customerCode->Code;
            NotificationsServices::InsertNotification(customerCode->CompanyId, content);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void DeleteRecurringPaymentById(String ^ id) {
        try {

            // thêm thông báo cho khách hàng và công ty
            RecurringPayments ^ recurringPayment = RecurringPaymentsRepository::GetOneById(id);
            if (recurringPayment == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin mã thanh toán định kì");
            }

            CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeById(recurringPayment->CustomerCodeId);
            if (customerCode == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin mã khách hàng");
            }


            User ^ company = UserRepository::FindById(customerCode->CompanyId);
            User ^ customer = UserRepository::FindById(recurringPayment->UserId);

            String ^ content = L"Đã hủy thanh toán định kì cho mã khách hàng " + customerCode->Code;
            NotificationsServices::InsertNotification(recurringPayment->UserId, content);

            content = L"Khách hàng " + customer->Id + L" đã hủy thanh toán định kì cho mã khách hàng " + customerCode->Code;
            NotificationsServices::InsertNotification(customerCode->CompanyId, content);

            RecurringPaymentsRepository::DeleteById(id);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !RECURRINGPAYMENTSERVICES_H
