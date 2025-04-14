#include "ServicePaymentForm.h"
#include "GradientHelper.h"

namespace BankingAppwinform {

ServicePaymentForm::ServicePaymentForm(void) {
    InitializeComponent();
    LoadServices();
    GradientColorHelper::ApplyGradient(this->flowLayoutPanelServices);
}

ServicePaymentForm::~ServicePaymentForm() {
    if (components) {
        delete components;
    }
}

void ServicePaymentForm::LoadServices() {
    array<Services ^> ^ services =
        HandleFile::ReadServicesArray("services.dat");
    if (services == nullptr || services->Length == 0) {
        return;
    }
    for (int i = 0; i < services->Length; i++) {
        Panel ^ panel = gcnew Panel();
        panel->Size = System::Drawing::Size(120, 120);
        /*panel->BackColor = Color::White;*/
        panel->Margin = System::Windows::Forms::Padding(10);
        

        Label ^ label = gcnew Label();
        label->Font =
            gcnew System::Drawing::Font("UTM Daxline", 12, FontStyle::Regular);
        label->Cursor = Cursors::Hand;

        label->Text = services[i]->Name;
        label->Dock = DockStyle::Fill;
        label->TextAlign = ContentAlignment::MiddleCenter;
        label->BackColor = Color::White;
        panel->Controls->Add(label);
        this->flowLayoutPanelServices->Controls->Add(panel);

        // Gán sự kiện click cho panel
        label->Tag = services[i]->Id; // Lưu ID dịch vụ vào Tag
        label->Click +=
            gcnew EventHandler(this, &ServicePaymentForm::OnServiceClick);
        GradientColorHelper::ApplyRoundedCorners(label,10);
        GradientColorHelper::ApplyRoundedCorners(panel,10);
        GradientColorHelper::ApplyGradient(panel1);
    }
}

void ServicePaymentForm::OnServiceClick(Object ^ sender, EventArgs ^ e) {
    Label ^ clickedLabel = (Label ^) sender;
    String^ serviceId = (String^)clickedLabel->Tag;
    loadFormTransfer(serviceId);
}

void ServicePaymentForm::loadFormTransfer(String^ serviceId) {

    array<User ^> ^ data = HandleFile::ReadUserArray("users.dat");

    if (data == nullptr || data->Length == 0) {
        this->labelHeader->Text = L"Không có công ty nào";
        return;
    }

    List<User ^> ^ companies = gcnew List<User ^>();
    for each (User ^ user in data) {

        if (user->getRole() == "company" && user->getServiceId() == serviceId) {
            companies->Add(user);
        }
    }

    if (companies->Capacity == 0) {
        this->labelHeader->Visible = true;
        this->panelContent->Visible = false;

        this->labelHeader->Text = L"Không có công ty nào";
        return;
    } else {
        this->labelHeader->Visible = false;
        this->panelContent->Visible = true;
    }

    selectCompanyBox->DataSource = companies;
    selectCompanyBox->DisplayMember = "FullName";
    selectCompanyBox->ValueMember = "AccountNumber";
};

System::Void ServicePaymentForm::selectCompanyBox_SelectedIndexChanged(
    System::Object ^ sender, System::EventArgs ^ e) {
    ComboBox ^ comboBox = dynamic_cast<ComboBox ^>(sender);
    if (comboBox != nullptr && comboBox->SelectedItem != nullptr) {
        User ^ selectedUser = dynamic_cast<User ^>(comboBox->SelectedItem);
        if (selectedUser != nullptr) {
            this->currComapnyAccNumber = selectedUser->AccountNumber;
        } else {
            MessageBox::Show("Lỗi: Không thể lấy dữ liệu công ty.");
        }
    }
}

System::Void ServicePaymentForm::btnTransfer_Click(System::Object ^ sender,
                                                   System::EventArgs ^ e) {

    //
    String ^ code = this->code->Text;
    String ^ pinInput = this->pin->Text;
    if (code == "" || pinInput == "") {
        MessageBox::Show(L"Vui lòng nhập mã thanh toán và mã pin", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (!Validate::isPin(pinInput)) {
        MessageBox::Show("Ma pin khong hop le !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    String^ companyAccountNumber = this->currComapnyAccNumber;
    String^ currUserAccNumber = GlobalData::GetCurrentUser()->AccountNumber;
    int pin = Convert::ToInt32(pinInput);

    // check code có tồn tại
    array<PaymentCodes ^> ^ codes = HandleFile::ReadCodeArray("codes.dat");
    if (codes == nullptr || codes->Length == 0) {
        MessageBox::Show(L"Lỗi: Không có mã thanh toán nào.");
        return;
    }
    PaymentCodes ^ paymentCode = nullptr;
    for (int i = 0; i < codes->Length; i++) {
        if (codes[i]->Code == code &&
            codes[i]->CompanyAccountNumber == companyAccountNumber) {
            paymentCode = codes[i];
        }
    }
    if (paymentCode == nullptr) {
        MessageBox::Show(L"Mã thanh toán không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (paymentCode->Status == 1) {
        MessageBox::Show(L"Mã thanh toán không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // chuyển tiền
    bool isTransferSuccess = Utils::transferMoney(
        currUserAccNumber, companyAccountNumber, paymentCode->Amount, pin);

    if (!isTransferSuccess) {
        MessageBox::Show(L"Chuyển tiền thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // sửa file code
    paymentCode->Status = 1;
    bool isSavedCode = HandleFile::WriteCodeArray(codes, "codes.dat");
    if (!isSavedCode) {
        MessageBox::Show(L"Lỗi máy chủ, thử lại sau !", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else {
        for (int i = 0; i < codes->Length; i++) {
            if (codes[i]->Code == code &&
                codes[i]->CompanyAccountNumber == companyAccountNumber) {
                codes[i]->Status = 1;
            }
        }
        bool isSavedCode = HandleFile::WriteCodeArray(codes, "codes.dat");
        if (!isSavedCode) {
            MessageBox::Show(L"Lỗi máy chủ, thử lại sau !", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else {
            MessageBox::Show(L"Thanh toán thành công !", "Thông báo",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information);
        }
    }

    // thanh toán định kì
    this->onSubmitCurrentPayment(currUserAccNumber, companyAccountNumber, 1);
}

void ServicePaymentForm::onSubmitCurrentPayment(String^ userAccountNumber,
                                                String^ companyAccountNumber,
                                                int monthly) {
    bool checked = this->submitRecurringPayment->Checked;
    if (!checked)
        return;

    // Tạo recurringPayment
    String ^ id = Utils::createUniqueID("RP");
    RecurringPayments ^ recurringPayment = gcnew RecurringPayments(
        id,
        userAccountNumber, companyAccountNumber, monthly);

    // Lấy thông tin thanh toán
    array<RecurringPayments ^> ^ recurringPayments =
        HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
    if (recurringPayments == nullptr) {
        recurringPayments = gcnew array<RecurringPayments ^>(1);
        recurringPayments[0] = recurringPayment;
        return;
    }

    // Kiểm tra xem đã có thanh toán định kì chưa
    for (int i = 0; i < recurringPayments->Length; i++) {
        if (recurringPayments[i]->UserAccountNumber == userAccountNumber &&
            recurringPayments[i]->CompanyAccountNumber ==
                companyAccountNumber) {
            return;
        }
    }

    // Nếu chưa thì thêm vào file
    Array::Resize(recurringPayments, recurringPayments->Length + 1);
    recurringPayments[recurringPayments->Length - 1] = recurringPayment;
    bool isSave = HandleFile::WriteRecurringPaymentsArray(
        recurringPayments, "recurringPayments.dat");
    if (!isSave) {
        MessageBox::Show("Lỗi máy chủ, thử lại sau !");
        return;
    }
};
}; // namespace BankingAppwinform
