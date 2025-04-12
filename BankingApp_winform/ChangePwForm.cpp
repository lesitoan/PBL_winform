#include "ChangePwForm.h"
#include"GradientHelper.h"

namespace BankingAppwinform {

ChangePwForm::ChangePwForm(void) { 
    InitializeComponent(); 
    GradientColorHelper::ApplyGradient(this);
    GradientColorHelper::ApplyGradient(this->panel1);
    GradientColorHelper::ApplyRoundedCorners(this->panel1, 20);
}

ChangePwForm::~ChangePwForm() {
    if (components) {
        delete components;
    }
}

System::Void ChangePwForm::btnSubmit_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    if (oldPassword->Text == "" || newPassword->Text == "" ||
        newPasswordConfirm->Text == "") {
        MessageBox::Show("Vui long nhap day du thong tin !", "Tiêu đề",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
    } else if (newPassword->Text != newPasswordConfirm->Text) {
        MessageBox::Show("Mat khau moi khong trung khop !", "Tiêu đề",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
    } else if (oldPassword->Text !=
               GlobalData::GetCurrentUser()->getPassword()) {
        MessageBox::Show("Mat khau khong dung !", "Tiêu đề",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
    } else {
        // luu user vao file
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        if (users == nullptr) {
            MessageBox::Show("Co loi xay ra !", "Tiêu đề",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        } else {
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getAccountNumber() ==
                    GlobalData::GetCurrentUser()->getAccountNumber()) {
                    users[i]->setPassword(newPassword->Text);
                    GlobalData::SetCurrentUser(users[i]);
                    break;
                }
            }
        }
        bool isSaved = HandleFile::WriteUserArray(users, "users.dat");
        if (isSaved) {
            MessageBox::Show("Doi mat khau thanh cong !", "Tiêu đề",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information);
        } else {
            MessageBox::Show("Co loi xay ra !", "Tiêu đề",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}

bool ChangePwForm::handleClickShowBtn(bool status,
                                      System::Windows::Forms::TextBox ^
                                          textbox) {
    if (status) {
        textbox->PasswordChar = '\0';
    } else {
        textbox->PasswordChar = '*';
    }
    return !status;
}

System::Void ChangePwForm::label1_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    if (showOldPw) {
        oldPassword->PasswordChar = '\0';
        showOldPw = false;
    } else {
        oldPassword->PasswordChar = '*';
        showOldPw = true;
    }
}

System::Void ChangePwForm::label2_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    showNewPw = handleClickShowBtn(showNewPw, newPassword);
}

System::Void ChangePwForm::label3_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    showNewPwConfirm = handleClickShowBtn(showNewPwConfirm, newPasswordConfirm);
}
}; // namespace BankingAppwinform
