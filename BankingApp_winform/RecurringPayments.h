#ifndef RECURRINGPAYMENTS_H
#define RECURRINGPAYMENTS_H

using namespace System;

public
ref class RecurringPayments {
  private:
    int id;
    int userAccountNumber;
    int companyId;
    int monthly;         //1,2,3,4,5....12
    DateTime paymentDay; // 1-31
    double debt;            // "complete", "pending"

  public:
    RecurringPayments(int id, int userAccountNumber, int companyId, int monthly,
                      DateTime paymentDay, double debt) {
        this->id = id;
        this->userAccountNumber = userAccountNumber;
        this->companyId = companyId;
        this->monthly = monthly;
        this->paymentDay = paymentDay;
        this->debt = debt;
    }
    RecurringPayments() {
        id = 0;
        userAccountNumber = 0;
        companyId = 0;
        monthly = 1;
        debt = 0;
    }

    RecurringPayments(int userAccountNumber, int companyId, int monthly) : id(11), userAccountNumber(userAccountNumber), companyId(companyId), monthly(monthly), paymentDay(DateTime::Now), debt(0) {}


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
