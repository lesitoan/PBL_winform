#pragma once
using namespace System;

public
ref class SelectReceiverEventArgs : public EventArgs {
  public:
    String ^ BankName;
    String ^ AccountName;
    int AccountNumber;
    double Amount;

    SelectReceiverEventArgs( String^ bankName ,String ^ accName, int accNumber, double amount) {
        BankName = bankName;
        AccountName = accName;
        AccountNumber = accNumber;
        Amount = amount;
    }
};
