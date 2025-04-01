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
        array<PaymentCodes ^> ^ codes = createListCode(this->codes);
        array<PaymentCodes ^> ^ oldCodes =
            HandleFile::ReadCodeArray("codes.dat");
        bool isSaveCode = false;
        if (oldCodes == nullptr || oldCodes->Length == 0) {
            isSaveCode = HandleFile::WriteCodeArray(codes, "codes.dat");
        } else {
            List<PaymentCodes ^> ^ newCodes = gcnew List<PaymentCodes ^>();
            for each (PaymentCodes ^ code in oldCodes) {
                newCodes->Add(code);
            }
            for each (PaymentCodes ^ code in codes) {
                newCodes->Add(code);
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

            array<String ^> ^ lines =
                textBox->Text->Split(gcnew array<wchar_t>{'\n'},
                                     StringSplitOptions::RemoveEmptyEntries);

            for each (String ^ line in lines) {
                array<String ^> ^ parts =
                    line->Split(gcnew array<wchar_t>{','},
                                StringSplitOptions::RemoveEmptyEntries);

                if (parts->Length != 3) {
                    continue;
                }

                String ^ code = parts[0]->Trim();
                int price = Int32::Parse(parts[1]->Trim());
                int day = Int32::Parse(parts[2]->Trim());

                // validate code, price, day

                //

                String^ companyAccNumber =
                    GlobalData::GetCurrentUser()->getAccountNumber();

                PaymentCodes ^ item =
                    gcnew PaymentCodes(companyAccNumber, code, price, day);
                items->Add(item);
            }

            return items->ToArray();
        }

        void CodeForm::loadTableCodes() {
        array<PaymentCodes ^> ^ codes = HandleFile::ReadCodeArray("codes.dat");
        if (codes == nullptr || codes->Length == 0) {
            return;
        }
        dataGridViewUsers->Rows->Clear();
        for each (PaymentCodes ^ code in codes) {
            if (code->CompanyAccountNumber !=
                GlobalData::GetCurrentUser()->getAccountNumber()) {
                continue;
            }
            String ^ status =
                code->Status ? L"Đã thanh toán" : L"Chưa thanh toán";
            dataGridViewUsers->Rows->Add(code->Code, code->Amount, status);
        }
    }
};
