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
    try {
        String ^ bank = selectBankBox->Text;
        String ^ accNumber = accountNumber->Text;

        if (bank == "" || accNumber == "") {
            MessageBox::Show("Nhap day du thong tin !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        }
        // tim user
        User ^ receiver = UserService::FindUserByAccNumber(accNumber);
        if (receiver == nullptr) {
            MessageBox::Show("Khong tim thay tai khoan !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        }
        this->receiver = receiver;
        panelTransfer->Visible = true;
        labelReceiver->Text = L"Người nhận: " + receiver->getFullName();
 
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông tin", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
    }
}

System::Void TransferMoneyForm::btnSubmit_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {
    try {
        double amount = 0;
        if (!Double::TryParse(amountInput->Text, amount)) {
            MessageBox::Show("Số tiền không hợp lệ", "Thông báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }
        int pin = 0;
        if (!Int32::TryParse(pinInput->Text, pin)) {
            MessageBox::Show("Mã pin không hợp lệ", "Thông báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }
        String ^ accNumber = accountNumber->Text;

        String ^ message = this->message->Text;
        
        UserService::TransferMoney(
            GlobalData::GetCurrentUser()->AccountNumber, accNumber, amount,
            pin, message, "");

        MessageBox::Show(L"Chuyển tiền thành công", "Thong bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->accountNumber->Text = "";
        this->pinInput->Text = "";
        this->amountInput->Text = "";
        this->message->Text = "";
        this->panelTransfer->Visible = false;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông tin", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
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
