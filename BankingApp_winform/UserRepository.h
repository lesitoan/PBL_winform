#include "HandleFile.h"
#include "User.h"
#include "BaseRepository.h"
#include "ENV.h"

#ifndef USERREPONSITORY_H
#define USERREPONSITORY_H

using namespace System;
using namespace System::IO;

public
ref class UserRepository : public BaseRepository<User ^> {
  private:

    static UserRepository() {
        InitializeRepository(ENV::USER_FILE);
    }

  public:
    static array<User ^> ^ GetUsers() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();

            return cache;

        } catch (Exception ^ ex) {
            throw gcnew Exception("getUsers error !!!", ex);
        }
    }

    static void UpdateById(String ^ id, User ^ user) {
        try {
            if (cache == nullptr) {
                return;
            }
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id == id) {
                    cache[i] = user;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<User ^>(cache, fileName);

            //HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("updateById error !!!", ex);
        }
    }

    static void InsertUser(User ^ user) {
        try {
            CheckLastUpdateTime();

            if (cache == nullptr) {
                cache = gcnew array<User ^>(0);
            }
            array<User ^> ^ newcache = gcnew array<User ^>(cache->Length + 1);
            for (int i = 0; i < cache->Length; i++) {
                newcache[i] = cache[i];
            }
            newcache[cache->Length] = user;
            cache = newcache;
            HandleFile::WriteArrayToFile<User ^>(cache, fileName);

            // update lại thời gian chỉnh sửa file
            //HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("addUser error !!!", ex);
        }
    }

    static User ^ FindUserByPhoneNumber(String ^ phoneNumber) {
        try {
            CheckLastUpdateTime();

            if (cache == nullptr) {
                return nullptr;
            }
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->getPhoneNumber() == phoneNumber) {
                    return cache[i];
                }
            }
            return nullptr;
        } catch (Exception ^ ex) {
            throw gcnew Exception("findUserByPhoneNumber error !!!", ex);
        }
    }

        static User^ FindById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return nullptr;
            }
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id == id) {
                    return cache[i];
                }
            }
            return nullptr;
        } catch (Exception ^ ex) {
            throw gcnew Exception("findById error !!!", ex);
        }
    }

};

#endif // USERREPONSITORY_H;
