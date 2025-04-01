#include "ModifyServiceForm.h"

namespace BankingAppwinform {

ModifyServiceForm::ModifyServiceForm(String ^ type) {
    InitializeComponent();
    this->type = type;
    if (type == "") {
        this->Close();
    } else if (type == "insert") {
        this->panelAdd->Visible = true;
        header->Text = L"THÊM DỊCH VỤ";
        btnSubmit->Text = "THÊM";
    } else if (type == "delete") {
        this->panelDelete->Visible = true;
        loadServiceBox();
        header->Text = L"XÓA DỊCH VỤ";
        btnSubmit->Text = "XÓA";
    }
}
ModifyServiceForm ::~ModifyServiceForm() {
    if (components) {
        delete components;
    }
}

System::Void ModifyServiceForm::btnClose_Click(System::Object ^ sender,
                                               System::EventArgs ^ e) {
    this->Close();
}

void ModifyServiceForm::loadServiceBox() {
    array<Services ^> ^ services =
        HandleFile::ReadServicesArray("services.dat");
    if (services == nullptr) {
        return;
    }
    for (int i = 0; i < services->Length; i++) {
        selectServiceBox->Items->Add(services[i]->Name);
    }
}

System::Void ModifyServiceForm::btnSubmit_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {

    array<Services ^> ^ services =
        HandleFile::ReadServicesArray("services.dat");

    // handle insert
    if (this->type == "insert") {
        String ^ name = serviceName->Text;
        if (name->Length == 0) {
            MessageBox::Show(L"Tên dịch vụ không được để trống");
            return;
        }

        // tạo id (fix lại sau)
        Random ^ rand = gcnew Random();
        String ^ id = Utils::createUniqueID("SER");
        //

        if (services == nullptr) {
            services = gcnew array<Services ^>(1);
            services[0] = gcnew Services(id, name);
        } else {
            // check dịch vụ đã tồn tại chưa
            for (int i = 0; i < services->Length; i++) {
                if (services[i]->Name == name) {
                    MessageBox::Show(L"Dịch vụ đã tồn tại");
                    return;
                }
            }
            array<Services ^> ^ newServices =
                gcnew array<Services ^>(services->Length + 1);
            for (int i = 0; i < services->Length; i++) {
                newServices[i] = services[i];
            }
            newServices[services->Length] = gcnew Services(id, name);
            services = newServices;
        }
        HandleFile::WriteServicesArray(services, "services.dat");
        MessageBox::Show(L"Thêm dịch vụ thành công");
    }

    // handle delete
    if (type == "delete") {
        System::Windows::Forms::DialogResult result;
        result = MessageBox::Show(L"Bạn có chắc chắn muốn xóa dịch vụ này?",
                                  L"Xóa", MessageBoxButtons::YesNo,
                                  MessageBoxIcon::Question);
        if (result == System::Windows::Forms::DialogResult::Yes) {
            for (int i = 0; i < services->Length; i++) {
                if (services[i]->Name == selectServiceBox->Text) {
                    // check dịch vụ có tồn tại công ty không, nếu có
                    // thì không được xóa
                    array<User ^> ^ users =
                        HandleFile::ReadUserArray("users.dat");
                    for (int j = 0; j < users->Length; j++) {
                        if (users[j]->getServiceId() == services[i]->Id) {
                            MessageBox::Show(L"Dịch vụ này đang được "
                                             L"sử dụng, không thể xóa");
                            return;
                        }
                    }

                    services[i] = services[services->Length - 1];
                    Array::Resize(services, services->Length - 1);
                    HandleFile::WriteServicesArray(services, "services.dat");
                    MessageBox::Show(L"Xóa dịch vụ thành công");
                    break;
                }
            }
        } else {
            return;
        }
    }

    ModifyServiceSuccess(this, EventArgs::Empty);
    this->Close();
}

} // namespace BankingAppwinform
