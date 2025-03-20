#pragma once
#include "GlobalData.h"
#include "HandleFile.h"
#include "RecurringPayments.h"
#include "User.h"
#include "Validate.h"
#include "RecurringPaymentRequest.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for ClientRecurringPaymentForm
/// </summary>
public
ref class ClientRecurringPaymentForm : public System::Windows::Forms::Form {
  public:
    ClientRecurringPaymentForm(void) {
        InitializeComponent();
        loadRecurringPaymentData();
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~ClientRecurringPaymentForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::DataGridView ^ dataGridViewRecurring;

  private:
  private:
  private:
  private:
  private:
  private:
    System::Windows::Forms::Panel ^ panelForm;

  private:
    System::Windows::Forms::Label ^ labelClientName;

  private:


  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::TextBox ^ amountRecurringPayment;

  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column7;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column8;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column10;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column11;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column12;

  private:
  private:
  private:
  private:
  private:
  private:
  protected:
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
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle1 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle2 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle3 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panelForm = (gcnew System::Windows::Forms::Panel());
        this->labelClientName = (gcnew System::Windows::Forms::Label());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->amountRecurringPayment =
            (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->dataGridViewRecurring =
            (gcnew System::Windows::Forms::DataGridView());
        this->Column7 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column8 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column10 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column11 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column12 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panel1->SuspendLayout();
        this->panelForm->SuspendLayout();
        this->panel4->SuspendLayout();
        this->panel2->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->BeginInit();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::Teal;
        this->panel1->Controls->Add(this->panelForm);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
        this->panel1->Location = System::Drawing::Point(0, 406);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(877, 208);
        this->panel1->TabIndex = 0;
        //
        // panelForm
        //
        this->panelForm->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panelForm->Controls->Add(this->labelClientName);
        this->panelForm->Controls->Add(this->labelAuth);
        this->panelForm->Controls->Add(this->panel4);
        this->panelForm->Controls->Add(this->btnSubmit);
        this->panelForm->Location = System::Drawing::Point(60, 27);
        this->panelForm->Margin = System::Windows::Forms::Padding(4);
        this->panelForm->Name = L"panelForm";
        this->panelForm->Size = System::Drawing::Size(752, 153);
        this->panelForm->TabIndex = 0;
        this->panelForm->Visible = false;
        //
        // labelClientName
        //
        this->labelClientName->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->labelClientName->AutoSize = true;
        this->labelClientName->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelClientName->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 15, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelClientName->ForeColor = System::Drawing::Color::Lime;
        this->labelClientName->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->labelClientName->Location = System::Drawing::Point(4, 10);
        this->labelClientName->Margin =
            System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelClientName->Name = L"labelClientName";
        this->labelClientName->Size = System::Drawing::Size(401, 33);
        this->labelClientName->TabIndex = 38;
        this->labelClientName->Text = L"Bạn đa chọn khách hàng: LE SI TOAN";
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(-3, 69);
        this->labelAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(293, 27);
        this->labelAuth->TabIndex = 36;
        this->labelAuth->Text = L"Nhập số tiền yêu cầu thanh toán:";
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->amountRecurringPayment);
        this->panel4->Location = System::Drawing::Point(3, 100);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(517, 46);
        this->panel4->TabIndex = 37;
        //
        // amountRecurringPayment
        //
        this->amountRecurringPayment->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->amountRecurringPayment->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->amountRecurringPayment->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
        this->amountRecurringPayment->Location = System::Drawing::Point(24, 7);
        this->amountRecurringPayment->Margin =
            System::Windows::Forms::Padding(4);
        this->amountRecurringPayment->MaxLength = 9;
        this->amountRecurringPayment->Multiline = true;
        this->amountRecurringPayment->Name = L"amountRecurringPayment";
        this->amountRecurringPayment->Size = System::Drawing::Size(493, 34);
        this->amountRecurringPayment->TabIndex = 29;
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor = System::Windows::Forms::AnchorStyles::Right;
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(535, 100);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(220, 46);
        this->btnSubmit->TabIndex = 35;
        this->btnSubmit->Text = L"YÊU CẦU";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(
            this, &ClientRecurringPaymentForm::btnSubmit_Click);
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::Teal;
        this->panel2->Controls->Add(this->dataGridViewRecurring);
        this->panel2->Location = System::Drawing::Point(0, -2);
        this->panel2->Margin = System::Windows::Forms::Padding(4);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(877, 401);
        this->panel2->TabIndex = 1;
        //
        // dataGridViewRecurring
        //
        this->dataGridViewRecurring->AllowUserToAddRows = false;
        this->dataGridViewRecurring->AllowUserToDeleteRows = false;
        dataGridViewCellStyle1->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle1->BackColor = System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
        dataGridViewCellStyle1->SelectionBackColor =
            System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->SelectionForeColor =
            System::Drawing::Color::Transparent;
        this->dataGridViewRecurring->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle1;
        this->dataGridViewRecurring->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewRecurring->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewRecurring->CellBorderStyle = System::Windows::Forms::
            DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewRecurring->ColumnHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
        dataGridViewCellStyle2->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle2->BackColor = System::Drawing::Color::Teal;
        dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
        dataGridViewCellStyle2->SelectionBackColor =
            System::Drawing::Color::Transparent;
        dataGridViewCellStyle2->SelectionForeColor =
            System::Drawing::Color::White;
        dataGridViewCellStyle2->WrapMode =
            System::Windows::Forms::DataGridViewTriState::True;
        this->dataGridViewRecurring->ColumnHeadersDefaultCellStyle =
            dataGridViewCellStyle2;
        this->dataGridViewRecurring->ColumnHeadersHeight = 40;
        this->dataGridViewRecurring->Columns->AddRange(
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(5){
                this->Column7, this->Column8, this->Column10, this->Column11,
                this->Column12});
        dataGridViewCellStyle3->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle3->BackColor = System::Drawing::Color::MintCream;
        dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(
            L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle3->ForeColor =
            System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle3->SelectionBackColor =
            System::Drawing::Color::Cyan;
        dataGridViewCellStyle3->SelectionForeColor =
            System::Drawing::SystemColors::ControlText;
        dataGridViewCellStyle3->WrapMode =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewRecurring->DefaultCellStyle = dataGridViewCellStyle3;
        this->dataGridViewRecurring->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->dataGridViewRecurring->EnableHeadersVisualStyles = false;
        this->dataGridViewRecurring->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewRecurring->Location = System::Drawing::Point(0, 0);
        this->dataGridViewRecurring->Margin =
            System::Windows::Forms::Padding(4);
        this->dataGridViewRecurring->Name = L"dataGridViewRecurring";
        this->dataGridViewRecurring->ReadOnly = true;
        this->dataGridViewRecurring->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewRecurring->RowHeadersVisible = false;
        this->dataGridViewRecurring->RowHeadersWidth = 51;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->BackColor =
            System::Drawing::Color::White;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle->ForeColor =
            System::Drawing::Color::Black;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewRecurring->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewRecurring->RowTemplate->Height = 40;
        this->dataGridViewRecurring->RowTemplate->ReadOnly = true;
        this->dataGridViewRecurring->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewRecurring->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewRecurring->Size = System::Drawing::Size(877, 401);
        this->dataGridViewRecurring->TabIndex = 5;
        //
        // Column7
        //
        this->Column7->HeaderText = L"Tên KH";
        this->Column7->MinimumWidth = 6;
        this->Column7->Name = L"Column7";
        this->Column7->ReadOnly = true;
        //
        // Column8
        //
        this->Column8->HeaderText = L"STK KH";
        this->Column8->MinimumWidth = 6;
        this->Column8->Name = L"Column8";
        this->Column8->ReadOnly = true;
        //
        // Column10
        //
        this->Column10->HeaderText = L"Số tháng TTĐK";
        this->Column10->MinimumWidth = 6;
        this->Column10->Name = L"Column10";
        this->Column10->ReadOnly = true;
        //
        // Column11
        //
        this->Column11->HeaderText = L"Ngày đến hạn";
        this->Column11->MinimumWidth = 6;
        this->Column11->Name = L"Column11";
        this->Column11->ReadOnly = true;
        //
        // Column12
        //
        this->Column12->HeaderText = L"Tiền nợ";
        this->Column12->MinimumWidth = 6;
        this->Column12->Name = L"Column12";
        this->Column12->ReadOnly = true;
        //
        // ClientRecurringPaymentForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(877, 614);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"ClientRecurringPaymentForm";
        this->Text = L"ClientRecurringPaymentForm";
        this->panel1->ResumeLayout(false);
        this->panelForm->ResumeLayout(false);
        this->panelForm->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->panel2->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewRecurring))
            ->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion

  private:
    void loadRecurringPaymentData() {
        dataGridViewRecurring->Rows->Clear();

        array<RecurringPayments ^> ^ recurringPayments =
            HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        if (users == nullptr) {
            return;
        }

        for each (RecurringPayments ^ payment in recurringPayments) {
            if (payment->CompanyAccountNumber !=
                GlobalData::GetCurrentUser()->AccountNumber) {
                continue;
            }
            User ^ user = nullptr;
            for each (User ^ u in users) {
                if (u->AccountNumber == payment->UserAccountNumber) {
                    user = u;
                    break;
                }
            }

            dataGridViewRecurring->Rows->Add(
                user->FullName, payment->UserAccountNumber, payment->Monthly,
                payment->PaymentDay.ToString("dd/MM/yyyy"), payment->Debt);
        }

        this->dataGridViewRecurring->CellClick +=
            gcnew DataGridViewCellEventHandler(
                this,
                &ClientRecurringPaymentForm::dataGridViewRecurring_CellClick);
    }

  private:
    System::Void dataGridViewRecurring_CellClick(
        System::Object ^ sender,
        System::Windows::Forms::DataGridViewCellEventArgs ^ e) {

        this->amountRecurringPayment->Text = "";
        this->amountRecurringPayment->ReadOnly = false;

        if (e->RowIndex >= 0) { // Kiểm tra nếu không phải header

            String ^ clientFullName = dataGridViewRecurring->Rows[e->RowIndex]
                                          ->Cells[0]
                                          ->Value->ToString();
            int clientAccountNumber = Convert::ToInt32(
                dataGridViewRecurring->Rows[e->RowIndex]->Cells[1]->Value);
            // int clientMonthly = Convert::ToInt32(
            //     dataGridViewRecurring->Rows[e->RowIndex]->Cells[2]->Value);
            DateTime clientPaymentDay =
                DateTime::Parse(dataGridViewRecurring->Rows[e->RowIndex]
                                    ->Cells[3]
                                    ->Value->ToString());
            double clientDebt = Convert::ToDouble(
                dataGridViewRecurring->Rows[e->RowIndex]->Cells[4]->Value);

            //show thông tin và tự động điền vào form chuyển tiền
            this->panelForm->Visible = true;
            this->labelClientName->Text =
                L"Bạn đã chọn khách hàng: " + clientFullName +
                " | STK: " + clientAccountNumber;
            if (clientDebt > 0) {
                this->amountRecurringPayment->Text = clientDebt.ToString();
                this->amountRecurringPayment->ReadOnly = true;
            }
            this->currClientAccountNumber = clientAccountNumber;
            this->currClientPaymentDay = clientPaymentDay;
        }
    }

  private:
    int currClientAccountNumber = 0;
    DateTime currClientPaymentDay;

    System::Void btnSubmit_Click(System::Object ^ sender, System::EventArgs ^ e) {

        String ^ amount = this->amountRecurringPayment->Text;
        if (!Validate::isNumber(amount)) {
            MessageBox::Show(L"Số tiền không hợp lệ", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else if (currClientAccountNumber == 0 || currClientPaymentDay == DateTime()) {
            MessageBox::Show(L"Cố lỗi xảy ra", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        } else if (DateTime::Now.Date < DateTime(currClientPaymentDay).Date) {
            MessageBox::Show(L"Chưa đến ngày thanh toán định kì", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }
        
        // Tạo yêu cầu thanh toán định kỳ
        RecurringPaymentRequest ^ request = gcnew RecurringPaymentRequest(
            currClientAccountNumber,
            GlobalData::GetCurrentUser()->AccountNumber,
            Convert::ToDouble(amount));

        // lưu vào file
        array<RecurringPaymentRequest ^> ^ requests =
            HandleFile::ReadRecurringPaymentRequestArray(
                "recurringPaymentRequests.dat");
        if (requests == nullptr) {
            requests = gcnew array<RecurringPaymentRequest ^>(1);
            requests[0] = request;
        } else {
            for (int i = 0; i < requests->Length; i++) {
                if (requests[i]->UserAccountNumber ==
                        request->UserAccountNumber &&
                    requests[i]->CompanyAccountNumber ==
                        request->CompanyAccountNumber) {
                    MessageBox::Show(L"Yêu cầu thanh toán đã tồn tại",
                                     "Cảnh báo", MessageBoxButtons::OK,
                                     MessageBoxIcon::Warning);
                    return;
                }
            }
            Array::Resize(requests, requests->Length + 1);
            requests[requests->Length - 1] = request;
        }
        bool isSaveRequest = HandleFile::WriteRecurringPaymentRequestArray(
            requests, "recurringPaymentRequests.dat");
        if (!isSaveRequest) {
            
            MessageBox::Show(L"Lỗi khi gửi yêu cầu", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // thay đổi số tiền nợ
        array<RecurringPayments ^> ^ recurringPayments =
            HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
        for (int i = 0; i < recurringPayments->Length; i++) {
            if (recurringPayments[i]->UserAccountNumber == currClientAccountNumber &&
                recurringPayments[i]->CompanyAccountNumber ==
                    GlobalData::GetCurrentUser()->AccountNumber
                ) {
                recurringPayments[i]->Debt = Convert::ToDouble(amount);
                break;
            }
        }
        bool isChangedRecurring = HandleFile::WriteRecurringPaymentsArray(
            recurringPayments,
                                               "recurringPayments.dat");
        if (isChangedRecurring) {
            MessageBox::Show(L"Yêu cầu thanh toán đã được gửi", "Thông báo",
                             MessageBoxButtons::OK,
                             MessageBoxIcon::Information);
            this->panelForm->Visible = false;
            this->loadRecurringPaymentData();
        } else {
            MessageBox::Show(L"Lỗi khi cập nhật số tiền nợ", "Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

};
} // namespace BankingAppwinform
