#include "CodeDetailForm.h"
#include"GradientHelper.h"

namespace BankingAppwinform {

CodeDetailForm::CodeDetailForm(CustomerCodes ^ customerCode) {
    InitializeComponent();
    this->customerCode = customerCode;
    loadCodeDetails();
    GradientColorHelper::ApplyGradient(this->leftContent);
}

CodeDetailForm::~CodeDetailForm() {
    if (components) {
        delete components;
    }
}


void CodeDetailForm::loadCodeDetails() {
    try {
        this->leftContent->Controls->Clear();
        if (this->customerCode == nullptr) {
            return;
        }

        array<CustomerCodeDetails ^> ^ codeDetails = CustomerCodeDetailServices::GetAllCodeDetails();
        if (codeDetails == nullptr || codeDetails->Length == 0) {
            return;
        }

        for (int i = 0; i < codeDetails->Length; i++) {
            if (codeDetails[i]->CustomerCodeId != this->customerCode->Id) {
                continue;
            }

            Panel ^ panel = createCodeDetailPanel(codeDetails[i]);
            this->leftContent->Controls->Add(panel);
        }

        this->leftContent->PerformLayout();
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Lấy dữ liệu cho mã khách hàng bị lỗi. thử lại sau.", L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

Panel ^ CodeDetailForm::createCodeDetailPanel(CustomerCodeDetails ^ detail) {
    Panel ^ panel = gcnew Panel();
    panel->BackColor = Color::FromArgb(0, 64, 64);
    panel->Padding = System::Windows::Forms::Padding(10);
    panel->Margin = System::Windows::Forms::Padding(5);
    panel->Width = leftContent->ClientSize.Width - 15;

    int yOffset = 10;
    int lineHeight = 20;

    addLabelToPanel(panel, yOffset, L"Mã hóa đơn: " + detail->Id);
    addLabelToPanel(panel, yOffset,
                    L"Mã khách hàng: " + this->customerCode->Code);
    addLabelToPanel(panel, yOffset,
                    L"Số tiền: " + detail->Amount.ToString("N0") + " vnd");
    addLabelToPanel(panel, yOffset,
                    L"Ngày tạo: " +
                        detail->CreateDate.ToString("dd/MM/yyyy hh:mm:ss tt"));
    addLabelToPanel(panel, yOffset,
                    L"Ngày hết hạn: " +
                        detail->ExpiredDate.ToString("dd/MM/yyyy hh:mm:ss tt"));
    addLabelToPanel(panel, yOffset,
                    L"Trạng thái: " + (detail->Status == 1
                                           ? L"đã thanh toán"
                                           : L"chưa thanh toán"));
    addLabelToPanel(panel, yOffset,
                    L"Tài khoản thanh toán: " +
                        detail->PaymentUserAccountNumber);
    addLabelToPanel(panel, yOffset, L"Ngày thanh toán: " + detail->PaymentDate);

    // Nút "Xóa hóa đơn"
    if (detail->Status == 0) {
        Button ^ btnDelete = gcnew Button();
        btnDelete->Text = L"Xóa hóa đơn";
        btnDelete->BackColor = Color::DarkRed;
        btnDelete->ForeColor = Color::White;
        btnDelete->Font =
            gcnew System::Drawing::Font("Arial", 9, FontStyle::Bold);
        btnDelete->Location = Point(10, yOffset);
        btnDelete->AutoSize = true;
        btnDelete->Tag = detail->Id; // Gán dữ liệu Id vào Tag
        btnDelete->Click +=
            gcnew EventHandler(this, &CodeDetailForm::deleteCodeDetail_Click);
        panel->Controls->Add(btnDelete);
        yOffset += 30;
    }

    panel->Height = yOffset + 10;
    return panel;
}


void CodeDetailForm::addLabelToPanel(Panel ^ panel, int % yOffset,
                                     String ^ text) {
    Label ^ label = gcnew Label();
    label->Text = text;
    label->Font = gcnew System::Drawing::Font("Arial", 10);
    label->ForeColor = Color::White;
    label->Location = Point(10, yOffset);
    label->AutoSize = true;
    panel->Controls->Add(label);
    yOffset += 20; // chiều cao mỗi dòng
}


void CodeDetailForm::deleteCodeDetail_Click(Object ^ sender, EventArgs ^ e) {
    try {
        Button ^ btn = dynamic_cast<Button ^>(sender);
        if (btn == nullptr)
            return;

        String ^ idToDelete = dynamic_cast<String ^>(btn->Tag);
        if (String::IsNullOrEmpty(idToDelete))
            return;

        CustomerCodeDetailServices::DeleteCodeDetail(idToDelete);

        // Refresh giao diện
        this->loadCodeDetails();
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}



System::Void CodeDetailForm::btnSubmit_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    try {
        
        if (this->amount->Text == "" || this->days->Text == "") {
            MessageBox::Show(L"Vui lòng nhập số tiền và thời gian",
                             L"Cảnh báo", MessageBoxButtons::OK,
                             MessageBoxIcon::Warning);
            return;
        }
        
        CustomerCodeDetails ^ codeDetail = CustomerCodeDetailServices::InsertCodeDetail(
            this->amount->Text, this->days->Text, this->customerCode->Id);

        MessageBox::Show(L"Hóa đơn đã được tạo thành công.");

        RecurringPayments ^ recurringPayment = RecurringPaymentServices::GetRecurringPaymentByCustomerCodeId(this->customerCode->Id);

        //this->payRecurringPayment(codeDetail, recurringPayment);
        if (recurringPayment != nullptr) {
            RecurringPaymentServices::PayRecurringPayment(recurringPayment, codeDetail);
            MessageBox::Show(L"Hóa đơn đã được thanh toán định kì thành công.");
        }

        this->loadCodeDetails();
        this->amount->Text = "";

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
    }
}

} // namespace BankingAppwinform
