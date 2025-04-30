#pragma once
#include "User.h"
using namespace System;

public
ref class SelectReceiverEventArgs : public EventArgs {
  public:
    Bank BankName;
    String ^ AccountName;
    String^ AccountNumber;
    double Amount;

    SelectReceiverEventArgs( Bank bankName ,String ^ accName, String^ accNumber, double amount) {
        BankName = bankName;
        AccountName = accName;
        AccountNumber = accNumber;
        Amount = amount;
    }
};
