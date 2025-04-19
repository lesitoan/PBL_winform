#include "ISaveToFile.h"

#ifndef SERVICES_H
#define SERVICES_H

using namespace System;
using namespace System::IO;

public
ref class Services : public ISaveToFile {
  private:
    String ^ id;
    String ^ name;

    public:
    Services(String ^ id, String ^ name) {
        this->id = id;
        this->name = name;
    }
    Services() {
        id = "";
        name = "";
    }

    property String ^ Id {
        String ^ get() { return id; }
    }
    property String ^ Name {
        String ^ get() { return name; }
        void set(String ^ value) {
            name = value;
        }
    } virtual void WriteTo(BinaryWriter ^ writer) {
        writer->Write(id);
        writer->Write(name);

    }

    virtual void ReadFrom(BinaryReader ^ reader) {
        id = reader->ReadString();
        name = reader->ReadString();
    }
};

#endif // SERVICES_H
