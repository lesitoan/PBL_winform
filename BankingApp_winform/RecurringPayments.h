#ifndef RECURRINGPAYMENTS_H
#define RECURRINGPAYMENTS_H

using namespace System;

public
ref class RecurringPayments {
  private:
    int id;
    int userAccountNumber;
    int companyId;
    int amount;
    String ^ frequency;  // month: 1,2,3,4,5....12
    DateTime paymentDay; // 1-31
    int status;         // "complete", "pending"

  public:
    RecurringPayments(int id, int userAccountNumber, int companyId, int amount,
                      String ^ frequency, DateTime paymentDay, int status) {
        this->id = id;
        this->userAccountNumber = userAccountNumber;
        this->companyId = companyId;
        this->amount = amount;
        this->frequency = frequency;
        this->paymentDay = paymentDay;
        this->status = status;
    }
    RecurringPayments() {
        id = 0;
        userAccountNumber = 0;
        companyId = 0;
        amount = 0;
        frequency = "";
        status = 0;
    }
    property int Id {
        int get() { return id; }
    }
    property int UserAccountNumber {
        int get() { return userAccountNumber; }
        void set(int value) { userAccountNumber = value; }
    }
    property int CompanyId {
        int get() { return companyId; }
        void set(int value) { companyId = value; }
    }
    property int Amount {
        int get() { return amount; }
        void set(int value) { amount = value; }
    }
    property String ^ Frequency {
        String ^ get() { return frequency; } 
        void set(String ^ value) { frequency = value; }
    } property DateTime PaymentDay {
        DateTime get() { return paymentDay; }
        void set(DateTime value) { paymentDay = value; }
    }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }

};

#endif // RECURRINGPAYMENTS_H
