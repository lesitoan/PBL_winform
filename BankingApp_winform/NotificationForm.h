﻿#pragma once
#include "Notifications.h"
#include "HandleFile.h"
#include "GlobalData.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for NotificationForm
/// </summary>
public
ref class NotificationForm : public System::Windows::Forms::Form {
  public:
    NotificationForm(void) {
        InitializeComponent();
        loadNotifications();
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~NotificationForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutContainer;

  protected:
  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::Label ^ label13;

  private:
    System::Windows::Forms::Label ^ label9;

  private:
    System::Windows::Forms::Label ^ label10;

  private:
    System::Windows::Forms::Label ^ label11;

  private:
    System::Windows::Forms::Label ^ label12;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Label ^ label14;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Label ^ label6;

  private:
    System::Windows::Forms::Label ^ label7;

  private:
    System::Windows::Forms::Label ^ label8;

  private:
    System::Windows::Forms::Label ^ label15;

  private:
    System::Windows::Forms::Label ^ label4;

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
        this->flowLayoutContainer =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->label13 = (gcnew System::Windows::Forms::Label());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->label10 = (gcnew System::Windows::Forms::Label());
        this->label11 = (gcnew System::Windows::Forms::Label());
        this->label12 = (gcnew System::Windows::Forms::Label());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label14 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->label8 = (gcnew System::Windows::Forms::Label());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label15 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->flowLayoutContainer->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // flowLayoutContainer
        //
        this->flowLayoutContainer->AutoScroll = true;
        this->flowLayoutContainer->Controls->Add(this->panel3);
        this->flowLayoutContainer->Controls->Add(this->panel2);
        this->flowLayoutContainer->Controls->Add(this->panel1);
        this->flowLayoutContainer->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->flowLayoutContainer->Location = System::Drawing::Point(0, 0);
        this->flowLayoutContainer->Name = L"flowLayoutContainer";
        this->flowLayoutContainer->Size = System::Drawing::Size(400, 401);
        this->flowLayoutContainer->TabIndex = 0;
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::SystemColors::ControlLight;
        this->panel3->Controls->Add(this->label13);
        this->panel3->Controls->Add(this->label9);
        this->panel3->Controls->Add(this->label10);
        this->panel3->Controls->Add(this->label11);
        this->panel3->Controls->Add(this->label12);
        this->panel3->Location = System::Drawing::Point(8, 8);
        this->panel3->Margin = System::Windows::Forms::Padding(8);
        this->panel3->Name = L"panel3";
        this->panel3->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
        this->panel3->Size = System::Drawing::Size(367, 89);
        this->panel3->TabIndex = 5;
        this->panel3->Visible = false;
        //
        // label13
        //
        this->label13->AutoSize = true;
        this->label13->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label13->Location = System::Drawing::Point(90, 10);
        this->label13->Name = L"label13";
        this->label13->Size = System::Drawing::Size(110, 13);
        this->label13->TabIndex = 4;
        this->label13->Text = L"12:00:00 03/02/2025";
        //
        // label9
        //
        this->label9->AutoSize = true;
        this->label9->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label9->Location = System::Drawing::Point(263, 64);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(92, 13);
        this->label9->TabIndex = 3;
        this->label9->Text = L"Đánh dấu đã đọc";
        //
        // label10
        //
        this->label10->AutoSize = true;
        this->label10->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label10->Location = System::Drawing::Point(4, 39);
        this->label10->Name = L"label10";
        this->label10->Size = System::Drawing::Size(327, 16);
        this->label10->TabIndex = 2;
        this->label10->Text =
            L"hãy nộp thêm tiền vào tài khoản để tiến hành giao dịch";
        //
        // label11
        //
        this->label11->AutoSize = true;
        this->label11->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label11->Location = System::Drawing::Point(3, 23);
        this->label11->Name = L"label11";
        this->label11->Size = System::Drawing::Size(310, 16);
        this->label11->TabIndex = 1;
        this->label11->Text =
            L"Thanh toán định kì của quý khách chưa haofn thành,";
        //
        // label12
        //
        this->label12->AutoSize = true;
        this->label12->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label12->Location = System::Drawing::Point(4, 10);
        this->label12->Name = L"label12";
        this->label12->Size = System::Drawing::Size(80, 13);
        this->label12->TabIndex = 0;
        this->label12->Text = L"THÔNG BÁO";
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
        this->panel2->Controls->Add(this->label14);
        this->panel2->Controls->Add(this->label5);
        this->panel2->Controls->Add(this->label6);
        this->panel2->Controls->Add(this->label7);
        this->panel2->Controls->Add(this->label8);
        this->panel2->Location = System::Drawing::Point(8, 113);
        this->panel2->Margin = System::Windows::Forms::Padding(8);
        this->panel2->Name = L"panel2";
        this->panel2->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
        this->panel2->Size = System::Drawing::Size(367, 89);
        this->panel2->TabIndex = 4;
        this->panel2->Visible = false;
        //
        // label14
        //
        this->label14->AutoSize = true;
        this->label14->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label14->Location = System::Drawing::Point(90, 10);
        this->label14->Name = L"label14";
        this->label14->Size = System::Drawing::Size(110, 13);
        this->label14->TabIndex = 5;
        this->label14->Text = L"12:00:00 03/02/2025";
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->Location = System::Drawing::Point(263, 64);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(92, 13);
        this->label5->TabIndex = 3;
        this->label5->Text = L"Đánh dấu đã đọc";
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label6->Location = System::Drawing::Point(4, 39);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(327, 16);
        this->label6->TabIndex = 2;
        this->label6->Text =
            L"hãy nộp thêm tiền vào tài khoản để tiến hành giao dịch";
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label7->Location = System::Drawing::Point(3, 23);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(310, 16);
        this->label7->TabIndex = 1;
        this->label7->Text =
            L"Thanh toán định kì của quý khách chưa haofn thành,";
        //
        // label8
        //
        this->label8->AutoSize = true;
        this->label8->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label8->Location = System::Drawing::Point(4, 10);
        this->label8->Name = L"label8";
        this->label8->Size = System::Drawing::Size(80, 13);
        this->label8->TabIndex = 0;
        this->label8->Text = L"THÔNG BÁO";
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
        this->panel1->Controls->Add(this->label15);
        this->panel1->Controls->Add(this->label4);
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->label2);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Location = System::Drawing::Point(8, 218);
        this->panel1->Margin = System::Windows::Forms::Padding(8);
        this->panel1->Name = L"panel1";
        this->panel1->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
        this->panel1->Size = System::Drawing::Size(367, 89);
        this->panel1->TabIndex = 0;
        this->panel1->Visible = false;
        //
        // label15
        //
        this->label15->AutoSize = true;
        this->label15->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label15->Location = System::Drawing::Point(90, 10);
        this->label15->Name = L"label15";
        this->label15->Size = System::Drawing::Size(110, 13);
        this->label15->TabIndex = 6;
        this->label15->Text = L"12:00:00 03/02/2025";
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label4->Location = System::Drawing::Point(263, 64);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(92, 13);
        this->label4->TabIndex = 3;
        this->label4->Text = L"Đánh dấu đã đọc";
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->Location = System::Drawing::Point(4, 39);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(327, 16);
        this->label3->TabIndex = 2;
        this->label3->Text =
            L"hãy nộp thêm tiền vào tài khoản để tiến hành giao dịch";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(3, 23);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(310, 16);
        this->label2->TabIndex = 1;
        this->label2->Text =
            L"Thanh toán định kì của quý khách chưa haofn thành,";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(4, 10);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(80, 13);
        this->label1->TabIndex = 0;
        this->label1->Text = L"THÔNG BÁO";
        //
        // NotificationForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(400, 401);
        this->Controls->Add(this->flowLayoutContainer);
        this->FormBorderStyle =
            System::Windows::Forms::FormBorderStyle::FixedToolWindow;
        this->Name = L"NotificationForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
        this->Text = L"NotificationForm";
        this->flowLayoutContainer->ResumeLayout(false);
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion

    void loadNotifications() {
        // Giả lập danh sách thông báo
        array<Notifications ^> ^ notifications =
            HandleFile::ReadNotificationsArray("notifications.dat");
        if (notifications == nullptr) {
            return;
        }

        // Thêm từng thông báo vào FlowLayoutPanel
        for (int i = 0; i < notifications->Length; i++) {
            if (notifications[i]->UserAccNumber !=
                GlobalData::GetCurrentUser()->AccountNumber) {
                continue;
            }
            addNotificationPanel(flowLayoutContainer, notifications[i], i);
        }
    }

    void addNotificationPanel(FlowLayoutPanel ^ flowLayoutPanel,
                              Notifications ^ notification, int index) {
        // Tạo một Panel mới chứa thông báo
        Panel ^ panel = gcnew Panel();
        panel->Size = System::Drawing::Size(flowLayoutPanel->Width - 20,
                                            90); // Tăng chiều cao để vừa 2 dòng
        panel->BorderStyle = BorderStyle::FixedSingle;

        if (notification->Status == 1) {
            panel->BackColor = System::Drawing::Color::LightGray;
        }

        // Tạo nhãn tiêu đề thông báo
        Label ^ titleLabel = gcnew Label();
        titleLabel->Text = L"THÔNG BÁO";
        titleLabel->Font =
            gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
        titleLabel->Location = System::Drawing::Point(5, 5);

        // Tạo nhãn thời gian thông báo
        Label ^ timeLabel = gcnew Label();
        timeLabel->Text = notification->CreatedAt;
        timeLabel->Font =
            gcnew System::Drawing::Font("Arial", 9, FontStyle::Italic);
        timeLabel->Location = System::Drawing::Point(100, 5);

        // Tạo nhãn nội dung thông báo (đảm bảo luôn có 2 dòng)
        Label ^ contentLabel = gcnew Label();
        contentLabel->Text = notification->Content;
        contentLabel->Font =
            gcnew System::Drawing::Font("Arial", 9, FontStyle::Regular);
        contentLabel->Location = System::Drawing::Point(5, 25);
        contentLabel->Size =
            System::Drawing::Size(panel->Width - 10, 40); // Đảm bảo vừa 2 dòng
        contentLabel->AutoSize = false;
        contentLabel->MaximumSize =
            System::Drawing::Size(panel->Width - 10, 40); // Giới hạn chiều cao

        // Tạo Label đánh dấu đã đọc
        String ^ markReadText =
            notification->Status == 1 ? L"Đã đọc" : L"Đánh dấu đã đọc";
        Label ^ markReadLabel = gcnew Label();
        markReadLabel->Text = markReadText;
        markReadLabel->ForeColor = notification->Status == 0
                                       ? System::Drawing::Color::Blue
                                       : System::Drawing::Color::Gray;
        markReadLabel->Cursor = notification->Status == 0 ? Cursors::Hand : Cursors::No;

        markReadLabel->Location =
            System::Drawing::Point(panel->Width - 120, 70);
        markReadLabel->AutoSize = true;

        // Thêm các thành phần vào panel
        panel->Controls->Add(titleLabel);
        panel->Controls->Add(timeLabel);
        panel->Controls->Add(contentLabel);
        panel->Controls->Add(markReadLabel);

        // Gắn thông báo vào Label để xử lý sự kiện click
        markReadLabel->Tag = notification; 


        // Thêm panel vào FlowLayoutPanel
        flowLayoutPanel->Controls->Add(panel);
        markReadLabel->Click += gcnew System::EventHandler(this, &NotificationForm::label1_Click);
    }

    private:
    System::Void label1_Click(System::Object ^ sender, System::EventArgs ^ e) {
        Label ^ clickedLabel =
            dynamic_cast<Label ^>(sender); // Ép kiểu sender thành Label

        if (clickedLabel != nullptr && clickedLabel->Tag != nullptr) {
            Notifications ^ notification = dynamic_cast<Notifications ^>(
                clickedLabel->Tag); // Lấy lại đối tượng notification
            
            if (notification == nullptr) {
                return;
            }
            

            // Đánh dấu đã đọc
            clickedLabel->Text = L"Đã đọc";
            clickedLabel->ForeColor = System::Drawing::Color::Gray;
            clickedLabel->Cursor = Cursors::No;

            // Cập nhật trạng thái đã đọc
            notification->Status = 1;

            array<Notifications ^> ^ notifications =
                HandleFile::ReadNotificationsArray("notifications.dat");
            if (notifications == nullptr) {
                return;
            }
            for (int i = 0; i < notifications->Length; i++) {
                if (notifications[i]->NotificationId ==
                    notification->NotificationId) {
                    notifications[i] = notification;
                    break;
                }
            }
            HandleFile::WriteNotificationsArray(notifications,
                                                "notifications.dat");
        }
    }






};
} // namespace BankingAppwinform
