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
    if (!Validate::isPin(this->pin->Text)) {
        MessageBox::Show("Pin phai co 6 chu so !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (this->password->Text == "") {
        MessageBox::Show("Mat khau khong chinh xac !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else {
        User ^ user = GlobalData::GetCurrentUser();
        if (user->getPassword() != this->password->Text) {
            MessageBox::Show("Mat khau khong chinh xac !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
        } else
        {

            // luu user vao file
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
            if (users == nullptr) {
                MessageBox::Show("Co loi xay ra !", "Tiêu đề",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            } else {
                for (int i = 0; i < users->Length; i++) {
                    if (users[i]->getAccountNumber() ==
                            GlobalData::GetCurrentUser()->getAccountNumber() &&
                        this->password->Text == users[i]->getPassword()) {
                        users[i]->setPin(Convert::ToInt32(this->pin->Text));
                        GlobalData::SetCurrentUser(users[i]);
                        break;
                    }
                }
            }
            bool isSaved = HandleFile::WriteUserArray(users, "users.dat");
            if (isSaved) {
                MessageBox::Show("Dat ma pin thanh cong !", "success",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Information);
            } else {
                MessageBox::Show("Co loi xay ra !", "success",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }
    this->pin->Text = "";
    this->password->Text = "";
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

    System::Void SetPinForm::btnShowConfirm_Click(System::Object ^ sender,
        System::EventArgs ^ e){
        if (txtConfirm->PasswordChar == '\0') {
            txtConfirm->PasswordChar = '\*';
        } else {
            txtConfirm->PasswordChar = '\0';
        }
    }
};
 // namespace BankingAppwinform
