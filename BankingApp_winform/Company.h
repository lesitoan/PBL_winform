#pragma once
#include "AbstractUser.h"
#include "ISaveToFile.h"

#ifndef Company_h
#define Company_h

using namespace System;
using namespace System::IO;

public
ref class Company : public AbstractUser, public ISaveToFile {
  private:
    String ^ serviceId;
  public:
    Company(String ^ _id, DateTime _createdAt, DateTime _updatedAt, String ^ _fullName,
           String ^ _password, String ^ _phoneNumber, String ^ _accountNumber, double _balance,
           Role _role, String ^ _pin, Bank _bankName, Status _status, String ^ _urlAvatar, String^ serviceId)
        : AbstractUser(_id, _createdAt, _updatedAt, _fullName, _password, _phoneNumber, _accountNumber,
                       _balance, _role, _pin, _bankName, _status, _urlAvatar) {
        this->serviceId = serviceId;
    }

    Company(String ^ _fullName, String ^ _password, String ^ _phoneNumber, String^ _accountNumber, String^ _serviceId)
        : AbstractUser(_fullName, _password, _phoneNumber, _accountNumber, Role::Company) {
        this->serviceId = _serviceId;
    }

    Company()
        : AbstractUser() {
    }

    virtual void WriteTo(BinaryWriter ^ writer) override {
        AbstractUser::WriteTo(writer);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        AbstractUser::ReadFrom(reader);
    }
};

#endif // !Company_h
