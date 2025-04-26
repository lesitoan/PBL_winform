#pragma once

#include "HandleFile.h"
#include "Transaction.h"

#ifndef TRANSACTIONREPOSITORY_H
#define TRANSACTIONREPOSITORY_H

using namespace System;
using namespace System::IO;

public
ref class TransactionsRepository {
  private:
    static array<Transaction ^> ^ transactionsCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;

    static TransactionsRepository() {
        transactionsCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "transactions.dat";
    }

    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime = HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                transactionsCache = HandleFile::ReadArrayFromFile<Transaction ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<Transaction ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();

            return transactionsCache;

        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

        static array<Transaction ^> ^
        GetTransactionsByUserId(String ^ userId) {
            try {
                CheckLastUpdateTime();

                if (transactionsCache == nullptr) {
                    return nullptr;
                }

                List<Transaction ^> ^ transactionsList = gcnew List<Transaction ^>();

                for (int i = 0; i < transactionsCache->Length; i++) {
                    if (transactionsCache[i]->FromUserId == userId ||
                        transactionsCache[i]->ToUserId== userId){
                        transactionsList->Add(transactionsCache[i]);
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

            if (transactionsCache == nullptr) {
                transactionsCache = gcnew array<Transaction ^>(0);
            }

            array<Transaction ^> ^ newTransactionsCache =
                gcnew array<Transaction ^>(transactionsCache->Length + 1);
            for (int i = 0; i < transactionsCache->Length; i++) {
                newTransactionsCache[i] = transactionsCache[i];
            }
            newTransactionsCache[transactionsCache->Length] = transaction;
            transactionsCache = newTransactionsCache;
            HandleFile::WriteArrayToFile<Transaction ^>(transactionsCache, fileName);
            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }

    static void UpdateById(String ^ transactionId, Transaction ^ transaction) {
        try {
            CheckLastUpdateTime();

            if (transactionsCache == nullptr) {
                return;
            }

            for (int i = 0; i < transactionsCache->Length; i++) {
                if (transactionsCache[i]->Id == transactionId) {
                    transactionsCache[i] = transaction;
                    break;
                }
            }
            HandleFile::WriteArrayToFile<Transaction ^>(transactionsCache, fileName);
            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateTransactionById error !!!", ex);
        }
    }

    static void DeleteCache() {
        try {
            transactionsCache = nullptr;
            lastReadTime = DateTime::MinValue;
            fileName = "transactions.dat";
        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteCache error !!!", ex);
        }
    };
};
#endif // TRANSACTIONREPOSITORY_H;