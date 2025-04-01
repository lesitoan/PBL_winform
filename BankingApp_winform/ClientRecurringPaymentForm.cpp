#include "ClientRecurringPaymentForm.h"

namespace BankingAppwinform {

ClientRecurringPaymentForm::ClientRecurringPaymentForm(void) {
    InitializeComponent();
    loadRecurringPaymentData();
}

ClientRecurringPaymentForm::~ClientRecurringPaymentForm() {
    if (components) {
        delete components;
    }
}
void ClientRecurringPaymentForm::loadRecurringPaymentData() {
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
            this, &ClientRecurringPaymentForm::dataGridViewRecurring_CellClick);
}

System::Void ClientRecurringPaymentForm::dataGridViewRecurring_CellClick(
    System::Object ^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {

    this->amountRecurringPayment->Text = "";
    this->amountRecurringPayment->ReadOnly = false;

    if (e->RowIndex >= 0) { // Kiểm tra nếu không phải header

        String ^ clientFullName = dataGridViewRecurring->Rows[e->RowIndex]
                                      ->Cells[0]
                                      ->Value->ToString();
        String ^ clientAccountNumber = dataGridViewRecurring->Rows[e->RowIndex]
                                      ->Cells[1]
                                      ->Value->ToString();
        // int clientMonthly = Convert::ToInt32(
        //     dataGridViewRecurring->Rows[e->RowIndex]->Cells[2]->Value);
        DateTime clientPaymentDay =
            DateTime::Parse(dataGridViewRecurring->Rows[e->RowIndex]
                                ->Cells[3]
                                ->Value->ToString());
        double clientDebt = Convert::ToDouble(
            dataGridViewRecurring->Rows[e->RowIndex]->Cells[4]->Value);

        // show thông tin và tự động điền vào form chuyển tiền
        this->panelForm->Visible = true;
        this->labelClientName->Text = L"Bạn đã chọn khách hàng: " +
                                      clientFullName +
                                      " | STK: " + clientAccountNumber;
        if (clientDebt > 0) {
            this->amountRecurringPayment->Text = clientDebt.ToString();
            this->amountRecurringPayment->ReadOnly = true;
        }
        this->currClientAccountNumber = clientAccountNumber;
        this->currClientPaymentDay = clientPaymentDay;
    }
}

System::Void
ClientRecurringPaymentForm::btnSubmit_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {

    String ^ amount = this->amountRecurringPayment->Text;
    if (!Validate::isNumber(amount)) {
        MessageBox::Show(L"Số tiền không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (currClientAccountNumber == "" ||
               currClientPaymentDay == DateTime()) {
        MessageBox::Show(L"Cố lỗi xảy ra", "Cảnh báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return;
    } else if (DateTime::Now.Date < DateTime(currClientPaymentDay).Date) {
        MessageBox::Show(L"Chưa đến ngày thanh toán định kì", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Tạo yêu cầu thanh toán định kỳ
    RecurringPaymentRequest ^ request = gcnew RecurringPaymentRequest(
        currClientAccountNumber, GlobalData::GetCurrentUser()->AccountNumber,
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
            if (requests[i]->UserAccountNumber == request->UserAccountNumber &&
                requests[i]->CompanyAccountNumber ==
                    request->CompanyAccountNumber) {
                MessageBox::Show(L"Yêu cầu thanh toán đã tồn tại", "Cảnh báo",
                                 MessageBoxButtons::OK,
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
        if (recurringPayments[i]->UserAccountNumber ==
                currClientAccountNumber &&
            recurringPayments[i]->CompanyAccountNumber ==
                GlobalData::GetCurrentUser()->AccountNumber) {
            recurringPayments[i]->Debt = Convert::ToDouble(amount);
            break;
        }
    }
    bool isChangedRecurring = HandleFile::WriteRecurringPaymentsArray(
        recurringPayments, "recurringPayments.dat");
    if (isChangedRecurring) {
        MessageBox::Show(L"Yêu cầu thanh toán đã được gửi", "Thông báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
        this->panelForm->Visible = false;
        this->loadRecurringPaymentData();
    } else {
        MessageBox::Show(L"Lỗi khi cập nhật số tiền nợ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}

} // namespace BankingAppwinform
