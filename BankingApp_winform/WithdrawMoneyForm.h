#pragma once

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
    WithdrawMoneyForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~WithdrawMoneyForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::TextBox ^ textBox2;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::TextBox ^ textBox1;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Label ^ label3;

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
        this->textBox2 = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->textBox2);
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->btnSubmit);
        this->panel1->Controls->Add(this->textBox1);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Location = System::Drawing::Point(24, 84);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(522, 333);
        this->panel1->TabIndex = 0;
        //
        // textBox2
        //
        this->textBox2->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->textBox2->Location = System::Drawing::Point(85, 149);
        this->textBox2->Name = L"textBox2";
        this->textBox2->PasswordChar = '*';
        this->textBox2->Size = System::Drawing::Size(343, 27);
        this->textBox2->TabIndex = 11;
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(81, 116);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(60, 21);
        this->label2->TabIndex = 10;
        this->label2->Text = L"Ma pin:";
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
        this->btnSubmit->Location = System::Drawing::Point(210, 204);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(109, 29);
        this->btnSubmit->TabIndex = 9;
        this->btnSubmit->Text = L"Rut tien";
        this->btnSubmit->UseVisualStyleBackColor = false;
        //
        // textBox1
        //
        this->textBox1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->textBox1->Location = System::Drawing::Point(85, 60);
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(343, 27);
        this->textBox1->TabIndex = 8;
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(81, 27);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(104, 21);
        this->label1->TabIndex = 7;
        this->label1->Text = L"Nhap so tien:";
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel2->Controls->Add(this->label3);
        this->panel2->Location = System::Drawing::Point(24, 12);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(522, 55);
        this->panel2->TabIndex = 1;
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label3->Location = System::Drawing::Point(19, 16);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(204, 21);
        this->label3->TabIndex = 12;
        this->label3->Text = L"So du hien tai: 95.000,000d";
        //
        // WithdrawMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(573, 429);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Name = L"WithdrawMoneyForm";
        this->Text = L"WithdrawMoneyForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
};
} // namespace BankingAppwinform
