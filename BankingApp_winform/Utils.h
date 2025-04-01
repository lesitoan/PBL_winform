#pragma once
#include "User.h"
#include "HandleFile.h"
#include "Transaction.h"
#include "GlobalData.h"

ref class Utils {
  public:
    static bool transferMoney(String ^ currUserAccNumber,
                              String ^ receiverAccNumber,
                              double amount, int pin);
    static String ^ createUniqueID(String ^ subID);
};
