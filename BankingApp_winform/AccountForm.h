#pragma once
#include "GlobalData.h"
#include "User.h"
#include "ChangePwForm.h"
#include "LoadChildForm.h"
#include "SetPinForm.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class AccountForm : public System::Windows::Forms::Form {
  public:
    AccountForm(void) {
        InitializeComponent();
    }

  protected:
    ~AccountForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panelContent;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::Button ^ btnChangePw;
    System::Windows::Forms::Label ^ labelAccountNumber;
    System::Windows::Forms::Label ^ labelFullName;

  private:
    System::Windows::Forms::Button ^ btnSetPin;

    System::Windows::Forms::Button ^ btnDeleteAccount;
    System::Windows::Forms::Panel ^ panelAvatar;

  private:
    System::Windows::Forms::Label ^ labelBalance;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AccountForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->labelBalance = (gcnew System::Windows::Forms::Label());
        this->panelAvatar = (gcnew System::Windows::Forms::Panel());
        this->labelAccountNumber = (gcnew System::Windows::Forms::Label());
        this->labelFullName = (gcnew System::Windows::Forms::Label());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->btnSetPin = (gcnew System::Windows::Forms::Button());
        this->btnDeleteAccount = (gcnew System::Windows::Forms::Button());
        this->btnChangePw = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel3->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->labelBalance);
        this->panel1->Controls->Add(this->panelAvatar);
        this->panel1->Controls->Add(this->labelAccountNumber);
        this->panel1->Controls->Add(this->labelFullName);
        this->panel1->Location = System::Drawing::Point(23, 24);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(533, 82);
        this->panel1->TabIndex = 0;
        //
        // labelBalance
        //
        this->labelBalance->AutoSize = true;
        this->labelBalance->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold));
        this->labelBalance->Location = System::Drawing::Point(189, 10);
        this->labelBalance->Name = L"labelBalance";
        this->labelBalance->Size = System::Drawing::Size(65, 24);
        this->labelBalance->TabIndex = 3;
        this->labelBalance->Text = L"So du: ";
        //
        // panelAvatar
        //
        this->panelAvatar->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelAvatar->BackgroundImage =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"panelAvatar.BackgroundImage")));
        this->panelAvatar->Location = System::Drawing::Point(432, 10);
        this->panelAvatar->Name = L"panelAvatar";
        this->panelAvatar->Size = System::Drawing::Size(89, 55);
        this->panelAvatar->TabIndex = 2;
        //
        // labelAccountNumber
        //
        this->labelAccountNumber->AutoSize = true;
        this->labelAccountNumber->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->labelAccountNumber->Location = System::Drawing::Point(21, 44);
        this->labelAccountNumber->Name = L"labelAccountNumber";
        this->labelAccountNumber->Size = System::Drawing::Size(0, 21);
        this->labelAccountNumber->TabIndex = 1;
        //
        // labelFullName
        //
        this->labelFullName->AutoSize = true;
        this->labelFullName->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelFullName->Location = System::Drawing::Point(21, 10);
        this->labelFullName->Name = L"labelFullName";
        this->labelFullName->Size = System::Drawing::Size(0, 24);
        this->labelFullName->TabIndex = 0;
        //
        // panelContent
        //
        this->panelContent->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->panelContent->Location = System::Drawing::Point(195, 125);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(361, 286);
        this->panelContent->TabIndex = 1;
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel3->Controls->Add(this->btnSetPin);
        this->panel3->Controls->Add(this->btnDeleteAccount);
        this->panel3->Controls->Add(this->btnChangePw);
        this->panel3->Location = System::Drawing::Point(23, 125);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(154, 286);
        this->panel3->TabIndex = 2;
        //
        // btnSetPin
        //
        this->btnSetPin->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnSetPin->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSetPin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSetPin->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSetPin->ForeColor = System::Drawing::Color::Black;
        this->btnSetPin->Location = System::Drawing::Point(16, 63);
        this->btnSetPin->Name = L"btnSetPin";
        this->btnSetPin->Size = System::Drawing::Size(120, 29);
        this->btnSetPin->TabIndex = 5;
        this->btnSetPin->Text = L"Doi PIN";
        this->btnSetPin->UseVisualStyleBackColor = false;
        this->btnSetPin->Click +=
            gcnew System::EventHandler(this, &AccountForm::btnSetPin_Click);
        //
        // btnDeleteAccount
        //
        this->btnDeleteAccount->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnDeleteAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnDeleteAccount->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnDeleteAccount->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnDeleteAccount->ForeColor = System::Drawing::Color::Black;
        this->btnDeleteAccount->Location = System::Drawing::Point(16, 108);
        this->btnDeleteAccount->Name = L"btnDeleteAccount";
        this->btnDeleteAccount->Size = System::Drawing::Size(120, 29);
        this->btnDeleteAccount->TabIndex = 4;
        this->btnDeleteAccount->Text = L"Xoa tai khoan";
        this->btnDeleteAccount->UseVisualStyleBackColor = false;
        //
        // btnChangePw
        //
        this->btnChangePw->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnChangePw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnChangePw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnChangePw->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnChangePw->ForeColor = System::Drawing::Color::Black;
        this->btnChangePw->Location = System::Drawing::Point(16, 18);
        this->btnChangePw->Name = L"btnChangePw";
        this->btnChangePw->Size = System::Drawing::Size(120, 29);
        this->btnChangePw->TabIndex = 3;
        this->btnChangePw->Text = L"Doi mat khau";
        this->btnChangePw->UseVisualStyleBackColor = false;
        this->btnChangePw->Click +=
            gcnew System::EventHandler(this, &AccountForm::btnChangePw_Click);
        //
        // AccountForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(568, 423);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panel1);
        this->Name = L"AccountForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"AccountForm";
        this->Load +=
            gcnew System::EventHandler(this, &AccountForm::AccountForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->ResumeLayout(false);
    }

#pragma endregion
  private:
    System::Void AccountForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
        if (!GlobalData::GetCurrentUser()->getPin()) {
            this->btnSetPin->Text = "Tao PIN";
        }
        this->labelFullName->Text += GlobalData::GetCurrentUser()->getFullName();
        this->labelAccountNumber->Text +=
            GlobalData::GetCurrentUser()->getAccountNumber();
        this->labelBalance->Text +=
            GlobalData::GetCurrentUser()->getBalance() + " VND";
    }

  private:
    System::Void btnChangePw_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew ChangePwForm());
    }

  private:
    System::Void btnSetPin_Click(System::Object ^ sender,
                                    System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew SetPinForm());
    }
  };
  }
