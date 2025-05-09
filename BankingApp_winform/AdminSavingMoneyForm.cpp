﻿#include "AdminSavingMoneyForm.h"
#include "GradientHelper.h"
namespace BankingAppwinform {

AdminSavingMoneyForm::AdminSavingMoneyForm(void) {
    InitializeComponent();
    loadSavingCustomers();
    loadRequest();
}
AdminSavingMoneyForm::~AdminSavingMoneyForm() {
    if (components) {
        delete components;
    }
}

System::Void
AdminSavingMoneyForm::btnShowCustomer_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {
    if (this->dataGridViewSavingMoney->Visible == true)
        return;
    this->dataGridViewSavingMoney->Visible = true;
    this->dataGridViewRequests->Visible = false;
}

System::Void AdminSavingMoneyForm::btnShowRequest_Click(System::Object ^ sender,
                                                        System::EventArgs ^ e) {

    if (this->dataGridViewRequests->Visible == true)
        return;
    this->dataGridViewSavingMoney->Visible = false;
    this->dataGridViewRequests->Visible = true;
}

void AdminSavingMoneyForm::loadSavingCustomers() {
    try {
        this->dataGridViewSavingMoney->Rows->Clear();

        array<SavingDTO ^> ^ savingItems = SavingServices::GetAllSavingCustomers();

        if (savingItems == nullptr || savingItems->Length == 0) {
            return;
        }

        for (int i = 0; i < savingItems->Length; i++) {

            double currentAmount = 0;
            if (savingItems[i]->SavingCustomer->Status == 1) {
                currentAmount = savingItems[i]->SavingCustomer->TotalAmount();
            } else {
                currentAmount = savingItems[i]->SavingCustomer->Amount + savingItems[i]->SavingCustomer->CalculateInterestAmount();
            }

            String ^ statusMessage = "";
            if (savingItems[i]->SavingCustomer->Status == 0) {
                statusMessage = L"Đang hoạt động";
            } else if (savingItems[i]->SavingCustomer->Status == 1) {
                statusMessage = L"Đã tất toán";
            } else if (savingItems[i]->SavingCustomer->Status == 2) {
                statusMessage = L"Yêu cầu tất toán";
            } else {
                statusMessage = L"Không xác định";
            }

            this->dataGridViewSavingMoney->Rows->Add(
                savingItems[i]->CurrUser->FullName,
                savingItems[i]->SavingCustomer->Type == "nonTermDeposit" ? L"Không kì hạn"
                                                         : L"Có kì hạn",
                savingItems[i]->SavingCustomer->InterestRate, savingItems[i]->SavingCustomer->Amount,
                savingItems[i]->SavingCustomer->DepositDate.ToString("dd/MM/yyyy"), currentAmount,
                statusMessage,
                savingItems[i]->SavingCustomer->Status == 1 ? savingItems[i]->SavingCustomer->PaymentDate.ToString()
                                            : L"Chưa có");
        }

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void AdminSavingMoneyForm::AdminSavingMoneyForm::loadRequest() {
    try {

        // Xóa các dòng hiện tại trong bảng
        this->dataGridViewRequests->Rows->Clear();

        // Đọc danh sách khách hàng tiết kiệm
        array<SavingDTO ^> ^ savingItems = SavingServices::GetAllSavingCustomers();

        if (savingItems == nullptr || savingItems->Length == 0) {
            return;
        }

        // Thêm cột nút nếu chưa có
        if (dataGridViewRequests->Columns["btnSubmit"] == nullptr) {
            DataGridViewButtonColumn ^ btnColumn = gcnew DataGridViewButtonColumn();
            btnColumn->HeaderText = L"Hành động";
            btnColumn->Text = L"Thanh toán";
            btnColumn->UseColumnTextForButtonValue = true;
            btnColumn->Name = "btnSubmit";
            btnColumn->DefaultCellStyle->BackColor = System::Drawing::Color::Green;
            btnColumn->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
            this->dataGridViewRequests->Columns->Add(btnColumn);
        }

        // Đếm dòng được thêm để tránh lỗi index
        int rowIndex = 0;

        for (int i = 0; i < savingItems->Length; i++) {
            if (savingItems[i]->SavingCustomer->Status == 2) {

                double currentAmount = savingItems[i]->SavingCustomer->Amount + savingItems[i]->SavingCustomer->CalculateInterestAmount();


                this->dataGridViewRequests->Rows->Add(
                    savingItems[i]->CurrUser->FullName,
                    savingItems[i]->SavingCustomer->Type == "nonTermDeposit" ? L"Không kì hạn"
                                                             : L"Có kì hạn",
                    savingItems[i]->SavingCustomer->InterestRate.ToString(),
                    savingItems[i]->SavingCustomer->Amount.ToString(),
                    savingItems[i]->SavingCustomer->DepositDate.ToString("dd/MM/yyyy"),
                    currentAmount);

                // Gán dữ liệu vào Tag để xử lý khi click
                this->dataGridViewRequests->Rows[rowIndex]->Tag = savingItems[i];

                // Cập nhật nút hành động
                this->dataGridViewRequests->Rows[rowIndex]
                    ->Cells["btnSubmit"]
                    ->Value = "Thanh toán";

                rowIndex++;
            }
        }

        // Chỉ gán CellClick một lần (kiểm tra nếu chưa gán)
        if (!this->isCellClickEventAttached) {
            this->dataGridViewRequests->CellClick +=
                gcnew DataGridViewCellEventHandler(
                    this, &AdminSavingMoneyForm::dataGridViewRequests_CellClick);
            this->isCellClickEventAttached = true;
        }

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

System::Void AdminSavingMoneyForm::dataGridViewRequests_CellClick(
    System::Object ^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {

    try {

        if (e->RowIndex < 0 || e->ColumnIndex < 0) {
            return;
        }

        if (dataGridViewRequests->Columns[e->ColumnIndex]->Name == "btnSubmit") {
            SavingDTO ^ savingItem = dynamic_cast<SavingDTO ^>(
                dataGridViewRequests->Rows[e->RowIndex]->Tag);

                    
            if (savingItem == nullptr) return;

            SavingCustomers ^ savingCustomer = savingItem->SavingCustomer;

            
            // Xử lý thanh toán yêu cầu rút tiết kiệm
            SavingServices::OnFinishSavingAdmin(savingCustomer);

            MessageBox::Show(L"Đã thanh toán yêu cầu rút tiết kiệm thành công",
                             L"Thông báo", MessageBoxButtons::OK,
                             MessageBoxIcon::Information);

            //// Cập nhật lại giao dịch trong file
            loadRequest();
            loadSavingCustomers();
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

} // namespace BankingAppwinform
