#include "RegisterSavingForm.h"
#include"GradientHelper.h"
namespace BankingAppwinform {
RegisterSavingForm::RegisterSavingForm(String ^ type) {

    this->type = type;

    InitializeComponent();

    this->labelBalance->Text = L"Số dư khả dụng: " +
                               GlobalData::GetCurrentUser()->getBalance() +
                               L" VND";
    if (type == "termDeposit") {
        header->Text = L"GỬI TIẾT KIỆM CÓ KÌ HẠN";
        labelInfo->Text = L"Gửi tiết kiệm có kì hạn với lãi xuất (3T 4.5%/năm, "
                          L"6T 5%/năm, 9T 5.5%/năm, 12T 6%/năm) "
                          L"bạn có thể rút tiền sau khi hết kì hạn";
    } else {
        header->Text = L"GỬI TIẾT KIỆM KHÔNG KÌ HẠN";
        labelInfo->Text = L"Gửi tiết kiệm không kì hạn với lãi xuất 4% / năm, "
                          L"bạn có thể rút tiền bất cứ khi nào";
        label5->Text = L"Chọn kì hạn:";
        selectTermBox->Items->Clear();
        selectTermBox->Items->Add(L"Không kì hạn");
        selectTermBox->SelectedIndex = 0;
        selectTermBox->Enabled = false;
    }
    GradientColorHelper::ApplyGradient(this);
    GradientColorHelper::ApplyRoundedCorners(this->panel1,8);
}

RegisterSavingForm::~RegisterSavingForm() {
    if (components) {
        delete components;
    }
}

System::Void RegisterSavingForm::header_Click(System::Object ^ sender,
                                              System::EventArgs ^ e) {}

System::Void RegisterSavingForm::btnClose_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {
    this->Close();
}

System::Void RegisterSavingForm::btnSubmit_Click(System::Object ^ sender,
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
    SavingCustomers ^ savingCustomer = gcnew SavingCustomers(
        id, accountNumber, Convert::ToDouble(amount), this->type, term);

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

    HandleFile::WriteArrayToFile<SavingCustomers^>(savingCustomers,
                                                  "savingCustomerssss.dat");

    bool isSaved = HandleFile::WriteSavingCustomersArray(savingCustomers,
                                                         "savingCustomers.dat");
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

} // namespace BankingAppwinform