#pragma once

#include "HandleFile.h"
#include "Transaction.h"
#include "BaseRepository.h"
#include "ENV.h"

#ifndef TRANSACTIONREPOSITORY_H
#define TRANSACTIONREPOSITORY_H

using namespace System;
using namespace System::IO;

public
ref class TransactionsRepository : public BaseRepository<Transaction ^> {
  private:
    static TransactionsRepository() {
            InitializeRepository(ENV::TRANSACTION_FILE);
    }

  public:
    static array<Transaction ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();

            return cache;

        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

        static array<Transaction ^> ^
        GetTransactionsByUserId(String ^ userId) {
            try {
                CheckLastUpdateTime();

                if (cache == nullptr) {
                    return nullptr;
                }

                List<Transaction ^> ^ transactionsList = gcnew List<Transaction ^>();

                for (int i = 0; i < cache->Length; i++) {
                    if (cache[i]->FromUserId == userId ||
                        cache[i]->ToUserId== userId){
                        transactionsList->Add(cache[i]);
                    }
                }

                return transactionsList->ToArray();
            } catch (Exception ^ ex) {
                throw gcnew Exception("GetTransactionsByUserId error !!!", ex);
            }
        }

        static void InsertOne(Transaction ^ transaction) {
        try {
            CheckLastUpdateTime();

            if (cache == nullptr) {
                cache = gcnew array<Transaction ^>(0);
            }

            array<Transaction ^> ^ newcache =
                gcnew array<Transaction ^>(cache->Length + 1);
            for (int i = 0; i < cache->Length; i++) {
                newcache[i] = cache[i];
            }
            newcache[cache->Length] = transaction;
            cache = newcache;
            HandleFile::WriteArrayToFile<Transaction ^>(cache, fileName);
            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }

    static void UpdateById(String ^ transactionId, Transaction ^ transaction) {
        try {
            CheckLastUpdateTime();

            if (cache == nullptr) {
                return;
            }

            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id == transactionId) {
                    cache[i] = transaction;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<Transaction ^>(cache, fileName);
            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateTransactionById error !!!", ex);
        }
    }

};
#endif // TRANSACTIONREPOSITORY_H;