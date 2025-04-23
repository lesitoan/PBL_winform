#pragma once
#include "GlobalData.h"
#include "SavingCustomers.h"
#include "User.h"
#include "SavingServices.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for RegisterSavingForm
/// </summary>
public
ref class RegisterSavingForm : public System::Windows::Forms::Form {
  public:
    RegisterSavingForm(String ^ type);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~RegisterSavingForm();

  private:
    System::Windows::Forms::Panel ^ panel5;

  protected:
  private:
    System::Windows::Forms::TextBox ^ pinInput;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::ComboBox ^ selectTermBox;

  private:
  private:
    System::Windows::Forms::Button ^ btnClose;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Label ^ labelInfo;

  private:
    System::Windows::Forms::Panel ^ panel6;

  private:
    System::Windows::Forms::TextBox ^ amountInput;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ header;

  private:
    System::Windows::Forms::Label ^ labelBalance;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterSavingForm::typeid));
        this->panel5 = (gcnew System::Windows::Forms::Panel());
        this->pinInput = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectTermBox = (gcnew System::Windows::Forms::ComboBox());
        this->btnClose = (gcnew System::Windows::Forms::Button());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->labelInfo = (gcnew System::Windows::Forms::Label());
        this->panel6 = (gcnew System::Windows::Forms::Panel());
        this->amountInput = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->header = (gcnew System::Windows::Forms::Label());
        this->labelBalance = (gcnew System::Windows::Forms::Label());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel5->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panel6->SuspendLayout();
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // panel5
        //
        this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->panel5->BackColor = System::Drawing::Color::White;
        this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel5->Controls->Add(this->pinInput);
        this->panel5->Location = System::Drawing::Point(503, 258);
        this->panel5->Margin = System::Windows::Forms::Padding(4);
        this->panel5->Name = L"panel5";
        this->panel5->Size = System::Drawing::Size(229, 46);
        this->panel5->TabIndex = 86;
        //
        // pinInput
        //
        this->pinInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->pinInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->pinInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->pinInput->Location = System::Drawing::Point(4, 7);
        this->pinInput->Margin = System::Windows::Forms::Padding(4);
        this->pinInput->MaxLength = 6;
        this->pinInput->Multiline = true;
        this->pinInput->Name = L"pinInput";
        this->pinInput->Size = System::Drawing::Size(219, 32);
        this->pinInput->TabIndex = 29;
        //
        // label3
        //
        this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label3->AutoSize = true;
        this->label3->BackColor = System::Drawing::Color::Transparent;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(447, 268);
        this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(46, 26);
        this->label3->TabIndex = 85;
        this->label3->Text = L"PIN:";
        //
        // label5
        //
        this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->BackColor = System::Drawing::Color::Transparent;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(96, 268);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(115, 26);
        this->label5->TabIndex = 83;
        this->label5->Text = L"Chọn kì hạn:";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel4->Controls->Add(this->selectTermBox);
        this->panel4->Location = System::Drawing::Point(223, 258);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(195, 46);
        this->panel4->TabIndex = 84;
        //
        // selectTermBox
        //
        this->selectTermBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->selectTermBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectTermBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
        this->selectTermBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
        this->selectTermBox->ForeColor = System::Drawing::Color::Black;
        this->selectTermBox->FormattingEnabled = true;
        this->selectTermBox->Items->AddRange(gcnew cli::array<System::Object ^>(4){L"3", L"6", L"9", L"12"});
        this->selectTermBox->Location = System::Drawing::Point(5, 6);
        this->selectTermBox->Margin = System::Windows::Forms::Padding(4);
        this->selectTermBox->Name = L"selectTermBox";
        this->selectTermBox->Size = System::Drawing::Size(185, 33);
        this->selectTermBox->TabIndex = 3;
        //
        // btnClose
        //
        this->btnClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                                                                     static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClose->FlatAppearance->BorderSize = 0;
        this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClose->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClose->ForeColor = System::Drawing::Color::White;
        this->btnClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnClose->Location = System::Drawing::Point(85, 354);
        this->btnClose->Margin = System::Windows::Forms::Padding(4);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(275, 52);
        this->btnClose->TabIndex = 77;
        this->btnClose->Text = L"THOÁT";
        this->btnClose->UseVisualStyleBackColor = false;
        this->btnClose->Click += gcnew System::EventHandler(this, &RegisterSavingForm::btnClose_Click);
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::Color::Green;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::White;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(395, 354);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(285, 52);
        this->btnSubmit->TabIndex = 76;
        this->btnSubmit->Text = L"XÁC NHẬN";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(this, &RegisterSavingForm::btnSubmit_Click);
        //
        // labelInfo
        //
        this->labelInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->labelInfo->BackColor = System::Drawing::Color::White;
        this->labelInfo->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelInfo->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
        this->labelInfo->ForeColor = System::Drawing::Color::Black;
        this->labelInfo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelInfo->Location = System::Drawing::Point(47, 98);
        this->labelInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelInfo->Name = L"labelInfo";
        this->labelInfo->Size = System::Drawing::Size(760, 27);
        this->labelInfo->TabIndex = 82;
        this->labelInfo->Text = L"Gửi tiết kiệm không kì hạn với lãi xuất 4% / năm, bạn có thể rút tiền bất cứ khi "
                                L"nào";
        this->labelInfo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panel6
        //
        this->panel6->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel6->BackColor = System::Drawing::Color::White;
        this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel6->Controls->Add(this->amountInput);
        this->panel6->Location = System::Drawing::Point(223, 169);
        this->panel6->Margin = System::Windows::Forms::Padding(4);
        this->panel6->Name = L"panel6";
        this->panel6->Size = System::Drawing::Size(509, 46);
        this->panel6->TabIndex = 81;
        //
        // amountInput
        //
        this->amountInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->amountInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->amountInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->amountInput->Location = System::Drawing::Point(5, 7);
        this->amountInput->Margin = System::Windows::Forms::Padding(4);
        this->amountInput->MaxLength = 9;
        this->amountInput->Multiline = true;
        this->amountInput->Name = L"amountInput";
        this->amountInput->Size = System::Drawing::Size(497, 32);
        this->amountInput->TabIndex = 29;
        //
        // label2
        //
        this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label2->AutoSize = true;
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(60, 177);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(155, 26);
        this->label2->TabIndex = 80;
        this->label2->Text = L"Nhập số tiền gửi:";
        //
        // header
        //
        this->header->BackColor = System::Drawing::Color::White;
        this->header->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                          static_cast<System::Byte>(0)));
        this->header->ForeColor = System::Drawing::Color::Indigo;
        this->header->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->header->Location = System::Drawing::Point(5, 0);
        this->header->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->header->Name = L"header";
        this->header->Size = System::Drawing::Size(763, 57);
        this->header->TabIndex = 79;
        this->header->Text = L"GỬI TIẾT KIỆM KHÔNG KÌ HẠN";
        this->header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        //
        // labelBalance
        //
        this->labelBalance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->labelBalance->AutoSize = true;
        this->labelBalance->BackColor = System::Drawing::Color::Transparent;
        this->labelBalance->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelBalance->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->labelBalance->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                static_cast<System::Byte>(0)));
        this->labelBalance->ForeColor = System::Drawing::Color::MediumOrchid;
        this->labelBalance->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelBalance->Location = System::Drawing::Point(11, 124);
        this->labelBalance->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelBalance->Name = L"labelBalance";
        this->labelBalance->Size = System::Drawing::Size(342, 27);
        this->labelBalance->TabIndex = 78;
        this->labelBalance->Text = L"Số dư hiện tại của bạn: 80.000.000 vnđ";
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->Controls->Add(this->panel5);
        this->panel1->Controls->Add(this->header);
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->panel4);
        this->panel1->Controls->Add(this->btnClose);
        this->panel1->Controls->Add(this->btnSubmit);
        this->panel1->Controls->Add(this->panel6);
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->labelBalance);
        this->panel1->Location = System::Drawing::Point(40, 36);
        this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(771, 436);
        this->panel1->TabIndex = 87;
        //
        // RegisterSavingForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(848, 511);
        this->Controls->Add(this->labelInfo);
        this->Controls->Add(this->panel1);
        this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
        this->Icon = (cli::safe_cast<System::Drawing::Icon ^>(resources->GetObject(L"$this.Icon")));
        this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
        this->MaximumSize = System::Drawing::Size(866, 558);
        this->MinimumSize = System::Drawing::Size(866, 558);
        this->Name = L"RegisterSavingForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"Register Saving Form";
        this->Load += gcnew System::EventHandler(this, &RegisterSavingForm::RegisterSavingForm_Load);
        this->panel5->ResumeLayout(false);
        this->panel5->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel6->ResumeLayout(false);
        this->panel6->PerformLayout();
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

    public:
    event EventHandler ^ AddSavingSuccess;

  private:
    String ^ type;

  private:
    System::Void btnClose_Click(System::Object ^ sender, System::EventArgs ^ e);

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

  private:
    System::Void RegisterSavingForm_Load(System::Object ^ sender, System::EventArgs ^ e);
};
} // namespace BankingAppwinform
