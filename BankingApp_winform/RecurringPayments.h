#ifndef RECURRINGPAYMENTS_H
#define RECURRINGPAYMENTS_H

using namespace System;

public
ref class RecurringPayments {
  private:
    String^ id;
    String ^ userAccountNumber;
    String ^ customerCodeId;
    int monthly;         //1,2,3,4,5....12
    int paymentDay; // 1-31

  public:
    RecurringPayments(String ^ id, String ^ userAccountNumber,
                      String ^ customerCodeId,
                      int monthly, int paymentDay) {
        this->id = id;
        this->userAccountNumber = userAccountNumber;
        this->customerCodeId = customerCodeId;
        this->monthly = monthly;
        this->paymentDay = paymentDay;
    }
    RecurringPayments() {
        id = "";
        userAccountNumber = "";
        customerCodeId = "";
        monthly = 1;
        paymentDay = 1;
    }

    RecurringPayments(String ^ id, String ^ userAccountNumber,
                      String ^ customerCodeId, int monthly)
        : id(id), userAccountNumber(userAccountNumber),
          customerCodeId(customerCodeId), monthly(monthly),
          paymentDay(1){}


    property String ^ Id { String ^ get() { return id; }
    } property String ^
        UserAccountNumber {
            String ^ get() { return userAccountNumber; } void set(String ^ value) {
                userAccountNumber = value;
            }
    } property String ^
        CustomerCodeId {
            String ^ get() { return customerCodeId; } void set(String ^ value) {
                customerCodeId = value;
            }
    }
    property int Monthly {
        int get() { return monthly; } 
        void set(int value) { monthly = value; }
    }
    property int PaymentDay {
        int get() { return paymentDay; }
        void set(int value) { paymentDay = value; }
    }

};

#endif // RECURRINGPAYMENTS_H
