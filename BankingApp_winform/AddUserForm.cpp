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

    array<Services ^> ^ services = ServicesRepository::GetAll();

    for each (Services ^ service in services) {
        selectServiceBox->Items->Add(service);
    }
    selectServiceBox->DisplayMember = "Name";
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

System::Void AddUserForm::btnSubmit_Click(System::Object ^ sender,
                                          System::EventArgs ^ e) {
    try {
        String ^ name = this->name->Text;
        String ^ phone = this->phone->Text;
        String ^ accNum = this->accNum->Text;
        String ^ password = this->password->Text;
        String ^ accType = this->selectAccTypeBox->Text;

        String ^ serviceId = "";
        Services ^ selectedService = dynamic_cast<Services ^>(selectServiceBox->SelectedItem);
        if (selectedService != nullptr) {
            serviceId = selectedService->Id;
        }

        if (name == "" || phone == "" || accNum == "" || password == "" ||
            accType == "") {
            MessageBox::Show(L"Vui lòng nhập đầy đủ thông tin", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        } else if (accType == "company" && serviceId == "") {
            MessageBox::Show(L"Chưa chọn dịch vụ", "Error", MessageBoxButtons::OK,
                             MessageBoxIcon::Error);
            return;
        }

        User ^ currentUser = UserRepository::FindUserByPhoneNumber(phone);
        if (currentUser != nullptr) {
            MessageBox::Show(L"Số điện thoại đã tồn tại", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        } else if (currentUser->AccountNumber == accNum) {
            MessageBox::Show(L"Số tài khoản đã tồn tại", "Error",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        double _balance = 0;
        int _pin = 0;
        String ^ _bankName = "BIDV";
        int _status = 1;

        User ^ user =
            gcnew User(name, password, phone, accNum, _balance,
                       accType, _pin, _bankName, _status, serviceId, "BankingApp_winform\\images\\avatars\\default_avatar.png");

        UserRepository::InsertUser(user);

        MessageBox::Show(L"Tạo tài khoản thành công !", "Success",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);

        createUserSuccess(this, EventArgs::Empty);
        this->Close();

    } catch (Exception ^ ex) {
        MessageBox::Show(L"Tạo tài khoản thất bại, thử lại sau", "Error", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    };
}

}; // namespace BankingAppwinform
