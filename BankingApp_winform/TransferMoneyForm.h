#pragma once
#include "Validate.h"
#include "HandleFile.h"
#include "GlobalData.h"
#include "User.h"
#include "Transaction.h"

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
    System::Windows::Forms::TextBox ^ accountNumber;
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Panel ^ panelTransfer;
    System::Windows::Forms::Label ^ labelReceiver;
    System::Windows::Forms::Label ^ label4;
    System::Windows::Forms::TextBox ^ contentInput;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::TextBox ^ pinInput;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::TextBox ^ amountInput;
    System::Windows::Forms::Button ^ btnSubmit;



#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->btnFindAccount = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->accountNumber = (gcnew System::Windows::Forms::TextBox());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->selectBankBox = (gcnew System::Windows::Forms::ComboBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->panelTransfer = (gcnew System::Windows::Forms::Panel());
        this->labelReceiver = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->contentInput = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->pinInput = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->amountInput = (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panelTransfer->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::Teal;
        this->panel1->Controls->Add(this->btnFindAccount);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->accountNumber);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->selectBankBox);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(658, 167);
        this->panel1->TabIndex = 0;
        //
        // btnFindAccount
        //
        this->btnFindAccount->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnFindAccount->BackColor = System::Drawing::SystemColors::Info;
        this->btnFindAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnFindAccount->FlatAppearance->BorderSize = 0;
        this->btnFindAccount->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnFindAccount->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnFindAccount->ForeColor = System::Drawing::Color::Teal;
        this->btnFindAccount->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->btnFindAccount->Location = System::Drawing::Point(92, 90);
        this->btnFindAccount->Name = L"btnFindAccount";
        this->btnFindAccount->Size = System::Drawing::Size(476, 38);
        this->btnFindAccount->TabIndex = 52;
        this->btnFindAccount->Text = L"CHUYỂN TIỀN";
        this->btnFindAccount->UseVisualStyleBackColor = false;
        this->btnFindAccount->Click += gcnew System::EventHandler(
            this, &TransferMoneyForm::btnFindAccount_Click);
        //
        // label1
        //
        this->label1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(293, 20);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(135, 22);
        this->label1->TabIndex = 53;
        this->label1->Text = L"Nhập số tài khoản:";
        //
        // accountNumber
        //
        this->accountNumber->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->accountNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->accountNumber->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->accountNumber->Location = System::Drawing::Point(297, 45);
        this->accountNumber->MaxLength = 9;
        this->accountNumber->Multiline = true;
        this->accountNumber->Name = L"accountNumber";
        this->accountNumber->Size = System::Drawing::Size(271, 27);
        this->accountNumber->TabIndex = 52;
        //
        // label5
        //
        this->label5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(88, 20);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(99, 22);
        this->label5->TabIndex = 51;
        this->label5->Text = L"Nhập số tiền:";
        //
        // selectBankBox
        //
        this->selectBankBox->Anchor =
            System::Windows::Forms::AnchorStyles::Left;
        this->selectBankBox->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->selectBankBox->ForeColor = System::Drawing::Color::Black;
        this->selectBankBox->FormattingEnabled = true;
        this->selectBankBox->Items->AddRange(gcnew cli::array<System::Object ^>(
            8){L"BIDV", L"Vietcombank", L"MB", L"VP Bank", L"Viettinbank",
               L"Sacombank", L"SHB", L"TP Bank"});
        this->selectBankBox->Location = System::Drawing::Point(92, 45);
        this->selectBankBox->Name = L"selectBankBox";
        this->selectBankBox->Size = System::Drawing::Size(180, 27);
        this->selectBankBox->TabIndex = 3;
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::Teal;
        this->panel2->Controls->Add(this->panelTransfer);
        this->panel2->Location = System::Drawing::Point(0, 173);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(658, 328);
        this->panel2->TabIndex = 1;
        //
        // panelTransfer
        //
        this->panelTransfer->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelTransfer->BackColor = System::Drawing::Color::Transparent;
        this->panelTransfer->Controls->Add(this->labelReceiver);
        this->panelTransfer->Controls->Add(this->label4);
        this->panelTransfer->Controls->Add(this->contentInput);
        this->panelTransfer->Controls->Add(this->label3);
        this->panelTransfer->Controls->Add(this->pinInput);
        this->panelTransfer->Controls->Add(this->label2);
        this->panelTransfer->Controls->Add(this->amountInput);
        this->panelTransfer->Controls->Add(this->btnSubmit);
        this->panelTransfer->Location = System::Drawing::Point(0, 1);
        this->panelTransfer->Name = L"panelTransfer";
        this->panelTransfer->Size = System::Drawing::Size(658, 326);
        this->panelTransfer->TabIndex = 15;
        this->panelTransfer->Visible = false;
        //
        // labelReceiver
        //
        this->labelReceiver->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->labelReceiver->AutoSize = true;
        this->labelReceiver->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelReceiver->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->labelReceiver->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 15.75F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelReceiver->ForeColor = System::Drawing::Color::SpringGreen;
        this->labelReceiver->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->labelReceiver->Location = System::Drawing::Point(87, 20);
        this->labelReceiver->Name = L"labelReceiver";
        this->labelReceiver->Size = System::Drawing::Size(219, 28);
        this->labelReceiver->TabIndex = 52;
        this->labelReceiver->Text = L"Người nhận: LE SI TOAN";
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
        this->label4->Location = System::Drawing::Point(88, 137);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(114, 22);
        this->label4->TabIndex = 51;
        this->label4->Text = L"Nhập nội dung:";
        //
        // contentInput
        //
        this->contentInput->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->contentInput->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->contentInput->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->contentInput->Location = System::Drawing::Point(92, 162);
        this->contentInput->MaxLength = 35;
        this->contentInput->Multiline = true;
        this->contentInput->Name = L"contentInput";
        this->contentInput->Size = System::Drawing::Size(476, 43);
        this->contentInput->TabIndex = 50;
        //
        // label3
        //
        this->label3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label3->AutoSize = true;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label3->ForeColor = System::Drawing::Color::Transparent;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(374, 63);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(100, 22);
        this->label3->TabIndex = 49;
        this->label3->Text = L"Nhập mã PIN:";
        //
        // pinInput
        //
        this->pinInput->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->pinInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->pinInput->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->pinInput->Location = System::Drawing::Point(378, 88);
        this->pinInput->MaxLength = 6;
        this->pinInput->Multiline = true;
        this->pinInput->Name = L"pinInput";
        this->pinInput->Size = System::Drawing::Size(190, 37);
        this->pinInput->TabIndex = 48;
        //
        // label2
        //
        this->label2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label2->AutoSize = true;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label2->ForeColor = System::Drawing::Color::Transparent;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(88, 63);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(99, 22);
        this->label2->TabIndex = 47;
        this->label2->Text = L"Nhập số tiền:";
        //
        // amountInput
        //
        this->amountInput->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->amountInput->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->amountInput->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->amountInput->Location = System::Drawing::Point(92, 88);
        this->amountInput->MaxLength = 8;
        this->amountInput->Multiline = true;
        this->amountInput->Name = L"amountInput";
        this->amountInput->Size = System::Drawing::Size(260, 37);
        this->amountInput->TabIndex = 46;
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
        this->btnSubmit->Location = System::Drawing::Point(92, 237);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(476, 42);
        this->btnSubmit->TabIndex = 45;
        this->btnSubmit->Text = L"CHUYỂN TIỀN";
        this->btnSubmit->UseVisualStyleBackColor = false;
        //
        // TransferMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::White;
        this->ClientSize = System::Drawing::Size(658, 499);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"TransferMoneyForm";
        this->Text = L"TransferMoneyForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panelTransfer->ResumeLayout(false);
        this->panelTransfer->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    User ^ receiver = nullptr;
    int receiverIndex = -1;

    private:
    System::Void btnFindAccount_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);

  private: // so tien ck toi thieu 10k, toi da 2.000.000 ?
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

};
}
