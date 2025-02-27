#pragma once
using namespace System;

public
ref class Transaction {
  private:
    int transactionId;
    int fromAccountNumber;
    int toAccountNumber;
    double amount;
    String ^ createdAt;

  public:
    Transaction(int _transactionId, int _fromAccountNumber,
                int _toAccountNumber, double _amount, String ^ _createdAt) {
        transactionId = _transactionId;
        fromAccountNumber = _fromAccountNumber;
        toAccountNumber = _toAccountNumber;
        amount = _amount;
        createdAt = _createdAt;
    }

    Transaction() : Transaction(0, 0, 0, 0, "") {};

    int getTransactionId() { return transactionId; }
    int  getFromAccount() { return fromAccountNumber; }
    int getToAccount() { return toAccountNumber; }
    String ^ getCreatedAt() { return createdAt; }
    double getAmount() { return amount; }
};