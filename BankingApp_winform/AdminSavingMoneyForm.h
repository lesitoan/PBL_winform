#pragma once
#include "HandleFile.h"
#include "SavingCustomers.h"
#include "User.h"
#include "SavingCustomersRepository.h"
#include "SavingServices.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for AdminSavingMoneyForm
/// </summary>
public
ref class AdminSavingMoneyForm : public System::Windows::Forms::Form {
  public:
    AdminSavingMoneyForm(void);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~AdminSavingMoneyForm();

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewSavingMoney;

    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::Button ^ btnShowRequest;

  private:
  private:
    System::Windows::Forms::Button ^ btnShowCustomer;

  private:
  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column9;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column4;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column7;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column5;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column6;

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewRequests;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^
        dataGridViewTextBoxColumn1;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^
        dataGridViewTextBoxColumn2;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column8;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^
        dataGridViewTextBoxColumn3;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^
        dataGridViewTextBoxColumn4;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^
        dataGridViewTextBoxColumn5;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle1 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle2 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle3 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle4 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle5 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle6 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        this->dataGridViewSavingMoney =
            (gcnew System::Windows::Forms::DataGridView());
        this->Column1 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column2 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column9 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column3 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column4 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column7 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column5 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column6 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->dataGridViewRequests =
            (gcnew System::Windows::Forms::DataGridView());
        this->dataGridViewTextBoxColumn1 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn2 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column8 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn3 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn4 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn5 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->btnShowRequest = (gcnew System::Windows::Forms::Button());
        this->btnShowCustomer = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewSavingMoney))
            ->BeginInit();
        this->panelContent->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRequests))
            ->BeginInit();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // dataGridViewSavingMoney
        //
        this->dataGridViewSavingMoney->AllowUserToAddRows = false;
        this->dataGridViewSavingMoney->AllowUserToDeleteRows = false;
        dataGridViewCellStyle1->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle1->BackColor = System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
        dataGridViewCellStyle1->SelectionBackColor =
            System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->SelectionForeColor =
            System::Drawing::Color::Transparent;
        this->dataGridViewSavingMoney->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle1;
        this->dataGridViewSavingMoney->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewSavingMoney->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewSavingMoney->CellBorderStyle = System::Windows::
            Forms::DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewSavingMoney->ColumnHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
        dataGridViewCellStyle2->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle2->BackColor = System::Drawing::Color::Teal;
        dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
        dataGridViewCellStyle2->SelectionBackColor =
            System::Drawing::Color::Transparent;
        dataGridViewCellStyle2->SelectionForeColor =
            System::Drawing::Color::White;
        dataGridViewCellStyle2->WrapMode =
            System::Windows::Forms::DataGridViewTriState::True;
        this->dataGridViewSavingMoney->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle2;
        this->dataGridViewSavingMoney->ColumnHeadersHeight = 60;
        this->dataGridViewSavingMoney->Columns->AddRange(
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(8){
                this->Column1, this->Column2, this->Column9, this->Column3,
                this->Column4, this->Column7, this->Column5, this->Column6});
        dataGridViewCellStyle3->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle3->BackColor = System::Drawing::Color::MintCream;
        dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle3->ForeColor =
            System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle3->SelectionBackColor =
            System::Drawing::Color::Cyan;
        dataGridViewCellStyle3->SelectionForeColor =
            System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle3->WrapMode =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewSavingMoney->DefaultCellStyle =
            dataGridViewCellStyle3;
        this->dataGridViewSavingMoney->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->dataGridViewSavingMoney->EnableHeadersVisualStyles = false;
        this->dataGridViewSavingMoney->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewSavingMoney->Location = System::Drawing::Point(0, 0);
        this->dataGridViewSavingMoney->Name = L"dataGridViewSavingMoney";
        this->dataGridViewSavingMoney->ReadOnly = true;
        this->dataGridViewSavingMoney->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewSavingMoney->RowHeadersVisible = false;
        this->dataGridViewSavingMoney->RowHeadersWidth = 51;
        this->dataGridViewSavingMoney->RowTemplate->DefaultCellStyle
            ->BackColor = System::Drawing::Color::White;
        this->dataGridViewSavingMoney->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewSavingMoney->RowTemplate->DefaultCellStyle
            ->ForeColor = System::Drawing::Color::Black;
        this->dataGridViewSavingMoney->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewSavingMoney->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewSavingMoney->RowTemplate->Height = 40;
        this->dataGridViewSavingMoney->RowTemplate->ReadOnly = true;
        this->dataGridViewSavingMoney->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewSavingMoney->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewSavingMoney->Size = System::Drawing::Size(1077, 661);
        this->dataGridViewSavingMoney->TabIndex = 3;
        //
        // Column1
        //
        this->Column1->HeaderText = L"SỐ TK";
        this->Column1->MinimumWidth = 6;
        this->Column1->Name = L"Column1";
        this->Column1->ReadOnly = true;
        //
        // Column2
        //
        this->Column2->HeaderText = L"LOẠI TIẾT KIỆM";
        this->Column2->MinimumWidth = 6;
        this->Column2->Name = L"Column2";
        this->Column2->ReadOnly = true;
        //
        // Column9
        //
        this->Column9->HeaderText = L"LÃI SUẤT";
        this->Column9->MinimumWidth = 6;
        this->Column9->Name = L"Column9";
        this->Column9->ReadOnly = true;
        //
        // Column3
        //
        this->Column3->HeaderText = L"SỐ TIỀN";
        this->Column3->MinimumWidth = 6;
        this->Column3->Name = L"Column3";
        this->Column3->ReadOnly = true;
        //
        // Column4
        //
        this->Column4->HeaderText = L"NGÀY GỬI";
        this->Column4->MinimumWidth = 6;
        this->Column4->Name = L"Column4";
        this->Column4->ReadOnly = true;
        //
        // Column7
        //
        this->Column7->HeaderText = L"SỐ TIỀN THỰC NHẬN";
        this->Column7->MinimumWidth = 6;
        this->Column7->Name = L"Column7";
        this->Column7->ReadOnly = true;
        //
        // Column5
        //
        this->Column5->HeaderText = L"TRẠNG THÁI";
        this->Column5->MinimumWidth = 6;
        this->Column5->Name = L"Column5";
        this->Column5->ReadOnly = true;
        //
        // Column6
        //
        this->Column6->HeaderText = L"NGÀY NHẬN";
        this->Column6->MinimumWidth = 6;
        this->Column6->Name = L"Column6";
        this->Column6->ReadOnly = true;
        //
        // panelContent
        //
        this->panelContent->Controls->Add(this->dataGridViewRequests);
        this->panelContent->Controls->Add(this->dataGridViewSavingMoney);
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(0, 50);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(1077, 661);
        this->panelContent->TabIndex = 5;
        //
        // dataGridViewRequests
        //
        this->dataGridViewRequests->AllowUserToAddRows = false;
        this->dataGridViewRequests->AllowUserToDeleteRows = false;
        dataGridViewCellStyle4->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle4->BackColor = System::Drawing::Color::Transparent;
        dataGridViewCellStyle4->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
        dataGridViewCellStyle4->SelectionBackColor =
            System::Drawing::Color::Transparent;
        dataGridViewCellStyle4->SelectionForeColor =
            System::Drawing::Color::Transparent;
        this->dataGridViewRequests->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle4;
        this->dataGridViewRequests->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewRequests->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewRequests->CellBorderStyle = System::Windows::Forms::
            DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewRequests->ColumnHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
        dataGridViewCellStyle5->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle5->BackColor = System::Drawing::Color::Teal;
        dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle5->ForeColor = System::Drawing::Color::White;
        dataGridViewCellStyle5->SelectionBackColor =
            System::Drawing::Color::Transparent;
        dataGridViewCellStyle5->SelectionForeColor =
            System::Drawing::Color::White;
        dataGridViewCellStyle5->WrapMode =
            System::Windows::Forms::DataGridViewTriState::True;
        this->dataGridViewRequests->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle5;
        this->dataGridViewRequests->ColumnHeadersHeight = 60;
        this->dataGridViewRequests->Columns->AddRange(
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(6){
                this->dataGridViewTextBoxColumn1,
                this->dataGridViewTextBoxColumn2, this->Column8,
                this->dataGridViewTextBoxColumn3,
                this->dataGridViewTextBoxColumn4,
                this->dataGridViewTextBoxColumn5});
        dataGridViewCellStyle6->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle6->BackColor = System::Drawing::Color::MintCream;
        dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle6->ForeColor =
            System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle6->SelectionBackColor =
            System::Drawing::Color::Cyan;
        dataGridViewCellStyle6->SelectionForeColor =
            System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle6->WrapMode =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewRequests->DefaultCellStyle = dataGridViewCellStyle6;
        this->dataGridViewRequests->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->dataGridViewRequests->EnableHeadersVisualStyles = false;
        this->dataGridViewRequests->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewRequests->Location = System::Drawing::Point(0, 0);
        this->dataGridViewRequests->Name = L"dataGridViewRequests";
        this->dataGridViewRequests->ReadOnly = true;
        this->dataGridViewRequests->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewRequests->RowHeadersVisible = false;
        this->dataGridViewRequests->RowHeadersWidth = 51;
        this->dataGridViewRequests->RowTemplate->DefaultCellStyle->BackColor =
            System::Drawing::Color::White;
        this->dataGridViewRequests->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewRequests->RowTemplate->DefaultCellStyle->ForeColor =
            System::Drawing::Color::Black;
        this->dataGridViewRequests->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewRequests->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewRequests->RowTemplate->Height = 40;
        this->dataGridViewRequests->RowTemplate->ReadOnly = true;
        this->dataGridViewRequests->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewRequests->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewRequests->Size = System::Drawing::Size(1077, 661);
        this->dataGridViewRequests->TabIndex = 4;
        this->dataGridViewRequests->Visible = false;
        //
        // dataGridViewTextBoxColumn1
        //
        this->dataGridViewTextBoxColumn1->HeaderText = L"SỐ TK";
        this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
        this->dataGridViewTextBoxColumn1->ReadOnly = true;
        //
        // dataGridViewTextBoxColumn2
        //
        this->dataGridViewTextBoxColumn2->HeaderText = L"LOẠI TIẾT KIỆM";
        this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
        this->dataGridViewTextBoxColumn2->ReadOnly = true;
        //
        // Column8
        //
        this->Column8->HeaderText = L"LÃI SUẤT";
        this->Column8->MinimumWidth = 6;
        this->Column8->Name = L"Column8";
        this->Column8->ReadOnly = true;
        //
        // dataGridViewTextBoxColumn3
        //
        this->dataGridViewTextBoxColumn3->HeaderText = L"SỐ TIỀN";
        this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
        this->dataGridViewTextBoxColumn3->ReadOnly = true;
        //
        // dataGridViewTextBoxColumn4
        //
        this->dataGridViewTextBoxColumn4->HeaderText = L"NGÀY GỬI";
        this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
        this->dataGridViewTextBoxColumn4->ReadOnly = true;
        //
        // dataGridViewTextBoxColumn5
        //
        this->dataGridViewTextBoxColumn5->HeaderText = L"SỐ TIỀN THỰC NHẬN";
        this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
        this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
        this->dataGridViewTextBoxColumn5->ReadOnly = true;
        //
        // btnShowRequest
        //
        this->btnShowRequest->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnShowRequest->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowRequest->FlatAppearance->BorderSize = 0;
        this->btnShowRequest->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnShowRequest->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnShowRequest->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnShowRequest->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnShowRequest->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnShowRequest->Location = System::Drawing::Point(255, 3);
        this->btnShowRequest->Name = L"btnShowRequest";
        this->btnShowRequest->Size = System::Drawing::Size(244, 41);
        this->btnShowRequest->TabIndex = 11;
        this->btnShowRequest->Text = L"YÊU CẦU RÚT TIẾT KIỆM";
        this->btnShowRequest->UseVisualStyleBackColor = false;
        this->btnShowRequest->Click += gcnew System::EventHandler(
            this, &AdminSavingMoneyForm::btnShowRequest_Click);
        //
        // btnShowCustomer
        //
        this->btnShowCustomer->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnShowCustomer->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowCustomer->FlatAppearance->BorderSize = 0;
        this->btnShowCustomer->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnShowCustomer->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnShowCustomer->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnShowCustomer->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnShowCustomer->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnShowCustomer->Location = System::Drawing::Point(0, 3);
        this->btnShowCustomer->Name = L"btnShowCustomer";
        this->btnShowCustomer->Size = System::Drawing::Size(249, 41);
        this->btnShowCustomer->TabIndex = 10;
        this->btnShowCustomer->Text = L"DANH SÁCH KHÁCH HÀNG";
        this->btnShowCustomer->UseVisualStyleBackColor = false;
        this->btnShowCustomer->Click += gcnew System::EventHandler(
            this, &AdminSavingMoneyForm::btnShowCustomer_Click);
        //
        // panel2
        //
        this->panel2->Controls->Add(this->btnShowRequest);
        this->panel2->Controls->Add(this->btnShowCustomer);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel2->Location = System::Drawing::Point(0, 0);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(1077, 50);
        this->panel2->TabIndex = 4;
        //
        // AdminSavingMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panel2);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
        this->Name = L"AdminSavingMoneyForm";
        this->Text = L"AdminSavingMoneyForm";
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewSavingMoney))
            ->EndInit();
        this->panelContent->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRequests))
            ->EndInit();
        this->panel2->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    bool isCellClickEventAttached = false;

  private:
    System::Void btnShowCustomer_Click(System::Object ^ sender,
                                       System::EventArgs ^ e);

  private:
    System::Void btnShowRequest_Click(System::Object ^ sender,
                                      System::EventArgs ^ e);

    void loadSavingCustomers();

    void AdminSavingMoneyForm::loadRequest();

    System::Void dataGridViewRequests_CellClick(
        System::Object ^ sender,
        System::Windows::Forms::DataGridViewCellEventArgs ^ e);
};
} // namespace BankingAppwinform
