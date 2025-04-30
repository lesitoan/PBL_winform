#include "BaseEntity.h"
#include "ENV.h"

using namespace System::Text;
using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;

#ifndef USER_H
#define USER_H

public enum class Role {
    User = 0,
    Admin = 1,
    Company = 2
};

public enum class Bank {
      BIDV = 0,
      Vietcombank = 1,
      Techcombank = 2,
      Agribank = 3,
      Vietinbank = 4,
      MBBank = 5,
      Sacombank = 6,
      ACB = 7,
      Eximbank = 8,
      HDBank = 9
  };

public
ref class User : public BaseEntity {
  private:
    String ^ fullName;
    String ^ password;
    String ^ phoneNumber;
    String ^ accountNumber;
    double balance;
    Role role; // user, admin, company
    int pin;
    Bank bankName;
    int status;
    String ^ serviceId;
    String ^ urlAvatar;

    String^ createAccNum() {
      DateTime now = DateTime::Now;
      return now.ToString("MdHHmmssff");
    }

  public:
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber)
        : BaseEntity() {
        fullName = _fullName;
        password = this->Hash(_password);
        phoneNumber = _phoneNumber;
        balance = 1000000;
        role = Role::User;
        pin = 0;
        accountNumber = this->createAccNum();
        bankName = Bank::BIDV;
        status = 1;
        serviceId = "";
        urlAvatar = ENV::DEFAULT_AVATAR_PATH;
    }
    User(String ^ _id, DateTime _createdAt, DateTime _updatedAt, String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         String ^ _accountNumber, double _balance, Role _role, int _pin,
         Bank _bankName, int _status, String ^ _serviceId,
         String ^ _avatar)
        : BaseEntity(_id, _createdAt, _updatedAt) {
        fullName = _fullName;
        password = this->Hash(_password);
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

    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         String ^ _accountNumber, double _balance, Role _role, int _pin,
         Bank _bankName, int _status, String ^ _serviceId)
        : BaseEntity() {
        fullName = _fullName;
        password = this->Hash(_password);
        phoneNumber = _phoneNumber;
        balance = _balance;
        role = _role;
        pin = _pin;
        accountNumber = _accountNumber;
        bankName = _bankName;
        status = _status;
        serviceId = _serviceId;
        urlAvatar = ENV::DEFAULT_AVATAR_PATH;
    }

    User(Bank bankname, String ^ fullName, String ^ accNum) {
        this->bankName = bankname;
        this->fullName = fullName;
        this->accountNumber = accNum;
        this->balance = 0;
        this->role = Role::User;
        this->pin = 0;
        this->status = 1;
        this->serviceId = "";
        this->urlAvatar = ENV::DEFAULT_AVATAR_PATH;
    }


 
    User()
        : User("", DateTime::MinValue, DateTime::MinValue, "", "", "", "", 0, Role::User , 0, Bank::BIDV, 1, "",
               ENV::DEFAULT_AVATAR_PATH) {};


    String ^ getFullName() { return fullName; } String ^
        getPassword() { return password; } String ^ getAccountNumber() {
            return accountNumber;
        } double getBalance() {
        return balance;
    }

    Role getRole() { return role; } int getPin() {
        return pin;
    }

    String ^ getPhoneNumber() { return phoneNumber; }
    
    Bank getBankName() { return bankName; }
    
    String ^
        getServiceId() {
            return serviceId;
        }

        void setPassword(String ^ _password) {
        this->password = this->Hash(_password);
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
        WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(getFullName());
        writer->Write(getPassword());
        writer->Write(getPhoneNumber());
        writer->Write(getAccountNumber());
        writer->Write(getBalance());
        writer->Write(static_cast<int>(getRole()));
        writer->Write(getPin());
        writer->Write(static_cast<int>(getBankName()));
        writer->Write(Status);
        writer->Write(getServiceId());
        writer->Write(UrlAvatar);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        fullName = reader->ReadString();
        password = reader->ReadString();
        phoneNumber = reader->ReadString();
        accountNumber = reader->ReadString();
        balance = reader->ReadDouble();
        role = static_cast<Role>(reader->ReadInt32());
        pin = reader->ReadInt32();
        bankName = static_cast<Bank>(reader->ReadInt32());
        Status = reader->ReadInt32();
        serviceId = reader->ReadString();
        UrlAvatar = reader->ReadString();
    }

    String ^ Hash(String ^ password) {
        array<Byte> ^ bytes = Encoding::UTF8->GetBytes(password);
        SHA256 ^ sha256 = SHA256::Create();
        array<Byte> ^ hashBytes = sha256->ComputeHash(bytes);

        // Chuyển hash sang dạng chuỗi hex
        StringBuilder ^ sb = gcnew StringBuilder();
        for (int i = 0; i < hashBytes->Length; i++) {
            sb->Append(hashBytes[i].ToString("x2"));
        }

        return sb->ToString();
    }
};

#endif // USER_H
