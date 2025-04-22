#include "ISaveToFile.h"

#ifndef USER_H
#define USER_H

using namespace System;
using namespace System::IO;

public
ref class User : public ISaveToFile {
  private:
    String ^ fullName;
    String ^ password;
    String ^ phoneNumber;
    String ^ accountNumber;
    double balance;
    String ^ role; // user, admin, company
    int pin;
    String ^ bankName;
    int status;
    String ^ serviceId;
    String ^ urlAvatar;

  public:
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         String ^ accNum) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = 1000000;
        role = "user"; // user, admin, company
        pin = 0;
        accountNumber = accNum;
        bankName = "BIDV";
        status = 1;
        serviceId = "";
        urlAvatar = "BankingApp_winform\\images\\avatars\\default_avatar.png";
    }
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         String ^ _accountNumber, double _balance, String ^ _role, int _pin,
         String ^ _bankName, int _status, String ^ _serviceId,
         String ^ _avatar) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = _balance;
        role = _role;
        pin = _pin;
        accountNumber = _accountNumber;
        bankName = _bankName;
        status = _status;
        serviceId = _serviceId;
        urlAvatar = _avatar;
    }

    User()
        : User("", "", "", "", 0, "user", 0, "BIDV", 1, "",
               "BankingApp_winform\\images\\avatars\\default_avatar.png") {};

    User(String ^ _bankName, String ^ _fullName, String ^ _accNumber) {
        bankName = _bankName;
        fullName = _fullName;
        accountNumber = _accNumber;

        password = "";
        phoneNumber = "";
        balance = 0;
        role = "user";
        pin = 0;
        status = 1;
        serviceId = "";
        urlAvatar = "BankingApp_winform\\images\\avatars\\default_avatar.png";
    }

    String ^ getFullName() { return fullName; } String ^
        getPassword() { return password; } String ^ getAccountNumber() {
            return accountNumber;
        } double getBalance() {
        return balance;
    }
    String ^ getRole() { return role; } int getPin() {
        return pin;
    }
    String ^ getPhoneNumber() { return phoneNumber; } String ^
        getBankName() { return bankName; } String ^
        getServiceId() {
            return serviceId;
        }

        void setPassword(String ^ _password) {
        this->password = _password;
    }
    void setPin(int _pin) {
        this->pin = _pin;
    }
    void setBalance(double _balance) {
        this->balance = _balance;
    }

    property String ^ FullName { String ^ get() { return fullName; } }

        property String ^
        AccountNumber {
            String ^ get() { return accountNumber; }
        }

        property int Status {
        int get() {
            return status;
        }
        void set(int value) {
            status = value;
        }
    }
    property String ^ UrlAvatar {
        String ^ get() { return urlAvatar; } void set(String ^ value) {
            urlAvatar = value;
        }
    }

        virtual void
        WriteTo(BinaryWriter ^ writer) {
        writer->Write(getFullName());
        writer->Write(getPassword());
        writer->Write(getPhoneNumber());
        writer->Write(getAccountNumber());
        writer->Write(getBalance());
        writer->Write(getRole());
        writer->Write(getPin());
        writer->Write(getBankName());
        writer->Write(Status);
        writer->Write(getServiceId());
        writer->Write(UrlAvatar);
    }

    virtual void ReadFrom(BinaryReader ^ reader) {
        fullName = reader->ReadString();
        password = reader->ReadString();
        phoneNumber = reader->ReadString();
        accountNumber = reader->ReadString();
        balance = reader->ReadDouble();
        role = reader->ReadString();
        pin = reader->ReadInt32();
        bankName = reader->ReadString();
        Status = reader->ReadInt32();
        serviceId = reader->ReadString();
        UrlAvatar = reader->ReadString();
    }
};

#endif // USER_H
