#pragma once
#include "RegisterSavingForm.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for ClientSavingMoneyForm
/// </summary>
public
ref class ClientSavingMoneyForm : public System::Windows::Forms::Form {
  public:
    ClientSavingMoneyForm(void) {
        InitializeComponent();
        loadSavingCustomers();
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~ClientSavingMoneyForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Label ^ btnTermDeposit;

  protected:
  private:
  private:
    System::Windows::Forms::Label ^ btnNonTermDeposit;

  protected:
  private:
  protected:
  private:
  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutSavingMoney;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Label ^ label6;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::Label ^ label13;

  private:
    System::Windows::Forms::Label ^ label14;

  private:
    System::Windows::Forms::Label ^ label15;

  private:
    System::Windows::Forms::Label ^ label16;

  private:
    System::Windows::Forms::Label ^ label17;

  private:
    System::Windows::Forms::Label ^ label18;

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
        this->btnTermDeposit = (gcnew System::Windows::Forms::Label());
        this->btnNonTermDeposit = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->flowLayoutSavingMoney =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->label13 = (gcnew System::Windows::Forms::Label());
        this->label14 = (gcnew System::Windows::Forms::Label());
        this->label15 = (gcnew System::Windows::Forms::Label());
        this->label16 = (gcnew System::Windows::Forms::Label());
        this->label17 = (gcnew System::Windows::Forms::Label());
        this->label18 = (gcnew System::Windows::Forms::Label());
        this->flowLayoutSavingMoney->SuspendLayout();
        this->panel1->SuspendLayout();
        this->panel3->SuspendLayout();
        this->SuspendLayout();
        //
        // btnTermDeposit
        //
        this->btnTermDeposit->AllowDrop = true;
        this->btnTermDeposit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnTermDeposit->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnTermDeposit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnTermDeposit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->btnTermDeposit->ForeColor =
            System::Drawing::SystemColors::ButtonHighlight;
        this->btnTermDeposit->Location = System::Drawing::Point(52, 30);
        this->btnTermDeposit->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->btnTermDeposit->Name = L"btnTermDeposit";
        this->btnTermDeposit->Size = System::Drawing::Size(767, 85);
        this->btnTermDeposit->TabIndex = 1;
        this->btnTermDeposit->Text = L"GỬI TIẾT KIỆM CÓ KÌ HẠN (6% / NĂM)";
        this->btnTermDeposit->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->btnTermDeposit->Click += gcnew System::EventHandler(
            this, &ClientSavingMoneyForm::btnTermDeposit_Click);
        //
        // btnNonTermDeposit
        //
        this->btnNonTermDeposit->AllowDrop = true;
        this->btnNonTermDeposit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnNonTermDeposit->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnNonTermDeposit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnNonTermDeposit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->btnNonTermDeposit->ForeColor =
            System::Drawing::SystemColors::ButtonHighlight;
        this->btnNonTermDeposit->Location = System::Drawing::Point(52, 131);
        this->btnNonTermDeposit->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->btnNonTermDeposit->Name = L"btnNonTermDeposit";
        this->btnNonTermDeposit->Size = System::Drawing::Size(767, 85);
        this->btnNonTermDeposit->TabIndex = 2;
        this->btnNonTermDeposit->Text =
            L"GỬI TIẾT KIỆM KHÔNG KÌ HẠN (4% / NĂM)";
        this->btnNonTermDeposit->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        this->btnNonTermDeposit->Click += gcnew System::EventHandler(
            this, &ClientSavingMoneyForm::btnNonTermDeposit_Click);
        //
        // label3
        //
        this->label3->AllowDrop = true;
        this->label3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label3->BackColor = System::Drawing::Color::Transparent;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label3->ForeColor =
            System::Drawing::SystemColors::ButtonHighlight;
        this->label3->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->label3->Location = System::Drawing::Point(52, 246);
        this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(767, 47);
        this->label3->TabIndex = 3;
        this->label3->Text = L"DANH SÁCH CÁC GÓI TIẾT KIỆM ĐÃ GỬI:";
        this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        //
        // flowLayoutSavingMoney
        //
        this->flowLayoutSavingMoney->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Bottom) |
                 System::Windows::Forms::AnchorStyles::Left));
        this->flowLayoutSavingMoney->AutoScroll = true;
        this->flowLayoutSavingMoney->BackColor = System::Drawing::Color::Teal;
        this->flowLayoutSavingMoney->Controls->Add(this->panel1);
        this->flowLayoutSavingMoney->Controls->Add(this->panel3);
        this->flowLayoutSavingMoney->Location = System::Drawing::Point(56, 296);
        this->flowLayoutSavingMoney->Name = L"flowLayoutSavingMoney";
        this->flowLayoutSavingMoney->Size = System::Drawing::Size(763, 283);
        this->flowLayoutSavingMoney->TabIndex = 4;
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel1->Controls->Add(this->label6);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->label4);
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->labelAuth);
        this->panel1->Location = System::Drawing::Point(3, 3);
        this->panel1->Name = L"panel1";
        this->panel1->Padding = System::Windows::Forms::Padding(0, 10, 0, 0);
        this->panel1->Size = System::Drawing::Size(733, 166);
        this->panel1->TabIndex = 0;
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label6->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 7.8F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label6->ForeColor = System::Drawing::Color::Transparent;
        this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label6->Location = System::Drawing::Point(541, 134);
        this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(188, 17);
        this->label6->TabIndex = 45;
        this->label6->Text = L"Ấn vào đây để kết thúc tiết kiệm";
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(16, 102);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(323, 23);
        this->label5->TabIndex = 44;
        this->label5->Text = L"Số tiền thực nhận đến hiện tại: 2050000VNĐ";
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label4->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label4->ForeColor = System::Drawing::Color::Transparent;
        this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label4->Location = System::Drawing::Point(16, 79);
        this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(175, 23);
        this->label4->TabIndex = 43;
        this->label4->Text = L"Lãi xuất hàng năm: 4%";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->ForeColor = System::Drawing::Color::Transparent;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(16, 56);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(171, 23);
        this->label2->TabIndex = 42;
        this->label2->Text = L"Ngày gửi: 06/04/2025";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::Transparent;
        this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label1->Location = System::Drawing::Point(16, 33);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(190, 23);
        this->label1->TabIndex = 41;
        this->label1->Text = L"Số tiền gửi: 2000000VND";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(16, 10);
        this->labelAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(202, 23);
        this->labelAuth->TabIndex = 40;
        this->labelAuth->Text = L"Loại tiết kiện: Không kì hạn";
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panel3->Controls->Add(this->label13);
        this->panel3->Controls->Add(this->label14);
        this->panel3->Controls->Add(this->label15);
        this->panel3->Controls->Add(this->label16);
        this->panel3->Controls->Add(this->label17);
        this->panel3->Controls->Add(this->label18);
        this->panel3->Location = System::Drawing::Point(3, 175);
        this->panel3->Name = L"panel3";
        this->panel3->Padding = System::Windows::Forms::Padding(0, 10, 0, 0);
        this->panel3->Size = System::Drawing::Size(733, 166);
        this->panel3->TabIndex = 1;
        //
        // label13
        //
        this->label13->AutoSize = true;
        this->label13->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label13->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 7.8F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label13->ForeColor = System::Drawing::Color::Transparent;
        this->label13->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label13->Location = System::Drawing::Point(558, 135);
        this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label13->Name = L"label13";
        this->label13->Size = System::Drawing::Size(188, 17);
        this->label13->TabIndex = 45;
        this->label13->Text = L"Ấn vào đây để kết thúc tiết kiệm";
        //
        // label14
        //
        this->label14->AutoSize = true;
        this->label14->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label14->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label14->ForeColor = System::Drawing::Color::Transparent;
        this->label14->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label14->Location = System::Drawing::Point(16, 102);
        this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label14->Name = L"label14";
        this->label14->Size = System::Drawing::Size(323, 23);
        this->label14->TabIndex = 44;
        this->label14->Text = L"Số tiền thực nhận đến hiện tại: 2050000VNĐ";
        //
        // label15
        //
        this->label15->AutoSize = true;
        this->label15->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label15->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label15->ForeColor = System::Drawing::Color::Transparent;
        this->label15->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label15->Location = System::Drawing::Point(16, 79);
        this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label15->Name = L"label15";
        this->label15->Size = System::Drawing::Size(175, 23);
        this->label15->TabIndex = 43;
        this->label15->Text = L"Lãi xuất hàng năm: 4%";
        //
        // label16
        //
        this->label16->AutoSize = true;
        this->label16->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label16->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label16->ForeColor = System::Drawing::Color::Transparent;
        this->label16->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label16->Location = System::Drawing::Point(16, 56);
        this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label16->Name = L"label16";
        this->label16->Size = System::Drawing::Size(171, 23);
        this->label16->TabIndex = 42;
        this->label16->Text = L"Ngày gửi: 06/04/2025";
        //
        // label17
        //
        this->label17->AutoSize = true;
        this->label17->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label17->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label17->ForeColor = System::Drawing::Color::Transparent;
        this->label17->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label17->Location = System::Drawing::Point(16, 33);
        this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label17->Name = L"label17";
        this->label17->Size = System::Drawing::Size(190, 23);
        this->label17->TabIndex = 41;
        this->label17->Text = L"Số tiền gửi: 2000000VND";
        //
        // label18
        //
        this->label18->AutoSize = true;
        this->label18->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label18->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 10.2F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label18->ForeColor = System::Drawing::Color::Transparent;
        this->label18->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label18->Location = System::Drawing::Point(16, 10);
        this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label18->Name = L"label18";
        this->label18->Size = System::Drawing::Size(202, 23);
        this->label18->TabIndex = 40;
        this->label18->Text = L"Loại tiết kiện: Không kì hạn";
        //
        // ClientSavingMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(877, 614);
        this->Controls->Add(this->flowLayoutSavingMoney);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->btnNonTermDeposit);
        this->Controls->Add(this->btnTermDeposit);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"ClientSavingMoneyForm";
        this->Text = L"ClientSavingMoneyForm";
        this->flowLayoutSavingMoney->ResumeLayout(false);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void btnTermDeposit_Click(System::Object ^ sender,
                                      System::EventArgs ^ e) {
        RegisterSavingForm ^ registerSavingForm =
            gcnew RegisterSavingForm("termDeposit");
            registerSavingForm->ShowDialog();
    }

  private:
    System::Void btnNonTermDeposit_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
        RegisterSavingForm ^ registerSavingForm =
            gcnew RegisterSavingForm("nonTermDeposit");
            registerSavingForm->ShowDialog();
    }

    void loadSavingCustomers() {

        flowLayoutSavingMoney->Controls->Clear();

        array<SavingCustomers ^> ^ savingItems =
            HandleFile::ReadSavingCustomersArray("savingCustomers.dat");

        if (savingItems == nullptr || savingItems->Length == 0) {
            Label ^ noSavingLabel = gcnew Label();
            noSavingLabel->Text = L"Chưa có tiết kiệm nào";
            noSavingLabel->ForeColor = Color::White;
            noSavingLabel->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            noSavingLabel->AutoSize = true;
            flowLayoutSavingMoney->Controls->Add(noSavingLabel);
            return;
        }

        for each (SavingCustomers ^ saving in savingItems) {
            AddSavingItemToFlow(saving);
        }
    }


    void AddSavingItemToFlow(SavingCustomers ^ saving) {
        // Panel đại diện cho 1 saving item
        Panel ^ itemPanel = gcnew Panel();
        itemPanel->BorderStyle = BorderStyle::FixedSingle;
        itemPanel->BackColor = Color::FromArgb(0, 64, 64);
        itemPanel->Width = flowLayoutSavingMoney->ClientSize.Width - 25;

        itemPanel->Height = 150; // đặt chiều cao cố định vừa đủ, có thể chỉnh
        itemPanel->Margin =
            System::Windows::Forms::Padding(0, 0, 0, 10); // cách giữa các item
        itemPanel->Dock =
            DockStyle::Top; // giúp fill ngang nếu flowLayoutPanel cho phép
        itemPanel->Anchor = AnchorStyles::Left | AnchorStyles::Right;

        // Label nội dung
        Label ^ label = gcnew Label();
        label->AutoSize = false;
        label->ForeColor = Color::White;
        label->Font = gcnew System::Drawing::Font("Segoe UI", 10);
        label->TextAlign = ContentAlignment::TopLeft;
        label->Padding =
            System::Windows::Forms::Padding(5); // padding bên trong
        label->Dock = DockStyle::Top;
        label->Height = 120; // cố định chiều cao

        // Tính số tiền thực nhận
        TimeSpan duration = DateTime::Now - saving->DepositDate;
        double receivedAmount =
            saving->Amount + (saving->Amount * saving->InterestRate *
                              duration.Days / 365.0 / 100.0);

        // Chuẩn bị nội dung
        String ^ content = String::Format(
            L"Loại tiết kiệm: {0}, {1}\n"
            L"Số tiền gửi: {2:N0}VNĐ\n"
            L"Ngày gửi: {3:dd/MM/yyyy}\n"
            L"Lãi suất hàng năm: {4}\n"
            L"Số tiền thực nhận đến hiện tại: {5:N0}VNĐ",
            saving->Type == "nonTermDeposit" ? L"Không kì hạn" : L"Có kì hạn",
            saving->Term == 0 ? L"" : saving->Term + L" tháng",
            saving->Amount, saving->DepositDate, saving->InterestRate,
            receivedAmount);

        label->Text = content;

        // Label kết thúc tiết kiệm
        Label ^ endLabel = gcnew Label();
        endLabel->Text = L"Ấn vào đây để kết thúc tiết kiệm";
        endLabel->ForeColor = Color::LightYellow;
        endLabel->Font =
            gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Italic);
        endLabel->AutoSize = false;
        endLabel->Dock = DockStyle::Bottom;
        endLabel->TextAlign = ContentAlignment::MiddleRight;
        endLabel->Padding = System::Windows::Forms::Padding(0, 0, 10, 5);
        endLabel->Height = 25;
        endLabel->Cursor = Cursors::Hand; // cho biết label có thể bấm
        endLabel->Click +=
            gcnew EventHandler(this, &ClientSavingMoneyForm::EndSaving_Click);
        itemPanel->Tag =
            saving; // Gán saving vào tag của panel để truy cập sau này

        // Add vào panel
        itemPanel->Controls->Add(endLabel);
        itemPanel->Controls->Add(label);

        // Thêm vào flowPanel
        flowLayoutSavingMoney->Controls->Add(itemPanel);
    }


    private:
    System::Void EndSaving_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        Label ^ clickedLabel = dynamic_cast<Label ^>(sender);
        if (clickedLabel != nullptr) {
            Panel ^ parentPanel = dynamic_cast<Panel ^>(clickedLabel->Parent);
            if (parentPanel != nullptr) {
                // Bạn có thể thêm Tag cho panel để chứa SavingCustomers
                SavingCustomers ^ saving =
                    dynamic_cast<SavingCustomers ^>(parentPanel->Tag);

                if (saving != nullptr) {
                    // Xử lý logic kết thúc tiết kiệm ở đây
                    MessageBox::Show(
                        "Bạn đã kết thúc tiết kiệm của tài khoản: " +
                            saving->Id,
                        "Thông báo", MessageBoxButtons::OK,
                        MessageBoxIcon::Information);
                }
            }
        }
    }




};
} // namespace BankingAppwinform
