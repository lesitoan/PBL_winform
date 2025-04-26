#include "BaseEntity.h"

#ifndef CUSTOMERCODES_H
#define CUSTOMERCODES_H

using namespace System;

public
ref class CustomerCodes : public BaseEntity {
  private:

    String ^ companyId;
    String ^ code;
    int status; // 1: còn hoạt động, 0: đã đóng

  public:
    CustomerCodes(String ^ id, DateTime createAt, DateTime updatedAt, String ^ companyId, String ^ code,
                  int status)
        : BaseEntity(id, createAt, updatedAt)
    {
        this->companyId = companyId;
        this->code = code;
        this->status = status;
    }

    CustomerCodes(String ^ companyId, String ^ code)
        : BaseEntity()
    {
        this->companyId = companyId;
        this->code = code;
        this->status = 1;
    }

    CustomerCodes()
        : BaseEntity() {
        this->companyId = "";
        this->code = "";
        this->status = 1;
    }

    property String ^
        CompanyId {
            String ^ get() { return companyId; }
        }
    property String ^
        Code {
            String ^ get() { return code; } void set(String ^ value) {
                code = value;
            }
        }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }

    virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(companyId);
        writer->Write(code);
        writer->Write(status);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        companyId = reader->ReadString();
        code = reader->ReadString();
        status = reader->ReadInt32();
    }
};

#endif // CUSTOMERCODES_H
