#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "User.h"
#include "Validate.h"
#include "GradientHelper.h"

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
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ btnShowConfirm;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::TextBox ^ txtConfirm;

  private:

    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                SetPinForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->btnShowConfirm = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->txtConfirm = (gcnew System::Windows::Forms::TextBox());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->pin = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->btnShowPw = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::Transparent;
        this->panel1->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->btnShowConfirm);
        this->panel1->Controls->Add(this->panel4);
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
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->ForeColor = System::Drawing::Color::Transparent;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(117, 188);
        this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(207, 26);
        this->label3->TabIndex = 60;
        this->label3->Text = L"Confirm New Pin Code:";
        //
        // btnShowConfirm
        //
        this->btnShowConfirm->Anchor =
            System::Windows::Forms::AnchorStyles::Right;
        this->btnShowConfirm->BackColor = System::Drawing::Color::White;
        this->btnShowConfirm->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowConfirm->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowConfirm->ForeColor = System::Drawing::Color::Black;
        this->btnShowConfirm->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnShowConfirm.Image")));
        this->btnShowConfirm->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->btnShowConfirm->Location = System::Drawing::Point(640, 218);
        this->btnShowConfirm->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->btnShowConfirm->Name = L"btnShowConfirm";
        this->btnShowConfirm->Size = System::Drawing::Size(72, 46);
        this->btnShowConfirm->TabIndex = 59;
        this->btnShowConfirm->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->btnShowConfirm->Click +=
            gcnew System::EventHandler(this, &SetPinForm::btnShowConfirm_Click);
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->txtConfirm);
        this->panel4->Location = System::Drawing::Point(123, 218);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(525, 46);
        this->panel4->TabIndex = 58;
        //
        // txtConfirm
        //
        this->txtConfirm->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->txtConfirm->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->txtConfirm->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->txtConfirm->Location = System::Drawing::Point(12, 4);
        this->txtConfirm->Margin = System::Windows::Forms::Padding(4);
        this->txtConfirm->MaxLength = 15;
        this->txtConfirm->Multiline = true;
        this->txtConfirm->Name = L"txtConfirm";
        this->txtConfirm->PasswordChar = '*';
        this->txtConfirm->Size = System::Drawing::Size(497, 34);
        this->txtConfirm->TabIndex = 29;
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->pin);
        this->panel3->Location = System::Drawing::Point(122, 42);
        this->panel3->Margin = System::Windows::Forms::Padding(4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(589, 46);
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
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->pin->Location = System::Drawing::Point(13, 8);
        this->pin->Margin = System::Windows::Forms::Padding(4);
        this->pin->MaxLength = 6;
        this->pin->Multiline = true;
        this->pin->Name = L"pin";
        this->pin->Size = System::Drawing::Size(561, 34);
        this->pin->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->password);
        this->panel2->Location = System::Drawing::Point(123, 132);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(525, 46);
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
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
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
        this->btnShowPw->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowPw->ForeColor = System::Drawing::Color::Black;
        this->btnShowPw->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnShowPw.Image")));
        this->btnShowPw->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnShowPw->Location = System::Drawing::Point(640, 132);
        this->btnShowPw->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->btnShowPw->Name = L"btnShowPw";
        this->btnShowPw->Size = System::Drawing::Size(72, 46);
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
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(118, 102);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(135, 26);
        this->label1->TabIndex = 46;
        this->label1->Text = L"New Pin Code:";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(117, 12);
        this->labelAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(124, 26);
        this->labelAuth->TabIndex = 44;
        this->labelAuth->Text = L"Old Pin Code:";
        //
        // button1
        //
        this->button1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button1->BackColor = System::Drawing::Color::Green;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->BorderColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->button1->FlatAppearance->MouseOverBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 16.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button1->ForeColor = System::Drawing::Color::Honeydew;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(123, 292);
        this->button1->Margin = System::Windows::Forms::Padding(4);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(589, 49);
        this->button1->TabIndex = 43;
        this->button1->Text = L"Change Pin Code";
        this->button1->UseVisualStyleBackColor = false;
        this->button1->Click +=
            gcnew System::EventHandler(this, &SetPinForm::btnSubmit_Click);
        //
        // SetPinForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->ClientSize = System::Drawing::Size(835, 452);
        this->Controls->Add(this->panel1);
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"SetPinForm";
        this->Text = L"SetPinForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
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

  private:
    System::Void btnShowConfirm_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);

};
} // namespace BankingAppwinform
