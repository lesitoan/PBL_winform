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

void AdminTransactionForm::loadTransactions(array<Transaction ^> ^
                                            transactions) {
    try {
        dataGridViewTransactions->Rows->Clear();

        if (transactions == nullptr || transactions->Length == 0) {
            transactions = TransactionsRepository::GetAll();
        }

        if (transactions == nullptr) {
            return;
        }
        for (int i = 0; i < transactions->Length; i++) {
            Transaction ^ transaction = transactions[i];
            String ^ type =
                transaction->getFromAccount() == "" ? L"Rút tiền" : L"Chuyển tiền";
            dataGridViewTransactions->Rows->Add(
                type, transaction->getFromAccount(), transaction->getToAccount(),
                transaction->getAmount(), transaction->getMessage(),
                transaction->getCreatedAt());
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void AdminTransactionForm::btnFind_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    try {

        array<Transaction ^> ^ transactions = TransactionServices::FindTransactionByAccNum(this->findText->Text);

        this->findText->Text = "";
        loadTransactions(transactions);

    } catch (Exception ^ ex) {
        dataGridViewTransactions->Rows->Clear();
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

}; // namespace BankingAppwinform
