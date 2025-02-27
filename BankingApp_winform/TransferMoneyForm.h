#pragma once
#include "Validate.h"
#include "HandleFile.h"
#include "GlobalData.h"
#include "User.h"
#include "Transaction.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class TransferMoneyForm : public System::Windows::Forms::Form {
  public:
    TransferMoneyForm(void) {
        InitializeComponent();
    }

  protected:
    ~TransferMoneyForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::ComboBox ^ selectBankBox;
    System::Windows::Forms::Label ^ labelAccountNumber;
    System::Windows::Forms::TextBox ^ accountNumber;
    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::Button ^ btnSubmit;
    System::Windows::Forms::TextBox ^ amountInput;
    System::Windows::Forms::Button ^ btnFindAccount;
    System::Windows::Forms::Label ^ label4;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::Label ^ labelReceiver;
    System::Windows::Forms::TextBox ^ pinInput;
    System::Windows::Forms::Panel ^ panelTransfer;
    System::ComponentModel::Container ^ components;
    
    User ^ receiver = nullptr;
    int receiverIndex = -1;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void) {
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->btnFindAccount = (gcnew System::Windows::Forms::Button());
        this->accountNumber = (gcnew System::Windows::Forms::TextBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->selectBankBox = (gcnew System::Windows::Forms::ComboBox());
        this->labelAccountNumber = (gcnew System::Windows::Forms::Label());
        this->panelTransfer = (gcnew System::Windows::Forms::Panel());
        this->labelReceiver = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->amountInput = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->pinInput = (gcnew System::Windows::Forms::TextBox());
        this->panel1->SuspendLayout();
        this->panelTransfer->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->btnFindAccount);
        this->panel1->Controls->Add(this->accountNumber);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->selectBankBox);
        this->panel1->Controls->Add(this->labelAccountNumber);
        this->panel1->Controls->Add(this->panelTransfer);
        this->panel1->Location = System::Drawing::Point(28, 24);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(515, 397);
        this->panel1->TabIndex = 0;
        //
        // btnFindAccount
        //
        this->btnFindAccount->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->btnFindAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnFindAccount->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnFindAccount->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnFindAccount->ForeColor = System::Drawing::Color::Black;
        this->btnFindAccount->Location = System::Drawing::Point(34, 112);
        this->btnFindAccount->Name = L"btnFindAccount";
        this->btnFindAccount->Size = System::Drawing::Size(454, 29);
        this->btnFindAccount->TabIndex = 7;
        this->btnFindAccount->Text = L"Tim tai khoan";
        this->btnFindAccount->UseVisualStyleBackColor = false;
        this->btnFindAccount->Click += gcnew System::EventHandler(
            this, &TransferMoneyForm::btnFindAccount_Click);
        //
        // accountNumber
        //
        this->accountNumber->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->accountNumber->Location = System::Drawing::Point(185, 68);
        this->accountNumber->Name = L"accountNumber";
        this->accountNumber->Size = System::Drawing::Size(305, 27);
        this->accountNumber->TabIndex = 5;
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(181, 32);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(104, 21);
        this->label1->TabIndex = 4;
        this->label1->Text = L"So tai khoan:";
        //
        // selectBankBox
        //
        this->selectBankBox->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->selectBankBox->FormattingEnabled = true;
        this->selectBankBox->Items->AddRange(gcnew cli::array<System::Object ^>(
            8){L"BIDV", L"Vietcombank", L"MB", L"VP Bank", L"Viettinbank",
               L"Sacombank", L"SHB", L"TP Bank"});
        this->selectBankBox->Location = System::Drawing::Point(34, 66);
        this->selectBankBox->Name = L"selectBankBox";
        this->selectBankBox->Size = System::Drawing::Size(128, 29);
        this->selectBankBox->TabIndex = 3;
        //
        // labelAccountNumber
        //
        this->labelAccountNumber->AutoSize = true;
        this->labelAccountNumber->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->labelAccountNumber->Location = System::Drawing::Point(32, 32);
        this->labelAccountNumber->Name = L"labelAccountNumber";
        this->labelAccountNumber->Size = System::Drawing::Size(131, 21);
        this->labelAccountNumber->TabIndex = 2;
        this->labelAccountNumber->Text = L"Chon ngan hang:";
        //
        // panelTransfer
        //
        this->panelTransfer->BackColor =
            System::Drawing::SystemColors::ActiveCaption;
        this->panelTransfer->Controls->Add(this->labelReceiver);
        this->panelTransfer->Controls->Add(this->btnSubmit);
        this->panelTransfer->Controls->Add(this->label4);
        this->panelTransfer->Controls->Add(this->amountInput);
        this->panelTransfer->Controls->Add(this->label3);
        this->panelTransfer->Controls->Add(this->pinInput);
        this->panelTransfer->Location = System::Drawing::Point(34, 166);
        this->panelTransfer->Name = L"panelTransfer";
        this->panelTransfer->Size = System::Drawing::Size(456, 217);
        this->panelTransfer->TabIndex = 13;
        this->panelTransfer->Visible = false;
        //
        // labelReceiver
        //
        this->labelReceiver->AutoSize = true;
        this->labelReceiver->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->labelReceiver->Location = System::Drawing::Point(3, 13);
        this->labelReceiver->Name = L"labelReceiver";
        this->labelReceiver->Size = System::Drawing::Size(99, 21);
        this->labelReceiver->TabIndex = 10;
        this->labelReceiver->Text = L"Nguoi nhan: ";
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::Color::Lime;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"#9Slide03 SVN-Kelson Sans Bold", 9.749999F,
            System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSubmit->ForeColor = System::Drawing::Color::Black;
        this->btnSubmit->Location = System::Drawing::Point(7, 175);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(446, 29);
        this->btnSubmit->TabIndex = 6;
        this->btnSubmit->Text = L"Xac nhan chuyen tien";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(
            this, &TransferMoneyForm::btnSubmit_Click);
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label4->Location = System::Drawing::Point(3, 120);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(60, 21);
        this->label4->TabIndex = 12;
        this->label4->Text = L"Ma Pin:";
        //
        // amountInput
        //
        this->amountInput->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->amountInput->Location = System::Drawing::Point(89, 70);
        this->amountInput->Name = L"amountInput";
        this->amountInput->Size = System::Drawing::Size(364, 27);
        this->amountInput->TabIndex = 8;
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label3->Location = System::Drawing::Point(3, 73);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(64, 21);
        this->label3->TabIndex = 11;
        this->label3->Text = L"So tien:";
        //
        // pinInput
        //
        this->pinInput->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold));
        this->pinInput->Location = System::Drawing::Point(89, 120);
        this->pinInput->Name = L"pinInput";
        this->pinInput->Size = System::Drawing::Size(364, 27);
        this->pinInput->TabIndex = 9;
        //
        // TransferMoneyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(568, 441);
        this->Controls->Add(this->panel1);
        this->Name = L"TransferMoneyForm";
        this->Text = L"TransferMoneyForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panelTransfer->ResumeLayout(false);
        this->panelTransfer->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void btnFindAccount_Click(System::Object ^ sender,
                                      System::EventArgs ^ e) {
        String^ bank = selectBankBox->Text;
        String ^ accNumber = accountNumber->Text;

        if (bank == "" || accNumber == "") {
            MessageBox::Show("Nhap day du thong tin !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        } else if (!Validate::isAccountNumber(accNumber)) {
            MessageBox::Show("So tai khoan khong hop le !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            panelTransfer->Visible = false;
            return;
        } else {
            // tim user
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");

            if (users == nullptr) {
                MessageBox::Show("Khong tim thay tai khoan !", "Canh bao",
                                 MessageBoxButtons::OK, MessageBoxIcon::Warning);
                panelTransfer->Visible = false;
                return;
            } else {
                
                for (int i = 0; i < users->Length; i++) {
                    if (users[i]->getAccountNumber() == Convert::ToInt32(accNumber) &&
                        users[i]->getBankName() == bank &&
                        GlobalData::GetCurrentUser()->getAccountNumber() ==
                            users[i]->getAccountNumber()) {
                        MessageBox::Show("Khong duoc chuyen khoan cho chinh ban !",
                                         "Canh bao", MessageBoxButtons::OK,
                                         MessageBoxIcon::Warning);
                        panelTransfer->Visible = false;
                        return;
                    } else if (users[i]->getAccountNumber() ==
                                   Convert::ToInt32(accNumber) &&
                               users[i]->getBankName() == bank) {
                        this->receiver = users[i];
                        receiverIndex = i;
                        break;
                    } else {
                        receiver = nullptr;
                        receiverIndex = -1;
                    }
                }
            }
            if (this->receiver == nullptr) {
                MessageBox::Show("Khong tim thay tai khoan !", "Canh bao",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
                panelTransfer->Visible = false;
                return;
            } else {
                panelTransfer->Visible = true;
                labelReceiver->Text = "Nguoi nhan: " + receiver->getFullName();
            }
        }
    }

  private: // so tien ck toi thieu 10k, toi da 2.000.000 ?
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        double amount = 0;
        int pin = 0;

        if (this->pinInput->Text == "" || this->amountInput->Text == "") {
            MessageBox::Show("Nhap day du thong tin !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else if (!Validate::isNumber(amountInput->Text)) {
            MessageBox::Show("So tien khong hop le !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else if (!Validate::isPin(this->pinInput->Text)) {
            MessageBox::Show("Ma pin khong hop le !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else {
            amount = Convert::ToDouble(this->amountInput->Text);
            pin = Convert::ToInt32(this->pinInput->Text);
        }
            
        if (amount < 10000) {
            MessageBox::Show("So tien ck toi thieu la 10.000 VND !", "Canh bao",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else {
            User ^ sender = GlobalData::GetCurrentUser();

            // xac thuc ma pin
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getAccountNumber() ==
                        sender->getAccountNumber() &&
                    users[i]->getPin() == pin) {
                    // check so du va chuyen khoan
                    if (sender->getBalance() < amount) {
                        MessageBox::Show(
                            "So du khong du de thuc hien giao dich !",
                            "Canh bao", MessageBoxButtons::OK,
                            MessageBoxIcon::Warning);
                        return;
                    } else {
                        sender->setBalance(sender->getBalance() - amount);
                        receiver->setBalance(receiver->getBalance() + amount);

                        // luu lai 2 user vao file
                        users[i] = sender;
                        users[receiverIndex] = receiver;
                        bool isSavedUser = HandleFile::WriteUserArray(users, "users.dat");
                        if (!isSavedUser) {
                            MessageBox::Show("loi may chu, thu lai sau !",
                                             "Canh bao", MessageBoxButtons::OK,
                                             MessageBoxIcon::Warning);
                            return;
                        } else {
                            // luu lich su giao dich
                            Transaction ^ transaction = gcnew Transaction(123, sender->getAccountNumber(),
                                receiver->getAccountNumber(), amount, DateTime::Now.ToString());
                            array<Transaction ^> ^ transactions =
                                HandleFile::ReadTransactionArray(
                                    "transactions.dat");
                            if (transactions == nullptr) {
                                transactions = gcnew array<Transaction ^>(1);
                                transactions[0] = transaction;
                            } else {
                                array<Transaction ^> ^ newTransactions =
                                    gcnew array<Transaction ^>(
                                        transactions->Length + 1);
                                for (int i = 0; i < transactions->Length; i++) {
                                    newTransactions[i] = transactions[i];
                                }
                                newTransactions[transactions->Length] =
                                    transaction;
                                transactions = newTransactions;
                            }
                            bool isSavedTransaction =
                                HandleFile::WriteTransactionArray(
                                    transactions, "transactions.dat");

                            // thong bao chuyen tien thanh cong
                            if (isSavedTransaction && isSavedUser) {
                                MessageBox::Show("Chuyen tien thanh cong !",
                                                 "Thong bao",
                                                 MessageBoxButtons::OK,
                                                 MessageBoxIcon::Information);
                                return;
                            } else {
                                MessageBox::Show("loi may chu, thu lai sau !",
                                                 "Canh bao",
                                                 MessageBoxButtons::OK,
                                                 MessageBoxIcon::Warning);
                                return;
                            }
                        }
                    }
                } else if (users[i]->getAccountNumber() == sender->getAccountNumber()) {
                    if (users[i]->getPin() == 0) {
                        MessageBox::Show("khach hang chua dang ki ma pin !", "Canh bao",
                                         MessageBoxButtons::OK,
                                         MessageBoxIcon::Warning);
                        return;
                    }
                    return;
                }
            }
        }
    }
};
}
