#ifndef PAYMENTCODES_H
#define PAYMENTCODES_H

using namespace System;

public
ref class PaymentCodes {
  private:
    int id;
    int companyId;
    String ^ code;
    int amount;
    int status;
    DateTime createdDate;
    DateTime expiredDate;

  public:
    PaymentCodes(int id, int companyId, String ^ code, int amount, int status,
                 DateTime createdDate, DateTime expiredDate) {
        this->id = id;
        this->companyId = companyId;
        this->code = code;
        this->amount = amount;
        this->status = status;
        this->createdDate = createdDate;
        this->expiredDate = expiredDate;
    }
    property int Id {
        int get() { return id; }
    }
    property int CompanyId {
        int get() { return companyId; }
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
