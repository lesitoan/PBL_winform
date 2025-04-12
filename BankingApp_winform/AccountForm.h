#pragma once
#include "ChangePwForm.h"
#include "GlobalData.h"
#include "LoadChildForm.h"
#include "SetPinForm.h"
#include "SetAvatarForm.h"

#include "User.h"
#include "AuthForm.h"


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
    AccountForm(Form ^ parentForm);

  protected:
    ~AccountForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Label ^ labelAccountNumber;
    System::Windows::Forms::Label ^ labelFullName;
    System::Windows::Forms::Label ^ labelBalance;


    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::PictureBox ^ pictureBoxAvatar;

    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Panel ^ panel2;

  public:
    static AxWMPLib::AxWindowsMediaPlayer ^ axWindowsMediaPlayer2;

  private:
    System::Windows::Forms::Panel ^ panelBtn1;

  private:
    System::Windows::Forms::Button ^ btnSetPin;

  private:
    System::Windows::Forms::Panel ^ panelBtn3;

  private:
    System::Windows::Forms::Panel ^ panelBtn4;

  private:
    System::Windows::Forms::Panel ^ panelNav;

  private:
    System::Windows::Forms::Panel ^ panelBtn2;

  private:
    System::Windows::Forms::Button ^ buttonSetAvatar;

  private:
    System::Windows::Forms::Button ^ btnLockAccount;

  private:
    System::Windows::Forms::Button ^ btnChangePw;

  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AccountForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->pictureBoxAvatar = (gcnew System::Windows::Forms::PictureBox());
        this->labelFullName = (gcnew System::Windows::Forms::Label());
        this->labelAccountNumber = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelBalance = (gcnew System::Windows::Forms::Label());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->axWindowsMediaPlayer2 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
        this->panelBtn1 = (gcnew System::Windows::Forms::Panel());
        this->btnSetPin = (gcnew System::Windows::Forms::Button());
        this->panelBtn3 = (gcnew System::Windows::Forms::Panel());
        this->buttonSetAvatar = (gcnew System::Windows::Forms::Button());
        this->panelBtn4 = (gcnew System::Windows::Forms::Panel());
        this->btnLockAccount = (gcnew System::Windows::Forms::Button());
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->panelBtn2 = (gcnew System::Windows::Forms::Panel());
        this->btnChangePw = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBoxAvatar))
            ->BeginInit();
        this->panelContent->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->axWindowsMediaPlayer2))
            ->BeginInit();
        this->panelBtn1->SuspendLayout();
        this->panelBtn3->SuspendLayout();
        this->panelBtn4->SuspendLayout();
        this->panelNav->SuspendLayout();
        this->panelBtn2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::LightPink;
        this->panel1->BackgroundImage =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"panel1.BackgroundImage")));
        this->panel1->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->panel1->Controls->Add(this->panel2);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->labelBalance);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(853, 106);
        this->panel1->TabIndex = 0;
        //
        // panel2
        //
        this->panel2->BackgroundImage =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"panel2.BackgroundImage")));
        this->panel2->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->panel2->Controls->Add(this->pictureBoxAvatar);
        this->panel2->Controls->Add(this->labelFullName);
        this->panel2->Controls->Add(this->labelAccountNumber);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Right;
        this->panel2->Location = System::Drawing::Point(394, 0);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(459, 106);
        this->panel2->TabIndex = 6;
        //
        // pictureBoxAvatar
        //
        this->pictureBoxAvatar->BackColor = System::Drawing::Color::Transparent;
        this->pictureBoxAvatar->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"pictureBoxAvatar.Image")));
        this->pictureBoxAvatar->Location = System::Drawing::Point(356, 15);
        this->pictureBoxAvatar->Margin = System::Windows::Forms::Padding(4);
        this->pictureBoxAvatar->Name = L"pictureBoxAvatar";
        this->pictureBoxAvatar->Size = System::Drawing::Size(70, 68);
        this->pictureBoxAvatar->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->pictureBoxAvatar->TabIndex = 4;
        this->pictureBoxAvatar->TabStop = false;
        //
        // labelFullName
        //
        this->labelFullName->BackColor = System::Drawing::Color::Transparent;
        this->labelFullName->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelFullName->ForeColor =
            System::Drawing::SystemColors::ButtonFace;
        this->labelFullName->Location = System::Drawing::Point(213, 15);
        this->labelFullName->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelFullName->Name = L"labelFullName";
        this->labelFullName->Size = System::Drawing::Size(113, 22);
        this->labelFullName->TabIndex = 0;
        this->labelFullName->Text = L"LE SI TOAN";
        this->labelFullName->TextAlign =
            System::Drawing::ContentAlignment::MiddleRight;
        //
        // labelAccountNumber
        //
        this->labelAccountNumber->BackColor =
            System::Drawing::Color::Transparent;
        this->labelAccountNumber->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelAccountNumber->ForeColor =
            System::Drawing::SystemColors::ButtonFace;
        this->labelAccountNumber->Location = System::Drawing::Point(208, 37);
        this->labelAccountNumber->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAccountNumber->Name = L"labelAccountNumber";
        this->labelAccountNumber->Size = System::Drawing::Size(118, 46);
        this->labelAccountNumber->TabIndex = 1;
        this->labelAccountNumber->Text = L"1223232323";
        this->labelAccountNumber->TextAlign =
            System::Drawing::ContentAlignment::MiddleRight;
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label1->Location = System::Drawing::Point(16, 15);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(85, 26);
        this->label1->TabIndex = 5;
        this->label1->Text = L"Balance:";
        //
        // labelBalance
        //
        this->labelBalance->AutoSize = true;
        this->labelBalance->BackColor = System::Drawing::Color::Transparent;
        this->labelBalance->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelBalance->ForeColor =
            System::Drawing::SystemColors::ButtonHighlight;
        this->labelBalance->Location = System::Drawing::Point(109, 15);
        this->labelBalance->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelBalance->Name = L"labelBalance";
        this->labelBalance->Size = System::Drawing::Size(115, 26);
        this->labelBalance->TabIndex = 3;
        this->labelBalance->Text = L"123000 VNĐ";
        //
        // panelContent
        //
        this->panelContent->BackColor = System::Drawing::Color::White;
        this->panelContent->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->panelContent->Controls->Add(this->axWindowsMediaPlayer2);
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(0, 159);
        this->panelContent->Margin = System::Windows::Forms::Padding(4);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(853, 407);
        this->panelContent->TabIndex = 3;
        //
        // axWindowsMediaPlayer2
        //
        this->axWindowsMediaPlayer2->Enabled = true;
        this->axWindowsMediaPlayer2->Location = System::Drawing::Point(-226, 0);
        this->axWindowsMediaPlayer2->Name = L"axWindowsMediaPlayer2";
        this->axWindowsMediaPlayer2->OcxState =
            (cli::safe_cast<System::Windows::Forms::AxHost::State ^>(
                resources->GetObject(L"axWindowsMediaPlayer2.OcxState")));
        this->axWindowsMediaPlayer2->Size = System::Drawing::Size(1082, 418);
        this->axWindowsMediaPlayer2->TabIndex = 0;
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
        this->panelBtn1->Margin = System::Windows::Forms::Padding(4);
        this->panelBtn1->Name = L"panelBtn1";
        this->panelBtn1->Size = System::Drawing::Size(176, 53);
        this->panelBtn1->TabIndex = 0;
        //
        // btnSetPin
        //
        this->btnSetPin->BackColor = System::Drawing::Color::SeaShell;
        this->btnSetPin->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->btnSetPin->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSetPin->Dock = System::Windows::Forms::DockStyle::Fill;
        this->btnSetPin->FlatAppearance->BorderSize = 0;
        this->btnSetPin->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnSetPin->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSetPin->ForeColor = System::Drawing::Color::Purple;
        this->btnSetPin->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnSetPin->Location = System::Drawing::Point(0, 0);
        this->btnSetPin->Margin = System::Windows::Forms::Padding(4);
        this->btnSetPin->Name = L"btnSetPin";
        this->btnSetPin->Size = System::Drawing::Size(176, 53);
        this->btnSetPin->TabIndex = 6;
        this->btnSetPin->Text = L"Change Pin Code";
        this->btnSetPin->UseVisualStyleBackColor = false;
        this->btnSetPin->Click +=
            gcnew System::EventHandler(this, &AccountForm::btnSetPin_Click);
        //
        // panelBtn3
        //
        this->panelBtn3->BackColor = System::Drawing::Color::Transparent;
        this->panelBtn3->Controls->Add(this->buttonSetAvatar);
        this->panelBtn3->Location = System::Drawing::Point(397, 0);
        this->panelBtn3->Margin = System::Windows::Forms::Padding(4);
        this->panelBtn3->Name = L"panelBtn3";
        this->panelBtn3->Size = System::Drawing::Size(232, 53);
        this->panelBtn3->TabIndex = 2;
        //
        // buttonSetAvatar
        //
        this->buttonSetAvatar->BackColor = System::Drawing::Color::SeaShell;
        this->buttonSetAvatar->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->buttonSetAvatar->Cursor = System::Windows::Forms::Cursors::Hand;
        this->buttonSetAvatar->Dock = System::Windows::Forms::DockStyle::Top;
        this->buttonSetAvatar->FlatAppearance->BorderSize = 0;
        this->buttonSetAvatar->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->buttonSetAvatar->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->buttonSetAvatar->ForeColor = System::Drawing::Color::Purple;
        this->buttonSetAvatar->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->buttonSetAvatar->Location = System::Drawing::Point(0, 0);
        this->buttonSetAvatar->Margin = System::Windows::Forms::Padding(4);
        this->buttonSetAvatar->Name = L"buttonSetAvatar";
        this->buttonSetAvatar->Size = System::Drawing::Size(232, 53);
        this->buttonSetAvatar->TabIndex = 10;
        this->buttonSetAvatar->Text = L"Change Avatar";
        this->buttonSetAvatar->UseVisualStyleBackColor = false;
        this->buttonSetAvatar->Click += gcnew System::EventHandler(
            this, &AccountForm::buttonSetAvatar_Click);
        //
        // panelBtn4
        //
        this->panelBtn4->Controls->Add(this->btnLockAccount);
        this->panelBtn4->Location = System::Drawing::Point(627, 0);
        this->panelBtn4->Margin = System::Windows::Forms::Padding(4);
        this->panelBtn4->Name = L"panelBtn4";
        this->panelBtn4->Size = System::Drawing::Size(238, 53);
        this->panelBtn4->TabIndex = 3;
        //
        // btnLockAccount
        //
        this->btnLockAccount->AutoSize = true;
        this->btnLockAccount->BackColor = System::Drawing::Color::SeaShell;
        this->btnLockAccount->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->btnLockAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLockAccount->Dock = System::Windows::Forms::DockStyle::Fill;
        this->btnLockAccount->FlatAppearance->BorderSize = 0;
        this->btnLockAccount->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnLockAccount->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnLockAccount->ForeColor = System::Drawing::Color::Purple;
        this->btnLockAccount->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLockAccount->Location = System::Drawing::Point(0, 0);
        this->btnLockAccount->Margin = System::Windows::Forms::Padding(4);
        this->btnLockAccount->Name = L"btnLockAccount";
        this->btnLockAccount->Size = System::Drawing::Size(238, 53);
        this->btnLockAccount->TabIndex = 9;
        this->btnLockAccount->Text = L"Block Account";
        this->btnLockAccount->UseVisualStyleBackColor = false;
        this->btnLockAccount->Click += gcnew System::EventHandler(
            this, &AccountForm::btnLockAccount_Click);
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::Color::DarkCyan;
        this->panelNav->Controls->Add(this->panelBtn4);
        this->panelNav->Controls->Add(this->panelBtn3);
        this->panelNav->Controls->Add(this->panelBtn2);
        this->panelNav->Controls->Add(this->panelBtn1);
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Top;
        this->panelNav->Location = System::Drawing::Point(0, 106);
        this->panelNav->Margin = System::Windows::Forms::Padding(4);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(853, 53);
        this->panelNav->TabIndex = 2;
        this->panelNav->SizeChanged += gcnew System::EventHandler(
            this, &AccountForm::panelNav_SizeChanged);
        //
        // panelBtn2
        //
        this->panelBtn2->BackColor = System::Drawing::Color::Transparent;
        this->panelBtn2->BackgroundImage =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"panelBtn2.BackgroundImage")));
        this->panelBtn2->Controls->Add(this->btnChangePw);
        this->panelBtn2->Location = System::Drawing::Point(177, 0);
        this->panelBtn2->Margin = System::Windows::Forms::Padding(4);
        this->panelBtn2->Name = L"panelBtn2";
        this->panelBtn2->Size = System::Drawing::Size(224, 53);
        this->panelBtn2->TabIndex = 1;
        //
        // btnChangePw
        //
        this->btnChangePw->BackColor = System::Drawing::Color::SeaShell;
        this->btnChangePw->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->btnChangePw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnChangePw->FlatAppearance->BorderSize = 0;
        this->btnChangePw->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnChangePw->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnChangePw->ForeColor = System::Drawing::Color::Purple;
        this->btnChangePw->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnChangePw->Location = System::Drawing::Point(-3, 0);
        this->btnChangePw->Margin = System::Windows::Forms::Padding(4);
        this->btnChangePw->Name = L"btnChangePw";
        this->btnChangePw->Size = System::Drawing::Size(224, 53);
        this->btnChangePw->TabIndex = 10;
        this->btnChangePw->Text = L"Change Password";
        this->btnChangePw->UseVisualStyleBackColor = false;
        this->btnChangePw->Click +=
            gcnew System::EventHandler(this, &AccountForm::btnChangePw_Click);
        //
        // AccountForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(853, 566);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panelNav);
        this->Controls->Add(this->panel1);
        this->Margin = System::Windows::Forms::Padding(4);
        this->MinimumSize = System::Drawing::Size(871, 603);
        this->Name = L"AccountForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"AccountForm";
        this->Load +=
            gcnew System::EventHandler(this, &AccountForm::AccountForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBoxAvatar))
            ->EndInit();
        this->panelContent->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->axWindowsMediaPlayer2))
            ->EndInit();
        this->panelBtn1->ResumeLayout(false);
        this->panelBtn3->ResumeLayout(false);
        this->panelBtn4->ResumeLayout(false);
        this->panelBtn4->PerformLayout();
        this->panelNav->ResumeLayout(false);
        this->panelBtn2->ResumeLayout(false);
        this->ResumeLayout(false);
    }

  //private:
  //  Button ^ selectedButton = nullptr;
  //  void ChangeButtonColor(Button ^ button) {
  //      if (selectedButton != nullptr) {
  //          selectedButton->BackColor = System::Drawing::Color::HotPink;
  //      }
  //      /*selectedButton = button;
  //      selectedButton->BackColor = System::Drawing::Color::FromArgb(
  //          static_cast<System::Int32>(static_cast<System::Byte>(0)),
  //          static_cast<System::Int32>(static_cast<System::Byte>(64)),
  //          static_cast<System::Int32>(static_cast<System::Byte>(64)));*/
  //  }

#pragma endregion
  private:
    Form ^ parentForm;

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
    System::Void panelNav_SizeChanged(System::Object ^ sender,
                                      System::EventArgs ^ e);

    void loadAvatar();

  private:
    System::Void btnLockAccount_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);

};
} // namespace BankingAppwinform
