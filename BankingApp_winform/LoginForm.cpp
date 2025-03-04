#include "LoginForm.h"

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
        MessageBox::Show("Vui long nhap day du thong tin");
        return;
    } else {
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        for each (User ^ user in users) {
            if (user->getPhoneNumber() == phone &&
                user->getPassword() == pass) {
                GlobalData::SetCurrentUser(user);
                MessageBox::Show("Dang nhap thanh cong");
                LoginSuccess(this, EventArgs::Empty);
                return;
            }
        }
        MessageBox::Show("Dang nhap that bai");
    }
}

System::Void LoginForm::btnShowPw_CheckedChanged(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    if (btnShowPw->Checked) {
        password->PasswordChar = '\0';
    } else {
        password->PasswordChar = '*';
    }
}
}; // namespace BankingAppwinform
