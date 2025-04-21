#pragma once
#include "ServicesRepository.h"
#include "UserRepository.h"
#include "Utils.h"

#ifndef SERVICESERVICES_H
#define SERVICESERVICES_H

using namespace System;
using namespace System::IO;

public
ref class ServiceServices {
  public:
    static void InsertService(String ^ name) {
        try {
            if (name == "") {
                throw gcnew Exception(L"Vui lòng nhập đầy đủ thông tin");
            }
            // kieemr tra xem dịch vụ đã tồn tại chưa
            Services ^ currentService = ServicesRepository::FindServiceByName(name);
            if (currentService != nullptr) {
                throw gcnew Exception(L"Dịch vụ đã tồn tại");
            }

            String ^ id = Utils::createUniqueID("SER");
            Services ^ newService = gcnew Services(id, name);
            ServicesRepository::InsertService(newService);
            
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
    static array<Services ^> ^ GetAllServices() {
        try {
            return ServicesRepository::GetAll();
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void DeleteServiceById(String ^ id) {
        try {
            if (id == "") {
                throw gcnew Exception(L"Không có thông tin dịch vụ");
            }
            // chỉ xóa khi không có công ty nào sử dụng dịch vụ này
            array<User ^> ^ users = UserRepository::GetUsers();
            if (users == nullptr || users->Length == 0) {
                return;
            }
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getServiceId() == id) {
                    throw gcnew Exception(L"Dịch vụ này đang được sử dụng, không thể xóa");
                }
            }
            ServicesRepository::DeleteById(id);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};
#endif // !SERVICESERVICES_H
