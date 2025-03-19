#ifndef RECURRINGPAYMENTS_H
#define RECURRINGPAYMENTS_H

using namespace System;

public
ref class RecurringPayments {
  private:
    int id;
    int userAccountNumber;
    int companyAccountNumber;
    int monthly;         //1,2,3,4,5....12
    DateTime paymentDay; // 1-31
    double debt;            // "complete", "pending"

  public:
    RecurringPayments(int id, int userAccountNumber, int companyAccountNumber,
                      int monthly,
                      DateTime paymentDay, double debt) {
        this->id = id;
        this->userAccountNumber = userAccountNumber;
        this->companyAccountNumber = companyAccountNumber;
        this->monthly = monthly;
        this->paymentDay = paymentDay;
        this->debt = debt;

    }
    RecurringPayments() {
        id = 0;
        userAccountNumber = 0;
        companyAccountNumber = 0;
        monthly = 1;
        debt = 0;
    }

    RecurringPayments(int userAccountNumber, int companyAccountNumber,
                      int monthly)
        : id(11), userAccountNumber(userAccountNumber),
          companyAccountNumber(companyAccountNumber), monthly(monthly),
          paymentDay(DateTime::Now.AddMonths(1)), debt(0) {}


    property int Id {
        int get() { return id; }
    }
    property int UserAccountNumber {
        int get() { return userAccountNumber; }
        void set(int value) { userAccountNumber = value; }
    }
    property int CompanyAccountNumber {
        int get() { return companyAccountNumber; }
        void set(int value) { companyAccountNumber = value; }
    }
    property int Monthly {
        int get() { return monthly; } 
        void set(int value) { monthly = value; }
    } property DateTime PaymentDay {
        DateTime get() { return paymentDay; }
        void set(DateTime value) { paymentDay = value; }
    }
    property double Debt {
        double get() { return debt; }
        void set(double value) { debt = value; }
    }

};

#endif // RECURRINGPAYMENTS_H
