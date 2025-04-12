#pragma once
#include "PaymentCodes.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for CodeInfoForm
/// </summary>
public
ref class CodeInfoForm : public System::Windows::Forms::Form {
  public:
    CodeInfoForm(PaymentCodes ^ paymentCode);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~CodeInfoForm();

  private:
    System::Windows::Forms::Panel ^ panel3;

  protected:
  private:
    System::Windows::Forms::TextBox ^ paymentDate;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::TextBox ^ status;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Panel ^ panel7;

  private:
    System::Windows::Forms::TextBox ^ expiredDate;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Panel ^ panel6;

  private:
    System::Windows::Forms::TextBox ^ amount;

  private:
    System::Windows::Forms::Panel ^ panel5;

  private:
    System::Windows::Forms::TextBox ^ createdDate;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::TextBox ^ code;

  private:


  protected:
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
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->paymentDate = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->status = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->panel7 = (gcnew System::Windows::Forms::Panel());
        this->expiredDate = (gcnew System::Windows::Forms::TextBox());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panel6 = (gcnew System::Windows::Forms::Panel());
        this->amount = (gcnew System::Windows::Forms::TextBox());
        this->panel5 = (gcnew System::Windows::Forms::Panel());
        this->createdDate = (gcnew System::Windows::Forms::TextBox());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->code = (gcnew System::Windows::Forms::TextBox());
        this->panel3->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel7->SuspendLayout();
        this->panel6->SuspendLayout();
        this->panel5->SuspendLayout();
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel3->Controls->Add(this->paymentDate);
        this->panel3->Location = System::Drawing::Point(271, 190);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(215, 37);
        this->panel3->TabIndex = 114;
        //
        // paymentDate
        //
        this->paymentDate->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->paymentDate->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->paymentDate->Cursor = System::Windows::Forms::Cursors::No;
        this->paymentDate->Enabled = false;
        this->paymentDate->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->paymentDate->Location = System::Drawing::Point(18, 6);
        this->paymentDate->MaxLength = 10;
        this->paymentDate->Multiline = true;
        this->paymentDate->Name = L"paymentDate";
        this->paymentDate->Size = System::Drawing::Size(195, 26);
        this->paymentDate->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel2->Controls->Add(this->status);
        this->panel2->Location = System::Drawing::Point(32, 190);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(214, 37);
        this->panel2->TabIndex = 121;
        //
        // status
        //
        this->status->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->status->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->status->Cursor = System::Windows::Forms::Cursors::No;
        this->status->Enabled = false;
        this->status->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->status->Location = System::Drawing::Point(18, 6);
        this->status->MaxLength = 10;
        this->status->Multiline = true;
        this->status->Name = L"status";
        this->status->Size = System::Drawing::Size(194, 26);
        this->status->TabIndex = 29;
        //
        // label3
        //
        this->label3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label3->AutoSize = true;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label3->ForeColor = System::Drawing::Color::Transparent;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(268, 165);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(127, 22);
        this->label3->TabIndex = 120;
        this->label3->Text = L"Ngày thanh toán:";
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label4->ForeColor = System::Drawing::Color::Transparent;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(268, 83);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(105, 22);
        this->label4->TabIndex = 119;
        this->label4->Text = L"Ngày hết hạn:";
        //
        // panel7
        //
        this->panel7->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel7->BackColor = System::Drawing::Color::White;
        this->panel7->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel7->Controls->Add(this->expiredDate);
        this->panel7->Location = System::Drawing::Point(272, 108);
        this->panel7->Name = L"panel7";
        this->panel7->Size = System::Drawing::Size(214, 37);
        this->panel7->TabIndex = 112;
        //
        // expiredDate
        //
        this->expiredDate->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->expiredDate->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->expiredDate->Cursor = System::Windows::Forms::Cursors::No;
        this->expiredDate->Enabled = false;
        this->expiredDate->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->expiredDate->Location = System::Drawing::Point(18, 6);
        this->expiredDate->MaxLength = 40;
        this->expiredDate->Multiline = true;
        this->expiredDate->Name = L"expiredDate";
        this->expiredDate->Size = System::Drawing::Size(194, 26);
        this->expiredDate->TabIndex = 29;
        //
        // label5
        //
        this->label5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(28, 165);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(79, 22);
        this->label5->TabIndex = 118;
        this->label5->Text = L"Trạng thái";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label2->ForeColor = System::Drawing::Color::Transparent;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(28, 83);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(61, 22);
        this->label2->TabIndex = 117;
        this->label2->Text = L"Số tiền:";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(268, 9);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(75, 22);
        this->label1->TabIndex = 116;
        this->label1->Text = L"Ngày tạo:";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(28, 9);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(115, 22);
        this->labelAuth->TabIndex = 115;
        this->labelAuth->Text = L"Mã thanh  toán:";
        //
        // panel6
        //
        this->panel6->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel6->BackColor = System::Drawing::Color::White;
        this->panel6->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel6->Controls->Add(this->amount);
        this->panel6->Location = System::Drawing::Point(32, 108);
        this->panel6->Name = L"panel6";
        this->panel6->Size = System::Drawing::Size(214, 37);
        this->panel6->TabIndex = 113;
        //
        // amount
        //
        this->amount->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->amount->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->amount->Cursor = System::Windows::Forms::Cursors::No;
        this->amount->Enabled = false;
        this->amount->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->amount->Location = System::Drawing::Point(18, 6);
        this->amount->MaxLength = 10;
        this->amount->Multiline = true;
        this->amount->Name = L"amount";
        this->amount->Size = System::Drawing::Size(194, 26);
        this->amount->TabIndex = 29;
        //
        // panel5
        //
        this->panel5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel5->BackColor = System::Drawing::Color::White;
        this->panel5->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel5->Controls->Add(this->createdDate);
        this->panel5->Location = System::Drawing::Point(272, 34);
        this->panel5->Name = L"panel5";
        this->panel5->Size = System::Drawing::Size(214, 37);
        this->panel5->TabIndex = 111;
        //
        // createdDate
        //
        this->createdDate->AccessibleRole =
            System::Windows::Forms::AccessibleRole::Clock;
        this->createdDate->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->createdDate->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->createdDate->Cursor = System::Windows::Forms::Cursors::No;
        this->createdDate->Enabled = false;
        this->createdDate->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->createdDate->Location = System::Drawing::Point(18, 6);
        this->createdDate->MaxLength = 40;
        this->createdDate->Multiline = true;
        this->createdDate->Name = L"createdDate";
        this->createdDate->Size = System::Drawing::Size(194, 26);
        this->createdDate->TabIndex = 29;
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
        this->panel1->Controls->Add(this->code);
        this->panel1->Location = System::Drawing::Point(32, 34);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(214, 37);
        this->panel1->TabIndex = 110;
        //
        // code
        //
        this->code->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->code->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->code->Cursor = System::Windows::Forms::Cursors::No;
        this->code->Enabled = false;
        this->code->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->code->Location = System::Drawing::Point(18, 6);
        this->code->MaxLength = 40;
        this->code->Multiline = true;
        this->code->Name = L"code";
        this->code->Size = System::Drawing::Size(194, 26);
        this->code->TabIndex = 29;
        //
        // CodeInfoForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(516, 246);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->panel7);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->labelAuth);
        this->Controls->Add(this->panel6);
        this->Controls->Add(this->panel5);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle =
            System::Windows::Forms::FormBorderStyle::FixedToolWindow;
        this->MaximumSize = System::Drawing::Size(532, 285);
        this->MinimumSize = System::Drawing::Size(532, 285);
        this->Name = L"CodeInfoForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"CodeInfoForm";
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel7->ResumeLayout(false);
        this->panel7->PerformLayout();
        this->panel6->ResumeLayout(false);
        this->panel6->PerformLayout();
        this->panel5->ResumeLayout(false);
        this->panel5->PerformLayout();
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
    void loadData(PaymentCodes ^ paymentCode);


};
} // namespace BankingAppwinform
