#pragma once
#include "AdminForm.h"
#include "LoadChildForm.h"

ref class EditUserForm;

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for AdminClientForm
/// </summary>
public
ref class TableUsersForm : public System::Windows::Forms::Form {
  public:
    TableUsersForm(void);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~TableUsersForm();

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column6;

  protected:
  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column5;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column4;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewUsers;

  private:
  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::TextBox ^ phoneNumber;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Button ^ button1;

  private:
    System::Windows::Forms::Button ^ btnModify;

  private:
  private:
    System::Windows::Forms::Button ^ button3;

  private:
  private:
  private:
  private:
  private:
  private:
  private:
  private:
  private:
  private:
  private:
  private:
  private:
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
        this->Column6 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column5 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column4 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column3 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column2 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column1 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewUsers =
            (gcnew System::Windows::Forms::DataGridView());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->btnModify = (gcnew System::Windows::Forms::Button());
        this->button3 = (gcnew System::Windows::Forms::Button());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewUsers))
            ->BeginInit();
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // Column6
        //
        this->Column6->HeaderText = L"Column6";
        this->Column6->Name = L"Column6";
        this->Column6->ReadOnly = true;
        //
        // Column5
        //
        this->Column5->HeaderText = L"Column5";
        this->Column5->Name = L"Column5";
        this->Column5->ReadOnly = true;
        //
        // Column4
        //
        this->Column4->HeaderText = L"Column4";
        this->Column4->Name = L"Column4";
        this->Column4->ReadOnly = true;
        //
        // Column3
        //
        this->Column3->HeaderText = L"Column3";
        this->Column3->Name = L"Column3";
        this->Column3->ReadOnly = true;
        //
        // Column2
        //
        this->Column2->HeaderText = L"Column2";
        this->Column2->Name = L"Column2";
        this->Column2->ReadOnly = true;
        //
        // Column1
        //
        this->Column1->HeaderText = L"Column1";
        this->Column1->Name = L"Column1";
        this->Column1->ReadOnly = true;
        //
        // dataGridViewUsers
        //
        this->dataGridViewUsers->AllowUserToAddRows = false;
        this->dataGridViewUsers->AllowUserToDeleteRows = false;
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
        this->dataGridViewUsers->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle1;
        this->dataGridViewUsers->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->dataGridViewUsers->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewUsers->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewUsers->CellBorderStyle = System::Windows::Forms::
            DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewUsers->ColumnHeadersBorderStyle =
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
        this->dataGridViewUsers->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle2;
        this->dataGridViewUsers->ColumnHeadersHeight = 40;
        this->dataGridViewUsers->Columns->AddRange(
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
        this->dataGridViewUsers->DefaultCellStyle = dataGridViewCellStyle3;
        this->dataGridViewUsers->EnableHeadersVisualStyles = false;
        this->dataGridViewUsers->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewUsers->Location = System::Drawing::Point(26, 79);
        this->dataGridViewUsers->Name = L"dataGridViewUsers";
        this->dataGridViewUsers->ReadOnly = true;
        this->dataGridViewUsers->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewUsers->RowHeadersVisible = false;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle->BackColor =
            System::Drawing::Color::White;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle->ForeColor =
            System::Drawing::Color::Black;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewUsers->RowTemplate->Height = 40;
        this->dataGridViewUsers->RowTemplate->ReadOnly = true;
        this->dataGridViewUsers->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewUsers->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewUsers->Size = System::Drawing::Size(929, 609);
        this->dataGridViewUsers->TabIndex = 2;
        this->dataGridViewUsers->CellContentClick +=
            gcnew System::Windows::Forms::DataGridViewCellEventHandler(
                this, &TableUsersForm::dataGridView1_CellContentClick);
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
        this->panel1->Controls->Add(this->phoneNumber);
        this->panel1->Location = System::Drawing::Point(26, 26);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(734, 37);
        this->panel1->TabIndex = 32;
        //
        // phoneNumber
        //
        this->phoneNumber->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->phoneNumber->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->phoneNumber->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->phoneNumber->Location = System::Drawing::Point(18, 6);
        this->phoneNumber->MaxLength = 40;
        this->phoneNumber->Multiline = true;
        this->phoneNumber->Name = L"phoneNumber";
        this->phoneNumber->Size = System::Drawing::Size(714, 26);
        this->phoneNumber->TabIndex = 29;
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::Color::DarkOrange;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Black;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(766, 26);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(188, 37);
        this->btnSubmit->TabIndex = 33;
        this->btnSubmit->Text = L"SEARCH";
        this->btnSubmit->UseVisualStyleBackColor = false;
        //
        // button1
        //
        this->button1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button1->BackColor = System::Drawing::Color::Green;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->BorderSize = 0;
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button1->ForeColor = System::Drawing::Color::Bisque;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(961, 79);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(90, 73);
        this->button1->TabIndex = 34;
        this->button1->Text = L"THÊM";
        this->button1->UseVisualStyleBackColor = false;
        //
        // btnModify
        //
        this->btnModify->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnModify->BackColor = System::Drawing::Color::RoyalBlue;
        this->btnModify->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnModify->FlatAppearance->BorderSize = 0;
        this->btnModify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnModify->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnModify->ForeColor = System::Drawing::Color::Bisque;
        this->btnModify->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnModify->Location = System::Drawing::Point(961, 158);
        this->btnModify->Name = L"btnModify";
        this->btnModify->Size = System::Drawing::Size(90, 73);
        this->btnModify->TabIndex = 35;
        this->btnModify->Text = L"SỬA";
        this->btnModify->UseVisualStyleBackColor = false;
        this->btnModify->Click +=
            gcnew System::EventHandler(this, &TableUsersForm::btnModify_Click);
        //
        // button3
        //
        this->button3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button3->BackColor = System::Drawing::Color::Red;
        this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button3->FlatAppearance->BorderSize = 0;
        this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button3->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button3->ForeColor = System::Drawing::Color::Bisque;
        this->button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button3->Location = System::Drawing::Point(961, 237);
        this->button3->Name = L"button3";
        this->button3->Size = System::Drawing::Size(90, 73);
        this->button3->TabIndex = 36;
        this->button3->Text = L"XÓA";
        this->button3->UseVisualStyleBackColor = false;
        //
        // TableUsersForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::White;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->button3);
        this->Controls->Add(this->btnModify);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->btnSubmit);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->dataGridViewUsers);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"TableUsersForm";
        this->Text = L"AdminClientForm";
        this->Load += gcnew System::EventHandler(
            this, &TableUsersForm::AdminClientForm_Load);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewUsers))
            ->EndInit();
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void dataGridView1_CellContentClick(
        System::Object ^ sender,
        System::Windows::Forms::DataGridViewCellEventArgs ^ e);

  private:
    System::Void AdminClientForm_Load(System::Object ^ sender,
                                      System::EventArgs ^ e);

  private:
    System::Void btnModify_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);
};
} // namespace BankingAppwinform
