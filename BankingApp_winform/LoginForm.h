#pragma once
#include "HandleFile.h"
#include "User.h"
#include "GlobalData.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class LoginForm : public System::Windows::Forms::Form {
  public:
    LoginForm(void) {
        InitializeComponent();
    }
    event EventHandler ^ LoginSuccess;

  protected:
    ~LoginForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::TextBox ^ password;
    System::Windows::Forms::TextBox ^ phoneNumber;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Button ^ btnSubmit;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code

    void InitializeComponent(void) {
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
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
        this->label3->Location = System::Drawing::Point(12, 52);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(171, 40);
        this->label3->TabIndex = 23;
        this->label3->Text = L"Dang nhap";
        //
        // password
        //
        this->password->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->password->Location = System::Drawing::Point(16, 220);
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(289, 27);
        this->password->TabIndex = 22;
        //
        // phoneNumber
        //
        this->phoneNumber->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->phoneNumber->Location = System::Drawing::Point(16, 148);
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(289, 27);
        this->phoneNumber->TabIndex = 19;
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(15, 196);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(79, 21);
        this->label2->TabIndex = 21;
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
        this->label1->Location = System::Drawing::Point(12, 124);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(108, 21);
        this->label1->TabIndex = 18;
        this->label1->Text = L"So dien thoai:";
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
        this->btnSubmit->Location = System::Drawing::Point(105, 276);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(117, 29);
        this->btnSubmit->TabIndex = 20;
        this->btnSubmit->Text = L"Dang nhap";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &LoginForm::btnSubmit_Click);
        //
        // LoginForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(324, 377);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->password);
        this->Controls->Add(this->phoneNumber);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->btnSubmit);
        this->Name = L"LoginForm";
        this->Text = L"LoginForm";
        this->Load +=
            gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
        this->ResumeLayout(false);
        this->PerformLayout();
    }

#pragma endregion
  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        String ^ phone = phoneNumber->Text;
        String ^ pass = password->Text;
        if (phone == "" || pass == "") {
            MessageBox::Show("Vui long nhap day du thong tin");
            return;
        } else {
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
            for each (User ^ user in users) {
                if (user->getPhoneNumber() == phone &&
                    user->getPassword() == pass) {
                    GlobalData::SetCurrentUser(user);
                    MessageBox::Show("Dang nhap thanh cong");
                    LoginSuccess(this, EventArgs::Empty);
                    return;
                }
            }
            MessageBox::Show("Dang nhap that bai");
        }
    }

  private:
    System::Void LoginForm_Load(System::Object ^ sender,
                                System::EventArgs ^ e) {}
};
}
