#include "WithdrawMoneyForm.h"
#include "GradientHelper.h"
namespace BankingAppwinform {

WithdrawMoneyForm::WithdrawMoneyForm(void) {
    InitializeComponent();
    this->labelBalance->Text = L"Số dư hiện tại: " +
                               GlobalData::GetCurrentUser()->getBalance() +
                               L" VNĐ";
    GradientColorHelper::ApplyGradient(this->panel1);
    GradientColorHelper::ApplyGradient(this->labelBalance);
}
WithdrawMoneyForm::~WithdrawMoneyForm() {
    if (components) {
        delete components;
    }
}

}; // namespace BankingAppwinform
