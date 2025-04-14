#pragma once
#include "CompanyForm.h"
#include "GlobalData.h"
#include "HandleFile.h"
#include "Services.h"
#include "User.h"
#include "Utils.h"
#include "Validate.h"
#include "RecurringPayments.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class ServicePaymentForm : public System::Windows::Forms::Form {
  public:
    ServicePaymentForm(void);

  protected:
    ~ServicePaymentForm();

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanelServices;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::Panel ^ panelContent;
    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::ComboBox ^ selectCompanyBox;
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::TextBox ^ code;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Button ^ btnTransfer;
    System::Windows::Forms::Label ^ labelReceiver;
    System::Windows::Forms::Label ^ labelHeader;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::TextBox ^ pin;
    System::Windows::Forms::CheckBox ^ submitRecurringPayment;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        this->flowLayoutPanelServices =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->labelHeader = (gcnew System::Windows::Forms::Label());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->submitRecurringPayment =
            (gcnew System::Windows::Forms::CheckBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->pin = (gcnew System::Windows::Forms::TextBox());
        this->labelReceiver = (gcnew System::Windows::Forms::Label());
        this->btnTransfer = (gcnew System::Windows::Forms::Button());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->code = (gcnew System::Windows::Forms::TextBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectCompanyBox = (gcnew System::Windows::Forms::ComboBox());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel1->SuspendLayout();
        this->panelContent->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // flowLayoutPanelServices
        //
        this->flowLayoutPanelServices->AutoScroll = true;
        this->flowLayoutPanelServices->BackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(192)));
        this->flowLayoutPanelServices->Dock =
            System::Windows::Forms::DockStyle::Left;
        this->flowLayoutPanelServices->Location = System::Drawing::Point(0, 0);
        this->flowLayoutPanelServices->Margin =
            System::Windows::Forms::Padding(4);
        this->flowLayoutPanelServices->Name = L"flowLayoutPanelServices";
        this->flowLayoutPanelServices->Size = System::Drawing::Size(413, 614);
        this->flowLayoutPanelServices->TabIndex = 0;
        //
        // panel1
        //
        this->panel1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel1->BackColor = System::Drawing::Color::White;
        this->panel1->Controls->Add(this->labelHeader);
        this->panel1->Controls->Add(this->panelContent);
        this->panel1->Location = System::Drawing::Point(421, 0);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(457, 614);
        this->panel1->TabIndex = 1;
        //
        // labelHeader
        //
        this->labelHeader->BackColor = System::Drawing::Color::Transparent;
        this->labelHeader->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelHeader->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->labelHeader->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 15.75F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelHeader->ForeColor = System::Drawing::Color::White;
        this->labelHeader->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelHeader->Location = System::Drawing::Point(33, 25);
        this->labelHeader->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelHeader->Name = L"labelHeader";
        this->labelHeader->Size = System::Drawing::Size(389, 58);
        this->labelHeader->TabIndex = 66;
        this->labelHeader->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->labelHeader->Visible = false;
        //
        // panelContent
        //
        this->panelContent->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelContent->BackColor = System::Drawing::Color::White;
        this->panelContent->Controls->Add(this->submitRecurringPayment);
        this->panelContent->Controls->Add(this->label2);
        this->panelContent->Controls->Add(this->panel2);
        this->panelContent->Controls->Add(this->labelReceiver);
        this->panelContent->Controls->Add(this->btnTransfer);
        this->panelContent->Controls->Add(this->panel3);
        this->panelContent->Controls->Add(this->label1);
        this->panelContent->Controls->Add(this->panel4);
        this->panelContent->Controls->Add(this->label5);
        this->panelContent->Location = System::Drawing::Point(16, 43);
        this->panelContent->Margin = System::Windows::Forms::Padding(4);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(427, 518);
        this->panelContent->TabIndex = 0;
        this->panelContent->Visible = false;
        //
        // submitRecurringPayment
        //
        this->submitRecurringPayment->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->submitRecurringPayment->AutoSize = true;
        this->submitRecurringPayment->BackColor =
            System::Drawing::Color::Transparent;
        this->submitRecurringPayment->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->submitRecurringPayment->ForeColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->submitRecurringPayment->Location =
            System::Drawing::Point(17, 381);
        this->submitRecurringPayment->Margin =
            System::Windows::Forms::Padding(4);
        this->submitRecurringPayment->Name = L"submitRecurringPayment";
        this->submitRecurringPayment->Size = System::Drawing::Size(255, 30);
        this->submitRecurringPayment->TabIndex = 67;
        this->submitRecurringPayment->Text = L"Đăng kí thanh toán định kì";
        this->submitRecurringPayment->UseVisualStyleBackColor = false;
        //
        // label2
        //
        this->label2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label2->AutoSize = true;
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(12, 287);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(124, 26);
        this->label2->TabIndex = 66;
        this->label2->Text = L"Nhập mã pin:";
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->pin);
        this->panel2->Location = System::Drawing::Point(13, 317);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(390, 47);
        this->panel2->TabIndex = 64;
        //
        // pin
        //
        this->pin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->pin->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->pin->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->pin->Location = System::Drawing::Point(0, 0);
        this->pin->Margin = System::Windows::Forms::Padding(4);
        this->pin->MaxLength = 10;
        this->pin->Multiline = true;
        this->pin->Name = L"pin";
        this->pin->Size = System::Drawing::Size(386, 44);
        this->pin->TabIndex = 29;
        this->pin->TextChanged += gcnew System::EventHandler(
            this, &ServicePaymentForm::pin_TextChanged);
        //
        // labelReceiver
        //
        this->labelReceiver->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->labelReceiver->AutoSize = true;
        this->labelReceiver->BackColor = System::Drawing::Color::Transparent;
        this->labelReceiver->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelReceiver->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->labelReceiver->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13.8F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelReceiver->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->labelReceiver->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->labelReceiver->Location = System::Drawing::Point(49, 51);
        this->labelReceiver->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelReceiver->Name = L"labelReceiver";
        this->labelReceiver->Size = System::Drawing::Size(259, 30);
        this->labelReceiver->TabIndex = 65;
        this->labelReceiver->Text = L"      THANH TOÁN HÓA ĐƠN";
        //
        // btnTransfer
        //
        this->btnTransfer->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnTransfer->BackColor = System::Drawing::Color::Green;
        this->btnTransfer->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnTransfer->FlatAppearance->BorderColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnTransfer->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Green;
        this->btnTransfer->FlatAppearance->MouseOverBackColor =
            System::Drawing::Color::Green;
        this->btnTransfer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnTransfer->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnTransfer->ForeColor = System::Drawing::Color::White;
        this->btnTransfer->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnTransfer->Location = System::Drawing::Point(17, 424);
        this->btnTransfer->Margin = System::Windows::Forms::Padding(4);
        this->btnTransfer->Name = L"btnTransfer";
        this->btnTransfer->Size = System::Drawing::Size(389, 47);
        this->btnTransfer->TabIndex = 64;
        this->btnTransfer->Text = L"THANH TOÁN";
        this->btnTransfer->UseVisualStyleBackColor = false;
        this->btnTransfer->Click += gcnew System::EventHandler(
            this, &ServicePaymentForm::btnTransfer_Click);
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel3->Controls->Add(this->code);
        this->panel3->Location = System::Drawing::Point(13, 225);
        this->panel3->Margin = System::Windows::Forms::Padding(4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(391, 46);
        this->panel3->TabIndex = 63;
        //
        // code
        //
        this->code->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            (((System::Windows::Forms::AnchorStyles::Top |
               System::Windows::Forms::AnchorStyles::Bottom) |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
        this->code->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->code->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->code->Location = System::Drawing::Point(8, -1);
        this->code->Margin = System::Windows::Forms::Padding(4);
        this->code->MaxLength = 10;
        this->code->Multiline = true;
        this->code->Name = L"code";
        this->code->Size = System::Drawing::Size(381, 46);
        this->code->TabIndex = 29;
        //
        // label1
        //
        this->label1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label1->AutoSize = true;
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(8, 195);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(190, 26);
        this->label1->TabIndex = 62;
        this->label1->Text = L"Nhập mã thanh toán:";
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel4->Controls->Add(this->selectCompanyBox);
        this->panel4->Location = System::Drawing::Point(13, 131);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(393, 46);
        this->panel4->TabIndex = 61;
        //
        // selectCompanyBox
        //
        this->selectCompanyBox->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->selectCompanyBox->FlatStyle =
            System::Windows::Forms::FlatStyle::Popup;
        this->selectCompanyBox->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
        this->selectCompanyBox->ForeColor = System::Drawing::Color::Black;
        this->selectCompanyBox->FormattingEnabled = true;
        this->selectCompanyBox->Location = System::Drawing::Point(8, 8);
        this->selectCompanyBox->Margin = System::Windows::Forms::Padding(4);
        this->selectCompanyBox->Name = L"selectCompanyBox";
        this->selectCompanyBox->Size = System::Drawing::Size(382, 33);
        this->selectCompanyBox->TabIndex = 3;
        this->selectCompanyBox->SelectedIndexChanged +=
            gcnew System::EventHandler(
                this,
                &ServicePaymentForm::selectCompanyBox_SelectedIndexChanged);
        //
        // label5
        //
        this->label5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->BackColor = System::Drawing::Color::Transparent;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(8, 101);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(128, 26);
        this->label5->TabIndex = 60;
        this->label5->Text = L"Chọn công ty:";
        this->label5->Click +=
            gcnew System::EventHandler(this, &ServicePaymentForm::label5_Click);
        //
        // ServicePaymentForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(877, 614);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->flowLayoutPanelServices);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"ServicePaymentForm";
        this->Text = L"ServicePaymentForm";
        this->panel1->ResumeLayout(false);
        this->panelContent->ResumeLayout(false);
        this->panelContent->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    String ^ currComapnyAccNumber = "";

  private:
    void LoadServices();

    void OnServiceClick(Object ^ sender, EventArgs ^ e);

    void loadFormTransfer(String^ serviceId);
    System::Void selectCompanyBox_SelectedIndexChanged(System::Object ^ sender,
                                                       System::EventArgs ^ e);
    System::Void btnTransfer_Click(System::Object ^ sender,
                                   System::EventArgs ^ e);

    System::Void label5_Click(System::Object ^ sender, System::EventArgs ^ e) {}


    void onSubmitCurrentPayment(String^ userAccountNumber, String^ companyAccountNumber,
                                int monthly);

private:
    System::Void pin_TextChanged(System::Object ^ sender,
                                 System::EventArgs ^ e) {}
};
} // namespace BankingAppwinform