#pragma once
#include "GlobalData.h"
#include "Notifications.h"
#include "NotificationsRepository.h"
#include "SavingCustomers.h"
#include "SavingCustomersRepository.h"
#include "Transaction.h"
#include "TransactionsRepository.h"
#include "UserRepository.h"
#include "Validate.h"

#ifndef SAVINGSERVICE_H
#define SAVINGSERVICE_H

using namespace System;
using namespace System::IO;

// để return về array cho ui render
public
ref class SavingDTO {
  private:
    User ^ user;
    SavingCustomers ^ saving;

  public:
    SavingDTO(User ^ _user, SavingCustomers ^ _saving) {
        user = _user;
        saving = _saving;
    }

    property User ^ CurrUser {
        User ^ get() { return user; }
    } property SavingCustomers ^
        SavingCustomer {
            SavingCustomers ^ get() { return saving; }
        }
};

public
ref class SavingServices {
  public:
    static array<SavingDTO ^> ^ GetAllSavingCustomers() {
        try {
            array<SavingCustomers ^> ^ savingItems = SavingCustomersRepository::GetAll();
            if (savingItems == nullptr || savingItems->Length == 0) {
                return nullptr;
            }
            
            array<SavingDTO ^> ^ data = gcnew array<SavingDTO ^>(savingItems->Length);
            for (int i = 0; i < savingItems->Length; i++) {
                User ^ currUser = UserRepository::FindById(savingItems[i]->UserId);
                data[i] = gcnew SavingDTO(currUser, savingItems[i]);
            }
            return data;

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void UpdateStatusSaving(String ^ id, SavingCustomers ^ savingCustomer) {
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
            savingCustomer->PaymentDate = DateTime::Now;
            savingCustomer->InterestAmount = savingCustomer->CalculateInterestAmount();

            SavingCustomersRepository::UpdateById(savingCustomer->Id, savingCustomer);

            User ^ user = UserRepository::FindById(savingCustomer->UserId);
            if (user == nullptr) {
                throw gcnew Exception(L"Không tìm thấy thông tin khách hàng");
            }
            user->setBalance(user->getBalance() + savingCustomer->InterestAmount + savingCustomer->Amount);

            UserRepository::UpdateById(user->Id, user);

            // thêm lịch sử giao dịch
            double totalAmount = savingCustomer->InterestAmount + savingCustomer->Amount;
            String ^ type = savingCustomer->Type == "nonTermDeposit" ? L"Không kì hạn" : L"Có kì hạn";
            Transaction ^ transaction = gcnew Transaction("", savingCustomer->UserId, totalAmount, L"Tất toán tiết kiệm", "saving");
            TransactionsRepository::InsertOne(transaction);

            // gửi thông báo cho khách hàng hiện tại
            String ^ message2 = String::Format(L"Bạn đã nhận tiết kiệm {0} với số tiền {1:N0} VNĐ", type, totalAmount);
            Notifications ^ notification = gcnew Notifications(savingCustomer->UserId, message2);
            NotificationsRepository::InsertOne(notification);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void AddSaving(String ^ type, String ^ amount, String ^ pin, int term) {
        try {
            if (amount->Length == 0 || pin->Length == 0) {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            } else if (!Validate::isNumber(amount)) {
                throw gcnew Exception(L"Số tiền gửi không hợp lệ");
            } else if (!Validate::isPin(pin)) {
                throw gcnew Exception(L"PIN không hợp lệ");
            } else if (Convert::ToDouble(amount) < 1000000) {
                throw gcnew Exception(L"Số tiền gửi tối thiểu là 1.000.000 vnđ");
            } else if (type == "termDeposit" && term == 0) {
                throw gcnew Exception(L"Vui lòng chọn kì hạn");
            }

            double currBalance = GlobalData::GetCurrentUser()->getBalance();
            if (currBalance < Convert::ToDouble(amount)) {
                throw gcnew Exception(L"Số dư không đủ để gửi tiết kiệm");
            }

            String ^ currUserId = GlobalData::GetCurrentUser()->Id;
            SavingCustomers ^ savingCustomer = gcnew SavingCustomers(currUserId, Convert::ToDouble(amount), type, term);

            // Lưu gói tiết kiệm vào file
            SavingCustomersRepository::InsertOne(savingCustomer);

            // Cập nhật số dư của người dùng
            double newBalance = currBalance - Convert::ToDouble(amount);
            GlobalData::GetCurrentUser()->setBalance(newBalance);
            UserRepository::UpdateById(currUserId, GlobalData::GetCurrentUser());

            // thêm lịch sử giao dịch
            Transaction ^ transaction = gcnew Transaction(currUserId, "", Convert::ToDouble(amount), L"gửi tiết kiệm " + amount, "saving");
            TransactionsRepository::InsertOne(transaction);

            // gửi thông báo cho khách hàng hiện tại
            String ^ message = String::Format(L"Bạn đã gửi tiết kiệm {0} với số tiền {1:N0} VNĐ", type, amount);
            Notifications ^ notification = gcnew Notifications(currUserId, message);
            NotificationsRepository::InsertOne(notification);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !SAVINGSERVICE_H
