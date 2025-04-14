#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include "CompanyBillingForm.h"
#include "AdminForm.h"

namespace BankingAppwinform {

CompanyBillingForm::CompanyBillingForm(String^ companyAccNumber) {
    InitializeComponent();
    this->companyAccountNumber = companyAccNumber;

    LoadPaymentCodes();
    LoadRecurringPaymentRequest();
}

CompanyBillingForm::~CompanyBillingForm() {
    if (components) {
        delete components;
    }
}

System::Void CompanyBillingForm::btnAccount_Click(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
    AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
    if (adminForm != nullptr) {
        adminForm->UndoLastForm();
    }
}

void CompanyBillingForm::LoadPaymentCodes() {
    /*
    dataGridViewCodes->Rows->Clear();

    array<PaymentCodes ^> ^ paymentCodes =
        HandleFile::ReadCodeArray("codes.dat");
    if (paymentCodes == nullptr || paymentCodes->Length == 0)
        return;

    for each (PaymentCodes ^ code in paymentCodes) {
        if (code->CompanyAccountNumber != this->companyAccountNumber)
            continue;

        dataGridViewCodes->Rows->Add(
            code->CompanyAccountNumber, code->Code,
            code->Amount.ToString(
                "N0"), // Hiển thị số có dấu phân cách (VD: 10,000)
            code->Status == 0 ? L"Chưa thanh toán" : L"Đã thanh toán",
            code->CreatedDate.ToString("dd/MM/yyyy"),
            code->ExpiredDate.ToString("dd/MM/yyyy"));
    }
    */
}

void CompanyBillingForm::LoadRecurringPaymentRequest() {

    /*
    dataGridViewRecurring->Rows->Clear(); // Xóa dữ liệu cũ nếu có

    array<RecurringPaymentRequest ^> ^ recurringPaymentRequests =
        HandleFile::ReadRecurringPaymentRequestArray(
            "recurringPaymentRequests.dat");
    if (recurringPaymentRequests == nullptr ||
        recurringPaymentRequests->Length == 0)
        return;

    if (dataGridViewRecurring->Columns["btnPay"] == nullptr) {
        DataGridViewButtonColumn ^ btnColumn = gcnew DataGridViewButtonColumn();
        btnColumn->HeaderText = L"Hành động";
        btnColumn->Text = L"Thanh toán";
        btnColumn->UseColumnTextForButtonValue = true;
        btnColumn->Name = "btnPay";
        // Thiết lập màu sắc cho nút
        btnColumn->DefaultCellStyle->BackColor = System::Drawing::Color::Green;
        btnColumn->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
        FlatStyle::Flat;

        this->dataGridViewRecurring->Columns->Add(btnColumn);
    }

    for (int i = 0; i < recurringPaymentRequests->Length; i++) {
        if (recurringPaymentRequests[i]->CompanyAccountNumber !=
            this->companyAccountNumber)
            continue;
        String ^ status = recurringPaymentRequests[i]->Status == "pending"
                              ? L"Chưa thanh toán"
                              : L"Đã thanh toán";
        dataGridViewRecurring->Rows->Add(
            recurringPaymentRequests[i]->UserAccountNumber,
            recurringPaymentRequests[i]->CompanyAccountNumber,
            recurringPaymentRequests[i]->Amount, status);

        dataGridViewRecurring->Rows[i]->Tag = recurringPaymentRequests[i];

        if (recurringPaymentRequests[i]->Status == "pending") {
            dataGridViewRecurring->Rows[i]->Cells["btnPay"]->Value =
                "Thanh toán";
        } else {
            dataGridViewRecurring->Rows[i]->Cells["btnPay"]->Value = "";
        }
    }
    this->dataGridViewRecurring->CellClick +=
        gcnew DataGridViewCellEventHandler(
            this, &CompanyBillingForm::dataGridViewRecurring_CellClick);

            */
}

System::Void CompanyBillingForm::dataGridViewRecurring_CellClick(
    System::Object ^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {

    /*

    if (e->RowIndex >= 0 &&
        dataGridViewRecurring->Columns[e->ColumnIndex]->Name == "btnPay") {
        RecurringPaymentRequest ^ request =
            (RecurringPaymentRequest ^) dataGridViewRecurring->Rows[e->RowIndex]
                ->Tag;

        if (request->Status == "success") {
            return;
        }

        User ^ user = nullptr;
        User ^ company = nullptr;

        // update file users và transactions
        array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
        int pin = 0;

        for (int i = 0; i < users->Length; i++) {
            if (company != nullptr && user != nullptr) {
                break;
            }

            if (users[i]->AccountNumber == request->CompanyAccountNumber) {
                company = users[i];
            }else if (users[i]->AccountNumber == request->UserAccountNumber) {
                pin = users[i]->getPin();
                user = users[i];
            }
        }
        
        // nếu số dư client không đủ thì gửi thông báo
        if (user->getBalance() < request->Amount) {
            String ^ id = Utils::createUniqueID("CB");
            Notifications ^ notification = gcnew Notifications(
                id, request->UserAccountNumber,
                L"Thanh toán định kì tại công ty " + company->FullName + " (" +
                    request->Amount + ") " +
                    L" chưa hoàn thành, " +
                L"hãy nộp thêm tiền vào tài khoản để tiến hành giao dịch",
                DateTime::Now.ToString("HH:mm:ss dd/MM/yyyy"), 0);

            array<Notifications ^> ^ notifications =
                HandleFile::ReadNotificationsArray("notifications.dat");
            if (notifications == nullptr) {
                notifications = gcnew array<Notifications ^>(0);
            } else {
                Array::Resize(notifications, notifications->Length + 1);
            }
            for (int i = notifications->Length - 1; i > 0; i--) {
                notifications[i] = notifications[i - 1];
            }
            notifications[0] = notification;
            HandleFile::WriteNotificationsArray(notifications,
                                                "notifications.dat");
            MessageBox::Show(L"Số dư không đủ để thanh toán, đã gửi thông báo cho khách hàng");
            return;
        }

 
        bool isTransfer = Utils::transferMoney(request->UserAccountNumber,
                                               request->CompanyAccountNumber,
                                               request->Amount, pin);
        if (!isTransfer) {
            return;
        }

        // update file recurringPaymentRequests
        array<RecurringPaymentRequest ^> ^ recurringPaymentRequests =
            HandleFile::ReadRecurringPaymentRequestArray(
                "recurringPaymentRequests.dat");
        for (int i = 0; i < recurringPaymentRequests->Length; i++) {
            if (recurringPaymentRequests[i]->UserAccountNumber ==
                    request->UserAccountNumber &&
                recurringPaymentRequests[i]->CompanyAccountNumber ==
                    request->CompanyAccountNumber) {
                for (int j = i; j < recurringPaymentRequests->Length - 1; j++) {
                    recurringPaymentRequests[j] =
                        recurringPaymentRequests[j + 1];
                }
                Array::Resize(recurringPaymentRequests,
                              recurringPaymentRequests->Length - 1);
                break;
            }
        }
        HandleFile::WriteRecurringPaymentRequestArray(
            recurringPaymentRequests, "recurringPaymentRequests.dat");

        // update file recurringPayments
        array<RecurringPayments ^> ^ recurringPayments =
            HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
        for (int i = 0; i < recurringPayments->Length; i++) {
            if (recurringPayments[i]->UserAccountNumber ==
                    request->UserAccountNumber &&
                recurringPayments[i]->CompanyAccountNumber ==
                    request->CompanyAccountNumber) {
                recurringPayments[i]->Debt = 0;
                recurringPayments[i]->PaymentDay =
                    recurringPayments[i]->PaymentDay.AddMonths(1);
                break;
            }
        }
        HandleFile::WriteRecurringPaymentsArray(recurringPayments,
                                                "recurringPayments.dat");

        // update ui
        MessageBox::Show(L"Thanh toán thành công cho tài khoản: " +
                         request->UserAccountNumber);
        LoadRecurringPaymentRequest();
    }
    */

}

System::Void CompanyBillingForm::btnShowCode_Click(System::Object ^ sender,
                                                   System::EventArgs ^ e) {

    /*
    if (dataGridViewCodes->Visible)
        return;
    dataGridViewCodes->Visible = true;
    dataGridViewRecurring->Visible = false;
    */
}
System::Void CompanyBillingForm::btnLoadRecurring_Click(System::Object ^ sender,
                                                        System::EventArgs ^ e) {
    /*
    if (dataGridViewRecurring->Visible)
        return;
    dataGridViewRecurring->Visible = true;
    dataGridViewCodes->Visible = false;
*/
}

}; // namespace BankingAppwinform


int getRandomNumber(int min, int max) {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    return min + std::rand() % ((max + 1) - min);
}
