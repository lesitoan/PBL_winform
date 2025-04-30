#include "SelectReceiverForm.h"


namespace BankingAppwinform {
SelectReceiverForm::SelectReceiverForm(User ^ user) {
    InitializeComponent();
    loadAccHistory(user);
    GradientColorHelper::ApplyGradient(this);
}

SelectReceiverForm::~SelectReceiverForm() {
    if (components) {
        delete components;
    }
}
void SelectReceiverForm::loadAccHistory(User ^ user) {
    try {
        selectAccHistory->Items->Clear();

        array<String ^> ^ accHistoryString = UserService::GetHistoryReceivers(user->Id);
        if (accHistoryString == nullptr || accHistoryString->Length == 0) {
            return;
        }

        for (int i = 0; i < accHistoryString->Length; i++) {
            selectAccHistory->Items->Add(accHistoryString[i]);
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->ToString(), L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
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
    Bank bankEnum = static_cast<Bank>(Enum::Parse(Bank::typeid, bankName));

    String ^ accName = parts[1];
    String ^ accNumber = parts[2];
    double amount = Convert::ToDouble(parts[3]);

    SelectReceiverSuccess(this, gcnew SelectReceiverEventArgs(
                                    bankEnum, accName, accNumber, amount));

    this->Close();
}
System::Void SelectReceiverForm::btnClose_Click_1(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
    this->Close();
}

} // namespace BankingAppwinform