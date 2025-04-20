#include "TransferMoneyForm.h"
#include "GradientHelper.h"

namespace BankingAppwinform {
TransferMoneyForm::TransferMoneyForm(void) { 
    InitializeComponent(); 
    GradientColorHelper::ApplyGradient(this->panelTransfer);
    GradientColorHelper::ApplyGradient(this->panel1);
    GradientColorHelper::ApplyGradient(this->panel2);
}

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
                if (users[i]->getAccountNumber() == accNumber &&
                    users[i]->getBankName() == bank &&
                    GlobalData::GetCurrentUser()->getAccountNumber() ==
                        users[i]->getAccountNumber()) {
                    MessageBox::Show("Khong duoc chuyen khoan cho chinh ban !",
                                     "Canh bao", MessageBoxButtons::OK,
                                     MessageBoxIcon::Warning);
                    panelTransfer->Visible = false;
                    return;
                } else if (users[i]->getAccountNumber() == accNumber &&
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
    bool isTransferSuccess =
        Utils::transferMoney(GlobalData::GetCurrentUser()->getAccountNumber(),
                             receiver->getAccountNumber(), amount, pin);
    if (isTransferSuccess) {
        MessageBox::Show(L"Chuyển tiền thành công", "Thong bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->accountNumber->Text = "";
        this->pinInput->Text = "";
        this->amountInput->Text = "";
        this->message->Text = "";
        this->panelTransfer->Visible = false;

    } else {
        MessageBox::Show(L"Chuyển tiền thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void
TransferMoneyForm::onSelectReceiverSuccess(System::Object ^ sender,
                                           SelectReceiverEventArgs ^ e) {
    // Nhận dữ liệu từ sự kiện
    String ^ selectedBankName = e->BankName;
    String ^ selectedAccountName = e->AccountName;
    String ^ selectedAccountNumber = e->AccountNumber;
    double selectedAmount = e->Amount;

    selectBankBox->Text = selectedBankName;
    accountNumber->Text = selectedAccountNumber;

    panelTransfer->Visible = true;
    labelReceiver->Text = L"Người nhận: " + selectedAccountName;

    amountInput->Text = selectedAmount.ToString();

    this->receiver = gcnew User(selectedBankName, selectedAccountName,
                                selectedAccountNumber);
}

System::Void
TransferMoneyForm::btnSelectAccHistory_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    SelectReceiverForm ^ selectReceiverForm =
        gcnew SelectReceiverForm(GlobalData::GetCurrentUser());
    selectReceiverForm->SelectReceiverSuccess +=
        gcnew EventHandler<SelectReceiverEventArgs ^>(
            this, &TransferMoneyForm::onSelectReceiverSuccess);

    selectReceiverForm->ShowDialog();
}

System::Void
TransferMoneyForm::accountNumber_TextChanged(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    panelTransfer->Visible = false;
    labelReceiver->Text = "";
    amountInput->Text = "";
    pinInput->Text = "";
}

System::Void
TransferMoneyForm::selectBankBox_TextChanged(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    panelTransfer->Visible = false;
    labelReceiver->Text = "";
    amountInput->Text = "";
    pinInput->Text = "";
}

}; // namespace BankingAppwinform
