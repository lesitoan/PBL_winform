#include "EditUserForm.h"

namespace BankingAppwinform {

System::Void EditUserForm::btnUndo_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    TableUsersForm ^ tableUsersForm = gcnew TableUsersForm();
    AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
    if (adminForm != nullptr) {
        adminForm->LoadForm(tableUsersForm);
    }
}

void EditUserForm::loadUserInfo(User ^ user) {
    this->name->Text = user->getFullName();
    this->phone->Text = user->getPhoneNumber();
    this->accNum->Text = user->getAccountNumber();
    this->acctype->Text = user->getRole();
    this->bankName->Text = user->getBankName();
    this->status->Text = user->Status == 1 ? L"Hoạt động" : L"Khóa";
    this->amount->Text = user->getBalance().ToString();
}

System::Void EditUserForm::btnSubmit_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    System::Windows::Forms::DialogResult result;
    result = MessageBox::Show(L"Bạn có chắc chắn muốn lưu lại thay đổi không ?",
                              L"Lưu thay đổi", MessageBoxButtons::YesNo,
                              MessageBoxIcon::Question);
    if (result == System::Windows::Forms::DialogResult::No) {
        return;
    }

    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    if (users == nullptr) {
        return;
    }
    bool isModyfied = false;
    for (int i = 0; i < users->Length; i++) {
        if (users[i]->getAccountNumber() == this->accNum->Text) {

            if (this->amount->Text != "" &&
                Validate::isNumber(this->amount->Text)) {
                int _amount = Double::Parse(this->amount->Text);
                if (_amount == users[i]->getBalance()) {
                    return;
                }
                users[i]->setBalance(_amount);
                isModyfied = true;
            }
            break;
        }
    }
    if (isModyfied) {
        HandleFile::WriteUserArray(users, "users.dat");
        MessageBox::Show(L"Thay đổi đã được lưu lại", L"Thành công",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
    } else {
        MessageBox::Show(L"Không thể thay đổi số dư", L"Lỗi",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
} // namespace BankingAppwinform