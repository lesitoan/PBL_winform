#pragma once

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
public
ref class ForgotPwForm : public System::Windows::Forms::Form {
  public:
    ForgotPwForm(void);

  protected:
    ~ForgotPwForm();

  private:
    System::Windows::Forms::Label ^ label6;
    System::Windows::Forms::Label ^ labelAuth;

    System::Windows::Forms::Button ^ button1;
    System::Windows::Forms::Label ^ label7;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::TextBox ^ fullName;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::TextBox ^ textBox1;

    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->fullName = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
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
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->Controls->Add(this->fullName);
        this->panel1->Location = System::Drawing::Point(59, 185);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(439, 37);
        this->panel1->TabIndex = 52;
        //
        // fullName
        //
        this->fullName->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->fullName->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->fullName->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->fullName->Location = System::Drawing::Point(18, 6);
        this->fullName->MaxLength = 35;
        this->fullName->Multiline = true;
        this->fullName->Name = L"fullName";
        this->fullName->Size = System::Drawing::Size(418, 28);
        this->fullName->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->textBox1);
        this->panel2->Location = System::Drawing::Point(59, 266);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(439, 37);
        this->panel2->TabIndex = 53;
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
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->textBox1->Location = System::Drawing::Point(18, 6);
        this->textBox1->MaxLength = 10;
        this->textBox1->Multiline = true;
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(418, 28);
        this->textBox1->TabIndex = 29;
        //
        // ForgotPwForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(547, 488);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->label6);
        this->Name = L"ForgotPwForm";
        this->Text = L"ForgotPwForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
};
} // namespace BankingAppwinform
