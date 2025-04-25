#pragma once
#include "BaseEntity.h"
#include "ENV.h"
#include "Enums.h"

#ifndef AbstractUsers_h
#define AbstractUsers_h

ref class AbstractUser abstract : public BaseEntity {
  protected:
    String ^ fullName;
    String ^ password;
    String ^ phoneNumber;
    String ^ accountNumber;
    double balance;
    Role role;
    String ^ pin;
    Bank bankName;
    Status status;
    String ^ urlAvatar;

    AbstractUser(String ^ _id, DateTime _createdAt, DateTime _updatedAt, String ^ _fullName, String ^ _password,
                 String ^ _phoneNumber, String ^ _accountNumber,
                 double _balance, Role _role, String ^ _pin,
                 Bank _bankName, Status _status, String ^ _urlAvatar)
        : BaseEntity(_id, _createdAt, _updatedAt) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        accountNumber = _accountNumber;
        balance = _balance;
        role = _role;
        pin = _pin;
        bankName = _bankName;
        status = _status;
        urlAvatar = _urlAvatar;
    }

    AbstractUser()
        : BaseEntity(),
          fullName(""),
          password(""),
          phoneNumber(""),
          accountNumber(""),
          balance(0),
          role(Role::Client),
          pin(""),
          bankName(Bank::BIDV),
          status(Status::Active),
          urlAvatar(ENV::DEFAULT_AVATAR_PATH) {
    }

    AbstractUser(String ^ _fullName, String ^ _password, String ^ _phoneNumber, String ^ _accountNumber, Role _role)
        : BaseEntity(),
          balance(0),
          pin(""),
          bankName(Bank::BIDV),
          status(Status::Active),
          urlAvatar(ENV::DEFAULT_AVATAR_PATH) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        accountNumber = _accountNumber;
        role = _role;
    }

    AbstractUser(String ^ _fullName, String ^ _password, String ^ _phoneNumber)
        : AbstractUser(_fullName, _password, _phoneNumber, this->createAccNumber(), Role::Client) {
    }

  private:
    String ^ createAccNumber() {
        String ^ accNum = DateTime::Now.ToString("yyyyMMddHHmmss");
        return accNum;
    }

  public : 
      virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(fullName);
        writer->Write(password);
        writer->Write(phoneNumber);
        writer->Write(email);
        writer->Write(accountNumber);
        writer->Write(balance);
        writer->Write((int)role);
        writer->Write(pin);
        writer->Write((int)bankName);
        writer->Write((int)status);
        writer->Write(urlAvatar);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        fullName = reader->ReadString();
        password = reader->ReadString();
        phoneNumber = reader->ReadString();
        email = reader->ReadString();
        accountNumber = reader->ReadString();
        balance = reader->ReadDouble();
        role = (Role)reader->ReadInt32();
        pin = reader->ReadString();
        bankName = (Bank)reader->ReadString();
        status = (Status)reader->ReadInt32();
        urlAvatar = reader->ReadString();
    }

    virtual property String ^ FullName {
        String ^ get() { return fullName; } void set(String ^ value) {
            fullName = value;
        }
    }
    virtual property String ^
        Password {
            String ^ get() { return password; } void set(String ^ value) {
                password = value;
            }
        }
    virtual property String ^
        PhoneNumber {
            String ^ get() { return phoneNumber; } void set(String ^ value) {
                phoneNumber = value;
            }
        }

    virtual property String ^
        Email {
            String ^ get() { return email; } void set(String ^ value) {
                email = value;
            }
        }
    virtual property String ^
        AccountNumber {
            String ^ get() { return accountNumber; } void set(String ^ value) {
                accountNumber = value;
            }
        }
    virtual property double Balance {
        double get() {
            return balance;
        }
        void set(double value) {
            balance = value;
        }
    }
    virtual property Role UseRole {
        Role get() {
            return role;
        }
    }
    virtual property String ^ Pin {
        String ^ get() { return pin; } void set(String ^ value) {
            pin = value;
        }
    } virtual property Bank BankName {
        Bank get() {
            return bankName;
        }
    }
    virtual property Status UserStatus {
        Status get() {
            return status;
        }
        void set(Status value) {
            status = value;
        }
    }

    virtual property String ^ UrlAvatar {
        String ^ get() { return urlAvatar; } void set(String ^ value) {
            urlAvatar = value;
        }
    }
};

#endif // AbstractUsers_h
