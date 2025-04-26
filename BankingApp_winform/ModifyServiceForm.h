#pragma once
#include "Services.h"
#include "User.h"
#include "ServiceServices.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class ModifyServiceForm : public System::Windows::Forms::Form {
  public:
    ModifyServiceForm(String ^ type);

  protected:
    ~ModifyServiceForm();

  private:
    System::Windows::Forms::Label ^ header;
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::Button ^ btnClose;
    System::Windows::Forms::Panel ^ panelAdd;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::TextBox ^ serviceName;
    System::Windows::Forms::Label ^ labelAuth;
    System::Windows::Forms::Panel ^ panelDelete;
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::ComboBox ^ selectServiceBox;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModifyServiceForm::typeid));
        this->header = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->btnClose = (gcnew System::Windows::Forms::Button());
        this->panelAdd = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->serviceName = (gcnew System::Windows::Forms::TextBox());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panelDelete = (gcnew System::Windows::Forms::Panel());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectServiceBox = (gcnew System::Windows::Forms::ComboBox());
        this->panelAdd->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panelDelete->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // header
        //
        this->header->AutoSize = true;
        this->header->BackColor = System::Drawing::Color::Transparent;
        this->header->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 22, System::Drawing::FontStyle::Bold));
        this->header->ForeColor = System::Drawing::Color::White;
        this->header->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->header->Location = System::Drawing::Point(308, 48);
        this->header->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->header->Name = L"header";
        this->header->Size = System::Drawing::Size(242, 48);
        this->header->TabIndex = 32;
        this->header->Text = L"THÊM DỊCH VỤ";
        this->header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::Color::Green;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::White;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(457, 247);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(285, 52);
        this->btnSubmit->TabIndex = 31;
        this->btnSubmit->Text = L"THÊM";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(this, &ModifyServiceForm::btnSubmit_Click);
        //
        // btnClose
        //
        this->btnClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                                                                     static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClose->FlatAppearance->BorderSize = 0;
        this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClose->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClose->ForeColor = System::Drawing::Color::White;
        this->btnClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnClose->Location = System::Drawing::Point(149, 247);
        this->btnClose->Margin = System::Windows::Forms::Padding(4);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(275, 52);
        this->btnClose->TabIndex = 35;
        this->btnClose->Text = L"THOÁT";
        this->btnClose->UseVisualStyleBackColor = false;
        this->btnClose->Click += gcnew System::EventHandler(this, &ModifyServiceForm::btnClose_Click);
        //
        // panelAdd
        //
        this->panelAdd->BackColor = System::Drawing::Color::Transparent;
        this->panelAdd->Controls->Add(this->panel2);
        this->panelAdd->Controls->Add(this->labelAuth);
        this->panelAdd->Location = System::Drawing::Point(149, 118);
        this->panelAdd->Margin = System::Windows::Forms::Padding(4);
        this->panelAdd->Name = L"panelAdd";
        this->panelAdd->Size = System::Drawing::Size(593, 102);
        this->panelAdd->TabIndex = 36;
        this->panelAdd->Visible = false;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->serviceName);
        this->panel2->Location = System::Drawing::Point(4, 43);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(589, 46);
        this->panel2->TabIndex = 36;
        //
        // serviceName
        //
        this->serviceName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->serviceName->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->serviceName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->serviceName->Location = System::Drawing::Point(24, 7);
        this->serviceName->Margin = System::Windows::Forms::Padding(4);
        this->serviceName->MaxLength = 30;
        this->serviceName->Multiline = true;
        this->serviceName->Name = L"serviceName";
        this->serviceName->Size = System::Drawing::Size(565, 34);
        this->serviceName->TabIndex = 29;
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(-1, 12);
        this->labelAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(116, 27);
        this->labelAuth->TabIndex = 35;
        this->labelAuth->Text = L"Tên dịch vụ:";
        //
        // panelDelete
        //
        this->panelDelete->BackColor = System::Drawing::Color::Transparent;
        this->panelDelete->Controls->Add(this->label5);
        this->panelDelete->Controls->Add(this->panel4);
        this->panelDelete->Location = System::Drawing::Point(137, 101);
        this->panelDelete->Margin = System::Windows::Forms::Padding(4);
        this->panelDelete->Name = L"panelDelete";
        this->panelDelete->Size = System::Drawing::Size(681, 121);
        this->panelDelete->TabIndex = 37;
        this->panelDelete->Visible = false;
        //
        // label5
        //
        this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->BackColor = System::Drawing::Color::Transparent;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(11, 17);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(196, 27);
        this->label5->TabIndex = 60;
        this->label5->Text = L"Chọn dịch vụ cần xóa:";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->selectServiceBox);
        this->panel4->Location = System::Drawing::Point(16, 53);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(589, 46);
        this->panel4->TabIndex = 61;
        //
        // selectServiceBox
        //
        this->selectServiceBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->selectServiceBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectServiceBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
        this->selectServiceBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
        this->selectServiceBox->ForeColor = System::Drawing::Color::Black;
        this->selectServiceBox->FormattingEnabled = true;
        this->selectServiceBox->Location = System::Drawing::Point(4, 7);
        this->selectServiceBox->Margin = System::Windows::Forms::Padding(4);
        this->selectServiceBox->Name = L"selectServiceBox";
        this->selectServiceBox->Size = System::Drawing::Size(584, 33);
        this->selectServiceBox->TabIndex = 3;
        //
        // ModifyServiceForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(876, 398);
        this->Controls->Add(this->panelDelete);
        this->Controls->Add(this->panelAdd);
        this->Controls->Add(this->btnClose);
        this->Controls->Add(this->header);
        this->Controls->Add(this->btnSubmit);
        this->Icon = (cli::safe_cast<System::Drawing::Icon ^>(resources->GetObject(L"$this.Icon")));
        this->Margin = System::Windows::Forms::Padding(4);
        this->MaximumSize = System::Drawing::Size(894, 445);
        this->MinimumSize = System::Drawing::Size(894, 445);
        this->Name = L"ModifyServiceForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"ModifyServiceForm";
        this->panelAdd->ResumeLayout(false);
        this->panelAdd->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panelDelete->ResumeLayout(false);
        this->panelDelete->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
  public:
    event EventHandler ^ ModifyServiceSuccess;

  private:
    String ^ type;

  private:
    System::Void btnClose_Click(System::Object ^ sender, System::EventArgs ^ e);

    void loadServiceBox();

    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);
};
} // namespace BankingAppwinform
