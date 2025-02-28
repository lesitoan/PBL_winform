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

    System::Windows::Forms::TextBox ^ password;
    System::Windows::Forms::TextBox ^ phoneNumber;


    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::CheckBox ^ btnShowPw;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code

    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                LoginForm::typeid));
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->btnShowPw = (gcnew System::Windows::Forms::CheckBox());
        this->SuspendLayout();
        //
        // password
        //
        this->password->BorderStyle = System::Windows::Forms::BorderStyle::None;
        resources->ApplyResources(this->password, L"password");
        this->password->Name = L"password";
        //
        // phoneNumber
        //
        this->phoneNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        resources->ApplyResources(this->phoneNumber, L"phoneNumber");
        this->phoneNumber->Name = L"phoneNumber";
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        resources->ApplyResources(this->btnSubmit, L"btnSubmit");
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &LoginForm::btnSubmit_Click);
        //
        // label4
        //
        this->label4->ForeColor = System::Drawing::Color::White;
        resources->ApplyResources(this->label4, L"label4");
        this->label4->Name = L"label4";
        //
        // label3
        //
        resources->ApplyResources(this->label3, L"label3");
        this->label3->ForeColor = System::Drawing::Color::White;
        this->label3->Name = L"label3";
        //
        // labelAuth
        //
        resources->ApplyResources(this->labelAuth, L"labelAuth");
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->Name = L"labelAuth";
        //
        // label1
        //
        resources->ApplyResources(this->label1, L"label1");
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->Name = L"label1";
        //
        // btnShowPw
        //
        this->btnShowPw->BackColor = System::Drawing::Color::MintCream;
        this->btnShowPw->Cursor = System::Windows::Forms::Cursors::Hand;
        resources->ApplyResources(this->btnShowPw, L"btnShowPw");
        this->btnShowPw->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->btnShowPw->Name = L"btnShowPw";
        this->btnShowPw->UseVisualStyleBackColor = false;
        this->btnShowPw->CheckedChanged += gcnew System::EventHandler(
            this, &LoginForm::btnShowPw_CheckedChanged);
        //
        // LoginForm
        //
        resources->ApplyResources(this, L"$this");
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->Controls->Add(this->btnShowPw);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->password);
        this->Controls->Add(this->phoneNumber);
        this->Controls->Add(this->btnSubmit);
        this->Name = L"LoginForm";
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
}
