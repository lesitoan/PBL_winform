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

    array<PaymentCodes ^> ^ codes = createListCode(this->codes);
    if (codes == nullptr) {
        return;
    }
    array<PaymentCodes ^> ^ oldCodes = HandleFile::ReadCodeArray("codes.dat");
    bool isSaveCode = false;
    if (oldCodes == nullptr || oldCodes->Length == 0) {
        isSaveCode = HandleFile::WriteCodeArray(codes, "codes.dat");
    } else {
        List<PaymentCodes ^> ^ newCodes = gcnew List<PaymentCodes ^>();
        // Thêm tất cả mã cũ vào danh sách mới
        for each (PaymentCodes ^ code in oldCodes) {
            newCodes->Add(code);
        }

        // Thêm mã mới nếu chưa tồn tại
        for each (PaymentCodes ^ newCode in codes) {
            bool isExist = false;

            for each (PaymentCodes ^ oldCode in oldCodes) {
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
        isSaveCode =
            HandleFile::WriteCodeArray(newCodes->ToArray(), "codes.dat");
    }
    if (isSaveCode) {
        MessageBox::Show("Thêm code thành công");
        loadTableCodes();
    } else {
        MessageBox::Show("Thêm code thất bại");
    }
}

array<PaymentCodes ^> ^ CodeForm::createListCode(TextBox ^ textBox) {
    List<PaymentCodes ^> ^ items = gcnew List<PaymentCodes ^>();

    array<String ^> ^ lines = textBox->Text->Split(
        gcnew array<wchar_t>{'\n'}, StringSplitOptions::RemoveEmptyEntries);
    if (lines->Length == 0) {
        MessageBox::Show(L"Vui lòng nhập mã thanh toán", L"Cảnh báo",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return nullptr;
    }

    for each (String ^ line in lines) {
        array<String ^> ^ parts = line->Split(
            gcnew array<wchar_t>{','}, StringSplitOptions::RemoveEmptyEntries);

        if (parts->Length != 3) {
            MessageBox::Show(L"Vui lòng nhập đúng định dạng: CODE,PRICE,DAY",
                             L"Cảnh báo", MessageBoxButtons::OK,
                             MessageBoxIcon::Warning);
            continue;
        }

        String ^ code = parts[0]->Trim();
        int price = Int32::Parse(parts[1]->Trim());
        int day = Int32::Parse(parts[2]->Trim());


        // validate code, price, day
        if (code->Length < 5 || price <= 0 || day <= 0) {
            MessageBox::Show(L"Mã code: " + code + L" phải lớn hơn 5 kí tự");
            continue;
        } else if (code->Length > 10) {
            MessageBox::Show(L"Mã code: " + code + L" không được quá 10 ký tự");
            continue;
        } else if (price > 100000000) { // 1 tram triệu
            MessageBox::Show(L"Mã code: " + code + L"Số tiền không được lớn hơn 100 triệu");
            continue;
        } 
        //

        String ^ companyAccNumber =
            GlobalData::GetCurrentUser()->getAccountNumber();

        PaymentCodes ^ item =
            gcnew PaymentCodes(companyAccNumber, code, price, day);
        items->Add(item);
    }

    if (items->Count == 0) {
        return nullptr;
    }

    return items->ToArray();
}

void CodeForm::loadTableCodes() {
    array<PaymentCodes ^> ^ codes = HandleFile::ReadCodeArray("codes.dat");
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
            codes[i]->Status ? L"Đã thanh toán" : L"Chưa thanh toán";
        dataGridViewCodes->Rows->Add(codes[i]->Code, codes[i]->Amount, status);

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
        PaymentCodes ^ selectedCode = dynamic_cast<PaymentCodes ^>(row->Tag);

        if (selectedCode == nullptr) {
            MessageBox::Show(L"Lỗi: Không thể lấy dữ liệu mã thanh toán.");
        }
        Form ^ codeInfoForm = gcnew CodeInfoForm(selectedCode);
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

    PaymentCodes ^ selectedCode = nullptr;
    for (int i = 0; i < this->dataGridViewCodes->SelectedRows->Count; i++) {
        DataGridViewRow ^ row = this->dataGridViewCodes->SelectedRows[i];
        selectedCode = dynamic_cast<PaymentCodes ^>(row->Tag);
        break;
    }
    if (selectedCode->Status == 1) {
        MessageBox::Show(L"Mã thanh toán đã được thanh toán, không thể xóa",
                         L"Cảnh báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return;
    }

    System::Windows::Forms::DialogResult choise = MessageBox::Show(
        L"Bạn có chắc chắn muốn xóa mã thanh toán này?", L"Cảnh báo",
        MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

    if (choise == System::Windows::Forms::DialogResult::No) {
        return;
    }
    array<PaymentCodes ^> ^ codes = HandleFile::ReadCodeArray("codes.dat");
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
    array<PaymentCodes ^> ^ newCodes =
        gcnew array<PaymentCodes ^>(codes->Length - 1);
    // Sao chép các phần tử từ mảng cũ sang mảng mới
    for (int i = 0; i < newCodes->Length; i++) {
        newCodes[i] = codes[i];
    }

    // Ghi lại mã đã xóa vào file
    bool isSaveCode =
        HandleFile::WriteCodeArray(newCodes, "codes.dat");
    if (isSaveCode) {
        MessageBox::Show("Xóa mã thanh toán thành công");
        loadTableCodes();
    } else {
        MessageBox::Show("Xóa mã thanh toán thất bại");
    }
}
}
