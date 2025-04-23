#include "ModifyServiceForm.h"
#include"GradientHelper.h"

namespace BankingAppwinform {

ModifyServiceForm::ModifyServiceForm(String ^ type) {
    InitializeComponent();
    GradientColorHelper::ApplyGradient(this);
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
    try {
        selectServiceBox->Items->Clear();
        array<Services ^> ^ services = ServiceServices::GetAllServices();
        if (services == nullptr) {
            return;
        }
        for (int i = 0; i < services->Length; i++) {
            selectServiceBox->Items->Add(gcnew KeyValuePair < String ^, Services ^ > (services[i]->Name, services[i]));
        }
        selectServiceBox->DisplayMember = "Key";
        selectServiceBox->ValueMember = "Value";

    } catch (Exception ^ ex) {
        MessageBox::Show(L"Tải dữ liệu dịch vụ lỗi, thử lại sau.", L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

System::Void ModifyServiceForm::btnSubmit_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {
    try {
        // handle insert
        if (this->type == "insert") {
            ServiceServices::InsertService(serviceName->Text);
            MessageBox::Show(L"Thêm dịch vụ thành công");


        } else if (type == "delete") {
            System::Windows::Forms::DialogResult result;
            result = MessageBox::Show(L"Bạn có chắc chắn muốn xóa dịch vụ này?",
                                      L"Xóa", MessageBoxButtons::YesNo,
                                      MessageBoxIcon::Question);
            if (result == System::Windows::Forms::DialogResult::No) 
                return;

            KeyValuePair<String ^, Services ^> ^ selectedItem =
                dynamic_cast<KeyValuePair<String ^, Services ^> ^>(selectServiceBox->SelectedItem);

            if (selectedItem == nullptr) {
                return;
            }
            String ^ id = selectedItem->Value->Id;
            ServiceServices::DeleteServiceById(id);
        }

        ModifyServiceSuccess(this, EventArgs::Empty);
        this->Close();
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

} // namespace BankingAppwinform
