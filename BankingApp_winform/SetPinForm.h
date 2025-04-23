#pragma once
#include "GlobalData.h"
#include "User.h"
#include "GradientHelper.h"

#include "UserServices.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class SetPinForm : public System::Windows::Forms::Form {
  public:
    SetPinForm(void);

  protected:
    ~SetPinForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Button ^ button1;
    System::Windows::Forms::Label ^ btnShowPw;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::TextBox ^ pin;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::TextBox ^ password;

  private:


  private:


  private:


  private:


  private:

    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SetPinForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->pin = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->btnShowPw = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::Transparent;
        this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->panel1->Controls->Add(this->panel3);
        this->panel1->Controls->Add(this->panel2);
        this->panel1->Controls->Add(this->btnShowPw);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->labelAuth);
        this->panel1->Controls->Add(this->button1);
        this->panel1->Location = System::Drawing::Point(16, 43);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(803, 370);
        this->panel1->TabIndex = 0;
        //
        // panel3
        //
        this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->pin);
        this->panel3->Location = System::Drawing::Point(123, 74);
        this->panel3->Margin = System::Windows::Forms::Padding(4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(589, 46);
        this->panel3->TabIndex = 57;
        //
        // pin
        //
        this->pin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->pin->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->pin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->pin->Location = System::Drawing::Point(13, 7);
        this->pin->Margin = System::Windows::Forms::Padding(4);
        this->pin->MaxLength = 6;
        this->pin->Multiline = true;
        this->pin->Name = L"pin";
        this->pin->Size = System::Drawing::Size(561, 34);
        this->pin->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->password);
        this->panel2->Location = System::Drawing::Point(123, 164);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(525, 46);
        this->panel2->TabIndex = 56;
        //
        // password
        //
        this->password->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->password->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->password->Location = System::Drawing::Point(12, 4);
        this->password->Margin = System::Windows::Forms::Padding(4);
        this->password->MaxLength = 15;
        this->password->Multiline = true;
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(497, 34);
        this->password->TabIndex = 29;
        //
        // btnShowPw
        //
        this->btnShowPw->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->btnShowPw->BackColor = System::Drawing::Color::White;
        this->btnShowPw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowPw->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowPw->ForeColor = System::Drawing::Color::Black;
        this->btnShowPw->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"btnShowPw.Image")));
        this->btnShowPw->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnShowPw->Location = System::Drawing::Point(640, 164);
        this->btnShowPw->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->btnShowPw->Name = L"btnShowPw";
        this->btnShowPw->Size = System::Drawing::Size(72, 46);
        this->btnShowPw->TabIndex = 54;
        this->btnShowPw->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        this->btnShowPw->Click += gcnew System::EventHandler(this, &SetPinForm::btnShowPw_Click);
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(117, 134);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(98, 26);
        this->label1->TabIndex = 46;
        this->label1->Text = L"Mật Khẩu:";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(117, 44);
        this->labelAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(112, 26);
        this->labelAuth->TabIndex = 44;
        this->labelAuth->Text = L"Mã Pin Mới:";
        //
        // button1
        //
        this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->button1->BackColor = System::Drawing::Color::Indigo;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                      static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                             static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
        this->button1->ForeColor = System::Drawing::Color::Honeydew;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(123, 255);
        this->button1->Margin = System::Windows::Forms::Padding(4);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(589, 49);
        this->button1->TabIndex = 43;
        this->button1->Text = L"Đổi Mã Pin";
        this->button1->UseVisualStyleBackColor = false;
        this->button1->Click += gcnew System::EventHandler(this, &SetPinForm::btnSubmit_Click);
        //
        // SetPinForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->ClientSize = System::Drawing::Size(835, 452);
        this->Controls->Add(this->panel1);
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"SetPinForm";
        this->Text = L"SetPinForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->ResumeLayout(false);
    }

#pragma endregion

  private:
    bool isShowPw = false;

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

  private:
    System::Void btnShowPw_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

};
} // namespace BankingAppwinform
