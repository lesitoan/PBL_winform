#include "RegisterSavingForm.h"
#include"GradientHelper.h"

namespace BankingAppwinform {
RegisterSavingForm::RegisterSavingForm(String ^ type) {
    InitializeComponent();
    this->type = type;
}

RegisterSavingForm::~RegisterSavingForm() {
    if (components) {
        delete components;
    }
}

System::Void RegisterSavingForm::RegisterSavingForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
    this->labelBalance->Text = L"Số dư khả dụng: " +
                               GlobalData::GetCurrentUser()->getBalance() +
                               L" VND";
    if (type == "termDeposit") {
        header->Text = L"GỬI TIẾT KIỆM CÓ KÌ HẠN";
        labelInfo->Text = L"Gửi tiết kiệm có kì hạn với lãi xuất (3T 4.5%/năm, "
                          L"6T 5%/năm, 9T 5.5%/năm, 12T 6%/năm) "
                          L"bạn có thể rút tiền sau khi hết kì hạn";
    } else {
        header->Text = L"GỬI TIẾT KIỆM KHÔNG KÌ HẠN";
        labelInfo->Text = L"Gửi tiết kiệm không kì hạn với lãi xuất 4% / năm, "
                          L"bạn có thể rút tiền bất cứ khi nào";
        label5->Text = L"Chọn kì hạn:";
        selectTermBox->Items->Clear();
        selectTermBox->Items->Add(L"Không kì hạn");
        selectTermBox->SelectedIndex = 0;
        selectTermBox->Enabled = false;
    }
    GradientColorHelper::ApplyGradient(this);
    GradientColorHelper::ApplyRoundedCorners(this->panel1, 8);
}



System::Void RegisterSavingForm::btnSubmit_Click(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    try {
        String ^ amount = amountInput->Text;
        String ^ pin = pinInput->Text;
        int term = 0;

        if (this->type == "termDeposit") {
            if (selectTermBox->SelectedIndex == -1) {
                MessageBox::Show(L"Vui lòng chọn kì hạn");
                return;
            } else {
                term = Convert::ToInt32(selectTermBox->Text);
            }
        }

        SavingServices::AddSaving(this->type, amount, pin, term);

        MessageBox::Show(L"Đăng ký tiết kiệm thành công");
        this->AddSavingSuccess(this, EventArgs::Empty);
        this->Close();

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return;
    }
}

System::Void RegisterSavingForm::btnClose_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {
    this->Close();
}

} // namespace BankingAppwinform