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

void AdminForm::LoadForm2(Form ^ childForm) {
    panelContent->Controls->Clear(); // Xóa form con trước đó
    childForm->TopLevel = false;
    childForm->Dock = DockStyle::Fill;
    panelContent->Controls->Add(childForm);
    childForm->Show();
}

System::Void AdminForm::btnClient_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    LoadChildForm::LoadForm(panelContent, gcnew TableUsersForm());
}

System::Void AdminForm::btnTransaction_Click(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    LoadChildForm::LoadForm(panelContent, gcnew AdminTransactionForm());
}

System::Void AdminForm::btnService_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    LoadChildForm::LoadForm(panelContent, gcnew AdminServiceForm());
}
}; // namespace BankingAppwinform
