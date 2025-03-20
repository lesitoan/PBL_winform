#include "TableUsersForm.h"
#pragma once
#include "AdminForm.h"
#include "EditUserForm.h"

namespace BankingAppwinform {

TableUsersForm::TableUsersForm(void) {
    InitializeComponent();
    this->loadUsers(nullptr);
}

TableUsersForm::~TableUsersForm() {
    if (components) {
        delete components;
    }
}

System::Void TableUsersForm::dataGridView1_CellContentClick(
    System::Object ^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {}

System::Void TableUsersForm::AdminClientForm_Load(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
}

System::Void TableUsersForm::btnModify_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    if (this->userSelected == nullptr) {
        MessageBox::Show(L"Vui lòng chọn người dùng cần sửa !", "Tiêu đề",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    EditUserForm ^ editUserForm = gcnew EditUserForm(userSelected);
    AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
    if (adminForm != nullptr) {
        adminForm->LoadForm(editUserForm);
    }
}
}; // namespace BankingAppwinform
