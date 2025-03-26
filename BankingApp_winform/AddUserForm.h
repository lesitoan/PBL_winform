#pragma once
#include "HandleFile.h"
#include "Services.h"
#include "User.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class AddUserForm : public System::Windows::Forms::Form {
  public:
    AddUserForm(void);

  protected:
    ~AddUserForm();

  private:
    System::Windows::Forms::Label ^ label7;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Panel ^ panel6;
    System::Windows::Forms::TextBox ^ accNum;
    System::Windows::Forms::Panel ^ panel5;
    System::Windows::Forms::TextBox ^ phone;
    System::Windows::Forms::Button ^ btnClose;
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::TextBox ^ name;
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::ComboBox ^ selectAccTypeBox;
    System::Windows::Forms::Panel ^ panelService;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::ComboBox ^ selectServiceBox;
    System::Windows::Forms::Panel ^ panel7;
    System::Windows::Forms::TextBox ^ password;
    System::Windows::Forms::Label ^ label4;
    System::ComponentModel::Container ^ components;

  public:
    event EventHandler ^ createUserSuccess;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panel6 = (gcnew System::Windows::Forms::Panel());
        this->accNum = (gcnew System::Windows::Forms::TextBox());
        this->panel5 = (gcnew System::Windows::Forms::Panel());
        this->phone = (gcnew System::Windows::Forms::TextBox());
        this->btnClose = (gcnew System::Windows::Forms::Button());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->name = (gcnew System::Windows::Forms::TextBox());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectAccTypeBox = (gcnew System::Windows::Forms::ComboBox());
        this->panelService = (gcnew System::Windows::Forms::Panel());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->selectServiceBox = (gcnew System::Windows::Forms::ComboBox());
        this->panel7 = (gcnew System::Windows::Forms::Panel());
        this->password = (gcnew System::Windows::Forms::TextBox());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->panel6->SuspendLayout();
        this->panel5->SuspendLayout();
        this->panel1->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panelService->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel7->SuspendLayout();
        this->SuspendLayout();
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 22, System::Drawing::FontStyle::Bold));
        this->label7->ForeColor = System::Drawing::Color::White;
        this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label7->Location = System::Drawing::Point(232, 36);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(217, 40);
        this->label7->TabIndex = 92;
        this->label7->Text = L"TẠO TÀI KHOẢN";
        this->label7->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label2->ForeColor = System::Drawing::Color::Transparent;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(43, 170);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(93, 22);
        this->label2->TabIndex = 90;
        this->label2->Text = L"Số tài khoản";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(350, 96);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(99, 22);
        this->label1->TabIndex = 89;
        this->label1->Text = L"Số điện thoại";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(43, 96);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(36, 22);
        this->labelAuth->TabIndex = 88;
        this->labelAuth->Text = L"Tên";
        //
        // panel6
        //
        this->panel6->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel6->BackColor = System::Drawing::Color::White;
        this->panel6->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel6->Controls->Add(this->accNum);
        this->panel6->Location = System::Drawing::Point(47, 195);
        this->panel6->Name = L"panel6";
        this->panel6->Size = System::Drawing::Size(266, 37);
        this->panel6->TabIndex = 86;
        //
        // accNum
        //
        this->accNum->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->accNum->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->accNum->Cursor = System::Windows::Forms::Cursors::Hand;
        this->accNum->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->accNum->Location = System::Drawing::Point(18, 6);
        this->accNum->MaxLength = 9;
        this->accNum->Multiline = true;
        this->accNum->Name = L"accNum";
        this->accNum->Size = System::Drawing::Size(246, 26);
        this->accNum->TabIndex = 29;
        //
        // panel5
        //
        this->panel5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel5->BackColor = System::Drawing::Color::White;
        this->panel5->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel5->Controls->Add(this->phone);
        this->panel5->Location = System::Drawing::Point(354, 121);
        this->panel5->Name = L"panel5";
        this->panel5->Size = System::Drawing::Size(266, 37);
        this->panel5->TabIndex = 85;
        //
        // phone
        //
        this->phone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->phone->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->phone->Cursor = System::Windows::Forms::Cursors::Hand;
        this->phone->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->phone->Location = System::Drawing::Point(18, 6);
        this->phone->MaxLength = 40;
        this->phone->Multiline = true;
        this->phone->Name = L"phone";
        this->phone->Size = System::Drawing::Size(246, 26);
        this->phone->TabIndex = 29;
        //
        // btnClose
        //
        this->btnClose->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnClose->BackColor = System::Drawing::Color::RoyalBlue;
        this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClose->FlatAppearance->BorderSize = 0;
        this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClose->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClose->ForeColor = System::Drawing::Color::Bisque;
        this->btnClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnClose->Location = System::Drawing::Point(47, 355);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(265, 48);
        this->btnClose->TabIndex = 84;
        this->btnClose->Text = L"THOÁT";
        this->btnClose->UseVisualStyleBackColor = false;
        this->btnClose->Click +=
            gcnew System::EventHandler(this, &AddUserForm::btnClose_Click);
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::Color::Green;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Bisque;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(350, 355);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(266, 48);
        this->btnSubmit->TabIndex = 83;
        this->btnSubmit->Text = L"OK";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &AddUserForm::btnSubmit_Click);
        //
        // panel1
        //
        this->panel1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel1->Controls->Add(this->name);
        this->panel1->Location = System::Drawing::Point(47, 121);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(266, 37);
        this->panel1->TabIndex = 82;
        //
        // name
        //
        this->name->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->name->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->name->Cursor = System::Windows::Forms::Cursors::Hand;
        this->name->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->name->Location = System::Drawing::Point(18, 6);
        this->name->MaxLength = 40;
        this->name->Multiline = true;
        this->name->Name = L"name";
        this->name->Size = System::Drawing::Size(246, 26);
        this->name->TabIndex = 29;
        //
        // label5
        //
        this->label5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(43, 252);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(108, 22);
        this->label5->TabIndex = 93;
        this->label5->Text = L"Loại tài khoản:";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->selectAccTypeBox);
        this->panel4->Location = System::Drawing::Point(47, 277);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(266, 37);
        this->panel4->TabIndex = 94;
        //
        // selectAccTypeBox
        //
        this->selectAccTypeBox->Anchor =
            System::Windows::Forms::AnchorStyles::Left;
        this->selectAccTypeBox->DropDownStyle =
            System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectAccTypeBox->FlatStyle =
            System::Windows::Forms::FlatStyle::Popup;
        this->selectAccTypeBox->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->selectAccTypeBox->ForeColor = System::Drawing::Color::Black;
        this->selectAccTypeBox->FormattingEnabled = true;
        this->selectAccTypeBox->Items->AddRange(
            gcnew cli::array<System::Object ^>(2){L"user", L"company"});
        this->selectAccTypeBox->Location = System::Drawing::Point(1, 7);
        this->selectAccTypeBox->Name = L"selectAccTypeBox";
        this->selectAccTypeBox->Size = System::Drawing::Size(262, 27);
        this->selectAccTypeBox->TabIndex = 3;
        this->selectAccTypeBox->SelectedIndexChanged +=
            gcnew System::EventHandler(
                this, &AddUserForm::selectAccTypeBox_SelectedIndexChanged);
        //
        // panelService
        //
        this->panelService->Controls->Add(this->label3);
        this->panelService->Controls->Add(this->panel3);
        this->panelService->Location = System::Drawing::Point(344, 238);
        this->panelService->Name = L"panelService";
        this->panelService->Size = System::Drawing::Size(275, 97);
        this->panelService->TabIndex = 95;
        this->panelService->Visible = false;
        //
        // label3
        //
        this->label3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label3->AutoSize = true;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label3->ForeColor = System::Drawing::Color::Transparent;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(2, 17);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(102, 22);
        this->label3->TabIndex = 97;
        this->label3->Text = L"Chọn dịch vụ:";
        //
        // panel3
        //
        this->panel3->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->selectServiceBox);
        this->panel3->Location = System::Drawing::Point(6, 42);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(266, 37);
        this->panel3->TabIndex = 98;
        //
        // selectServiceBox
        //
        this->selectServiceBox->Anchor =
            System::Windows::Forms::AnchorStyles::Left;
        this->selectServiceBox->DropDownStyle =
            System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectServiceBox->FlatStyle =
            System::Windows::Forms::FlatStyle::Popup;
        this->selectServiceBox->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->selectServiceBox->ForeColor = System::Drawing::Color::Black;
        this->selectServiceBox->FormattingEnabled = true;
        this->selectServiceBox->Location = System::Drawing::Point(1, 7);
        this->selectServiceBox->Name = L"selectServiceBox";
        this->selectServiceBox->Size = System::Drawing::Size(262, 27);
        this->selectServiceBox->TabIndex = 3;
        //
        // panel7
        //
        this->panel7->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel7->BackColor = System::Drawing::Color::White;
        this->panel7->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel7->Controls->Add(this->password);
        this->panel7->Location = System::Drawing::Point(354, 195);
        this->panel7->Name = L"panel7";
        this->panel7->Size = System::Drawing::Size(266, 37);
        this->panel7->TabIndex = 86;
        //
        // password
        //
        this->password->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->password->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->password->Cursor = System::Windows::Forms::Cursors::Hand;
        this->password->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->password->Location = System::Drawing::Point(18, 6);
        this->password->MaxLength = 40;
        this->password->Multiline = true;
        this->password->Name = L"password";
        this->password->Size = System::Drawing::Size(246, 26);
        this->password->TabIndex = 29;
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label4->ForeColor = System::Drawing::Color::Transparent;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(350, 170);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(77, 22);
        this->label4->TabIndex = 96;
        this->label4->Text = L"Mật khẩu:";
        //
        // AddUserForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(665, 475);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->panel7);
        this->Controls->Add(this->panelService);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->panel6);
        this->Controls->Add(this->panel5);
        this->Controls->Add(this->btnClose);
        this->Controls->Add(this->btnSubmit);
        this->Controls->Add(this->panel1);
        this->MaximumSize = System::Drawing::Size(681, 514);
        this->MinimumSize = System::Drawing::Size(681, 514);
        this->Name = L"AddUserForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"AddUserForm";
        this->panel6->ResumeLayout(false);
        this->panel6->PerformLayout();
        this->panel5->ResumeLayout(false);
        this->panel5->PerformLayout();
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panelService->ResumeLayout(false);
        this->panelService->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel7->ResumeLayout(false);
        this->panel7->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
  private:
    System::Void btnClose_Click(System::Object ^ sender, System::EventArgs ^ e);

    void loadServiceBox();

    System::Void selectAccTypeBox_SelectedIndexChanged(System::Object ^ sender,
                                                       System::EventArgs ^ e);
    bool isUsedPhoneNumber(String ^ phoneNumber);
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);
};
} // namespace BankingAppwinform
