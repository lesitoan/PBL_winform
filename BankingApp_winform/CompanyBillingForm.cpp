﻿
#include "CompanyBillingForm.h"
#include "AdminForm.h"

namespace BankingAppwinform {

CompanyBillingForm::CompanyBillingForm(String^ companyId) {
    InitializeComponent();
    loadRecurringPaymentData(companyId);
}

CompanyBillingForm::~CompanyBillingForm() {
    if (components) {
        delete components;
    }
}

void CompanyBillingForm::loadRecurringPaymentData(String ^ companyId) {
    try {
        dataGridViewRecurring->Rows->Clear();

        // Thêm cột "Xóa" nếu chưa có
        if (!dataGridViewRecurring->Columns->Contains(
                dataGridViewRecurring->Columns["DeleteColumn"])) {
            DataGridViewButtonColumn ^ deleteColumn =
                gcnew DataGridViewButtonColumn();
            deleteColumn->HeaderText = "Xóa";
            deleteColumn->Text = "Xóa";
            deleteColumn->UseColumnTextForButtonValue = true;
            deleteColumn->Name = "DeleteColumn";
            dataGridViewRecurring->Columns->Add(deleteColumn);
        }

        // Đọc dữ liệu từ file
        array<RecurringPaymentDTO ^> ^ data = RecurringPaymentServices::GetRecurringPaymentByCompanyId(companyId);
        if (data == nullptr || data->Length == 0) {
            return;
        }

        // Lặp qua từng khoản thanh toán định kỳ
        for each (RecurringPaymentDTO ^ payment in data) {
            // Thêm dòng vào DataGridView
            int rowIndex = dataGridViewRecurring->Rows->Add(
                payment->DataCustomerCodes->Code, payment->DataUser->FullName, payment->DataUser->AccountNumber,
                payment->DataRecurringPayment->PaymentDay);

            dataGridViewRecurring->Rows[rowIndex]->Tag = payment;
        }

        this->dataGridViewRecurring->CellClick +=
            gcnew DataGridViewCellEventHandler(
                this, &CompanyBillingForm::dataGridViewRecurring_CellClick);

    } catch (Exception ^ ex) {
        MessageBox::Show(L"Đã xảy ra lỗi khi tải dữ liệu thanh toán định kỳ",
                         L"Lỗi", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void CompanyBillingForm::dataGridViewRecurring_CellClick(
    System::Object ^ sender,DataGridViewCellEventArgs ^ e) {

    try {
        // Kiểm tra click hợp lệ và click vào cột "Xóa"
        if (e->RowIndex >= 0 &&
            e->ColumnIndex == dataGridViewRecurring->Columns["DeleteColumn"]->Index) {
            // Xác nhận xóa
            System::Windows::Forms::DialogResult result;
            result = MessageBox::Show(L"Bạn có chắc muốn xóa?",
                                      L"XÓa", MessageBoxButtons::YesNo,
                                      MessageBoxIcon::Question);
            if (result == System::Windows::Forms::DialogResult::No)
                return;

                // Lấy dòng hiện tại và payment được lưu trong Tag
            DataGridViewRow ^ row = dataGridViewRecurring->Rows[e->RowIndex];
            RecurringPaymentDTO ^ paymentToDelete =
                dynamic_cast<RecurringPaymentDTO ^>(row->Tag);

            if (paymentToDelete == nullptr)
                return;

            RecurringPaymentServices::DeleteRecurringPaymentById(paymentToDelete->DataRecurringPayment->Id);

            dataGridViewRecurring->Rows->RemoveAt(e->RowIndex);
        }    
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void CompanyBillingForm::OnUndoClick(Object ^ sender, EventArgs ^ e) {
    AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
    if (adminForm != nullptr) {
        adminForm->UndoLastForm();
    }
}
}; // namespace BankingAppwinform
