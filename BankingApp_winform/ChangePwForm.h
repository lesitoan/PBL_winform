#pragma once
#include "GlobalData.h"
#include "User.h"
#include "HandleFile.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class ChangePwForm : public System::Windows::Forms::Form {
  public:
    ChangePwForm(void) {
        InitializeComponent();
    }

  protected:
    ~ChangePwForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::TextBox ^ oldPassword;
    System::Windows::Forms::TextBox ^ newPasswordConfirm;
    System::Windows::Forms::TextBox ^ newPassword;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Label ^ label3;

  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->oldPassword = (gcnew System::Windows::Forms::TextBox());
        this->newPasswordConfirm = (gcnew System::Windows::Forms::TextBox());
        this->newPassword = (gcnew System::Windows::Forms::TextBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->SuspendLayout();
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
        this->label2->Location = System::Drawing::Point(9, 9);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(63, 17);
        this->label2->TabIndex = 24;
        this->label2->Text = L"Mat khau:";
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
        this->btnSubmit->Location = System::Drawing::Point(93, 163);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(135, 24);
        this->btnSubmit->TabIndex = 23;
        this->btnSubmit->Text = L"Doi mat khau";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::btnSubmit_Click);
        //
        // oldPassword
        //
        this->oldPassword->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->oldPassword->Location = System::Drawing::Point(12, 29);
        this->oldPassword->Name = L"oldPassword";
        this->oldPassword->PasswordChar = '*';
        this->oldPassword->Size = System::Drawing::Size(302, 23);
        this->oldPassword->TabIndex = 27;
        //
        // newPasswordConfirm
        //
        this->newPasswordConfirm->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->newPasswordConfirm->Location = System::Drawing::Point(12, 121);
        this->newPasswordConfirm->Name = L"newPasswordConfirm";
        this->newPasswordConfirm->PasswordChar = '*';
        this->newPasswordConfirm->Size = System::Drawing::Size(302, 23);
        this->newPasswordConfirm->TabIndex = 28;
        //
        // newPassword
        //
        this->newPassword->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->newPassword->Location = System::Drawing::Point(12, 75);
        this->newPassword->Name = L"newPassword";
        this->newPassword->PasswordChar = '*';
        this->newPassword->Size = System::Drawing::Size(302, 23);
        this->newPassword->TabIndex = 29;
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
        this->label1->Location = System::Drawing::Point(9, 55);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(89, 17);
        this->label1->TabIndex = 30;
        this->label1->Text = L"Mat khau moi:";
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->ForeColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->label3->Location = System::Drawing::Point(9, 101);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(147, 17);
        this->label3->TabIndex = 31;
        this->label3->Text = L"Xac nhan mat khau moi:";
        //
        // ChangePwForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(326, 199);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->newPassword);
        this->Controls->Add(this->newPasswordConfirm);
        this->Controls->Add(this->oldPassword);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->btnSubmit);
        this->ForeColor = System::Drawing::SystemColors::ControlLight;
        this->Name = L"ChangePwForm";
        this->Text = L"ChangePwForm";
        this->Load +=
            gcnew System::EventHandler(this, &ChangePwForm::ChangePwForm_Load);
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        if (oldPassword->Text == "" || newPassword->Text == "" ||
            newPasswordConfirm->Text == "") {
            MessageBox::Show("Vui long nhap day du thong tin !", "Tiêu đề", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        } else if (newPassword->Text != newPasswordConfirm->Text) {
            MessageBox::Show("Mat khau moi khong trung khop !", "Tiêu đề",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
        } else if (oldPassword->Text != GlobalData::GetCurrentUser()->getPassword()) {
            MessageBox::Show("Mat khau khong dung !", "Tiêu đề",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
                    if (users[i]->getAccountNumber() == GlobalData::GetCurrentUser()->getAccountNumber()) {
                        users[i]->setPassword(newPassword->Text);
                        GlobalData::SetCurrentUser(users[i]);
                        break;
                    }
                }
            }
            bool isSaved = HandleFile::WriteUserArray(users, "users.dat");
            if (isSaved) {
                MessageBox::Show("Doi mat khau thanh cong !", "Tiêu đề",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Information);
            } else {
                MessageBox::Show("Co loi xay ra !", "Tiêu đề",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    }

  private:
    System::Void ChangePwForm_Load(System::Object ^ sender,
                                   System::EventArgs ^ e) {}
};
} // namespace BankingAppwinform
