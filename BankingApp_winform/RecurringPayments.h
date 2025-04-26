#include "BaseEntity.h"

#ifndef RECURRINGPAYMENTS_H
#define RECURRINGPAYMENTS_H

using namespace System;

public
ref class RecurringPayments : public BaseEntity {
  private:
    String ^ userId;
    String ^ customerCodeId;
    int monthly;    // 1,2,3,4,5....12
    int paymentDay; // 1-31

  public:
    RecurringPayments(String ^ id, DateTime createAt, DateTime updatedAt, String ^ userId,
                      String ^ customerCodeId, int monthly, int paymentDay)
        : BaseEntity(id, createAt, updatedAt)
    {
        this->userId = userId;
        this->customerCodeId = customerCodeId;
        this->monthly = monthly;
        this->paymentDay = paymentDay;
    }

    RecurringPayments(String ^ userId, String ^ customerCodeId, int paymentDay)
        : BaseEntity() {
        this->userId = userId;
        this->customerCodeId = customerCodeId;
        this->monthly = 1;
        this->paymentDay = paymentDay;
    }

    RecurringPayments() 
        : BaseEntity()
    {
        userId = "";
        customerCodeId = "";
        monthly = 1;
        paymentDay = 1;
    }

    property String ^
        UserId {
            String ^
                get() { return userId; }
            void set(String ^ value) {
                userId = value;
            }
        }
    property String ^
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

    virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(userId);
        writer->Write(customerCodeId);
        writer->Write(monthly);
        writer->Write(paymentDay);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        userId = reader->ReadString();
        customerCodeId = reader->ReadString();
        monthly = reader->ReadInt32();
        paymentDay = reader->ReadInt32();
    }
};

#endif // RECURRINGPAYMENTS_H
