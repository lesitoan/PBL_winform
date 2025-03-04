#include "SignupForm.h"

namespace BankingAppwinform {

SignupForm::SignupForm(void) { InitializeComponent(); }

SignupForm::~SignupForm() {
    if (components) {
        delete components;
    }
}

System::Void SignupForm::btnSubmit_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    // kiem tra da nhap du thong tin chua
    if (fullName->Text->Length == 0 || password->Text->Length == 0 ||
        passwordConfirm->Text->Length == 0 || phoneNumber->Text->Length == 0) {
        MessageBox::Show("Vui long nhap day du thong tin !", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (password->Text != passwordConfirm->Text) {
        MessageBox::Show("Mat khau khong khop !", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    if (password->Text->Length < 6) {
        MessageBox::Show("Mat khau phai co it nhat 6 ki tu !", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (phoneNumber->Text->Length != 10) {
        MessageBox::Show("Sai dinh dang so dien thoai !", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    // kiem tra ten > 5 ki tu
    if (fullName->Text->Length < 5) {
        MessageBox::Show("Ten phai co it nhat 5 ki tu !", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // luu user vao file
    User ^ user = gcnew User(fullName->Text, password->Text, phoneNumber->Text);
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    if (users == nullptr) {
        users = gcnew array<User ^>{user};
    } else {
        array<User ^> ^ newUsers = gcnew array<User ^>(users->Length + 1);
        for (int i = 0; i < users->Length; i++) {
            newUsers[i] = users[i];
        }
        newUsers[users->Length] = user;
        users = newUsers;
    }
    bool isSaved = HandleFile::WriteUserArray(users, "users.dat");
    if (isSaved) {
        MessageBox::Show("Dang ki thanh cong !", "Success",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
        // Chuyen sang trang dang nhap
        SignupSuccess(this, EventArgs::Empty);
    }
}

System::Void SignupForm::btnShowPwCf_CheckedChanged(System::Object ^ sender,
                                                    System::EventArgs ^ e) {
    if (btnShowPwCf->Checked) {
        passwordConfirm->PasswordChar = '\0';
        btnShowPwCf->Text = "Hide";
    } else {
        passwordConfirm->PasswordChar = '*';
        btnShowPwCf->Text = "Show";
    }
}

Void SignupForm::btnShowPw_CheckedChanged(System::Object ^ sender,
                                          System::EventArgs ^ e) {
    if (btnShowPw->Checked) {
        password->PasswordChar = '\0';
        btnShowPw->Text = "Hide";
    } else {
        password->PasswordChar = '*';
        btnShowPw->Text = "Show";
    }
}
}; // namespace BankingAppwinform
