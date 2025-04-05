#pragma once
#include "SavingCustomers.h"
#include "HandleFile.h"
#include "Validate.h"
#include "GlobalData.h"
#include "Utils.h"
#include "User.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for RegisterSavingForm
/// </summary>
public
ref class RegisterSavingForm : public System::Windows::Forms::Form {
  public:
    RegisterSavingForm(String ^ type) {

        this->type = type;

        InitializeComponent();


        this->labelBalance->Text = L"Số dư khả dụng: " +
                                   GlobalData::GetCurrentUser()->getBalance() +
                                   L" VND";
        if (type == "termDeposit") {
            header->Text = L"GỬI TIẾT KIỆM CÓ KÌ HẠN";
            labelInfo->Text = L"Gửi tiết kiệm có kì hạn với lãi xuất (3T 4.5%/năm, 6T 5%/năm, 9T 5.5%/năm, 12T 6%/năm) "
                              L"bạn có thể rút tiền sau khi hết kì hạn";
        } else {
            header->Text = L"GỬI TIẾT KIỆM KHÔNG KÌ HẠN";
            labelInfo->Text =
                L"Gửi tiết kiệm không kì hạn với lãi xuất 4% / năm, "
                L"bạn có thể rút tiền bất cứ khi nào";
            label5->Text = L"Chọn kì hạn:";
            selectTermBox->Items->Clear();
            selectTermBox->Items->Add(L"Không kì hạn");
            selectTermBox->SelectedIndex = 0;
            selectTermBox->Enabled = false;
        }
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~RegisterSavingForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel5;

  protected:
  private:
    System::Windows::Forms::TextBox ^ pinInput;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::ComboBox ^ selectTermBox;

  private:


  private:
    System::Windows::Forms::Button ^ btnClose;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Label ^ labelInfo;

  private:
    System::Windows::Forms::Panel ^ panel6;

  private:
    System::Windows::Forms::TextBox ^ amountInput;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ header;

  private:
    System::Windows::Forms::Label ^ labelBalance;

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
        this->panel5 = (gcnew System::Windows::Forms::Panel());
        this->pinInput = (gcnew System::Windows::Forms::TextBox());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectTermBox = (gcnew System::Windows::Forms::ComboBox());
        this->btnClose = (gcnew System::Windows::Forms::Button());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->labelInfo = (gcnew System::Windows::Forms::Label());
        this->panel6 = (gcnew System::Windows::Forms::Panel());
        this->amountInput = (gcnew System::Windows::Forms::TextBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->header = (gcnew System::Windows::Forms::Label());
        this->labelBalance = (gcnew System::Windows::Forms::Label());
        this->panel5->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panel6->SuspendLayout();
        this->SuspendLayout();
        //
        // panel5
        //
        this->panel5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel5->BackColor = System::Drawing::Color::White;
        this->panel5->Controls->Add(this->pinInput);
        this->panel5->Location = System::Drawing::Point(543, 297);
        this->panel5->Margin = System::Windows::Forms::Padding(4);
        this->panel5->Name = L"panel5";
        this->panel5->Size = System::Drawing::Size(255, 46);
        this->panel5->TabIndex = 86;
        //
        // pinInput
        //
        this->pinInput->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->pinInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->pinInput->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->pinInput->Location = System::Drawing::Point(28, 7);
        this->pinInput->Margin = System::Windows::Forms::Padding(4);
        this->pinInput->MaxLength = 6;
        this->pinInput->Multiline = true;
        this->pinInput->Name = L"pinInput";
        this->pinInput->Size = System::Drawing::Size(227, 34);
        this->pinInput->TabIndex = 29;
        //
        // label3
        //
        this->label3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label3->AutoSize = true;
        this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label3->ForeColor = System::Drawing::Color::Transparent;
        this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label3->Location = System::Drawing::Point(488, 307);
        this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(47, 27);
        this->label3->TabIndex = 85;
        this->label3->Text = L"PIN:";
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
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(43, 307);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(116, 27);
        this->label5->TabIndex = 83;
        this->label5->Text = L"Chọn kì hạn:";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->selectTermBox);
        this->panel4->Location = System::Drawing::Point(210, 297);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(248, 46);
        this->panel4->TabIndex = 84;
        //
        // selectTermBox
        //
        this->selectTermBox->Anchor =
            System::Windows::Forms::AnchorStyles::Left;
        this->selectTermBox->DropDownStyle =
            System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectTermBox->FlatStyle =
            System::Windows::Forms::FlatStyle::Popup;
        this->selectTermBox->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
        this->selectTermBox->ForeColor = System::Drawing::Color::Black;
        this->selectTermBox->FormattingEnabled = true;
        this->selectTermBox->Items->AddRange(
            gcnew cli::array<System::Object ^>(4){L"3", L"6", L"9", L"12"});
        this->selectTermBox->Location = System::Drawing::Point(4, 7);
        this->selectTermBox->Margin = System::Windows::Forms::Padding(4);
        this->selectTermBox->Name = L"selectTermBox";
        this->selectTermBox->Size = System::Drawing::Size(239, 33);
        this->selectTermBox->TabIndex = 3;
        //
        // btnClose
        //
        this->btnClose->BackColor = System::Drawing::SystemColors::HotTrack;
        this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClose->FlatAppearance->BorderSize = 0;
        this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClose->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClose->ForeColor = System::Drawing::Color::White;
        this->btnClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnClose->Location = System::Drawing::Point(126, 398);
        this->btnClose->Margin = System::Windows::Forms::Padding(4);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(275, 52);
        this->btnClose->TabIndex = 77;
        this->btnClose->Text = L"THOÁT";
        this->btnClose->UseVisualStyleBackColor = false;
        this->btnClose->Click += gcnew System::EventHandler(
            this, &RegisterSavingForm::btnClose_Click);
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(434, 398);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(285, 52);
        this->btnSubmit->TabIndex = 76;
        this->btnSubmit->Text = L"XÁC NHẬN";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(
            this, &RegisterSavingForm::btnSubmit_Click);
        //
        // labelInfo
        //
        this->labelInfo->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->labelInfo->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelInfo->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelInfo->ForeColor = System::Drawing::Color::Transparent;
        this->labelInfo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelInfo->Location = System::Drawing::Point(0, 98);
        this->labelInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelInfo->Name = L"labelInfo";
        this->labelInfo->Size = System::Drawing::Size(849, 27);
        this->labelInfo->TabIndex = 82;
        this->labelInfo->Text = L"Gửi tiết kiệm không kì hạn với lãi xuất 4% / "
                                L"năm, bạn có thể rút tiền bất cứ khi "
                                L"nào";
        this->labelInfo->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panel6
        //
        this->panel6->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel6->BackColor = System::Drawing::Color::White;
        this->panel6->Controls->Add(this->amountInput);
        this->panel6->Location = System::Drawing::Point(210, 208);
        this->panel6->Margin = System::Windows::Forms::Padding(4);
        this->panel6->Name = L"panel6";
        this->panel6->Size = System::Drawing::Size(588, 46);
        this->panel6->TabIndex = 81;
        //
        // amountInput
        //
        this->amountInput->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->amountInput->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->amountInput->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->amountInput->Location = System::Drawing::Point(28, 7);
        this->amountInput->Margin = System::Windows::Forms::Padding(4);
        this->amountInput->MaxLength = 9;
        this->amountInput->Multiline = true;
        this->amountInput->Name = L"amountInput";
        this->amountInput->Size = System::Drawing::Size(560, 34);
        this->amountInput->TabIndex = 29;
        //
        // label2
        //
        this->label2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label2->AutoSize = true;
        this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label2->ForeColor = System::Drawing::Color::Transparent;
        this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label2->Location = System::Drawing::Point(42, 216);
        this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(156, 27);
        this->label2->TabIndex = 80;
        this->label2->Text = L"Nhập số tiền gửi:";
        //
        // header
        //
        this->header->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 22, System::Drawing::FontStyle::Bold));
        this->header->ForeColor = System::Drawing::Color::White;
        this->header->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->header->Location = System::Drawing::Point(-2, 41);
        this->header->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->header->Name = L"header";
        this->header->Size = System::Drawing::Size(851, 48);
        this->header->TabIndex = 79;
        this->header->Text = L"GỬI TIẾT KIỆM KHÔNG KÌ HẠN";
        this->header->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // labelBalance
        //
        this->labelBalance->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->labelBalance->AutoSize = true;
        this->labelBalance->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelBalance->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->labelBalance->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 13.8F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelBalance->ForeColor = System::Drawing::Color::SpringGreen;
        this->labelBalance->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->labelBalance->Location = System::Drawing::Point(41, 157);
        this->labelBalance->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelBalance->Name = L"labelBalance";
        this->labelBalance->Size = System::Drawing::Size(394, 30);
        this->labelBalance->TabIndex = 78;
        this->labelBalance->Text = L"Số dư hiện tại của bạn: 80.000.000 vnđ";
        //
        // RegisterSavingForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(848, 513);
        this->Controls->Add(this->panel5);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->btnClose);
        this->Controls->Add(this->btnSubmit);
        this->Controls->Add(this->labelInfo);
        this->Controls->Add(this->panel6);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->header);
        this->Controls->Add(this->labelBalance);
        this->FormBorderStyle =
            System::Windows::Forms::FormBorderStyle::FixedToolWindow;
        this->MaximumSize = System::Drawing::Size(866, 560);
        this->MinimumSize = System::Drawing::Size(866, 560);
        this->Name = L"RegisterSavingForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"RegisterSavingForm";
        this->panel5->ResumeLayout(false);
        this->panel5->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel6->ResumeLayout(false);
        this->panel6->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
  private:
    String ^ type;


    System::Void header_Click(System::Object ^ sender, System::EventArgs ^ e) {}

  private:
    System::Void btnClose_Click(System::Object ^ sender,
                                System::EventArgs ^ e) {
        this->Close();
    }

  private:
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e) {
        String ^ amount = amountInput->Text;
        String ^ pin = pinInput->Text;
        int term = 0;

        if (amount->Length == 0 || pin->Length == 0) {
            MessageBox::Show(L"Vui lòng nhập đầy đủ thông tin");
            return;
        }
        if (!Validate::isNumber(amount)) {
            MessageBox::Show(L"Số tiền gửi không hợp lệ");
            return;
        }
        if (!Validate::isPin(pin)) {
            MessageBox::Show(L"PIN không hợp lệ");
            return;
        }
        if (Convert::ToDouble(amount) < 1000000) {
            MessageBox::Show(L"Số tiền gửi tối thiểu là 1.000.000 vnđ");
            return;
        }
        if (this->type == "termDeposit") {
            if (selectTermBox->SelectedIndex == -1) {
                MessageBox::Show(L"Vui lòng chọn kì hạn");
                return;
            } else {
                term = Convert::ToInt32(selectTermBox->Text);
            }
        }
        if (Convert::ToDouble(amount) >
            GlobalData::GetCurrentUser()->getBalance()) {
            MessageBox::Show(L"Số tiền gửi không được lớn hơn số dư khả dụng");
            return;
        }

        // Tạo id cho gói tiết kiệm
        String ^ id = Utils::createUniqueID(L"SC");

        // Tạo gói tiết kiệm
        String ^ accountNumber = GlobalData::GetCurrentUser()->getAccountNumber();
        SavingCustomers ^ savingCustomer = gcnew SavingCustomers(id, accountNumber,
            Convert::ToDouble(amount), this->type, term);

        // Lưu gói tiết kiệm vào file
        array<SavingCustomers ^> ^ savingCustomers =
            HandleFile::ReadSavingCustomersArray("savingCustomers.dat");
        if (savingCustomers == nullptr) {
            savingCustomers = gcnew array<SavingCustomers ^>(0);
        } else {
            array<SavingCustomers ^> ^ newSavingCustomers =
                gcnew array<SavingCustomers ^>(savingCustomers->Length + 1);
            for (int i = 0; i < savingCustomers->Length; i++) {
                newSavingCustomers[i] = savingCustomers[i];
            }
            newSavingCustomers[savingCustomers->Length] = savingCustomer;
            savingCustomers = newSavingCustomers;
        }
        bool isSaved = HandleFile::WriteSavingCustomersArray(
            savingCustomers, "savingCustomers.dat");
        if (isSaved) {
            // Cập nhật số dư của người dùng
            double newBalance = GlobalData::GetCurrentUser()->getBalance() -
                                Convert::ToDouble(amount);
            GlobalData::GetCurrentUser()->setBalance(newBalance);

            // Cập nhật số dư của người dùng trong file
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getAccountNumber() == accountNumber) {
                    users[i]->setBalance(newBalance);
                    break;
                }
            }
            HandleFile::WriteUserArray(users, "users.dat");
            MessageBox::Show(L"Đăng ký tiết kiệm thành công");
            this->Close();
        } else {
            MessageBox::Show(L"Đăng ký tiết kiệm thất bại");
        }
    }
};
} // namespace BankingAppwinform
