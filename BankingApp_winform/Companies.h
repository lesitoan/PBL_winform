#ifndef COMPANIES_H
#define COMPANIES_H

using namespace System;

public
ref class Companies {
  private:
    int id;
    String ^ name;
    int serviceId;
    int amount;
    String ^ password;
    String ^ phoneNumber;
    String ^ role;

  public:
    Companies(int id, String ^ name, int serviceId, int amount) {
        this->id = id;
        this->name = name;
        this->serviceId = serviceId;
        this->amount = amount;
        this->role = "company";
    }
    Companies(int id, String ^ name, int serviceId, int amount,
              String ^ password, String ^ phoneNumber, String ^ role) {
        this->id = id;
        this->name = name;
        this->serviceId = serviceId;
        this->amount = amount;
        this->password = password;
        this->phoneNumber = phoneNumber;
        this->role = role;
    }
    Companies() {
        id = 0;
        name = "ENV";
        serviceId = 1;
        amount = 0;
        role = "company";
        password = "123456";
        phoneNumber = "19008118";
    }

    property int Id {
        int get() { return id; }
    }
    property String ^ Name {
        String ^ get() { return name; } void set(String ^ value) {
            name = value;
        }
    }
    property int ServiceId {
        int get() { return serviceId; }
        void set(int value) { serviceId = value; }
    }
    property int Amount {
        int get() { return amount; }
        void set(int value) { amount = value; }
    }
    property String ^ Role { String ^ get() { return role; } }
    property String ^ Password {
        String ^ get() { return password; }
    }
    property String ^PhoneNumber {
        String ^ get() { return phoneNumber; }
    }

};

#endif // COMPANIES_H
