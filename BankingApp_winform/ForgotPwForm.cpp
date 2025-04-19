#include "ForgotPwForm.h"

#pragma once

namespace BankingAppwinform {

    ForgotPwForm::ForgotPwForm(void) {
        InitializeComponent();

    }

    ForgotPwForm::~ForgotPwForm() {
        if (components) {
            delete components;
        }
    }

    System::Void ForgotPwForm::btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        try {
            // Lấy thông tin từ form
            String ^ fullName = this->fullName->Text;
            String ^ phoneNumber = this->phoneNumber->Text;

            if (fullName->Length == 0 ||
                phoneNumber->Length == 0) {
                MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            } else if (!Validate::isValidVietnamPhoneNumber(phoneNumber)) {
                MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            } else if (!Validate::isValidCustomerName(fullName)) {
                MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Kiểm tra thông tin nhập vào có trùng với thông tin trong file
            User ^ user = UserRepository::FindUserByPhoneNumber(phoneNumber);

            if (user->getFullName() != fullName) {
                MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            DateTime now = DateTime::Now;
            String ^ newPassword = "TML" + now.ToString("HHmmss");

            user->setPassword(newPassword);

            // Lưu lại thông tin vào file
            UserRepository::UpdateUserByAccNumber(user->AccountNumber, user);

            MessageBox::Show(L"Lấy lại mật khẩu thành công! Mật khẩu mới là: " + newPassword,
                             "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

        
        } catch (Exception ^ ex) {
            MessageBox::Show(L"Có lỗi xảy ra, thử lại sau", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

};


