#pragma once
#include "AccountForm.h"
#include "HistoryForm.h"
#include "LoadChildForm.h"
#include "TransferMoneyForm.h"
#include "WithdrawMoneyForm.h"
#include "User.h"
#include "GlobalData.h"

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
    MainForm() {
        InitializeComponent();
    }

  protected:
    ~MainForm() {
        if (components) {
            delete components;
        }
    }

  private:

    System::Windows::Forms::Panel ^ panelNav;


    System::Windows::Forms::Button ^ btnAccount;





  private:
    System::Windows::Forms::PictureBox ^ pictureBox1;

  private:


  private:
    System::Windows::Forms::CheckBox ^ checkBox1;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Button ^ btnHistory;

  private:


  private:
    System::Windows::Forms::Button ^ btnWithdraw;

  private:


  private:
    System::Windows::Forms::Button ^ btnTransfer;

  private:
    System::Windows::Forms::Button ^ btnLogout;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::Label ^ headerText;

  private:


  private:


    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                MainForm::typeid));
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->btnLogout = (gcnew System::Windows::Forms::Button());
        this->btnHistory = (gcnew System::Windows::Forms::Button());
        this->btnWithdraw = (gcnew System::Windows::Forms::Button());
        this->btnTransfer = (gcnew System::Windows::Forms::Button());
        this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->btnAccount = (gcnew System::Windows::Forms::Button());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->headerText = (gcnew System::Windows::Forms::Label());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panelNav->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->BeginInit();
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panelNav->Controls->Add(this->btnLogout);
        this->panelNav->Controls->Add(this->btnHistory);
        this->panelNav->Controls->Add(this->btnWithdraw);
        this->panelNav->Controls->Add(this->btnTransfer);
        this->panelNav->Controls->Add(this->checkBox1);
        this->panelNav->Controls->Add(this->label2);
        this->panelNav->Controls->Add(this->label1);
        this->panelNav->Controls->Add(this->pictureBox1);
        this->panelNav->Controls->Add(this->btnAccount);
        this->panelNav->Cursor = System::Windows::Forms::Cursors::Default;
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Left;
        this->panelNav->ForeColor =
            System::Drawing::SystemColors::InactiveCaptionText;
        this->panelNav->Location = System::Drawing::Point(0, 0);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(207, 561);
        this->panelNav->TabIndex = 1;
        //
        // btnLogout
        //
        this->btnLogout->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
        this->btnLogout->BackColor = System::Drawing::Color::Brown;
        this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLogout->FlatAppearance->BorderSize = 0;
        this->btnLogout->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnLogout->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13, System::Drawing::FontStyle::Bold));
        this->btnLogout->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnLogout->ImageAlign =
            System::Drawing::ContentAlignment::BottomCenter;
        this->btnLogout->Location = System::Drawing::Point(0, 503);
        this->btnLogout->Name = L"btnLogout";
        this->btnLogout->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
        this->btnLogout->Size = System::Drawing::Size(207, 58);
        this->btnLogout->TabIndex = 12;
        this->btnLogout->Text = L"ĐĂNG XUẤT";
        this->btnLogout->UseVisualStyleBackColor = false;
        this->btnLogout->Click +=
            gcnew System::EventHandler(this, &MainForm::btnLogout_Click);
        //
        // btnHistory
        //
        this->btnHistory->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnHistory->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnHistory->FlatAppearance->BorderSize = 0;
        this->btnHistory->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnHistory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnHistory->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13, System::Drawing::FontStyle::Bold));
        this->btnHistory->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnHistory->Location = System::Drawing::Point(-3, 291);
        this->btnHistory->Name = L"btnHistory";
        this->btnHistory->Padding =
            System::Windows::Forms::Padding(15, 0, 0, 0);
        this->btnHistory->Size = System::Drawing::Size(207, 58);
        this->btnHistory->TabIndex = 11;
        this->btnHistory->Text = L"LỊCH SỬ";
        this->btnHistory->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnHistory->UseVisualStyleBackColor = false;
        this->btnHistory->Click +=
            gcnew System::EventHandler(this, &MainForm::btnHistory_Click);
        //
        // btnWithdraw
        //
        this->btnWithdraw->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnWithdraw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnWithdraw->FlatAppearance->BorderSize = 0;
        this->btnWithdraw->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnWithdraw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnWithdraw->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13, System::Drawing::FontStyle::Bold));
        this->btnWithdraw->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnWithdraw->Location = System::Drawing::Point(0, 227);
        this->btnWithdraw->Name = L"btnWithdraw";
        this->btnWithdraw->Padding =
            System::Windows::Forms::Padding(15, 0, 0, 0);
        this->btnWithdraw->Size = System::Drawing::Size(207, 58);
        this->btnWithdraw->TabIndex = 10;
        this->btnWithdraw->Text = L"RÚT TIỀN";
        this->btnWithdraw->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnWithdraw->UseVisualStyleBackColor = false;
        this->btnWithdraw->Click +=
            gcnew System::EventHandler(this, &MainForm::btnWithdraw_Click);
        //
        // btnTransfer
        //
        this->btnTransfer->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnTransfer->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnTransfer->FlatAppearance->BorderSize = 0;
        this->btnTransfer->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnTransfer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnTransfer->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13, System::Drawing::FontStyle::Bold));
        this->btnTransfer->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnTransfer->Location = System::Drawing::Point(0, 163);
        this->btnTransfer->Name = L"btnTransfer";
        this->btnTransfer->Padding =
            System::Windows::Forms::Padding(15, 0, 0, 0);
        this->btnTransfer->Size = System::Drawing::Size(207, 58);
        this->btnTransfer->TabIndex = 9;
        this->btnTransfer->Text = L"CHUYỂN TIỀN";
        this->btnTransfer->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnTransfer->UseVisualStyleBackColor = false;
        this->btnTransfer->Click +=
            gcnew System::EventHandler(this, &MainForm::btnTransfer_Click);
        //
        // checkBox1
        //
        this->checkBox1->AutoSize = true;
        this->checkBox1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->checkBox1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 8));
        this->checkBox1->ForeColor =
            System::Drawing::SystemColors::ControlLightLight;
        this->checkBox1->Location = System::Drawing::Point(78, 55);
        this->checkBox1->Name = L"checkBox1";
        this->checkBox1->Size = System::Drawing::Size(52, 18);
        this->checkBox1->TabIndex = 8;
        this->checkBox1->Text = L"Show";
        this->checkBox1->UseVisualStyleBackColor = true;
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->ForeColor = System::Drawing::Color::White;
        this->label2->Location = System::Drawing::Point(74, 33);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(90, 19);
        this->label2->TabIndex = 7;
        this->label2->Text = L"120000VNĐ";
        this->label2->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::White;
        this->label1->Location = System::Drawing::Point(74, 11);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(81, 22);
        this->label1->TabIndex = 6;
        this->label1->Text = L"LE SI TOAN";
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // pictureBox1
        //
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(12, 12);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(60, 57);
        this->pictureBox1->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->pictureBox1->TabIndex = 5;
        this->pictureBox1->TabStop = false;
        //
        // btnAccount
        //
        this->btnAccount->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAccount->FlatAppearance->BorderSize = 0;
        this->btnAccount->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAccount->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13, System::Drawing::FontStyle::Bold));
        this->btnAccount->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnAccount->Location = System::Drawing::Point(0, 99);
        this->btnAccount->Name = L"btnAccount";
        this->btnAccount->Padding =
            System::Windows::Forms::Padding(15, 0, 0, 0);
        this->btnAccount->Size = System::Drawing::Size(207, 58);
        this->btnAccount->TabIndex = 0;
        this->btnAccount->Text = L"TÀI KHOẢN";
        this->btnAccount->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->UseVisualStyleBackColor = false;
        this->btnAccount->Click +=
            gcnew System::EventHandler(this, &MainForm::btnAccount_Click);
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel1->Controls->Add(this->headerText);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(207, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(677, 42);
        this->panel1->TabIndex = 2;
        //
        // headerText
        //
        this->headerText->Dock = System::Windows::Forms::DockStyle::Fill;
        this->headerText->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13, System::Drawing::FontStyle::Bold));
        this->headerText->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->headerText->Location = System::Drawing::Point(0, 0);
        this->headerText->Name = L"headerText";
        this->headerText->Size = System::Drawing::Size(677, 42);
        this->headerText->TabIndex = 0;
        this->headerText->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panelContent
        //
        this->panelContent->BackColor = System::Drawing::Color::Teal;
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(207, 42);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(677, 519);
        this->panelContent->TabIndex = 3;
        //
        // MainForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(884, 561);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->panelNav);
        this->MinimumSize = System::Drawing::Size(900, 600);
        this->Name = L"MainForm";
        this->ShowInTaskbar = false;
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"MainForm";
        this->Load +=
            gcnew System::EventHandler(this, &MainForm::MainForm_Load);
        this->panelNav->ResumeLayout(false);
        this->panelNav->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->EndInit();
        this->panel1->ResumeLayout(false);
        this->ResumeLayout(false);
    }


#pragma endregion
  private:
    Button ^ selectedButton = nullptr;
    void ChangeButtonColor(Button ^ button) {
        if (selectedButton != nullptr) {
            selectedButton->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
        }
        selectedButton = button;
        selectedButton->BackColor = System::Drawing::Color::Teal;
    }
  private:
    System::Void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
        User ^ user = GlobalData::GetCurrentUser();
        LoadChildForm::LoadForm(this->panelContent, gcnew AccountForm());
        this->headerText->Text = L"DOASHBOARD";
    }
    System::Void btnAccount_Click(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew AccountForm());
        ChangeButtonColor(btnAccount);
        this->headerText->Text = L"TÀI KHOẢN";
    }
    System::Void btnTransfer_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew TransferMoneyForm());
        ChangeButtonColor(btnTransfer);
        this->headerText->Text = L"CHUYỂN KHOẢN";

    }
    System::Void btnWithdraw_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew WithdrawMoneyForm());
        ChangeButtonColor(btnWithdraw);
        this->headerText->Text = L"RÚT TIỀN";

    }
    System::Void btnHistory_Click(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew HistoryForm());
        ChangeButtonColor(btnHistory);
        this->headerText->Text = L"LỊCH SỬ";

    }
    System::Void btnLogout_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        System::Windows::Forms::DialogResult result;
        result = MessageBox::Show("Bạn có chắc chắn muốn đăng xuất?",
                                  "Đăng xuất", MessageBoxButtons::YesNo,
                                  MessageBoxIcon::Question);
        if (result == System::Windows::Forms::DialogResult::Yes) {
            GlobalData::SetCurrentUser(nullptr);
            this->Close();
        }
    }

};
}
