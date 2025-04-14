#include "CodeDetailForm.h"

namespace BankingAppwinform {

CodeDetailForm::CodeDetailForm(CustomerCodes ^ customerCode) {
    InitializeComponent();
    this->customerCode = customerCode;
    loadCodeDetails();
}

CodeDetailForm::~CodeDetailForm() {
    if (components) {
        delete components;
    }
}

void CodeDetailForm::loadCodeDetails() {

    this->leftContent->Controls->Clear();

    if (this->customerCode == nullptr) {
        return;
    }

    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");
    if (codeDetails == nullptr || codeDetails->Length == 0) {
        return;
    }

    for (int i = 0; i < codeDetails->Length; i++) {
        if (codeDetails[i]->CustomerCodeId != this->customerCode->Id) {
            continue;
        }

        Panel ^ panel = gcnew Panel();
        panel->BackColor = Color::Teal;
        panel->Padding = System::Windows::Forms::Padding(10);
        panel->Margin = System::Windows::Forms::Padding(5);
        panel->Width = leftContent->ClientSize.Width - 15;

        int yOffset = 10;
        int lineHeight = 20;

        // Mã hóa đơn
        Label ^ lblId = gcnew Label();
        lblId->Text = L"Mã hóa đơn: " + codeDetails[i]->Id;
        lblId->Font = gcnew System::Drawing::Font("Arial", 10);
        lblId->Location = Point(10, yOffset);
        lblId->AutoSize = true;
        panel->Controls->Add(lblId);
        yOffset += lineHeight;

        // Mã khách hàng
        Label ^ lblCustomerCode = gcnew Label();
        lblCustomerCode->Text =
            L"Mã khách hàng: " + codeDetails[i]->CustomerCodeId;
        lblCustomerCode->Font = gcnew System::Drawing::Font("Arial", 10);
        lblCustomerCode->Location = Point(10, yOffset);
        lblCustomerCode->AutoSize = true;
        panel->Controls->Add(lblCustomerCode);
        yOffset += lineHeight;

        // Số tiền
        Label ^ lblAmount = gcnew Label();
        lblAmount->Text =
            L"Số tiền: " + codeDetails[i]->Amount.ToString("N0") + " vnd";
        lblAmount->Font = gcnew System::Drawing::Font("Arial", 10);
        lblAmount->Location = Point(10, yOffset);
        lblAmount->AutoSize = true;
        panel->Controls->Add(lblAmount);
        yOffset += lineHeight;

        // Ngày tạo
        Label ^ lblCreateDate = gcnew Label();
        lblCreateDate->Text =
            L"Ngày tạo: " +
            codeDetails[i]->CreateDate.ToString("dd/MM/yyyy hh:mm:ss tt");
        lblCreateDate->Font = gcnew System::Drawing::Font("Arial", 10);
        lblCreateDate->Location = Point(10, yOffset);
        lblCreateDate->AutoSize = true;
        panel->Controls->Add(lblCreateDate);
        yOffset += lineHeight;

        // Ngày hết hạn
        Label ^ lblExpired = gcnew Label();
        lblExpired->Text =
            L"Ngày hết hạn: " +
            codeDetails[i]->ExpiredDate.ToString("dd/MM/yyyy hh:mm:ss tt");
        lblExpired->Font = gcnew System::Drawing::Font("Arial", 10);
        lblExpired->Location = Point(10, yOffset);
        lblExpired->AutoSize = true;
        panel->Controls->Add(lblExpired);
        yOffset += lineHeight;

        // Trạng thái
        Label ^ lblStatus = gcnew Label();
        lblStatus->Text =
            L"Trạng thái: " +
            (codeDetails[i]->Status == 1 ? L"đã thanh toán" : L"chưa thanh toán");
        lblStatus->Font = gcnew System::Drawing::Font("Arial", 10);
        lblStatus->Location = Point(10, yOffset);
        lblStatus->AutoSize = true;
        panel->Controls->Add(lblStatus);
        yOffset += lineHeight;

        // Tài khoản thanh toán
        Label ^ lblAccount = gcnew Label();
        lblAccount->Text =
            L"Tài khoản thanh toán: " + codeDetails[i]->PaymentUserAccountNumber;
        lblAccount->Font = gcnew System::Drawing::Font("Arial", 10);
        lblAccount->Location = Point(10, yOffset);
        lblAccount->AutoSize = true;
        panel->Controls->Add(lblAccount);
        yOffset += lineHeight;

        // Ngày thanh toán
        Label ^ lblPaymentDate = gcnew Label();
        lblPaymentDate->Text =
            L"Ngày thanh toán: " + codeDetails[i]->PaymentDate;
        lblPaymentDate->Font = gcnew System::Drawing::Font("Arial", 10);
        lblPaymentDate->Location = Point(10, yOffset);
        lblPaymentDate->AutoSize = true;
        panel->Controls->Add(lblPaymentDate);
        yOffset += lineHeight;

        // Cập nhật chiều cao panel
        panel->Height = yOffset + 10;
        panel->Margin = System::Windows::Forms::Padding(5);


        // Thêm vào giao diện
        leftContent->Controls->Add(panel);
        leftContent->PerformLayout();
    }
}

System::Void CodeDetailForm::btnSubmit_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    if (this->amount->Text == "" || this->days->Text == "") {
        MessageBox::Show(L"Vui lòng nhập số tiền và thời gian", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    if (!Validate::isNumber(this->amount->Text) ||
        !Validate::isNumber(this->days->Text)) {
        MessageBox::Show(L"Số tiền hoặc thời gian không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    double amount = Convert::ToDouble(this->amount->Text);
    int days = Convert::ToInt32(this->days->Text);
    if (amount <= 0 || days <= 0) {
        MessageBox::Show(L"Số tiền hoặc thời gian không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    if (this->customerCode == nullptr) {
        return;
    }

    // tạo hóa đơn mới
    String ^ codeDetailId = Utils::createUniqueID("CCD");
    DateTime expiredDate = DateTime::Now.AddDays(days);
    CustomerCodeDetails ^ codeDetail = gcnew CustomerCodeDetails(
        codeDetailId, this->customerCode->Id, amount, expiredDate);

    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");
    if (codeDetails == nullptr) {
        codeDetails = gcnew array<CustomerCodeDetails ^>(1);
        codeDetails[0] = codeDetail;
    } else {
        array<CustomerCodeDetails ^> ^ newCodeDetails =
            gcnew array<CustomerCodeDetails ^>(codeDetails->Length + 1);
        for (int i = 0; i < codeDetails->Length; i++) {
            newCodeDetails[i] = codeDetails[i];
        }
        newCodeDetails[codeDetails->Length] = codeDetail;
        codeDetails = newCodeDetails;
    }
    bool isSaveCodeDetail = HandleFile::WriteCustomerCodeDetailsArray(
        codeDetails, "customerCodeDetails.dat");
    if (isSaveCodeDetail) {
        MessageBox::Show(L"Thêm hóa đơn thành công");
        this->loadCodeDetails();
    } else {
        MessageBox::Show(L"Thêm hóa đơn thất bại");
    }
}

} // namespace BankingAppwinform
