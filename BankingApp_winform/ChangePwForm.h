﻿#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "User.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class ChangePwForm : public System::Windows::Forms::Form {
  public:
    ChangePwForm(void);

  protected:
    ~ChangePwForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Label ^ label6;


    System::Windows::Forms::Label ^ label5;

    System::Windows::Forms::Label ^ label4;

    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Label ^ label1;
    System::ComponentModel::Container ^ components;

  private:
    bool showOldPw = false;
    bool showNewPw = false;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::TextBox ^ oldPassword;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::TextBox ^ newPasswordConfirm;

  private:


  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::TextBox ^ newPassword;

  private:

    bool showNewPwConfirm = false;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                ChangePwForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->newPasswordConfirm = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->newPassword = (gcnew System::Windows::Forms::TextBox());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->oldPassword = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel4->SuspendLayout();
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
        this->panel1->Controls->Add(this->panel4);
        this->panel1->Controls->Add(this->panel2);
        this->panel1->Controls->Add(this->panel3);
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->label6);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->label4);
        this->panel1->Controls->Add(this->btnSubmit);
        this->panel1->Location = System::Drawing::Point(16, 16);
        this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(803, 441);
        this->panel1->TabIndex = 0;
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->newPasswordConfirm);
        this->panel4->Location = System::Drawing::Point(123, 254);
        this->panel4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(531, 46);
        this->panel4->TabIndex = 56;
        //
        // newPasswordConfirm
        //
        this->newPasswordConfirm->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->newPasswordConfirm->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->newPasswordConfirm->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->newPasswordConfirm->Location = System::Drawing::Point(24, 7);
        this->newPasswordConfirm->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->newPasswordConfirm->MaxLength = 15;
        this->newPasswordConfirm->Multiline = true;
        this->newPasswordConfirm->Name = L"newPasswordConfirm";
        this->newPasswordConfirm->PasswordChar = '*';
        this->newPasswordConfirm->Size = System::Drawing::Size(503, 34);
        this->newPasswordConfirm->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->newPassword);
        this->panel2->Location = System::Drawing::Point(123, 146);
        this->panel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(531, 46);
        this->panel2->TabIndex = 55;
        //
        // newPassword
        //
        this->newPassword->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->newPassword->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->newPassword->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->newPassword->Location = System::Drawing::Point(24, 7);
        this->newPassword->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->newPassword->MaxLength = 9;
        this->newPassword->Multiline = true;
        this->newPassword->Name = L"newPassword";
        this->newPassword->PasswordChar = '*';
        this->newPassword->Size = System::Drawing::Size(503, 34);
        this->newPassword->TabIndex = 29;
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->oldPassword);
        this->panel3->Location = System::Drawing::Point(123, 46);
        this->panel3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(531, 46);
        this->panel3->TabIndex = 54;
        //
        // oldPassword
        //
        this->oldPassword->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->oldPassword->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->oldPassword->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->oldPassword->Location = System::Drawing::Point(24, 7);
        this->oldPassword->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->oldPassword->MaxLength = 15;
        this->oldPassword->Multiline = true;
        this->oldPassword->Name = L"oldPassword";
        this->oldPassword->PasswordChar = '*';
        this->oldPassword->Size = System::Drawing::Size(503, 34);
        this->oldPassword->TabIndex = 29;
        //
        // label3
        //
        this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->label3->BackColor = System::Drawing::Color::White;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label3->ForeColor = System::Drawing::Color::Black;
        this->label3->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label3.Image")));
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(640, 254);
        this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(72, 46);
        this->label3->TabIndex = 53;
        this->label3->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->label3->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::label3_Click);
        //
        // label2
        //
        this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->label2->BackColor = System::Drawing::Color::White;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label2->ForeColor = System::Drawing::Color::Black;
        this->label2->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label2.Image")));
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(640, 146);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(72, 46);
        this->label2->TabIndex = 52;
        this->label2->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->label2->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::label2_Click);
        //
        // label1
        //
        this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->label1->BackColor = System::Drawing::Color::White;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Black;
        this->label1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label1.Image")));
        this->label1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(640, 46);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(72, 46);
        this->label1->TabIndex = 51;
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->label1->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::label1_Click);
        //
        // label6
        //
        this->label6->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label6->AutoSize = true;
        this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label6->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label6->ForeColor = System::Drawing::Color::Transparent;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(117, 223);
        this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(216, 27);
        this->label6->TabIndex = 50;
        this->label6->Text = L"Xác nhận mật khẩu mới:";
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(117, 116);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(313, 27);
        this->label5->TabIndex = 47;
        this->label5->Text = L"Nhập mật khẩu mới (ít nhất 6 kí tự):";
        //
        // label4
        //
        this->label4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label4->AutoSize = true;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label4->ForeColor = System::Drawing::Color::Transparent;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(117, 15);
        this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(147, 27);
        this->label4->TabIndex = 44;
        this->label4->Text = L"Nhập mật khẩu:";
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(123, 345);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(593, 52);
        this->btnSubmit->TabIndex = 42;
        this->btnSubmit->Text = L"THAY ĐỔI";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::btnSubmit_Click);
        //
        // ChangePwForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(835, 471);
        this->Controls->Add(this->panel1);
        this->ForeColor = System::Drawing::SystemColors::ControlLight;
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->Name = L"ChangePwForm";
        this->Text = L"ChangePwForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    bool handleClickShowBtn(bool status,
                            System::Windows::Forms::TextBox ^ textbox);

    System::Void label1_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void label2_Click(System::Object ^ sender, System::EventArgs ^ e);

    System::Void label3_Click(System::Object ^ sender, System::EventArgs ^ e);

};
} // namespace BankingAppwinform
