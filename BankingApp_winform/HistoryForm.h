#pragma once
#include "Transaction.h"
#include "HandleFile.h"
#include "GlobalData.h"

namespace BankingAppwinform {
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class HistoryForm : public System::Windows::Forms::Form {
  public:
    HistoryForm(void) {
        InitializeComponent();
        array<String ^> ^ transactions = {"+300000 VND", "-500000 VND",
                                          "+2000000 VND", "-100000 VND",
                                          "dsdsdsd",
                                          "dsdsdsd",     "dsdsdsd",      "dsdsdsds"};

        // Thêm các panel giao dịch
        int index = 0; // Biến đếm để tạo tên duy nhất
        for each (String ^ transaction in transactions) {
            AddTransactionPanel(transaction, index);
            index++;
        }

        // Cập nhật giao diện
        panelContainer->PerformLayout();

    }
    void AddTransactionPanel(String ^ transactionInfo, int index) {
        Panel ^ panel = gcnew Panel();
        panel->BackColor = Color::FromArgb(28, 107, 107); // Màu xanh đậm từ ảnh
        panel->Padding = System::Windows::Forms::Padding(0);
        panel->Height = 120; // Chiều cao cố định

        // Tính chiều rộng chính xác để tránh trống bên phải
        int containerWidth = panelContainer->ClientSize.Width;
        int panelWidth = containerWidth - 15;
            //Math::Floor(containerWidth / 2.0) - 15; // Trừ 5px để tránh tràn

        panel->Width = panelWidth;

        // Đặt Anchor để panel giãn theo form
        panel->Anchor =
            AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right;

        // Đặt tên duy nhất
        panel->Name = "panel_" + index.ToString();

        Label ^ lblTransaction = gcnew Label();
        lblTransaction->Text = "Giao dịch: " + transactionInfo;
        lblTransaction->ForeColor = Color::White;
        lblTransaction->Dock = DockStyle::Top;
        lblTransaction->AutoSize = true;

        panel->Controls->Add(lblTransaction);
        panelContainer->Controls->Add(panel);
    }

    // Cập nhật kích thước Panel khi Form thay đổi kích thước
    void OnResize(Object ^ sender, EventArgs ^ e) {
        int containerWidth = panelContainer->ClientSize.Width;
        for each (Control ^ panel in panelContainer->Controls) {
            panel->Width = containerWidth - 15 ;
        }
    }

  protected:
    ~HistoryForm() {
        if (components) {
            delete components;
        }
    }

  private:





    System::ComponentModel::Container ^ components;

    String ^ activePanel = "TRANSFER";

  private:
    System::Windows::Forms::Panel ^ panelNav;

  private:


  private:
    System::Windows::Forms::Button ^ btnActiveWithDrawList;

  private:


  private:
    System::Windows::Forms::Button ^ btnActiveTransferList;

  private:
    System::Windows::Forms::Panel ^ panelBtn2;

  private:
    System::Windows::Forms::Panel ^ panelBtn1;

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
    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::FlowLayoutPanel ^ panelContainer;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Label ^ label13;

  private:
    System::Windows::Forms::Label ^ label11;

  private:
    System::Windows::Forms::Label ^ label12;

  private:
    System::Windows::Forms::Label ^ label9;

  private:
    System::Windows::Forms::Label ^ label10;

  private:
    System::Windows::Forms::Label ^ label7;

  private:
    System::Windows::Forms::Label ^ label8;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Label ^ label6;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanel1;

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


  private:

    array<Transaction ^> ^ transactions;

    void loadContent(array<Transaction ^> ^ transactions, Panel ^ panel, String ^ type) {

        int yOffset = 10;
        panel->Controls->Clear();

        //Label ^ headerText = gcnew Label();
        //headerText->ForeColor = Color::Black;
        //headerText->Font =
        //    gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
        //headerText->AutoSize = true;
        //headerText->Location = System::Drawing::Point(10, yOffset);

        //if (transactions == nullptr) {
        //    headerText->Text = "CHUA CO LICH SU GIAO DICH";
        //    panel->Controls->Add(headerText);
        //    return;
        //} else if (type == "TRANSFER") {
        //    headerText->Text = "LICH SU CHUYEN KHOAN";
        //    panel->Controls->Add(headerText);
        //    yOffset += 30;
        //} else {
        //    headerText->Text = "LICH SU RUT TIEN";
        //    panel->Controls->Add(headerText);
        //    yOffset += 30;
        //}


        //for each (Transaction ^ transaction in transactions) {
        //    Label ^ lblTransaction = gcnew Label();
        //    if (transaction->getToAccount() == 0 && type == "WITHDRAW") {
        //        lblTransaction->Text =
        //            "Rut tien: " + transaction->getAmount().ToString("N0") +
        //            " VND - " + transaction->getCreatedAt();
        //        lblTransaction->ForeColor = Color::Red;
        //    } else if (type == "TRANSFER") {
        //        if (transaction->getFromAccount() ==
        //                 GlobalData::GetCurrentUser()->getAccountNumber()) {
        //            lblTransaction->Text =
        //                "Chuyen tien: " +
        //                transaction->getAmount().ToString("N0") +
        //                " VND - den: " + transaction->getToAccount() + " - " +
        //                transaction->getCreatedAt();
        //            lblTransaction->ForeColor = Color::Red;
        //        }
        //        else {
        //            lblTransaction->Text =
        //                "nhan tien: " +
        //                transaction->getAmount().ToString("N0") +
        //                " VND - tu: " + transaction->getFromAccount() + " - " +
        //                transaction->getCreatedAt();
        //            lblTransaction->ForeColor = Color::Green;
        //        }
        //    }
        //    //lblTransaction->ForeColor = Color::Red;
        //    lblTransaction->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
        //    lblTransaction->AutoSize = true;
        //    lblTransaction->Location = System::Drawing::Point(10, yOffset);
        //    panel->Controls->Add(lblTransaction);
        //    yOffset += 30;
        //}
    }



#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->panelBtn2 = (gcnew System::Windows::Forms::Panel());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->btnActiveWithDrawList = (gcnew System::Windows::Forms::Button());
        this->panelBtn1 = (gcnew System::Windows::Forms::Panel());
        this->btnActiveTransferList = (gcnew System::Windows::Forms::Button());
        this->panelContainer =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label13 = (gcnew System::Windows::Forms::Label());
        this->label11 = (gcnew System::Windows::Forms::Label());
        this->label12 = (gcnew System::Windows::Forms::Label());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->label10 = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->label8 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->flowLayoutPanel1 =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panelNav->SuspendLayout();
        this->panelBtn2->SuspendLayout();
        this->panelBtn1->SuspendLayout();
        this->panelContainer->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::Color::Teal;
        this->panelNav->Controls->Add(this->panelBtn2);
        this->panelNav->Controls->Add(this->panelBtn1);
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Top;
        this->panelNav->Location = System::Drawing::Point(0, 0);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(658, 44);
        this->panelNav->TabIndex = 1;
        this->panelNav->SizeChanged += gcnew System::EventHandler(
            this, &HistoryForm::panelNav_SizeChanged);
        //
        // panelBtn2
        //
        this->panelBtn2->Controls->Add(this->panelContent);
        this->panelBtn2->Controls->Add(this->btnActiveWithDrawList);
        this->panelBtn2->Location = System::Drawing::Point(332, 0);
        this->panelBtn2->Name = L"panelBtn2";
        this->panelBtn2->Size = System::Drawing::Size(326, 44);
        this->panelBtn2->TabIndex = 1;
        //
        // panelContent
        //
        this->panelContent->Location = System::Drawing::Point(38, 13);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(55, 25);
        this->panelContent->TabIndex = 25;
        //
        // btnActiveWithDrawList
        //
        this->btnActiveWithDrawList->BackColor =
            System::Drawing::Color::Transparent;
        this->btnActiveWithDrawList->Cursor =
            System::Windows::Forms::Cursors::Hand;
        this->btnActiveWithDrawList->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->btnActiveWithDrawList->FlatAppearance->BorderSize = 0;
        this->btnActiveWithDrawList->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnActiveWithDrawList->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnActiveWithDrawList->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->btnActiveWithDrawList->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnActiveWithDrawList->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnActiveWithDrawList->Location = System::Drawing::Point(0, 0);
        this->btnActiveWithDrawList->Name = L"btnActiveWithDrawList";
        this->btnActiveWithDrawList->Size = System::Drawing::Size(326, 44);
        this->btnActiveWithDrawList->TabIndex = 24;
        this->btnActiveWithDrawList->Text = L"LỊCH SỬ RÚT TIỀN";
        this->btnActiveWithDrawList->UseVisualStyleBackColor = false;
        this->btnActiveWithDrawList->Click += gcnew System::EventHandler(
            this, &HistoryForm::btnActiveWithDrawList_Click);
        //
        // panelBtn1
        //
        this->panelBtn1->Controls->Add(this->btnActiveTransferList);
        this->panelBtn1->Location = System::Drawing::Point(0, 0);
        this->panelBtn1->Name = L"panelBtn1";
        this->panelBtn1->Size = System::Drawing::Size(335, 44);
        this->panelBtn1->TabIndex = 0;
        //
        // btnActiveTransferList
        //
        this->btnActiveTransferList->BackColor =
            System::Drawing::Color::Transparent;
        this->btnActiveTransferList->Cursor =
            System::Windows::Forms::Cursors::Hand;
        this->btnActiveTransferList->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->btnActiveTransferList->FlatAppearance->BorderSize = 0;
        this->btnActiveTransferList->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnActiveTransferList->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnActiveTransferList->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->btnActiveTransferList->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnActiveTransferList->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnActiveTransferList->Location = System::Drawing::Point(0, 0);
        this->btnActiveTransferList->Name = L"btnActiveTransferList";
        this->btnActiveTransferList->Size = System::Drawing::Size(335, 44);
        this->btnActiveTransferList->TabIndex = 23;
        this->btnActiveTransferList->Text = L"LỊCH SỬ CHUYỂN KHOẢN";
        this->btnActiveTransferList->UseVisualStyleBackColor = false;
        this->btnActiveTransferList->Click += gcnew System::EventHandler(
            this, &HistoryForm::btnActiveTransferList_Click);
        //
        // panelContainer
        //
        this->panelContainer->AutoScroll = true;
        this->panelContainer->BackColor = System::Drawing::Color::Teal;
        this->panelContainer->Controls->Add(this->panel2);
        this->panelContainer->Dock = System::Windows::Forms::DockStyle::Left;
        this->panelContainer->Location = System::Drawing::Point(0, 44);
        this->panelContainer->Margin = System::Windows::Forms::Padding(0);
        this->panelContainer->Name = L"panelContainer";
        this->panelContainer->Size = System::Drawing::Size(329, 455);
        this->panelContainer->TabIndex = 2;
        this->panelContainer->Resize +=
            gcnew System::EventHandler(this, &HistoryForm::OnResize);
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::CadetBlue;
        this->panel2->Controls->Add(this->label13);
        this->panel2->Controls->Add(this->label11);
        this->panel2->Controls->Add(this->label12);
        this->panel2->Controls->Add(this->label9);
        this->panel2->Controls->Add(this->label10);
        this->panel2->Controls->Add(this->label7);
        this->panel2->Controls->Add(this->label8);
        this->panel2->Controls->Add(this->label5);
        this->panel2->Controls->Add(this->label6);
        this->panel2->Controls->Add(this->label4);
        this->panel2->Controls->Add(this->label3);
        this->panel2->Controls->Add(this->label2);
        this->panel2->Controls->Add(this->label1);
        this->panel2->Location = System::Drawing::Point(3, 3);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(282, 208);
        this->panel2->TabIndex = 5;
        this->panel2->Visible = false;
        //
        // label13
        //
        this->label13->AutoSize = true;
        this->label13->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label13->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label13->Location = System::Drawing::Point(148, 38);
        this->label13->Name = L"label13";
        this->label13->Size = System::Drawing::Size(121, 18);
        this->label13->TabIndex = 12;
        this->label13->Text = L"18:00 02/03/2025";
        //
        // label11
        //
        this->label11->AutoSize = true;
        this->label11->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label11->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label11->Location = System::Drawing::Point(125, 178);
        this->label11->Name = L"label11";
        this->label11->Size = System::Drawing::Size(99, 18);
        this->label11->TabIndex = 11;
        this->label11->Text = L"NGUYEN VAN A";
        //
        // label12
        //
        this->label12->AutoSize = true;
        this->label12->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label12->Location = System::Drawing::Point(16, 178);
        this->label12->Name = L"label12";
        this->label12->Size = System::Drawing::Size(100, 18);
        this->label12->TabIndex = 10;
        this->label12->Text = L"Tên người gửi: ";
        //
        // label9
        //
        this->label9->AutoSize = true;
        this->label9->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label9->ForeColor = System::Drawing::Color::White;
        this->label9->Location = System::Drawing::Point(121, 153);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(76, 18);
        this->label9->TabIndex = 9;
        this->label9->Text = L"123456789";
        //
        // label10
        //
        this->label10->AutoSize = true;
        this->label10->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label10->Location = System::Drawing::Point(16, 153);
        this->label10->Name = L"label10";
        this->label10->Size = System::Drawing::Size(99, 18);
        this->label10->TabIndex = 8;
        this->label10->Text = L"STK người gửi: ";
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label7->ForeColor = System::Drawing::SystemColors::ButtonFace;
        this->label7->Location = System::Drawing::Point(100, 125);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(162, 18);
        this->label7->TabIndex = 7;
        this->label7->Text = L"LE SI TOAN chuyen khoan";
        //
        // label8
        //
        this->label8->AutoSize = true;
        this->label8->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label8->Location = System::Drawing::Point(16, 125);
        this->label8->Name = L"label8";
        this->label8->Size = System::Drawing::Size(71, 18);
        this->label8->TabIndex = 6;
        this->label8->Text = L"Nội dung: ";
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label5->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(192)));
        this->label5->Location = System::Drawing::Point(100, 96);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(91, 18);
        this->label5->TabIndex = 5;
        this->label5->Text = L"1200000 VNĐ";
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label6->Location = System::Drawing::Point(16, 96);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(75, 18);
        this->label6->TabIndex = 4;
        this->label6->Text = L"Số dư cuối:";
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label4->ForeColor = System::Drawing::Color::Lime;
        this->label4->Location = System::Drawing::Point(100, 67);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(91, 18);
        this->label4->TabIndex = 3;
        this->label4->Text = L"+300000 VNĐ";
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label3->Location = System::Drawing::Point(16, 67);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(78, 18);
        this->label3->TabIndex = 2;
        this->label3->Text = L"Số tiền GD: ";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label2->Location = System::Drawing::Point(16, 38);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(128, 18);
        this->label2->TabIndex = 1;
        this->label2->Text = L"Thời gian giao dịch:";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label1->Location = System::Drawing::Point(16, 10);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(237, 18);
        this->label1->TabIndex = 0;
        this->label1->Text = L"NGÂN HÀNG xin thông báo quý khách";
        //
        // flowLayoutPanel1
        //
        this->flowLayoutPanel1->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Right;
        this->flowLayoutPanel1->Location = System::Drawing::Point(335, 44);
        this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
        this->flowLayoutPanel1->Size = System::Drawing::Size(323, 455);
        this->flowLayoutPanel1->TabIndex = 3;
        //
        // HistoryForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(658, 499);
        this->Controls->Add(this->flowLayoutPanel1);
        this->Controls->Add(this->panelContainer);
        this->Controls->Add(this->panelNav);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"HistoryForm";
        this->Text = L"HistoryForm";
        this->Load +=
            gcnew System::EventHandler(this, &HistoryForm::HistoryForm_Load);
        this->panelNav->ResumeLayout(false);
        this->panelBtn2->ResumeLayout(false);
        this->panelBtn1->ResumeLayout(false);
        this->panelContainer->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->ResumeLayout(false);
    }

#pragma endregion


  private:
    System::Void HistoryForm_Load(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        transactions = HandleFile::ReadTransactionArray("transactions.dat");
        //loadContent(transactions, panelContent, "TRANSFER");
    }
  private:
    System::Void btnActiveTransferList_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
        ChangeButtonColor(btnActiveTransferList);
        if (activePanel == "TRANSFER") {
            return;
        } else {
            activePanel = "TRANSFER";
            loadContent(transactions, panelContent, "TRANSFER");
        }
    }

  private:
    System::Void btnActiveWithDrawList_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
        ChangeButtonColor(btnActiveWithDrawList);
        if (activePanel == "WITHDRAW") {
            return;
        } else {
            activePanel = "WITHDRAW";
            loadContent(transactions, panelContent, "WITHDRAW");
        }
    }

    private:
    Button ^ selectedButton = nullptr;
    void ChangeButtonColor(Button ^ button) {
        if (selectedButton != nullptr) {
            selectedButton->BackColor = System::Drawing::Color::Teal;
        }
        selectedButton = button;
        selectedButton->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
    }

  
private:
    System::Void panelNav_SizeChanged(System::Object ^ sender,
                                      System::EventArgs ^ e) {
      int parentWidth = panelNav->ClientSize.Width;
      int panelWidth = parentWidth / 2;
      this->panelBtn1->Width = panelWidth;
      this->panelBtn1->Left = 0;

      this->panelBtn2->Width = panelWidth;
      this->panelBtn2->Left = panelWidth;  
    }
};
}
