﻿#pragma once
#include "AdminForm.h"
#include "TableUsersForm.h"
#include "User.h"
#include "UserServices.h"
#include "Validate.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class EditUserForm : public System::Windows::Forms::Form {
  public:
    EditUserForm(User ^ userSelected);

  protected:
    ~EditUserForm();

  private:
    System::Windows::Forms::Button ^ btnUndo;
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::TextBox ^ name;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::TextBox ^ amount;
    System::Windows::Forms::Panel ^ panel5;
    System::Windows::Forms::TextBox ^ phone;
    System::Windows::Forms::Panel ^ panel6;
    System::Windows::Forms::TextBox ^ accNum;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::TextBox ^ acctype;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::TextBox ^ bankName;
    System::Windows::Forms::Panel ^ panel7;
    System::Windows::Forms::TextBox ^ status;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::Label ^ label4;
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Label ^ label6;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        this->btnUndo = (gcnew System::Windows::Forms::Button());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->name = (gcnew System::Windows::Forms::TextBox());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->amount = (gcnew System::Windows::Forms::TextBox());
        this->panel5 = (gcnew System::Windows::Forms::Panel());
        this->phone = (gcnew System::Windows::Forms::TextBox());
        this->panel6 = (gcnew System::Windows::Forms::Panel());
        this->accNum = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->acctype = (gcnew System::Windows::Forms::TextBox());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->bankName = (gcnew System::Windows::Forms::TextBox());
        this->panel7 = (gcnew System::Windows::Forms::Panel());
        this->status = (gcnew System::Windows::Forms::TextBox());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->panel1->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panel5->SuspendLayout();
        this->panel6->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel7->SuspendLayout();
        this->SuspendLayout();
        //
        // btnUndo
        //
        this->btnUndo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->btnUndo->BackColor = System::Drawing::Color::RoyalBlue;
        this->btnUndo->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnUndo->FlatAppearance->BorderSize = 0;
        this->btnUndo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnUndo->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnUndo->ForeColor = System::Drawing::Color::Bisque;
        this->btnUndo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnUndo->Location = System::Drawing::Point(373, 496);
        this->btnUndo->Margin = System::Windows::Forms::Padding(4);
        this->btnUndo->Name = L"btnUndo";
        this->btnUndo->Size = System::Drawing::Size(283, 59);
        this->btnUndo->TabIndex = 40;
        this->btnUndo->Text = L"QUAY LẠI";
        this->btnUndo->UseVisualStyleBackColor = false;
        this->btnUndo->Click += gcnew System::EventHandler(this, &EditUserForm::btnUndo_Click);
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::Color::Green;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Bisque;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(735, 496);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(283, 59);
        this->btnSubmit->TabIndex = 39;
        this->btnSubmit->Text = L"OK";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(this, &EditUserForm::btnSubmit_Click);
        //
        // name
        //
        this->name->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->name->BackColor = System::Drawing::Color::White;
        this->name->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->name->Cursor = System::Windows::Forms::Cursors::No;
        this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->name->Location = System::Drawing::Point(17, 4);
        this->name->Margin = System::Windows::Forms::Padding(4);
        this->name->MaxLength = 40;
        this->name->Multiline = true;
        this->name->Name = L"name";
        this->name->ReadOnly = true;
        this->name->Size = System::Drawing::Size(331, 35);
        this->name->TabIndex = 29;
        //
        // panel1
        //
        this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel1->Controls->Add(this->name);
        this->panel1->Location = System::Drawing::Point(103, 193);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(354, 45);
        this->panel1->TabIndex = 37;
        //
        // panel4
        //
        this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel4->Controls->Add(this->amount);
        this->panel4->Location = System::Drawing::Point(103, 398);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(1169, 45);
        this->panel4->TabIndex = 43;
        //
        // amount
        //
        this->amount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->amount->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->amount->Location = System::Drawing::Point(17, -1);
        this->amount->Margin = System::Windows::Forms::Padding(4);
        this->amount->MaxLength = 40;
        this->amount->Multiline = true;
        this->amount->Name = L"amount";
        this->amount->Size = System::Drawing::Size(1150, 40);
        this->amount->TabIndex = 29;
        //
        // panel5
        //
        this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel5->BackColor = System::Drawing::Color::White;
        this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel5->Controls->Add(this->phone);
        this->panel5->Location = System::Drawing::Point(512, 193);
        this->panel5->Margin = System::Windows::Forms::Padding(4);
        this->panel5->Name = L"panel5";
        this->panel5->Size = System::Drawing::Size(354, 45);
        this->panel5->TabIndex = 44;
        //
        // phone
        //
        this->phone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->phone->BackColor = System::Drawing::Color::White;
        this->phone->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->phone->Cursor = System::Windows::Forms::Cursors::No;
        this->phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->phone->Location = System::Drawing::Point(17, 4);
        this->phone->Margin = System::Windows::Forms::Padding(4);
        this->phone->MaxLength = 40;
        this->phone->Multiline = true;
        this->phone->Name = L"phone";
        this->phone->ReadOnly = true;
        this->phone->Size = System::Drawing::Size(335, 35);
        this->phone->TabIndex = 29;
        //
        // panel6
        //
        this->panel6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel6->BackColor = System::Drawing::Color::White;
        this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel6->Controls->Add(this->accNum);
        this->panel6->Location = System::Drawing::Point(917, 193);
        this->panel6->Margin = System::Windows::Forms::Padding(4);
        this->panel6->Name = L"panel6";
        this->panel6->Size = System::Drawing::Size(354, 45);
        this->panel6->TabIndex = 45;
        //
        // accNum
        //
        this->accNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->accNum->BackColor = System::Drawing::Color::White;
        this->accNum->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->accNum->Cursor = System::Windows::Forms::Cursors::No;
        this->accNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->accNum->Location = System::Drawing::Point(16, -1);
        this->accNum->Margin = System::Windows::Forms::Padding(4);
        this->accNum->MaxLength = 40;
        this->accNum->Multiline = true;
        this->accNum->Name = L"accNum";
        this->accNum->ReadOnly = true;
        this->accNum->Size = System::Drawing::Size(336, 40);
        this->accNum->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel2->Controls->Add(this->acctype);
        this->panel2->Location = System::Drawing::Point(103, 299);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(354, 45);
        this->panel2->TabIndex = 46;
        //
        // acctype
        //
        this->acctype->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->acctype->BackColor = System::Drawing::Color::White;
        this->acctype->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->acctype->Cursor = System::Windows::Forms::Cursors::No;
        this->acctype->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->acctype->Location = System::Drawing::Point(17, -1);
        this->acctype->Margin = System::Windows::Forms::Padding(4);
        this->acctype->MaxLength = 40;
        this->acctype->Multiline = true;
        this->acctype->Name = L"acctype";
        this->acctype->ReadOnly = true;
        this->acctype->Size = System::Drawing::Size(335, 40);
        this->acctype->TabIndex = 29;
        //
        // panel3
        //
        this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel3->Controls->Add(this->bankName);
        this->panel3->Location = System::Drawing::Point(511, 299);
        this->panel3->Margin = System::Windows::Forms::Padding(4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(354, 45);
        this->panel3->TabIndex = 45;
        //
        // bankName
        //
        this->bankName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->bankName->BackColor = System::Drawing::Color::White;
        this->bankName->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->bankName->Cursor = System::Windows::Forms::Cursors::No;
        this->bankName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->bankName->Location = System::Drawing::Point(18, -1);
        this->bankName->Margin = System::Windows::Forms::Padding(4);
        this->bankName->MaxLength = 40;
        this->bankName->Multiline = true;
        this->bankName->Name = L"bankName";
        this->bankName->ReadOnly = true;
        this->bankName->Size = System::Drawing::Size(334, 40);
        this->bankName->TabIndex = 29;
        //
        // panel7
        //
        this->panel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel7->BackColor = System::Drawing::Color::White;
        this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel7->Controls->Add(this->status);
        this->panel7->Location = System::Drawing::Point(917, 299);
        this->panel7->Margin = System::Windows::Forms::Padding(4);
        this->panel7->Name = L"panel7";
        this->panel7->Size = System::Drawing::Size(354, 45);
        this->panel7->TabIndex = 45;
        //
        // status
        //
        this->status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->status->BackColor = System::Drawing::Color::White;
        this->status->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->status->Cursor = System::Windows::Forms::Cursors::No;
        this->status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->status->Location = System::Drawing::Point(16, -1);
        this->status->Margin = System::Windows::Forms::Padding(4);
        this->status->MaxLength = 40;
        this->status->Multiline = true;
        this->status->Name = L"status";
        this->status->ReadOnly = true;
        this->status->Size = System::Drawing::Size(336, 40);
        this->status->TabIndex = 29;
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->BackColor = System::Drawing::Color::Transparent;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::White;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(97, 162);
        this->labelAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(44, 27);
        this->labelAuth->TabIndex = 47;
        this->labelAuth->Text = L"Tên";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::White;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(507, 162);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(123, 27);
        this->label1->TabIndex = 48;
        this->label1->Text = L"Số điện thoại";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label2->ForeColor = System::Drawing::Color::White;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(912, 162);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(116, 27);
        this->label2->TabIndex = 49;
        this->label2->Text = L"Số tài khoản";
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->BackColor = System::Drawing::Color::Transparent;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label3->ForeColor = System::Drawing::Color::White;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(97, 268);
        this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(130, 27);
        this->label3->TabIndex = 50;
        this->label3->Text = L"Loại tài khoản";
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->BackColor = System::Drawing::Color::Transparent;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label4->ForeColor = System::Drawing::Color::White;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(507, 268);
        this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(138, 27);
        this->label4->TabIndex = 51;
        this->label4->Text = L"Tên ngân hàng";
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->BackColor = System::Drawing::Color::Transparent;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::White;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(912, 268);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(98, 27);
        this->label5->TabIndex = 52;
        this->label5->Text = L"Trạng thái";
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->BackColor = System::Drawing::Color::Transparent;
        this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label6->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label6->ForeColor = System::Drawing::Color::White;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(97, 367);
        this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(135, 27);
        this->label6->TabIndex = 53;
        this->label6->Text = L"Thay đổi số dư";
        //
        // EditUserForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(1436, 875);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->panel7);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel6);
        this->Controls->Add(this->panel5);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->btnUndo);
        this->Controls->Add(this->btnSubmit);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"EditUserForm";
        this->Text = L"EditUserForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->panel5->ResumeLayout(false);
        this->panel5->PerformLayout();
        this->panel6->ResumeLayout(false);
        this->panel6->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel7->ResumeLayout(false);
        this->panel7->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
  private:
    User ^ userSelected;

    System::Void btnUndo_Click(System::Object ^ sender, System::EventArgs ^ e);

    void loadUserInfo();

    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);
};
} // namespace BankingAppwinform
