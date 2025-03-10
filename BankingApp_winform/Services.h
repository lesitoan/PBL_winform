#ifndef SERVICES_H
#define SERVICES_H

using namespace System;

public
ref class Services {
  private:
    int id;
    String ^ name;

    public:
    Services(int id, String ^ name) {
        this->id = id;
        this->name = name;
    }
    property int Id {
        int get() { return id; }
    }
    property String ^ Name {
        String ^ get() { return name; }
        void set(String ^ value) {
            name = value;
        }
    }
};

#endif // SERVICES_H
