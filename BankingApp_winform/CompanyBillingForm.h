#pragma once

#include "GlobalData.h"
#include "RecurringPayments.h"
#include "User.h"
#include "CustomerCodes.h"
#include "Notifications.h"

#include "RecurringPaymentServices.h"

#include <cstdlib>
#include <ctime>


ref class AdminForm;
namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class CompanyBillingForm : public System::Windows::Forms::Form {
  public:
    CompanyBillingForm(String^ companyAccountNumber);

  protected:
    ~CompanyBillingForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Button ^ btnLoadRecurring;

    System::Windows::Forms::Button ^ btnAccount;
    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewRecurring;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column7;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column8;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column10;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column11;












    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CompanyBillingForm::typeid));
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->btnAccount = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->btnLoadRecurring = (gcnew System::Windows::Forms::Button());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->dataGridViewRecurring = (gcnew System::Windows::Forms::DataGridView());
        this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panelContent->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->dataGridViewRecurring))->BeginInit();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->Controls->Add(this->btnAccount);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(1436, 54);
        this->panel1->TabIndex = 0;
        //
        // btnAccount
        //
        this->btnAccount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left));
        this->btnAccount->BackColor = System::Drawing::Color::Transparent;
        this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAccount->FlatAppearance->BorderSize = 0;
        this->btnAccount->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Teal;
        this->btnAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAccount->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnAccount->ForeColor = System::Drawing::SystemColors::ControlText;
        this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image ^>(resources->GetObject(L"btnAccount.Image")));
        this->btnAccount->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->Location = System::Drawing::Point(4, 0);
        this->btnAccount->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnAccount->Name = L"btnAccount";
        this->btnAccount->Size = System::Drawing::Size(195, 52);
        this->btnAccount->TabIndex = 3;
        this->btnAccount->Text = L"              Quay lại";
        this->btnAccount->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->UseVisualStyleBackColor = false;
        this->btnAccount->Click += gcnew System::EventHandler(this, &CompanyBillingForm::OnUndoClick);
        //
        // panel2
        //
        this->panel2->Controls->Add(this->btnLoadRecurring);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel2->Location = System::Drawing::Point(0, 54);
        this->panel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(1436, 62);
        this->panel2->TabIndex = 1;
        //
        // btnLoadRecurring
        //
        this->btnLoadRecurring->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
        this->btnLoadRecurring->BackColor = System::Drawing::Color::Indigo;
        this->btnLoadRecurring->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLoadRecurring->FlatAppearance->BorderSize = 0;
        this->btnLoadRecurring->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Teal;
        this->btnLoadRecurring->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnLoadRecurring->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnLoadRecurring->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnLoadRecurring->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLoadRecurring->Location = System::Drawing::Point(4, 4);
        this->btnLoadRecurring->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnLoadRecurring->Name = L"btnLoadRecurring";
        this->btnLoadRecurring->Size = System::Drawing::Size(1428, 50);
        this->btnLoadRecurring->TabIndex = 11;
        this->btnLoadRecurring->Text = L"THANH TOÁN ĐỊNH KÌ";
        this->btnLoadRecurring->UseVisualStyleBackColor = false;
        //
        // panelContent
        //
        this->panelContent->Controls->Add(this->dataGridViewRecurring);
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(0, 116);
        this->panelContent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(1436, 759);
        this->panelContent->TabIndex = 2;
        //
        // dataGridViewRecurring
        //
        this->dataGridViewRecurring->AllowUserToAddRows = false;
        this->dataGridViewRecurring->AllowUserToDeleteRows = false;
        dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle1->BackColor = System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
        dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::Transparent;
        this->dataGridViewRecurring->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
        this->dataGridViewRecurring->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewRecurring->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewRecurring->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewRecurring->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
        dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle2->BackColor = System::Drawing::Color::MediumOrchid;
        dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                                                    static_cast<System::Byte>(0)));
        dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
        dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                                                                                      static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
        dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
        this->dataGridViewRecurring->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
        this->dataGridViewRecurring->ColumnHeadersHeight = 40;
        this->dataGridViewRecurring->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(4){this->Column7,
                                                                                                                         this->Column8, this->Column10, this->Column11});
        dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle3->BackColor = System::Drawing::Color::MintCream;
        dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                    static_cast<System::Byte>(0)));
        dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::Cyan;
        dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewRecurring->DefaultCellStyle = dataGridViewCellStyle3;
        this->dataGridViewRecurring->Dock = System::Windows::Forms::DockStyle::Fill;
        this->dataGridViewRecurring->EnableHeadersVisualStyles = false;
        this->dataGridViewRecurring->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewRecurring->Location = System::Drawing::Point(0, 0);
        this->dataGridViewRecurring->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->dataGridViewRecurring->Name = L"dataGridViewRecurring";
        this->dataGridViewRecurring->ReadOnly = true;
        this->dataGridViewRecurring->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewRecurring->RowHeadersVisible = false;
        this->dataGridViewRecurring->RowHeadersWidth = 51;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::White;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewRecurring->RowTemplate->Height = 40;
        this->dataGridViewRecurring->RowTemplate->ReadOnly = true;
        this->dataGridViewRecurring->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewRecurring->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewRecurring->Size = System::Drawing::Size(1436, 759);
        this->dataGridViewRecurring->TabIndex = 6;
        //
        // Column7
        //
        this->Column7->HeaderText = L"Mã KH";
        this->Column7->MinimumWidth = 6;
        this->Column7->Name = L"Column7";
        this->Column7->ReadOnly = true;
        //
        // Column8
        //
        this->Column8->HeaderText = L"Tên Người TT";
        this->Column8->MinimumWidth = 6;
        this->Column8->Name = L"Column8";
        this->Column8->ReadOnly = true;
        //
        // Column10
        //
        this->Column10->HeaderText = L"Số TK người TT";
        this->Column10->MinimumWidth = 6;
        this->Column10->Name = L"Column10";
        this->Column10->ReadOnly = true;
        //
        // Column11
        //
        this->Column11->HeaderText = L"Ngày đến hạn";
        this->Column11->MinimumWidth = 6;
        this->Column11->Name = L"Column11";
        this->Column11->ReadOnly = true;
        //
        // CompanyBillingForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1436, 875);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->Name = L"CompanyBillingForm";
        this->Text = L"CompanyBillingForm";
        this->panel1->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->panelContent->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->dataGridViewRecurring))->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion

  private:

    void loadRecurringPaymentData(String ^ companyAccNumber);

    System::Void dataGridViewRecurring_CellClick(System::Object ^ sender,
                                                 DataGridViewCellEventArgs ^ e);
    void OnUndoClick(Object ^ sender, EventArgs ^ e);
};
} // namespace BankingAppwinform
