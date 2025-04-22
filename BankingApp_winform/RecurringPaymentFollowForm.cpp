#include "RecurringPaymentFollowForm.h"

namespace BankingAppwinform {

RecurringPaymentFollowForm::RecurringPaymentFollowForm(void) {
    InitializeComponent();
    LoadRecurringPaymentFollow();
}

RecurringPaymentFollowForm::~RecurringPaymentFollowForm() {
    if (components) {
        delete components;
    }
}

Void RecurringPaymentFollowForm::LoadRecurringPaymentFollow() {

    try {
        this->flowLayoutPanelFollow->Controls->Clear();

        array<RecurringPayments ^> ^ myRecurringPayments =
            RecurringPaymentServices::GetRecurringPaymentsByUserAccNumber(
                GlobalData::GetCurrentUser()->AccountNumber
            );

        if (myRecurringPayments == nullptr || myRecurringPayments->Length == 0) {
            return;
        }
        
        for (int i = myRecurringPayments->Length - 1; i >= 0; i--) {
            User ^ company = UserService::GetCompanyByCustomerCodeId(
                myRecurringPayments[i]->CustomerCodeId
            );
            if (company == nullptr) {
                continue;
            }

            Label ^ label = gcnew Label();
            label->AutoSize = false; // Tắt AutoSize để mình tự đặt kích thước
            label->Height = 30;      // Chiều cao dòng
            label->Width = flowLayoutPanelFollow->ClientSize.Width -
                           20; // chừa 10 padding mỗi bên
            label->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            label->Cursor = Cursors::Hand;
            label->Margin = System::Windows::Forms::Padding(
                10, 10, 10, 0); // padding giữa các dòng
            label->BackColor = Color::WhiteSmoke;
            label->Padding = System::Windows::Forms::Padding(
                5, 5, 5, 5); // padding trong label
            label->TextAlign = ContentAlignment::MiddleLeft;

            label->Text = L"Công ty: " + company->FullName +
                          L" | Ngày đến hạn: " +
                          myRecurringPayments[i]->PaymentDay;

            label->Tag = myRecurringPayments[i]->Id;
            label->Click += gcnew EventHandler(
                this, &RecurringPaymentFollowForm::labelFollow_Click);

            this->flowLayoutPanelFollow->Controls->Add(label);
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Tải dữ liệu thông báo thất bại, thử lại sau.", L"Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void RecurringPaymentFollowForm::labelFollow_Click(System::Object ^ sender, System::EventArgs ^ e) {
    try {
        Label ^ clickedLabel = dynamic_cast<Label ^>(sender);
        if (clickedLabel == nullptr) {
            return;
        }

        String ^ recurringPaymentId = safe_cast<String ^>(clickedLabel->Tag);

        System::Windows::Forms::DialogResult result;
        result = MessageBox::Show(L"Bạn có chắc muốn hủy thanh toán ĐK này ?", L"Xóa",
                                  MessageBoxButtons::YesNo, MessageBoxIcon::Question);

        if (result == System::Windows::Forms::DialogResult::No) {
            return;
        }

        RecurringPaymentServices::DeleteRecurringPaymentById(recurringPaymentId);

        this->LoadRecurringPaymentFollow();  
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Hủy thanh toán định kì thất bại, thử lại sau.", L"Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
} // namespace BankingAppwinform
