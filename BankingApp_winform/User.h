#pragma once
#include "User.h"
using namespace System;

using namespace System::IO;
using namespace System::Collections::Generic;


public ref class User {
public:
    String^ userName;
    String^ password;
    int accountNumber;
    int balance;
    bool isAdmin;
    int pin;

public:
    User(String^ _userName, String^ _password, int _accountNumber, int _balance, bool _isAdmin, int _pin) {
        userName = _userName;
        password = _password;
        accountNumber = _accountNumber;
        balance = _balance;
        isAdmin = _isAdmin;
        pin = _pin;
    }

    User(String^ _userName, String^ _password) : User(_userName, _password, 12345, 0, false, 1) {}
	User() : User("", "", 0, 0, false, 1) {}
   
};