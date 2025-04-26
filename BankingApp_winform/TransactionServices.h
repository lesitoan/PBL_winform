#pragma once
#include "Transaction.h"
#include "TransactionsRepository.h"
#include "UserRepository.h"

#ifndef TRANSACTIONSERVICES_H
#define TRANSACTIONSERVICES_H
using namespace System;
using namespace System::IO;
using namespace System::Text::RegularExpressions;

// để return về array cho ui render
public
ref class TransactionDTO {
  private:
    User ^ fromUser;
    User ^ toUser;
    Transaction ^ transaction;

  public:
    TransactionDTO(User ^ _fromUser, User ^ _toUser,
                   Transaction ^ _transaction) {
        fromUser = _fromUser;
        toUser = _toUser;
        transaction = _transaction;
    }

    property User ^ FromUser {
        User ^ get() { return fromUser; }
    }
        property User ^
        ToUser {
            User ^ get() { return toUser; }
        } property Transaction ^
        ThisTransaction {
            Transaction ^ get() {
                return transaction;
            }
        }
};

public
ref class TransactionServices {
  public:
    static array<TransactionDTO ^> ^ GetAllTransactionData() {
        try {
            array<Transaction ^> ^ transactions = TransactionsRepository::GetAll();
            if (transactions == nullptr || transactions->Length == 0) {
                return nullptr;
            }
            array<TransactionDTO ^> ^ transactionDTOs = gcnew array<TransactionDTO ^>(transactions->Length);
            for (int i = 0; i < transactions->Length; i++) {
                User ^ sender = nullptr;
                User ^ receiver = nullptr;

                if (transactions[i]->FromUserId != nullptr) {
                    sender = UserRepository::FindById(transactions[i]->FromUserId);
                }
                if (transactions[i]->ToUserId != nullptr) {
                    receiver = UserRepository::FindById(transactions[i]->ToUserId);
                }

                if (sender == nullptr && receiver == nullptr) {
                    continue;
                }
                TransactionDTO ^ transactionDTO =
                    gcnew TransactionDTO(sender,
                                         receiver,
                                         transactions[i]);
                transactionDTOs[i] = transactionDTO;
            }
            return transactionDTOs;
        } catch (Exception ^ ex) {
            throw ex;
        }
    }

        static array<TransactionDTO ^> ^
        FindTransactionByUserName(String ^ userName) {
            try {

                if (userName == "") {
                    return gcnew array<TransactionDTO ^>(0);
                }
                array<Transaction ^> ^ transactions = TransactionsRepository::GetAll();

                if (transactions == nullptr || transactions->Length == 0) {
                    return gcnew array<TransactionDTO ^>(0);
                }

                // chuyen sang kieu class moi
                array<TransactionDTO ^> ^ transactionDTOs = gcnew array<TransactionDTO ^>(transactions->Length);
                for (int i = 0; i < transactions->Length; i++) {
                    User ^ sender = nullptr;
                    User ^ receiver = nullptr;

                    if (transactions[i]->FromUserId != nullptr) {
                        sender = UserRepository::FindById(transactions[i]->FromUserId);
                    }
                    if (transactions[i]->ToUserId != nullptr) {
                        receiver = UserRepository::FindById(transactions[i]->ToUserId);
                    }

                    if (sender == nullptr && receiver == nullptr) {
                        continue;
                    }
                    TransactionDTO ^ transactionDTO =
                        gcnew TransactionDTO(sender,
                                             receiver,
                                             transactions[i]);
                    transactionDTOs[i] = transactionDTO;
                }
                //-----------------------------

                List<TransactionDTO ^> ^ matchedTransactions = gcnew List<TransactionDTO ^>();
                for (int i = 0; i < transactionDTOs->Length; i++) {

                    String ^ pattern = ".*" + Regex::Escape(userName) + ".*";
                    // Kiểm tra tên có chứa input không (không phân biệt hoa thường)
                    bool isMatch1 = 0;
                    bool isMatch2 = 0;

                    if (transactionDTOs[i]->FromUser) {
                        isMatch1 = Regex::IsMatch(transactionDTOs[i]->FromUser->FullName, pattern,
                                                       RegexOptions::IgnoreCase);
                    }
                    if (transactionDTOs[i]->ToUser) {
                        isMatch2 = Regex::IsMatch(transactionDTOs[i]->ToUser->FullName, pattern,
                                                  RegexOptions::IgnoreCase);
                    }

                    if (isMatch1 || isMatch2) {
                        matchedTransactions->Add(transactionDTOs[i]);
                    }
                }
                if (matchedTransactions->Count == 0) {
                    return gcnew array<TransactionDTO ^>(0);
                }
                array<TransactionDTO ^> ^ result = gcnew array<TransactionDTO ^>(matchedTransactions->Count);
                for (int i = 0; i < matchedTransactions->Count; i++) {
                    result[i] = matchedTransactions[i];
                }
                return result;

            } catch (Exception ^ ex) {
                throw ex;
            }
        }

        static array<TransactionDTO ^> ^
        FindTransactionByUserId(String ^ userId) {
            try {
                array<Transaction ^> ^ transactions = TransactionsRepository::GetTransactionsByUserId(userId);
                if (transactions == nullptr || transactions->Length == 0) {
                    return nullptr;
                }

                array<TransactionDTO ^> ^ transactionDTOs = gcnew array<TransactionDTO ^>(transactions->Length);
                for (int i = 0; i < transactions->Length; i++) {
                    User ^ sender = nullptr;
                    User ^ receiver = nullptr;

                    if (transactions[i]->FromUserId != nullptr) {
                        sender = UserRepository::FindById(transactions[i]->FromUserId);
                    }
                    if (transactions[i]->ToUserId != nullptr) {
                        receiver = UserRepository::FindById(transactions[i]->ToUserId);
                    }

                    if (sender == nullptr && receiver == nullptr) {
                        continue;
                    }
                    TransactionDTO ^ transactionDTO =
                        gcnew TransactionDTO(sender,
                                             receiver,
                                             transactions[i]);
                    transactionDTOs[i] = transactionDTO;
                }
                return transactionDTOs;
            } catch (Exception ^ ex) {
                throw ex;
            }
        }

        static void InsertTransaction(String ^ fromAccNum, String ^ toAccNum, double amount, String ^ Message) {
        try {
            String ^ type = "transfer";
            Transaction ^ transaction = gcnew Transaction(fromAccNum, toAccNum, amount, Message, type);
            TransactionsRepository::InsertOne(transaction);
        } catch (Exception ^ ex) {
            throw ex;
        }
    }
};

#endif // !TRANSACTIONSERVICES_H
