#pragma once
#include "HandleFile.h"
#include "RecurringPayments.h"
#include "BaseRepository.h"
#include "ENV.h"

//#ifndef RECURRINGPAYMENTS_H
//#define RECURRINGPAYMENTS_H

using namespace System;
using namespace System::IO;

public
ref class RecurringPaymentsRepository : public BaseRepository<RecurringPayments ^> {
  private:

    static RecurringPaymentsRepository() {
        InitializeRepository(ENV::RECURRING_PAYMENT_FILE);
    }

  public:
    static array<RecurringPayments ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return cache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static void InsertOne(RecurringPayments ^ recurringPayments) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                cache = gcnew array<RecurringPayments ^>(0);
            }
            array<RecurringPayments ^> ^ newcache =
                gcnew array<RecurringPayments ^>(
                    cache->Length + 1);

            for (int i = 0; i < cache->Length; i++) {
                newcache[i] = cache[i];
            }
            newcache[cache->Length] =
                recurringPayments;
            cache = newcache;
            HandleFile::WriteArrayToFile<RecurringPayments ^>(
                cache, fileName);

            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }
    static void DeleteById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (cache == nullptr) {
                return;
            }
            List<RecurringPayments ^> ^ recurringPaymentsList =
                gcnew List<RecurringPayments ^>();
            for (int i = 0; i < cache->Length; i++) {
                if (cache[i]->Id != id) {
                    recurringPaymentsList->Add(cache[i]);
                }
            }
            if (recurringPaymentsList->Count == cache->Length) {
                return;
            }
            cache = recurringPaymentsList->ToArray();
            HandleFile::WriteArrayToFile<RecurringPayments ^>(
                cache, fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteById error !!!", ex);
        }
    }

    static RecurringPayments ^ GetOneById(String ^ id) {
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
            throw gcnew Exception("GetOneById error !!!", ex);
        }
    }

};

//#endif // RECURRINGPAYMENTS_H


