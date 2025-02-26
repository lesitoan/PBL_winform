#pragma once
#include "HandleFile.h"
#include "LoginForm.h"
#include "User.h"

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

  private:
    System::Windows::Forms::TextBox ^ password;

  protected:
  private:
  private:
    System::Windows::Forms::TextBox ^ fullName;

  private:
  private:
  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::TextBox ^ phoneNumber;

  private:
  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::TextBox ^ passwordConfirm;

  private:
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
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->fullName = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->passwordConfirm = (gcnew System::Windows::Forms::TextBox());
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
        // password
        //
        this->password->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->password->Location = System::Drawing::Point(16, 210);
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(289, 27);
        this->password->TabIndex = 28;
        //
        // fullName
        //
        this->fullName->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->fullName->Location = System::Drawing::Point(16, 91);
        this->fullName->Name = L"fullName";
        this->fullName->Size = System::Drawing::Size(289, 27);
        this->fullName->TabIndex = 25;
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
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &SignupForm::btnSubmit_Click);
        //
        // phoneNumber
        //
        this->phoneNumber->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->phoneNumber->Location = System::Drawing::Point(16, 148);
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(289, 27);
        this->phoneNumber->TabIndex = 31;
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
        // passwordConfirm
        //
        this->passwordConfirm->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->passwordConfirm->Location = System::Drawing::Point(16, 275);
        this->passwordConfirm->Name = L"passwordConfirm";
        this->passwordConfirm->PasswordChar = '*';
        this->passwordConfirm->Size = System::Drawing::Size(289, 27);
        this->passwordConfirm->TabIndex = 33;
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
        this->Controls->Add(this->passwordConfirm);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->phoneNumber);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->password);
        this->Controls->Add(this->fullName);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->btnSubmit);
        this->Name = L"SignupForm";
        this->Text = L"SignupForm";
        this->Load +=
            gcnew System::EventHandler(this, &SignupForm::SignupForm_Load);
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
  private:
    System::Void SignupForm_Load(System::Object ^ sender,
                                 System::EventArgs ^ e) {}

  public:
    event EventHandler ^ SignupSuccess;

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        // kiem tra da nhap du thong tin chua
        if (fullName->Text->Length == 0 || password->Text->Length == 0 ||
            passwordConfirm->Text->Length == 0 ||
            phoneNumber->Text->Length == 0) {
            MessageBox::Show("Vui long nhap day du thong tin !", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (password->Text != passwordConfirm->Text) {
            MessageBox::Show("Mat khau khong khop !", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        if (password->Text->Length < 6) {
            MessageBox::Show("Mat khau phai co it nhat 6 ki tu !", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (phoneNumber->Text->Length != 10) {
            MessageBox::Show("Sai dinh dang so dien thoai !", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        // kiem tra ten > 5 ki tu
        if (fullName->Text->Length < 5) {
            MessageBox::Show("Ten phai co it nhat 5 ki tu !", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // luu user vao file
        User ^ user = gcnew User(fullName->Text, password->Text, phoneNumber->Text);
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        if (users == nullptr) {
            users = gcnew array<User ^>{user};
        } else {
            array<User ^> ^ newUsers = gcnew array<User ^>(users->Length + 1);
            for (int i = 0; i < users->Length; i++) {
                newUsers[i] = users[i];
            }
            newUsers[users->Length] = user;
            users = newUsers;
        }
        bool isSaved =
            HandleFile::WriteUserArray(users, "users.dat");
        if (isSaved) {
            MessageBox::Show("Dang ki thanh cong !", "Success",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information);
            // Chuyen sang trang dang nhap
            SignupSuccess(this, EventArgs::Empty);
        }
    }
};
} // namespace BankingAppwinform
