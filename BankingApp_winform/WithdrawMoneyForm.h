﻿#pragma once
#include "GlobalData.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for WithdrawMoneyForm
/// </summary>
public
ref class WithdrawMoneyForm : public System::Windows::Forms::Form {
  public:
    WithdrawMoneyForm(void);

  protected:
    ~WithdrawMoneyForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Label ^ label4;
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Button ^ button1;
    System::Windows::Forms::Label ^ labelBalance;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::TextBox ^ textBox1;
    System::Windows::Forms::Panel ^ panel6;
    System::Windows::Forms::TextBox ^ amountInput;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->panel6 = (gcnew System::Windows::Forms::Panel());
        this->amountInput = (gcnew System::Windows::Forms::TextBox());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->labelBalance = (gcnew System::Windows::Forms::Label());
        this->panel1->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel6->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::Teal;
        this->panel1->Controls->Add(this->panel3);
        this->panel1->Controls->Add(this->panel6);
        this->panel1->Controls->Add(this->label4);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->button1);
        this->panel1->Location = System::Drawing::Point(0, 91);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(880, 526);
        this->panel1->TabIndex = 0;
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->textBox1);
        this->panel3->Location = System::Drawing::Point(123, 241);
        this->panel3->Margin = System::Windows::Forms::Padding(4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(635, 46);
        this->panel3->TabIndex = 62;
        //
        // textBox1
        //
        this->textBox1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->textBox1->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->textBox1->Location = System::Drawing::Point(28, 7);
        this->textBox1->Margin = System::Windows::Forms::Padding(4);
        this->textBox1->MaxLength = 6;
        this->textBox1->Multiline = true;
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(607, 34);
        this->textBox1->TabIndex = 29;
        //
        // panel6
        //
        this->panel6->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel6->BackColor = System::Drawing::Color::White;
        this->panel6->Controls->Add(this->amountInput);
        this->panel6->Location = System::Drawing::Point(123, 140);
        this->panel6->Margin = System::Windows::Forms::Padding(4);
        this->panel6->Name = L"panel6";
        this->panel6->Size = System::Drawing::Size(635, 46);
        this->panel6->TabIndex = 61;
        //
        // amountInput
        //
        this->amountInput->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->amountInput->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->amountInput->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->amountInput->Location = System::Drawing::Point(28, 7);
        this->amountInput->Margin = System::Windows::Forms::Padding(4);
        this->amountInput->MaxLength = 9;
        this->amountInput->Multiline = true;
        this->amountInput->Name = L"amountInput";
        this->amountInput->Size = System::Drawing::Size(607, 34);
        this->amountInput->TabIndex = 29;
        //
        // label4
        //
        this->label4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label4->AutoSize = true;
        this->label4->BackColor = System::Drawing::Color::Transparent;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label4->ForeColor = System::Drawing::Color::White;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(117, 210);
        this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(141, 26);
        this->label4->TabIndex = 57;
        this->label4->Text = L"Enter Pin Code:";
        //
        // label5
        //
        this->label5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->BackColor = System::Drawing::Color::Transparent;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::Color::White;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(119, 110);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(137, 26);
        this->label5->TabIndex = 55;
        this->label5->Text = L"Enter Amount:";
        //
        // button1
        //
        this->button1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button1->BackColor = System::Drawing::Color::Transparent;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::White;
        this->button1->FlatAppearance->MouseOverBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->button1->ForeColor = System::Drawing::Color::White;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(123, 334);
        this->button1->Margin = System::Windows::Forms::Padding(4);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(635, 52);
        this->button1->TabIndex = 53;
        this->button1->Text = L"Withdraw Money";
        this->button1->UseVisualStyleBackColor = false;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::Teal;
        this->panel2->Controls->Add(this->labelBalance);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel2->Location = System::Drawing::Point(0, 0);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(877, 84);
        this->panel2->TabIndex = 1;
        //
        // labelBalance
        //
        this->labelBalance->BackColor = System::Drawing::Color::Transparent;
        this->labelBalance->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelBalance->Dock = System::Windows::Forms::DockStyle::Fill;
        this->labelBalance->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->labelBalance->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13.8F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelBalance->ForeColor = System::Drawing::Color::Sienna;
        this->labelBalance->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->labelBalance->Location = System::Drawing::Point(0, 0);
        this->labelBalance->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelBalance->Name = L"labelBalance";
        this->labelBalance->Size = System::Drawing::Size(877, 84);
        this->labelBalance->TabIndex = 58;
        this->labelBalance->Text = L"Số dư hiện tại: 123000 VNĐ";
        this->labelBalance->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // WithdrawMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(877, 614);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"WithdrawMoneyForm";
        this->Text = L"WithdrawMoneyForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel6->ResumeLayout(false);
        this->panel6->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion
};
} // namespace BankingAppwinform
