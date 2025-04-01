#pragma once
#ifndef RECURRINGPAYMENTREQUEST_H
#define RECURRINGPAYMENTREQUEST_H

using namespace System;

ref class RecurringPaymentRequest {
  private:
    String ^ id;         
    String ^ userAccountNumber;    
    String ^ companyAccountNumber; 
    double amount;            
    DateTime requestDate;     
    String ^ status;       // pending, success  

    public:
    RecurringPaymentRequest(String ^ reqId, String ^ userAcc,
                            String ^ companyAcc,
                            double amt,
                            DateTime date, String ^ stat) {
        id = reqId;
        userAccountNumber = userAcc;
        companyAccountNumber = companyAcc;
        amount = amt;
        requestDate = date;
        status = stat;
    }

    RecurringPaymentRequest(String ^ userAcc, String ^ companyAcc, double amt) {
        id = "";
        userAccountNumber = userAcc;
        companyAccountNumber = companyAcc;
        amount = amt;
        requestDate = DateTime::Now;
        status = "pending";
    }

    RecurringPaymentRequest() {
        id = "";
        userAccountNumber = "";
        companyAccountNumber = "";
        amount = 0;
        requestDate = DateTime::Now;
        status = "pending";
    }

    property String ^ Id { String ^ get() { return id; }
    } property String ^
        UserAccountNumber {
            String ^ get() { return userAccountNumber; }
    } property String ^
        CompanyAccountNumber {
            String ^ get() { return companyAccountNumber; }
    }
    property double Amount {
        double get() { return amount; }
    }
    property DateTime RequestDate {
        DateTime get() { return requestDate; }
    }
    property String ^ Status {
        String ^ get() { return status; } void set(String ^ value) {
            status = value;
        }
    }
};

#endif
