#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
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

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::TextBox ^ pin;

  private:


  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::TextBox ^ password;

  private:

    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                SetPinForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->btnShowPw = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->pin = (gcnew System::Windows::Forms::TextBox());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::Transparent;
        this->panel1->Controls->Add(this->panel3);
        this->panel1->Controls->Add(this->panel2);
        this->panel1->Controls->Add(this->btnShowPw);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->labelAuth);
        this->panel1->Controls->Add(this->button1);
        this->panel1->Location = System::Drawing::Point(12, 30);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(602, 236);
        this->panel1->TabIndex = 0;
        //
        // btnShowPw
        //
        this->btnShowPw->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->btnShowPw->BackColor = System::Drawing::Color::White;
        this->btnShowPw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowPw->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowPw->ForeColor = System::Drawing::Color::Black;
        this->btnShowPw->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnShowPw.Image")));
        this->btnShowPw->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnShowPw->Location = System::Drawing::Point(480, 106);
        this->btnShowPw->Name = L"btnShowPw";
        this->btnShowPw->Size = System::Drawing::Size(54, 37);
        this->btnShowPw->TabIndex = 54;
        this->btnShowPw->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->btnShowPw->Click +=
            gcnew System::EventHandler(this, &SetPinForm::btnShowPw_Click);
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(88, 81);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(116, 22);
        this->label1->TabIndex = 46;
        this->label1->Text = L"Nhập mật khẩu:";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(88, 6);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(174, 22);
        this->labelAuth->TabIndex = 44;
        this->labelAuth->Text = L"Nhập mã PIN ( 6 chữ số):";
        //
        // button1
        //
        this->button1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button1->BackColor = System::Drawing::SystemColors::Info;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->BorderSize = 0;
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button1->ForeColor = System::Drawing::Color::Teal;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(92, 174);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(442, 40);
        this->button1->TabIndex = 43;
        this->button1->Text = L"OK";
        this->button1->UseVisualStyleBackColor = false;
        this->button1->Click +=
            gcnew System::EventHandler(this, &SetPinForm::btnSubmit_Click);
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->password);
        this->panel2->Location = System::Drawing::Point(92, 106);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(394, 37);
        this->panel2->TabIndex = 56;
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
        this->password->MaxLength = 15;
        this->password->Multiline = true;
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(373, 28);
        this->password->TabIndex = 29;
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->pin);
        this->panel3->Location = System::Drawing::Point(92, 31);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(442, 37);
        this->panel3->TabIndex = 57;
        //
        // pin
        //
        this->pin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->pin->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->pin->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->pin->Location = System::Drawing::Point(21, 6);
        this->pin->MaxLength = 6;
        this->pin->Multiline = true;
        this->pin->Name = L"pin";
        this->pin->Size = System::Drawing::Size(421, 28);
        this->pin->TabIndex = 29;
        //
        // SetPinForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(626, 292);
        this->Controls->Add(this->panel1);
        this->Name = L"SetPinForm";
        this->Text = L"SetPinForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
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
