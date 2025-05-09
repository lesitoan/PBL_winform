﻿#pragma once
#include "GlobalData.h"
#include "SelectReceiverForm.h"
#include "User.h"

#include "UserServices.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class TransferMoneyForm : public System::Windows::Forms::Form {
  public:
    TransferMoneyForm(void);

  protected:
    ~TransferMoneyForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::ComboBox ^ selectBankBox;
    System::ComponentModel::Container ^ components;
    System::Windows::Forms::Button ^ btnFindAccount;
    System::Windows::Forms::Label ^ label1;

    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Panel ^ panelTransfer;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::TextBox ^ accountNumber;

  private:
    System::Windows::Forms::Label ^ btnSelectAccHistory;

  private:
  private:
    System::Windows::Forms::Panel ^ panel7;

  private:
    System::Windows::Forms::TextBox ^ message;

  private:
  private:
    System::Windows::Forms::Panel ^ panel6;

  private:
    System::Windows::Forms::TextBox ^ amountInput;

  private:
    System::Windows::Forms::Panel ^ panel5;

  private:
    System::Windows::Forms::TextBox ^ pinInput;

  private:
    System::Windows::Forms::Label ^ labelReceiver;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
  private:
  private:
  private:
  private:
  private:
#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->btnSelectAccHistory = (gcnew System::Windows::Forms::Label());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->accountNumber = (gcnew System::Windows::Forms::TextBox());
        this->btnFindAccount = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectBankBox = (gcnew System::Windows::Forms::ComboBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->panelTransfer = (gcnew System::Windows::Forms::Panel());
        this->panel7 = (gcnew System::Windows::Forms::Panel());
        this->message = (gcnew System::Windows::Forms::TextBox());
        this->panel6 = (gcnew System::Windows::Forms::Panel());
        this->amountInput = (gcnew System::Windows::Forms::TextBox());
        this->panel5 = (gcnew System::Windows::Forms::Panel());
        this->pinInput = (gcnew System::Windows::Forms::TextBox());
        this->labelReceiver = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panelTransfer->SuspendLayout();
        this->panel7->SuspendLayout();
        this->panel6->SuspendLayout();
        this->panel5->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->btnSelectAccHistory);
        this->panel1->Controls->Add(this->panel3);
        this->panel1->Controls->Add(this->btnFindAccount);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->panel4);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(877, 226);
        this->panel1->TabIndex = 0;
        //
        // btnSelectAccHistory
        //
        this->btnSelectAccHistory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->btnSelectAccHistory->AutoSize = true;
        this->btnSelectAccHistory->BackColor = System::Drawing::Color::Transparent;
        this->btnSelectAccHistory->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSelectAccHistory->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                       static_cast<System::Byte>(0)));
        this->btnSelectAccHistory->ForeColor = System::Drawing::Color::Transparent;
        this->btnSelectAccHistory->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSelectAccHistory->Location = System::Drawing::Point(125, 176);
        this->btnSelectAccHistory->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->btnSelectAccHistory->Name = L"btnSelectAccHistory";
        this->btnSelectAccHistory->Size = System::Drawing::Size(226, 26);
        this->btnSelectAccHistory->TabIndex = 60;
        this->btnSelectAccHistory->Text = L"Chọn Từ Lịch Sử Giao Dịch";
        this->btnSelectAccHistory->Click += gcnew System::EventHandler(this, &TransferMoneyForm::btnSelectAccHistory_Click);
        //
        // panel3
        //
        this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->accountNumber);
        this->panel3->Location = System::Drawing::Point(392, 42);
        this->panel3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(369, 46);
        this->panel3->TabIndex = 58;
        //
        // accountNumber
        //
        this->accountNumber->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->accountNumber->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->accountNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->accountNumber->Location = System::Drawing::Point(28, 7);
        this->accountNumber->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->accountNumber->MaxLength = 20;
        this->accountNumber->Multiline = true;
        this->accountNumber->Name = L"accountNumber";
        this->accountNumber->Size = System::Drawing::Size(341, 34);
        this->accountNumber->TabIndex = 29;
        this->accountNumber->TextChanged += gcnew System::EventHandler(this, &TransferMoneyForm::accountNumber_TextChanged);
        //
        // btnFindAccount
        //
        this->btnFindAccount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->btnFindAccount->BackColor = System::Drawing::Color::Indigo;
        this->btnFindAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnFindAccount->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                             static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnFindAccount->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                  static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnFindAccount->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
        this->btnFindAccount->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnFindAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnFindAccount->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                  static_cast<System::Byte>(0)));
        this->btnFindAccount->ForeColor = System::Drawing::Color::White;
        this->btnFindAccount->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnFindAccount->Location = System::Drawing::Point(127, 111);
        this->btnFindAccount->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnFindAccount->Name = L"btnFindAccount";
        this->btnFindAccount->Size = System::Drawing::Size(635, 47);
        this->btnFindAccount->TabIndex = 52;
        this->btnFindAccount->Text = L"Tiếp Tục";
        this->btnFindAccount->UseVisualStyleBackColor = false;
        this->btnFindAccount->Click += gcnew System::EventHandler(this, &TransferMoneyForm::btnFindAccount_Click);
        //
        // label1
        //
        this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label1->AutoSize = true;
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(395, 11);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(125, 26);
        this->label1->TabIndex = 53;
        this->label1->Text = L"Số Tài Khoản:";
        //
        // label5
        //
        this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->BackColor = System::Drawing::Color::Transparent;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(121, 11);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(110, 26);
        this->label5->TabIndex = 51;
        this->label5->Text = L"Ngân Hàng:";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->selectBankBox);
        this->panel4->Location = System::Drawing::Point(127, 42);
        this->panel4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(248, 46);
        this->panel4->TabIndex = 59;
        //
        // selectBankBox
        //
        this->selectBankBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->selectBankBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectBankBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
        this->selectBankBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
        this->selectBankBox->ForeColor = System::Drawing::Color::Black;
        this->selectBankBox->FormattingEnabled = true;
        this->selectBankBox->Location = System::Drawing::Point(4, 7);
        this->selectBankBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->selectBankBox->Name = L"selectBankBox";
        this->selectBankBox->Size = System::Drawing::Size(239, 33);
        this->selectBankBox->TabIndex = 3;
        this->selectBankBox->TextChanged += gcnew System::EventHandler(this, &TransferMoneyForm::selectBankBox_TextChanged);
        //
        // panel2
        //
        this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel2->Controls->Add(this->panelTransfer);
        this->panel2->Location = System::Drawing::Point(0, 234);
        this->panel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(877, 383);
        this->panel2->TabIndex = 1;
        //
        // panelTransfer
        //
        this->panelTransfer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->panelTransfer->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panelTransfer->Controls->Add(this->panel7);
        this->panelTransfer->Controls->Add(this->panel6);
        this->panelTransfer->Controls->Add(this->panel5);
        this->panelTransfer->Controls->Add(this->labelReceiver);
        this->panelTransfer->Controls->Add(this->label4);
        this->panelTransfer->Controls->Add(this->label3);
        this->panelTransfer->Controls->Add(this->label2);
        this->panelTransfer->Controls->Add(this->btnSubmit);
        this->panelTransfer->Location = System::Drawing::Point(0, 4);
        this->panelTransfer->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panelTransfer->Name = L"panelTransfer";
        this->panelTransfer->Size = System::Drawing::Size(877, 378);
        this->panelTransfer->TabIndex = 15;
        this->panelTransfer->Visible = false;
        //
        // panel7
        //
        this->panel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->panel7->BackColor = System::Drawing::Color::White;
        this->panel7->Controls->Add(this->message);
        this->panel7->Location = System::Drawing::Point(127, 191);
        this->panel7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel7->Name = L"panel7";
        this->panel7->Size = System::Drawing::Size(635, 46);
        this->panel7->TabIndex = 69;
        //
        // message
        //
        this->message->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->message->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->message->Location = System::Drawing::Point(28, 7);
        this->message->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->message->MaxLength = 50;
        this->message->Multiline = true;
        this->message->Name = L"message";
        this->message->Size = System::Drawing::Size(607, 34);
        this->message->TabIndex = 29;
        //
        // panel6
        //
        this->panel6->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel6->BackColor = System::Drawing::Color::White;
        this->panel6->Controls->Add(this->amountInput);
        this->panel6->Location = System::Drawing::Point(127, 100);
        this->panel6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel6->Name = L"panel6";
        this->panel6->Size = System::Drawing::Size(363, 46);
        this->panel6->TabIndex = 68;
        //
        // amountInput
        //
        this->amountInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->amountInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->amountInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->amountInput->Location = System::Drawing::Point(28, 7);
        this->amountInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->amountInput->MaxLength = 9;
        this->amountInput->Multiline = true;
        this->amountInput->Name = L"amountInput";
        this->amountInput->Size = System::Drawing::Size(335, 34);
        this->amountInput->TabIndex = 29;
        //
        // panel5
        //
        this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->panel5->BackColor = System::Drawing::Color::White;
        this->panel5->Controls->Add(this->pinInput);
        this->panel5->Location = System::Drawing::Point(501, 100);
        this->panel5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel5->Name = L"panel5";
        this->panel5->Size = System::Drawing::Size(260, 46);
        this->panel5->TabIndex = 67;
        //
        // pinInput
        //
        this->pinInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->pinInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->pinInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->pinInput->Location = System::Drawing::Point(28, 7);
        this->pinInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->pinInput->MaxLength = 6;
        this->pinInput->Multiline = true;
        this->pinInput->Name = L"pinInput";
        this->pinInput->Size = System::Drawing::Size(232, 34);
        this->pinInput->TabIndex = 29;
        //
        // labelReceiver
        //
        this->labelReceiver->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->labelReceiver->AutoSize = true;
        this->labelReceiver->BackColor = System::Drawing::Color::Transparent;
        this->labelReceiver->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelReceiver->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->labelReceiver->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
        this->labelReceiver->ForeColor = System::Drawing::Color::HotPink;
        this->labelReceiver->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelReceiver->Location = System::Drawing::Point(120, 16);
        this->labelReceiver->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelReceiver->Name = L"labelReceiver";
        this->labelReceiver->Size = System::Drawing::Size(241, 30);
        this->labelReceiver->TabIndex = 66;
        this->labelReceiver->Text = L"Người Nhận: LE SI TOAN";
        //
        // label4
        //
        this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label4->AutoSize = true;
        this->label4->BackColor = System::Drawing::Color::Transparent;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label4->ForeColor = System::Drawing::Color::Transparent;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(121, 160);
        this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(222, 26);
        this->label4->TabIndex = 65;
        this->label4->Text = L"Nội Dung Chuyển Khoản:";
        //
        // label3
        //
        this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label3->AutoSize = true;
        this->label3->BackColor = System::Drawing::Color::Transparent;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label3->ForeColor = System::Drawing::Color::Transparent;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(503, 69);
        this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(75, 26);
        this->label3->TabIndex = 64;
        this->label3->Text = L"Mã Pin:";
        //
        // label2
        //
        this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label2->AutoSize = true;
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label2->ForeColor = System::Drawing::Color::Transparent;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(121, 69);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(103, 26);
        this->label2->TabIndex = 63;
        this->label2->Text = L"Nhập Tiền:";
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::Color::Indigo;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                        static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnSubmit->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                             static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnSubmit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
        this->btnSubmit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                               static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
        this->btnSubmit->ForeColor = System::Drawing::Color::White;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(127, 283);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(635, 52);
        this->btnSubmit->TabIndex = 62;
        this->btnSubmit->Text = L"Chuyển Tiền";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(this, &TransferMoneyForm::btnSubmit_Click);
        //
        // TransferMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::White;
        this->ClientSize = System::Drawing::Size(877, 614);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->Name = L"TransferMoneyForm";
        this->Text = L"TransferMoneyForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->panelTransfer->ResumeLayout(false);
        this->panelTransfer->PerformLayout();
        this->panel7->ResumeLayout(false);
        this->panel7->PerformLayout();
        this->panel6->ResumeLayout(false);
        this->panel6->PerformLayout();
        this->panel5->ResumeLayout(false);
        this->panel5->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    User ^ receiver = nullptr;
    int receiverIndex = -1;

  public:
    void setReceiver(User ^ receiver) { this->receiver = receiver; }

  private:
    System::Void btnFindAccount_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);

    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    System::Void onSelectReceiverSuccess(System::Object ^ sender,
                                         SelectReceiverEventArgs ^ e);

    System::Void btnSelectAccHistory_Click(System::Object ^ sender,
                                           System::EventArgs ^ e);

    System::Void accountNumber_TextChanged(System::Object ^ sender,
                                           System::EventArgs ^ e);

    System::Void selectBankBox_TextChanged(System::Object ^ sender,
                                           System::EventArgs ^ e);

    void loadBank();
};
} // namespace BankingAppwinform
