#pragma once
#ifndef RECURRINGPAYMENTREQUEST_H
#define RECURRINGPAYMENTREQUEST_H

using namespace System;

ref class RecurringPaymentRequest {
  private:
    int id;         
    int userAccountNumber;    
    int companyAccountNumber; 
    double amount;            
    DateTime requestDate;     
    String ^ status;       // pending, success  

    public:
    RecurringPaymentRequest(int reqId, int userAcc, int companyAcc, double amt,
                            DateTime date, String ^ stat) {
        id = reqId;
        userAccountNumber = userAcc;
        companyAccountNumber = companyAcc;
        amount = amt;
        requestDate = date;
        status = stat;
    }

    RecurringPaymentRequest(int userAcc, int companyAcc, double amt) {
        id = 0;
        userAccountNumber = userAcc;
        companyAccountNumber = companyAcc;
        amount = amt;
        requestDate = DateTime::Now;
        status = "pending";
    }

    RecurringPaymentRequest() {
        id = 0;
        userAccountNumber = 0;
        companyAccountNumber = 0;
        amount = 0;
        requestDate = DateTime::Now;
        status = "pending";
    }

    property int Id {
        int get() { return id; }
    }
    property int UserAccountNumber {
        int get() { return userAccountNumber; }
    }
    property int CompanyAccountNumber {
        int get() { return companyAccountNumber; }
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
