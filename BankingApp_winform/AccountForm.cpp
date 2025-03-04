#include "AccountForm.h"

namespace BankingAppwinform {
AccountForm::AccountForm(void) { InitializeComponent(); }

AccountForm::~AccountForm() {
    if (components) {
        delete components;
    }
}

System::Void AccountForm::AccountForm_Load(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    if (!GlobalData::GetCurrentUser()->getPin()) {
        this->btnSetPin->Text = "Tao PIN";
    }
    this->labelFullName->Text = GlobalData::GetCurrentUser()->getFullName();
    this->labelAccountNumber->Text =
        GlobalData::GetCurrentUser()->getAccountNumber().ToString();
    this->labelBalance->Text =
        GlobalData::GetCurrentUser()->getBalance() + " VND";
}

System::Void AccountForm::btnChangePw_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew ChangePwForm());
    ChangeButtonColor(btnChangePw);
}

System::Void AccountForm::btnSetPin_Click(System::Object ^ sender,
                                          System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew SetPinForm());
    ChangeButtonColor(btnSetPin);
}

System::Void AccountForm::buttonSetAvatar_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {
    ChangeButtonColor(buttonSetAvatar);
}

System::Void AccountForm::btnDeleteAccount_Click(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    ChangeButtonColor(btnDeleteAccount);
}

System::Void AccountForm::panelNav_SizeChanged(System::Object ^ sender,
                                               System::EventArgs ^ e) {
    int parentWidth =
        panelNav->ClientSize.Width;   // Lấy chiều rộng của panel cha
    int panelWidth = parentWidth / 4; // Chia đều thành 3 phần

    // Cập nhật kích thước và vị trí của 3 panel con
    panelBtn1->Width = panelWidth;
    panelBtn2->Width = panelWidth;
    panelBtn3->Width = panelWidth; // Panel cuối cùng nhận phần dư
    panelBtn4->Width = panelWidth; // Panel cuối cùng nhận phần dư

    panelBtn1->Left = 0;
    panelBtn2->Left = panelWidth;
    panelBtn3->Left = panelWidth * 2;
    panelBtn4->Left = panelWidth * 3;
}
}; // namespace BankingAppwinform