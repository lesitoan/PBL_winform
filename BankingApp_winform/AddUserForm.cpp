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
    try {

        selectServiceBox->Items->Clear();

        array<Services ^> ^ services = ServicesRepository::GetAll();

        for each (Services ^ service in services) {
            selectServiceBox->Items->Add(service);
        }
        selectServiceBox->DisplayMember = "Name";

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
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

        AuthServices::AddUser(name, phone, accNum, password, accType, serviceId);

        MessageBox::Show(L"Tạo tài khoản thành công !", "Success",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);

        createUserSuccess(this, EventArgs::Empty);
        this->Close();

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    };
}

}; // namespace BankingAppwinform
