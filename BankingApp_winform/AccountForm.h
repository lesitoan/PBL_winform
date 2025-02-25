#pragma once

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for AccountForm
/// </summary>
public
ref class AccountForm : public System::Windows::Forms::Form {
  public:
    AccountForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~AccountForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  protected:
  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::Button ^ btnChangePw;

  private:
    System::Windows::Forms::Label ^ labelAccountNumber;

  private:
  private:
    System::Windows::Forms::Label ^ labelUserName;

  private:
    System::Windows::Forms::Button ^ btnChangePin;

  private:
    System::Windows::Forms::Button ^ btnDeleteAccount;

  private:
    System::Windows::Forms::Panel ^ panelAvatar;

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
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                AccountForm::typeid));
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panelAvatar = (gcnew System::Windows::Forms::Panel());
        this->labelAccountNumber = (gcnew System::Windows::Forms::Label());
        this->labelUserName = (gcnew System::Windows::Forms::Label());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->btnChangePin = (gcnew System::Windows::Forms::Button());
        this->btnDeleteAccount = (gcnew System::Windows::Forms::Button());
        this->btnChangePw = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel3->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->panelAvatar);
        this->panel1->Controls->Add(this->labelAccountNumber);
        this->panel1->Controls->Add(this->labelUserName);
        this->panel1->Location = System::Drawing::Point(37, 24);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(500, 82);
        this->panel1->TabIndex = 0;
        //
        // panelAvatar
        //
        this->panelAvatar->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelAvatar->BackgroundImage =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"panelAvatar.BackgroundImage")));
        this->panelAvatar->Location = System::Drawing::Point(432, 10);
        this->panelAvatar->Name = L"panelAvatar";
        this->panelAvatar->Size = System::Drawing::Size(56, 55);
        this->panelAvatar->TabIndex = 2;
        //
        // labelAccountNumber
        //
        this->labelAccountNumber->AutoSize = true;
        this->labelAccountNumber->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->labelAccountNumber->Location = System::Drawing::Point(21, 44);
        this->labelAccountNumber->Name = L"labelAccountNumber";
        this->labelAccountNumber->Size = System::Drawing::Size(87, 21);
        this->labelAccountNumber->TabIndex = 1;
        this->labelAccountNumber->Text = L"123456789";
        //
        // labelUserName
        //
        this->labelUserName->AutoSize = true;
        this->labelUserName->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 14.25F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelUserName->Location = System::Drawing::Point(21, 10);
        this->labelUserName->Name = L"labelUserName";
        this->labelUserName->Size = System::Drawing::Size(96, 24);
        this->labelUserName->TabIndex = 0;
        this->labelUserName->Text = L"Le Si Toan";
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel2->Location = System::Drawing::Point(195, 125);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(342, 238);
        this->panel2->TabIndex = 1;
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel3->Controls->Add(this->btnChangePin);
        this->panel3->Controls->Add(this->btnDeleteAccount);
        this->panel3->Controls->Add(this->btnChangePw);
        this->panel3->Location = System::Drawing::Point(37, 125);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(140, 238);
        this->panel3->TabIndex = 2;
        //
        // btnChangePin
        //
        this->btnChangePin->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnChangePin->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnChangePin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnChangePin->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnChangePin->ForeColor = System::Drawing::Color::Black;
        this->btnChangePin->Location = System::Drawing::Point(16, 63);
        this->btnChangePin->Name = L"btnChangePin";
        this->btnChangePin->Size = System::Drawing::Size(109, 29);
        this->btnChangePin->TabIndex = 5;
        this->btnChangePin->Text = L"Doi PIN";
        this->btnChangePin->UseVisualStyleBackColor = false;
        //
        // btnDeleteAccount
        //
        this->btnDeleteAccount->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnDeleteAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnDeleteAccount->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnDeleteAccount->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnDeleteAccount->ForeColor = System::Drawing::Color::Black;
        this->btnDeleteAccount->Location = System::Drawing::Point(16, 108);
        this->btnDeleteAccount->Name = L"btnDeleteAccount";
        this->btnDeleteAccount->Size = System::Drawing::Size(109, 29);
        this->btnDeleteAccount->TabIndex = 4;
        this->btnDeleteAccount->Text = L"Xoa tai khoan";
        this->btnDeleteAccount->UseVisualStyleBackColor = false;
        //
        // btnChangePw
        //
        this->btnChangePw->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnChangePw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnChangePw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnChangePw->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnChangePw->ForeColor = System::Drawing::Color::Black;
        this->btnChangePw->Location = System::Drawing::Point(16, 18);
        this->btnChangePw->Name = L"btnChangePw";
        this->btnChangePw->Size = System::Drawing::Size(109, 29);
        this->btnChangePw->TabIndex = 3;
        this->btnChangePw->Text = L"Doi mat khau";
        this->btnChangePw->UseVisualStyleBackColor = false;
        //
        // AccountForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(568, 393);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Name = L"AccountForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"AccountForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion
};
} // namespace BankingAppwinform
