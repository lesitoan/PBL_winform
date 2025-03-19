#pragma once
#include "User.h"
#include "Transaction.h"
#include "Services.h"
#include "PaymentCodes.h"
#include "RecurringPayments.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;




ref class HandleFile {
  public:
    static bool WriteUserArray(array<User ^> ^ users, String ^ filePath);
    static array<User ^> ^ ReadUserArray(String ^ filePath);

    static bool WriteTransactionArray(array<Transaction ^> ^ transactions,
                                      String ^ filePath);
    static array<Transaction ^> ^ ReadTransactionArray(String ^ filePath);

    static bool WriteServicesArray(array<Services ^> ^ services,
                                      String ^ filePath);
    static array<Services ^> ^ ReadServicesArray(String ^ filePath);

    static bool WriteCodeArray(array<PaymentCodes ^> ^ codes,
                                   String ^ filePath);
    static array<PaymentCodes ^> ^ ReadCodeArray(String ^ filePath);

    static bool WriteRecurringPaymentsArray(array<RecurringPayments ^> ^
                                                recurringPayments,
                               String ^ filePath);
    static array<RecurringPayments ^> ^
        ReadRecurringPaymentsArray(String ^ filePath);

};