#include "BaseEntity.h"

#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

using namespace System;

public
ref class Notifications : public BaseEntity {
  private:
    String ^ userId;
    String ^ content;
    int status; // 0: unread, 1: read

  public:
    Notifications(String ^ id, DateTime createAt, DateTime updatedAt, String ^ _userId,
                  String ^ _content, int _status)
        : BaseEntity(id, createAt, updatedAt)
    {
        userId = _userId;
        content = _content;
        status = _status;
    }

    Notifications(String ^ _userId, String ^ _content)
        : BaseEntity()
    {
        userId = _userId;
        content = _content;
        status = 0;
    }

    Notifications()
        : Notifications("", DateTime::MinValue, DateTime::MinValue ,"", "", 0) {};


    property String ^
        UserId {
            String ^ get() { return userId; }
        }
    property String ^
        Content {
            String ^ get() { return content; } void set(String ^ value) {
                content = value;
            }
        }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }

    virtual void WriteTo(BinaryWriter ^ writer) override {
        BaseEntity::WriteTo(writer);

        writer->Write(userId);
        writer->Write(content);
        writer->Write(status);
    }

    virtual void ReadFrom(BinaryReader ^ reader) override {
        BaseEntity::ReadFrom(reader);

        userId = reader->ReadString();
        content = reader->ReadString();
        status = reader->ReadInt32();
    }
};

#endif