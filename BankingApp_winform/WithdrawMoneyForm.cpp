#include "WithdrawMoneyForm.h"
#include "GradientHelper.h"
namespace BankingAppwinform {

WithdrawMoneyForm::WithdrawMoneyForm(void) {
    InitializeComponent();
    this->labelBalance->Text = L"Số dư hiện tại: " +
                               GlobalData::GetCurrentUser()->getBalance() +
                               L" VNĐ";
    GradientColorHelper::ApplyGradient(this->panel1);
}

System::Void WithdrawMoneyForm::btnSubmit_Click(System::Object ^ sender, System::EventArgs ^ e) {

    try {
        UserService::WithDrawMoney(pin->Text, Convert::ToDouble(amount->Text));

        MessageBox::Show(L"Rút tiền thành công", L"Thông báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

WithdrawMoneyForm::~WithdrawMoneyForm() {
    if (components) {
        delete components;
    }
}

}; // namespace BankingAppwinform
