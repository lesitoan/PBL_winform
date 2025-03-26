#pragma once
#include "HandleFile.h"
#include "LoginForm.h"
#include "User.h"
#include "Validate.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class SignupForm : public System::Windows::Forms::Form {
  public:
    SignupForm(void);

  protected:
    ~SignupForm();

  private:
    System::Windows::Forms::CheckBox ^ btnShowPw;
    System::Windows::Forms::Label ^ label6;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Label ^ label7;
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::Label ^ label9;
    System::Windows::Forms::CheckBox ^ btnShowPwCf;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::TextBox ^ fullName;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::TextBox ^ phoneNumber;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::TextBox ^ password;
    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::TextBox ^ passwordConfirm;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->btnShowPw = (gcnew System::Windows::Forms::CheckBox());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->btnShowPwCf = (gcnew System::Windows::Forms::CheckBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->fullName = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->passwordConfirm = (gcnew System::Windows::Forms::TextBox());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // btnShowPw
        //
        this->btnShowPw->BackColor = System::Drawing::Color::MintCream;
        this->btnShowPw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowPw->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowPw->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->btnShowPw->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnShowPw->Location = System::Drawing::Point(406, 228);
        this->btnShowPw->Name = L"btnShowPw";
        this->btnShowPw->Padding = System::Windows::Forms::Padding(5, 6, 5, 5);
        this->btnShowPw->Size = System::Drawing::Size(93, 37);
        this->btnShowPw->TabIndex = 41;
        this->btnShowPw->Text = L"Show";
        this->btnShowPw->UseVisualStyleBackColor = false;
        this->btnShowPw->CheckedChanged += gcnew System::EventHandler(
            this, &SignupForm::btnShowPw_CheckedChanged);
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label6->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label6->ForeColor = System::Drawing::Color::Transparent;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(56, 203);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(187, 22);
        this->label6->TabIndex = 40;
        this->label6->Text = L"Nhập mật khẩu (6-9 kí tự):";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(281, 117);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(141, 22);
        this->labelAuth->TabIndex = 39;
        this->labelAuth->Text = L"Nhập số điện thoại:";
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 22, System::Drawing::FontStyle::Bold));
        this->label7->ForeColor = System::Drawing::Color::White;
        this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label7->Location = System::Drawing::Point(141, 49);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(270, 40);
        this->label7->TabIndex = 38;
        this->label7->Text = L"ĐĂNG KÍ TÀI KHOẢN";
        this->label7->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(57, 391);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(442, 42);
        this->btnSubmit->TabIndex = 35;
        this->btnSubmit->Text = L"ĐĂNG KÍ TÀI KHOẢN";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &SignupForm::btnSubmit_Click);
        //
        // label9
        //
        this->label9->AutoSize = true;
        this->label9->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label9->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label9->ForeColor = System::Drawing::Color::Transparent;
        this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label9->Location = System::Drawing::Point(56, 117);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(213, 22);
        this->label9->TabIndex = 43;
        this->label9->Text = L"Nhập tên (không dấu, in hoa):";
        //
        // btnShowPwCf
        //
        this->btnShowPwCf->BackColor = System::Drawing::Color::MintCream;
        this->btnShowPwCf->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowPwCf->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowPwCf->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->btnShowPwCf->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnShowPwCf->Location = System::Drawing::Point(406, 314);
        this->btnShowPwCf->Name = L"btnShowPwCf";
        this->btnShowPwCf->Padding =
            System::Windows::Forms::Padding(5, 6, 5, 5);
        this->btnShowPwCf->Size = System::Drawing::Size(93, 37);
        this->btnShowPwCf->TabIndex = 46;
        this->btnShowPwCf->Text = L"Show";
        this->btnShowPwCf->UseVisualStyleBackColor = false;
        this->btnShowPwCf->CheckedChanged += gcnew System::EventHandler(
            this, &SignupForm::btnShowPwCf_CheckedChanged);
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(56, 289);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(142, 22);
        this->label1->TabIndex = 45;
        this->label1->Text = L"Xác nhận mật khẩu:";
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->Controls->Add(this->fullName);
        this->panel1->Location = System::Drawing::Point(57, 142);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(212, 37);
        this->panel1->TabIndex = 47;
        //
        // fullName
        //
        this->fullName->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->fullName->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->fullName->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->fullName->Location = System::Drawing::Point(18, 6);
        this->fullName->MaxLength = 35;
        this->fullName->Multiline = true;
        this->fullName->Name = L"fullName";
        this->fullName->Size = System::Drawing::Size(191, 28);
        this->fullName->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->phoneNumber);
        this->panel2->Location = System::Drawing::Point(285, 142);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(214, 37);
        this->panel2->TabIndex = 48;
        //
        // phoneNumber
        //
        this->phoneNumber->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->phoneNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->phoneNumber->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->phoneNumber->Location = System::Drawing::Point(18, 6);
        this->phoneNumber->MaxLength = 10;
        this->phoneNumber->Multiline = true;
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(196, 28);
        this->phoneNumber->TabIndex = 29;
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->password);
        this->panel3->Location = System::Drawing::Point(57, 228);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(354, 37);
        this->panel3->TabIndex = 49;
        //
        // password
        //
        this->password->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->password->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->password->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->password->Location = System::Drawing::Point(18, 6);
        this->password->MaxLength = 9;
        this->password->Multiline = true;
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(333, 28);
        this->password->TabIndex = 29;
        //
        // panel4
        //
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->passwordConfirm);
        this->panel4->Location = System::Drawing::Point(57, 314);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(351, 37);
        this->panel4->TabIndex = 50;
        //
        // passwordConfirm
        //
        this->passwordConfirm->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->passwordConfirm->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->passwordConfirm->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->passwordConfirm->Location = System::Drawing::Point(18, 6);
        this->passwordConfirm->MaxLength = 9;
        this->passwordConfirm->Multiline = true;
        this->passwordConfirm->Name = L"passwordConfirm";
        this->passwordConfirm->PasswordChar = '*';
        this->passwordConfirm->Size = System::Drawing::Size(330, 28);
        this->passwordConfirm->TabIndex = 29;
        //
        // SignupForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(547, 488);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->btnShowPwCf);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->label9);
        this->Controls->Add(this->btnShowPw);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->btnSubmit);
        this->Name = L"SignupForm";
        this->Text = L"SignupForm";
        this->Load +=
            gcnew System::EventHandler(this, &SignupForm::SignupForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion

  public:
    event EventHandler ^ SignupSuccess;

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    System::Void btnShowPwCf_CheckedChanged(System::Object ^ sender,
                                            System::EventArgs ^ e);

    System::Void btnShowPw_CheckedChanged(System::Object ^ sender,
                                          System::EventArgs ^ e);

    System::Void SignupForm_Load(System::Object ^ sender,
                                 System::EventArgs ^ e) {}

    bool isUsedPhoneNumber(String ^ phoneNumber);
    int randomAccountNumber();
};
} // namespace BankingAppwinform
