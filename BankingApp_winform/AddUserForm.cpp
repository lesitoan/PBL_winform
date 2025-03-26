#include "AddUserForm.h"

namespace BankingAppwinform {

AddUserForm::AddUserForm(void) { InitializeComponent(); }

AddUserForm::~AddUserForm() {
    if (components) {
        delete components;
    }
}

System::Void AddUserForm::btnClose_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    this->Close();
}

void AddUserForm::loadServiceBox() {
    selectServiceBox->Items->Clear();

    array<Services ^> ^ services =
        HandleFile::ReadServicesArray("services.dat");
    if (services == nullptr) {
        return;
    }
    for (int i = 0; i < services->Length; i++) {
        selectServiceBox->Items->Add(services[i]->Name);
    }
}

System::Void
AddUserForm::selectAccTypeBox_SelectedIndexChanged(System::Object ^ sender,
                                                   System::EventArgs ^ e) {
    if (selectAccTypeBox->Text == "company") {
        panelService->Visible = true;
        loadServiceBox();
    } else {
        panelService->Visible = false;
    }
}

bool AddUserForm::isUsedPhoneNumber(String ^ phoneNumber) {
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    for each (User ^ user in users) {
        if (user->getPhoneNumber() == phoneNumber) {
            return true;
        }
    }
    return false;
}

System::Void AddUserForm::btnSubmit_Click(System::Object ^ sender,
                                          System::EventArgs ^ e) {
    String ^ name = this->name->Text;
    String ^ phone = this->phone->Text;
    String ^ accNum = this->accNum->Text;
    String ^ password = this->password->Text;
    String ^ accType = this->selectAccTypeBox->Text;
    String ^ service = this->selectServiceBox->Text;

    if (name == "" || phone == "" || accNum == "" || password == "" ||
        accType == "") {
        MessageBox::Show(L"Vui lòng nhập đầy đủ thông tin", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    } else if (isUsedPhoneNumber(phone)) {
        MessageBox::Show(L"Số điện thoại đã được sử dụng", "Error",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    } else if (accType == "company" && service == "") {
        MessageBox::Show(L"Chưa chọn dịch vụ", "Error", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
        return;
    }

    int accNumber = Convert::ToInt32(accNum);
    int serviceId = 0;
    double _balance = 0;
    int _pin = 0;
    String ^ _bankName = "BIDV";
    int _status = 1;

    if (accType == "company") {
        array<Services ^> ^ services =
            HandleFile::ReadServicesArray("services.dat");
        if (services == nullptr) {
            return;
        }
        for (int i = 0; i < services->Length; i++) {
            if (services[i]->Name == service) {
                serviceId = services[i]->Id;
                break;
            }
        }
    }
    User ^ user = gcnew User(name, password, phone, accNumber, _balance,
                             accType, _pin, _bankName, _status, serviceId);
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    if (users == nullptr) {
        users = gcnew array<User ^>{user};
    } else {
        array<User ^> ^ newUsers = gcnew array<User ^>(users->Length + 1);
        for (int i = 0; i < users->Length; i++) {
            newUsers[i] = users[i];
        }
        newUsers[users->Length] = user;
        users = newUsers;
    }
    bool isSaved = HandleFile::WriteUserArray(users, "users.dat");
    if (isSaved) {
        MessageBox::Show(L"Tạo tài khoản thành công !", "Success",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);

        createUserSuccess(this, EventArgs::Empty);
        this->Close();
    }
};
}; // namespace BankingAppwinform
