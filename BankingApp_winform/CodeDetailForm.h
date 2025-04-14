#pragma once
#include "CustomerCodeDetails.h"
#include "CustomerCodes.h"
#include "GlobalData.h"
#include "HandleFile.h"
#include "Validate.h"
#include "Utils.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for CodeDetailForm
/// </summary>
public
ref class CodeDetailForm : public System::Windows::Forms::Form {
  public:
    CodeDetailForm(CustomerCodes ^ customerCode);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~CodeDetailForm();

  private:
    System::Windows::Forms::FlowLayoutPanel ^ leftContent;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Label ^ label8;

  private:
    System::Windows::Forms::Label ^ label7;

  private:
    System::Windows::Forms::Label ^ label6;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label10;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Label ^ label9;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::TextBox ^ days;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::TextBox ^ amount;

  protected:
  private:
  protected:
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
        this->leftContent = (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label8 = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->amount = (gcnew System::Windows::Forms::TextBox());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->days = (gcnew System::Windows::Forms::TextBox());
        this->label10 = (gcnew System::Windows::Forms::Label());
        this->leftContent->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel1->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // leftContent
        //
        this->leftContent->AutoScroll = true;
        this->leftContent->BackColor = System::Drawing::Color::Teal;
        this->leftContent->Controls->Add(this->panel2);
        this->leftContent->Dock = System::Windows::Forms::DockStyle::Left;
        this->leftContent->Location = System::Drawing::Point(0, 0);
        this->leftContent->Name = L"leftContent";
        this->leftContent->Padding =
            System::Windows::Forms::Padding(4, 4, 0, 0);
        this->leftContent->Size = System::Drawing::Size(326, 344);
        this->leftContent->TabIndex = 1;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel2->Controls->Add(this->label8);
        this->panel2->Controls->Add(this->label7);
        this->panel2->Controls->Add(this->label6);
        this->panel2->Controls->Add(this->label5);
        this->panel2->Controls->Add(this->label4);
        this->panel2->Controls->Add(this->label3);
        this->panel2->Controls->Add(this->label2);
        this->panel2->Controls->Add(this->label1);
        this->panel2->Location = System::Drawing::Point(7, 7);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(300, 222);
        this->panel2->TabIndex = 0;
        this->panel2->Visible = false;
        //
        // label8
        //
        this->label8->AutoSize = true;
        this->label8->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label8->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label8->Location = System::Drawing::Point(15, 190);
        this->label8->Name = L"label8";
        this->label8->Size = System::Drawing::Size(246, 16);
        this->label8->TabIndex = 7;
        this->label8->Text = L"Ngày thanh toán: 15/04/2025 11:32:32 SA";
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label7->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label7->Location = System::Drawing::Point(15, 165);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(193, 16);
        this->label7->TabIndex = 6;
        this->label7->Text = L"Tài khoản thanh toán: 12323232";
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label6->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label6->Location = System::Drawing::Point(15, 140);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(153, 16);
        this->label6->TabIndex = 5;
        this->label6->Text = L"Trạng thái: đã thanh toán";
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label5->Location = System::Drawing::Point(15, 115);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(228, 16);
        this->label5->TabIndex = 4;
        this->label5->Text = L"Ngày hết hạn: 10/05/2025 12:00:00 SA";
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label4->Location = System::Drawing::Point(15, 90);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(204, 16);
        this->label4->TabIndex = 3;
        this->label4->Text = L"Ngày tạo: 10/04/2025 12:00:00 SA";
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label3->Location = System::Drawing::Point(15, 65);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(121, 16);
        this->label3->TabIndex = 2;
        this->label3->Text = L"Số tiền: 120000 vnđ";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label2->Location = System::Drawing::Point(15, 40);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(160, 16);
        this->label2->TabIndex = 1;
        this->label2->Text = L"Mã khách hàng: ABCDED";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label1->Location = System::Drawing::Point(15, 14);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(146, 16);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Mã hóa đơn: DFKFJ454";
        //
        // panel1
        //
        this->panel1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::Teal;
        this->panel1->Controls->Add(this->label10);
        this->panel1->Controls->Add(this->btnSubmit);
        this->panel1->Controls->Add(this->label9);
        this->panel1->Controls->Add(this->panel4);
        this->panel1->Controls->Add(this->labelAuth);
        this->panel1->Controls->Add(this->panel3);
        this->panel1->Location = System::Drawing::Point(332, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(214, 344);
        this->panel1->TabIndex = 2;
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(12, 82);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(61, 22);
        this->labelAuth->TabIndex = 94;
        this->labelAuth->Text = L"Số tiền:";
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::Color::Green;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Bisque;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(16, 237);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(183, 48);
        this->btnSubmit->TabIndex = 92;
        this->btnSubmit->Text = L"OK";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click +=
            gcnew System::EventHandler(this, &CodeDetailForm::btnSubmit_Click);
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
        this->panel3->Controls->Add(this->amount);
        this->panel3->Location = System::Drawing::Point(16, 107);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(184, 37);
        this->panel3->TabIndex = 91;
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
        this->amount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->amount->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->amount->Location = System::Drawing::Point(18, 6);
        this->amount->MaxLength = 40;
        this->amount->Multiline = true;
        this->amount->Name = L"amount";
        this->amount->Size = System::Drawing::Size(164, 26);
        this->amount->TabIndex = 29;
        //
        // label9
        //
        this->label9->AutoSize = true;
        this->label9->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label9->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label9->ForeColor = System::Drawing::Color::Transparent;
        this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label9->Location = System::Drawing::Point(12, 153);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(138, 22);
        this->label9->TabIndex = 96;
        this->label9->Text = L"Thời hạn (số ngày)";
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel4->Controls->Add(this->days);
        this->panel4->Location = System::Drawing::Point(16, 178);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(184, 37);
        this->panel4->TabIndex = 95;
        //
        // days
        //
        this->days->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->days->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->days->Cursor = System::Windows::Forms::Cursors::Hand;
        this->days->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->days->Location = System::Drawing::Point(18, 6);
        this->days->MaxLength = 40;
        this->days->Multiline = true;
        this->days->Name = L"days";
        this->days->Size = System::Drawing::Size(164, 26);
        this->days->TabIndex = 29;
        //
        // label10
        //
        this->label10->AutoSize = true;
        this->label10->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label10->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label10->ForeColor = System::Drawing::Color::Transparent;
        this->label10->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label10->Location = System::Drawing::Point(48, 41);
        this->label10->Name = L"label10";
        this->label10->Size = System::Drawing::Size(115, 22);
        this->label10->TabIndex = 97;
        this->label10->Text = L"THÊM HÓA ĐƠN";
        //
        // CodeDetailForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::MintCream;
        this->ClientSize = System::Drawing::Size(543, 344);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->leftContent);
        this->FormBorderStyle =
            System::Windows::Forms::FormBorderStyle::FixedToolWindow;
        this->MaximumSize = System::Drawing::Size(559, 383);
        this->MinimumSize = System::Drawing::Size(559, 383);
        this->Name = L"CodeDetailForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"CodeDetailForm";
        this->leftContent->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

    CustomerCodes ^ customerCode;

  private:
    void loadCodeDetails();

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);
};
} // namespace BankingAppwinform
