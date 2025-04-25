#pragma once
#include "AbstractUser.h"
#include "ISaveToFile.h"

#ifndef Admin_h
#define Admin_h

using namespace System;
using namespace System::IO;

public
ref class Admin : public AbstractUser, public ISaveToFile {
  public:
    Admin(String ^ _id, DateTime _createdAt, DateTime _updatedAt, String ^ _fullName,
           String ^ _password, String ^ _phoneNumber, String ^ _accountNumber, double _balance,
           Role _role, String ^ _pin, Bank _bankName, Status _status, String ^ _urlAvatar)
        : AbstractUser(_id, _createdAt, _updatedAt, _fullName, _password, _phoneNumber, _accountNumber,
                       _balance, _role, _pin, _bankName, _status, _urlAvatar) {
    }

    Admin()
        : AbstractUser() {
    }

    virtual void WriteTo(BinaryWriter ^ writer) override {
        AbstractUser::WriteTo(writer);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        AbstractUser::ReadFrom(reader);
    }
};

#endif // !Admin_h
