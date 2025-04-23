#include "EditUserForm.h"
#include"GradientHelper.h"
namespace BankingAppwinform {

EditUserForm::EditUserForm(User ^ userSelected) {
    InitializeComponent();
    this->userSelected = userSelected;
    this->loadUserInfo();
    GradientColorHelper::ApplyGradient(this);
}

EditUserForm::~EditUserForm() {
    if (components) {
        delete components;
    }
}

System::Void EditUserForm::btnUndo_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    TableUsersForm ^ tableUsersForm = gcnew TableUsersForm();
    AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
    if (adminForm != nullptr) {
        adminForm->LoadForm(tableUsersForm);
    }
}

void EditUserForm::loadUserInfo() {
    User ^ user = this->userSelected;
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
    try {
        System::Windows::Forms::DialogResult result;
        result = MessageBox::Show(L"Bạn có chắc chắn muốn lưu lại thay đổi không ?",
                                  L"Lưu thay đổi", MessageBoxButtons::YesNo,
                                  MessageBoxIcon::Question);
        if (result == System::Windows::Forms::DialogResult::No) {
            return;
        }
        if (this->amount->Text == "") {
            throw gcnew Exception(L"Vui lòng nhập số dư");
        } else if (!Validate::isNumber(this->amount->Text)) {
            throw gcnew Exception(L"Số dư không hợp lệ");
        }
        this->userSelected->setBalance(Convert::ToDouble(this->amount->Text));
        UserService::UpdateUserByAccNumber(this->userSelected->getAccountNumber(),
                                            this->userSelected);
        MessageBox::Show(L"Cập nhật thông tin thành công", L"Thông báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);

        TableUsersForm ^ tableUsersForm = gcnew TableUsersForm();
        AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
        if (adminForm != nullptr) {
            adminForm->LoadForm(tableUsersForm);
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}


} // namespace BankingAppwinform