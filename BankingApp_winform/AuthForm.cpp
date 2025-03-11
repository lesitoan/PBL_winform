#include "AuthForm.h"



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
    this->labelAuth->Text = L"Đăng kí";
}

System::Void AuthForm::labelForgotPw_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew ForgotPwForm());
    this->currentForm = "forgotpw";
    this->labelForgotPw->Visible = false;
    this->labelAuth->Text = L"Đăng nhập";
}

System::Void AuthForm::labelAuth_Click(System::Object ^ sender,
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
        // signupForm->AutoScroll = true;
        currentForm = "signup";
    }
    this->labelForgotPw->Visible = true;
}

System::Void AuthForm::btnDarkMode_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    if (theme == "light") {
        this->panelRightContent->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->theme = "dark";
    } else {
        this->panelRightContent->BackColor = System::Drawing::Color::White;
        this->theme = "light";
    }
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
    if (currentUser->getRole() == "admin") {
        AdminForm ^ adminForm = gcnew AdminForm();
        adminForm->ShowDialog();
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
    this->labelAuth->Text = L"Đăng kí";
}

}; // namespace BankingAppwinform