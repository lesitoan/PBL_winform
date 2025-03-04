#pragma once
#include "ChangePwForm.h"
#include "GlobalData.h"
#include "LoadChildForm.h"
#include "SetPinForm.h"
#include "User.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class AccountForm : public System::Windows::Forms::Form {
  public:
    AccountForm(void);

  protected:
    ~AccountForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Label ^ labelAccountNumber;
    System::Windows::Forms::Label ^ labelFullName;
    System::Windows::Forms::Label ^ labelBalance;
    System::Windows::Forms::Panel ^ panelBtn1;
    System::Windows::Forms::Panel ^ panelNav;
    System::Windows::Forms::Panel ^ panelContent;
    System::Windows::Forms::Panel ^ panelBtn3;
    System::Windows::Forms::Panel ^ panelBtn2;
    System::Windows::Forms::Panel ^ panelBtn4;
    System::Windows::Forms::Button ^ buttonSetAvatar;
    System::Windows::Forms::Button ^ btnChangePw;
    System::Windows::Forms::Button ^ btnDeleteAccount;
    System::Windows::Forms::Button ^ btnSetPin;
    System::Windows::Forms::PictureBox ^ pictureBox1;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Panel ^ panel2;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AccountForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->labelBalance = (gcnew System::Windows::Forms::Label());
        this->labelAccountNumber = (gcnew System::Windows::Forms::Label());
        this->labelFullName = (gcnew System::Windows::Forms::Label());
        this->panelBtn1 = (gcnew System::Windows::Forms::Panel());
        this->btnSetPin = (gcnew System::Windows::Forms::Button());
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->panelBtn4 = (gcnew System::Windows::Forms::Panel());
        this->btnDeleteAccount = (gcnew System::Windows::Forms::Button());
        this->panelBtn3 = (gcnew System::Windows::Forms::Panel());
        this->buttonSetAvatar = (gcnew System::Windows::Forms::Button());
        this->panelBtn2 = (gcnew System::Windows::Forms::Panel());
        this->btnChangePw = (gcnew System::Windows::Forms::Button());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->panel1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->BeginInit();
        this->panelBtn1->SuspendLayout();
        this->panelNav->SuspendLayout();
        this->panelBtn4->SuspendLayout();
        this->panelBtn3->SuspendLayout();
        this->panelBtn2->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel1->Controls->Add(this->panel2);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->labelBalance);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(642, 86);
        this->panel1->TabIndex = 0;
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label1->Location = System::Drawing::Point(12, 12);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(53, 21);
        this->label1->TabIndex = 5;
        this->label1->Text = L"Số dư:";
        //
        // pictureBox1
        //
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(250, 12);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(91, 55);
        this->pictureBox1->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::Zoom;
        this->pictureBox1->TabIndex = 4;
        this->pictureBox1->TabStop = false;
        //
        // labelBalance
        //
        this->labelBalance->AutoSize = true;
        this->labelBalance->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->labelBalance->ForeColor = System::Drawing::Color::Lime;
        this->labelBalance->Location = System::Drawing::Point(62, 12);
        this->labelBalance->Name = L"labelBalance";
        this->labelBalance->Size = System::Drawing::Size(93, 21);
        this->labelBalance->TabIndex = 3;
        this->labelBalance->Text = L"123000 VNĐ";
        //
        // labelAccountNumber
        //
        this->labelAccountNumber->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->labelAccountNumber->ForeColor =
            System::Drawing::SystemColors::ButtonFace;
        this->labelAccountNumber->Location = System::Drawing::Point(77, 30);
        this->labelAccountNumber->Name = L"labelAccountNumber";
        this->labelAccountNumber->Size = System::Drawing::Size(167, 37);
        this->labelAccountNumber->TabIndex = 1;
        this->labelAccountNumber->Text = L"1223232323";
        this->labelAccountNumber->TextAlign =
            System::Drawing::ContentAlignment::MiddleRight;
        //
        // labelFullName
        //
        this->labelFullName->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->labelFullName->ForeColor =
            System::Drawing::SystemColors::ButtonFace;
        this->labelFullName->Location = System::Drawing::Point(62, 12);
        this->labelFullName->Name = L"labelFullName";
        this->labelFullName->Size = System::Drawing::Size(182, 18);
        this->labelFullName->TabIndex = 0;
        this->labelFullName->Text = L"LE SI TOAN";
        this->labelFullName->TextAlign =
            System::Drawing::ContentAlignment::MiddleRight;
        //
        // panelBtn1
        //
        this->panelBtn1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelBtn1->BackColor = System::Drawing::Color::Transparent;
        this->panelBtn1->Controls->Add(this->btnSetPin);
        this->panelBtn1->Location = System::Drawing::Point(0, 0);
        this->panelBtn1->Name = L"panelBtn1";
        this->panelBtn1->Size = System::Drawing::Size(134, 43);
        this->panelBtn1->TabIndex = 0;
        //
        // btnSetPin
        //
        this->btnSetPin->BackColor = System::Drawing::Color::Transparent;
        this->btnSetPin->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSetPin->Dock = System::Windows::Forms::DockStyle::Fill;
        this->btnSetPin->FlatAppearance->BorderSize = 0;
        this->btnSetPin->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnSetPin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSetPin->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->btnSetPin->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnSetPin->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnSetPin->Location = System::Drawing::Point(0, 0);
        this->btnSetPin->Name = L"btnSetPin";
        this->btnSetPin->Size = System::Drawing::Size(134, 43);
        this->btnSetPin->TabIndex = 6;
        this->btnSetPin->Text = L"ĐỔI PIN";
        this->btnSetPin->UseVisualStyleBackColor = false;
        this->btnSetPin->Click +=
            gcnew System::EventHandler(this, &AccountForm::btnSetPin_Click);
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::Color::DarkCyan;
        this->panelNav->Controls->Add(this->panelBtn4);
        this->panelNav->Controls->Add(this->panelBtn3);
        this->panelNav->Controls->Add(this->panelBtn2);
        this->panelNav->Controls->Add(this->panelBtn1);
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Top;
        this->panelNav->Location = System::Drawing::Point(0, 86);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(642, 43);
        this->panelNav->TabIndex = 2;
        this->panelNav->SizeChanged += gcnew System::EventHandler(
            this, &AccountForm::panelNav_SizeChanged);
        //
        // panelBtn4
        //
        this->panelBtn4->Controls->Add(this->btnDeleteAccount);
        this->panelBtn4->Location = System::Drawing::Point(470, 0);
        this->panelBtn4->Name = L"panelBtn4";
        this->panelBtn4->Size = System::Drawing::Size(172, 40);
        this->panelBtn4->TabIndex = 3;
        //
        // btnDeleteAccount
        //
        this->btnDeleteAccount->BackColor = System::Drawing::Color::Transparent;
        this->btnDeleteAccount->Cursor = System::Windows::Forms::Cursors::No;
        this->btnDeleteAccount->Dock = System::Windows::Forms::DockStyle::Fill;
        this->btnDeleteAccount->FlatAppearance->BorderSize = 0;
        this->btnDeleteAccount->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnDeleteAccount->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnDeleteAccount->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->btnDeleteAccount->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnDeleteAccount->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnDeleteAccount->Location = System::Drawing::Point(0, 0);
        this->btnDeleteAccount->Name = L"btnDeleteAccount";
        this->btnDeleteAccount->Size = System::Drawing::Size(172, 40);
        this->btnDeleteAccount->TabIndex = 7;
        this->btnDeleteAccount->Text = L"XÓA TÀI KHOẢN";
        this->btnDeleteAccount->UseVisualStyleBackColor = false;
        this->btnDeleteAccount->Click += gcnew System::EventHandler(
            this, &AccountForm::btnDeleteAccount_Click);
        //
        // panelBtn3
        //
        this->panelBtn3->BackColor = System::Drawing::Color::Transparent;
        this->panelBtn3->Controls->Add(this->buttonSetAvatar);
        this->panelBtn3->Location = System::Drawing::Point(298, 0);
        this->panelBtn3->Name = L"panelBtn3";
        this->panelBtn3->Size = System::Drawing::Size(174, 40);
        this->panelBtn3->TabIndex = 2;
        //
        // buttonSetAvatar
        //
        this->buttonSetAvatar->BackColor = System::Drawing::Color::Transparent;
        this->buttonSetAvatar->Cursor = System::Windows::Forms::Cursors::No;
        this->buttonSetAvatar->Dock = System::Windows::Forms::DockStyle::Top;
        this->buttonSetAvatar->FlatAppearance->BorderSize = 0;
        this->buttonSetAvatar->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->buttonSetAvatar->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->buttonSetAvatar->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->buttonSetAvatar->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->buttonSetAvatar->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->buttonSetAvatar->Location = System::Drawing::Point(0, 0);
        this->buttonSetAvatar->Name = L"buttonSetAvatar";
        this->buttonSetAvatar->Size = System::Drawing::Size(174, 40);
        this->buttonSetAvatar->TabIndex = 9;
        this->buttonSetAvatar->Text = L"ĐỔI AVATAR";
        this->buttonSetAvatar->UseVisualStyleBackColor = false;
        this->buttonSetAvatar->Click += gcnew System::EventHandler(
            this, &AccountForm::buttonSetAvatar_Click);
        //
        // panelBtn2
        //
        this->panelBtn2->BackColor = System::Drawing::Color::Transparent;
        this->panelBtn2->Controls->Add(this->btnChangePw);
        this->panelBtn2->Location = System::Drawing::Point(133, 0);
        this->panelBtn2->Name = L"panelBtn2";
        this->panelBtn2->Size = System::Drawing::Size(168, 40);
        this->panelBtn2->TabIndex = 1;
        //
        // btnChangePw
        //
        this->btnChangePw->BackColor = System::Drawing::Color::Transparent;
        this->btnChangePw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnChangePw->Dock = System::Windows::Forms::DockStyle::Fill;
        this->btnChangePw->FlatAppearance->BorderSize = 0;
        this->btnChangePw->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnChangePw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnChangePw->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->btnChangePw->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnChangePw->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnChangePw->Location = System::Drawing::Point(0, 0);
        this->btnChangePw->Name = L"btnChangePw";
        this->btnChangePw->Size = System::Drawing::Size(168, 40);
        this->btnChangePw->TabIndex = 8;
        this->btnChangePw->Text = L"ĐỔI MẬT KHẨU";
        this->btnChangePw->UseVisualStyleBackColor = false;
        this->btnChangePw->Click +=
            gcnew System::EventHandler(this, &AccountForm::btnChangePw_Click);
        //
        // panelContent
        //
        this->panelContent->BackColor = System::Drawing::Color::Teal;
        this->panelContent->BackgroundImage =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"panelContent.BackgroundImage")));
        this->panelContent->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Zoom;
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(0, 129);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(642, 331);
        this->panelContent->TabIndex = 3;
        //
        // panel2
        //
        this->panel2->Controls->Add(this->pictureBox1);
        this->panel2->Controls->Add(this->labelFullName);
        this->panel2->Controls->Add(this->labelAccountNumber);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Right;
        this->panel2->Location = System::Drawing::Point(298, 0);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(344, 86);
        this->panel2->TabIndex = 6;
        //
        // AccountForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(642, 460);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panelNav);
        this->Controls->Add(this->panel1);
        this->MinimumSize = System::Drawing::Size(658, 499);
        this->Name = L"AccountForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"AccountForm";
        this->Load +=
            gcnew System::EventHandler(this, &AccountForm::AccountForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->EndInit();
        this->panelBtn1->ResumeLayout(false);
        this->panelNav->ResumeLayout(false);
        this->panelBtn4->ResumeLayout(false);
        this->panelBtn3->ResumeLayout(false);
        this->panelBtn2->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->ResumeLayout(false);
    }

  private:
    Button ^ selectedButton = nullptr;
    void ChangeButtonColor(Button ^ button) {
        if (selectedButton != nullptr) {
            selectedButton->BackColor = System::Drawing::Color::Teal;
        }
        selectedButton = button;
        selectedButton->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
    }

#pragma endregion
  private:
    System::Void AccountForm_Load(System::Object ^ sender,
                                  System::EventArgs ^ e);

  private:
    System::Void btnChangePw_Click(System::Object ^ sender,
                                   System::EventArgs ^ e);

  private:
    System::Void btnSetPin_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

  private:
    System::Void buttonSetAvatar_Click(System::Object ^ sender,
                                       System::EventArgs ^ e);

  private:
    System::Void btnDeleteAccount_Click(System::Object ^ sender,
                                        System::EventArgs ^ e);

  private:
    System::Void panelNav_SizeChanged(System::Object ^ sender,
                                      System::EventArgs ^ e);
};
} // namespace BankingAppwinform
