#pragma once
#ifndef CUSTOMERCODEDETAILS_H
#define CUSTOMERCODEDETAILS_H

using namespace System;

ref class CustomerCodeDetails {
  private:
    String ^ id;         
    String ^ customerCodeId;
    String ^ paymentUserAccountNumber;
    double amount;            
    DateTime createDate;
    String^ paymentDate;
    DateTime expiredDate;
    int status; // 1: đã nôp tiền, 0: chưa nộp tiền

    public:
    CustomerCodeDetails(String ^ codeDetailId, String ^ customerCodeId,
                            double amt,
                            DateTime expiredDate) {
        id = codeDetailId;
        this->customerCodeId = customerCodeId;
        this->paymentUserAccountNumber = "";
        amount = amt;
        createDate = DateTime::Now;
        paymentDate = "";
        this->expiredDate = expiredDate;
        status = 0;
    }

    CustomerCodeDetails(String ^ codeDetailId, String ^ customerCodeId,
                        String ^ paymentUserAccountNumber, double amt,
                        DateTime createDate, String ^ paymentDate,
                        DateTime expiredDate, int stat) {
        id = codeDetailId;
        this->customerCodeId = customerCodeId;
        this->paymentUserAccountNumber = paymentUserAccountNumber;
        amount = amt;
        this->createDate = createDate;
        this->paymentDate = paymentDate;
        this->expiredDate = expiredDate;
        status = stat;
    }

    CustomerCodeDetails() {
        id = "";
        customerCodeId = "";
        paymentUserAccountNumber = "";
        amount = 0;

        createDate = DateTime::Now;
        paymentDate = "";
        expiredDate = DateTime::Now;
        status = 0;
    }

    property String ^ Id { String ^ get() { return id; }
    } property String ^
        CustomerCodeId {
            String ^ get() { return customerCodeId; }
    } property String ^
        PaymentUserAccountNumber {
            String ^ get() { return paymentUserAccountNumber; }
    }
    property double Amount {
        double get() { return amount; }
    }
    property DateTime CreateDate {
        DateTime get() { return createDate; }
    }
    property String ^ PaymentDate {
        String ^ get() { return paymentDate; } void set(String ^ value) {
            paymentDate = value;
        }
    }
    property DateTime ExpiredDate {
        DateTime get() { return expiredDate; }
        void set(DateTime value) { expiredDate = value; }
    }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }
};

#endif
