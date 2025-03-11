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
        MessageBox::Show(L"Vui lòng nhập đầy đủ thông tin!", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }else if (password->Text != passwordConfirm->Text) {
        MessageBox::Show(L"Mật khẩu không khớp nhau", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    } else if (!Validate::isValidPassword(password->Text)) {
        MessageBox::Show(L"Mật khẩu phải từ 6-9 kí tự, có ít nhất 1 chữ cái và 1 số, không chứ dấu cách", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    } else if (!Validate::isValidVietnamPhoneNumber(phoneNumber->Text)) {
        MessageBox::Show(L"Số điện thoại không hợp lệ", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    } else if (!Validate::isValidCustomerName(fullName->Text)) {
        MessageBox::Show(L"Tên chỉ được viết in hoa không dấu và ít nhất 2 từ", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    } else if (isUsedPhoneNumber(phoneNumber->Text)) {
        MessageBox::Show(L"Số điện thoại đã được sử dụng", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }


    int accNum = randomAccountNumber();
    // luu user vao file
    User ^ user =
        gcnew User(fullName->Text, password->Text, phoneNumber->Text, accNum);
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
        MessageBox::Show(L"Đăng kí tài khoản thành công !", "Success",
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
bool SignupForm::isUsedPhoneNumber(String ^ phoneNumber) {
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    for each (User ^ user in users) {
        if (user->getPhoneNumber() == phoneNumber) {
            return true;
        }
    }
    return false;
}

int SignupForm::randomAccountNumber() {
    Random ^ random = gcnew Random();
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    if (users == nullptr) {
        return random->Next(100000000, 1000000000);
    }
    while (true) {
        int accNum = random->Next(100000000, 1000000000);
        bool isUnique = true;
        for each (User ^ user in users) {
            if (user->getAccountNumber() == accNum) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            return accNum;
        }
        if (users->Length >= 900000000) {
            throw gcnew Exception(L"Không thể tạo số tài khoản mới");
        }
    }
}

}; // namespace BankingAppwinform
