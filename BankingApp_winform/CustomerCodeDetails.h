#include "BaseEntity.h"


#pragma once
#ifndef CUSTOMERCODEDETAILS_H
#define CUSTOMERCODEDETAILS_H

using namespace System;

ref class CustomerCodeDetails : public BaseEntity {
  private:
    String ^ customerCodeId;
    String ^ paymentUserId;
    double amount;
    DateTime paymentDate;
    DateTime expiredDate;
    int status; // 1: đã nôp tiền, 0: chưa nộp tiền

  public:
    CustomerCodeDetails(String ^ customerCodeId,double amt, DateTime expiredDate)
        : BaseEntity()
    {
        this->customerCodeId = customerCodeId;
        this->paymentUserId = "";
        amount = amt;
        paymentDate = DateTime::MinValue;
        this->expiredDate = expiredDate;
        status = 0;
    }

    CustomerCodeDetails(String ^ id, DateTime createAt, DateTime updatedAt, String ^ customerCodeId,
                        String ^ paymentUserId, double amt, DateTime paymentDate,
                        DateTime expiredDate, int stat)
        : BaseEntity(id, createAt, updatedAt) {
        this->customerCodeId = customerCodeId;
        this->paymentUserId = paymentUserId;
        amount = amt;
        this->paymentDate = paymentDate;
        this->expiredDate = expiredDate;
        status = stat;
    }

    CustomerCodeDetails() : BaseEntity() {
        customerCodeId = "";
        paymentUserId = "";
        amount = 0;
        paymentDate = DateTime::MinValue;
        expiredDate = DateTime::Now;
        status = 0;
    }

    property String ^ CustomerCodeId {
        String ^ get() { return customerCodeId; } void set(String ^ value) {
            customerCodeId = value;
        }
    }

    property String ^
        PaymentUserId {
            String ^ get() {
                return paymentUserId;
            } void set(String ^ value) {
                paymentUserId = value;
            }
        }
    property double Amount {
        double get() { return amount; }
    }

    property DateTime PaymentDate {
        DateTime get() { return paymentDate; } void set(DateTime value) {
            paymentDate = value;
        }
    } property DateTime ExpiredDate {
        DateTime get() { return expiredDate; }
        void set(DateTime value) { expiredDate = value; }
    }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }

    virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(customerCodeId);
        writer->Write(paymentUserId);
        writer->Write(amount);
        writer->Write(paymentDate.ToBinary());
        writer->Write(expiredDate.ToBinary());
        writer->Write(status);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        customerCodeId = reader->ReadString();
        paymentUserId = reader->ReadString();
        amount = reader->ReadDouble();
        paymentDate = DateTime::FromBinary(reader->ReadInt64());
        expiredDate = DateTime::FromBinary(reader->ReadInt64());
        status = reader->ReadInt32();
    }
};

#endif
