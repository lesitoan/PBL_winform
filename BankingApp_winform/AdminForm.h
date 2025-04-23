#pragma once
#include "LoadChildForm.h"

#include "AdminServiceForm.h"
#include "AdminTransactionForm.h"
#include "GlobalData.h"
#include "AdminSavingMoneyForm.h"


ref class TableUsersForm;
ref class EditUserForm;
ref class AuthForm;

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class AdminForm : public System::Windows::Forms::Form {
  public:
    AdminForm(void);

  protected:
    ~AdminForm();


    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panelContent;
    System::Windows::Forms::Panel ^ panelNav;

    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::PictureBox ^ pictureBox1;
    System::Windows::Forms::Label ^ labelFullName;
    System::Windows::Forms::Button ^ btnLogout;
    System::Windows::Forms::Button ^ btnService;
    System::Windows::Forms::Button ^ btnTransaction;
    System::Windows::Forms::Button ^ btnClient;
    System::Windows::Forms::Panel ^ panel2;



  protected:
    System::Windows::Forms::Button ^ btnSavingMoney;

  protected:
    System::Windows::Forms::Label ^ labelHeader;

  protected:

    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->btnSavingMoney = (gcnew System::Windows::Forms::Button());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->labelFullName = (gcnew System::Windows::Forms::Label());
        this->btnLogout = (gcnew System::Windows::Forms::Button());
        this->btnService = (gcnew System::Windows::Forms::Button());
        this->btnTransaction = (gcnew System::Windows::Forms::Button());
        this->btnClient = (gcnew System::Windows::Forms::Button());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->labelHeader = (gcnew System::Windows::Forms::Label());
        this->panel1->SuspendLayout();
        this->panelNav->SuspendLayout();
        this->panel4->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox1))->BeginInit();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                   static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel1->Controls->Add(this->panelNav);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(276, 937);
        this->panel1->TabIndex = 0;
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                     static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panelNav->BackgroundImage = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"panelNav.BackgroundImage")));
        this->panelNav->Controls->Add(this->btnSavingMoney);
        this->panelNav->Controls->Add(this->panel4);
        this->panelNav->Controls->Add(this->btnLogout);
        this->panelNav->Controls->Add(this->btnService);
        this->panelNav->Controls->Add(this->btnTransaction);
        this->panelNav->Controls->Add(this->btnClient);
        this->panelNav->Cursor = System::Windows::Forms::Cursors::Default;
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Left;
        this->panelNav->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
        this->panelNav->Location = System::Drawing::Point(0, 0);
        this->panelNav->Margin = System::Windows::Forms::Padding(4);
        this->panelNav->MinimumSize = System::Drawing::Size(83, 690);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(276, 937);
        this->panelNav->TabIndex = 2;
        //
        // btnSavingMoney
        //
        this->btnSavingMoney->BackColor = System::Drawing::Color::Transparent;
        this->btnSavingMoney->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSavingMoney->FlatAppearance->BorderSize = 0;
        this->btnSavingMoney->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                  static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnSavingMoney->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnSavingMoney->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnSavingMoney->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSavingMoney->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSavingMoney->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnSavingMoney->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"btnSavingMoney.Image")));
        this->btnSavingMoney->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnSavingMoney->Location = System::Drawing::Point(4, 334);
        this->btnSavingMoney->Margin = System::Windows::Forms::Padding(4);
        this->btnSavingMoney->Name = L"btnSavingMoney";
        this->btnSavingMoney->Size = System::Drawing::Size(276, 71);
        this->btnSavingMoney->TabIndex = 15;
        this->btnSavingMoney->Text = L"                 QL TIẾT KIỆM";
        this->btnSavingMoney->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnSavingMoney->UseVisualStyleBackColor = false;
        this->btnSavingMoney->Click += gcnew System::EventHandler(this, &AdminForm::btnSavingMoney_Click);
        //
        // panel4
        //
        this->panel4->BackColor = System::Drawing::Color::Transparent;
        this->panel4->Controls->Add(this->pictureBox1);
        this->panel4->Controls->Add(this->labelFullName);
        this->panel4->Location = System::Drawing::Point(0, 4);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(276, 86);
        this->panel4->TabIndex = 14;
        //
        // pictureBox1
        //
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(25, 15);
        this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(54, 50);
        this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->pictureBox1->TabIndex = 5;
        this->pictureBox1->TabStop = false;
        //
        // labelFullName
        //
        this->labelFullName->AutoSize = true;
        this->labelFullName->BackColor = System::Drawing::Color::Transparent;
        this->labelFullName->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
        this->labelFullName->ForeColor = System::Drawing::Color::White;
        this->labelFullName->Location = System::Drawing::Point(93, 27);
        this->labelFullName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelFullName->Name = L"labelFullName";
        this->labelFullName->Size = System::Drawing::Size(103, 27);
        this->labelFullName->TabIndex = 6;
        this->labelFullName->Text = L"LE SI TOAN";
        this->labelFullName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnLogout
        //
        this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
        this->btnLogout->BackColor = System::Drawing::Color::Brown;
        this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLogout->FlatAppearance->BorderSize = 0;
        this->btnLogout->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Teal;
        this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnLogout->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnLogout->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnLogout->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"btnLogout.Image")));
        this->btnLogout->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLogout->Location = System::Drawing::Point(0, 865);
        this->btnLogout->Margin = System::Windows::Forms::Padding(4);
        this->btnLogout->Name = L"btnLogout";
        this->btnLogout->Size = System::Drawing::Size(276, 71);
        this->btnLogout->TabIndex = 12;
        this->btnLogout->Text = L"                ĐĂNG XUẤT";
        this->btnLogout->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLogout->UseVisualStyleBackColor = false;
        this->btnLogout->Click += gcnew System::EventHandler(this, &AdminForm::btnLogout_Click);
        //
        // btnService
        //
        this->btnService->BackColor = System::Drawing::Color::Transparent;
        this->btnService->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnService->FlatAppearance->BorderSize = 0;
        this->btnService->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                              static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnService->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnService->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnService->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnService->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnService->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnService->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"btnService.Image")));
        this->btnService->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnService->Location = System::Drawing::Point(0, 255);
        this->btnService->Margin = System::Windows::Forms::Padding(4);
        this->btnService->Name = L"btnService";
        this->btnService->Size = System::Drawing::Size(276, 71);
        this->btnService->TabIndex = 10;
        this->btnService->Text = L"                 DỊCH VỤ";
        this->btnService->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnService->UseVisualStyleBackColor = false;
        this->btnService->Click += gcnew System::EventHandler(this, &AdminForm::btnService_Click);
        //
        // btnTransaction
        //
        this->btnTransaction->BackColor = System::Drawing::Color::Transparent;
        this->btnTransaction->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnTransaction->FlatAppearance->BorderSize = 0;
        this->btnTransaction->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                  static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnTransaction->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnTransaction->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnTransaction->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnTransaction->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnTransaction->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnTransaction->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"btnTransaction.Image")));
        this->btnTransaction->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnTransaction->Location = System::Drawing::Point(-4, 176);
        this->btnTransaction->Margin = System::Windows::Forms::Padding(4);
        this->btnTransaction->Name = L"btnTransaction";
        this->btnTransaction->Size = System::Drawing::Size(276, 71);
        this->btnTransaction->TabIndex = 9;
        this->btnTransaction->Text = L"                 GIAO DỊCH";
        this->btnTransaction->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnTransaction->UseVisualStyleBackColor = false;
        this->btnTransaction->Click += gcnew System::EventHandler(this, &AdminForm::btnTransaction_Click);
        //
        // btnClient
        //
        this->btnClient->BackColor = System::Drawing::Color::Transparent;
        this->btnClient->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClient->FlatAppearance->BorderSize = 0;
        this->btnClient->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                             static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnClient->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                               static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnClient->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                               static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClient->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClient->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnClient->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"btnClient.Image")));
        this->btnClient->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnClient->Location = System::Drawing::Point(0, 97);
        this->btnClient->Margin = System::Windows::Forms::Padding(4);
        this->btnClient->Name = L"btnClient";
        this->btnClient->Size = System::Drawing::Size(276, 71);
        this->btnClient->TabIndex = 0;
        this->btnClient->Text = L"                 KHÁCH HÀNG";
        this->btnClient->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnClient->UseVisualStyleBackColor = false;
        this->btnClient->Click += gcnew System::EventHandler(this, &AdminForm::btnClient_Click);
        //
        // panelContent
        //
        this->panelContent->BackColor = System::Drawing::Color::White;
        this->panelContent->BackgroundImage = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"panelContent.BackgroundImage")));
        this->panelContent->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(276, 52);
        this->panelContent->Margin = System::Windows::Forms::Padding(4);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(1436, 885);
        this->panelContent->TabIndex = 2;
        //
        // panel2
        //
        this->panel2->Controls->Add(this->labelHeader);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel2->Location = System::Drawing::Point(276, 0);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(1436, 52);
        this->panel2->TabIndex = 3;
        //
        // labelHeader
        //
        this->labelHeader->AutoSize = true;
        this->labelHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                        static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->labelHeader->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->labelHeader->ForeColor = System::Drawing::Color::White;
        this->labelHeader->Location = System::Drawing::Point(3, 4);
        this->labelHeader->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelHeader->Name = L"labelHeader";
        this->labelHeader->Padding = System::Windows::Forms::Padding(9);
        this->labelHeader->Size = System::Drawing::Size(246, 45);
        this->labelHeader->TabIndex = 4;
        this->labelHeader->Text = L"DANH SÁCH KHÁCH HÀNG";
        this->labelHeader->Click += gcnew System::EventHandler(this, &AdminForm::labelHeader_Click);
        //
        // AdminForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1712, 937);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Icon = (cli::safe_cast<System::Drawing::Icon ^>(resources->GetObject(L"$this.Icon")));
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"AdminForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"AdminForm";
        this->panel1->ResumeLayout(false);
        this->panelNav->ResumeLayout(false);
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox1))->EndInit();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

    private:
        System::Collections::Generic::Stack<Form ^> ^ formHistory = gcnew System::Collections::Generic::Stack<Form ^>();
    System::Void btnClient_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);
    System::Void btnTransaction_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);
    System::Void btnService_Click(System::Object ^ sender,
                                  System::EventArgs ^ e);
    System::Void btnLogout_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    public:
    void LoadForm(Form ^ childForm);
    void UndoLastForm();

  private:
    System::Void btnSavingMoney_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);

  private:
    System::Void labelHeader_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {}
};
} // namespace BankingAppwinform
