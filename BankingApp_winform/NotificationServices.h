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

           const int MAX_MY_NOTIFICATIONS = 10;
           String ^ id = Utils::createUniqueID("NTF");
           String ^ createdAt = DateTime::Now.ToString("dd/MM/yyyy");
           int status = 0; // chuwa ddoc
           Notifications ^ notification =
               gcnew Notifications(id, userAccNumber, content, createdAt, status);

           // Chỉ tạo tối đa 10 thông báo mới nhất
           array<Notifications ^> ^ myNotifications = NotificationsServices::GetNotificationsByUserAccNumber(userAccNumber);

           if (myNotifications != nullptr && myNotifications->Length >= MAX_MY_NOTIFICATIONS) {
               // Sắp xếp tăng dần theo ngày tạo 
               array<Notifications ^> ^ sorted = gcnew array<Notifications ^>(myNotifications->Length);
               Array::Copy(myNotifications, sorted, myNotifications->Length);

 
               Array::Sort(sorted, gcnew Comparison<Notifications ^>(&NotificationsServices::CompareNotificationsByDate));

               // thay thế cái cũ nhất
               NotificationsRepository::UpdateById(sorted[0]->NotificationId, notification);
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

               // Sắp xếp theo ngày tạo giảm dần
               array<Notifications ^> ^ sorted = gcnew array<Notifications ^>(filteredNotifications->Count);
               Array::Copy(filteredNotifications->ToArray(), sorted, filteredNotifications->Count);
               Array::Sort(sorted, gcnew Comparison<Notifications ^>(&NotificationsServices::CompareNotificationsByDate));

               return sorted;

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

 private:
   static int CompareNotificationsByDate(Notifications ^ a, Notifications ^ b) {
       DateTime d1 = DateTime::ParseExact(a->CreatedAt, "dd/MM/yyyy", nullptr);
       DateTime d2 = DateTime::ParseExact(b->CreatedAt, "dd/MM/yyyy", nullptr);
       return DateTime::Compare(d1, d2);
   }

};

#endif // !NOTIFICATIONSERVICES_H
