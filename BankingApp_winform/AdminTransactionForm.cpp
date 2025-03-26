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
                                                System::EventArgs ^ e) {}

void AdminTransactionForm::loadTransactions(array<Transaction ^> ^
                                            transactions) {
    dataGridViewTransactions->Rows->Clear();

    if (transactions == nullptr || transactions->Length == 0) {
        transactions = HandleFile::ReadTransactionArray("transactions.dat");
    }

    if (transactions == nullptr) {
        return;
    }
    for (int i = 0; i < transactions->Length; i++) {
        Transaction ^ transaction = transactions[i];
        String ^ type =
            transaction->getFromAccount() == 0 ? L"Rút tiền" : L"Chuyển tiền";
        dataGridViewTransactions->Rows->Add(
            type, transaction->getFromAccount(), transaction->getToAccount(),
            transaction->getAmount(), transaction->getMessage(),
            transaction->getCreatedAt());
    }
}

void AdminTransactionForm::btnFind_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {

    array<Transaction ^> ^ transactions =
        HandleFile::ReadTransactionArray("transactions.dat");

    String ^ find = this->findText->Text;
    if (find == "") {
        loadTransactions(transactions);
        this->findText->Text = "";
        return;
    }

    List<Transaction ^> ^ matchedTransactions = gcnew List<Transaction ^>();

    for (int i = 0; i < transactions->Length; i++) {
        // Chuyển input thành regex pattern
        String ^ pattern = ".*" + Regex::Escape(find) + ".*";
        // Kiểm tra tên có chứa input không (không phân biệt hoa thường)
        bool isMatch1 =
            Regex::IsMatch(transactions[i]->getFromAccount().ToString(),
                           pattern, RegexOptions::IgnoreCase);
        bool isMatch2 =
            Regex::IsMatch(transactions[i]->getToAccount().ToString(), pattern,
                           RegexOptions::IgnoreCase);

        if (isMatch1 || isMatch2) {
            matchedTransactions->Add(transactions[i]);
        }
    }
    this->findText->Text = "";
    loadTransactions(matchedTransactions->ToArray());
}
}; // namespace BankingAppwinform
