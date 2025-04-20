#pragma once
#include "SavingCustomersRepository.h"
#include"UserRepository.h"
#include "SavingCustomers.h"

#ifndef SAVINGSERVICE_H
#define SAVINGSERVICE_H

using namespace System;
using namespace System::IO;

public
ref class SavingService {
  public:
    static void UpdateStatusSaving(String^ id, SavingCustomers ^ savingCustomer) {
        try {
            if (savingCustomer == nullptr) {
                throw gcnew Exception(L"Không có thông tin khách hàng");
            }
            SavingCustomersRepository::UpdateById(id, savingCustomer);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void OnFinishSavingAdmin(SavingCustomers ^ savingCustomer) {
        try {

            if (savingCustomer == nullptr) {
                throw gcnew Exception(L"Không có thông tin khách hàng");
            }

            savingCustomer->Status = 1; // Đã tất toán
            savingCustomer->PaymentDate = DateTime::Now.ToString("dd/MM/yyyy");
            TimeSpan duration = DateTime::Now - savingCustomer->DepositDate;
            savingCustomer->InterestAmount =
                savingCustomer->Amount +
                (savingCustomer->Amount * savingCustomer->InterestRate *
                 duration.Days / 365.0);

            SavingCustomersRepository::UpdateById(savingCustomer->Id, savingCustomer);
            


            User ^ user = UserRepository::FindUserByAccNumber(savingCustomer->UserAccountNumber);
            if (user == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin khách hàng");
            }
            user->setBalance(user->getBalance() + savingCustomer->InterestAmount);

            UserRepository::UpdateUserByAccNumber(user->getAccountNumber(), user);


        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !SAVINGSERVICE_H
