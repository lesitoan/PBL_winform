#pragma once
#include "PaymentCodes.h"
#include "RecurringPayments.h"
#include "HandleFile.h"

ref class AdminForm;
namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for CompanyBillingForm
/// </summary>
public
ref class CompanyBillingForm : public System::Windows::Forms::Form {
  public:
    CompanyBillingForm(int companyAccountNumber);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~CompanyBillingForm();

  private:
    System::Windows::Forms::Panel ^ panel1;

  protected:
  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Button ^ btnLoadRecurring;

  private:


  private:


  private:
    System::Windows::Forms::Button ^ btnShowCode;

  private:


  private:
    System::Windows::Forms::Button ^ btnAccount;

  private:
    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewCodes;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column4;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column5;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column6;

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewRecurring;

  private:


  private:


  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column7;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column8;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column9;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column10;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column11;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column12;

  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                CompanyBillingForm::typeid));
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
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->btnAccount = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->btnLoadRecurring = (gcnew System::Windows::Forms::Button());
        this->btnShowCode = (gcnew System::Windows::Forms::Button());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->dataGridViewRecurring =
            (gcnew System::Windows::Forms::DataGridView());
        this->Column7 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column8 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column9 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column10 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column11 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column12 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewCodes =
            (gcnew System::Windows::Forms::DataGridView());
        this->Column1 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column2 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column3 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column4 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column5 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column6 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panelContent->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewCodes))
            ->BeginInit();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->Controls->Add(this->btnAccount);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(1077, 44);
        this->panel1->TabIndex = 0;
        //
        // btnAccount
        //
        this->btnAccount->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Bottom) |
                 System::Windows::Forms::AnchorStyles::Left));
        this->btnAccount->BackColor = System::Drawing::Color::Transparent;
        this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAccount->FlatAppearance->BorderSize = 0;
        this->btnAccount->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAccount->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnAccount->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnAccount.Image")));
        this->btnAccount->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->Location = System::Drawing::Point(3, 0);
        this->btnAccount->Name = L"btnAccount";
        this->btnAccount->Size = System::Drawing::Size(73, 42);
        this->btnAccount->TabIndex = 3;
        this->btnAccount->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->UseVisualStyleBackColor = false;
        this->btnAccount->Click += gcnew System::EventHandler(
            this, &CompanyBillingForm::btnAccount_Click);
        //
        // panel2
        //
        this->panel2->Controls->Add(this->btnLoadRecurring);
        this->panel2->Controls->Add(this->btnShowCode);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel2->Location = System::Drawing::Point(0, 44);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(1077, 50);
        this->panel2->TabIndex = 1;
        //
        // btnLoadRecurring
        //
        this->btnLoadRecurring->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnLoadRecurring->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLoadRecurring->FlatAppearance->BorderSize = 0;
        this->btnLoadRecurring->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnLoadRecurring->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnLoadRecurring->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnLoadRecurring->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnLoadRecurring->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLoadRecurring->Location = System::Drawing::Point(189, 3);
        this->btnLoadRecurring->Name = L"btnLoadRecurring";
        this->btnLoadRecurring->Size = System::Drawing::Size(169, 41);
        this->btnLoadRecurring->TabIndex = 11;
        this->btnLoadRecurring->Text = L"THANH TOÁN ĐỊNH KÌ";
        this->btnLoadRecurring->UseVisualStyleBackColor = false;
        this->btnLoadRecurring->Click += gcnew System::EventHandler(
            this, &CompanyBillingForm::btnLoadRecurring_Click);
        //
        // btnShowCode
        //
        this->btnShowCode->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnShowCode->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowCode->FlatAppearance->BorderSize = 0;
        this->btnShowCode->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnShowCode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnShowCode->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnShowCode->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnShowCode->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnShowCode->Location = System::Drawing::Point(0, 3);
        this->btnShowCode->Name = L"btnShowCode";
        this->btnShowCode->Size = System::Drawing::Size(183, 41);
        this->btnShowCode->TabIndex = 10;
        this->btnShowCode->Text = L"MÃ CODE THANH TOÁN";
        this->btnShowCode->UseVisualStyleBackColor = false;
        this->btnShowCode->Click += gcnew System::EventHandler(
            this, &CompanyBillingForm::btnShowCode_Click);
        //
        // panelContent
        //
        this->panelContent->Controls->Add(this->dataGridViewRecurring);
        this->panelContent->Controls->Add(this->dataGridViewCodes);
        this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panelContent->Location = System::Drawing::Point(0, 94);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(1077, 617);
        this->panelContent->TabIndex = 2;
        //
        // dataGridViewRecurring
        //
        this->dataGridViewRecurring->AllowUserToAddRows = false;
        this->dataGridViewRecurring->AllowUserToDeleteRows = false;
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
        this->dataGridViewRecurring->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle1;
        this->dataGridViewRecurring->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewRecurring->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewRecurring->CellBorderStyle = System::Windows::Forms::
            DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewRecurring->ColumnHeadersBorderStyle =
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
        this->dataGridViewRecurring->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle2;
        this->dataGridViewRecurring->ColumnHeadersHeight = 40;
        this->dataGridViewRecurring->Columns->AddRange(
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(6){
                this->Column7, this->Column8, this->Column9, this->Column10,
                this->Column11, this->Column12});
        dataGridViewCellStyle3->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle3->BackColor = System::Drawing::Color::MintCream;
        dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 12, System::Drawing::FontStyle::Regular,
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
        this->dataGridViewRecurring->DefaultCellStyle = dataGridViewCellStyle3;
        this->dataGridViewRecurring->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->dataGridViewRecurring->EnableHeadersVisualStyles = false;
        this->dataGridViewRecurring->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewRecurring->Location = System::Drawing::Point(0, 0);
        this->dataGridViewRecurring->Name = L"dataGridViewRecurring";
        this->dataGridViewRecurring->ReadOnly = true;
        this->dataGridViewRecurring->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewRecurring->RowHeadersVisible = false;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->BackColor =
            System::Drawing::Color::White;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->ForeColor =
            System::Drawing::Color::Black;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewRecurring->RowTemplate->Height = 40;
        this->dataGridViewRecurring->RowTemplate->ReadOnly = true;
        this->dataGridViewRecurring->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewRecurring->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewRecurring->Size = System::Drawing::Size(1077, 617);
        this->dataGridViewRecurring->TabIndex = 4;
        this->dataGridViewRecurring->Visible = false;
        //
        // Column7
        //
        this->Column7->HeaderText = L"ID";
        this->Column7->Name = L"Column7";
        this->Column7->ReadOnly = true;
        //
        // Column8
        //
        this->Column8->HeaderText = L"STK KH";
        this->Column8->Name = L"Column8";
        this->Column8->ReadOnly = true;
        //
        // Column9
        //
        this->Column9->HeaderText = L"Số tiền";
        this->Column9->Name = L"Column9";
        this->Column9->ReadOnly = true;
        //
        // Column10
        //
        this->Column10->HeaderText = L"TTĐK theo";
        this->Column10->Name = L"Column10";
        this->Column10->ReadOnly = true;
        //
        // Column11
        //
        this->Column11->HeaderText = L"Ngày đến hạn";
        this->Column11->Name = L"Column11";
        this->Column11->ReadOnly = true;
        //
        // Column12
        //
        this->Column12->HeaderText = L"Trạng thái";
        this->Column12->Name = L"Column12";
        this->Column12->ReadOnly = true;
        //
        // dataGridViewCodes
        //
        this->dataGridViewCodes->AllowUserToAddRows = false;
        this->dataGridViewCodes->AllowUserToDeleteRows = false;
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
        this->dataGridViewCodes->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle4;
        this->dataGridViewCodes->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewCodes->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewCodes->CellBorderStyle = System::Windows::Forms::
            DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewCodes->ColumnHeadersBorderStyle =
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
        this->dataGridViewCodes->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle5;
        this->dataGridViewCodes->ColumnHeadersHeight = 40;
        this->dataGridViewCodes->Columns->AddRange(
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(6){
                this->Column1, this->Column2, this->Column3, this->Column4,
                this->Column5, this->Column6});
        dataGridViewCellStyle6->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle6->BackColor = System::Drawing::Color::MintCream;
        dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 12, System::Drawing::FontStyle::Regular,
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
        this->dataGridViewCodes->DefaultCellStyle = dataGridViewCellStyle6;
        this->dataGridViewCodes->Dock = System::Windows::Forms::DockStyle::Fill;
        this->dataGridViewCodes->EnableHeadersVisualStyles = false;
        this->dataGridViewCodes->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewCodes->Location = System::Drawing::Point(0, 0);
        this->dataGridViewCodes->Name = L"dataGridViewCodes";
        this->dataGridViewCodes->ReadOnly = true;
        this->dataGridViewCodes->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewCodes->RowHeadersVisible = false;
        this->dataGridViewCodes->RowTemplate->DefaultCellStyle->BackColor =
            System::Drawing::Color::White;
        this->dataGridViewCodes->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewCodes->RowTemplate->DefaultCellStyle->ForeColor =
            System::Drawing::Color::Black;
        this->dataGridViewCodes->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewCodes->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewCodes->RowTemplate->Height = 40;
        this->dataGridViewCodes->RowTemplate->ReadOnly = true;
        this->dataGridViewCodes->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewCodes->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewCodes->Size = System::Drawing::Size(1077, 617);
        this->dataGridViewCodes->TabIndex = 3;
        //
        // Column1
        //
        this->Column1->HeaderText = L"ID";
        this->Column1->Name = L"Column1";
        this->Column1->ReadOnly = true;
        //
        // Column2
        //
        this->Column2->HeaderText = L"Mã CODE";
        this->Column2->Name = L"Column2";
        this->Column2->ReadOnly = true;
        //
        // Column3
        //
        this->Column3->HeaderText = L"Số tiền";
        this->Column3->Name = L"Column3";
        this->Column3->ReadOnly = true;
        //
        // Column4
        //
        this->Column4->HeaderText = L"Trạng thái";
        this->Column4->Name = L"Column4";
        this->Column4->ReadOnly = true;
        //
        // Column5
        //
        this->Column5->HeaderText = L"Ngày tạo";
        this->Column5->Name = L"Column5";
        this->Column5->ReadOnly = true;
        //
        // Column6
        //
        this->Column6->HeaderText = L"Ngày hết hạn";
        this->Column6->Name = L"Column6";
        this->Column6->ReadOnly = true;
        //
        // CompanyBillingForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->panelContent);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"CompanyBillingForm";
        this->Text = L"CompanyBillingForm";
        this->panel1->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->panelContent->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewCodes))
            ->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion


    void LoadPaymentCodes(int companyAccountNumber) {
        dataGridViewCodes->Rows->Clear();

        array<PaymentCodes ^> ^ paymentCodes = HandleFile::ReadCodeArray("codes.dat");
        if (paymentCodes == nullptr || paymentCodes->Length == 0)
            return;

        for each (PaymentCodes ^ code in paymentCodes) {
            if (code->CompanyAccountNumber != companyAccountNumber)
                continue;

            dataGridViewCodes->Rows->Add(
                code->CompanyAccountNumber, code->Code,
                code->Amount.ToString(
                    "N0"), // Hiển thị số có dấu phân cách (VD: 10,000)
                code->Status == 0 ? L"Chưa thanh toán" : L"Đã thanh toán",
                code->CreatedDate.ToString("dd/MM/yyyy"),
                code->ExpiredDate.ToString("dd/MM/yyyy"));
        }
    }

  array<RecurringPayments ^> ^
      GetFakeRecurringPayments() {
          array<RecurringPayments ^> ^ recurringPayments =
              gcnew array<RecurringPayments ^>(20);

          array<String ^> ^ frequencies = {"monthly", "quarterly", "yearly"};
          array<int> ^ statuses = {0, 1}; // 0 = pending, 1 = complete

          Random ^ rand = gcnew Random();

          for (int i = 0; i < 20; i++) {
              recurringPayments[i] = gcnew RecurringPayments(
                  i + 1, // id
                  rand->Next(
                      100000,
                      999999), // userAccountNumber (tài khoản ngẫu nhiên)
                  (i % 5) + 1, // companyId (chia ngẫu nhiên 5 công ty)
                  (rand->Next(1, 20) * 50000), // amount (50,000 - 1,000,000)
                  frequencies[rand->Next(
                      0, 3)], // frequency (monthly, quarterly, yearly)
                  DateTime(2025, 3, rand->Next(1, 29)), // paymentDay (1-28)
                  statuses[rand->Next(0, 2)] // status (pending hoặc complete)
              );
          }

          return recurringPayments;
      }

  void LoadRecurringPayments() {
        dataGridViewRecurring->Rows->Clear(); // Xóa dữ liệu cũ nếu có

        array<RecurringPayments ^> ^ recurringPayments =
            GetFakeRecurringPayments();

        for each (RecurringPayments ^ payment in recurringPayments) {
            dataGridViewRecurring->Rows->Add(
                payment->Id, payment->UserAccountNumber,
                payment->Amount.ToString("N0"), // Hiển thị số tiền có dấu phẩy
                payment->Frequency, payment->PaymentDay.ToString("dd/MM/yyyy"),
                payment->Status == 0 ? "Pending" : "Complete");
        }
    }



  
  private
      : System::Void
        btnAccount_Click(System::Object ^ sender, System::EventArgs ^ e);

  private:
    System::Void btnShowCode_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
        if (dataGridViewCodes->Visible) return;
        dataGridViewCodes->Visible = true;
        dataGridViewRecurring->Visible = false;
    }

  private:
    System::Void btnLoadRecurring_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
        if (dataGridViewRecurring->Visible)
            return;
        dataGridViewRecurring->Visible = true;
        dataGridViewCodes->Visible = false;
    }
};
} // namespace BankingAppwinform
