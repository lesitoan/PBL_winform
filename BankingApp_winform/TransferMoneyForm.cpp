﻿#include "TransferMoneyForm.h"

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
    }

    bool isTransferSuccess = Utils::transferMoney(GlobalData::GetCurrentUser()->getAccountNumber(),
                         receiver->getAccountNumber(), amount, pin);
    if (isTransferSuccess) {
        MessageBox::Show(L"Chuyển tiền thành công", "Thong bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
    } else {
        MessageBox::Show(L"Chuyển tiền thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

}
};
