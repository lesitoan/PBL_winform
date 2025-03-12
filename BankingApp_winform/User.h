#ifndef USER_H
#define USER_H

using namespace System;

public
ref class User {
  private:
    String ^ fullName;
    String ^ password;
    String ^ phoneNumber;
    int accountNumber;
    double balance;
    String ^ role; // user, admin, company
    int pin;
    String ^ bankName;
    int serviceId;

  public:
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         int accNum) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = 1000000;
        role = "user"; // user, admin, company
        pin = 0;
        accountNumber = accNum;
        bankName = "BIDV";
        serviceId = 0;
    }
    User(String ^ _fullName, String ^ _password, String ^ _phoneNumber,
         int _accountNumber, double _balance, String ^ _role, int _pin,
         String ^ _bankName, int _serviceId) {
        fullName = _fullName;
        password = _password;
        phoneNumber = _phoneNumber;
        balance = _balance;
        role = _role;
        pin = _pin;
        accountNumber = _accountNumber;
        bankName = _bankName;
        serviceId = _serviceId;
    }

    User() : User("", "", "", 0, 0, "user", 0, "BIDV", 0) {};

    String ^ getFullName() { return fullName; } String ^
        getPassword() { return password; } int getAccountNumber() {
        return accountNumber;
    }
    double getBalance() { return balance; }
    String ^ getRole() { return role; } int getPin() { return pin; }
    String ^ getPhoneNumber() { return phoneNumber; } String ^
        getBankName() { return bankName; } int getServiceId() {
        return serviceId;
    }

    void setPassword(String ^ _password) { this->password = _password; }
    void setPin(int _pin) { this->pin = _pin; }
    void setBalance(double _balance) { this->balance = _balance; }

    property String ^ FullName { String ^ get() { return fullName; } }

    property int AccountNumber {
        int get() { return accountNumber; }
    }
};

#endif // USER_H
