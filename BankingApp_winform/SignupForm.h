#pragma once

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for SignupForm
/// </summary>
public
ref class SignupForm : public System::Windows::Forms::Form {
  public:
    SignupForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~SignupForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Label ^ label3;

  protected:
  private:
    System::Windows::Forms::TextBox ^ textBox2;

  private:
    System::Windows::Forms::TextBox ^ textBox1;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::TextBox ^ textBox3;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::TextBox ^ textBox4;

  private:
    System::Windows::Forms::Label ^ label5;

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
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->textBox2 = (gcnew System::Windows::Forms::TextBox());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->textBox3 = (gcnew System::Windows::Forms::TextBox());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->textBox4 = (gcnew System::Windows::Forms::TextBox());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->SuspendLayout();
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 24,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label3->Location = System::Drawing::Point(12, 19);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(126, 40);
        this->label3->TabIndex = 29;
        this->label3->Text = L"Dang ki";
        //
        // textBox2
        //
        this->textBox2->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->textBox2->Location = System::Drawing::Point(16, 210);
        this->textBox2->Name = L"textBox2";
        this->textBox2->PasswordChar = '*';
        this->textBox2->Size = System::Drawing::Size(289, 27);
        this->textBox2->TabIndex = 28;
        //
        // textBox1
        //
        this->textBox1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->textBox1->Location = System::Drawing::Point(16, 91);
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(289, 27);
        this->textBox1->TabIndex = 25;
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(15, 186);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(79, 21);
        this->label2->TabIndex = 27;
        this->label2->Text = L"Mat khau:";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(12, 67);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(40, 21);
        this->label1->TabIndex = 24;
        this->label1->Text = L"Ten:";
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::System;
        this->btnSubmit->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->btnSubmit->ForeColor = System::Drawing::Color::Black;
        this->btnSubmit->Location = System::Drawing::Point(95, 323);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(117, 29);
        this->btnSubmit->TabIndex = 26;
        this->btnSubmit->Text = L"Dang ki";
        this->btnSubmit->UseVisualStyleBackColor = false;
        //
        // textBox3
        //
        this->textBox3->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->textBox3->Location = System::Drawing::Point(16, 148);
        this->textBox3->Name = L"textBox3";
        this->textBox3->Size = System::Drawing::Size(289, 27);
        this->textBox3->TabIndex = 31;
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label4->Location = System::Drawing::Point(12, 124);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(108, 21);
        this->label4->TabIndex = 30;
        this->label4->Text = L"So dien thoai:";
        //
        // textBox4
        //
        this->textBox4->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->textBox4->Location = System::Drawing::Point(16, 275);
        this->textBox4->Name = L"textBox4";
        this->textBox4->PasswordChar = '*';
        this->textBox4->Size = System::Drawing::Size(289, 27);
        this->textBox4->TabIndex = 33;
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label5->Location = System::Drawing::Point(15, 251);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(153, 21);
        this->label5->TabIndex = 32;
        this->label5->Text = L"Xac nhan mat khau:";
        //
        // SignupForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(324, 377);
        this->Controls->Add(this->textBox4);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->textBox3);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->textBox2);
        this->Controls->Add(this->textBox1);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->btnSubmit);
        this->Name = L"SignupForm";
        this->Text = L"SignupForm";
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
};
} // namespace BankingAppwinform
