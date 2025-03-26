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

void TableUsersForm::loadUsers(array<User ^> ^ usersArr) {
    dataGridViewUsers->Rows->Clear();

    if (usersArr == nullptr) {
        usersArr = HandleFile::ReadUserArray("users.dat");
        this->users = usersArr;
    }
    if (usersArr == nullptr) {
        return;
    }
    for (int i = 0; i < usersArr->Length; i++) {

        if (usersArr[i]->getRole() == "admin") {
            continue;
        }
        String ^ status = usersArr[i]->Status == 1 ? L"Hoạt động" : L"Khóa";
        dataGridViewUsers->Rows->Add(
            usersArr[i]->getFullName(), usersArr[i]->getPhoneNumber(),
            usersArr[i]->getBalance(),

            usersArr[i]->getAccountNumber(), usersArr[i]->getRole(),
            usersArr[i]->getBankName(), status);

        int lastRow = dataGridViewUsers->Rows->Count - 1;
        dataGridViewUsers->Rows[lastRow]->Tag = usersArr[i];
    }

    this->dataGridViewUsers->CellClick += gcnew DataGridViewCellEventHandler(
        this, &TableUsersForm::handleUserRowClick);
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
    if (userSelected == nullptr) {
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
    for (int i = 0; i < users->Length; i++) {
        if (users[i]->getAccountNumber() == userSelected->getAccountNumber()) {
            users[i]->Status = 1 - users[i]->Status;
            break;
        }
    }
    HandleFile::WriteUserArray(users, "users.dat");
    MessageBox::Show(L"Thay đổi đã được lưu lại", L"Thành công",
                     MessageBoxButtons::OK, MessageBoxIcon::Information);
    loadUsers(nullptr);
}

void TableUsersForm::btnFind_Click(System::Object ^ sender,
                                   System::EventArgs ^ e) {
    String ^ find = this->findText->Text;
    if (find == "")
        users = HandleFile::ReadUserArray("users.dat");

    List<User ^> ^ matchedUsers = gcnew List<User ^>();

    for (int i = 0; i < users->Length; i++) {
        // Chuyển input thành regex pattern
        String ^ pattern = ".*" + Regex::Escape(find) + ".*";
        // Kiểm tra tên có chứa input không (không phân biệt hoa thường)
        bool isMatch = Regex::IsMatch(users[i]->getFullName(), pattern,
                                      RegexOptions::IgnoreCase);
        if (isMatch) {
            matchedUsers->Add(users[i]);
        }
    }
    this->findText->Text = "";
    loadUsers(matchedUsers->ToArray());
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
