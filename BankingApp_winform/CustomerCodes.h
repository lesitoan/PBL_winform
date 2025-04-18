#include "ISaveToFile.h"

#ifndef CUSTOMERCODES_H
#define CUSTOMERCODES_H

using namespace System;

public
ref class CustomerCodes : public ISaveToFile {
  private:
    String ^ id;
    String ^ companyAccountNumber;

    String ^ code;
    int status; // 1: còn hoạt động, 0: đã đóng
    DateTime createdDate;

  public:
    CustomerCodes(String ^ id, String ^ companyAccountNumber, String ^ code,
                  int status, DateTime createdDate) {
        this->id = id;
        this->companyAccountNumber = companyAccountNumber;
        this->code = code;
        this->status = status;
        this->createdDate = createdDate;
    }
    CustomerCodes(String ^ id, String ^ companyAccountNumber, String ^ code) {
        this->id = id;
        this->companyAccountNumber = companyAccountNumber;
        this->code = code;
        this->status = 1;
        this->createdDate = DateTime::Now;
    }
    CustomerCodes() {
        this->id = "";
        this->companyAccountNumber = "";
        this->code = "";
        this->status = 1;
        this->createdDate = DateTime::Now;
    }

    property String ^ Id { String ^ get() { return id; } } property String ^
        CompanyAccountNumber {
            String ^ get() { return companyAccountNumber; }
        } property String ^
        Code {
            String ^ get() { return code; } void set(String ^ value) {
                code = value;
            }
        } property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }
    property DateTime CreatedDate {
        DateTime get() { return createdDate; }
    }

    virtual void WriteTo(BinaryWriter ^ writer) {
        writer->Write(id);
        writer->Write(companyAccountNumber);
        writer->Write(code);
        writer->Write(status);
        writer->Write(createdDate.ToString("yyyy-MM-dd HH:mm:ss"));
    }

    virtual void ReadFrom(BinaryReader ^ reader) {
        id = reader->ReadString();
        companyAccountNumber = reader->ReadString();
        code = reader->ReadString();
        status = reader->ReadInt32();
        createdDate = DateTime::Parse(reader->ReadString());
    }
};

#endif // CUSTOMERCODES_H
