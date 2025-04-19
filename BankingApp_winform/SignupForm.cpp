#include "SignupForm.h"

namespace BankingAppwinform {

SignupForm::SignupForm(void) {
    InitializeComponent();
}

SignupForm::~SignupForm() {
    if (components) {
        delete components;
    }
}

System::Void SignupForm::btnSubmit_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    try {
        AuthServices::Signup(fullName->Text, phoneNumber->Text, password->Text, passwordConfirm->Text);
        MessageBox::Show(L"Đăng kí tài khoản thành công !", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        SignupSuccess(this, EventArgs::Empty);

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void SignupForm::label4_Click(System::Object ^ sender,
                                      System::EventArgs ^ e) {
    if (passwordConfirm->PasswordChar == '\0') {
        passwordConfirm->PasswordChar = '\*';
    } else {
        passwordConfirm->PasswordChar = '\0';
    }
}

System::Void SignupForm::label2_Click(System::Object ^ sender,
                                      System::EventArgs ^ e) {
    if (password->PasswordChar == '\0') {
        password->PasswordChar = '\*';
    } else {
        password->PasswordChar = '\0';
    }
}

}; // namespace BankingAppwinform
