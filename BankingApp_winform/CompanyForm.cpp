#include "CompanyForm.h"

#pragma once
#include "AdminForm.h"
#include "Companies.h"

namespace BankingAppwinform {

    CompanyForm::CompanyForm(int serviceId) {
        InitializeComponent();

        LoadCompanies(1);
    }
    CompanyForm::~CompanyForm() {
        if (components) {
            delete components;
        }
    }

    void CompanyForm::LoadCompanies(int serviceId) {
        array<Companies ^> ^ companies = GetFakeCompanies();

        // Xóa các panel cũ trước khi load danh sách mới
        flowLayoutPanelContainer->Controls->Clear();

        for (int i = 0; i < companies->Length; i++) {
            if (companies[i]->ServiceId != serviceId)
                continue; // Chỉ lấy công ty thuộc dịch vụ đang chọn

            Panel ^ panel = gcnew Panel();
            panel->Size = System::Drawing::Size(180, 80);
            panel->BackColor = Color::LightBlue;
            panel->Margin = System::Windows::Forms::Padding(10);

            Label ^ label = gcnew Label();
            label->Font =
                gcnew System::Drawing::Font("UTM Daxline", 12, FontStyle::Bold);
            label->Cursor = Cursors::Hand;

            label->Text = companies[i]->Name +
                          "\nSố tiền: " + companies[i]->Amount + " VND";
            label->Dock = DockStyle::Fill;
            label->TextAlign = ContentAlignment::MiddleCenter;

            panel->Controls->Add(label);
            flowLayoutPanelContainer->Controls->Add(panel);
            // Gán sự kiện click cho panel
            //label->Tag = services[i]->Id; // Lưu ID dịch vụ vào Tag
            label->Click +=
                gcnew EventHandler(this, &CompanyForm::OnCompanyClick);
        }

        this->Controls->Add(flowLayoutPanelContainer);
    }

    void CompanyForm::OnCompanyClick(Object ^ sender, EventArgs ^ e) {
        Label ^ clickedLabel = (Label ^) sender;
        // int companyId = (int)clickedLabel->Tag;
         int companyId = 1;

        
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

  array<Companies ^> ^ CompanyForm::GetFakeCompanies() {
          return gcnew array<Companies ^>{
              gcnew Companies(1, "EVN Hà Nội", 1, 500000),
              gcnew Companies(2, "EVN HCM", 1, 600000),
              gcnew Companies(3, "EVN Đà Nẵng", 1, 550000),
              gcnew Companies(4, "EVN Miền Nam", 1, 580000),
              gcnew Companies(5, "EVN Miền Bắc", 1, 570000),

              gcnew Companies(6, "Công ty Nước Sạch Hà Nội", 2, 150000),
              gcnew Companies(7, "Công ty Cấp Nước Sài Gòn", 2, 180000),
              gcnew Companies(8, "Công ty Nước Đà Nẵng", 2, 160000),
              gcnew Companies(9, "Công ty Nước Miền Nam", 2, 170000),
              gcnew Companies(10, "Công ty Nước Miền Bắc", 2, 165000),

              gcnew Companies(11, "VNPT Hà Nội", 3, 300000),
              gcnew Companies(12, "FPT Telecom", 3, 400000),
              gcnew Companies(13, "Viettel Internet", 3, 350000),
              gcnew Companies(14, "CMC Telecom", 3, 320000),
              gcnew Companies(15, "SCTV Internet", 3, 310000),

              gcnew Companies(16, "Viettel Mobile", 4, 100000),
              gcnew Companies(17, "Vinaphone", 4, 120000),
              gcnew Companies(18, "Mobifone", 4, 110000),
              gcnew Companies(19, "Vietnamobile", 4, 90000),
              gcnew Companies(20, "Itel", 4, 95000),

              gcnew Companies(21, "K+ Truyền Hình", 5, 200000),
              gcnew Companies(22, "FPT Play", 5, 250000),
              gcnew Companies(23, "VTVcab", 5, 220000),
              gcnew Companies(24, "SCTV Truyền Hình", 5, 210000),
              gcnew Companies(25, "MyTV", 5, 230000),

              gcnew Companies(26, "ĐH Bách Khoa Hà Nội", 6, 5000000),
              gcnew Companies(27, "ĐH Quốc Gia TP.HCM", 6, 4500000),
              gcnew Companies(28, "ĐH FPT", 6, 6000000),
              gcnew Companies(29, "ĐH RMIT", 6, 10000000),
              gcnew Companies(30, "ĐH Ngoại Thương", 6, 5500000),

              gcnew Companies(31, "Bảo Việt Nhân Thọ", 7, 1000000),
              gcnew Companies(32, "Manulife", 7, 1200000),
              gcnew Companies(33, "Prudential", 7, 1100000),
              gcnew Companies(34, "Generali", 7, 900000),
              gcnew Companies(35, "AIA Việt Nam", 7, 950000),

              gcnew Companies(36, "FE Credit", 8, 2000000),
              gcnew Companies(37, "HD Saison", 8, 1800000),
              gcnew Companies(38, "Home Credit", 8, 1900000),
              gcnew Companies(39, "Mirae Asset", 8, 2200000),
              gcnew Companies(40, "Shinhan Finance", 8, 2100000),

              gcnew Companies(41, "VETC", 9, 50000),
              gcnew Companies(42, "ePass", 9, 60000),
              gcnew Companies(43, "SAVICO", 9, 45000),
              gcnew Companies(44, "Công ty Thu Phí BOT", 9, 55000),
              gcnew Companies(45, "Dịch vụ Đường Bộ", 9, 52000),

              gcnew Companies(46, "BQL Chung Cư Vinhomes", 10, 300000),
              gcnew Companies(47, "BQL Chung Cư Masteri", 10, 280000),
              gcnew Companies(48, "BQL Chung Cư The Manor", 10, 320000),
              gcnew Companies(49, "BQL Chung Cư Sunrise", 10, 310000),
              gcnew Companies(50, "BQL Chung Cư EcoPark", 10, 290000)};
      }

      System::Void
        CompanyForm::btnAccount_Click(System::Object ^ sender, System::EventArgs ^ e) {
        OnUndoClick(sender, e);
    }
};
