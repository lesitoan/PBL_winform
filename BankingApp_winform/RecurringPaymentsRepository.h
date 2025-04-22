#pragma once
#include "HandleFile.h"
#include "RecurringPayments.h"

//#ifndef RECURRINGPAYMENTS_H
//#define RECURRINGPAYMENTS_H

using namespace System;
using namespace System::IO;

public
ref class RecurringPaymentsRepository {
  private:
    static array<RecurringPayments ^> ^ recurringPaymentsCache;
    static DateTime lastReadTime = DateTime::MinValue;
    static String ^ fileName;

    static RecurringPaymentsRepository() {
        recurringPaymentsCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "recurringpayments.dat";
    }

    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime =
                HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                recurringPaymentsCache =
                    HandleFile::ReadArrayFromFile<RecurringPayments ^>(fileName);
                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static array<RecurringPayments ^> ^ GetAll() {
        try {
            // kiểm tra lần chỉnh sửa cuối cùng của file
            CheckLastUpdateTime();
            return recurringPaymentsCache;
        } catch (Exception ^ ex) {
            throw gcnew Exception("getAll transaction error !!!", ex);
        }
    }

    static void InsertOne(RecurringPayments ^ recurringPayments) {
        try {
            CheckLastUpdateTime();
            if (recurringPaymentsCache == nullptr) {
                recurringPaymentsCache = gcnew array<RecurringPayments ^>(0);
            }
            array<RecurringPayments ^> ^ newRecurringPaymentsCache =
                gcnew array<RecurringPayments ^>(
                    recurringPaymentsCache->Length + 1);

            for (int i = 0; i < recurringPaymentsCache->Length; i++) {
                newRecurringPaymentsCache[i] = recurringPaymentsCache[i];
            }
            newRecurringPaymentsCache[recurringPaymentsCache->Length] =
                recurringPayments;
            recurringPaymentsCache = newRecurringPaymentsCache;
            HandleFile::WriteArrayToFile<RecurringPayments ^>(
                recurringPaymentsCache, fileName);

            // update lại thời gian chỉnh sửa file
            HandleFile::UpdateFilehistoryUpdate(fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("InsertOne transaction error !!!", ex);
        }
    }
    static void DeleteById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (recurringPaymentsCache == nullptr) {
                return;
            }
            List<RecurringPayments ^> ^ recurringPaymentsList =
                gcnew List<RecurringPayments ^>();
            for (int i = 0; i < recurringPaymentsCache->Length; i++) {
                if (recurringPaymentsCache[i]->Id != id) {
                    recurringPaymentsList->Add(recurringPaymentsCache[i]);
                }
            }
            if (recurringPaymentsList->Count == recurringPaymentsCache->Length) {
                return;
            }
            recurringPaymentsCache = recurringPaymentsList->ToArray();
            HandleFile::WriteArrayToFile<RecurringPayments ^>(
                recurringPaymentsCache, fileName);
        } catch (Exception ^ ex) {
            throw gcnew Exception("DeleteById error !!!", ex);
        }
    }

    static RecurringPayments ^ GetOneById(String ^ id) {
        try {
            CheckLastUpdateTime();
            if (recurringPaymentsCache == nullptr) {
                return nullptr;
            }
            for (int i = 0; i < recurringPaymentsCache->Length; i++) {
                if (recurringPaymentsCache[i]->Id == id) {
                    return recurringPaymentsCache[i];
                }
            }
            return nullptr;
        } catch (Exception ^ ex) {
            throw gcnew Exception("GetOneById error !!!", ex);
        }
    }

    static void DeleteCache() {
        recurringPaymentsCache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "recurringpayments.dat";
    }

};

//#endif // RECURRINGPAYMENTS_H


