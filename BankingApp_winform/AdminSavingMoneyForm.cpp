#include "AdminSavingMoneyForm.h"

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
    this->dataGridViewSavingMoney->Rows->Clear();

    array<SavingCustomers ^> ^ savingItems =
        HandleFile::ReadSavingCustomersArray("savingCustomers.dat");
    if (savingItems == nullptr || savingItems->Length == 0) {
        return;
    }
    for (int i = 0; i < savingItems->Length; i++) {

        double currentAmount = 0;
        if (savingItems[i]->Status == 1) {
            currentAmount = savingItems[i]->InterestAmount;
        } else {
            TimeSpan duration = DateTime::Now - savingItems[i]->DepositDate;
            currentAmount = savingItems[i]->Amount +
                            (savingItems[i]->Amount *
                             savingItems[i]->InterestRate * duration.Days) /
                                365.0;
        }

        String ^ statusMessage = "";
        if (savingItems[i]->Status == 0) {
            statusMessage = L"Đang hoạt động";
        } else if (savingItems[i]->Status == 1) {
            statusMessage = L"Đã tất toán";
        } else if (savingItems[i]->Status == 2) {
            statusMessage = L"Yêu cầu tất toán";
        } else {
            statusMessage = L"Không xác định";
        }

        this->dataGridViewSavingMoney->Rows->Add(
            savingItems[i]->UserAccountNumber,
            savingItems[i]->Type == "nonTermDeposit" ? L"Không kì hạn"
                                                     : L"Có kì hạn",
            savingItems[i]->InterestRate, savingItems[i]->Amount,
            savingItems[i]->DepositDate.ToString("dd/MM/yyyy"), currentAmount,
            statusMessage,
            savingItems[i]->Status == 1 ? savingItems[i]->PaymentDate
                                        : L"Chưa có");
    }
}

void AdminSavingMoneyForm::AdminSavingMoneyForm::loadRequest() {
    // Xóa các dòng hiện tại trong bảng
    this->dataGridViewRequests->Rows->Clear();

    // Đọc danh sách khách hàng tiết kiệm
    array<SavingCustomers ^> ^ savingItems =
        HandleFile::ReadSavingCustomersArray("savingCustomers.dat");
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
        if (savingItems[i]->Status == 2) {

            TimeSpan duration = DateTime::Now - savingItems[i]->DepositDate;
            double currentAmount =
                savingItems[i]->Amount +
                (savingItems[i]->Amount * savingItems[i]->InterestRate *
                 duration.Days) /
                    365.0;

            this->dataGridViewRequests->Rows->Add(
                savingItems[i]->UserAccountNumber,
                savingItems[i]->Type == "nonTermDeposit" ? L"Không kì hạn"
                                                         : L"Có kì hạn",
                savingItems[i]->InterestRate.ToString(),
                savingItems[i]->Amount.ToString(),
                savingItems[i]->DepositDate.ToString("dd/MM/yyyy"),
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
}

System::Void AdminSavingMoneyForm::dataGridViewRequests_CellClick(
    System::Object ^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {
    if (e->RowIndex < 0 || e->ColumnIndex < 0) {
        return;
    }
    if (dataGridViewRequests->Columns[e->ColumnIndex]->Name == "btnSubmit") {
        SavingCustomers ^ savingItem = dynamic_cast<SavingCustomers ^>(
            dataGridViewRequests->Rows[e->RowIndex]->Tag);
        if (savingItem == nullptr)
            return;

        // Cập nhật lại thông tin trong file
        array<SavingCustomers ^> ^ savingItems =
            HandleFile::ReadSavingCustomersArray("savingCustomers.dat");
        for (int i = 0; i < savingItems->Length; i++) {
            if (savingItems[i]->Id == savingItem->Id) {
                savingItems[i]->Status = 1;
                savingItems[i]->PaymentDate =
                    DateTime::Now.ToString("dd/MM/yyyy");

                TimeSpan duration = DateTime::Now - savingItems[i]->DepositDate;

                savingItems[i]->InterestAmount =
                    savingItems[i]->Amount +
                    (savingItems[i]->Amount * savingItems[i]->InterestRate *
                     duration.Days / 365.0);

                break;
            }
        }
        HandleFile::WriteSavingCustomersArray(savingItems,
                                              "savingCustomers.dat");

        MessageBox::Show(L"Đã thanh toán yêu cầu rút tiết kiệm thành công",
                         L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);

        // Cập nhật lại giao dịch trong file
        loadRequest();
        loadSavingCustomers();
    }
}

} // namespace BankingAppwinform
