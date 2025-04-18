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
        // kiem tra da nhap du thong tin chua
        if (fullName->Text->Length == 0 || password->Text->Length == 0 ||
            passwordConfirm->Text->Length == 0 || phoneNumber->Text->Length == 0) {
            MessageBox::Show(L"Vui lòng nhập đầy đủ thông tin!", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        } else if (password->Text != passwordConfirm->Text) {
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
        }

        User ^ currentUser = UserRepository::FindUserByPhoneNumber(phoneNumber->Text);
        if (currentUser != nullptr) {
            MessageBox::Show(L"Số điện thoại đã được sử dụng", "Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String ^ accNum = Utils::createUniqueID("");
        User ^ user = gcnew User(fullName->Text, password->Text, phoneNumber->Text, accNum);
        UserRepository::InsertUser(user);
        MessageBox::Show(L"Đăng kí tài khoản thành công !", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        SignupSuccess(this, EventArgs::Empty);

    } catch (Exception ^ ex) {
        MessageBox::Show(L"Có lỗi xảy ra, thử lại sau", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
