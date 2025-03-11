#include "AdminServiceForm.h"
#pragma once
#include "AdminForm.h"
#include "CompanyForm.h"
#include "Services.h"

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

    array<Services ^> ^ services = HandleFile::ReadServicesArray("services.dat");
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

    this->Controls->Add(flowLayoutPanelContainer);

    
}

void AdminServiceForm::OnServiceClick(Object ^ sender, EventArgs ^ e) {
    Label ^ clickedLabel = (Label ^) sender;
    int serviceId = (int)clickedLabel->Tag;

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
}; // namespace BankingAppwinform
