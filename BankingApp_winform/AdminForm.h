#pragma once
#include "LoadChildForm.h"

#include "AdminServiceForm.h"
#include "AdminTransactionForm.h"
#include "GlobalData.h"

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

/// <summary>
/// Summary for AdminForm
/// </summary>
public
ref class AdminForm : public System::Windows::Forms::Form {
  public:
    AdminForm(void);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~AdminForm();

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
  private:
  private:
    System::Windows::Forms::Panel ^ panelContent;

  private:
  private:
    System::Windows::Forms::Panel ^ panelNav;

  private:
    System::Windows::Forms::Button ^ btnMenu;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::PictureBox ^ pictureBox1;

  private:
    System::Windows::Forms::Label ^ labelFullName;

  private:
  private:
  private:
    System::Windows::Forms::Button ^ btnLogout;

  private:
    System::Windows::Forms::Button ^ btnService;

  private:
  private:
  private:
    System::Windows::Forms::Button ^ btnTransaction;

  private:
  private:
    System::Windows::Forms::Button ^ btnClient;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Label ^ labelHeader;

  private:
    System::Windows::Forms::PictureBox ^ pictureBox2;

  private:


  private:
  protected:
  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AdminForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->btnMenu = (gcnew System::Windows::Forms::Button());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->labelFullName = (gcnew System::Windows::Forms::Label());
        this->btnLogout = (gcnew System::Windows::Forms::Button());
        this->btnService = (gcnew System::Windows::Forms::Button());
        this->btnTransaction = (gcnew System::Windows::Forms::Button());
        this->btnClient = (gcnew System::Windows::Forms::Button());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->labelHeader = (gcnew System::Windows::Forms::Label());
        this->panel1->SuspendLayout();
        this->panelNav->SuspendLayout();
        this->panel4->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->BeginInit();
        this->panelContent->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->BeginInit();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel1->Controls->Add(this->panelNav);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(207, 761);
        this->panel1->TabIndex = 0;
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panelNav->Controls->Add(this->btnMenu);
        this->panelNav->Controls->Add(this->panel4);
        this->panelNav->Controls->Add(this->btnLogout);
        this->panelNav->Controls->Add(this->btnService);
        this->panelNav->Controls->Add(this->btnTransaction);
        this->panelNav->Controls->Add(this->btnClient);
        this->panelNav->Cursor = System::Windows::Forms::Cursors::Default;
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Left;
        this->panelNav->ForeColor =
            System::Drawing::SystemColors::InactiveCaptionText;
        this->panelNav->Location = System::Drawing::Point(0, 0);
        this->panelNav->MinimumSize = System::Drawing::Size(62, 561);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(207, 761);
        this->panelNav->TabIndex = 2;
        //
        // btnMenu
        //
        this->btnMenu->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnMenu->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnMenu->FlatAppearance->BorderSize = 0;
        this->btnMenu->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnMenu->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnMenu->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnMenu->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnMenu.Image")));
        this->btnMenu->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnMenu->Location = System::Drawing::Point(0, 0);
        this->btnMenu->Name = L"btnMenu";
        this->btnMenu->Size = System::Drawing::Size(207, 42);
        this->btnMenu->TabIndex = 13;
        this->btnMenu->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnMenu->UseVisualStyleBackColor = false;
        //
        // panel4
        //
        this->panel4->Controls->Add(this->pictureBox1);
        this->panel4->Controls->Add(this->labelFullName);
        this->panel4->Location = System::Drawing::Point(0, 42);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(207, 70);
        this->panel4->TabIndex = 14;
        //
        // pictureBox1
        //
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(12, 12);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(41, 41);
        this->pictureBox1->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->pictureBox1->TabIndex = 5;
        this->pictureBox1->TabStop = false;
        //
        // labelFullName
        //
        this->labelFullName->AutoSize = true;
        this->labelFullName->BackColor = System::Drawing::Color::Transparent;
        this->labelFullName->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelFullName->ForeColor = System::Drawing::Color::White;
        this->labelFullName->Location = System::Drawing::Point(70, 22);
        this->labelFullName->Name = L"labelFullName";
        this->labelFullName->Size = System::Drawing::Size(81, 22);
        this->labelFullName->TabIndex = 6;
        this->labelFullName->Text = L"LE SI TOAN";
        this->labelFullName->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnLogout
        //
        this->btnLogout->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Bottom |
                 System::Windows::Forms::AnchorStyles::Left));
        this->btnLogout->BackColor = System::Drawing::Color::Brown;
        this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLogout->FlatAppearance->BorderSize = 0;
        this->btnLogout->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnLogout->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnLogout->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnLogout->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnLogout.Image")));
        this->btnLogout->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLogout->Location = System::Drawing::Point(0, 703);
        this->btnLogout->Name = L"btnLogout";
        this->btnLogout->Size = System::Drawing::Size(207, 58);
        this->btnLogout->TabIndex = 12;
        this->btnLogout->Text = L"                  ĐĂNG XUẤT";
        this->btnLogout->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLogout->UseVisualStyleBackColor = false;
        this->btnLogout->Click +=
            gcnew System::EventHandler(this, &AdminForm::btnLogout_Click);
        //
        // btnService
        //
        this->btnService->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnService->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnService->FlatAppearance->BorderSize = 0;
        this->btnService->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnService->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnService->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnService->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnService->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnService->Location = System::Drawing::Point(0, 246);
        this->btnService->Name = L"btnService";
        this->btnService->Size = System::Drawing::Size(207, 58);
        this->btnService->TabIndex = 10;
        this->btnService->Text = L"                   DỊCH VỤ";
        this->btnService->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnService->UseVisualStyleBackColor = false;
        this->btnService->Click +=
            gcnew System::EventHandler(this, &AdminForm::btnService_Click);
        //
        // btnTransaction
        //
        this->btnTransaction->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnTransaction->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnTransaction->FlatAppearance->BorderSize = 0;
        this->btnTransaction->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnTransaction->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnTransaction->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnTransaction->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnTransaction->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnTransaction->Location = System::Drawing::Point(0, 182);
        this->btnTransaction->Name = L"btnTransaction";
        this->btnTransaction->Size = System::Drawing::Size(207, 58);
        this->btnTransaction->TabIndex = 9;
        this->btnTransaction->Text = L"                   GIAO DỊCH";
        this->btnTransaction->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnTransaction->UseVisualStyleBackColor = false;
        this->btnTransaction->Click +=
            gcnew System::EventHandler(this, &AdminForm::btnTransaction_Click);
        //
        // btnClient
        //
        this->btnClient->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnClient->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClient->FlatAppearance->BorderSize = 0;
        this->btnClient->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClient->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClient->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnClient->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnClient->Location = System::Drawing::Point(0, 118);
        this->btnClient->Name = L"btnClient";
        this->btnClient->Size = System::Drawing::Size(207, 58);
        this->btnClient->TabIndex = 0;
        this->btnClient->Text = L"                   KHÁCH HÀNG";
        this->btnClient->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnClient->UseVisualStyleBackColor = false;
        this->btnClient->Click +=
            gcnew System::EventHandler(this, &AdminForm::btnClient_Click);
        //
        // panelContent
        //
        this->panelContent->BackColor = System::Drawing::Color::Teal;
        this->panelContent->Controls->Add(this->pictureBox2);
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(207, 42);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(1077, 719);
        this->panelContent->TabIndex = 2;
        //
        // pictureBox2
        //
        this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
        this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox2.Image")));
        this->pictureBox2->Location = System::Drawing::Point(234, 85);
        this->pictureBox2->Name = L"pictureBox2";
        this->pictureBox2->Size = System::Drawing::Size(683, 500);
        this->pictureBox2->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::Zoom;
        this->pictureBox2->TabIndex = 0;
        this->pictureBox2->TabStop = false;
        //
        // panel2
        //
        this->panel2->Controls->Add(this->labelHeader);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel2->Location = System::Drawing::Point(207, 0);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(1077, 42);
        this->panel2->TabIndex = 3;
        //
        // labelHeader
        //
        this->labelHeader->AutoSize = true;
        this->labelHeader->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->labelHeader->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->labelHeader->ForeColor = System::Drawing::Color::White;
        this->labelHeader->Location = System::Drawing::Point(22, 0);
        this->labelHeader->Name = L"labelHeader";
        this->labelHeader->Padding = System::Windows::Forms::Padding(7);
        this->labelHeader->Size = System::Drawing::Size(196, 35);
        this->labelHeader->TabIndex = 4;
        this->labelHeader->Text = L"DANH SÁCH KHÁCH HÀNG";
        //
        // AdminForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1284, 761);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Name = L"AdminForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"AdminForm";
        this->panel1->ResumeLayout(false);
        this->panelNav->ResumeLayout(false);
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->EndInit();
        this->panelContent->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->EndInit();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

    private:
        System::Collections::Generic::Stack<Form ^> ^ formHistory = gcnew System::Collections::Generic::Stack<Form ^>();

  public:
    void LoadForm(Form ^ childForm);
    void UndoLastForm();

  private:
    System::Void btnClient_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

  private:
    System::Void btnTransaction_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);

  private:
    System::Void btnService_Click(System::Object ^ sender,
                                  System::EventArgs ^ e);

  private:
    System::Void btnLogout_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);
};
} // namespace BankingAppwinform
