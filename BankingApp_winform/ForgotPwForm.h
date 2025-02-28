#pragma once

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for ForgotPwForm
/// </summary>
public
ref class ForgotPwForm : public System::Windows::Forms::Form {
  public:
    ForgotPwForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~ForgotPwForm() {
        if (components) {
            delete components;
        }
    }

  private:


  protected:
  private:


  private:


  private:


  private:


  private:


  private:


  private:


  private:


  private:
    System::Windows::Forms::Label ^ label6;

  private:


  private:


  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:


  private:
    System::Windows::Forms::TextBox ^ phoneNumber;

  private:
    System::Windows::Forms::Button ^ button1;

  private:
    System::Windows::Forms::Label ^ label7;

  private:
    System::Windows::Forms::TextBox ^ textBox4;

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
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->textBox4 = (gcnew System::Windows::Forms::TextBox());
        this->SuspendLayout();
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 22, System::Drawing::FontStyle::Bold));
        this->label6->ForeColor = System::Drawing::Color::White;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(161, 101);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(231, 40);
        this->label6->TabIndex = 43;
        this->label6->Text = L"QUÊN MÂT KHẨU";
        this->label6->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(55, 241);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(141, 22);
        this->labelAuth->TabIndex = 47;
        this->labelAuth->Text = L"Nhập số điện thoại:";
        //
        // phoneNumber
        //
        this->phoneNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->phoneNumber->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->phoneNumber->Location = System::Drawing::Point(56, 266);
        this->phoneNumber->Multiline = true;
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(442, 37);
        this->phoneNumber->TabIndex = 44;
        //
        // button1
        //
        this->button1->BackColor = System::Drawing::SystemColors::Info;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->BorderSize = 0;
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button1->ForeColor = System::Drawing::Color::Teal;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(56, 342);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(442, 42);
        this->button1->TabIndex = 45;
        this->button1->Text = L"LẤY LẠI MẬT KHẨU";
        this->button1->UseVisualStyleBackColor = false;
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label7->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label7->ForeColor = System::Drawing::Color::Transparent;
        this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label7->Location = System::Drawing::Point(55, 160);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(132, 22);
        this->label7->TabIndex = 51;
        this->label7->Text = L"Nhập tên của bạn:";
        //
        // textBox4
        //
        this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->textBox4->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->textBox4->Location = System::Drawing::Point(56, 185);
        this->textBox4->Multiline = true;
        this->textBox4->Name = L"textBox4";
        this->textBox4->Size = System::Drawing::Size(442, 37);
        this->textBox4->TabIndex = 50;
        //
        // ForgotPwForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(547, 488);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->textBox4);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->phoneNumber);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->label6);
        this->Name = L"ForgotPwForm";
        this->Text = L"ForgotPwForm";
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
};
} // namespace BankingAppwinform
