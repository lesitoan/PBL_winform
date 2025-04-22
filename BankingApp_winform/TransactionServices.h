#pragma once
#include "Transaction.h"
#include "TransactionsRepository.h"
#include "Utils.h"

#ifndef TRANSACTIONSERVICES_H
#define TRANSACTIONSERVICES_H
using namespace System;
using namespace System::IO;
using namespace System::Text::RegularExpressions;

public
ref class TransactionServices {
  public:
    static array<Transaction^>^ FindTransactionByAccNum(String ^ accNum) {
        try {
            array<Transaction ^> ^ transactions = TransactionsRepository::GetAll();


            if (transactions == nullptr || transactions->Length == 0) {
                throw gcnew Exception(L"Không tìm thấy giao dịch nào");
                //return gcnew array<Transaction ^>(0);
            }

            if (accNum == "") {
                return transactions;
            }

            List<Transaction ^> ^ matchedTransactions = gcnew List<Transaction ^>();
            for (int i = 0; i < transactions->Length; i++) {
                String ^ pattern = ".*" + Regex::Escape(accNum) + ".*";

                bool isMatch1 =
                    Regex::IsMatch(transactions[i]->getFromAccount(),
                                   pattern, RegexOptions::IgnoreCase);
                bool isMatch2 =
                    Regex::IsMatch(transactions[i]->getToAccount(), pattern,
                                   RegexOptions::IgnoreCase);

                if (isMatch1 || isMatch2) {
                    matchedTransactions->Add(transactions[i]);
                }
            }
            if (matchedTransactions->Count == 0) {
                throw gcnew Exception(L"Không tìm thấy giao dịch nào");
                //return gcnew array<Transaction ^>(0);
            }
            array<Transaction ^> ^ result = gcnew array<Transaction ^>(matchedTransactions->Count);
            for (int i = 0; i < matchedTransactions->Count; i++) {
                result[i] = matchedTransactions[i];
            }
            return result;

        } catch (Exception ^ ex) {
            throw ex;
        }
    }

    static void InsertTransaction(String^ fromAccNum, String^ toAccNum, double amount, String^ Message) {
        try {
            String ^ transactionId = Utils::createUniqueID("TR");
            String ^ createdAt = DateTime::Now.ToString("dd/MM/yyyy");
            Transaction ^ transaction = gcnew Transaction(transactionId, fromAccNum, toAccNum, amount, Message, createdAt);
            TransactionsRepository::InsertOne(transaction);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

};


#endif // !TRANSACTIONSERVICES_h
