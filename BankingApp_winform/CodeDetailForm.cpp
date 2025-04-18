#include "CodeDetailForm.h"

namespace BankingAppwinform {

CodeDetailForm::CodeDetailForm(CustomerCodes ^ customerCode) {
    InitializeComponent();
    this->customerCode = customerCode;
    loadCodeDetails();
}

CodeDetailForm::~CodeDetailForm() {
    if (components) {
        delete components;
    }
}


void CodeDetailForm::loadCodeDetails() {
    this->leftContent->Controls->Clear();

    if (this->customerCode == nullptr) {
        return;
    }

    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");
    if (codeDetails == nullptr || codeDetails->Length == 0) {
        return;
    }

    for (int i = 0; i < codeDetails->Length; i++) {
        if (codeDetails[i]->CustomerCodeId != this->customerCode->Id) {
            continue;
        }

        Panel ^ panel = createCodeDetailPanel(codeDetails[i]);
        this->leftContent->Controls->Add(panel);
    }

    this->leftContent->PerformLayout();
}

Panel ^ CodeDetailForm::createCodeDetailPanel(CustomerCodeDetails ^ detail) {
    Panel ^ panel = gcnew Panel();
    panel->BackColor = Color::FromArgb(0, 64, 64);
    panel->Padding = System::Windows::Forms::Padding(10);
    panel->Margin = System::Windows::Forms::Padding(5);
    panel->Width = leftContent->ClientSize.Width - 15;

    int yOffset = 10;
    int lineHeight = 20;

    addLabelToPanel(panel, yOffset, L"Mã hóa đơn: " + detail->Id);
    addLabelToPanel(panel, yOffset,
                    L"Mã khách hàng: " + this->customerCode->Code);
    addLabelToPanel(panel, yOffset,
                    L"Số tiền: " + detail->Amount.ToString("N0") + " vnd");
    addLabelToPanel(panel, yOffset,
                    L"Ngày tạo: " +
                        detail->CreateDate.ToString("dd/MM/yyyy hh:mm:ss tt"));
    addLabelToPanel(panel, yOffset,
                    L"Ngày hết hạn: " +
                        detail->ExpiredDate.ToString("dd/MM/yyyy hh:mm:ss tt"));
    addLabelToPanel(panel, yOffset,
                    L"Trạng thái: " + (detail->Status == 1
                                           ? L"đã thanh toán"
                                           : L"chưa thanh toán"));
    addLabelToPanel(panel, yOffset,
                    L"Tài khoản thanh toán: " +
                        detail->PaymentUserAccountNumber);
    addLabelToPanel(panel, yOffset, L"Ngày thanh toán: " + detail->PaymentDate);

    // Nút "Xóa hóa đơn"
    if (detail->Status == 0) {
        Button ^ btnDelete = gcnew Button();
        btnDelete->Text = L"Xóa hóa đơn";
        btnDelete->BackColor = Color::DarkRed;
        btnDelete->ForeColor = Color::White;
        btnDelete->Font =
            gcnew System::Drawing::Font("Arial", 9, FontStyle::Bold);
        btnDelete->Location = Point(10, yOffset);
        btnDelete->AutoSize = true;
        btnDelete->Tag = detail->Id; // Gán dữ liệu Id vào Tag
        btnDelete->Click +=
            gcnew EventHandler(this, &CodeDetailForm::deleteCodeDetail_Click);
        panel->Controls->Add(btnDelete);
        yOffset += 30;
    }

    panel->Height = yOffset + 10;
    return panel;
}


void CodeDetailForm::addLabelToPanel(Panel ^ panel, int % yOffset,
                                     String ^ text) {
    Label ^ label = gcnew Label();
    label->Text = text;
    label->Font = gcnew System::Drawing::Font("Arial", 10);
    label->ForeColor = Color::White;
    label->Location = Point(10, yOffset);
    label->AutoSize = true;
    panel->Controls->Add(label);
    yOffset += 20; // chiều cao mỗi dòng
}


void CodeDetailForm::deleteCodeDetail_Click(Object ^ sender, EventArgs ^ e) {
    Button ^ btn = dynamic_cast<Button ^>(sender);
    if (btn == nullptr)
        return;

    String ^ idToDelete = dynamic_cast<String ^>(btn->Tag);
    if (String::IsNullOrEmpty(idToDelete))
        return;

    // Đọc danh sách cũ
    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");

    // Lọc lại danh sách (xóa cái có ID trùng)
    List<CustomerCodeDetails ^> ^ newList = gcnew List<CustomerCodeDetails ^>();
    for each (CustomerCodeDetails ^ detail in codeDetails) {
        if (detail->Id != idToDelete) {
            newList->Add(detail);
        }
    }

    // Ghi lại file
    HandleFile::WriteCustomerCodeDetailsArray(newList->ToArray(),
                                              "customerCodeDetails.dat");

    // Refresh giao diện
    this->loadCodeDetails(); // gọi lại để cập nhật UI
}




System::Void CodeDetailForm::btnSubmit_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    if (this->amount->Text == "" || this->days->Text == "") {
        MessageBox::Show(L"Vui lòng nhập số tiền và thời gian", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    double amount = Convert::ToDouble(this->amount->Text);
    int days = Convert::ToInt32(this->days->Text);
    if (amount <= 0 || days <= 0) {
        MessageBox::Show(L"Số tiền hoặc thời gian không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    if (this->customerCode == nullptr) {
        return;
    }

    // mỗi mã khách hàng trong 1 tháng chỉ được tạo 1 hóa đơn
    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");
    if (codeDetails != nullptr) {
        for (int i = 0; i < codeDetails->Length; i++) {
            /*if (codeDetails[i]->CustomerCodeId == this->customerCode->Id &&
                codeDetails[i]->CreateDate.Month == DateTime::Now.Month) {
                MessageBox::Show(L"Mỗi mã khách hàng chỉ được tạo 1 hóa đơn mỗi tháng",
                                 L"Cảnh báo", MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
                return;
            } else if (codeDetails[i]->CustomerCodeId ==
                           this->customerCode->Id &&
                       codeDetails[i]->Status == 0) {
                MessageBox::Show(L"Mã khách hàng đã có hóa đơn chưa thanh toán",
                                 L"Cảnh báo", MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
            }*/

            if (codeDetails[i]->CustomerCodeId == this->customerCode->Id &&
                codeDetails[i]->Status == 0) {
                MessageBox::Show(L"Mã khách hàng đã có hóa đơn chưa thanh toán",
                                 L"Cảnh báo", MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
            }
        }
    }

    // tạo hóa đơn mới
    String ^ codeDetailId = Utils::createUniqueID("CCD");
    DateTime expiredDate = DateTime::Now.AddDays(days);
    CustomerCodeDetails ^ codeDetail = gcnew CustomerCodeDetails(
        codeDetailId, this->customerCode->Id, amount, expiredDate);

    
    if (codeDetails == nullptr) {
        codeDetails = gcnew array<CustomerCodeDetails ^>(1);
        codeDetails[0] = codeDetail;
    } else {
        array<CustomerCodeDetails ^> ^ newCodeDetails =
            gcnew array<CustomerCodeDetails ^>(codeDetails->Length + 1);
        for (int i = 0; i < codeDetails->Length; i++) {
            newCodeDetails[i] = codeDetails[i];
        }
        newCodeDetails[codeDetails->Length] = codeDetail;
        codeDetails = newCodeDetails;
    }
    bool isSaveCodeDetail = HandleFile::WriteCustomerCodeDetailsArray(
        codeDetails, "customerCodeDetails.dat");
    if (isSaveCodeDetail) {
        MessageBox::Show(L"Thêm hóa đơn thành công");

        // thanh toán định kì cho hóa đơn đó nếu có
        array<RecurringPayments ^> ^ recurringPayments =
            HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
        if (recurringPayments != nullptr) {
            for (int i = 0; i < recurringPayments->Length; i++) {

                if (recurringPayments[i]->CustomerCodeId ==this->customerCode->Id) {
                    payRecurringPayment(codeDetail, recurringPayments[i]);
                    break;
                }
            }
        } 
        //---------

        this->loadCodeDetails();
        this->amount->Text = "";
    } else {
        MessageBox::Show(L"Thêm hóa đơn thất bại");
    }
}



    // thanh toán định kì cho hóa đơn đó nếu có
void CodeDetailForm::payRecurringPayment(CustomerCodeDetails ^ request,
                                         RecurringPayments ^recurringPayment) {
    User ^ user = nullptr;
    User ^ company = nullptr;

    // update file users và transactions
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    int pin = 0;

    for (int i = 0; i < users->Length; i++) {
        if (users[i]->AccountNumber == this->customerCode->CompanyAccountNumber) {
            company = users[i];
        } else if (users[i]->AccountNumber ==
                   recurringPayment->UserAccountNumber) {
            pin = users[i]->getPin();
            user = users[i];
        }
    }

    // nếu số dư client không đủ thì gửi thông báo
    if (user->getBalance() < request->Amount) {
        String ^ id = Utils::createUniqueID("CB");
        Notifications ^ notification = gcnew Notifications(
            id, recurringPayment->UserAccountNumber,
            L"Thanh toán định kì tại công ty " + company->FullName + " (" +
                request->Amount + ") " + L" chưa hoàn thành, " +
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
        HandleFile::WriteNotificationsArray(notifications, "notifications.dat");
        MessageBox::Show(
            L"Số dư không đủ để thanh toán định kì từ tài khoản: " +
            user->FullName + "\n"
            L"Đã gửi thông báo đến khách hàng");
        return;
    }

    bool isTransfer = Utils::transferMoney(user->AccountNumber, company->AccountNumber,
                                           request->Amount, pin);
    if (!isTransfer) {
        return;
    }

    // update file codeDetails
    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");
    for (int i = 0; i < codeDetails->Length; i++) {
        if (codeDetails[i]->Id == request->Id) {
            codeDetails[i]->Status = 1;
            codeDetails[i]->PaymentUserAccountNumber =
                recurringPayment->UserAccountNumber;
            codeDetails[i]->PaymentDate = DateTime::Now.ToString("dd/MM/yyyy");
            break;
        }
    }
    HandleFile::WriteCustomerCodeDetailsArray(codeDetails,
                                              "customerCodeDetails.dat");
    MessageBox::Show(L"hóa đơn này đã được thanh toán từ người dùng: " + user->FullName);
    
}

} // namespace BankingAppwinform
