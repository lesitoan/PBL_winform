#pragma once
#include "User.h"
#include "UserRepository.h"
#include "CustomerCodesRepository.h"
#include "TransactionsRepository.h"

#ifndef USERSERVICE_H
#define USERSERVICE_H
using namespace System;
using namespace System::IO;

public
ref class UserService {
  public:
    static array<User ^> ^ GetAllUsers() {
        try {
            array<User ^> ^ users = UserRepository::GetUsers();
            if (users == nullptr || users->Length == 0) {
                return nullptr;
            }
            return users;

        } catch (Exception ^ ex) {
            throw gcnew Exception("GetAllUsers error !!!", ex);
        }
    }

    static array<User ^>^ GetCompanyByServiceId(String ^ serviceId) {
        try {
            array<User ^> ^ users = UserRepository::GetUsers();
            if (users == nullptr || users->Length == 0) {
                return nullptr;
            }
            List<User ^> ^ companies = gcnew List<User ^>();
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getRole() == "company" &&
                    users[i]->getServiceId() == serviceId) {
                    companies->Add(users[i]);
                }
            }
            if (companies->Count == 0) {
                return nullptr;
            }
            return companies->ToArray();

        } catch (Exception ^ ex) {
            throw gcnew Exception("GetCompanyByServiceId error !!!", ex);
        }
    }

    static array<String ^> ^
        GetHistoryReceivers(String ^ accNumber) {
            try {
                array<Transaction ^> ^ transactions = TransactionsRepository::GetAll();
                if (transactions == nullptr || transactions->Length == 0) {
                    return nullptr;
                }
                List<String ^> ^ receiverString = gcnew List<String ^>();
                int count = 0;

                for (int i = transactions->Length - 1; i > 0; i--) {
                    if (count == 5) {
                        break;
                    }
                    if (transactions[i]->getFromAccount() == accNumber && 
                        transactions[i]->getToAccount() != "") {
                        User^ user = UserRepository::FindUserByAccNumber(transactions[i]->getToAccount());
                        if (user->getRole() != "user") {
                            continue;
                        }
                        String ^ toAcc =
                            user->getBankName() + " - " +
                            user->getFullName() + " - " +
                            transactions[i]->getToAccount() +
                            " - " +
                            transactions[i]->getAmount().ToString();

                        receiverString->Add(toAcc);
                        count++;
                    }
                }
                if (receiverString->Count == 0) {
                    return nullptr;
                }
                return receiverString->ToArray();
            } catch (Exception ^ ex) {
                throw gcnew Exception("GetHistoryReceivers error !!!", ex);
            }
        }
    
    static User^  GetCompanyByCustomerCodeId(String ^ customerCodeId) {
            try {
                if (customerCodeId == "") {
                    throw gcnew Exception(L"Không có thông tin mã khách hàng");
                }
                array<User ^> ^ users = UserRepository::GetUsers();
                if (users == nullptr || users->Length == 0) {
                    return nullptr;
                }
                CustomerCodes ^ customerCode = CustomerCodesRepository::FindCustomerCodeById(customerCodeId);
                if (customerCode == nullptr) {
                    throw gcnew Exception(L"Không tìm thấy thông tin mã khách hàng");
                }
                User ^ company = UserRepository::FindUserByAccNumber(customerCode->CompanyAccountNumber);
                if (company == nullptr) {
                    throw gcnew Exception(L"Không tìm thấy thông tin công ty");
                }
                return company;
            } catch (Exception ^ ex) {
                throw gcnew Exception("GetCompanyByServiceId error !!!", ex);
            }
        }
    static void UpdateUserByAccNumber(String ^ accNumber, User ^ user) {
        try {
            UserRepository::UpdateUserByAccNumber(accNumber, user);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateUserByAccNumber error !!!", ex);
        }
    }
};

#endif // !USERSERVICE_H
