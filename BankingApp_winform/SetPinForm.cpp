#include "SetPinForm.h"

namespace BankingAppwinform {
SetPinForm::SetPinForm(void) { 
    InitializeComponent(); 
    GradientColorHelper::ApplyGradient(this);
    /*GradientColorHelper::ApplyGradient(this->panel1);
    GradientColorHelper::ApplyRoundedCorners(this->panel1,20);*/
}

SetPinForm::~SetPinForm() {
    if (components) {
        delete components;
    }
}
System::Void SetPinForm::btnSubmit_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    try {
        UserService::UpdatePin(pin->Text, password->Text);

        MessageBox::Show(L"Cập nhật mã PIN thành công", L"Thông báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->pin->Text = "";
        this->password->Text = "";
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
    }
}

System::Void SetPinForm::btnShowPw_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    if (isShowPw) {
        password->PasswordChar = '\0';
        isShowPw = false;
    } else {
        password->PasswordChar = '*';
        isShowPw = true;
    }
}

};
 // namespace BankingAppwinform
