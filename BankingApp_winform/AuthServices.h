#pragma once
#include "HandleFile.h"
#include "User.h"
#include "Validate.h"
#include "GlobalData.h"

#include "UserRepository.h"
#include "CustomerCodesRepository.h"
#include "CustomerCodeDetailsRepository.h"
#include "RecurringPaymentsRepository.h"
#include "NotificationsRepository.h"
#include"TransactionsRepository.h"
#include"ServicesRepository.h"
#include "SavingCustomersRepository.h"


using namespace System;
using namespace System::IO;

public
ref class AuthServices {
  public:

    static User^ Login(String ^ phone, String ^ pass) {
        try {
            if (phone == "" || pass == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            }

            User ^ user = UserRepository::FindUserByPhoneNumber(phone);


            if (user == nullptr) {
                throw gcnew Exception(L"Đăng nhập thất bại, thử lại sau");
            }

            if (user->getPassword() != user->Hash(pass)) {
                throw gcnew Exception(L"Số điện thoại hoặc mật khẩu không đúng");
            }
            if (user->Status == 0) {
                throw gcnew Exception(L"Tài khoản của bạn đã bị khóa");
            }

            GlobalData::SetCurrentUser(user);
            return user;

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void Signup(String ^ fullName, String ^ phoneNumber, String ^ password, String ^ passwordConfirm) {
        try {

            if (fullName == "" || password == "" ||
                passwordConfirm == "" || phoneNumber == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin!");

            } else if (password != passwordConfirm) {
                throw gcnew Exception(L"Mật khẩu không khớp nhau");

            } else if (!Validate::isValidPassword(password)) {
                throw gcnew Exception(L"Mật khẩu phải từ 6-9 kí tự, có ít nhất 1 chữ cái và 1 số, không chứ dấu cách");

            } else if (!Validate::isValidVietnamPhoneNumber(phoneNumber)) {
                throw gcnew Exception(L"Số điện thoại không hợp lệ");

            } else if (!Validate::isValidCustomerName(fullName)) {
                throw gcnew Exception(L"Tên chỉ được viết in hoa không dấu và ít nhất 2 từ");

            } 

            User ^ currentUser = UserRepository::FindUserByPhoneNumber(phoneNumber);

            if (currentUser != nullptr) {
                throw gcnew Exception(L"Số điện thoại đã được sử dụng");
            }

            User ^ user = gcnew User(fullName, password, phoneNumber);
            UserRepository::InsertUser(user);

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static String^ ForgotPassword(String ^ phoneNumber, String ^ fullName) {
        try {
            if (phoneNumber == "" || fullName == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");

            }

            User ^ user = UserRepository::FindUserByPhoneNumber(phoneNumber);

            if (user == nullptr) {
                throw gcnew Exception(L"Số điện thoại hoặc tên chưa đúng");
            }
            if (user->getFullName() != fullName) {
                throw gcnew Exception(L"Số điện thoại hoặc tên chưa đúng");
            }
            DateTime now = DateTime::Now;
            String ^ newPassword = "TML" + now.ToString("HHmmss");
            user->setPassword(newPassword);
            // Lưu lại thông tin vào file
            UserRepository::UpdateById(user->Id, user);

            return newPassword;

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void LockAccount(String ^ phoneNumber) {
        try {
            if (phoneNumber == "") {
                throw gcnew Exception(L"Vui lòng nhập số điện thoại");
            }

            User ^ user = UserRepository::FindUserByPhoneNumber(phoneNumber);
            if (user == nullptr) {
                throw gcnew Exception(L"Số điện thoại không tồn tại");
            }
            user->Status = 0; // khóa tài khoản
            UserRepository::UpdateById(user->Id, user);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void AddUser(String ^ name, String ^ phone, String ^ accNum,
                        String ^ password, Role accType, String^ serviceId) {
        try {

            if (name == "" || phone == "" || accNum == "" || password == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");

            } else if (accType == Role::Company && serviceId == "") {
                throw gcnew Exception(L"Chưa chọn dịch vụ");
            }

            User ^ currentUser = UserRepository::FindUserByPhoneNumber(phone);

            if (currentUser != nullptr && currentUser->AccountNumber == accNum) {
                throw gcnew Exception(L"Số điện thoại đã tồn tại");

            }

            double _balance = 0;
            int _pin = 0;
            int _status = 1;
            Bank bankName = Bank::BIDV;

            User ^ user =
                gcnew User(name, password, phone, accNum, _balance,
                           accType, _pin, bankName, _status, serviceId);

            UserRepository::InsertUser(user);

        } catch (Exception ^ ex) {

            MessageBox::Show(ex->ToString(), "Success",
                             MessageBoxButtons::OK, MessageBoxIcon::Information);
            throw ex;
        };
    }

    static bool isLogin(String ^ pin) {
        try {
            if (pin == "") {
                throw gcnew Exception(L"Vui lòng nhập mã pin");
            } else if (!Validate::isPin(pin)) {
                throw gcnew Exception(L"Mã pin không hợp lệ");
            }
            array<User ^> ^ users = UserRepository::GetUsers();
            if (users == nullptr) {
                throw gcnew Exception(L"Lỗi máy chủ, thử lại sau !");
            }
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getAccountNumber() == GlobalData::GetCurrentUser()->AccountNumber) {
                    if (users[i]->getPin() == 0) {
                        throw gcnew Exception(L"Hãy đạt mã PIN trước khi thêm mã thanh toán");

                    } else if (users[i]->getPin() != Convert::ToInt32(pin)) {
                        throw gcnew Exception(L"Mã pin không hợp lệ !");
                    }
                }
            }
            return true;

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void Logout() {
        try {
            GlobalData::SetCurrentUser(nullptr);
            /*UserRepository::DeleteCache();
            CustomerCodesRepository::DeleteCache();
            CustomerCodeDetailsRepository::DeleteCache();
            RecurringPaymentsRepository::DeleteCache();
            NotificationsRepository::DeleteCache();
            TransactionsRepository::DeleteCache();
            ServicesRepository::DeleteCache();
            SavingCustomersRepository::DeleteCache();*/

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

};

