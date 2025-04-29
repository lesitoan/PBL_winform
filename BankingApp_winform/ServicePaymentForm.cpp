#include "ServicePaymentForm.h"


namespace BankingAppwinform {

ServicePaymentForm::ServicePaymentForm(void) {
    InitializeComponent();
    LoadServices();
    GradientColorHelper::ApplyGradient(this->flowLayoutPanelServices);
    GradientColorHelper::AttachHoverEffect(this->panel5, Color::FromArgb(255, 128, 128));
}

ServicePaymentForm::~ServicePaymentForm() {
    if (components) {
        delete components;
    }
}

void ServicePaymentForm::LoadServices() {
    try {
        array<Services ^> ^ services = ServiceServices::GetAllServices();

        if (services == nullptr || services->Length == 0) {
            return;
        }

        for (int i = 0; i < services->Length; i++) {
            Panel ^ panel = gcnew Panel();
            panel->Size = System::Drawing::Size(120, 120);
            panel->BackColor = Color::White;
            panel->Margin = System::Windows::Forms::Padding(10);
            Label ^ label = gcnew Label();
            label->Font =
                gcnew System::Drawing::Font("UTM Daxline", 12, FontStyle::Regular);
            label->Cursor = Cursors::Hand;

            GradientColorHelper::AttachHoverEffect(label, Color::FromArgb(255, 128, 128));
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
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Lấy danh sách dịch vụ thất bại", "Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void ServicePaymentForm::OnServiceClick(Object ^ sender, EventArgs ^ e) {
    Label ^ clickedLabel = (Label ^) sender;
    String ^ serviceId = (String ^) clickedLabel->Tag;
    loadFormTransfer(serviceId);
}

void ServicePaymentForm::loadFormTransfer(String ^ serviceId) {
    try {
        array<User ^> ^ companies = UserService::GetCompanyByServiceId(serviceId);

        if (companies == nullptr || companies->Length == 0) {
            this->labelHeader->Visible = true;
            this->panelContent->Visible = false;

            this->labelHeader->Text = L"Không có công ty nào";
            return;
        }

        this->labelHeader->Visible = false;
        this->panelContent->Visible = true;
        selectCompanyBox->DataSource = companies;
        selectCompanyBox->DisplayMember = "FullName";
        selectCompanyBox->ValueMember = "AccountNumber";    
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Lỗi: Không thể tải form thanh toán dịch vụ",
                         "Lỗi", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
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

    try {
        //
        String ^ code = this->code->Text;
        String ^ pinInput = this->pin->Text;
        String ^ companyAccountNumber = this->currComapnyAccNumber;
        String ^ currUserAccNumber = GlobalData::GetCurrentUser()->AccountNumber;
        String ^ currUserId = GlobalData::GetCurrentUser()->Id;

        if (code == "" || companyAccountNumber == "" || currUserAccNumber == "") {
            MessageBox::Show("Vui lòng nhập đầy đủ thông tin");
            return;
        }

        ServiceServices::PayCustomerCode(code, companyAccountNumber,
                                      currUserAccNumber, pinInput);

        MessageBox::Show("Thanh toán thành công", "Thông báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);

        if (this->submitRecurringPayment->Checked) {
            RecurringPaymentServices::RegisterRecurringPayment(code,
                                                               currUserId);
            MessageBox::Show(L"Đăng kí thanh toán định kì thành công", L"Thông báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông tin", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
    }
}


System::Void ServicePaymentForm::label3_Click(System::Object ^ sender,
                                              System::EventArgs ^ e) {
    Form ^ form = gcnew RecurringPaymentFollowForm();
    form->ShowDialog();
}

}; // namespace BankingAppwinform
