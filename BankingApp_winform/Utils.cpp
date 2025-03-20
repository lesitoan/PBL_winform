#include "Utils.h"

bool Utils::transferMoney(int currUserAccNumber, int receiverAccNumber, double amount,int pin) {
    //validate
    if (pin == 0) {
        MessageBox::Show(L"Khach hang chua dang ki ma pin !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return 0;
    } else if (currUserAccNumber == 0 || receiverAccNumber == 0) {
        MessageBox::Show(L"Chuyển khoản thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return 0;
    } else if (currUserAccNumber == receiverAccNumber) {
        MessageBox::Show(L"Chuyển khoản thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return 0;
    } else if (amount < 0) {
        MessageBox::Show(L"Số tiền chuyển khoản không hợp lệ", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return 0;
    }

    //
    array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
    if (users == nullptr) {
        MessageBox::Show(L"Lỗi máy chủ, thử lại sau !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return 0;
    }

    int receiverIndex = -1;
    int senderIndex = -1;
    for (int i = 0; i < users->Length; i++) {
        if (users[i]->getAccountNumber() == currUserAccNumber) {
            if (users[i]->getPin() != pin) {
                MessageBox::Show(L"Ma pin khong hop le !", "Canh bao",
                                 MessageBoxButtons::OK,
                                 MessageBoxIcon::Warning);
                return 0;
            }
            senderIndex = i;
        } else if (users[i]->getAccountNumber() == receiverAccNumber) {
            receiverIndex = i;
        }
    }
    if (senderIndex == -1 || receiverIndex == -1) {
        MessageBox::Show(L"Chuyển khoản thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return 0;
    } else if (users[senderIndex]->getBalance() < amount) {
        MessageBox::Show(L"So du khong du de thuc hien giao dich !", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return 0;
    }

    // chỉnh sửa thông tin
    users[senderIndex]->setBalance(users[senderIndex]->getBalance() - amount);
    users[receiverIndex]->setBalance(users[receiverIndex]->getBalance() + amount);

    // ghi lại file
    bool isSavedUser = HandleFile::WriteUserArray(users, "users.dat");
    if (!isSavedUser) {
        MessageBox::Show(L"Chuyển khoản thất bại", "Canh bao",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return 0;
    }

    // lưu lịch sử giao dịch
    String ^ message = "Chuyen khoan toi tai khoan " + receiverAccNumber; // sửa lại sau

    Transaction ^ transaction =
        gcnew Transaction(123, currUserAccNumber, receiverAccNumber, amount,
                          message,
                          DateTime::Now.ToString());
    array<Transaction ^> ^ transactions =
        HandleFile::ReadTransactionArray("transactions.dat");
    if (transactions == nullptr) {
        transactions = gcnew array<Transaction ^>(1);
        transactions[0] = transaction;
    } else {
        array<Transaction ^> ^ newTransactions =
            gcnew array<Transaction ^>(transactions->Length + 1);
        transactions->CopyTo(newTransactions, 0);
        newTransactions[transactions->Length] = transaction;
        transactions = newTransactions;
    }
    bool isSavedTransaction =
        HandleFile::WriteTransactionArray(transactions, "transactions.dat");

    // thông báo chuyển tiền thành công
    if (isSavedTransaction && isSavedUser) {
        GlobalData::SetCurrentUser(users[senderIndex]);
        return 1;
    } else {
        MessageBox::Show(L"Chuyển khoản thất bại", L"Lỗi",
                         MessageBoxButtons::OK, MessageBoxIcon::Error);
        return 0;
    }
}