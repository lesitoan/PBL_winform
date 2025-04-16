#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "CustomerCodes.h"
#include "Validate.h"
#include "Utils.h"
#include "CustomerCodeDetails.h"
#include "RecurringPayments.h"
#include "CodeDetailForm.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

public
ref class CodeForm : public System::Windows::Forms::Form {
  public:
    CodeForm(void);

  protected:
    ~CodeForm();

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::TextBox ^ customerCodes;

    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::TextBox ^ pin;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Button ^ btnAddCode;
    System::Windows::Forms::Label ^ label7;
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewCodes;





  private:
    System::Windows::Forms::Panel ^ panel5;

  private:
    System::Windows::Forms::Button ^ btnDeleteCode;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                CodeForm::typeid));
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle1 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle2 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle3 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->btnAddCode = (gcnew System::Windows::Forms::Button());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->pin = (gcnew System::Windows::Forms::TextBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->customerCodes = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->panel5 = (gcnew System::Windows::Forms::Panel());
        this->btnDeleteCode = (gcnew System::Windows::Forms::Button());
        this->dataGridViewCodes =
            (gcnew System::Windows::Forms::DataGridView());
        this->Column1 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column2 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column3 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panel1->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel5->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewCodes))
            ->BeginInit();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::Teal;
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->btnAddCode);
        this->panel1->Controls->Add(this->panel4);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->label7);
        this->panel1->Controls->Add(this->panel3);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
        this->panel1->Location = System::Drawing::Point(0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(296, 499);
        this->panel1->TabIndex = 0;
        //
        // label2
        //
        this->label2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 8));
        this->label2->ForeColor = System::Drawing::Color::Transparent;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(21, 78);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(249, 22);
        this->label2->TabIndex = 64;
        this->label2->Text = L"Nhập MÃ KH (Mỗi mã 1 dòng, vd: ABCDEF)";
        //
        // btnAddCode
        //
        this->btnAddCode->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Bottom |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnAddCode->BackColor = System::Drawing::SystemColors::Info;
        this->btnAddCode->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAddCode->FlatAppearance->BorderSize = 0;
        this->btnAddCode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAddCode->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnAddCode->ForeColor = System::Drawing::Color::Teal;
        this->btnAddCode->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnAddCode->Location = System::Drawing::Point(21, 396);
        this->btnAddCode->Name = L"btnAddCode";
        this->btnAddCode->Size = System::Drawing::Size(252, 40);
        this->btnAddCode->TabIndex = 58;
        this->btnAddCode->Text = L"OK";
        this->btnAddCode->UseVisualStyleBackColor = false;
        this->btnAddCode->Click +=
            gcnew System::EventHandler(this, &CodeForm::btnAddCode_Click);
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Bottom |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->pin);
        this->panel4->Location = System::Drawing::Point(21, 334);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(252, 37);
        this->panel4->TabIndex = 61;
        //
        // pin
        //
        this->pin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->pin->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->pin->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->pin->Location = System::Drawing::Point(18, 6);
        this->pin->MaxLength = 15;
        this->pin->Multiline = true;
        this->pin->Name = L"pin";
        this->pin->Size = System::Drawing::Size(231, 28);
        this->pin->TabIndex = 29;
        //
        // label1
        //
        this->label1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Bottom |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(17, 309);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(76, 22);
        this->label1->TabIndex = 59;
        this->label1->Text = L"Nhập PIN:";
        //
        // label7
        //
        this->label7->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label7->AutoSize = true;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 17, System::Drawing::FontStyle::Bold));
        this->label7->ForeColor = System::Drawing::Color::White;
        this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label7->Location = System::Drawing::Point(30, 33);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(240, 30);
        this->label7->TabIndex = 63;
        this->label7->Text = L"THÊM MÃ KHÁCH HÀNG";
        this->label7->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->Controls->Add(this->customerCodes);
        this->panel3->Location = System::Drawing::Point(21, 103);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(252, 203);
        this->panel3->TabIndex = 62;
        //
        // customerCodes
        //
        this->customerCodes->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->customerCodes->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->customerCodes->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->customerCodes->Location = System::Drawing::Point(14, 12);
        this->customerCodes->MaxLength = 300;
        this->customerCodes->Multiline = true;
        this->customerCodes->Name = L"customerCodes";
        this->customerCodes->Size = System::Drawing::Size(226, 179);
        this->customerCodes->TabIndex = 29;
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
        this->panel2->Controls->Add(this->panel5);
        this->panel2->Controls->Add(this->dataGridViewCodes);
        this->panel2->Location = System::Drawing::Point(299, 0);
        this->panel2->Margin = System::Windows::Forms::Padding(20, 3, 3, 3);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(359, 499);
        this->panel2->TabIndex = 1;
        //
        // panel5
        //
        this->panel5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Bottom |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel5->BackColor = System::Drawing::Color::White;
        this->panel5->Controls->Add(this->btnDeleteCode);
        this->panel5->Location = System::Drawing::Point(0, 456);
        this->panel5->Name = L"panel5";
        this->panel5->Size = System::Drawing::Size(359, 43);
        this->panel5->TabIndex = 4;
        //
        // btnDeleteCode
        //
        this->btnDeleteCode->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnDeleteCode->BackColor = System::Drawing::Color::Red;
        this->btnDeleteCode->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnDeleteCode->FlatAppearance->BorderSize = 0;
        this->btnDeleteCode->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnDeleteCode->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnDeleteCode->ForeColor = System::Drawing::Color::Transparent;
        this->btnDeleteCode->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnDeleteCode.Image")));
        this->btnDeleteCode->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnDeleteCode->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->btnDeleteCode->Location = System::Drawing::Point(291, 4);
        this->btnDeleteCode->Margin = System::Windows::Forms::Padding(1);
        this->btnDeleteCode->Name = L"btnDeleteCode";
        this->btnDeleteCode->Size = System::Drawing::Size(67, 34);
        this->btnDeleteCode->TabIndex = 35;
        this->btnDeleteCode->UseVisualStyleBackColor = false;
        this->btnDeleteCode->Click +=
            gcnew System::EventHandler(this, &CodeForm::btnDeleteCode_Click);
        //
        // dataGridViewCodes
        //
        this->dataGridViewCodes->AllowUserToAddRows = false;
        this->dataGridViewCodes->AllowUserToDeleteRows = false;
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
        this->dataGridViewCodes->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle1;
        this->dataGridViewCodes->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->dataGridViewCodes->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewCodes->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewCodes->CellBorderStyle = System::Windows::Forms::
            DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewCodes->ColumnHeadersBorderStyle =
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
        this->dataGridViewCodes->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle2;
        this->dataGridViewCodes->ColumnHeadersHeight = 40;
        this->dataGridViewCodes->Columns->AddRange(
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(3){
                this->Column1, this->Column2, this->Column3});
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
        this->dataGridViewCodes->DefaultCellStyle = dataGridViewCellStyle3;
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
        this->dataGridViewCodes->Size = System::Drawing::Size(359, 456);
        this->dataGridViewCodes->TabIndex = 3;
        //
        // Column1
        //
        this->Column1->HeaderText = L"Mã KH";
        this->Column1->Name = L"Column1";
        this->Column1->ReadOnly = true;
        //
        // Column2
        //
        this->Column2->HeaderText = L"Ngày tạo";
        this->Column2->Name = L"Column2";
        this->Column2->ReadOnly = true;
        //
        // Column3
        //
        this->Column3->HeaderText = L"Trạng thái";
        this->Column3->Name = L"Column3";
        this->Column3->ReadOnly = true;
        //
        // CodeForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(658, 499);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"CodeForm";
        this->Text = L"CodeForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel5->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewCodes))
            ->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion

    private:
    //PaymentCodes ^ selectedPaymentCode;

  private:
    System::Void btnAddCode_Click(System::Object ^ sender,
                                  System::EventArgs ^ e);

    array<CustomerCodes ^> ^ createListCode(TextBox ^ textBox);

    void loadTableCodes();
    void CodeForm::dataGridViewCodes_CellDoubleClick(Object ^ sender,
                                                     DataGridViewCellEventArgs ^
                                                         e);

private:
    System::Void btnDeleteCode_Click(System::Object ^ sender,
                                     System::EventArgs ^ e);
};
} // namespace BankingAppwinform
