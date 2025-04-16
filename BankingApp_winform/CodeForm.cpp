#include "CodeForm.h"

namespace BankingAppwinform {

CodeForm::CodeForm(void) {
    InitializeComponent();
    loadTableCodes();

}
CodeForm::~CodeForm() {
    if (components) {
        delete components;
    }
}

System::Void CodeForm::btnAddCode_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    
    //check pin
    if (this->pin->Text == "") {
        MessageBox::Show(L"Vui lòng nhập mã pin", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    } else if (!Validate::isPin(this->pin->Text)) {
        MessageBox::Show(L"Mã pin không hợp lệ", "Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    if (users == nullptr) {
        MessageBox::Show(L"Lỗi máy chủ, thử lại sau !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    for (int i = 0; i < users->Length; i++) {
        if (users[i]->getAccountNumber() ==
            GlobalData::GetCurrentUser()->AccountNumber) {
            if (users[i]->getPin() != Convert::ToInt32(this->pin->Text)) {
                MessageBox::Show(L"Ma pin khong hop le !", "Canh bao",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
                return;
            }
        }
    }

    array<CustomerCodes ^> ^ codes = createListCode(this->customerCodes);
    if (codes == nullptr) {
        return;
    }
    array<CustomerCodes ^> ^ oldCodes = HandleFile::ReadCustomerCodesArray("customerCodes.dat");
    bool isSaveCode = false;
    if (oldCodes == nullptr || oldCodes->Length == 0) {
        isSaveCode = HandleFile::WriteCustomerCodesArray(codes, "customerCodes.dat");
    } else {
        List<CustomerCodes ^> ^ newCodes = gcnew List<CustomerCodes ^>();
        // Thêm tất cả mã cũ vào danh sách mới
        for each (CustomerCodes ^ code in oldCodes) {
            newCodes->Add(code);
        }

        // Thêm mã mới nếu chưa tồn tại
        for each (CustomerCodes ^ newCode in codes) {
            bool isExist = false;

            for each (CustomerCodes ^ oldCode in oldCodes) {
                if (newCode->CompanyAccountNumber ==
                        oldCode->CompanyAccountNumber &&
                    newCode->Code == oldCode->Code) {
                    isExist = true;
                    break;
                }
            }

            if (!isExist) {
                newCodes->Add(newCode);
            }
        }
        isSaveCode = HandleFile::WriteCustomerCodesArray(newCodes->ToArray(),
                                                         "customerCodes.dat");
    }
    if (isSaveCode) {
        MessageBox::Show("Thêm code thành công");
        this->customerCodes->Text = "";
        this->pin->Text = "";
        loadTableCodes();
    } else {
        MessageBox::Show("Thêm code thất bại");
    }
}

array<CustomerCodes ^> ^ CodeForm::createListCode(TextBox ^ textBox) {

    List<CustomerCodes ^> ^ items = gcnew List<CustomerCodes ^>();

    array<String ^> ^ lines = textBox->Text->Split(
        gcnew array<wchar_t>{'\n'}, StringSplitOptions::RemoveEmptyEntries);
    if (lines->Length == 0) {
        MessageBox::Show(L"Vui lòng nhập mã thanh toán", L"Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return nullptr;
    }

    for (int i = 0; i < lines->Length; i++) {
        // validate code, price, day
        if (lines[i]->Length < 5 || lines[i]->Length > 10) {
            MessageBox::Show(L"Mã khách hàng: " + lines[i] +
                             L" phải lớn hơn 5 kí tự và nhỏ hơn 10 kí tự");
            continue;
        }
        //

        String ^ companyAccNumber =
            GlobalData::GetCurrentUser()->getAccountNumber();

        System::Random ^ rand = gcnew System::Random();
        String ^ id = Utils::createUniqueID("CC") + i;

        CustomerCodes ^ item =
            gcnew CustomerCodes(id, companyAccNumber, lines[i]);
        items->Add(item);
    }

    if (items->Count == 0) {
        return nullptr;
    }

    return items->ToArray();
}

void CodeForm::loadTableCodes() {

    array<CustomerCodes ^> ^ codes =
        HandleFile::ReadCustomerCodesArray("customerCodes.dat");
    if (codes == nullptr || codes->Length == 0) {
        return;
    }
    dataGridViewCodes->Rows->Clear();

    for (int i = 0; i < codes->Length; i++) {

        if (codes[i]->CompanyAccountNumber !=
            GlobalData::GetCurrentUser()->getAccountNumber()) {
            continue;
        }
        String ^ status =
            codes[i]->Status ? L"Hoạt động" : L"Khóa";
        dataGridViewCodes->Rows->Add(
            codes[i]->Code, codes[i]->CreatedDate.ToString("dd/MM/yyyy"),
            status);
        int lastRow = dataGridViewCodes->Rows->Count - 1;
        dataGridViewCodes->Rows[lastRow]->Tag = codes[i];
    }

    this->dataGridViewCodes->CellDoubleClick +=
        gcnew DataGridViewCellEventHandler(
            this, &CodeForm::dataGridViewCodes_CellDoubleClick);
}

void CodeForm::dataGridViewCodes_CellDoubleClick(Object ^ sender,
                                                 DataGridViewCellEventArgs ^
                                                     e) {
    if (e->RowIndex >= 0) {
        DataGridViewRow ^ row = dataGridViewCodes->Rows[e->RowIndex];
        CustomerCodes ^ selectedCode = dynamic_cast<CustomerCodes ^>(row->Tag);

        if (selectedCode == nullptr) {
            MessageBox::Show(L"Lỗi: Không thể lấy dữ liệu mã khách hàng");
        }
        Form ^ codeInfoForm = gcnew CodeDetailForm(selectedCode);
        codeInfoForm->ShowDialog();
    }
}

System::Void CodeForm::btnDeleteCode_Click(System::Object ^ sender,
                                           System::EventArgs ^ e) {
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
    //chỉ xóa khi chưa có hóa đơn và chưa ai đk thanh toán định kì
    array<RecurringPayments ^> ^ recurringPayments =
        HandleFile::ReadRecurringPaymentsArray("recurringPayments.dat");
    if (recurringPayments != nullptr) {
        for (int i = 0; i < recurringPayments->Length; i++) {
            if (recurringPayments[i]->CustomerCodeId == selectedCode->Code) {
                MessageBox::Show(
                    L"Không thể xóa mã thanh toán này vì đã"
                    L"có người đăng ký thanh toán định kỳ",
                    L"Cảnh báo", MessageBoxButtons::OK,
                    MessageBoxIcon::Warning);
                return;
            }
        }
    }

    array<CustomerCodeDetails ^> ^ codeDetails =
        HandleFile::ReadCustomerCodeDetailsArray("customerCodeDetails.dat");
    if (codeDetails != nullptr) {
        for (int i = 0; i < codeDetails->Length; i++) {
            if (codeDetails[i]->CustomerCodeId == selectedCode->Id) {
                MessageBox::Show(L"Không thể xóa mã thanh toán này vì đã"
                                 L"có hóa đơn liên quan",
                                 L"Cảnh báo", MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
                return;
            }
        }
    }



    System::Windows::Forms::DialogResult choise = MessageBox::Show(
        L"Bạn có chắc chắn muốn xóa mã thanh toán này?", L"Cảnh báo",
        MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

    if (choise == System::Windows::Forms::DialogResult::No) {
        return;
    }
    array<CustomerCodes ^> ^ codes =
        HandleFile::ReadCustomerCodesArray("customerCodes.dat");
    if (codes == nullptr || codes->Length == 0) {
        MessageBox::Show(L"Lỗi máy chủ, thử lại sau !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    
    for (int i = 0; i < codes->Length; i++) {
        if (codes[i]->Code == selectedCode->Code &&
            codes[i]->CompanyAccountNumber ==
                GlobalData::GetCurrentUser()->getAccountNumber()) {
            for (int j = i; j < codes->Length - 1; j++) {
                codes[j] = codes[j + 1];
            }
            break;
        }
    }
    // Tạo mảng mới với kích thước giảm đi 1
    array<CustomerCodes ^> ^ newCodes =
        gcnew array<CustomerCodes ^>(codes->Length - 1);
    // Sao chép các phần tử từ mảng cũ sang mảng mới
    for (int i = 0; i < newCodes->Length; i++) {
        newCodes[i] = codes[i];
    }

    // Ghi lại mã đã xóa vào file
    bool isSaveCode =
        HandleFile::WriteCustomerCodesArray(newCodes, "customerCodes.dat");
    if (isSaveCode) {
        MessageBox::Show("Xóa mã khách hàng thành công");
        loadTableCodes();
    } else {
        MessageBox::Show("Xóa mã  khách hàng thất bại");
    }
}


}
