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

};

