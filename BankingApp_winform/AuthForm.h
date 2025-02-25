#pragma once
#include "ForgotPwForm.h"
#include "LoadChildForm.h"
#include "LoginForm.h"
#include "MainForm.h"
#include "SignupForm.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class AuthForm : public System::Windows::Forms::Form {
  public:
    AuthForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~AuthForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Panel ^ Panel3;

  private:
    System::Windows::Forms::PictureBox ^ pictureBox1;

  private:
    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Label ^ labelForgotPw;

  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code

    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AuthForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->labelForgotPw = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->Panel3 = (gcnew System::Windows::Forms::Panel());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panel1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->BeginInit();
        this->Panel3->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->labelForgotPw);
        this->panel1->Controls->Add(this->labelAuth);
        this->panel1->Controls->Add(this->pictureBox1);
        this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(362, 461);
        this->panel1->TabIndex = 0;
        //
        // labelForgotPw
        //
        this->labelForgotPw->AutoSize = true;
        this->labelForgotPw->Font = (gcnew System::Drawing::Font(
            L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelForgotPw->ForeColor = System::Drawing::Color::Blue;
        this->labelForgotPw->Location = System::Drawing::Point(169, 421);
        this->labelForgotPw->Name = L"labelForgotPw";
        this->labelForgotPw->Size = System::Drawing::Size(107, 19);
        this->labelForgotPw->TabIndex = 2;
        this->labelForgotPw->Text = L"Quên mật khẩu";
        this->labelForgotPw->Click +=
            gcnew System::EventHandler(this, &AuthForm::labelForgotPw_Click);
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Font = (gcnew System::Drawing::Font(
            L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelAuth->ForeColor = System::Drawing::Color::Blue;
        this->labelAuth->Location = System::Drawing::Point(96, 421);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(56, 19);
        this->labelAuth->TabIndex = 1;
        this->labelAuth->Text = L"Đăng kí";
        this->labelAuth->Click +=
            gcnew System::EventHandler(this, &AuthForm::labelAuth_Click);
        //
        // pictureBox1
        //
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(81, 97);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(188, 135);
        this->pictureBox1->TabIndex = 0;
        this->pictureBox1->TabStop = false;
        //
        // Panel3
        //
        this->Panel3->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->Panel3->Controls->Add(this->panelContent);
        this->Panel3->Dock = System::Windows::Forms::DockStyle::Fill;
        this->Panel3->Location = System::Drawing::Point(362, 0);
        this->Panel3->Name = L"Panel3";
        this->Panel3->Size = System::Drawing::Size(422, 461);
        this->Panel3->TabIndex = 1;
        //
        // panelContent
        //
        this->panelContent->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->panelContent->Location = System::Drawing::Point(47, 23);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(340, 416);
        this->panelContent->TabIndex = 0;
        //
        // AuthForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(784, 461);
        this->Controls->Add(this->Panel3);
        this->Controls->Add(this->panel1);
        this->Name = L"AuthForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"AuthForm";
        this->Load +=
            gcnew System::EventHandler(this, &AuthForm::AuthForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->EndInit();
        this->Panel3->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void AuthForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
        LoginForm ^ loginForm = gcnew LoginForm();
        loginForm->LoginSuccess +=
            gcnew EventHandler(this, &AuthForm::OnLoginSuccess);
        LoadChildForm::LoadForm(this->panelContent, loginForm);
        this->labelAuth->Text = "Dang ki";
    }

    System::Void OnLoginSuccess(System::Object ^ sender,
                                System::EventArgs ^ e) {
        this->Hide();
        MainForm ^ mainForm = gcnew MainForm();
        mainForm->ShowDialog();
        this->Close();
    }

  private:
    String ^ currentForm = "login";

  private:
    System::Void labelForgotPw_Click(System::Object ^ sender,
                                     System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew ForgotPwForm());
        this->currentForm = "forgotpw";
        this->labelForgotPw->Visible = false;
        this->labelAuth->Text = "Dang nhap";
    }

  private:
    System::Void labelAuth_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        if (currentForm == "signup" || currentForm == "forgotpw") {
            LoginForm ^ loginForm = gcnew LoginForm();
            LoadChildForm::LoadForm(this->panelContent, loginForm);
            this->labelAuth->Text = "Dang ki";
            currentForm = "login";

        } else {
            LoadChildForm::LoadForm(this->panelContent, gcnew SignupForm());
            this->labelAuth->Text = "Dang nhap";
            currentForm = "signup";
        }
        this->labelForgotPw->Visible = true;
    }
};
} // namespace BankingAppwinform
