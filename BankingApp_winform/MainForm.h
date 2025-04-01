#pragma once
#include "AccountForm.h"
#include "GlobalData.h"
#include "HistoryForm.h"
#include "LoadChildForm.h"
#include "TransferMoneyForm.h"
#include "User.h"
#include "WithdrawMoneyForm.h"
#include "CodeForm.h"
#include "ServicePaymentForm.h"
#include "ClientRecurringPaymentForm.h"
#include "NotificationForm.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class MainForm : public System::Windows::Forms::Form {
  public:
    MainForm();

  protected:
    ~MainForm();

  private:
    System::Windows::Forms::Panel ^ panelNav;
    System::Windows::Forms::Button ^ btnAccount;

  private:
    System::Windows::Forms::PictureBox ^ pictureBoxAvatar;

    System::Windows::Forms::CheckBox ^ btnShowBalance;
    System::Windows::Forms::Label ^ labelBalance;
    System::Windows::Forms::Label ^ labelFullName;
    System::Windows::Forms::Button ^ btnHistory;
    System::Windows::Forms::Button ^ btnWithdraw;
    System::Windows::Forms::Button ^ btnTransfer;
    System::Windows::Forms::Button ^ btnLogout;
    System::Windows::Forms::Panel ^ panel2;
    System::Windows::Forms::Button ^ btnMenu;
    System::Windows::Forms::Timer ^ timer1;

  private:
    System::Windows::Forms::Panel ^ panelHeader;

    System::Windows::Forms::Label ^ headerText;
    System::Windows::Forms::Panel ^ panel3;
    System::Windows::Forms::Panel ^ panelx;
    System::Windows::Forms::Panel ^ panelContent;

  private:
    System::Windows::Forms::Button ^ btnCode;

  private:
    System::Windows::Forms::Button ^ btnServicePayment;

  private:
    System::Windows::Forms::Button ^ btnRecurringPayment;

  private:
    System::Windows::Forms::Button ^ btnNotification;

  private:


  private:


  private:

    System::ComponentModel::IContainer ^ components;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->components = (gcnew System::ComponentModel::Container());
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                MainForm::typeid));
        this->panelNav = (gcnew System::Windows::Forms::Panel());
        this->btnHistory = (gcnew System::Windows::Forms::Button());
        this->btnServicePayment = (gcnew System::Windows::Forms::Button());
        this->btnRecurringPayment = (gcnew System::Windows::Forms::Button());
        this->btnCode = (gcnew System::Windows::Forms::Button());
        this->btnWithdraw = (gcnew System::Windows::Forms::Button());
        this->btnTransfer = (gcnew System::Windows::Forms::Button());
        this->btnAccount = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->pictureBoxAvatar = (gcnew System::Windows::Forms::PictureBox());
        this->labelFullName = (gcnew System::Windows::Forms::Label());
        this->btnShowBalance = (gcnew System::Windows::Forms::CheckBox());
        this->labelBalance = (gcnew System::Windows::Forms::Label());
        this->btnMenu = (gcnew System::Windows::Forms::Button());
        this->btnLogout = (gcnew System::Windows::Forms::Button());
        this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
        this->panelHeader = (gcnew System::Windows::Forms::Panel());
        this->btnNotification = (gcnew System::Windows::Forms::Button());
        this->headerText = (gcnew System::Windows::Forms::Label());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->panelx = (gcnew System::Windows::Forms::Panel());
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->panelNav->SuspendLayout();
        this->panel2->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBoxAvatar))
            ->BeginInit();
        this->panelHeader->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panelx->SuspendLayout();
        this->SuspendLayout();
        //
        // panelNav
        //
        this->panelNav->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panelNav->Controls->Add(this->btnHistory);
        this->panelNav->Controls->Add(this->btnServicePayment);
        this->panelNav->Controls->Add(this->btnRecurringPayment);
        this->panelNav->Controls->Add(this->btnCode);
        this->panelNav->Controls->Add(this->btnWithdraw);
        this->panelNav->Controls->Add(this->btnTransfer);
        this->panelNav->Controls->Add(this->btnAccount);
        this->panelNav->Controls->Add(this->panel2);
        this->panelNav->Controls->Add(this->btnMenu);
        this->panelNav->Controls->Add(this->btnLogout);
        this->panelNav->Cursor = System::Windows::Forms::Cursors::Default;
        this->panelNav->Dock = System::Windows::Forms::DockStyle::Left;
        this->panelNav->ForeColor =
            System::Drawing::SystemColors::InactiveCaptionText;
        this->panelNav->Location = System::Drawing::Point(0, 0);
        this->panelNav->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panelNav->MinimumSize = System::Drawing::Size(83, 690);
        this->panelNav->Name = L"panelNav";
        this->panelNav->Size = System::Drawing::Size(276, 690);
        this->panelNav->TabIndex = 1;
        //
        // btnHistory
        //
        this->btnHistory->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnHistory->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnHistory->Dock = System::Windows::Forms::DockStyle::Top;
        this->btnHistory->FlatAppearance->BorderSize = 0;
        this->btnHistory->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnHistory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnHistory->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnHistory->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnHistory->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnHistory.Image")));
        this->btnHistory->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnHistory->Location = System::Drawing::Point(0, 564);
        this->btnHistory->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnHistory->Name = L"btnHistory";
        this->btnHistory->Size = System::Drawing::Size(276, 71);
        this->btnHistory->TabIndex = 11;
        this->btnHistory->Text = L"                 LỊCH SỬ";
        this->btnHistory->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnHistory->UseVisualStyleBackColor = false;
        this->btnHistory->Click +=
            gcnew System::EventHandler(this, &MainForm::btnHistory_Click);
        //
        // btnServicePayment
        //
        this->btnServicePayment->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnServicePayment->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnServicePayment->Dock = System::Windows::Forms::DockStyle::Top;
        this->btnServicePayment->FlatAppearance->BorderSize = 0;
        this->btnServicePayment->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnServicePayment->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnServicePayment->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnServicePayment->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnServicePayment->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"btnServicePayment.Image")));
        this->btnServicePayment->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnServicePayment->Location = System::Drawing::Point(0, 493);
        this->btnServicePayment->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnServicePayment->Name = L"btnServicePayment";
        this->btnServicePayment->Size = System::Drawing::Size(276, 71);
        this->btnServicePayment->TabIndex = 16;
        this->btnServicePayment->Text = L"                TT DỊCH VỤ";
        this->btnServicePayment->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnServicePayment->UseVisualStyleBackColor = false;
        this->btnServicePayment->Click += gcnew System::EventHandler(
            this, &MainForm::btnServicePayment_Click);
        //
        // btnRecurringPayment
        //
        this->btnRecurringPayment->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnRecurringPayment->Cursor =
            System::Windows::Forms::Cursors::Hand;
        this->btnRecurringPayment->Dock =
            System::Windows::Forms::DockStyle::Top;
        this->btnRecurringPayment->FlatAppearance->BorderSize = 0;
        this->btnRecurringPayment->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnRecurringPayment->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnRecurringPayment->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnRecurringPayment->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnRecurringPayment->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"btnRecurringPayment.Image")));
        this->btnRecurringPayment->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnRecurringPayment->Location = System::Drawing::Point(0, 422);
        this->btnRecurringPayment->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnRecurringPayment->Name = L"btnRecurringPayment";
        this->btnRecurringPayment->Size = System::Drawing::Size(276, 71);
        this->btnRecurringPayment->TabIndex = 17;
        this->btnRecurringPayment->Text = L"                YCTT ĐỊNH KÌ";
        this->btnRecurringPayment->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnRecurringPayment->UseVisualStyleBackColor = false;
        this->btnRecurringPayment->Visible = false;
        this->btnRecurringPayment->Click += gcnew System::EventHandler(
            this, &MainForm::btnRecurringPayment_Click);
        //
        // btnCode
        //
        this->btnCode->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnCode->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnCode->Dock = System::Windows::Forms::DockStyle::Top;
        this->btnCode->FlatAppearance->BorderSize = 0;
        this->btnCode->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnCode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnCode->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnCode->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnCode->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnCode.Image")));
        this->btnCode->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnCode->Location = System::Drawing::Point(0, 351);
        this->btnCode->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnCode->Name = L"btnCode";
        this->btnCode->Size = System::Drawing::Size(276, 71);
        this->btnCode->TabIndex = 15;
        this->btnCode->Text = L"                QUẢN LÍ CODE";
        this->btnCode->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnCode->UseVisualStyleBackColor = false;
        this->btnCode->Visible = false;
        this->btnCode->Click +=
            gcnew System::EventHandler(this, &MainForm::btnCode_Click);
        //
        // btnWithdraw
        //
        this->btnWithdraw->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnWithdraw->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnWithdraw->Dock = System::Windows::Forms::DockStyle::Top;
        this->btnWithdraw->FlatAppearance->BorderSize = 0;
        this->btnWithdraw->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnWithdraw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnWithdraw->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnWithdraw->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnWithdraw->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnWithdraw.Image")));
        this->btnWithdraw->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnWithdraw->Location = System::Drawing::Point(0, 280);
        this->btnWithdraw->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnWithdraw->Name = L"btnWithdraw";
        this->btnWithdraw->Size = System::Drawing::Size(276, 71);
        this->btnWithdraw->TabIndex = 10;
        this->btnWithdraw->Text = L"                RÚT TIỀN";
        this->btnWithdraw->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnWithdraw->UseVisualStyleBackColor = false;
        this->btnWithdraw->Click +=
            gcnew System::EventHandler(this, &MainForm::btnWithdraw_Click);
        //
        // btnTransfer
        //
        this->btnTransfer->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnTransfer->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnTransfer->Dock = System::Windows::Forms::DockStyle::Top;
        this->btnTransfer->FlatAppearance->BorderSize = 0;
        this->btnTransfer->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnTransfer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnTransfer->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnTransfer->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnTransfer->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnTransfer.Image")));
        this->btnTransfer->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnTransfer->Location = System::Drawing::Point(0, 209);
        this->btnTransfer->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnTransfer->Name = L"btnTransfer";
        this->btnTransfer->Size = System::Drawing::Size(276, 71);
        this->btnTransfer->TabIndex = 9;
        this->btnTransfer->Text = L"                CHUYỂN TIỀN";
        this->btnTransfer->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnTransfer->UseVisualStyleBackColor = false;
        this->btnTransfer->Click +=
            gcnew System::EventHandler(this, &MainForm::btnTransfer_Click);
        //
        // btnAccount
        //
        this->btnAccount->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAccount->Dock = System::Windows::Forms::DockStyle::Top;
        this->btnAccount->FlatAppearance->BorderSize = 0;
        this->btnAccount->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAccount->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnAccount->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnAccount.Image")));
        this->btnAccount->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->Location = System::Drawing::Point(0, 138);
        this->btnAccount->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnAccount->Name = L"btnAccount";
        this->btnAccount->Size = System::Drawing::Size(276, 71);
        this->btnAccount->TabIndex = 0;
        this->btnAccount->Text = L"                TÀI KHOẢN";
        this->btnAccount->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->UseVisualStyleBackColor = false;
        this->btnAccount->Click +=
            gcnew System::EventHandler(this, &MainForm::btnAccount_Click);
        //
        // panel2
        //
        this->panel2->Controls->Add(this->pictureBoxAvatar);
        this->panel2->Controls->Add(this->labelFullName);
        this->panel2->Controls->Add(this->btnShowBalance);
        this->panel2->Controls->Add(this->labelBalance);
        this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel2->Location = System::Drawing::Point(0, 52);
        this->panel2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(276, 86);
        this->panel2->TabIndex = 14;
        //
        // pictureBoxAvatar
        //
        this->pictureBoxAvatar->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"pictureBoxAvatar.Image")));
        this->pictureBoxAvatar->Location = System::Drawing::Point(16, 15);
        this->pictureBoxAvatar->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->pictureBoxAvatar->Name = L"pictureBoxAvatar";
        this->pictureBoxAvatar->Size = System::Drawing::Size(55, 50);
        this->pictureBoxAvatar->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->pictureBoxAvatar->TabIndex = 5;
        this->pictureBoxAvatar->TabStop = false;
        //
        // labelFullName
        //
        this->labelFullName->AutoSize = true;
        this->labelFullName->BackColor = System::Drawing::Color::Transparent;
        this->labelFullName->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline Medium", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelFullName->ForeColor = System::Drawing::Color::White;
        this->labelFullName->Location = System::Drawing::Point(89, 15);
        this->labelFullName->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelFullName->Name = L"labelFullName";
        this->labelFullName->Size = System::Drawing::Size(103, 27);
        this->labelFullName->TabIndex = 6;
        this->labelFullName->Text = L"LE SI TOAN";
        this->labelFullName->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnShowBalance
        //
        this->btnShowBalance->AutoSize = true;
        this->btnShowBalance->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnShowBalance->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 8));
        this->btnShowBalance->ForeColor =
            System::Drawing::SystemColors::ControlLightLight;
        this->btnShowBalance->Location = System::Drawing::Point(231, 48);
        this->btnShowBalance->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnShowBalance->Name = L"btnShowBalance";
        this->btnShowBalance->Size = System::Drawing::Size(18, 17);
        this->btnShowBalance->TabIndex = 8;
        this->btnShowBalance->UseVisualStyleBackColor = true;
        this->btnShowBalance->CheckedChanged += gcnew System::EventHandler(
            this, &MainForm::btnShowBalance_CheckedChanged);
        //
        // labelBalance
        //
        this->labelBalance->AutoSize = true;
        this->labelBalance->BackColor = System::Drawing::Color::Transparent;
        this->labelBalance->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelBalance->ForeColor = System::Drawing::Color::White;
        this->labelBalance->Location = System::Drawing::Point(89, 42);
        this->labelBalance->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelBalance->Name = L"labelBalance";
        this->labelBalance->Size = System::Drawing::Size(120, 25);
        this->labelBalance->TabIndex = 7;
        this->labelBalance->Text = L"120000VNĐ";
        this->labelBalance->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnMenu
        //
        this->btnMenu->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnMenu->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnMenu->Dock = System::Windows::Forms::DockStyle::Top;
        this->btnMenu->FlatAppearance->BorderSize = 0;
        this->btnMenu->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnMenu->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnMenu->ForeColor = System::Drawing::SystemColors::HighlightText;
        this->btnMenu->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnMenu.Image")));
        this->btnMenu->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnMenu->Location = System::Drawing::Point(0, 0);
        this->btnMenu->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnMenu->Name = L"btnMenu";
        this->btnMenu->Size = System::Drawing::Size(276, 52);
        this->btnMenu->TabIndex = 13;
        this->btnMenu->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnMenu->UseVisualStyleBackColor = false;
        this->btnMenu->Click +=
            gcnew System::EventHandler(this, &MainForm::btnMenu_Click);
        //
        // btnLogout
        //
        this->btnLogout->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Bottom |
                 System::Windows::Forms::AnchorStyles::Left));
        this->btnLogout->BackColor = System::Drawing::Color::Brown;
        this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLogout->FlatAppearance->BorderSize = 0;
        this->btnLogout->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnLogout->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnLogout->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnLogout->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnLogout.Image")));
        this->btnLogout->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLogout->Location = System::Drawing::Point(0, 619);
        this->btnLogout->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnLogout->Name = L"btnLogout";
        this->btnLogout->Size = System::Drawing::Size(276, 71);
        this->btnLogout->TabIndex = 12;
        this->btnLogout->Text = L"                  ĐĂNG XUẤT";
        this->btnLogout->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnLogout->UseVisualStyleBackColor = false;
        this->btnLogout->Click +=
            gcnew System::EventHandler(this, &MainForm::btnLogout_Click);
        //
        // timer1
        //
        this->timer1->Interval = 3;
        this->timer1->Tick +=
            gcnew System::EventHandler(this, &MainForm::timer1_Tick);
        //
        // panelHeader
        //
        this->panelHeader->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->panelHeader->Controls->Add(this->btnNotification);
        this->panelHeader->Controls->Add(this->headerText);
        this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
        this->panelHeader->Location = System::Drawing::Point(276, 0);
        this->panelHeader->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panelHeader->Name = L"panelHeader";
        this->panelHeader->Size = System::Drawing::Size(903, 52);
        this->panelHeader->TabIndex = 2;
        //
        // btnNotification
        //
        this->btnNotification->Anchor =
            System::Windows::Forms::AnchorStyles::Right;
        this->btnNotification->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnNotification->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnNotification->FlatAppearance->BorderSize = 0;
        this->btnNotification->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnNotification->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnNotification->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnNotification->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnNotification->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"btnNotification.Image")));
        this->btnNotification->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnNotification->Location = System::Drawing::Point(815, 0);
        this->btnNotification->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->btnNotification->Name = L"btnNotification";
        this->btnNotification->Size = System::Drawing::Size(88, 52);
        this->btnNotification->TabIndex = 12;
        this->btnNotification->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnNotification->UseVisualStyleBackColor = false;
        this->btnNotification->Click +=
            gcnew System::EventHandler(this, &MainForm::btnNotification_Click);
        //
        // headerText
        //
        this->headerText->Dock = System::Windows::Forms::DockStyle::Fill;
        this->headerText->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->headerText->ForeColor = System::Drawing::Color::White;
        this->headerText->Location = System::Drawing::Point(0, 0);
        this->headerText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->headerText->Name = L"headerText";
        this->headerText->Size = System::Drawing::Size(903, 52);
        this->headerText->TabIndex = 0;
        this->headerText->Text = L"HEADER";
        this->headerText->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panel3
        //
        this->panel3->BackColor =
            System::Drawing::SystemColors::ControlLightLight;
        this->panel3->Controls->Add(this->panelx);
        this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
        this->panel3->Location = System::Drawing::Point(276, 52);
        this->panel3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(903, 638);
        this->panel3->TabIndex = 3;
        //
        // panelx
        //
        this->panelx->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelx->BackColor = System::Drawing::Color::White;
        this->panelx->Controls->Add(this->panelContent);
        this->panelx->Location = System::Drawing::Point(0, 0);
        this->panelx->Margin = System::Windows::Forms::Padding(0);
        this->panelx->Name = L"panelx";
        this->panelx->Size = System::Drawing::Size(903, 638);
        this->panelx->TabIndex = 0;
        this->panelx->SizeChanged +=
            gcnew System::EventHandler(this, &MainForm::resizeEven);
        //
        // panelContent
        //
        this->panelContent->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelContent->BackColor = System::Drawing::Color::Teal;
        this->panelContent->Location = System::Drawing::Point(13, 14);
        this->panelContent->Margin = System::Windows::Forms::Padding(0);
        this->panelContent->MaximumSize = System::Drawing::Size(1067, 738);
        this->panelContent->MinimumSize = System::Drawing::Size(873, 613);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(877, 613);
        this->panelContent->TabIndex = 0;
        //
        // MainForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1179, 690);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->panelHeader);
        this->Controls->Add(this->panelNav);
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->MinimumSize = System::Drawing::Size(1194, 728);
        this->Name = L"MainForm";
        this->ShowInTaskbar = false;
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"MainForm";
        this->Load +=
            gcnew System::EventHandler(this, &MainForm::MainForm_Load);
        this->panelNav->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBoxAvatar))
            ->EndInit();
        this->panelHeader->ResumeLayout(false);
        this->panel3->ResumeLayout(false);
        this->panelx->ResumeLayout(false);
        this->ResumeLayout(false);
    }

#pragma endregion

  private:
    bool isOpenNav = true;
    Button ^ selectedButton = nullptr;

    void ChangeButtonColor(Button ^ button);
    void InitLoad();

  private:
    System::Void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e);
    System::Void btnAccount_Click(System::Object ^ sender,
                                  System::EventArgs ^ e);
    System::Void btnTransfer_Click(System::Object ^ sender,
                                   System::EventArgs ^ e);
    System::Void btnWithdraw_Click(System::Object ^ sender,
                                   System::EventArgs ^ e);
    System::Void btnHistory_Click(System::Object ^ sender,
                                  System::EventArgs ^ e);
    System::Void btnLogout_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    System::Void timer1_Tick(System::Object ^ sender, System::EventArgs ^ e);


    System::Void btnMenu_Click(System::Object ^ sender, System::EventArgs ^ e);


    System::Void resizeEven(System::Object ^ sender, System::EventArgs ^ e);


    System::Void btnShowBalance_CheckedChanged(System::Object ^ sender,
                                               System::EventArgs ^ e);


    System::Void btnCode_Click(System::Object ^ sender, System::EventArgs ^ e);


    System::Void btnServicePayment_Click(System::Object ^ sender,
                                         System::EventArgs ^ e);

    System::Void btnRecurringPayment_Click(System::Object ^ sender,
                                           System::EventArgs ^ e);

    System::Void btnNotification_Click(System::Object ^ sender,
                                       System::EventArgs ^ e);

    void loadAvatar();

};
} // namespace BankingAppwinform
