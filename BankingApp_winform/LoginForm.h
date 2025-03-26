#pragma once
#include "HandleFile.h"
#include "User.h"
#include "GlobalData.h"
#include "Services.h"

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
    LoginForm(void);
    event EventHandler ^ LoginSuccess;
    

  protected:
    ~LoginForm();

  private:
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::Label ^ label4;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::CheckBox ^ btnShowPw;
    System::Windows::Forms::TextBox ^ phoneNumber;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::TextBox ^ password;
    System::ComponentModel::Container ^ components;


#pragma region Windows Form Designer generated code

    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                LoginForm::typeid));
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->btnShowPw = (gcnew System::Windows::Forms::CheckBox());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
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
        // phoneNumber
        //
        resources->ApplyResources(this->phoneNumber, L"phoneNumber");
        this->phoneNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->phoneNumber->Name = L"phoneNumber";
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->Controls->Add(this->phoneNumber);
        resources->ApplyResources(this->panel1, L"panel1");
        this->panel1->Name = L"panel1";
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->password);
        resources->ApplyResources(this->panel2, L"panel2");
        this->panel2->Name = L"panel2";
        //
        // password
        //
        resources->ApplyResources(this->password, L"password");
        this->password->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->password->Name = L"password";
        //
        // LoginForm
        //
        resources->ApplyResources(this, L"$this");
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->btnShowPw);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->btnSubmit);
        this->Name = L"LoginForm";
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
                                 System::EventArgs ^ e);

  private:
    System::Void btnShowPw_CheckedChanged(System::Object ^ sender,
                                          System::EventArgs ^ e);
};
}
