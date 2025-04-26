#include "BaseEntity.h"

#ifndef SERVICES_H
#define SERVICES_H

using namespace System;
using namespace System::IO;

public
ref class Services : public BaseEntity {
  private:
    String ^ name;

    public:
    Services(String ^ id, DateTime createAt, DateTime updatedAt, String ^ name)
          : BaseEntity(id, createAt, updatedAt)
    {
          this->name = name;
    }
    Services()
        : BaseEntity()
    {
        name = "";
    }
    Services(String ^ name)
        : BaseEntity() {
        this->name = name;
    }

    property String ^ Name {
        String ^ get() { return name; }
        void set(String ^ value) {
            name = value;
        }
    }
    virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(name);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        name = reader->ReadString();
    }
};

#endif // SERVICES_H
