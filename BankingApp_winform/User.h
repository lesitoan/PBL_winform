#pragma once
using namespace System;

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
    String ^ bankName;

    int randomAccountNumber() {
        Random ^ random = gcnew Random();
        return random->Next(100000000, 999999999);
    }

  public:
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = 1000000;
        isAdmin = false;
        pin = 0;
        accountNumber = this->randomAccountNumber();
        bankName = "BIDV";
    }
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         int _accountNumber, double _balance, bool _isAdmin, int _pin,
         String ^ _bankName) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = _balance;
        isAdmin = _isAdmin;
        pin = _pin;
        accountNumber = _accountNumber;
        bankName = _bankName;
    }

    User() : User("", "", "", 0, 0, false, 0, "BIDV") {};

    String^ getFullName() { return fullName; }
    String^ getPassword() { return password; } 
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance;}
    bool getIsAdmin() { return isAdmin; }
    int getPin() { return pin; }
    String ^ getPhoneNumber() { return phoneNumber; }
    String ^ getBankName() { return bankName; }

    void setPassword(String ^ _password) {
        this->password = _password;
    }
    void setPin(int _pin) { this->pin = _pin; }
    void setBalance(double _balance) { this->balance = _balance; }
};