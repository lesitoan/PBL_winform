#pragma once

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for TransferMoneyForm
/// </summary>
public
ref class TransferMoneyForm : public System::Windows::Forms::Form {
  public:
    TransferMoneyForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~TransferMoneyForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::ComboBox ^ selectBankBox;

  private:
  private:
    System::Windows::Forms::Label ^ labelAccountNumber;

  private:
    System::Windows::Forms::TextBox ^ textBox1;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  protected:
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
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->labelAccountNumber = (gcnew System::Windows::Forms::Label());
        this->selectBankBox = (gcnew System::Windows::Forms::ComboBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->btnSubmit);
        this->panel1->Controls->Add(this->textBox1);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->selectBankBox);
        this->panel1->Controls->Add(this->labelAccountNumber);
        this->panel1->Location = System::Drawing::Point(28, 24);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(515, 346);
        this->panel1->TabIndex = 0;
        //
        // labelAccountNumber
        //
        this->labelAccountNumber->AutoSize = true;
        this->labelAccountNumber->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->labelAccountNumber->Location = System::Drawing::Point(88, 74);
        this->labelAccountNumber->Name = L"labelAccountNumber";
        this->labelAccountNumber->Size = System::Drawing::Size(131, 21);
        this->labelAccountNumber->TabIndex = 2;
        this->labelAccountNumber->Text = L"Chon ngan hang:";
        //
        // selectBankBox
        //
        this->selectBankBox->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->selectBankBox->FormattingEnabled = true;
        this->selectBankBox->Items->AddRange(gcnew cli::array<System::Object ^>(
            8){L"BIDV", L"Vietcombank", L"MB", L"VP Bank", L"Viettinbank",
               L"Sacombank", L"SHB", L"TP Bank"});
        this->selectBankBox->Location = System::Drawing::Point(92, 108);
        this->selectBankBox->Name = L"selectBankBox";
        this->selectBankBox->Size = System::Drawing::Size(343, 29);
        this->selectBankBox->TabIndex = 3;
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(88, 163);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(104, 21);
        this->label1->TabIndex = 4;
        this->label1->Text = L"So tai khoan:";
        //
        // textBox1
        //
        this->textBox1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->textBox1->Location = System::Drawing::Point(92, 196);
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(343, 27);
        this->textBox1->TabIndex = 5;
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSubmit->ForeColor = System::Drawing::Color::Black;
        this->btnSubmit->Location = System::Drawing::Point(210, 249);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(109, 29);
        this->btnSubmit->TabIndex = 6;
        this->btnSubmit->Text = L"Chuyen tien";
        this->btnSubmit->UseVisualStyleBackColor = false;
        //
        // TransferMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(568, 393);
        this->Controls->Add(this->panel1);
        this->Name = L"TransferMoneyForm";
        this->Text = L"TransferMoneyForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
};
} // namespace BankingAppwinform
