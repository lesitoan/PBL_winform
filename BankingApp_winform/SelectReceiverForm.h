#pragma once
#include "HandleFile.h"
#include "Transaction.h"
#include "User.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for SelectReceiverForm
/// </summary>
public
ref class SelectReceiverForm : public System::Windows::Forms::Form {
  public:
    SelectReceiverForm(User^ user) {
        InitializeComponent();
        loadAccHistory(user);
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~SelectReceiverForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Label ^ label5;

  protected:
  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::ComboBox ^ selectAccHistory;

  private:
  private:
    System::Windows::Forms::Button ^ btnClose;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
  protected:
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
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectAccHistory = (gcnew System::Windows::Forms::ComboBox());
        this->btnClose = (gcnew System::Windows::Forms::Button());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel4->SuspendLayout();
        this->SuspendLayout();
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
        this->label5->ForeColor = System::Drawing::Color::Black;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(35, 37);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(236, 22);
        this->label5->TabIndex = 105;
        this->label5->Text = L"Chọn tài khoản từ lịch sử gần đây:";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->selectAccHistory);
        this->panel4->Location = System::Drawing::Point(39, 62);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(371, 37);
        this->panel4->TabIndex = 106;
        //
        // selectAccHistory
        //
        this->selectAccHistory->Anchor =
            System::Windows::Forms::AnchorStyles::Left;
        this->selectAccHistory->DropDownStyle =
            System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectAccHistory->FlatStyle =
            System::Windows::Forms::FlatStyle::Popup;
        this->selectAccHistory->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->selectAccHistory->ForeColor = System::Drawing::Color::Black;
        this->selectAccHistory->FormattingEnabled = true;
        this->selectAccHistory->Items->AddRange(
            gcnew cli::array<System::Object ^>(2){L"user", L"company"});
        this->selectAccHistory->Location = System::Drawing::Point(1, 7);
        this->selectAccHistory->Name = L"selectAccHistory";
        this->selectAccHistory->Size = System::Drawing::Size(367, 27);
        this->selectAccHistory->TabIndex = 3;
        //
        // btnClose
        //
        this->btnClose->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnClose->BackColor = System::Drawing::Color::RoyalBlue;
        this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClose->FlatAppearance->BorderSize = 0;
        this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClose->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClose->ForeColor = System::Drawing::Color::Bisque;
        this->btnClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnClose->Location = System::Drawing::Point(40, 125);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(172, 48);
        this->btnClose->TabIndex = 104;
        this->btnClose->Text = L"THOÁT";
        this->btnClose->UseVisualStyleBackColor = false;
        this->btnClose->Click += gcnew System::EventHandler(
            this, &SelectReceiverForm::btnClose_Click_1);
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
        this->btnSubmit->Location = System::Drawing::Point(235, 125);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(175, 48);
        this->btnSubmit->TabIndex = 103;
        this->btnSubmit->Text = L"OK";
        this->btnSubmit->UseVisualStyleBackColor = false;
        //
        // SelectReceiverForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::MintCream;
        this->ClientSize = System::Drawing::Size(449, 241);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->btnClose);
        this->Controls->Add(this->btnSubmit);
        this->MaximumSize = System::Drawing::Size(465, 280);
        this->MinimumSize = System::Drawing::Size(465, 280);
        this->Name = L"SelectReceiverForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"SelectReceiverForm";
        this->panel4->ResumeLayout(false);
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion

    private:
    void loadAccHistory(User ^ user) {
          array<Transaction ^> ^ transactions =
              HandleFile::ReadTransactionArray("transactions.dat");
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");

          int accNumber = user->AccountNumber;

          List<String ^> ^ accHistory = gcnew List<String ^>();

          int count = 0;

          for (int i = 0; i < transactions->Length; i++) {
              if (transactions[i]->getFromAccount() == accNumber &&
                  transactions[i]->getToAccount() != 0) {

                  for (int j = 0; j < users->Length; j++) {
                      if (users[j]->AccountNumber == transactions[i]->getToAccount() &&
                          users[i]->getRole() == "user") {
                          String ^ toAcc =
                              users[j]->getFullName() + " - " +
                              transactions[i]->getToAccount().ToString() +
                              " - " +
                              transactions[i]->getAmount().ToString();
                          accHistory->Add(toAcc);
                          break;
                      }
                  }
                  count++;
                  if (count == 5) {
                      break;
                  }
              }
          }

          for (int i = 0; i < accHistory->Count; i++) {
              selectAccHistory->Items->Add(accHistory[i]);
          }

    }

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {}

  private:
    System::Void btnClose_Click_1(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        this->Close();
    }




};
} // namespace BankingAppwinform
