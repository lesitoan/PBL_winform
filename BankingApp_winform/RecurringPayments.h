#ifndef RECURRINGPAYMENTS_H
#define RECURRINGPAYMENTS_H

using namespace System;

public
ref class RecurringPayments {
  private:
    String^ id;
    String ^ userAccountNumber;
    String ^ companyAccountNumber;
    int monthly;         //1,2,3,4,5....12
    DateTime paymentDay; // 1-31
    double debt;            // "complete", "pending"

  public:
    RecurringPayments(String ^ id, String ^ userAccountNumber,
                      String ^ companyAccountNumber,
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
        id = "";
        userAccountNumber = "";
        companyAccountNumber = "";
        monthly = 1;
        debt = 0;
    }

    RecurringPayments(String ^ id, String ^ userAccountNumber,
                      String ^ companyAccountNumber, int monthly)
        : id(id), userAccountNumber(userAccountNumber),
          companyAccountNumber(companyAccountNumber), monthly(monthly),
          paymentDay(DateTime::Now.AddMonths(-1)), debt(0) {}


    property String ^ Id { String ^ get() { return id; }
    } property String ^
        UserAccountNumber {
            String ^ get() { return userAccountNumber; } void set(String ^ value) {
                userAccountNumber = value;
            }
    } property String ^
        CompanyAccountNumber {
            String ^
                get() { return companyAccountNumber; } void set(String ^ value) {
                companyAccountNumber = value;
            }
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
