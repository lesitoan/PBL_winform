#include "AdminTransactionForm.h"

namespace BankingAppwinform {

AdminTransactionForm::AdminTransactionForm(void) {
    InitializeComponent();
    loadTransactions(nullptr);
}

AdminTransactionForm::~AdminTransactionForm() {
    if (components) {
        delete components;
    }
}

System::Void
AdminTransactionForm::AdminTransactionForm_Load(System::Object ^ sender,
                                                System::EventArgs ^ e) {
}

void AdminTransactionForm::loadTransactions(array<TransactionDTO ^> ^
                                            data) {
    try {
        dataGridViewTransactions->Rows->Clear();

        if (data == nullptr) {
            data = TransactionServices::GetAllTransactionData();
        }

        if (data == nullptr) {
            return;
        }
        for (int i = 0; i < data->Length; i++) {
            TransactionDTO ^ transaction = data[i];
            String ^ fromUserName = L"...";
            String ^ toUserName = L"...";
            if (transaction->FromUser != nullptr) {
                fromUserName = transaction->FromUser->FullName;
            }
            if (transaction->ToUser != nullptr) {
                toUserName = transaction->ToUser->FullName;
            }
            
            String ^ type = "";
            if (transaction->ThisTransaction->Type == "transfer") {
                type = L"Chuyển khoản";
            } else if (transaction->ThisTransaction->Type == "withdraw") {
                type = L"Rút tiền";
            } else if (transaction->ThisTransaction->Type == "deposit") {
                type = L"Nạp tiền";
            } else if (transaction->ThisTransaction->Type == "saving") {
                type = L"Gửi tiết kiệm";
            } else if (transaction->ThisTransaction->Type == "savingWithdraw") {
                type = L"Rút tiết kiệm";
            } else if (transaction->ThisTransaction->Type == "savingTransfer") {
                type = L"Chuyển khoản tiết kiệm";
            }
            dataGridViewTransactions->Rows->Add(
                type, fromUserName, toUserName,
                transaction->ThisTransaction->Amount, transaction->ThisTransaction->Message,
                transaction->ThisTransaction->CreatedAt);
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void AdminTransactionForm::btnFind_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    try {

        array<TransactionDTO ^> ^ data = TransactionServices::FindTransactionByUserName(this->findText->Text);

        this->findText->Text = "";
        loadTransactions(data);

    } catch (Exception ^ ex) {
        dataGridViewTransactions->Rows->Clear();
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

}; // namespace BankingAppwinform
