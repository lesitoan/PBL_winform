#include "TableUsersForm.h"


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

void TableUsersForm::loadUsers(array<User ^> ^ usersArr) {
    try {
        dataGridViewUsers->Rows->Clear();

        if (usersArr == nullptr) {
            usersArr = UserService::GetAllUsers();
            this->users = usersArr;
        }
        if (usersArr == nullptr) {
            return;
        }
        for (int i = 0; i < usersArr->Length; i++) {

            if (usersArr[i]->getRole() == Role::Admin) {
                continue;
            }
            String ^ status = usersArr[i]->Status == 1 ? L"Hoạt động" : L"Khóa";
            dataGridViewUsers->Rows->Add(
                usersArr[i]->getFullName(), usersArr[i]->getPhoneNumber(),
                usersArr[i]->getBalance(),

                usersArr[i]->getAccountNumber(), usersArr[i]->getRole().ToString(),
                usersArr[i]->getBankName().ToString(), status);
            int lastRow = dataGridViewUsers->Rows->Count - 1;
            dataGridViewUsers->Rows[lastRow]->Tag = usersArr[i];
        }

        this->dataGridViewUsers->CellClick += gcnew DataGridViewCellEventHandler(
            this, &TableUsersForm::handleUserRowClick);    
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->ToString(), L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
        return;
    }
}


System::Void TableUsersForm::handleUserRowClick(
    System::Object ^ sender,
                   System::Windows::Forms::DataGridViewCellEventArgs ^ e) {
    if (e->RowIndex < 0) {
        return;
    }
    DataGridViewRow ^ row = dataGridViewUsers->Rows[e->RowIndex];
    this->userSelected = dynamic_cast<User ^>(row->Tag);

    if (userSelected->Status) {
        btnLock->Text = L"KHÓA";
        btnLock->BackColor = System::Drawing::Color::Red;
    } else {
        btnLock->Text = L"MỞ KHÓA";
        btnLock->BackColor = System::Drawing::Color::Green;
    }
}

System::Void TableUsersForm::btnLock_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    System::Windows::Forms::DialogResult result;
    if (this->userSelected == nullptr) {
        MessageBox::Show(L"Vui lòng chọn một tài khoản", L"Thông báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    result = MessageBox::Show(L"Bạn có chắc chắn muốn lưu lại thay đổi không ?",
                              L"Lưu thay đổi", MessageBoxButtons::YesNo,
                              MessageBoxIcon::Question);
    if (result == System::Windows::Forms::DialogResult::No) {
        return;
    }

    if (users == nullptr) {
        return;
    }
    int status = userSelected->Status == 1 ? 0 : 1;

    UserService::UpdateStatus(userSelected->getAccountNumber(), status);

    MessageBox::Show(L"Thay đổi đã được lưu lại", L"Thành công",
                     MessageBoxButtons::OK, MessageBoxIcon::Information);
    loadUsers(nullptr);
}

void TableUsersForm::btnFind_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
    try {
        String ^ find = this->findText->Text;
        if (find == "")
            this->loadUsers(nullptr);

        array<User ^> ^ matchedUsers = UserService::FilterUserMatchName(find);
        loadUsers(matchedUsers);

        this->findText->Text = "";
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->ToString(), L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
        return;
    }
}

System::Void TableUsersForm::btnAddUser_Click(System::Object ^ sender,
                                              System::EventArgs ^ e) {
    AddUserForm ^ addUserForm = gcnew AddUserForm();
    addUserForm->createUserSuccess +=
        gcnew EventHandler(this, &TableUsersForm::onCreateUserSuccess);
    addUserForm->ShowDialog();
}

System::Void TableUsersForm::onCreateUserSuccess(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    loadUsers(nullptr);
}

}; // namespace BankingAppwinform
