#pragma once

using namespace System;

public
ref class ENV {
  public:
    static String ^ DEFAULT_AVATAR_PATH = "BankingApp_winform\\images\\avatars\\default_avatar.png";

    static String ^ CUSTOMER_CODE_DETAIL_FILE = "customerCodeDetails.dat";
    static String ^ CUSTOMER_CODE_FILE = "customerCodes.dat";
    static String ^ USER_FILE = "users.dat";
    static String ^ TRANSACTION_FILE = "transactions.dat";
    static String ^ SERVICE_FILE = "services.dat";
    static String ^ NOTIFICATION_FILE = "notifications.dat";
    static String ^ RECURRING_PAYMENT_FILE = "recurringpayments.dat";
    static String ^ SAVING_CUSTOMER_FILE = "savingcurrent.dat";
    static String ^ HISTORY_FILE = "history.dat";


};