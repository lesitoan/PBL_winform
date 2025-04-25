#include "ChangePwForm.h"
#include"GradientHelper.h"

namespace BankingAppwinform {

ChangePwForm::ChangePwForm(void) { 
    InitializeComponent(); 
    GradientColorHelper::ApplyGradient(this);
    //GradientColorHelper::ApplyGradient(this->panel1);
    //GradientColorHelper::ApplyRoundedCorners(this->panel1, 20);
}

ChangePwForm::~ChangePwForm() {
    if (components) {
        delete components;
    }
}

System::Void ChangePwForm::btnSubmit_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    try {
        UserService::ChangePassword(oldPassword->Text, newPassword->Text, newPasswordConfirm->Text);
        MessageBox::Show(L"Đổi mật khẩu thành công", "Tiêu đề",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->oldPassword->Text = "";
        this->newPassword->Text = "";
        this->newPasswordConfirm->Text = "";

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
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
