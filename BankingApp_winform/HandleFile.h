#pragma once
#include "CustomerCodes.h"
#include "CustomerCodeDetails.h"
#include "RecurringPayments.h"
#include "Services.h"
#include "Transaction.h"
#include "User.h"
#include "Notifications.h"
#include "SavingCustomers.h"

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

    static bool WriteCustomerCodesArray(array<CustomerCodes ^> ^ codes,
                               String ^ filePath);
    static array<CustomerCodes ^> ^ ReadCustomerCodesArray(String ^ filePath);

    static bool WriteRecurringPaymentsArray(array<RecurringPayments ^> ^
                                                recurringPayments,
                                            String ^ filePath);
    static array<RecurringPayments ^> ^ ReadRecurringPaymentsArray(String ^ filePath);

    static bool WriteCustomerCodeDetailsArray(array<CustomerCodeDetails ^> ^
                                                  customerCodeDetails,
                                                  String ^ filePath);

    static array<CustomerCodeDetails ^> ^
        ReadCustomerCodeDetailsArray(String ^ filePath);

    static bool WriteNotificationsArray(array<Notifications ^> ^ notifications,
                                        String ^ filePath);

    static array<Notifications ^> ^ ReadNotificationsArray(String ^ filePath);

    static bool WriteSavingCustomersArray(array<SavingCustomers ^> ^ savingCustomers,
                                        String ^ filePath);

    static array<SavingCustomers ^> ^
        ReadSavingCustomersArray(String ^ filePath);

};