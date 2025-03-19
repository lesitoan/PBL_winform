#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "RecurringPayments.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for ClientRecurringPaymentForm
/// </summary>
public
ref class ClientRecurringPaymentForm : public System::Windows::Forms::Form {
  public:
    ClientRecurringPaymentForm(void) {
        InitializeComponent();
        loadRecurringPaymentData();
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~ClientRecurringPaymentForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Panel ^ panel2;

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

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column12;

  private:
    System::Windows::Forms::Panel ^ panelForm;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::TextBox ^ amountRecurringPayment;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
  private:
  private:
  private:
  private:
  private:
  protected:
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
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle1 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle2 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle3 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
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
        this->Column12 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panelForm = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->amountRecurringPayment =
            (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->BeginInit();
        this->panelForm->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::Teal;
        this->panel1->Controls->Add(this->panelForm);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
        this->panel1->Location = System::Drawing::Point(0, 330);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(658, 169);
        this->panel1->TabIndex = 0;
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
        this->panel2->Location = System::Drawing::Point(0, -2);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(658, 326);
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
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(5){
                this->Column7, this->Column8, this->Column10, this->Column11,
                this->Column12});
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
        this->dataGridViewRecurring->Size = System::Drawing::Size(658, 326);
        this->dataGridViewRecurring->TabIndex = 5;
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
        // Column10
        //
        this->Column10->HeaderText = L"Số tháng TTĐK";
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
        this->Column12->HeaderText = L"Tiền nợ";
        this->Column12->Name = L"Column12";
        this->Column12->ReadOnly = true;
        //
        // panelForm
        //
        this->panelForm->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelForm->Controls->Add(this->label1);
        this->panelForm->Controls->Add(this->labelAuth);
        this->panelForm->Controls->Add(this->panel4);
        this->panelForm->Controls->Add(this->btnSubmit);
        this->panelForm->Location = System::Drawing::Point(45, 22);
        this->panelForm->Name = L"panelForm";
        this->panelForm->Size = System::Drawing::Size(564, 124);
        this->panelForm->TabIndex = 0;
        this->panelForm->Visible = false;
        //
        // label1
        //
        this->label1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 15, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::Lime;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(111, 6);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(320, 27);
        this->label1->TabIndex = 38;
        this->label1->Text = L"Bạn đa chọn khách hàng: LE SI TOAN";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(-2, 56);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(233, 22);
        this->labelAuth->TabIndex = 36;
        this->labelAuth->Text = L"Nhập số tiền yêu cầu thanh toán:";
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->amountRecurringPayment);
        this->panel4->Location = System::Drawing::Point(2, 81);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(388, 37);
        this->panel4->TabIndex = 37;
        //
        // amountRecurringPayment
        //
        this->amountRecurringPayment->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->amountRecurringPayment->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->amountRecurringPayment->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->amountRecurringPayment->Location = System::Drawing::Point(18, 6);
        this->amountRecurringPayment->MaxLength = 9;
        this->amountRecurringPayment->Multiline = true;
        this->amountRecurringPayment->Name = L"amountRecurringPayment";
        this->amountRecurringPayment->Size = System::Drawing::Size(370, 28);
        this->amountRecurringPayment->TabIndex = 29;
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(401, 81);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(165, 37);
        this->btnSubmit->TabIndex = 35;
        this->btnSubmit->Text = L"YÊU CẦU";
        this->btnSubmit->UseVisualStyleBackColor = false;
        //
        // ClientRecurringPaymentForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(658, 499);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"ClientRecurringPaymentForm";
        this->Text = L"ClientRecurringPaymentForm";
        this->panel1->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->EndInit();
        this->panelForm->ResumeLayout(false);
        this->panelForm->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    void loadRecurringPaymentData() {
        array<RecurringPayments ^> ^ recurringPayments =
            HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
        if (recurringPayments == nullptr) {
            return;
        }

        for each (RecurringPayments ^ payment in recurringPayments) {
            dataGridViewRecurring->Rows->Add(
                payment->Id, payment->UserAccountNumber, payment->Monthly,
                payment->PaymentDay.ToString("dd/MM/yyyy"), payment->Debt);
        }
    }


};
} // namespace BankingAppwinform
