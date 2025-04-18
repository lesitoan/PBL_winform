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
        String ^ phone = this->phoneNumber->Text;
        String ^ pass = this->password->Text;
        if (phone == "" || pass == "") {
            MessageBox::Show(L"Vui lòng nhập đầy đủ thông tin");
            return;
        }
        User ^ user = UserRepository::FindUserByPhoneNumber(phone);
        if (user == nullptr) {
            MessageBox::Show(L"Đăng nhập thất bại 1");
            return;
        }
        if (user->getPassword() != pass) {
            MessageBox::Show(L"Đăng nhập thất bại 2");
            return;
        }
        if (user->Status == 0) {
            MessageBox::Show(L"Tài khoản của bạn đã bị khóa");
            return;
        }
        GlobalData::SetCurrentUser(user);
        MessageBox::Show(L"Đăng nhập thành công", L"Thành công", MessageBoxButtons::OK, MessageBoxIcon::Information);
        LoginSuccess(this, EventArgs::Empty);

    } catch (Exception ^ ex) {
        MessageBox::Show(L"Lỗi đăng nhập, vui lòng thử lại sau", L"Lỗi đăng nhập", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void LoginForm::btnShowPassword_Click(System::Object ^ sender, System::EventArgs ^ e) {
    if (this->password->PasswordChar == '\0')
        this->password->PasswordChar = '*';
    else
        this->password->PasswordChar = '\0';
}

}; // namespace BankingAppwinform
