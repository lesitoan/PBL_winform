#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "User.h"

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
    ChangePwForm(void) { InitializeComponent(); }

  protected:
    ~ChangePwForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  protected:
  private:
  private:
    System::Windows::Forms::Label ^ label6;

  private:
    System::Windows::Forms::TextBox ^ newPasswordConfirm;

  private:
  private:
  private:
  private:
  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::TextBox ^ newPassword;

  private:
  private:
  private:
  private:
  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::TextBox ^ oldPassword;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
  private:
  private:
  private:
  private:
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
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                ChangePwForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->newPasswordConfirm = (gcnew System::Windows::Forms::TextBox());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->newPassword = (gcnew System::Windows::Forms::TextBox());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->oldPassword = (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->label6);
        this->panel1->Controls->Add(this->newPasswordConfirm);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->newPassword);
        this->panel1->Controls->Add(this->label4);
        this->panel1->Controls->Add(this->oldPassword);
        this->panel1->Controls->Add(this->btnSubmit);
        this->panel1->Location = System::Drawing::Point(12, 13);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(602, 358);
        this->panel1->TabIndex = 0;
        //
        // label3
        //
        this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->label3->BackColor = System::Drawing::Color::White;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label3->ForeColor = System::Drawing::Color::Black;
        this->label3->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label3.Image")));
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(480, 206);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(54, 37);
        this->label3->TabIndex = 53;
        this->label3->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->label3->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::label3_Click);
        //
        // label2
        //
        this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->label2->BackColor = System::Drawing::Color::White;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label2->ForeColor = System::Drawing::Color::Black;
        this->label2->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label2.Image")));
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(480, 119);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(54, 37);
        this->label2->TabIndex = 52;
        this->label2->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->label2->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::label2_Click);
        //
        // label1
        //
        this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->label1->BackColor = System::Drawing::Color::White;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Black;
        this->label1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"label1.Image")));
        this->label1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(480, 37);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(54, 37);
        this->label1->TabIndex = 51;
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->label1->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::label1_Click);
        //
        // label6
        //
        this->label6->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label6->AutoSize = true;
        this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label6->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label6->ForeColor = System::Drawing::Color::Transparent;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(88, 181);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(171, 22);
        this->label6->TabIndex = 50;
        this->label6->Text = L"Xác nhận mật khẩu mới:";
        //
        // newPasswordConfirm
        //
        this->newPasswordConfirm->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->newPasswordConfirm->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->newPasswordConfirm->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->newPasswordConfirm->Location = System::Drawing::Point(92, 206);
        this->newPasswordConfirm->Multiline = true;
        this->newPasswordConfirm->Name = L"newPasswordConfirm";
        this->newPasswordConfirm->PasswordChar = '*';
        this->newPasswordConfirm->Size = System::Drawing::Size(392, 37);
        this->newPasswordConfirm->TabIndex = 49;
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(88, 94);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(247, 22);
        this->label5->TabIndex = 47;
        this->label5->Text = L"Nhập mật khẩu mới (ít nhất 6 kí tự):";
        //
        // newPassword
        //
        this->newPassword->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->newPassword->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->newPassword->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->newPassword->Location = System::Drawing::Point(89, 119);
        this->newPassword->Multiline = true;
        this->newPassword->Name = L"newPassword";
        this->newPassword->PasswordChar = '*';
        this->newPassword->Size = System::Drawing::Size(395, 37);
        this->newPassword->TabIndex = 46;
        //
        // label4
        //
        this->label4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label4->AutoSize = true;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label4->ForeColor = System::Drawing::Color::Transparent;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(88, 12);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(116, 22);
        this->label4->TabIndex = 44;
        this->label4->Text = L"Nhập mật khẩu:";
        //
        // oldPassword
        //
        this->oldPassword->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->oldPassword->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->oldPassword->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->oldPassword->Location = System::Drawing::Point(89, 37);
        this->oldPassword->Multiline = true;
        this->oldPassword->Name = L"oldPassword";
        this->oldPassword->PasswordChar = '*';
        this->oldPassword->Size = System::Drawing::Size(395, 37);
        this->oldPassword->TabIndex = 43;
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(92, 280);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(445, 42);
        this->btnSubmit->TabIndex = 42;
        this->btnSubmit->Text = L"THAY ĐỔI";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &ChangePwForm::btnSubmit_Click);
        //
        // ChangePwForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(626, 383);
        this->Controls->Add(this->panel1);
        this->ForeColor = System::Drawing::SystemColors::ControlLight;
        this->Name = L"ChangePwForm";
        this->Text = L"ChangePwForm";
        this->Load +=
            gcnew System::EventHandler(this, &ChangePwForm::ChangePwForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        if (oldPassword->Text == "" || newPassword->Text == "" ||
            newPasswordConfirm->Text == "") {
            MessageBox::Show("Vui long nhap day du thong tin !", "Tiêu đề",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
        } else if (newPassword->Text != newPasswordConfirm->Text) {
            MessageBox::Show("Mat khau moi khong trung khop !", "Tiêu đề",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
        } else if (oldPassword->Text !=
                   GlobalData::GetCurrentUser()->getPassword()) {
            MessageBox::Show("Mat khau khong dung !", "Tiêu đề",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
        } else {
            // luu user vao file
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
            if (users == nullptr) {
                MessageBox::Show("Co loi xay ra !", "Tiêu đề",
                                 MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            } else {
                for (int i = 0; i < users->Length; i++) {
                    if (users[i]->getAccountNumber() ==
                        GlobalData::GetCurrentUser()->getAccountNumber()) {
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

  private:
    bool handleClickShowBtn(bool status,
                            System::Windows::Forms::TextBox ^ textbox) {
        if (status) {
            textbox->PasswordChar = '\0';
        } else {
            textbox->PasswordChar = '*';
        }
        return !status;
    }

    private:
  bool showOldPw = false;
   bool showNewPw = false;
  bool showNewPwConfirm = false;
  private:
    System::Void label1_Click(System::Object ^ sender, System::EventArgs ^ e) {
        if (showOldPw) {
            oldPassword->PasswordChar = '\0';
            showOldPw = false;
        } else {
            oldPassword->PasswordChar = '*';
            showOldPw = true;
        }
    }

  private:
    System::Void label2_Click(System::Object ^ sender, System::EventArgs ^ e) {
        showNewPw = handleClickShowBtn(showNewPw, newPassword);
    }

  private:
    System::Void label3_Click(System::Object ^ sender, System::EventArgs ^ e) {
        showNewPwConfirm = handleClickShowBtn(showNewPwConfirm,
                                           newPasswordConfirm); 
    }
};
} // namespace BankingAppwinform
