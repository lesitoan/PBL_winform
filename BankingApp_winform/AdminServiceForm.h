#pragma once
#include "AdminForm.h"
#include "CompanyForm.h"
#include "HandleFile.h"
#include "ModifyServiceForm.h"
#include "Services.h"

ref class AdminForm;
namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class AdminServiceForm : public System::Windows::Forms::Form {
  public:
    AdminServiceForm(void);

  protected:
    ~AdminServiceForm();

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanelContainer;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::PictureBox ^ pictureBox1;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::PictureBox ^ pictureBox2;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::Button ^ btnAddService;
    System::Windows::Forms::Button ^ btnDeleteService;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AdminServiceForm::typeid));
        this->flowLayoutPanelContainer =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->btnAddService = (gcnew System::Windows::Forms::Button());
        this->btnDeleteService = (gcnew System::Windows::Forms::Button());
        this->flowLayoutPanelContainer->SuspendLayout();
        this->panel1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->BeginInit();
        this->panel2->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->BeginInit();
        this->panel3->SuspendLayout();
        this->SuspendLayout();
        //
        // flowLayoutPanelContainer
        //
        this->flowLayoutPanelContainer->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->flowLayoutPanelContainer->AutoScroll = true;
        this->flowLayoutPanelContainer->BackColor =
            System::Drawing::SystemColors::ButtonFace;
        this->flowLayoutPanelContainer->Controls->Add(this->panel1);
        this->flowLayoutPanelContainer->Controls->Add(this->panel2);
        this->flowLayoutPanelContainer->Location = System::Drawing::Point(0, 0);
        this->flowLayoutPanelContainer->Name = L"flowLayoutPanelContainer";
        this->flowLayoutPanelContainer->Size = System::Drawing::Size(1077, 649);
        this->flowLayoutPanelContainer->TabIndex = 0;
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)));
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->pictureBox1);
        this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panel1->Location = System::Drawing::Point(24, 12);
        this->panel1->Margin = System::Windows::Forms::Padding(24, 12, 0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(139, 147);
        this->panel1->TabIndex = 0;
        this->panel1->Visible = false;
        this->panel1->Click +=
            gcnew System::EventHandler(this, &AdminServiceForm::panel1_Click);
        //
        // label1
        //
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->label1->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label1->Location = System::Drawing::Point(0, 98);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(139, 49);
        this->label1->TabIndex = 1;
        this->label1->Text = L"Thanh toán điện";
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // pictureBox1
        //
        this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Top;
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(0, 0);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(139, 98);
        this->pictureBox1->TabIndex = 0;
        this->pictureBox1->TabStop = false;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)));
        this->panel2->Controls->Add(this->label2);
        this->panel2->Controls->Add(this->pictureBox2);
        this->panel2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panel2->Location = System::Drawing::Point(175, 12);
        this->panel2->Margin = System::Windows::Forms::Padding(12, 12, 0, 0);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(139, 147);
        this->panel2->TabIndex = 1;
        this->panel2->Visible = false;
        //
        // label2
        //
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->label2->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label2->Location = System::Drawing::Point(0, 98);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(139, 49);
        this->label2->TabIndex = 3;
        this->label2->Text = L"Thanh toán nước";
        this->label2->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // pictureBox2
        //
        this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Top;
        this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox2.Image")));
        this->pictureBox2->Location = System::Drawing::Point(0, 0);
        this->pictureBox2->Name = L"pictureBox2";
        this->pictureBox2->Size = System::Drawing::Size(139, 98);
        this->pictureBox2->TabIndex = 2;
        this->pictureBox2->TabStop = false;
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
        this->panel3->Controls->Add(this->btnAddService);
        this->panel3->Controls->Add(this->btnDeleteService);
        this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
        this->panel3->Location = System::Drawing::Point(0, 645);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(1077, 66);
        this->panel3->TabIndex = 1;
        //
        // btnAddService
        //
        this->btnAddService->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnAddService->BackColor = System::Drawing::Color::Green;
        this->btnAddService->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAddService->FlatAppearance->BorderSize = 0;
        this->btnAddService->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnAddService->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnAddService->ForeColor = System::Drawing::Color::Transparent;
        this->btnAddService->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnAddService.Image")));
        this->btnAddService->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAddService->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->btnAddService->Location = System::Drawing::Point(675, 17);
        this->btnAddService->Name = L"btnAddService";
        this->btnAddService->Padding =
            System::Windows::Forms::Padding(8, 0, 0, 0);
        this->btnAddService->Size = System::Drawing::Size(188, 37);
        this->btnAddService->TabIndex = 35;
        this->btnAddService->Text = L"  Thêm dịch vụ";
        this->btnAddService->UseVisualStyleBackColor = false;
        this->btnAddService->Click += gcnew System::EventHandler(
            this, &AdminServiceForm::btnAddService_Click);
        //
        // btnDeleteService
        //
        this->btnDeleteService->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnDeleteService->BackColor = System::Drawing::Color::Red;
        this->btnDeleteService->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnDeleteService->FlatAppearance->BorderSize = 0;
        this->btnDeleteService->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnDeleteService->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnDeleteService->ForeColor = System::Drawing::Color::Transparent;
        this->btnDeleteService->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"btnDeleteService.Image")));
        this->btnDeleteService->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnDeleteService->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->btnDeleteService->Location = System::Drawing::Point(880, 17);
        this->btnDeleteService->Name = L"btnDeleteService";
        this->btnDeleteService->Padding =
            System::Windows::Forms::Padding(14, 0, 0, 0);
        this->btnDeleteService->Size = System::Drawing::Size(185, 37);
        this->btnDeleteService->TabIndex = 34;
        this->btnDeleteService->Text = L"     Xóa dịch vụ";
        this->btnDeleteService->UseVisualStyleBackColor = false;
        this->btnDeleteService->Click += gcnew System::EventHandler(
            this, &AdminServiceForm::btnDeleteService_Click);
        //
        // AdminServiceForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->flowLayoutPanelContainer);
        this->Controls->Add(this->panel3);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"AdminServiceForm";
        this->Text = L"AdminServiceForm";
        this->flowLayoutPanelContainer->ResumeLayout(false);
        this->panel1->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->EndInit();
        this->panel2->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->EndInit();
        this->panel3->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    void LoadServices();
    void OnServiceClick(Object ^ sender, EventArgs ^ e);

    System::Void panel1_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void btnAddService_Click(System::Object ^ sender,
                                     System::EventArgs ^ e);

    System::Void AdminServiceForm::onModyfyService(System::Object ^ sender,
                                                   System::EventArgs ^ e);

    System::Void btnDeleteService_Click(System::Object ^ sender,
                                        System::EventArgs ^ e);
};
}
