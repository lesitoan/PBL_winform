#pragma once
using namespace System;

public
ref class Transaction {
  private:
    String ^ transactionId;
    String ^ fromAccountNumber;
    String ^ toAccountNumber;
    double amount;
    String ^ message;
    String ^ createdAt;

  public:
    Transaction(String ^ _transactionId, String ^ _fromAccountNumber,
                String ^ _toAccountNumber, double _amount, String ^ _message,
                String ^ _createdAt) {
        transactionId = _transactionId;
        fromAccountNumber = _fromAccountNumber;
        toAccountNumber = _toAccountNumber;
        amount = _amount;
        message = _message;
        createdAt = _createdAt;
    }

    Transaction() : Transaction("", "", "", 0, "", "") {};

    Transaction(const Transaction % other) {
        transactionId = other.transactionId;
        fromAccountNumber = other.fromAccountNumber;
        toAccountNumber = other.toAccountNumber;
        amount = other.amount;
        message = other.message;
        createdAt = other.createdAt;
    }
    String ^ getTransactionId() { return transactionId; }
    String ^
        getFromAccount() { return fromAccountNumber; }
    String ^
        getToAccount() { return toAccountNumber; }
    String ^ getMessage() { return message; }
    String ^ getCreatedAt() { return createdAt; } double getAmount() {
        return amount;
    }
};