#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "RecurringPayments.h"
#include "User.h"
#include "Validate.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class ClientRecurringPaymentForm : public System::Windows::Forms::Form {
  public:
    ClientRecurringPaymentForm(void);

  protected:
    ~ClientRecurringPaymentForm();

  private:

    System::Windows::Forms::Panel ^ panel2;
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
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->dataGridViewRecurring =
            (gcnew System::Windows::Forms::DataGridView());
        this->Column7 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column8 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column10 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column11 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panel2->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->BeginInit();
        this->SuspendLayout();
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::Teal;
        this->panel2->Controls->Add(this->dataGridViewRecurring);
        this->panel2->Location = System::Drawing::Point(12, 12);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(634, 475);
        this->panel2->TabIndex = 1;
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
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(4){
                this->Column7, this->Column8, this->Column10, this->Column11});
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
        this->dataGridViewRecurring->RowHeadersWidth = 51;
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
        this->dataGridViewRecurring->Size = System::Drawing::Size(634, 475);
        this->dataGridViewRecurring->TabIndex = 5;
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
        // ClientRecurringPaymentForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(658, 499);
        this->Controls->Add(this->panel2);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"ClientRecurringPaymentForm";
        this->Text = L"ClientRecurringPaymentForm";
        this->panel2->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion

  private:

    void loadRecurringPaymentData();
};
} // namespace BankingAppwinform
