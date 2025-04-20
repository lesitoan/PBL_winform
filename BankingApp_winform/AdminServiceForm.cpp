#include "AdminServiceForm.h"

namespace BankingAppwinform {

AdminServiceForm::AdminServiceForm(void) {
    InitializeComponent();

    LoadServices();
}

AdminServiceForm::~AdminServiceForm() {
    if (components) {
        delete components;
    }
}

void AdminServiceForm::LoadServices() {
    try {
        flowLayoutPanelContainer->Controls->Clear();

        array<Services ^> ^ services = ServicesRepository::GetAll();

        if (services == nullptr || services->Length == 0) {
            return;
        }

        for (int i = 0; i < services->Length; i++) {
            Panel ^ panel = gcnew Panel();
            panel->Size = System::Drawing::Size(120, 120);
            panel->BackColor = Color::Aqua;
            panel->Margin = System::Windows::Forms::Padding(10);

            Label ^ label = gcnew Label();
            label->Font =
                gcnew System::Drawing::Font("UTM Daxline", 12, FontStyle::Bold);
            label->Cursor = Cursors::Hand;

            label->Text = services[i]->Name;
            label->Dock = DockStyle::Fill;
            label->TextAlign = ContentAlignment::MiddleCenter;

            panel->Controls->Add(label);
            flowLayoutPanelContainer->Controls->Add(panel);

            // Gán sự kiện click cho panel
            label->Tag = services[i]->Id; // Lưu ID dịch vụ vào Tag
            label->Click +=
                gcnew EventHandler(this, &AdminServiceForm::OnServiceClick);
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Tải thông tinn dịch vụ thất bại. Thử lại sau", L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void AdminServiceForm::OnServiceClick(Object ^ sender, EventArgs ^ e) {
    Label ^ clickedLabel = (Label ^) sender;
    String^ serviceId = (String^)clickedLabel->Tag;

    // Tạo form mới và truyền serviceId
    CompanyForm ^ companyForm = gcnew CompanyForm(serviceId);

    // Gọi hàm LoadForm trong MainForm
    AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
    if (adminForm != nullptr) {
        adminForm->LoadForm(companyForm);
    }
}

System::Void AdminServiceForm::panel1_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {}

System::Void AdminServiceForm::btnAddService_Click(System::Object ^ sender,
                                                   System::EventArgs ^ e) {
    ModifyServiceForm ^ addServiceForm = gcnew ModifyServiceForm("insert");
    addServiceForm->ModifyServiceSuccess +=
        gcnew EventHandler(this, &AdminServiceForm::onModyfyService);
    addServiceForm->ShowDialog();
}

System::Void AdminServiceForm::onModyfyService(System::Object ^ sender,
                                               System::EventArgs ^ e) {
    LoadServices();
}

System::Void AdminServiceForm::btnDeleteService_Click(System::Object ^ sender,
                                                      System::EventArgs ^ e) {
    ModifyServiceForm ^ deleteServiceForm = gcnew ModifyServiceForm("delete");
    deleteServiceForm->ModifyServiceSuccess +=
        gcnew EventHandler(this, &AdminServiceForm::onModyfyService);
    deleteServiceForm->ShowDialog();
}

}; // namespace BankingAppwinform
