#ifndef PAYMENTCODES_H
#define PAYMENTCODES_H

using namespace System;

public
ref class PaymentCodes {
  private:
    int id;
    int companyAccountNumber;
    String ^ code;
    int amount;
    int status;
    DateTime createdDate;
    DateTime expiredDate;

  public:
    PaymentCodes(int id, int companyAccountNumber, String ^ code, int amount,
                 int status,
                 DateTime createdDate, DateTime expiredDate) {
        this->id = id;
        this->companyAccountNumber = companyAccountNumber;
        this->code = code;
        this->amount = amount;
        this->status = status;
        this->createdDate = createdDate;
        this->expiredDate = expiredDate;
    }
    PaymentCodes(int companyAccountNumber, String ^ code, int amount, int day) {
        this->id = 0;
        this->companyAccountNumber = companyAccountNumber;
        this->code = code;
        this->amount = amount;
        this->status = 0;
        this->createdDate = DateTime::Now;
        this->expiredDate = DateTime::Now.AddDays(day);
    }
    PaymentCodes() {
        this->id = 0;
        this->companyAccountNumber = 0;
        this->code = "";
        this->amount = 0;
        this->status = 0;
        this->createdDate = DateTime::Now;
        this->expiredDate = DateTime::Now;
    }

    property int Id {
        int get() { return id; }
    }
    property int CompanyAccountNumber {
        int get() { return companyAccountNumber; }
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
};

#endif // PAYMENTCODES_H
