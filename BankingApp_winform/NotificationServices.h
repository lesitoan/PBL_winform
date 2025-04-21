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

            const int MAX_NOTIFICATIONS = 10;
            String ^ id = Utils::createUniqueID("NTF");
            String ^ createdAt = DateTime::Now.ToString("dd/MM/yyyy");
            int status = 0; // chuwa ddoc
            Notifications ^ notification =
                gcnew Notifications(id, userAccNumber, content, createdAt, status);

            // Chỉ tạo tối đa 10 thông báo mới nhất
            array<Notifications ^> ^ myNotifications = NotificationsServices::GetNotificationsByUserAccNumber(userAccNumber);

            if (myNotifications != nullptr && myNotifications->Length >= MAX_NOTIFICATIONS) {
                for (int i = 0; i < myNotifications->Length - 1; i++) {
                    myNotifications[i] = myNotifications[i + 1];
                }
                myNotifications[myNotifications->Length - 1] = notification;
                NotificationsRepository::UpdateAll(myNotifications);
            }

            NotificationsRepository::InsertOne(notification);
        } catch (Exception ^ ex) {
            MessageBox::Show(ex->ToString(), L"Lỗi", MessageBoxButtons::OK,
                             MessageBoxIcon::Error);
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

        static array<Notifications ^> ^
        GetNotificationsByUserAccNumber(String ^ userAccNumber) {
            try {
                array<Notifications ^> ^ allNotifications =
                    NotificationsRepository::GetAll();
                if (allNotifications == nullptr) {
                    return nullptr;
                }

                List<Notifications ^> ^ filteredNotifications = gcnew List<Notifications ^>();
                for (int i = 0; i < allNotifications->Length; i++) {
                    if (allNotifications[i]->UserAccNumber == userAccNumber) {
                        filteredNotifications->Add(allNotifications[i]);
                    }
                }
                if (filteredNotifications->Count == 0) {
                    return nullptr;
                }
                return filteredNotifications->ToArray();

            } catch (Exception ^ ex) {
                throw ex;
            }
        }

        static void UpdateNotificationStatus(String ^ id, int status) {
        try {
            Notifications ^ notification = nullptr;
            array<Notifications ^> ^ allNotifications = NotificationsRepository::GetAll();
            if (allNotifications == nullptr) {
                return;
            }
            for (int i = 0; i < allNotifications->Length; i++) {
                if (allNotifications[i]->NotificationId == id) {
                    notification = allNotifications[i];
                    break;
                }
            }
            if (notification != nullptr) {
                notification->Status = status;
                NotificationsRepository::UpdateById(id, notification);
            }
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !NOTIFICATIONSERVICES_H
