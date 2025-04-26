#include "BaseEntity.h"


#pragma once
using namespace System;

public
ref class Transaction : public BaseEntity {
  private:
    String ^ fromUserId;
    String ^ toUserId;
    double amount;
    String ^ message;
    String ^ type;

  public:
    Transaction(String ^ id, DateTime createAt, DateTime updatedAt, String ^ _fromUserId,
                String ^ _toUserId, double _amount, String ^ _message, String ^ _type)
        : BaseEntity(id, createAt, updatedAt)
    {
        fromUserId = _fromUserId;
        toUserId = _toUserId;
        amount = _amount;
        message = _message;
        type = _type;
    } 

    Transaction( String ^ _fromUserId,String ^ _toUserId, double _amount, String ^ _message, String^ _type)
        : BaseEntity() {
        fromUserId = _fromUserId;
        toUserId = _toUserId;
        amount = _amount;
        message = _message;
        type = _type;
    } 

    Transaction()
        : Transaction("", DateTime::MinValue, DateTime::MinValue, "", "", 0, "", "") {};

    property String ^
        FromUserId {
            String ^ get() { return fromUserId; }
        }
    property String ^
        ToUserId {
            String ^ get() { return toUserId; }
        }
    property double Amount{
        double get() {
            return amount;
        }
    }
    property String ^
        Message {
            String ^ get() { return message; } void set(String ^ value) {
                message = value;
            }
        }
    property String ^
        Type {
            String ^ get() { return type; }
        }


    virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(fromUserId);
        writer->Write(toUserId);
        writer->Write(amount);
        writer->Write(message);
        writer->Write(type);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        fromUserId = reader->ReadString();
        toUserId = reader->ReadString();
        amount = reader->ReadDouble();
        message = reader->ReadString();
        type = reader->ReadString();
    }
};