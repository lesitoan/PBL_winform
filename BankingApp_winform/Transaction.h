#include "ISaveToFile.h"

#pragma once
using namespace System;

public
ref class Transaction : public ISaveToFile {
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
    Transaction(String ^ _transactionId, String ^ _fromAccountNumber,
                String ^ _toAccountNumber, double _amount, String ^ _message) {
        transactionId = _transactionId;
        fromAccountNumber = _fromAccountNumber;
        toAccountNumber = _toAccountNumber;
        amount = _amount;
        message = _message;
        createdAt = DateTime::Now.ToString("dd/MM/yyyy");
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
    String ^ getTransactionId() { return transactionId; } String ^
        getFromAccount() { return fromAccountNumber; } String ^
        getToAccount() { return toAccountNumber; } String ^
        getMessage() { return message; } String ^
        getCreatedAt() { return createdAt; } double getAmount() {
        return amount;
    }

    virtual void WriteTo(BinaryWriter ^ writer) {
        writer->Write(transactionId);
        writer->Write(fromAccountNumber);
        writer->Write(toAccountNumber);
        writer->Write(amount);
        writer->Write(message);
        writer->Write(createdAt);
    }

    virtual void ReadFrom(BinaryReader ^ reader) {
        transactionId = reader->ReadString();
        fromAccountNumber = reader->ReadString();
        toAccountNumber = reader->ReadString();
        amount = reader->ReadDouble();
        message = reader->ReadString();
        createdAt = reader->ReadString();
    }
};