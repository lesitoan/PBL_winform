#include "TransferMoneyForm.h"
#include "GradientHelper.h"

namespace BankingAppwinform {
TransferMoneyForm::TransferMoneyForm(void) { 
    InitializeComponent(); 
    loadBank();
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
        if (selectBankBox->SelectedIndex == -1 || accountNumber->Text->Trim() == "") {
            MessageBox::Show("Nhập đầy đủ thông tin!", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        }

        String ^ accNumber = accountNumber->Text->Trim();
        String ^ bankText = selectBankBox->SelectedItem->ToString();
        Bank bank = static_cast<Bank>(Enum::Parse(Bank::typeid, bankText));

        // tìm user theo số tài khoản và ngân hàng
        User ^ receiver = UserService::FindUserByAccNumber(accNumber);

        if (receiver == nullptr || bank != receiver->getBankName()) {
            MessageBox::Show(L"Không tìm thấy tài khoản!", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        }

        this->receiver = receiver;
        panelTransfer->Visible = true;
        labelReceiver->Text = L"Người nhận: " + receiver->getFullName();

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
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

        // Cập nhật số dư của người gửi và người nhận
        GlobalData::GetCurrentUser()->setBalance(
            GlobalData::GetCurrentUser()->getBalance() - Convert::ToDouble(amount));

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
    Bank selectedBankName = e->BankName;
    String ^ selectedAccountName = e->AccountName;
    String ^ selectedAccountNumber = e->AccountNumber;
    double selectedAmount = e->Amount;

    selectBankBox->Text = selectedBankName.ToString();
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

void TransferMoneyForm::loadBank() {
    selectBankBox->Items->Clear();

    // Thêm tất cả các giá trị enum Bank vào ComboBox
    for each (Bank bank in Enum::GetValues(Bank::typeid)) {
        selectBankBox->Items->Add(bank.ToString());
    }

    // Tùy chọn: đặt mặc định không chọn gì
    selectBankBox->SelectedIndex = -1;
}

}; // namespace BankingAppwinform
