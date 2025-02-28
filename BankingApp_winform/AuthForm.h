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
        loadForm();
    }

  protected:
    ~AuthForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::PictureBox ^ pictureBox1;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::PictureBox ^ pictureBox2;
    System::Windows::Forms::Panel ^ panelContent;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Label ^ labelForgotPw;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Panel ^ panelRightContent;
    System::ComponentModel::IContainer ^ components;

  private:
    String ^ currentForm = "login";
    String ^ theme = "light";

  private:
    System::Void loadForm() {
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
    }

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AuthForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->labelForgotPw = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panelRightContent = (gcnew System::Windows::Forms::Panel());
        this->panel1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->BeginInit();
        this->panel2->SuspendLayout();
        this->panelRightContent->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel1->Controls->Add(this->pictureBox2);
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->pictureBox1);
        this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(318, 561);
        this->panel1->TabIndex = 0;
        //
        // pictureBox2
        //
        this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox2.Image")));
        this->pictureBox2->Location = System::Drawing::Point(263, 12);
        this->pictureBox2->Name = L"pictureBox2";
        this->pictureBox2->Size = System::Drawing::Size(49, 39);
        this->pictureBox2->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::Zoom;
        this->pictureBox2->TabIndex = 7;
        this->pictureBox2->TabStop = false;
        this->pictureBox2->Click +=
            gcnew System::EventHandler(this, &AuthForm::btnDarkMode_Click);
        //
        // label3
        //
        this->label3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
        this->label3->AutoSize = true;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 8));
        this->label3->ForeColor = System::Drawing::Color::White;
        this->label3->Location = System::Drawing::Point(91, 534);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(119, 14);
        this->label3->TabIndex = 6;
        this->label3->Text = L"Hỗ trợ 24/7: 0123465387";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 15.75F));
        this->label2->ForeColor = System::Drawing::Color::White;
        this->label2->Location = System::Drawing::Point(74, 331);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(173, 28);
        this->label2->TabIndex = 5;
        this->label2->Text = L"QUÝ KHÁCH HÀNG";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 15.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::White;
        this->label1->Location = System::Drawing::Point(101, 294);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(124, 28);
        this->label1->TabIndex = 4;
        this->label1->Text = L"CHÀO MỪNG";
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // pictureBox1
        //
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(37, 107);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(240, 184);
        this->pictureBox1->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::Zoom;
        this->pictureBox1->TabIndex = 3;
        this->pictureBox1->TabStop = false;
        //
        // panelContent
        //
        this->panelContent->Anchor = System::Windows::Forms::AnchorStyles::None;
        this->panelContent->AutoScroll = true;
        this->panelContent->BackColor = System::Drawing::Color::Teal;
        this->panelContent->Location = System::Drawing::Point(0, 0);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(563, 527);
        this->panelContent->TabIndex = 0;
        //
        // panel2
        //
        this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
        this->panel2->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel2->Controls->Add(this->labelForgotPw);
        this->panel2->Controls->Add(this->labelAuth);
        this->panel2->Location = System::Drawing::Point(0, 525);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(563, 36);
        this->panel2->TabIndex = 1;
        //
        // labelForgotPw
        //
        this->labelForgotPw->AutoSize = true;
        this->labelForgotPw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelForgotPw->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 12, System::Drawing::FontStyle::Underline,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelForgotPw->ForeColor = System::Drawing::Color::Transparent;
        this->labelForgotPw->Location = System::Drawing::Point(435, 5);
        this->labelForgotPw->Name = L"labelForgotPw";
        this->labelForgotPw->Size = System::Drawing::Size(113, 22);
        this->labelForgotPw->TabIndex = 2;
        this->labelForgotPw->Text = L"Quên mật khẩu";
        this->labelForgotPw->Click +=
            gcnew System::EventHandler(this, &AuthForm::labelForgotPw_Click);
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 12, System::Drawing::FontStyle::Underline,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->Location = System::Drawing::Point(346, 5);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(61, 22);
        this->labelAuth->TabIndex = 1;
        this->labelAuth->Text = L"Đăng kí";
        this->labelAuth->Click +=
            gcnew System::EventHandler(this, &AuthForm::labelAuth_Click);
        //
        // panelRightContent
        //
        this->panelRightContent->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelRightContent->AutoScroll = true;
        this->panelRightContent->BackColor =
            System::Drawing::Color::Transparent;
        this->panelRightContent->Controls->Add(this->panel2);
        this->panelRightContent->Controls->Add(this->panelContent);
        this->panelRightContent->Location = System::Drawing::Point(324, 0);
        this->panelRightContent->Name = L"panelRightContent";
        this->panelRightContent->Size = System::Drawing::Size(560, 561);
        this->panelRightContent->TabIndex = 1;
        //
        // AuthForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(884, 561);
        this->Controls->Add(this->panelRightContent);
        this->Controls->Add(this->panel1);
        this->MinimumSize = System::Drawing::Size(900, 600);
        this->Name = L"AuthForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Banking App";
        this->Load +=
            gcnew System::EventHandler(this, &AuthForm::AuthForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->EndInit();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panelRightContent->ResumeLayout(false);
        this->ResumeLayout(false);
    }

#pragma endregion
  private:
    System::Void AuthForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
        LoginForm ^ loginForm = gcnew LoginForm();
        loginForm->LoginSuccess +=
            gcnew EventHandler(this, &AuthForm::OnLoginSuccess);
        LoadChildForm::LoadForm(this->panelContent, loginForm);
        this->labelAuth->Text = L"Đăng kí";
    }

    System::Void OnLoginSuccess(System::Object ^ sender,
                                System::EventArgs ^ e) {
        this->Hide();
        MainForm ^ mainForm = gcnew MainForm();
        mainForm->ShowDialog();
        this->Close();
    }

    System::Void OnSignupSuccess(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        LoginForm ^ loginForm = gcnew LoginForm();
        loginForm->LoginSuccess +=
            gcnew EventHandler(this, &AuthForm::OnLoginSuccess);
        LoadChildForm::LoadForm(this->panelContent, loginForm);
        this->labelAuth->Text = L"Đăng kí";
    }

  private:
    System::Void labelForgotPw_Click(System::Object ^ sender,
                                     System::EventArgs ^ e) {
        LoadChildForm::LoadForm(this->panelContent, gcnew ForgotPwForm());
        this->currentForm = "forgotpw";
        this->labelForgotPw->Visible = false;
        this->labelAuth->Text = L"Đăng nhập";
    }

  private:
    System::Void labelAuth_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        if (currentForm == "signup" || currentForm == "forgotpw") {
            LoginForm ^ loginForm = gcnew LoginForm();
            LoadChildForm::LoadForm(this->panelContent, loginForm);
            this->labelAuth->Text = L"Đăng kí";
            currentForm = "login";

        } else {
            SignupForm ^ signupForm = gcnew SignupForm();
            LoadChildForm::LoadForm(this->panelContent, signupForm);
            signupForm->SignupSuccess +=
                gcnew EventHandler(this, &AuthForm::OnSignupSuccess);
            this->labelAuth->Text = L"Đăng nhập";
            //signupForm->AutoScroll = true;
            currentForm = "signup";
        }
        this->labelForgotPw->Visible = true;
    }

  private:
    System::Void btnDarkMode_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
        if (theme == "light") {
            this->panelRightContent->BackColor =
                System::Drawing::Color::FromArgb(
                    static_cast<System::Int32>(static_cast<System::Byte>(0)),
                    static_cast<System::Int32>(static_cast<System::Byte>(64)),
                    static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->theme = "dark";
        } else {
            this->panelRightContent->BackColor = System::Drawing::Color::White;
            this->theme = "light";
        }
    }

  private:
    System::Void panel1_Click(System::Object ^ sender, System::EventArgs ^ e) {}
};
} // namespace BankingAppwinform
