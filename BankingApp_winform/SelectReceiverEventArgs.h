#pragma once
using namespace System;

public
ref class SelectReceiverEventArgs : public EventArgs {
  public:
    String ^ BankName;
    String ^ AccountName;
    String^ AccountNumber;
    double Amount;

    SelectReceiverEventArgs( String^ bankName ,String ^ accName, String^ accNumber, double amount) {
        BankName = bankName;
        AccountName = accName;
        AccountNumber = accNumber;
        Amount = amount;
    }
};
