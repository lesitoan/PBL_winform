#include "TableUsersForm.h"
#pragma once
#include "AdminForm.h"
#include "EditUserForm.h"

namespace BankingAppwinform {

TableUsersForm::TableUsersForm(void) {
    InitializeComponent();
    //
    // TODO: Add the constructor code here
    //
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
    for (int i = 1; i <= 30; i++) {
        System::String ^ name = "User" + i;
        System::String ^ phone = "09" + i.ToString("00000000");
        int balance = 100000 + (i * 5000);
        int accountNumber = 100000 + i;
        System::String ^ status = (i % 2 == 0) ? "active" : "inactive";
        System::String ^ bank = (i % 3 == 0)   ? "Vietcombank"
                                : (i % 3 == 1) ? "BIDV"
                                               : "Techcombank";

        dataGridViewUsers->Rows->Add(name, phone, balance, accountNumber,
                                     status, bank);
    }
}

System::Void TableUsersForm::btnModify_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    EditUserForm ^ editUserForm = gcnew EditUserForm();
    AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
    if (adminForm != nullptr) {
        adminForm->LoadForm2(editUserForm);
    }
}
}; // namespace BankingAppwinform
