#pragma once
#include "HandleFile.h"
#include "User.h"
#include "UserRepository.h"
#include "Validate.h"
#include "Utils.h"

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
            if (user->getPassword() != pass) {
                throw gcnew Exception(L"Số điện thoại hoặc mật khẩu không đúng");
            }
            if (user->Status == 0) {
                throw gcnew Exception(L"Tài khoản của bạn đã bị khóa");
            }

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

            String ^ accNum = Utils::createUniqueID("");
            User ^ user = gcnew User(fullName, password, phoneNumber, accNum);
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
            UserRepository::UpdateUserByAccNumber(user->AccountNumber, user);

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
            UserRepository::UpdateUserByAccNumber(user->getAccountNumber(), user);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void AddUser(String ^ name, String ^ phone, String ^ accNum,
                        String ^ password, String^ accType, String^ serviceId) {
        try {

            if (name == "" || phone == "" || accNum == "" || password == "" ||
                accType == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");

            } else if (accType == "company" && serviceId == "") {
                throw gcnew Exception(L"Chưa chọn dịch vụ");
            }

            User ^ currentUser = UserRepository::FindUserByPhoneNumber(phone);

            if (currentUser != nullptr && currentUser->AccountNumber == accNum) {
                throw gcnew Exception(L"Số điện thoại đã tồn tại");

            }

            double _balance = 0;
            int _pin = 0;
            String ^ _bankName = "BIDV";
            int _status = 1;

            User ^ user =
                gcnew User(name, password, phone, accNum, _balance,
                           accType, _pin, _bankName, _status, serviceId, "BankingApp_winform\\images\\avatars\\default_avatar.png");

            UserRepository::InsertUser(user);

        } catch (Exception ^ ex) {

            MessageBox::Show(ex->ToString(), "Success",
                             MessageBoxButtons::OK, MessageBoxIcon::Information);
            throw ex;
        };
    }

};

