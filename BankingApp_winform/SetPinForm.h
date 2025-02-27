#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "User.h"
#include "Validate.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class SetPinForm : public System::Windows::Forms::Form {
  public:
    SetPinForm(void) { InitializeComponent(); }

  protected:
    ~SetPinForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::TextBox ^ password;
    System::Windows::Forms::TextBox ^ pin;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->pin = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->SuspendLayout();
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->label1->Location = System::Drawing::Point(9, 84);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(63, 17);
        this->label1->TabIndex = 35;
        this->label1->Text = L"Mat khau:";
        //
        // password
        //
        this->password->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->password->Location = System::Drawing::Point(12, 104);
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(302, 23);
        this->password->TabIndex = 34;
        //
        // pin
        //
        this->pin->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->pin->Location = System::Drawing::Point(12, 49);
        this->pin->Name = L"pin";
        this->pin->PasswordChar = '*';
        this->pin->Size = System::Drawing::Size(302, 23);
        this->pin->TabIndex = 33;
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->label2->Location = System::Drawing::Point(9, 29);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(65, 17);
        this->label2->TabIndex = 32;
        this->label2->Text = L"Pin (6 so):";
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::System;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSubmit->ForeColor = System::Drawing::Color::Black;
        this->btnSubmit->Location = System::Drawing::Point(94, 146);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(135, 24);
        this->btnSubmit->TabIndex = 31;
        this->btnSubmit->Text = L"Doi Pin";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &SetPinForm::btnSubmit_Click);
        //
        // SetPinForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(326, 199);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->password);
        this->Controls->Add(this->pin);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->btnSubmit);
        this->Name = L"SetPinForm";
        this->Text = L"SetPinForm";
        this->Load +=
            gcnew System::EventHandler(this, &SetPinForm::SetPinForm_Load);
        this->ResumeLayout(false);
        this->PerformLayout();
    }

#pragma endregion
  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        if (!Validate::isPin(this->pin->Text)) {
            MessageBox::Show("Pin phai co 6 chu so !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else if (this->password->Text == "") {
            MessageBox::Show("Mat khau khong chinh xac !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else {
            User ^ user = GlobalData::GetCurrentUser();
            if (user->getPassword() != this->password->Text) {
                MessageBox::Show("Mat khau khong chinh xac !", "Canh bao",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
            } else {

                // luu user vao file
                array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
                if (users == nullptr) {
                    MessageBox::Show("Co loi xay ra !", "Tiêu đề",
                                     MessageBoxButtons::OK,
                                     MessageBoxIcon::Error);
                    return;
                } else {
                    for (int i = 0; i < users->Length; i++) {
                        if (users[i]->getAccountNumber() ==
                                GlobalData::GetCurrentUser()
                                    ->getAccountNumber() &&
                            this->password->Text == users[i]->getPassword()) {
                            users[i]->setPin(Convert::ToInt32(this->pin->Text));
                            GlobalData::SetCurrentUser(users[i]);
                            break;
                        }
                    }
                }
                bool isSaved = HandleFile::WriteUserArray(users, "users.dat");
                if (isSaved) {
                    MessageBox::Show("Dat ma pin thanh cong !", "success",
                                     MessageBoxButtons::OK,
                                     MessageBoxIcon::Information);
                } else {
                    MessageBox::Show("Co loi xay ra !", "success",
                                     MessageBoxButtons::OK,
                                     MessageBoxIcon::Error);
                }
            }
        }
    }

  private:
    System::Void SetPinForm_Load(System::Object ^ sender,
                                 System::EventArgs ^ e) {}
};
}
