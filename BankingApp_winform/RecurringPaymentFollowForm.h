#pragma once
#include "CustomerCodes.h"
#include "GlobalData.h"
#include "HandleFile.h"
#include "RecurringPayments.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for RecurringPaymentFollowForm
/// </summary>
public
ref class RecurringPaymentFollowForm : public System::Windows::Forms::Form {
  public:
    RecurringPaymentFollowForm(void) {
        InitializeComponent();
        LoadRecurringPaymentFollow();
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~RecurringPaymentFollowForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanelFollow;

  protected:
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
        this->flowLayoutPanelFollow =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->SuspendLayout();
        //
        // flowLayoutPanelFollow
        //
        this->flowLayoutPanelFollow->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->flowLayoutPanelFollow->Location = System::Drawing::Point(0, 0);
        this->flowLayoutPanelFollow->Name = L"flowLayoutPanelFollow";
        this->flowLayoutPanelFollow->Size = System::Drawing::Size(505, 241);
        this->flowLayoutPanelFollow->TabIndex = 0;
        //
        // RecurringPaymentFollowForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(505, 241);
        this->Controls->Add(this->flowLayoutPanelFollow);
        this->ForeColor = System::Drawing::SystemColors::ControlText;
        this->FormBorderStyle =
            System::Windows::Forms::FormBorderStyle::FixedToolWindow;
        this->MaximumSize = System::Drawing::Size(521, 280);
        this->MinimumSize = System::Drawing::Size(521, 280);
        this->Name = L"RecurringPaymentFollowForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"RecurringPaymentFollowForm";
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    /// <summary>
  private:
    Void LoadRecurringPaymentFollow() {

        this->flowLayoutPanelFollow->Controls->Clear();

        array<RecurringPayments ^> ^ recurringPayments =
            HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");

        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        if (users == nullptr || users->Length == 0) {
            return;
        }
        if (recurringPayments == nullptr || recurringPayments->Length == 0) {
            return;
        }
        for (int i = 0; i < recurringPayments->Length; i++) {
            if (recurringPayments[i]->UserAccountNumber !=
                GlobalData::GetCurrentUser()->AccountNumber)
                continue;

            User ^ company =
                findCompanyByCodeId(recurringPayments[i]->CustomerCodeId);
            if (company == nullptr)
                continue;

            Label ^ label = gcnew Label();
            label->AutoSize = false; // Tắt AutoSize để mình tự đặt kích thước
            label->Height = 30;      // Chiều cao dòng
            label->Width = flowLayoutPanelFollow->ClientSize.Width -
                           20; // chừa 10 padding mỗi bên
            label->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            label->Cursor = Cursors::Hand;
            label->Margin = System::Windows::Forms::Padding(
                10, 10, 10, 0); // padding giữa các dòng
            label->BackColor = Color::WhiteSmoke;
            label->Padding = System::Windows::Forms::Padding(
                5, 5, 5, 5); // padding trong label
            label->TextAlign = ContentAlignment::MiddleLeft;

            label->Text = L"Công ty: " + company->FullName +
                          L" | Ngày đến hạn: " +
                          recurringPayments[i]->PaymentDay;

            label->Tag = recurringPayments[i]->Id;
            label->Click += gcnew EventHandler(
                this, &RecurringPaymentFollowForm::labelFollow_Click);

            this->flowLayoutPanelFollow->Controls->Add(label);
        }
    }

    User ^ findCompanyByCodeId(String ^ codeID) {
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        array<CustomerCodes ^> ^ customerCodes =
            HandleFile::ReadCustomerCodesArray("customerCodes.dat");
        if (customerCodes == nullptr || customerCodes->Length == 0)
            return nullptr;
        if (users == nullptr || users->Length == 0)
            return nullptr;

        for (int i = 0; i < customerCodes->Length; i++) {
            if (customerCodes[i]->Id != codeID) {
                continue;
            }
            for (int j = 0; j < users->Length; j++) {
                if (customerCodes[i]->CompanyAccountNumber ==
                    users[j]->AccountNumber) {
                    return users[j];
                }
            }
            return nullptr;
        }
    }



    System::Void
        labelFollow_Click(System::Object ^ sender, System::EventArgs ^ e) {
        Label ^ clickedLabel = dynamic_cast<Label ^>(sender);
        if (clickedLabel != nullptr) {
            String ^ recurringPaymentId =
                safe_cast<String ^>(clickedLabel->Tag);
            System::Windows::Forms::DialogResult result;
            result = MessageBox::Show(L"Bạn có chắc muốn xóa?", L"Xóa",
                                      MessageBoxButtons::YesNo,
                                      MessageBoxIcon::Question);
            if (result == System::Windows::Forms::DialogResult::Yes) {
                array<RecurringPayments ^> ^ allPayments =
                    HandleFile::ReadRecurringPaymentsArray(
                        "recurringPayments.dat");
                List<RecurringPayments ^> ^ updatedPayments =
                    gcnew List<RecurringPayments ^>();
                for each (RecurringPayments ^ p in allPayments) {
                    if (p->Id != recurringPaymentId) { // So sánh theo Id
                        updatedPayments->Add(p);
                    }
                }
                // Ghi lại file
                HandleFile::WriteRecurringPaymentsArray(
                    updatedPayments->ToArray(), "recurringPayments.dat");
                MessageBox::Show(L"Đã xóa thanh toán định kỳ.", "Thành công",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Information);
                this->LoadRecurringPaymentFollow();
            }
        }
    }


};
} // namespace BankingAppwinform
