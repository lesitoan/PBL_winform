#pragma once
#include "HandleFile.h"
#include "Transaction.h"
#include "TransactionsRepository.h"
#include "TransactionServices.h"


namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text::RegularExpressions;

public
ref class AdminTransactionForm : public System::Windows::Forms::Form {
  public:
    AdminTransactionForm(void);

  protected:
    ~AdminTransactionForm();

  private:
    System::Windows::Forms::Button ^ btnFind;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::TextBox ^ findText;
    System::Windows::Forms::DataGridView ^ dataGridViewTransactions;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column4;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column5;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column6;
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
        this->btnFind = (gcnew System::Windows::Forms::Button());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->findText = (gcnew System::Windows::Forms::TextBox());
        this->dataGridViewTransactions =
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
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewTransactions))
            ->BeginInit();
        this->SuspendLayout();
        //
        // btnFind
        //
        this->btnFind->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnFind->BackColor = System::Drawing::Color::DarkOrange;
        this->btnFind->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnFind->FlatAppearance->BorderSize = 0;
        this->btnFind->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnFind->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnFind->ForeColor = System::Drawing::Color::Black;
        this->btnFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnFind->Location = System::Drawing::Point(863, 13);
        this->btnFind->Name = L"btnFind";
        this->btnFind->Size = System::Drawing::Size(188, 37);
        this->btnFind->TabIndex = 36;
        this->btnFind->Text = L"TÌM";
        this->btnFind->UseVisualStyleBackColor = false;
        this->btnFind->Click += gcnew System::EventHandler(
            this, &AdminTransactionForm::btnFind_Click);
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
        this->panel1->Controls->Add(this->findText);
        this->panel1->Location = System::Drawing::Point(24, 12);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(822, 37);
        this->panel1->TabIndex = 35;
        //
        // findText
        //
        this->findText->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->findText->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->findText->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->findText->Location = System::Drawing::Point(18, 6);
        this->findText->MaxLength = 40;
        this->findText->Multiline = true;
        this->findText->Name = L"findText";
        this->findText->Size = System::Drawing::Size(802, 26);
        this->findText->TabIndex = 29;
        //
        // dataGridViewTransactions
        //
        this->dataGridViewTransactions->AllowUserToAddRows = false;
        this->dataGridViewTransactions->AllowUserToDeleteRows = false;
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
        this->dataGridViewTransactions->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle1;
        this->dataGridViewTransactions->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->dataGridViewTransactions->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewTransactions->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewTransactions->CellBorderStyle = System::Windows::
            Forms::DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewTransactions->ColumnHeadersBorderStyle =
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
        this->dataGridViewTransactions->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle2;
        this->dataGridViewTransactions->ColumnHeadersHeight = 40;
        this->dataGridViewTransactions->Columns->AddRange(
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(6){
                this->Column1, this->Column2, this->Column3, this->Column4,
                this->Column5, this->Column6});
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
        this->dataGridViewTransactions->DefaultCellStyle =
            dataGridViewCellStyle3;
        this->dataGridViewTransactions->EnableHeadersVisualStyles = false;
        this->dataGridViewTransactions->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewTransactions->Location =
            System::Drawing::Point(24, 65);
        this->dataGridViewTransactions->Name = L"dataGridViewTransactions";
        this->dataGridViewTransactions->ReadOnly = true;
        this->dataGridViewTransactions->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewTransactions->RowHeadersVisible = false;
        this->dataGridViewTransactions->RowTemplate->DefaultCellStyle
            ->BackColor = System::Drawing::Color::White;
        this->dataGridViewTransactions->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewTransactions->RowTemplate->DefaultCellStyle
            ->ForeColor = System::Drawing::Color::Black;
        this->dataGridViewTransactions->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewTransactions->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewTransactions->RowTemplate->Height = 40;
        this->dataGridViewTransactions->RowTemplate->ReadOnly = true;
        this->dataGridViewTransactions->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewTransactions->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewTransactions->Size = System::Drawing::Size(1027, 621);
        this->dataGridViewTransactions->TabIndex = 34;
        //
        // Column1
        //
        this->Column1->HeaderText = L"Loại";
        this->Column1->Name = L"Column1";
        this->Column1->ReadOnly = true;
        //
        // Column2
        //
        this->Column2->HeaderText = L"Người gửi";
        this->Column2->Name = L"Column2";
        this->Column2->ReadOnly = true;
        //
        // Column3
        //
        this->Column3->HeaderText = L"Người nhận";
        this->Column3->Name = L"Column3";
        this->Column3->ReadOnly = true;
        //
        // Column4
        //
        this->Column4->HeaderText = L"Số tiền";
        this->Column4->Name = L"Column4";
        this->Column4->ReadOnly = true;
        //
        // Column5
        //
        this->Column5->HeaderText = L"Nội dung";
        this->Column5->Name = L"Column5";
        this->Column5->ReadOnly = true;
        //
        // Column6
        //
        this->Column6->HeaderText = L"Thời gian";
        this->Column6->Name = L"Column6";
        this->Column6->ReadOnly = true;
        //
        // AdminTransactionForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ButtonFace;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->btnFind);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->dataGridViewTransactions);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"AdminTransactionForm";
        this->Text = L"AdminTransactionForm";
        this->Load += gcnew System::EventHandler(
            this, &AdminTransactionForm::AdminTransactionForm_Load);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewTransactions))
            ->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    System::Void AdminTransactionForm_Load(System::Object ^ sender,
                                           System::EventArgs ^ e);

    void loadTransactions(array<Transaction ^> ^ transactions);

    void btnFind_Click(System::Object ^ sender, System::EventArgs ^ e);
};
} // namespace BankingAppwinform
