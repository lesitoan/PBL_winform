#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

using namespace System;

public
ref class Notifications {
    private:
    int notificationId;
    int userAccNumber;
    String ^ content;
    String ^ createdAt;
    int status; // 0: unread, 1: read

  public:
    Notifications(int _notificationId, int _userAccNumber, String ^ _content,
                  String ^ _createdAt, int _status) {
        notificationId = _notificationId;
        userAccNumber = _userAccNumber;
        content = _content;
        createdAt = _createdAt;
        status = _status;
    }
    Notifications() : Notifications(0, 0, "", "", 0) {};
    Notifications(const Notifications % other) {
        notificationId = other.notificationId;
        userAccNumber = other.userAccNumber;
        content = other.content;
        createdAt = other.createdAt;
        status = other.status;
    }
    property int NotificationId {
        int get() { return notificationId; }
    }
    property int UserAccNumber {
        int get() { return userAccNumber; }
    }
    property String ^ Content {
        String ^ get() { return content; } void set(String ^ value) {
            content = value;
        }
    }
    property String ^
        CreatedAt {
            String ^ get() { return createdAt; } void set(String ^ value) {
                createdAt = value;
            }
    } 
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }

  };

#endif