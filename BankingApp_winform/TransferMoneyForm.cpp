#include "TransferMoneyForm.h"

namespace BankingAppwinform {
TransferMoneyForm::TransferMoneyForm(void) { InitializeComponent(); }

TransferMoneyForm::~TransferMoneyForm() {
    if (components) {
        delete components;
    }
}
System::Void TransferMoneyForm::btnFindAccount_Click(System::Object ^ sender,
                                                     System::EventArgs ^ e) {
    String ^ bank = selectBankBox->Text;
    String ^ accNumber = accountNumber->Text;

    if (bank == "" || accNumber == "") {
        MessageBox::Show("Nhap day du thong tin !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        panelTransfer->Visible = false;
        return;
    } else if (!Validate::isAccountNumber(accNumber)) {
        MessageBox::Show("So tai khoan khong hop le !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        panelTransfer->Visible = false;
        return;
    } else {
        // tim user
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");

        if (users == nullptr) {
            MessageBox::Show("Khong tim thay tai khoan !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        } else {

            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getAccountNumber() ==
                        Convert::ToInt32(accNumber) &&
                    users[i]->getBankName() == bank &&
                    GlobalData::GetCurrentUser()->getAccountNumber() ==
                        users[i]->getAccountNumber()) {
                    MessageBox::Show("Khong duoc chuyen khoan cho chinh ban !",
                                     "Canh bao", MessageBoxButtons::OK,
                                     MessageBoxIcon::Warning);
                    panelTransfer->Visible = false;
                    return;
                } else if (users[i]->getAccountNumber() ==
                               Convert::ToInt32(accNumber) &&
                           users[i]->getBankName() == bank) {
                    this->receiver = users[i];
                    receiverIndex = i;
                    break;
                } else {
                    receiver = nullptr;
                    receiverIndex = -1;
                }
            }
        }
        if (this->receiver == nullptr) {
            MessageBox::Show("Khong tim thay tai khoan !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        } else {
            panelTransfer->Visible = true;
            labelReceiver->Text = L"Người nhận: " + receiver->getFullName();
        }
    }
}

// so tien ck toi thieu 10k, toi da 2.000.000 ?
System::Void TransferMoneyForm::btnSubmit_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {
    double amount = 0;
    int pin = 0;

    if (this->pinInput->Text == "" || this->amountInput->Text == "") {
        MessageBox::Show("Nhap day du thong tin !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (!Validate::isNumber(amountInput->Text)) {
        MessageBox::Show("So tien khong hop le !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (!Validate::isPin(this->pinInput->Text)) {
        MessageBox::Show("Ma pin khong hop le !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else {
        amount = Convert::ToDouble(this->amountInput->Text);
        pin = Convert::ToInt32(this->pinInput->Text);
    }

    if (amount < 10000) {
        MessageBox::Show("So tien ck toi thieu la 10.000 VND !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else {
        User ^ sender = GlobalData::GetCurrentUser();

        // xac thuc ma pin
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        for (int i = 0; i < users->Length; i++) {
            if (users[i]->getAccountNumber() == sender->getAccountNumber() &&
                users[i]->getPin() == pin) {
                // check so du va chuyen khoan
                if (sender->getBalance() < amount) {
                    MessageBox::Show("So du khong du de thuc hien giao dich !",
                                     "Canh bao", MessageBoxButtons::OK,
                                     MessageBoxIcon::Warning);
                    return;
                } else {
                    sender->setBalance(sender->getBalance() - amount);
                    receiver->setBalance(receiver->getBalance() + amount);

                    // luu lai 2 user vao file
                    users[i] = sender;
                    users[receiverIndex] = receiver;
                    bool isSavedUser =
                        HandleFile::WriteUserArray(users, "users.dat");
                    if (!isSavedUser) {
                        MessageBox::Show("loi may chu, thu lai sau !",
                                         "Canh bao", MessageBoxButtons::OK,
                                         MessageBoxIcon::Warning);
                        return;
                    } else {
                        // luu lich su giao dich
                        Transaction ^ transaction =
                            gcnew Transaction(123, sender->getAccountNumber(),
                                              receiver->getAccountNumber(),
                                              amount, DateTime::Now.ToString());
                        array<Transaction ^> ^ transactions =
                            HandleFile::ReadTransactionArray(
                                "transactions.dat");
                        if (transactions == nullptr) {
                            transactions = gcnew array<Transaction ^>(1);
                            transactions[0] = transaction;
                        } else {
                            array<Transaction ^> ^ newTransactions =
                                gcnew array<Transaction ^>(
                                    transactions->Length + 1);
                            for (int i = 0; i < transactions->Length; i++) {
                                newTransactions[i] = transactions[i];
                            }
                            newTransactions[transactions->Length] = transaction;
                            transactions = newTransactions;
                        }
                        bool isSavedTransaction =
                            HandleFile::WriteTransactionArray(
                                transactions, "transactions.dat");

                        // thong bao chuyen tien thanh cong
                        if (isSavedTransaction && isSavedUser) {
                            MessageBox::Show("Chuyen tien thanh cong !",
                                             "Thong bao", MessageBoxButtons::OK,
                                             MessageBoxIcon::Information);
                            return;
                        } else {
                            MessageBox::Show("loi may chu, thu lai sau !",
                                             "Canh bao", MessageBoxButtons::OK,
                                             MessageBoxIcon::Warning);
                            return;
                        }
                    }
                }
            } else if (users[i]->getAccountNumber() ==
                       sender->getAccountNumber()) {
                if (users[i]->getPin() == 0) {
                    MessageBox::Show("khach hang chua dang ki ma pin !",
                                     "Canh bao", MessageBoxButtons::OK,
                                     MessageBoxIcon::Warning);
                    return;
                }
                return;
            }
        }
    }
}
}; // namespace BankingAppwinform
