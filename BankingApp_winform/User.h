#pragma once
#include "User.h"
using namespace System;

using namespace System::IO;
using namespace System::Collections::Generic;

public
ref class User {
  private:
    String ^ fullName;
    String ^ password;
    String ^ phoneNumber;
    int accountNumber;
    double balance;
    bool isAdmin;
    int pin;

    int randomAccountNumber() {
        Random ^ random = gcnew Random();
        return random->Next(10000, 99999);
    }

  public:
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = 0;
        isAdmin = false;
        pin = 0;
        accountNumber = this->randomAccountNumber();
    }
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         int _accountNumber, double _balance, bool _isAdmin, int _pin) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = _balance;
        isAdmin = _isAdmin;
        pin = _pin;
        accountNumber = _accountNumber;
    }

    User() : User("", "", "", 0, 0, false, 0) {};

    String^ getFullName() { return fullName; }
    String^ getPassword() { return password; } 
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance;}
    bool getIsAdmin() { return isAdmin; }
    int getPin() { return pin; }
    String ^ getPhoneNumber() { return phoneNumber; }
};