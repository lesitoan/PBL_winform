#pragma once
#include "User.h"
#include "HandleFile.h"
#include "Transaction.h"
#include "GlobalData.h"

ref class Utils {
  public:
    static bool transferMoney(int currUserAccNumber, int receiverAccNumber,
                              double amount, int pin);
};
