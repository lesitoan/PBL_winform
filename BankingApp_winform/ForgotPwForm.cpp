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
            String ^ fullName = this->fullName->Text;
            String ^ phoneNumber = this->phoneNumber->Text;

            String^ newPassword = AuthServices::ForgotPassword(phoneNumber, fullName);

            MessageBox::Show(L"Lấy lại mật khẩu thành công! Mật khẩu mới là: " + newPassword,
                             "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

        
        } catch (Exception ^ ex) {
            MessageBox::Show(ex->Message, "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

};


