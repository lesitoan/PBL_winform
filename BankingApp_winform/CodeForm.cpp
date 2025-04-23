#include "CodeForm.h"
#include "GradientHelper.h"
using namespace System::Text::RegularExpressions;

namespace BankingAppwinform {

CodeForm::CodeForm(void) {
    InitializeComponent();
    loadTableCodes();
    GradientColorHelper::ApplyGradient(this->panel1);
}
CodeForm::~CodeForm() {
    if (components) {
        delete components;
    }
}

System::Void CodeForm::btnAddCode_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {

    try {
        CustomerCodeServices::addCustomerCodes(this->customerCodes->Text, this->pin->Text);

        this->customerCodes->Text = "";
        this->pin->Text = "";
        loadTableCodes();

    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void CodeForm::loadTableCodes() {
    try {
        dataGridViewCodes->Rows->Clear();
        array<CustomerCodes ^> ^ codes = CustomerCodeServices::GetCustomerCodesByCompanyAccNum(GlobalData::GetCurrentUser()->getAccountNumber());
        if (codes == nullptr || codes->Length == 0) {
            return;
        }

        for (int i = 0; i < codes->Length; i++) {
            String ^ status = codes[i]->Status ? L"Hoạt động" : L"Khóa";
            dataGridViewCodes->Rows->Add(
                codes[i]->Code, codes[i]->CreatedDate.ToString("dd/MM/yyyy"),
                status);
            int lastRow = dataGridViewCodes->Rows->Count - 1;
            dataGridViewCodes->Rows[lastRow]->Tag = codes[i];
        }

        this->dataGridViewCodes->CellDoubleClick +=
            gcnew DataGridViewCellEventHandler(
                this, &CodeForm::dataGridViewCodes_CellDoubleClick);
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Tải dữ liệu mã khách hàng thất bại, thử lại sau.", L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void CodeForm::dataGridViewCodes_CellDoubleClick(Object ^ sender,
                                                 DataGridViewCellEventArgs ^
                                                     e) {
    if (e->RowIndex >= 0) {
        DataGridViewRow ^ row = dataGridViewCodes->Rows[e->RowIndex];
        CustomerCodes ^ selectedCode = dynamic_cast<CustomerCodes ^>(row->Tag);

        if (selectedCode == nullptr) {
            MessageBox::Show(L"Không thể lấy thông tin, thử lại sau.", L"Lỗi", MessageBoxButtons::OK,
                             MessageBoxIcon::Error);
        } else if (selectedCode->Status == 0) {
            MessageBox::Show(L"Mã khách hàng đã bị khóa, không thể xem thông tin.", L"Cảnh báo", MessageBoxButtons::OK,
                             MessageBoxIcon::Warning);
            return;
        }
        Form ^ codeInfoForm = gcnew CodeDetailForm(selectedCode);
        codeInfoForm->ShowDialog();
    }
}

System::Void CodeForm::btnDeleteCode_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    try {
        if (this->dataGridViewCodes->SelectedRows->Count == 0) {
            MessageBox::Show(L"Vui lòng chọn mã thanh toán để xóa", L"Cảnh báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        CustomerCodes ^ selectedCode = nullptr;
        for (int i = 0; i < this->dataGridViewCodes->SelectedRows->Count; i++) {
            DataGridViewRow ^ row = this->dataGridViewCodes->SelectedRows[i];
            selectedCode = dynamic_cast<CustomerCodes ^>(row->Tag);
            break;
        }

        System::Windows::Forms::DialogResult choise = MessageBox::Show(
            L"Bạn có chắc chắn muốn xóa mã thanh toán này?", L"Cảnh báo",
            MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

        if (choise == System::Windows::Forms::DialogResult::No) {
            return;
        }
        CustomerCodeServices::DeleteCustomerCode(selectedCode->Id);
        this->loadTableCodes();

    } catch (Exception ^ ex) {
        MessageBox::Show(L"Xóa thất bại.", L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

} // namespace BankingAppwinform
