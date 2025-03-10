#include "AdminForm.h"

#include "EditUserForm.h"
#include "LoadChildForm.h"
#include "TableUsersForm.h"

#include "AdminServiceForm.h"
#include "AdminTransactionForm.h"

namespace BankingAppwinform {

AdminForm::AdminForm(void) {
    InitializeComponent();
    //
    // TODO: Add the constructor code here
    //
}

AdminForm::~AdminForm() {
    if (components) {
        delete components;
    }
}

void AdminForm::LoadForm(Form ^ newForm) {
    // Nếu panelContent đang chứa Form nào thì lưu vào Stack trước khi thay thế
    if (panelContent->Controls->Count > 0) {
        Form ^ currentForm = dynamic_cast<Form ^>(panelContent->Controls[0]);
        if (currentForm != nullptr) {
            formHistory->Push(currentForm); // Lưu form hiện tại vào stack
        }
    }

    // Xóa nội dung cũ
    panelContent->Controls->Clear();

    // Đưa form mới vào panelContent
    newForm->TopLevel = false;
    newForm->Dock = DockStyle::Fill;
    panelContent->Controls->Add(newForm);
    newForm->Show();
}

void AdminForm::UndoLastForm() {
    if (formHistory->Count > 0) {
        Form ^ previousForm = formHistory->Pop();  // Lấy form trước đó
        panelContent->Controls->Clear();           // Xóa form hiện tại
        panelContent->Controls->Add(previousForm); // Load lại form trước đó
        previousForm->Show();
    }
}


System::Void AdminForm::btnClient_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    LoadChildForm::LoadForm(panelContent, gcnew TableUsersForm());
    formHistory->Clear();
    this->labelHeader->Text = L"DANH SÁCH KHÁCH HÀNG";
}

System::Void AdminForm::btnTransaction_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    LoadChildForm::LoadForm(panelContent, gcnew AdminTransactionForm());
    formHistory->Clear();
    this->labelHeader->Text = L"LỊCH SỬ GIAO DỊCH";
}

System::Void AdminForm::btnService_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    LoadChildForm::LoadForm(panelContent, gcnew AdminServiceForm());
    formHistory->Clear();
    this->labelHeader->Text = L"DỊCH VỤ";
}
};
