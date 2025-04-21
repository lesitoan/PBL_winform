#pragma once
#include "GlobalData.h"
#include "Transaction.h"
#include "TransactionServices.h"

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
    HistoryForm(void);

  protected:
    ~HistoryForm();

  private:
    System::ComponentModel::Container ^ components;
    System::Windows::Forms::Panel ^ fullContent;
    System::Windows::Forms::FlowLayoutPanel ^ rightContent;
    System::Windows::Forms::FlowLayoutPanel ^ leftContent;
    System::Windows::Forms::Panel ^ panelHeader;
    System::Windows::Forms::Panel ^ panelHeaderRight;
    System::Windows::Forms::Panel ^ panelHeaderLeft;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::Label ^ label1;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->fullContent = (gcnew System::Windows::Forms::Panel());
        this->panelHeader = (gcnew System::Windows::Forms::Panel());
        this->panelHeaderRight = (gcnew System::Windows::Forms::Panel());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->panelHeaderLeft = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->rightContent = (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->leftContent = (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->fullContent->SuspendLayout();
        this->panelHeader->SuspendLayout();
        this->panelHeaderRight->SuspendLayout();
        this->panelHeaderLeft->SuspendLayout();
        this->SuspendLayout();
        //
        // fullContent
        //
        this->fullContent->BackColor = System::Drawing::Color::MintCream;
        this->fullContent->Controls->Add(this->panelHeader);
        this->fullContent->Controls->Add(this->rightContent);
        this->fullContent->Controls->Add(this->leftContent);
        this->fullContent->Dock = System::Windows::Forms::DockStyle::Fill;
        this->fullContent->Location = System::Drawing::Point(0, 0);
        this->fullContent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->fullContent->Name = L"fullContent";
        this->fullContent->Size = System::Drawing::Size(877, 614);
        this->fullContent->TabIndex = 1;
        this->fullContent->SizeChanged += gcnew System::EventHandler(
            this, &HistoryForm::fullContent_SizeChanged);
        //
        // panelHeader
        //
        this->panelHeader->BackColor = System::Drawing::Color::Teal;
        this->panelHeader->Controls->Add(this->panelHeaderRight);
        this->panelHeader->Controls->Add(this->panelHeaderLeft);
        this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
        this->panelHeader->Location = System::Drawing::Point(0, 0);
        this->panelHeader->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panelHeader->Name = L"panelHeader";
        this->panelHeader->Size = System::Drawing::Size(877, 47);
        this->panelHeader->TabIndex = 2;
        //
        // panelHeaderRight
        //
        this->panelHeaderRight->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelHeaderRight->BackColor =
            System::Drawing::Color::DarkSlateGray;
        this->panelHeaderRight->Controls->Add(this->label2);
        this->panelHeaderRight->Location = System::Drawing::Point(427, 0);
        this->panelHeaderRight->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panelHeaderRight->Name = L"panelHeaderRight";
        this->panelHeaderRight->Size = System::Drawing::Size(449, 47);
        this->panelHeaderRight->TabIndex = 1;
        //
        // label2
        //
        this->label2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label2->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label2->ForeColor =
            System::Drawing::SystemColors::ButtonHighlight;
        this->label2->Location = System::Drawing::Point(0, 0);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(449, 47);
        this->label2->TabIndex = 1;
        this->label2->Text = L"LỊCH SỬ RÚT TIỀN";
        this->label2->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panelHeaderLeft
        //
        this->panelHeaderLeft->BackColor =
            System::Drawing::Color::MediumAquamarine;
        this->panelHeaderLeft->Controls->Add(this->label1);
        this->panelHeaderLeft->Location = System::Drawing::Point(0, 0);
        this->panelHeaderLeft->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->panelHeaderLeft->Name = L"panelHeaderLeft";
        this->panelHeaderLeft->Size = System::Drawing::Size(428, 47);
        this->panelHeaderLeft->TabIndex = 0;
        //
        // label1
        //
        this->label1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 10, System::Drawing::FontStyle::Bold));
        this->label1->ForeColor =
            System::Drawing::SystemColors::ButtonHighlight;
        this->label1->Location = System::Drawing::Point(0, 0);
        this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(428, 47);
        this->label1->TabIndex = 0;
        this->label1->Text = L"LỊCH SỬ CHUYỂN KHOẢN";
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // rightContent
        //
        this->rightContent->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->rightContent->AutoScroll = true;
        this->rightContent->BackColor = System::Drawing::Color::White;
        this->rightContent->ForeColor =
            System::Drawing::SystemColors::ControlText;
        this->rightContent->Location = System::Drawing::Point(427, 54);
        this->rightContent->Margin =
            System::Windows::Forms::Padding(4, 4, 4, 4);
        this->rightContent->Name = L"rightContent";
        this->rightContent->Size = System::Drawing::Size(451, 560);
        this->rightContent->TabIndex = 1;
        this->rightContent->SizeChanged += gcnew System::EventHandler(
            this, &HistoryForm::rightContent_SizeChanged);
        //
        // leftContent
        //
        this->leftContent->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->leftContent->AutoScroll = true;
        this->leftContent->BackColor = System::Drawing::Color::White;
        this->leftContent->Location = System::Drawing::Point(0, 54);
        this->leftContent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->leftContent->Name = L"leftContent";
        this->leftContent->Size = System::Drawing::Size(428, 560);
        this->leftContent->TabIndex = 0;
        this->leftContent->SizeChanged += gcnew System::EventHandler(
            this, &HistoryForm::leftContent_SizeChanged);
        //
        // HistoryForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(877, 614);
        this->Controls->Add(this->fullContent);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->Name = L"HistoryForm";
        this->Text = L"HistoryForm";
        this->fullContent->ResumeLayout(false);
        this->panelHeader->ResumeLayout(false);
        this->panelHeaderRight->ResumeLayout(false);
        this->panelHeaderLeft->ResumeLayout(false);
        this->ResumeLayout(false);
    }

#pragma endregion

  private:
    Button ^ selectedButton = nullptr;


    void AddTransactionPanel(FlowLayoutPanel ^ flowLayoutPanel,
                             Transaction ^ transaction);

    // Cập nhật kích thước Panel khi Form thay đổi kích thước
    void OnResize(FlowLayoutPanel ^ flowLayoutPanel, Object ^ sender,
                  EventArgs ^ e);

  private:
    System::Void fullContent_SizeChanged(System::Object ^ sender,
                                         System::EventArgs ^ e);

  private:
    System::Void leftContent_SizeChanged(System::Object ^ sender,
                                         System::EventArgs ^ e);

  private:
    System::Void rightContent_SizeChanged(System::Object ^ sender,
                                          System::EventArgs ^ e);
    void loadTransactionsHistory();
};
} // namespace BankingAppwinform
