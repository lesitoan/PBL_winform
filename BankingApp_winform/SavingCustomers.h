

#ifndef SAVINGCUSTOMERS_H
#define SAVINGCUSTOMERS_H

using namespace System;

public
ref class SavingCustomers {
  private:
    String ^ id;
    String ^ userAccountNumber; // so tai khoan khach hang
    double amount;
    double interestAmount;
    String ^ type; // termDeposit, nonTermDeposit
    int  term;
    float interestRate; 
    DateTime depositDate;
    String^ paymentDate; // khoi tao bang "", vì chưa thanh toán
    int status; // 0: chưa thanh toán, 1: đã thanh toán, 2 đang yêu cầu

  public:
    SavingCustomers(String ^ _id, String^ _accNumber, double _amount, double _interserAmount, String^ _type, int _term,
                    float _rate,
                    DateTime _depositDate, String^ _paymentDate, int _status) {
        id = _id;
        userAccountNumber = _accNumber;
        amount = _amount;
        interestAmount = _interserAmount;
        type = _type;
        term = _term;
        interestRate = _rate;
        depositDate = _depositDate;
        paymentDate = _paymentDate;
        status = _status;
    }
    SavingCustomers()
        : SavingCustomers("", "", 0, 0, "", 0, 0, DateTime::Now, "", 0) {};

    SavingCustomers(String^ _id,String^ _accNumber,  double _amount, String^ _type, int _term) {
        id = _id;
        userAccountNumber = _accNumber;
        amount = _amount;
        interestAmount = 0;
        type = _type;
        term = _term;
        if (type == "nonTermDeposit") {
            interestRate = 0.04;
        } else {
            if (term == 3)
                interestRate = 0.045;
            else if (term == 6)
                interestRate = 0.05;
            else if (term == 9)
                interestRate = 0.055;
            else if (term == 12)
                interestRate = 0.06;
        }
        depositDate = DateTime::Now;
        paymentDate = "";
        status = 0;
    }
    property String ^ Id {
        String ^ get() { return id; }
    } property String ^
        UserAccountNumber {
            String ^
                get() { return userAccountNumber; } 
        }
    property double Amount {
        double get() { return amount; }
    }
    property double InterestAmount {
        double get() { return interestAmount; }
        void set(double value) { interestAmount = value; }
    }
    property String ^ Type {
        String ^ get() { return type; }
    }
    property int Term {
        int get() { return term; }
    }
    property float InterestRate {
        float get() { return interestRate; }
    }
    property DateTime DepositDate {
        DateTime get() { return depositDate; }
    }
    property String ^ PaymentDate {
        String ^ get() { return paymentDate; }
        void set(String ^ value) {
            paymentDate = value;
        }
    }
    property int Status {
        int get() { return status; }
        void set(int value) { status = value; }
    }
};

#endif // SAVINGCUSTOMERS_H
