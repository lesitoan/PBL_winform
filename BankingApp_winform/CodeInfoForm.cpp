#include "CodeInfoForm.h"

namespace BankingAppwinform {

CodeInfoForm::CodeInfoForm(PaymentCodes ^ paymentCode) {
    InitializeComponent(); 
    loadData(paymentCode);
}

CodeInfoForm::~CodeInfoForm() {
    if (components) {
        delete components;
    }
}

void CodeInfoForm::loadData(PaymentCodes ^ paymentCode) {
    code->Text = paymentCode->Code;
    amount->Text = paymentCode->Amount.ToString();

    String ^ statusMessage = paymentCode->Status == 0 ? L"Chưa thanh toán" : L"Đã thanh toán";
    status->Text = statusMessage;
    createdDate->Text = paymentCode->CreatedDate.ToString();
    expiredDate->Text = paymentCode->ExpiredDate.ToString();
    String ^ paymentDateString = paymentCode->PaymentDate == ""
                                     ? L"Chưa thanh toán"
                                     : paymentCode->PaymentDate;
    paymentDate->Text = paymentDateString;
}

} // namespace BankingAppwinform
