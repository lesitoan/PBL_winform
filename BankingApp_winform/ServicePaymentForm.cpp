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
        panel->BackColor = Color::White;
        panel->Margin = System::Windows::Forms::Padding(10);
//<<<<<<< HEAD
//=======

//>>>>>>> f522501fd0973f0b25f1a55b5e6b8c2e0f5933aa
        Label ^ label = gcnew Label();
        label->Font =
            gcnew System::Drawing::Font("UTM Daxline", 12, FontStyle::Regular);
        label->Cursor = Cursors::Hand;
        
        GradientColorHelper::AttachHoverEffect(label, Color::FromArgb(255,128,128));
        label->Text = services[i]->Name;
        label->Dock = DockStyle::Fill;
        label->TextAlign = ContentAlignment::MiddleCenter;
        label->BackColor = Color::White;
        panel->Controls->Add(label);
        this->flowLayoutPanelServices->Controls->Add(panel);
        GradientColorHelper::AttachPanelClickHandlers(
            this->flowLayoutPanelServices);
        // Gán sự kiện click cho panel
        label->Tag = services[i]->Id; // Lưu ID dịch vụ vào Tag
        label->Click +=
            gcnew EventHandler(this, &ServicePaymentForm::OnServiceClick);
        GradientColorHelper::ApplyRoundedCorners(label, 10);
        GradientColorHelper::ApplyRoundedCorners(panel, 10);
        GradientColorHelper::ApplyGradient(panel1);
        // khi hover vào label thì đổi màu dùng hàm OnMouseEnter của thư viện GradientHelper
    }
        
}

void ServicePaymentForm::OnServiceClick(Object ^ sender, EventArgs ^ e) {
    Label ^ clickedLabel = (Label ^) sender;
    String ^ serviceId = (String ^) clickedLabel->Tag;
    loadFormTransfer(serviceId);
}

void ServicePaymentForm::loadFormTransfer(String ^ serviceId) {

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

        // check xem khách hàng đã đăng kí định kì ở đây chưa
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
    String ^ companyAccountNumber = this->currComapnyAccNumber;
    String ^ currUserAccNumber = GlobalData::GetCurrentUser()->AccountNumber;
    int pin = Convert::ToInt32(pinInput);

    // check code có tồn tại
    array<CustomerCodes ^> ^ codes =
        HandleFile::ReadCustomerCodesArray("customerCodes.dat");
    if (codes == nullptr || codes->Length == 0) {
        MessageBox::Show(L"Lỗi: Không tồn tại mã khách hàng");
        return;
    }
    CustomerCodes ^ customerCode = nullptr;
    for (int i = 0; i < codes->Length; i++) {
        if (codes[i]->Code == code &&
            codes[i]->CompanyAccountNumber == companyAccountNumber) {
            customerCode = codes[i];
            break;
        }
    }
    if (customerCode == nullptr) {
        MessageBox::Show(L"Mã khách hàng không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (customerCode->Status == 0) {
        MessageBox::Show(L"Mã tkhách hàng đã hết hạn", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    /*lấy hóa đơn tương ứng với mã khách hàng*/
    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");
    if (codeDetails == nullptr || codeDetails->Length == 0) {
        MessageBox::Show(L"Khách hàng chưa có hóa đơn cần thanh toán");
        return;
    }
    CustomerCodeDetails ^ currentCodeDetail = nullptr;
    for (int i = 0; i < codeDetails->Length; i++) {
        if (codeDetails[i]->CustomerCodeId == customerCode->Id &&
            codeDetails[i]->Status == 0 &&
            codeDetails[i]->ExpiredDate > DateTime::Now) {
            currentCodeDetail = codeDetails[i];
            MessageBox::Show(codeDetails[i]->Amount + " - ");
            break;
        }
    }
    if (currentCodeDetail == nullptr) {
        MessageBox::Show(L"Khách hàng chưa có hóa đơn cần thanh toán");
        return;
    }

    // chuyển tiền
    bool isTransferSuccess =
        Utils::transferMoney(currUserAccNumber, companyAccountNumber,
                             currentCodeDetail->Amount, pin);

    if (!isTransferSuccess) {
        MessageBox::Show(L"Chuyển tiền thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    // sửa file code
    currentCodeDetail->Status = 1;
    currentCodeDetail->PaymentDate = DateTime::Now.ToString("dd/MM/yyyy");
    currentCodeDetail->PaymentUserAccountNumber = currUserAccNumber;
    for (int i = 0; i < codeDetails->Length; i++) {
        if (codeDetails[i]->Id == currentCodeDetail->Id) {
            codeDetails[i] = currentCodeDetail;
            break;
        }
    }
    bool isSave = HandleFile::WriteCustomerCodeDetailsArray(
        codeDetails, "customerCodeDetails.dat");
    if (!isSave) {
        MessageBox::Show("Lỗi máy chủ, thử lại sau !");
        return;
    } else {
        MessageBox::Show("Thanh toán thành công !");
        onSubmitCurrentPayment(customerCode->Id,
                               currUserAccNumber); // đăng kí định kì
    }
}

void ServicePaymentForm::onSubmitCurrentPayment(String ^ userAccountNumber,
                                                String ^ companyAccountNumber,
                                                int monthly) {
    throw gcnew System::NotImplementedException();
}

void ServicePaymentForm::onSubmitCurrentPayment(String ^ customerCodeId,
                                                String ^ userAccountNumber) {
    bool checked = this->submitRecurringPayment->Checked;
    if (!checked)
        return;

    // kiểm tra có user nào đã đk với mã kh đó chưa
    array<RecurringPayments ^> ^ recurringPayments =
        HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
    if (recurringPayments == nullptr || recurringPayments->Length == 0) {
        recurringPayments = gcnew array<RecurringPayments ^>(0);
    } else {
        for (int i = 0; i < recurringPayments->Length; i++) {
            if (recurringPayments[i]->CustomerCodeId == customerCodeId &&
                recurringPayments[i]->UserAccountNumber == userAccountNumber) {
                MessageBox::Show(
                    "Mã khách hàng đã được đăng kí thanh toán định kì");
                return;
            }
        }
    }
    // tạo mã định kì
    String ^ recurringPaymentId = Utils::createUniqueID("RP");
    RecurringPayments ^ recurringPayment = gcnew RecurringPayments(
        recurringPaymentId, userAccountNumber, customerCodeId,
        Convert::ToInt32(DateTime::Now.Day));
    // thêm vào file
    List<RecurringPayments ^> ^ newList =
        gcnew List<RecurringPayments ^>(recurringPayments);
    newList->Add(recurringPayment);
    bool isSave = HandleFile::WriteRecurringPaymentsArray(
        newList->ToArray(), "recurringPayments.dat");
    if (!isSave) {
        MessageBox::Show("Lỗi máy chủ, thử lại sau !");
        return;
    }
};

System::Void ServicePaymentForm::submitRecurringPayment_CheckedChanged(
    System::Object ^ sender, System::EventArgs ^ e) {
    this->isChangedRecurringPayment = true;
}

System::Void ServicePaymentForm::label3_Click(System::Object ^ sender,
                                              System::EventArgs ^ e) {
    Form ^ form = gcnew RecurringPaymentFollowForm();
    form->ShowDialog();
}

}; // namespace BankingAppwinform
