#pragma once
#include "HandleFile.h"
#include "LoginForm.h"
#include "User.h"
#include "Validate.h"
#include "Utils.h"
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

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

    System::Windows::Forms::Label ^ label6;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Label ^ label7;
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::Label ^ label9;

    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::TextBox ^ fullName;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::TextBox ^ phoneNumber;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::TextBox ^ password;
    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::TextBox ^ passwordConfirm;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Label ^ label2;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                SignupForm::typeid));
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->fullName = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->passwordConfirm = (gcnew System::Windows::Forms::TextBox());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->BackColor = System::Drawing::Color::Transparent;
        this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label6->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label6->ForeColor = System::Drawing::Color::Transparent;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(75, 250);
        this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(96, 27);
        this->label6->TabIndex = 40;
        this->label6->Text = L"Password";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->BackColor = System::Drawing::Color::Transparent;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(375, 144);
        this->labelAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(178, 27);
        this->labelAuth->TabIndex = 39;
        this->labelAuth->Text = L"Telephone Number";
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->BackColor = System::Drawing::Color::Transparent;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 24, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label7->ForeColor = System::Drawing::Color::White;
        this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label7->Location = System::Drawing::Point(197, 81);
        this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(366, 50);
        this->label7->TabIndex = 38;
        this->label7->Text = L"Create Your Account";
        this->label7->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::Color::Transparent;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 16.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSubmit->ForeColor = System::Drawing::Color::White;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(73, 461);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(592, 52);
        this->btnSubmit->TabIndex = 35;
        this->btnSubmit->Text = L"Sign Up";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &SignupForm::btnSubmit_Click);
        //
        // label9
        //
        this->label9->AutoSize = true;
        this->label9->BackColor = System::Drawing::Color::Transparent;
        this->label9->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label9->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label9->ForeColor = System::Drawing::Color::Transparent;
        this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label9->Location = System::Drawing::Point(75, 144);
        this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(63, 27);
        this->label9->TabIndex = 43;
        this->label9->Text = L"Name";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(75, 356);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(168, 27);
        this->label1->TabIndex = 45;
        this->label1->Text = L"Confirm Password";
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->Controls->Add(this->fullName);
        this->panel1->Location = System::Drawing::Point(76, 175);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(283, 46);
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
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->fullName->Location = System::Drawing::Point(24, 7);
        this->fullName->Margin = System::Windows::Forms::Padding(4);
        this->fullName->MaxLength = 35;
        this->fullName->Multiline = true;
        this->fullName->Name = L"fullName";
        this->fullName->Size = System::Drawing::Size(255, 34);
        this->fullName->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->phoneNumber);
        this->panel2->Location = System::Drawing::Point(380, 175);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(285, 46);
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
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->phoneNumber->Location = System::Drawing::Point(24, 7);
        this->phoneNumber->Margin = System::Windows::Forms::Padding(4);
        this->phoneNumber->MaxLength = 10;
        this->phoneNumber->Multiline = true;
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(261, 34);
        this->phoneNumber->TabIndex = 29;
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->label2);
        this->panel3->Controls->Add(this->password);
        this->panel3->Location = System::Drawing::Point(76, 281);
        this->panel3->Margin = System::Windows::Forms::Padding(4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(589, 46);
        this->panel3->TabIndex = 49;
        //
        // label2
        //
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label2.Image")));
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(520, 7);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(66, 34);
        this->label2->TabIndex = 52;
        this->label2->Text = L"            ";
        this->label2->Click +=
            gcnew System::EventHandler(this, &SignupForm::label2_Click);
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
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->password->Location = System::Drawing::Point(24, 7);
        this->password->Margin = System::Windows::Forms::Padding(4);
        this->password->MaxLength = 9;
        this->password->Multiline = true;
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(561, 34);
        this->password->TabIndex = 29;
        //
        // panel4
        //
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->label4);
        this->panel4->Controls->Add(this->passwordConfirm);
        this->panel4->Location = System::Drawing::Point(76, 386);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(592, 46);
        this->panel4->TabIndex = 50;
        //
        // label4
        //
        this->label4->BackColor = System::Drawing::Color::Transparent;
        this->label4->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label4.Image")));
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(522, 7);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(66, 34);
        this->label4->TabIndex = 51;
        this->label4->Text = L"            ";
        this->label4->Click +=
            gcnew System::EventHandler(this, &SignupForm::label4_Click);
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
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->passwordConfirm->Location = System::Drawing::Point(24, 7);
        this->passwordConfirm->Margin = System::Windows::Forms::Padding(4);
        this->passwordConfirm->MaxLength = 9;
        this->passwordConfirm->Multiline = true;
        this->passwordConfirm->Name = L"passwordConfirm";
        this->passwordConfirm->PasswordChar = '*';
        this->passwordConfirm->Size = System::Drawing::Size(564, 34);
        this->passwordConfirm->TabIndex = 29;
        //
        // SignupForm
        //
        this->AcceptButton = this->btnSubmit;
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::HotPink;
        this->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->ClientSize = System::Drawing::Size(729, 601);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->label9);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->btnSubmit);
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"SignupForm";
        this->Text = L"SignupForm";
        this->Load +=
            gcnew System::EventHandler(this, &SignupForm::SignupForm_Load);
        this->Paint += gcnew System::Windows::Forms::PaintEventHandler(
            this, &SignupForm::SignupForm_Paint);
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

    System::Void SignupForm_Paint(System::Object ^ sender,
                                    System::Windows::Forms::PaintEventArgs ^
                                        e) {
        Graphics ^ g = e->Graphics;
        Rectangle rect = this->ClientRectangle;

        // Gradient từ hồng đậm sang hồng nhạt
        LinearGradientBrush ^ pinkGradient = gcnew LinearGradientBrush(
            rect, Color::FromArgb(138, 43, 226),
            Color::FromArgb(255, 105, 180),     // 💖 Hot Pink
            LinearGradientMode::ForwardDiagonal // Hướng chéo
        );

        g->FillRectangle(pinkGradient, rect);
    }

  public:
    event EventHandler ^ SignupSuccess;

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    System::Void SignupForm_Load(System::Object ^ sender,
                                 System::EventArgs ^ e) {}

    bool isUsedPhoneNumber(String ^ phoneNumber);
    int randomAccountNumber();

  private:
    System::Void label4_Click(System::Object ^ sender, System::EventArgs ^ e);


  private:
    System::Void label2_Click(System::Object ^ sender, System::EventArgs ^ e);


};
} // namespace BankingAppwinform
