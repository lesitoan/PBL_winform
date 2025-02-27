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

    }

  protected:
    ~HistoryForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panelContent;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Button ^ btnActiveTransferList;
    System::Windows::Forms::Button ^ btnActiveWithDrawList;
    System::ComponentModel::Container ^ components;

    String ^ activePanel = "TRANSFER";
    array<Transaction ^> ^ transactions;

    void loadContent(array<Transaction ^> ^ transactions, Panel ^ panel, String ^ type) {

        int yOffset = 10;
        panel->Controls->Clear();

        Label ^ headerText = gcnew Label();
        headerText->ForeColor = Color::Black;
        headerText->Font =
            gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
        headerText->AutoSize = true;
        headerText->Location = System::Drawing::Point(10, yOffset);

        if (transactions == nullptr) {
            headerText->Text = "CHUA CO LICH SU GIAO DICH";
            panel->Controls->Add(headerText);
            return;
        } else if (type == "TRANSFER") {
            headerText->Text = "LICH SU CHUYEN KHOAN";
            panel->Controls->Add(headerText);
            yOffset += 30;
        } else {
            headerText->Text = "LICH SU RUT TIEN";
            panel->Controls->Add(headerText);
            yOffset += 30;
        }


        for each (Transaction ^ transaction in transactions) {
            Label ^ lblTransaction = gcnew Label();
            if (transaction->getToAccount() == 0 && type == "WITHDRAW") {
                lblTransaction->Text =
                    "Rut tien: " + transaction->getAmount().ToString("N0") +
                    " VND - " + transaction->getCreatedAt();
                lblTransaction->ForeColor = Color::Red;
            } else if (type == "TRANSFER") {
                if (transaction->getFromAccount() ==
                         GlobalData::GetCurrentUser()->getAccountNumber()) {
                    lblTransaction->Text =
                        "Chuyen tien: " +
                        transaction->getAmount().ToString("N0") +
                        " VND - den: " + transaction->getToAccount() + " - " +
                        transaction->getCreatedAt();
                    lblTransaction->ForeColor = Color::Red;
                }
                else {
                    lblTransaction->Text =
                        "nhan tien: " +
                        transaction->getAmount().ToString("N0") +
                        " VND - tu: " + transaction->getFromAccount() + " - " +
                        transaction->getCreatedAt();
                    lblTransaction->ForeColor = Color::Green;
                }
            }
            //lblTransaction->ForeColor = Color::Red;
            lblTransaction->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
            lblTransaction->AutoSize = true;
            lblTransaction->Location = System::Drawing::Point(10, yOffset);
            panel->Controls->Add(lblTransaction);
            yOffset += 30;
        }
    }



#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->panelContent = (gcnew System::Windows::Forms::Panel());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->btnActiveTransferList = (gcnew System::Windows::Forms::Button());
        this->btnActiveWithDrawList = (gcnew System::Windows::Forms::Button());
        this->panelContent->SuspendLayout();
        this->SuspendLayout();
        //
        // panelContent
        //
        this->panelContent->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->panelContent->Controls->Add(this->label3);
        this->panelContent->Controls->Add(this->label1);
        this->panelContent->Location = System::Drawing::Point(22, 81);
        this->panelContent->Name = L"panelContent";
        this->panelContent->Size = System::Drawing::Size(530, 341);
        this->panelContent->TabIndex = 0;
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label3->ForeColor = System::Drawing::Color::Green;
        this->label3->Location = System::Drawing::Point(33, 41);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(175, 21);
        this->label3->TabIndex = 9;
        this->label3->Text = L"+435.000\? 20/02/2025";
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(197, 11);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(150, 21);
        this->label1->TabIndex = 8;
        this->label1->Text = L"Lich su chuyen tien";
        //
        // btnActiveTransferList
        //
        this->btnActiveTransferList->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnActiveTransferList->Cursor =
            System::Windows::Forms::Cursors::Hand;
        this->btnActiveTransferList->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnActiveTransferList->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->btnActiveTransferList->ForeColor = System::Drawing::Color::Black;
        this->btnActiveTransferList->Location = System::Drawing::Point(22, 12);
        this->btnActiveTransferList->Name = L"btnActiveTransferList";
        this->btnActiveTransferList->Size = System::Drawing::Size(262, 53);
        this->btnActiveTransferList->TabIndex = 21;
        this->btnActiveTransferList->Text = L"Lich su chuyen khoan";
        this->btnActiveTransferList->UseVisualStyleBackColor = false;
        this->btnActiveTransferList->Click += gcnew System::EventHandler(
            this, &HistoryForm::btnActiveTransferList_Click);
        //
        // btnActiveWithDrawList
        //
        this->btnActiveWithDrawList->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnActiveWithDrawList->Cursor =
            System::Windows::Forms::Cursors::Hand;
        this->btnActiveWithDrawList->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnActiveWithDrawList->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->btnActiveWithDrawList->ForeColor = System::Drawing::Color::Black;
        this->btnActiveWithDrawList->Location = System::Drawing::Point(290, 12);
        this->btnActiveWithDrawList->Name = L"btnActiveWithDrawList";
        this->btnActiveWithDrawList->Size = System::Drawing::Size(262, 53);
        this->btnActiveWithDrawList->TabIndex = 22;
        this->btnActiveWithDrawList->Text = L"Lich su rut tien";
        this->btnActiveWithDrawList->UseVisualStyleBackColor = false;
        this->btnActiveWithDrawList->Click += gcnew System::EventHandler(
            this, &HistoryForm::btnActiveWithDrawList_Click);
        //
        // HistoryForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(573, 434);
        this->Controls->Add(this->btnActiveWithDrawList);
        this->Controls->Add(this->btnActiveTransferList);
        this->Controls->Add(this->panelContent);
        this->Name = L"HistoryForm";
        this->Text = L"HistoryForm";
        this->Load +=
            gcnew System::EventHandler(this, &HistoryForm::HistoryForm_Load);
        this->panelContent->ResumeLayout(false);
        this->panelContent->PerformLayout();
        this->ResumeLayout(false);
    }

#pragma endregion
  private:
    System::Void HistoryForm_Load(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        transactions = HandleFile::ReadTransactionArray("transactions.dat");
        loadContent(transactions, panelContent, "TRANSFER");
    }
  private:
    System::Void btnActiveTransferList_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
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
        if (activePanel == "WITHDRAW") {
            return;
        } else {
            activePanel = "WITHDRAW";
            loadContent(transactions, panelContent, "WITHDRAW");
        }
    }

  
};
}
