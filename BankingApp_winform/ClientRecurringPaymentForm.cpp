#include "ClientRecurringPaymentForm.h"

namespace BankingAppwinform {

ClientRecurringPaymentForm::ClientRecurringPaymentForm(void) {
    InitializeComponent();
    loadRecurringPaymentData();
}

ClientRecurringPaymentForm::~ClientRecurringPaymentForm() {
    if (components) {
        delete components;
    }
}


void ClientRecurringPaymentForm::loadRecurringPaymentData() {
    dataGridViewRecurring->Rows->Clear();
    array<RecurringPayments ^> ^ recurringPayments =
        HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");

    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");

    array<CustomerCodes ^> ^ customerCodes =
        HandleFile::ReadCustomerCodesArray("customerCodes.dat");

    if (users == nullptr || recurringPayments == nullptr) {
        return;
    }

    // lấy ta các mã khách hàng của người dùng hiện tại
    List<String ^> ^ customerCodesList = gcnew List<String ^>();
    for each (CustomerCodes ^ code in customerCodes) {
        if (code->CompanyAccountNumber ==
            GlobalData::GetCurrentUser()->getAccountNumber()) {
            customerCodesList->Add(code->Code);
        }
    }

    for each (RecurringPayments ^ payment in recurringPayments) {

        for each (String ^ currCustomerCode in customerCodesList) {
            if (payment->CustomerCodeId == currCustomerCode) {

                // tìm người dùng có mã tài khoản là mã khách hàng để lấy tên và stk
                User ^ user = nullptr;
                for each (User ^ u in users) {
                    if (u->AccountNumber == payment->UserAccountNumber) {
                        user = u;
                        break;
                    }
                }

                if (user == nullptr) {
                    continue; // không tìm thấy người dùng
                }

                dataGridViewRecurring->Rows->Add(
                    currCustomerCode, user->FullName, user->AccountNumber,
                    payment->PaymentDay);
                int lastRow = dataGridViewRecurring->Rows->Count - 1;
                dataGridViewRecurring->Rows[lastRow]->Tag = payment;

            }
        }
    }
}

} // namespace BankingAppwinform
