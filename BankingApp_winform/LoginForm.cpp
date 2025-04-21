#include "LoginForm.h"


namespace BankingAppwinform {

LoginForm::LoginForm(void) {
    this->InitializeComponent();
}

LoginForm::~LoginForm() {
    if (components) {
        delete components;
    }
}
System::Void LoginForm::btnSubmit_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    try {
        User ^ user = AuthServices::Login(this->phoneNumber->Text, this->password->Text);
        MessageBox::Show(L"Đăng nhập thành công", L"Thành công", MessageBoxButtons::OK, MessageBoxIcon::Information);
        LoginSuccess(this, EventArgs::Empty);

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Lỗi đăng nhập", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void LoginForm::btnShowPassword_Click(System::Object ^ sender, System::EventArgs ^ e) {
    if (this->password->PasswordChar == '\0')
        this->password->PasswordChar = '*';
    else
        this->password->PasswordChar = '\0';
}

}; // namespace BankingAppwinform
