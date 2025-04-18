#include "ISaveToFile.h"

#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

using namespace System;

public
ref class Notifications : public ISaveToFile {
  private:
    String ^ notificationId;
    String ^ userAccNumber;
    String ^ content;
    String ^ createdAt;
    int status; // 0: unread, 1: read

  public:
    Notifications(String ^ _notificationId, String ^ _userAccNumber,
                  String ^ _content, String ^ _createdAt, int _status) {
        notificationId = _notificationId;
        userAccNumber = _userAccNumber;
        content = _content;
        createdAt = _createdAt;
        status = _status;
    }
    Notifications() : Notifications("", "", "", "", 0) {};
    Notifications(const Notifications % other) {
        notificationId = other.notificationId;
        userAccNumber = other.userAccNumber;
        content = other.content;
        createdAt = other.createdAt;
        status = other.status;
    }
    property String ^
        NotificationId {
            String ^ get() { return notificationId; }
        } property String ^
        UserAccNumber {
            String ^ get() { return userAccNumber; }
        } property String ^
        Content {
            String ^ get() { return content; } void set(String ^ value) {
                content = value;
            }
        } property String ^
        CreatedAt {
            String ^ get() { return createdAt; } void set(String ^ value) {
                createdAt = value;
            }
        } property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }

    virtual void WriteTo(BinaryWriter ^ writer) {
        writer->Write(notificationId);
        writer->Write(userAccNumber);
        writer->Write(content);
        writer->Write(createdAt);
        writer->Write(status);
    }

    virtual void ReadFrom(BinaryReader ^ reader) {
        notificationId = reader->ReadString();
        userAccNumber = reader->ReadString();
        content = reader->ReadString();
        createdAt = reader->ReadString();
        status = reader->ReadInt32();
    }
};

#endif