#include "BaseEntity.h"

#ifndef SAVINGCUSTOMERS_H
#define SAVINGCUSTOMERS_H

using namespace System;

public
ref class SavingCustomers : public BaseEntity {
  private:
    String ^ userId;
    double amount;
    double interestAmount;
    String ^ type; // termDeposit, nonTermDeposit
    int term;      // so thang
    float interestRate; 
    DateTime depositDate;
    DateTime paymentDate;
    int status; // 0: chưa thanh toán, 1: đã thanh toán, 2 đang yêu cầu

  public:
    SavingCustomers(String ^ id, DateTime createAt, DateTime updatedAt, String ^ _userId, double _amount, double _interserAmount, String ^ _type, int _term,
                    float _rate, DateTime _depositDate, DateTime _paymentDate, int _status)
    
        : BaseEntity(id, createAt, updatedAt)
    {
        userId = _userId;
        amount = _amount;
        interestAmount = _interserAmount;
        type = _type;
        term = _term;
        interestRate = _rate;
        depositDate = _depositDate;
        paymentDate = _paymentDate;
        status = _status;
    }

    SavingCustomers()
        : SavingCustomers("", DateTime::MinValue, DateTime::MinValue, "", 0, 0, "", 0, 0, DateTime::MinValue, DateTime::MinValue, 0) {};

    SavingCustomers(String ^ _userId, double _amount, String ^ _type, int _term) 
        : BaseEntity()
    {
        userId = _userId;
        amount = _amount;
        interestAmount = 0;
        type = _type;
        term = _term;
        if (type == "nonTermDeposit") {
            interestRate = 0.04;
        } else {
            if (term == 3)
                interestRate = 0.045;
            else if (term == 6)
                interestRate = 0.05;
            else if (term == 9)
                interestRate = 0.055;
            else if (term == 12)
                interestRate = 0.06;
        }
        depositDate = DateTime::Now;
        paymentDate = DateTime::MinValue;
        status = 0;
    }

    double CalculateInterestAmount() {
        DateTime currDate = depositDate.AddMonths(term);
        if (currDate > DateTime::Now) {
            currDate = DateTime::Now;
        }
        TimeSpan duration = currDate - depositDate;
        return amount * interestRate * duration.Days / 365.0;
    }
    Double TotalAmount() {
        return amount + interestAmount;
    }

    property String ^
        UserId {
            String ^
                get() { return userId; } 
        }
    property double Amount {
        double get() { return amount; }
    }
    property double InterestAmount {
        double get() { return interestAmount; }
        void set(double value) { interestAmount = value; }
    }
    property String ^ Type {
        String ^ get() { return type; }
    }
    property int Term {
        int get() { return term; }
    }
    property float InterestRate {
        float get() { return interestRate; }
    }
    property DateTime DepositDate {
        DateTime get() { return depositDate; }
    }
    property DateTime PaymentDate {
        DateTime get() {
            return paymentDate;
        }
        void set(DateTime value) {
            paymentDate = value;
        }
    }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }

    virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(this->userId);
        writer->Write(this->amount);
        writer->Write(this->interestAmount);
        writer->Write(this->type);
        writer->Write(this->term);
        writer->Write(this->interestRate);
        writer->Write(this->depositDate.ToBinary());
        writer->Write(this->paymentDate.ToBinary());
        writer->Write(this->status);
    }
    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        userId = reader->ReadString();
        amount = reader->ReadDouble();
        interestAmount = reader->ReadDouble();
        type = reader->ReadString();
        term = reader->ReadInt32();
        interestRate = reader->ReadSingle();
        depositDate = DateTime::FromBinary(reader->ReadInt64());
        paymentDate = DateTime::FromBinary(reader->ReadInt64());
        status = reader->ReadInt32();
    }

};

#endif // SAVINGCUSTOMERS_H
