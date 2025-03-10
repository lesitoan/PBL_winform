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
    array<Services ^> ^ services = GetFakeServices();

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

array<Services ^> ^ AdminServiceForm::GetFakeServices() {
    return gcnew array<Services ^>{gcnew Services(1, L"TT điện"),
                                   gcnew Services(2, L"TT nước"),
                                   gcnew Services(3, L"TT internet"),
                                   gcnew Services(4, L"TT  điện thoại"),
                                   gcnew Services(5, L"TT truyền hình"),
                                   gcnew Services(6, L"TT  học phí"),
                                   gcnew Services(7, L"TT bảo hiểm"),
                                   gcnew Services(8, L"TT vay tiêu dùng"),
                                   gcnew Services(9, L"TT phí giao thông"),
                                   gcnew Services(10, L"TT phí chung cư")};
}

System::Void AdminServiceForm::panel1_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {}
}; // namespace BankingAppwinform
