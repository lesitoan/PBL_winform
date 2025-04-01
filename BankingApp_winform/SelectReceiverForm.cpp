#include "SelectReceiverForm.h"

namespace BankingAppwinform {
SelectReceiverForm::SelectReceiverForm(User ^ user) {
    InitializeComponent();
    loadAccHistory(user);
}

SelectReceiverForm::~SelectReceiverForm() {
    if (components) {
        delete components;
    }
}
void SelectReceiverForm::loadAccHistory(User ^ user) {
    array<Transaction ^> ^ transactions =
        HandleFile::ReadTransactionArray("transactions.dat");
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");

    String^ accNumber = user->AccountNumber;

    accHistory = gcnew List<String ^>();

    int count = 0;
    int length = transactions->Length;

    while (length > 0 && count < 5) {
        if (transactions[length - 1]->getFromAccount() == accNumber &&
            transactions[length - 1]->getToAccount() != "") {
            for (int j = 0; j < users->Length; j++) {
                if (users[j]->AccountNumber ==
                        transactions[length - 1]->getToAccount() &&
                    users[j]->getRole() == "user") {
                    String ^ toAcc =
                        users[j]->getBankName() + " - " +
                        users[j]->getFullName() + " - " +
                        transactions[length - 1]->getToAccount() +
                        " - " +
                        transactions[length - 1]->getAmount().ToString();
                    accHistory->Add(toAcc);
                    break;
                }
            }
            count++;
        }
        length--;
    }
    for (int i = 0; i < accHistory->Count; i++) {
        selectAccHistory->Items->Add(accHistory[i]);
    }
}
System::Void SelectReceiverForm::btnSubmit_Click(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    if (selectAccHistory->Text == "") {
        MessageBox::Show("Chọn tài khoản từ lịch sử gần đây");
        return;
    }

    array<String ^> ^ parts = selectAccHistory->Text->Split(
        gcnew array<String ^>{" - "}, StringSplitOptions::RemoveEmptyEntries);

    String ^ bankName = parts[0];
    String ^ accName = parts[1];
    String ^ accNumber = parts[2];
    double amount = Convert::ToDouble(parts[3]);

    SelectReceiverSuccess(this, gcnew SelectReceiverEventArgs(
                                    bankName, accName, accNumber, amount));

    this->Close();
}
System::Void SelectReceiverForm::btnClose_Click_1(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
    this->Close();
}

} // namespace BankingAppwinform