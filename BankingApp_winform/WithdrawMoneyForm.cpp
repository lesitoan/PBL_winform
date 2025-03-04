#include "WithdrawMoneyForm.h"

namespace BankingAppwinform {

WithdrawMoneyForm::WithdrawMoneyForm(void) {
    InitializeComponent();
    this->labelBalance->Text = L"Số dư hiện tại: " +
                               GlobalData::GetCurrentUser()->getBalance() +
                               L" VNĐ";
}
WithdrawMoneyForm::~WithdrawMoneyForm() {
    if (components) {
        delete components;
    }
}

}; // namespace BankingAppwinform
