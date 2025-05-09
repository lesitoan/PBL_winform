﻿#include "AuthForm.h"

namespace BankingAppwinform {
AuthForm::AuthForm() {
    InitializeComponent();
    this->loadForm();
}

AuthForm::~AuthForm() {
    if (components) {
        delete components;
    }
}

System::Void AuthForm::AuthForm_Load(System::Object ^ sender,
                                     System::EventArgs ^ e) {
    LoginForm ^ loginForm = gcnew LoginForm();
    loginForm->LoginSuccess +=
        gcnew EventHandler(this, &AuthForm::OnLoginSuccess);
    LoadChildForm::LoadForm(this->panelContent, loginForm);
    this->labelAuth->Text = L"Không Có Tài Khoản?";

    //
    String ^ projectPath =
        System::IO::Directory::GetParent(Application::StartupPath)
            ->Parent->FullName;
    String ^ correctPath = System::IO::Path::Combine(
        projectPath, "BankingApp_winform\\images\\VideoAuthForm.mp4");


    this->axWindowsMediaPlayer1->uiMode ="none";
    this->axWindowsMediaPlayer1->URL = correctPath;
    this->axWindowsMediaPlayer1->settings->setMode("loop", true);
    this->axWindowsMediaPlayer1->Ctlcontrols->play();
    this->VisibleChanged +=
        gcnew System::EventHandler(this, &AuthForm::AuthForm_VisibleChanged);
}

System::Void AuthForm::labelForgotPw_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    ForgotPwForm ^ forgotPwForm = gcnew ForgotPwForm();
    LoadChildForm::LoadForm(this->panelContent, forgotPwForm);
    this->currentForm = "forgotpw";
    this->labelForgotPw->Visible = false;
    this->labelAuth->Text = L"Đăng Nhập";
}

System::Void AuthForm::labelAuth_Click(System::Object ^ sender,
                                       System::EventArgs ^ e) {
    if (currentForm == "signup" || currentForm == "forgotpw") {
        LoginForm ^ loginForm = gcnew LoginForm();
        LoadChildForm::LoadForm(this->panelContent, loginForm);  
        loginForm->LoginSuccess +=
            gcnew EventHandler(this, &AuthForm::OnLoginSuccess);
        this->labelAuth->Text = L"Không Có Tài Khoản?";
        currentForm = "login";

    } else {
        SignupForm ^ signupForm = gcnew SignupForm();
        LoadChildForm::LoadForm(this->panelContent, signupForm);
        signupForm->SignupSuccess +=
            gcnew EventHandler(this, &AuthForm::OnSignupSuccess);
        this->labelAuth->Text = L"Đăng Nhập";
        // signupForm->AutoScroll = true;
        currentForm = "signup";
    }
    this->labelForgotPw->Visible = true;
}



System::Void AuthForm::loadForm() {
    this->panel1->BackColor = System::Drawing::Color::FromArgb(
        static_cast<System::Int32>(static_cast<System::Byte>(0)),
        static_cast<System::Int32>(static_cast<System::Byte>(64)),
        static_cast<System::Int32>(static_cast<System::Byte>(64)));
}

System::Void AuthForm::OnLoginSuccess(System::Object ^ sender,
                                      System::EventArgs ^ e) {
    User ^ currentUser = GlobalData::GetCurrentUser();
    this->Hide();
    if (currentUser->getRole() == Role::Admin) {
        AdminForm ^ adminForm = gcnew AdminForm();
        adminForm->ShowDialog();
        this->axWindowsMediaPlayer1->Ctlcontrols->pause();
        this->Close();
        return;
    }
    MainForm ^ mainForm = gcnew MainForm();
    mainForm->ShowDialog();
    this->Close();
}
System::Void AuthForm::OnSignupSuccess(System::Object ^ sender,
                                       System::EventArgs ^ e) {
    LoginForm ^ loginForm = gcnew LoginForm();
    loginForm->LoginSuccess +=
        gcnew EventHandler(this, &AuthForm::OnLoginSuccess);
    LoadChildForm::LoadForm(this->panelContent, loginForm);
    this->labelAuth->Text = L"Không Có Tài Khoản?";
}

}; // namespace BankingAppwinform