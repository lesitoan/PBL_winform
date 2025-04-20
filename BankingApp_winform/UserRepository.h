#include "HandleFile.h"
#include "User.h"

#ifndef USERREPONSITORY_H
#define USERREPONSITORY_H

using namespace System;
using namespace System::IO;

public
ref class UserRepository {
  private:
    static array<User ^> ^ usersCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;

    static UserRepository() {
        usersCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "users.dat";
    }

    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime = HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                usersCache = HandleFile::ReadArrayFromFile<User ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<User ^> ^ GetUsers() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();

            return usersCache;

        } catch (Exception ^ ex) {
            throw gcnew Exception("getUsers error !!!", ex);
        }
    }

        static void UpdateUserByAccNumber(String ^ accNumber, User ^ user) {
        try {

            CheckLastUpdateTime();

            if (usersCache == nullptr) {
                return;
            }
            for (int i = 0; i < usersCache->Length; i++) {
                if (usersCache[i]->getAccountNumber() == accNumber) {
                    usersCache[i] = user;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<User ^>(usersCache, fileName);

            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);

        } catch (Exception ^ ex) {
            throw gcnew Exception("updateUserByAccNumber error !!!", ex);
        }
    }

    static void InsertUser(User ^ user) {
        try {
            CheckLastUpdateTime();

            if (usersCache == nullptr) {
                usersCache = gcnew array<User ^>(0);
            }
            array<User ^> ^ newUsersCache = gcnew array<User ^>(usersCache->Length + 1);
            for (int i = 0; i < usersCache->Length; i++) {
                newUsersCache[i] = usersCache[i];
            }
            newUsersCache[usersCache->Length] = user;
            usersCache = newUsersCache;
            HandleFile::WriteArrayToFile<User ^>(usersCache, fileName);

            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("addUser error !!!", ex);
        }
    }

    static User ^ FindUserByPhoneNumber(String ^ phoneNumber) {
        try {
            CheckLastUpdateTime();

            if (usersCache == nullptr) {
                return nullptr;
            }
            for (int i = 0; i < usersCache->Length; i++) {
                if (usersCache[i]->getPhoneNumber() == phoneNumber) {
                    return usersCache[i];
                }
            }
            return nullptr;
        } catch (Exception ^ ex) {
            throw gcnew Exception("findUserByPhoneNumber error !!!", ex);
        }
    }

        static User
        ^ FindUserByAccNumber(String ^ accNumber) {
              try {
                  CheckLastUpdateTime();
                  if (usersCache == nullptr) {
                      return nullptr;
                  }
                  for (int i = 0; i < usersCache->Length; i++) {
                      if (usersCache[i]->getAccountNumber() == accNumber) {
                          return usersCache[i];
                      }
                  }
                  return nullptr;
              } catch (Exception ^ ex) {
                  throw gcnew Exception("findUserByAccNumber error !!!", ex);
              }
          }

        static void DeteteCache() {
        usersCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "users.dat";
    }
};

#endif // USERREPONSITORY_H;
