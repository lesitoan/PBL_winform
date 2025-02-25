#pragma once
#include "AccountForm.h"
#include "HistoryForm.h"
#include "LoadChildForm.h"
#include "TransferMoneyForm.h"
#include "WithdrawMoneyForm.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class MainForm : public System::Windows::Forms::Form {
  public:
    MainForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    ~MainForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panelHeader;

  private:
    System::Windows::Forms::Panel ^ panelNav;

  private:
    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Button ^ btnAccount;

  private:
    System::Windows::Forms::Button ^ btnLogout;

  private:
    System::Windows::Forms::Button ^ btnWithdraw;

  private:
    System::Windows::Forms::Button ^ btnHistory;

  private:
    System::Windows::Forms::Button ^ btnTransfer;

  protected:
  protected:
  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code

    void InitializeComponent(void) {
        this->panelHeader = (gcnew System::Windows::Forms::Panel());
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->btnLogout = (gcnew System::Windows::Forms::Button());
        this->btnWithdraw = (gcnew System::Windows::Forms::Button());
        this->btnHistory = (gcnew System::Windows::Forms::Button());
        this->btnTransfer = (gcnew System::Windows::Forms::Button());
        this->btnAccount = (gcnew System::Windows::Forms::Button());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panelNav->SuspendLayout();
        this->panelContent->SuspendLayout();
        this->SuspendLayout();
        //
        // panelHeader
        //
        this->panelHeader->BackColor = System::Drawing::Color::MediumSeaGreen;
        this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
        this->panelHeader->Location = System::Drawing::Point(0, 0);
        this->panelHeader->Name = L"panelHeader";
        this->panelHeader->Size = System::Drawing::Size(784, 29);
        this->panelHeader->TabIndex = 0;
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::SystemColors::WindowFrame;
        this->panelNav->Controls->Add(this->btnLogout);
        this->panelNav->Controls->Add(this->btnWithdraw);
        this->panelNav->Controls->Add(this->btnHistory);
        this->panelNav->Controls->Add(this->btnTransfer);
        this->panelNav->Controls->Add(this->btnAccount);
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Left;
        this->panelNav->ForeColor =
            System::Drawing::SystemColors::InactiveCaptionText;
        this->panelNav->Location = System::Drawing::Point(0, 29);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(200, 432);
        this->panelNav->TabIndex = 1;
        //
        // btnLogout
        //
        this->btnLogout->BackColor = System::Drawing::Color::Firebrick;
        this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnLogout->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnLogout->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnLogout->Location = System::Drawing::Point(24, 386);
        this->btnLogout->Name = L"btnLogout";
        this->btnLogout->Size = System::Drawing::Size(143, 34);
        this->btnLogout->TabIndex = 4;
        this->btnLogout->Text = L"Dang xuat";
        this->btnLogout->UseVisualStyleBackColor = false;
        this->btnLogout->Click +=
            gcnew System::EventHandler(this, &MainForm::btnLogout_Click);
        //
        // btnWithdraw
        //
        this->btnWithdraw->BackColor =
            System::Drawing::SystemColors::WindowFrame;
        this->btnWithdraw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnWithdraw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnWithdraw->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnWithdraw->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnWithdraw->Location = System::Drawing::Point(24, 122);
        this->btnWithdraw->Name = L"btnWithdraw";
        this->btnWithdraw->Size = System::Drawing::Size(143, 34);
        this->btnWithdraw->TabIndex = 3;
        this->btnWithdraw->Text = L"Rut tien";
        this->btnWithdraw->UseVisualStyleBackColor = false;
        this->btnWithdraw->Click +=
            gcnew System::EventHandler(this, &MainForm::btnWithdraw_Click);
        //
        // btnHistory
        //
        this->btnHistory->BackColor =
            System::Drawing::SystemColors::WindowFrame;
        this->btnHistory->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnHistory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnHistory->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnHistory->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnHistory->Location = System::Drawing::Point(24, 174);
        this->btnHistory->Name = L"btnHistory";
        this->btnHistory->Size = System::Drawing::Size(143, 34);
        this->btnHistory->TabIndex = 2;
        this->btnHistory->Text = L"Lich su";
        this->btnHistory->UseVisualStyleBackColor = false;
        this->btnHistory->Click +=
            gcnew System::EventHandler(this, &MainForm::btnHistory_Click);
        //
        // btnTransfer
        //
        this->btnTransfer->BackColor =
            System::Drawing::SystemColors::WindowFrame;
        this->btnTransfer->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnTransfer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnTransfer->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnTransfer->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnTransfer->Location = System::Drawing::Point(24, 70);
        this->btnTransfer->Name = L"btnTransfer";
        this->btnTransfer->Size = System::Drawing::Size(143, 34);
        this->btnTransfer->TabIndex = 1;
        this->btnTransfer->Text = L"Chuyen tien";
        this->btnTransfer->UseVisualStyleBackColor = false;
        this->btnTransfer->Click +=
            gcnew System::EventHandler(this, &MainForm::btnTransfer_Click);
        //
        // btnAccount
        //
        this->btnAccount->BackColor =
            System::Drawing::SystemColors::WindowFrame;
        this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAccount->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnAccount->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnAccount->Location = System::Drawing::Point(24, 18);
        this->btnAccount->Name = L"btnAccount";
        this->btnAccount->Size = System::Drawing::Size(143, 34);
        this->btnAccount->TabIndex = 0;
        this->btnAccount->Text = L" Tai Khoan";
        this->btnAccount->UseVisualStyleBackColor = false;
        this->btnAccount->Click +=
            gcnew System::EventHandler(this, &MainForm::btnAccount_Click);
        //
        // panelContent
        //
        this->panelContent->BackColor = System::Drawing::SystemColors::Control;
        this->panelContent->Controls->Add(this->panel1);
        this->panelContent->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(200, 29);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(584, 432);
        this->panelContent->TabIndex = 2;
        //
        // panel1
        //
        this->panel1->BackColor =
            System::Drawing::SystemColors::ControlDarkDark;
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(584, 29);
        this->panel1->TabIndex = 0;
        //
        // MainForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(784, 461);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panelNav);
        this->Controls->Add(this->panelHeader);
        this->Name = L"MainForm";
        this->ShowInTaskbar = false;
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"MainForm";
        this->Load +=
            gcnew System::EventHandler(this, &MainForm::MainForm_Load);
        this->panelNav->ResumeLayout(false);
        this->panelContent->ResumeLayout(false);
        this->ResumeLayout(false);
    }

#pragma endregion
  private:
    System::Void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
        // System::Windows::Forms::FormBorderStyle::None;
    }

  private:
    System::Void btnAccount_Click(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew AccountForm());
    }

  private:
    System::Void btnTransfer_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew TransferMoneyForm());
    }

  private:
    System::Void btnWithdraw_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew WithdrawMoneyForm());
    }

  private:
    System::Void btnHistory_Click(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew HistoryForm());
    }

  private:
    System::Void btnLogout_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        System::Windows::Forms::DialogResult result;
        result = MessageBox::Show("Bạn có chắc chắn muốn đăng xuất?",
                                  "Đăng xuất", MessageBoxButtons::YesNo,
                                  MessageBoxIcon::Question);
        if (result == System::Windows::Forms::DialogResult::Yes) {
            this->Close();
        }
    }
};
} // namespace BankingAppwinform
