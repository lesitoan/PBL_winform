#ifndef PAYMENTCODES_H
#define PAYMENTCODES_H

using namespace System;

public
ref class PaymentCodes {
  private:
    String ^ id;
    String ^ companyAccountNumber;

    String ^ code;
    int amount;
    int status;
    DateTime createdDate;
    DateTime expiredDate;
    String ^ paymentDate;

  public:
    PaymentCodes(String ^ id, String ^ companyAccountNumber, String ^ code,
                 int amount,
                 int status,
                 DateTime createdDate, DateTime expiredDate, String^ paymentDate) {
        this->id = id;
        this->companyAccountNumber = companyAccountNumber;
        this->code = code;
        this->amount = amount;
        this->status = status;
        this->createdDate = createdDate;
        this->expiredDate = expiredDate;
        this->paymentDate = paymentDate;
    }
    PaymentCodes(String ^ companyAccountNumber, String ^ code, int amount,
                 int day) {
        this->id = "";
        this->companyAccountNumber = companyAccountNumber;
        this->code = code;
        this->amount = amount;
        this->status = 0;
        this->createdDate = DateTime::Now;
        this->expiredDate = DateTime::Now.AddDays(day);
        this->paymentDate = "";
    }
    PaymentCodes() {
        this->id = "";
        this->companyAccountNumber = "";
        this->code = "";
        this->amount = 0;
        this->status = 0;
        this->createdDate = DateTime::Now;
        this->expiredDate = DateTime::Now;
        this->paymentDate = "";
    }

    property String ^ Id { String ^ get() { return id; }
    } property String ^
        CompanyAccountNumber {
            String ^ get() { return companyAccountNumber; }
    }
    property String ^ Code {
        String ^ get() { return code; }
        void set(String ^ value) {
            code = value;
        }
    } property int Amount {
        int get() { return amount; }
        void set(int value) { amount = value; }
    }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }
    property DateTime CreatedDate {
        DateTime get() { return createdDate; }
    }
    property DateTime ExpiredDate {
        DateTime get() { return expiredDate; }
        void set(DateTime value) { expiredDate = value; }
    }
    property String ^ PaymentDate {
        String ^ get() { return paymentDate; } void set(String ^ value) {
            paymentDate = value;
        }
    }
};

#endif // PAYMENTCODES_H
