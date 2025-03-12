#include <vector>
#include "CompanyForm.h"

#pragma once
#include "AdminForm.h"
#include "User.h"

namespace BankingAppwinform {

    CompanyForm::CompanyForm(int serviceId) {
        InitializeComponent();

        LoadCompanies(serviceId);
    }
    CompanyForm::~CompanyForm() {
        if (components) {
            delete components;
        }
    }

    void CompanyForm::LoadCompanies(int serviceId) {
        array<User ^> ^ companies = HandleFile::ReadUserArray("users.dat");

        if (companies == nullptr || companies->Length == 0) {
            return;
        }

        // Xóa các panel cũ trước khi load danh sách mới
        flowLayoutPanelContainer->Controls->Clear();

        for (int i = 0; i < companies->Length; i++) {
            if (companies[i]->getRole() != "company" ||
                companies[i]->getServiceId() != serviceId) {
                continue;
            }
            Panel ^ panel = gcnew Panel();
            panel->Size =
                System::Drawing::Size(139, 147); // Kích thước hình chữ nhật
            panel->BackColor = Color::LightBlue; // Màu nền xanh nhạt
            panel->Margin = System::Windows::Forms::Padding(10);

            Label ^ label = gcnew Label();
            label->Font =
                gcnew System::Drawing::Font("UTM Daxline", 12, FontStyle::Bold);
            label->Cursor = Cursors::Hand;

            label->Text = companies[i]->getFullName();
            label->Dock = DockStyle::Fill;
            label->TextAlign = ContentAlignment::MiddleCenter;
            label->Dock = DockStyle::Fill;
            label->AutoSize = false; 

            panel->Controls->Add(label);
            flowLayoutPanelContainer->Controls->Add(panel);
            // Gán sự kiện click cho panel
            label->Tag = companies[i]->getAccountNumber(); // Lưu ID dịch vụ vào Tag
            label->Click +=
                gcnew EventHandler(this, &CompanyForm::OnCompanyClick);
        }
    }

    void CompanyForm::OnCompanyClick(Object ^ sender, EventArgs ^ e) {
        Label ^ clickedLabel = (Label ^) sender;
        int companyId = (int)clickedLabel->Tag;

        
        CompanyBillingForm ^ companyBillingForm =
            gcnew CompanyBillingForm(companyId);

        // Gọi hàm LoadForm trong MainForm
        AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
        if (adminForm != nullptr) {
            adminForm->LoadForm(companyBillingForm);
        }
    }

    void CompanyForm::OnUndoClick(Object ^ sender, EventArgs ^ e) {
        AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
        if (adminForm != nullptr) {
            adminForm->UndoLastForm();
        }
    }


      System::Void
        CompanyForm::btnAccount_Click(System::Object ^ sender, System::EventArgs ^ e) {
        OnUndoClick(sender, e);
    }
};
