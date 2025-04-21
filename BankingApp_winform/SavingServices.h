#pragma once
#include "SavingCustomersRepository.h"
#include"UserRepository.h"
#include "SavingCustomers.h"
#include "Validate.h"
#include "Utils.h"

#ifndef SAVINGSERVICE_H
#define SAVINGSERVICE_H

using namespace System;
using namespace System::IO;

public
ref class SavingServices {
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

    static void AddSaving(String^ type, String ^ amount, String ^ pin, int term) {
        try {
            if (amount->Length == 0 || pin->Length == 0) {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            }else if (!Validate::isNumber(amount)) {
                throw gcnew Exception(L"Số tiền gửi không hợp lệ");
            }else if (!Validate::isPin(pin)) {
                throw gcnew Exception(L"PIN không hợp lệ");
            }else if (Convert::ToDouble(amount) < 1000000) {
                throw gcnew Exception(L"Số tiền gửi tối thiểu là 1.000.000 vnđ");
            }else if (type == "termDeposit" && term == 0) {
                throw gcnew Exception(L"Vui lòng chọn kì hạn");
            }


            double currBalance = GlobalData::GetCurrentUser()->getBalance();
            if (currBalance < Convert::ToDouble(amount)) {
                throw gcnew Exception(L"Số dư không đủ để gửi tiết kiệm");
            }

            String ^ accountNumber = GlobalData::GetCurrentUser()->getAccountNumber();

            String ^ id = Utils::createUniqueID(L"SC");
            SavingCustomers ^ savingCustomer = gcnew SavingCustomers(
                id, accountNumber, Convert::ToDouble(amount), type, term
            );

            // Lưu gói tiết kiệm vào file
            SavingCustomersRepository::InsertOne(savingCustomer);

            // Cập nhật số dư của người dùng
            double newBalance = currBalance - Convert::ToDouble(amount);
            GlobalData::GetCurrentUser()->setBalance(newBalance);
            UserRepository::UpdateUserByAccNumber(accountNumber, GlobalData::GetCurrentUser());

        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !SAVINGSERVICE_H
