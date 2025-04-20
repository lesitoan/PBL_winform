#pragma once
#include "Notifications.h"
#include "NotificationsRepository.h"
#include "Utils.h"

#ifndef NOTIFICATIONSERVICES_H
#define NOTIFICATIONSERVICES_H
using namespace System;
using namespace System::IO;

public
ref class NotificationsServices {
  public:
    static void InsertNotification(String ^ userAccNumber, String ^ content) {
        try {
            String ^ id = Utils::createUniqueID("NTF");
            String ^ createdAt = DateTime::Now.ToString("dd/MM/yyyy");
            int status = 0; //chuwa ddoc
            Notifications ^ notification =
                gcnew Notifications(id, userAccNumber, content, createdAt, status);
            NotificationsRepository::InsertOne(notification);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
    static array<Notifications ^> ^ GetAllNotifications() {
        try {
            return NotificationsRepository::GetAll();
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};


#endif // !NOTIFICATIONSERVICES_H
