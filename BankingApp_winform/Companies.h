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

  public:
    Companies(int id, String ^ name, int serviceId, int amount) {
        this->id = id;
        this->name = name;
        this->serviceId = serviceId;
        this->amount = amount;
    }
    Companies() {
        id = 0;
        name = "";
        serviceId = 0;
        amount = 0;
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

};

#endif // COMPANIES_H
