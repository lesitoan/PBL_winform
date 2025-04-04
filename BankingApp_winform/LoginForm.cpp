﻿#include "LoginForm.h"

namespace BankingAppwinform {
LoginForm::LoginForm(void) { this->InitializeComponent(); }

LoginForm::~LoginForm() {
    if (components) {
        delete components;
    }
}
System::Void LoginForm::btnSubmit_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {

    String ^ phone = this->phoneNumber->Text;
    String ^ pass = this->password->Text;
    if (phone == "" || pass == "") {
        MessageBox::Show(L"Vui lòng nhập đầy đủ thông tin");
        return;
    } else {
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        for each (User ^ user in users) {
            if (user->getPhoneNumber() == phone &&
                user->getPassword() == pass) {
                if (user->Status == 0) {
                    MessageBox::Show(L"Tài khoản của bạn đã bị khóa");
                    return;
                }

                GlobalData::SetCurrentUser(user);
                MessageBox::Show(L"Đăng nhập thành công");
                LoginSuccess(this, EventArgs::Empty);
                return;
            }
        }
        MessageBox::Show(L"Đăng nhập thất bại");
    }
}
System::Void LoginForm::btnShowPw_CheckedChanged(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    if (this->btnShowPw->Checked) {
        this->password->PasswordChar = '\0';
    } else {
        this->password->PasswordChar = '*';
    }
}
}; // namespace BankingAppwinform
