#pragma once
#include "Validate.h"
#include "HandleFile.h"

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

  private:
    System::Windows::Forms::Button ^ btnSubmit;


    System::Windows::Forms::Label ^ label7;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::TextBox ^ fullName;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::TextBox ^ phoneNumber;

  private:


    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->fullName = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
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
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(56, 342);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(442, 42);
        this->btnSubmit->TabIndex = 45;
        this->btnSubmit->Text = L"LẤY LẠI MẬT KHẨU";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &ForgotPwForm::btnSubmit_Click);
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
        this->panel2->Controls->Add(this->phoneNumber);
        this->panel2->Location = System::Drawing::Point(59, 266);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(439, 37);
        this->panel2->TabIndex = 53;
        //
        // phoneNumber
        //
        this->phoneNumber->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->phoneNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->phoneNumber->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->phoneNumber->Location = System::Drawing::Point(18, 6);
        this->phoneNumber->MaxLength = 20;
        this->phoneNumber->Multiline = true;
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(418, 28);
        this->phoneNumber->TabIndex = 29;
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
        this->Controls->Add(this->btnSubmit);
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
  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        // 📌 Lấy thông tin từ form
        String ^ fullName = this->fullName->Text;
        String ^ phoneNumber = this->phoneNumber->Text;
        if (fullName->Length == 0 ||
            phoneNumber->Length == 0) {
            MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        } else if (!Validate::isValidVietnamPhoneNumber(phoneNumber)) {
            MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        } else if (!Validate::isValidCustomerName(fullName)) {
            MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        // 📌 Kiểm tra thông tin nhập vào có trùng với thông tin trong file
        // không
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        DateTime now = DateTime::Now;
        String ^ newPassword = "TML" + now.ToString("HHmmss");
        for each (User ^ user in users) {
            if (user->getFullName() == fullName &&
                user->getPhoneNumber() == phoneNumber) {
                user->setPassword(newPassword);
                bool isSaved = HandleFile::WriteUserArray(users, "users.dat");
                if (isSaved) {
                    MessageBox::Show(L"Mật khẩu mới của bạn là: " + newPassword,
                                     "Success", MessageBoxButtons::OK,
                                     MessageBoxIcon::Information);
                    return;
                } else {
                    MessageBox::Show(L"Lấy lại mật khẩu thất bại!", "Error",
                                     MessageBoxButtons::OK,
                                     MessageBoxIcon::Error);
                    return;
                }
            }
        }
    }
};
} // namespace BankingAppwinform
