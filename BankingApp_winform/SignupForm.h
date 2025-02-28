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
    System::Windows::Forms::CheckBox ^ btnShowPw;

  protected:
  private:
    System::Windows::Forms::Label ^ label6;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Label ^ label7;

  private:


  private:
    System::Windows::Forms::TextBox ^ password;

  private:
    System::Windows::Forms::TextBox ^ phoneNumber;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Label ^ label9;

  private:
    System::Windows::Forms::TextBox ^ fullName;

  private:
    System::Windows::Forms::CheckBox ^ btnShowPwCf;

  private:


  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::TextBox ^ passwordConfirm;

  private:


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
  private:


  private:


  private:
  private:


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
        this->btnShowPw = (gcnew System::Windows::Forms::CheckBox());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->fullName = (gcnew System::Windows::Forms::TextBox());
        this->btnShowPwCf = (gcnew System::Windows::Forms::CheckBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->passwordConfirm = (gcnew System::Windows::Forms::TextBox());
        this->SuspendLayout();
        //
        // btnShowPw
        //
        this->btnShowPw->BackColor = System::Drawing::Color::MintCream;
        this->btnShowPw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowPw->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowPw->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->btnShowPw->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnShowPw->Location = System::Drawing::Point(406, 228);
        this->btnShowPw->Name = L"btnShowPw";
        this->btnShowPw->Padding = System::Windows::Forms::Padding(5, 6, 5, 5);
        this->btnShowPw->Size = System::Drawing::Size(93, 37);
        this->btnShowPw->TabIndex = 41;
        this->btnShowPw->Text = L"Show";
        this->btnShowPw->UseVisualStyleBackColor = false;
        this->btnShowPw->CheckedChanged += gcnew System::EventHandler(
            this, &SignupForm::btnShowPw_CheckedChanged);
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label6->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label6->ForeColor = System::Drawing::Color::Transparent;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(56, 203);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(218, 22);
        this->label6->TabIndex = 40;
        this->label6->Text = L"Nhập mật khẩu (ít nhất 6 kí tự):";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(270, 117);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(141, 22);
        this->labelAuth->TabIndex = 39;
        this->labelAuth->Text = L"Nhập số điện thoại:";
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 22, System::Drawing::FontStyle::Bold));
        this->label7->ForeColor = System::Drawing::Color::White;
        this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label7->Location = System::Drawing::Point(141, 49);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(270, 40);
        this->label7->TabIndex = 38;
        this->label7->Text = L"ĐĂNG KÍ TÀI KHOẢN";
        this->label7->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // password
        //
        this->password->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->password->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->password->Location = System::Drawing::Point(57, 228);
        this->password->Multiline = true;
        this->password->Name = L"password";
        this->password->PasswordChar = '*';
        this->password->Size = System::Drawing::Size(354, 37);
        this->password->TabIndex = 36;
        //
        // phoneNumber
        //
        this->phoneNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->phoneNumber->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->phoneNumber->Location = System::Drawing::Point(276, 142);
        this->phoneNumber->Multiline = true;
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(226, 37);
        this->phoneNumber->TabIndex = 34;
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
        this->btnSubmit->Location = System::Drawing::Point(57, 391);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(442, 42);
        this->btnSubmit->TabIndex = 35;
        this->btnSubmit->Text = L"ĐĂNG KÍ TÀI KHOẢN";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &SignupForm::btnSubmit_Click);
        //
        // label9
        //
        this->label9->AutoSize = true;
        this->label9->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label9->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label9->ForeColor = System::Drawing::Color::Transparent;
        this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label9->Location = System::Drawing::Point(56, 117);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(164, 22);
        this->label9->TabIndex = 43;
        this->label9->Text = L"Nhập tên (không dấu):";
        //
        // fullName
        //
        this->fullName->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->fullName->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->fullName->Location = System::Drawing::Point(57, 142);
        this->fullName->Multiline = true;
        this->fullName->Name = L"fullName";
        this->fullName->Size = System::Drawing::Size(213, 37);
        this->fullName->TabIndex = 42;
        //
        // btnShowPwCf
        //
        this->btnShowPwCf->BackColor = System::Drawing::Color::MintCream;
        this->btnShowPwCf->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowPwCf->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->btnShowPwCf->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->btnShowPwCf->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnShowPwCf->Location = System::Drawing::Point(406, 314);
        this->btnShowPwCf->Name = L"btnShowPwCf";
        this->btnShowPwCf->Padding =
            System::Windows::Forms::Padding(5, 6, 5, 5);
        this->btnShowPwCf->Size = System::Drawing::Size(93, 37);
        this->btnShowPwCf->TabIndex = 46;
        this->btnShowPwCf->Text = L"Show";
        this->btnShowPwCf->UseVisualStyleBackColor = false;
        this->btnShowPwCf->CheckedChanged += gcnew System::EventHandler(
            this, &SignupForm::btnShowPwCf_CheckedChanged);
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(56, 289);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(142, 22);
        this->label1->TabIndex = 45;
        this->label1->Text = L"Xác nhận mật khẩu:";
        //
        // passwordConfirm
        //
        this->passwordConfirm->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->passwordConfirm->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->passwordConfirm->Location = System::Drawing::Point(57, 314);
        this->passwordConfirm->Multiline = true;
        this->passwordConfirm->Name = L"passwordConfirm";
        this->passwordConfirm->PasswordChar = '*';
        this->passwordConfirm->Size = System::Drawing::Size(354, 37);
        this->passwordConfirm->TabIndex = 44;
        //
        // SignupForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(547, 488);
        this->Controls->Add(this->btnShowPwCf);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->passwordConfirm);
        this->Controls->Add(this->label9);
        this->Controls->Add(this->fullName);
        this->Controls->Add(this->btnShowPw);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->password);
        this->Controls->Add(this->phoneNumber);
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

  private:
    System::Void btnShowPwCf_CheckedChanged(System::Object ^ sender,
                                            System::EventArgs ^ e) {
        if (btnShowPwCf->Checked) {
            passwordConfirm->PasswordChar = '\0';
            btnShowPwCf->Text = "Hide";
        } else {
            passwordConfirm->PasswordChar = '*';
            btnShowPwCf->Text = "Show";
        }
    }

  private:
    System::Void btnShowPw_CheckedChanged(System::Object ^ sender,
                                          System::EventArgs ^ e) {
        if (btnShowPw->Checked) {
            password->PasswordChar = '\0';
            btnShowPw->Text = "Hide";
        } else {
            password->PasswordChar = '*';
            btnShowPw->Text = "Show";
        }
    }
};
} // namespace BankingAppwinform
