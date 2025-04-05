#include "HandleFile.h"

bool HandleFile::WriteUserArray(array<User^>^ users, String^ filePath) {
    try {
        FileStream^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter^ writer = gcnew BinaryWriter(fs);
        writer->Write(users->Length);
        for each (User ^ user in users) {
            writer->Write(user->getFullName());
            writer->Write(user->getPassword());
            writer->Write(user->getPhoneNumber());
            writer->Write(user->getAccountNumber());
            writer->Write(user->getBalance());
            writer->Write(user->getRole());
            writer->Write(user->getPin());
            writer->Write(user->getBankName());
            writer->Write(user->Status);
            writer->Write(user->getServiceId());
            writer->Write(user->UrlAvatar);
        }
        writer->Close();
        fs->Close(); 
        return true;
    }
    catch (Exception^)
    {
        //MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return false;
    }
}

array<User^>^ HandleFile::ReadUserArray(String^ filePath)
{
    try
    {
        if (!File::Exists(filePath)) {
            return gcnew array<User ^>(
                0); 
        }


        FileStream^ fs = gcnew FileStream(filePath, FileMode::OpenOrCreate);
        BinaryReader^ reader = gcnew BinaryReader(fs);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<User ^>(0);
        }

        int count = reader->ReadInt32();
        array<User^>^ users = gcnew array<User^>(count);

        for (int i = 0; i < count; i++)
        {
            String^ _fullName = reader->ReadString();
            String ^ _password = reader->ReadString();
            String ^ _phoneNumber = reader->ReadString();
            String ^ _accountNumber = reader->ReadString();
            double _balance = reader->ReadDouble();
            String ^ _role = reader->ReadString();
            int _pin = reader->ReadInt32();
            String ^ _bankName = reader->ReadString();
            int _status = reader->ReadInt32();
            String ^ _serviceId = reader->ReadString();
            String ^ _urlAvatar = reader->ReadString();


            users[i] = gcnew User(_fullName, _password, _phoneNumber, _accountNumber, _balance, _role, _pin,
                                  _bankName, _status, _serviceId, _urlAvatar);
        }
        reader->Close();
        fs->Close(); 
        return users;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return nullptr;
    }
}

array<Transaction ^> ^ HandleFile::ReadTransactionArray(String ^ filePath) {
    try {

        if (!File::Exists(filePath)) {
            return gcnew array<Transaction ^>(0);
        }

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Open);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        int count = reader->ReadInt32();
        array<Transaction ^> ^ transactions = gcnew array<Transaction ^>(count);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<Transaction ^>(0);
        }

        for (int i = 0; i < count; i++) {
            String ^ _transactionId = reader->ReadString();
            String ^ _fromAccountNumber = reader->ReadString();
            String ^ _toAccountNumber = reader->ReadString();
            double _amount = reader->ReadDouble();
            String ^ _message = reader->ReadString();
            String ^ _createdAt = reader->ReadString();
            transactions[i] =
                gcnew Transaction(_transactionId, _fromAccountNumber,
                                  _toAccountNumber, _amount,_message, _createdAt);
        }
        reader->Close();
        fs->Close(); 
        return transactions;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return nullptr;
    }
}

bool HandleFile::WriteTransactionArray(array<Transaction ^> ^ transactions,
                                       String ^ filePath) {
    try {

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter ^ writer = gcnew BinaryWriter(fs);
        writer->Write(transactions->Length);
        for each (Transaction ^ transaction in transactions) {
            writer->Write(transaction->getTransactionId());
            writer->Write(transaction->getFromAccount());
            writer->Write(transaction->getToAccount());
            writer->Write(transaction->getAmount());
            writer->Write(transaction->getMessage());
            writer->Write(transaction->getCreatedAt());
        }
        writer->Close();
        fs->Close(); 
        return true;
    } catch (Exception ^ ex) {
        /*MessageBox::Show(ex->Message, "Canh bao", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);*/
        return false;
    }
}


bool HandleFile::WriteServicesArray(array<Services ^> ^ services,
                                    String ^ filePath) {
    try {
        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter ^ writer = gcnew BinaryWriter(fs);
        writer->Write(services->Length);
        for each (Services ^ service in services) {
            writer->Write(service->Id);
            writer->Write(service->Name);
        }
        writer->Close();
        fs->Close();
        return true;
    } catch (Exception ^) {
        // MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
        // MessageBoxIcon::Warning);
        return false;
    }
}

array<Services ^> ^ HandleFile::ReadServicesArray(String ^ filePath) {
    try {
        if (!File::Exists(filePath)) {
            return gcnew array<Services ^>(0);
        }

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::OpenOrCreate);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<Services ^>(0);
        }

        int count = reader->ReadInt32();
        array<Services ^> ^ services = gcnew array<Services ^>(count);

        for (int i = 0; i < count; i++) {
            String ^ _id = reader->ReadString();
            String ^ _name = reader->ReadString();

            services[i] = gcnew Services(_id, _name);

        }
        reader->Close();
        fs->Close();
        return services;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return nullptr;
    }
}

bool HandleFile::WriteCodeArray(array<PaymentCodes ^> ^ codes,
                                String ^ filePath) {
    try {
        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter ^ writer = gcnew BinaryWriter(fs);
        writer->Write(codes->Length);
        for each (PaymentCodes ^ code in codes) {
            writer->Write(code->Id);
            writer->Write(code->CompanyAccountNumber);
            writer->Write(code->Code);
            writer->Write(code->Amount);
            writer->Write(code->Status);
            writer->Write(code->CreatedDate.ToString());
            writer->Write(code->ExpiredDate.ToString());
        }
        writer->Close();
        fs->Close();
        return true;
    } catch (Exception ^) {
        // MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
        // MessageBoxIcon::Warning);
        return false;
    }
}

array<PaymentCodes ^> ^ HandleFile::ReadCodeArray(String ^ filePath) {
    try {
        if (!File::Exists(filePath)) {
            return gcnew array<PaymentCodes ^>(0);
        }

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::OpenOrCreate);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<PaymentCodes ^>(0);
        }

        int count = reader->ReadInt32();
        array<PaymentCodes ^> ^ codes = gcnew array<PaymentCodes ^>(count);

        for (int i = 0; i < count; i++) {
            String ^ _id = reader->ReadString();
            String ^ _companyAccountNumber = reader->ReadString();
            String ^ _code = reader->ReadString();
            int _amount = reader->ReadInt32();
            int _status = reader->ReadInt32();
            DateTime _createdDate = DateTime::Parse(reader->ReadString());
            DateTime _expiredDate = DateTime::Parse(reader->ReadString());
            codes[i] =
                gcnew PaymentCodes(_id, _companyAccountNumber, _code, _amount,
                                   _status, _createdDate, _expiredDate);
        }
        reader->Close();
        fs->Close();
        return codes;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return nullptr;
    }
}


bool HandleFile::WriteRecurringPaymentsArray(array<RecurringPayments ^> ^recurringPayments, String^ filePath) {
    try {
        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter ^ writer = gcnew BinaryWriter(fs);
        writer->Write(recurringPayments->Length);
        for each (RecurringPayments ^ recurringPayment in recurringPayments) {
            writer->Write(recurringPayment->Id);
            writer->Write(recurringPayment->UserAccountNumber);
            writer->Write(recurringPayment->CompanyAccountNumber);
            writer->Write(recurringPayment->Monthly);
            writer->Write(recurringPayment->PaymentDay.ToString());
            writer->Write(recurringPayment->Debt);
        }
        writer->Close();
        fs->Close();
        return true;
    } catch (Exception ^) {
        // MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
        // MessageBoxIcon::Warning);
        return false;
    }
}


array<RecurringPayments ^> ^ HandleFile::ReadRecurringPaymentsArray(String ^ filePath) {
    try {
        if (!File::Exists(filePath)) {
            return gcnew array<RecurringPayments ^>(0);
        }

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::OpenOrCreate);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<RecurringPayments ^>(0);
        }

        int count = reader->ReadInt32();
        array<RecurringPayments ^> ^ recurringPayments =
            gcnew array<RecurringPayments ^>(count);

        for (int i = 0; i < count; i++) {
            String ^ _id = reader->ReadString();
            String ^ _userAccountNumber = reader->ReadString();
            String ^ _companyAccountNumber = reader->ReadString();
            int _monthly = reader->ReadInt32();
            DateTime _paymentDay = DateTime::Parse(reader->ReadString());
            double _debt = reader->ReadDouble();
            recurringPayments[i] = gcnew RecurringPayments(
                _id, _userAccountNumber, _companyAccountNumber,
                                        _monthly, _paymentDay, _debt);
        }
        reader->Close();
        fs->Close();
        return recurringPayments;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return nullptr;
    }
}

bool HandleFile::WriteRecurringPaymentRequestArray(
    array<RecurringPaymentRequest^>^
    recurringRequests, String^ filePath) {
    try {
        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter ^ writer = gcnew BinaryWriter(fs);
        writer->Write(recurringRequests->Length);
        for each (RecurringPaymentRequest ^ request in recurringRequests) {
            writer->Write(request->Id);
            writer->Write(request->UserAccountNumber);
            writer->Write(request->CompanyAccountNumber);
            writer->Write(request->Amount);
            writer->Write(request->RequestDate.ToString());
            writer->Write(request->Status);
        }
        writer->Close();
        fs->Close();
        return true;
    } catch (Exception ^) {
        // MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
        // MessageBoxIcon::Warning);
        return false;
    }

}

array<RecurringPaymentRequest ^> ^
HandleFile::ReadRecurringPaymentRequestArray(String^ filePath) {
    try {
        if (!File::Exists(filePath)) {
            return gcnew array<RecurringPaymentRequest ^>(0);
        }

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::OpenOrCreate);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<RecurringPaymentRequest ^>(0);
        }

        int count = reader->ReadInt32();
        array<RecurringPaymentRequest ^> ^ recurringRequests =
            gcnew array<RecurringPaymentRequest ^>(count);

        for (int i = 0; i < count; i++) {

            String ^ _id = reader->ReadString();
            String ^ _userAccountNumber = reader->ReadString();
            String ^ _companyAccountNumber = reader->ReadString();
            double _amount = reader->ReadDouble();
            DateTime _requestDate = DateTime::Parse(reader->ReadString());
            String ^ _status = reader->ReadString();

            recurringRequests[i] = gcnew RecurringPaymentRequest(
                _id, _userAccountNumber, _companyAccountNumber, _amount,
                _requestDate, _status);
        }
        reader->Close();
        fs->Close();
        return recurringRequests;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return nullptr;
    }
}


bool HandleFile::WriteNotificationsArray(array<Notifications ^> ^ notifications,
                                         String ^ filePath) {
    try {
        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter ^ writer = gcnew BinaryWriter(fs);
        writer->Write(notifications->Length);
        for each (Notifications ^ notification in notifications) {

            writer->Write(notification->NotificationId);
            writer->Write(notification->UserAccNumber);
            writer->Write(notification->Content);
            writer->Write(notification->CreatedAt);
            writer->Write(notification->Status);
        }
        writer->Close();
        fs->Close();
        return true;
    } catch (Exception ^) {
        // MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
        // MessageBoxIcon::Warning);
        return false;
    }
}

array<Notifications ^> ^ HandleFile::ReadNotificationsArray(String ^ filePath) {
    try {
        if (!File::Exists(filePath)) {
            return gcnew array<Notifications ^>(0);
        }

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::OpenOrCreate);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<Notifications ^>(0);
        }

        int count = reader->ReadInt32();
        array<Notifications ^> ^ notifications =
            gcnew array<Notifications ^>(count);

        for (int i = 0; i < count; i++) {

            String ^ _id = reader->ReadString();
            String ^ _userAccountNumber = reader->ReadString();
            String ^ _content = reader->ReadString();
            String ^ _createAt = reader->ReadString();
            int _status = reader->ReadInt32();
            
            notifications[i] = gcnew Notifications(
                _id, _userAccountNumber, _content, _createAt, _status);
        }
        reader->Close();
        fs->Close();
        return notifications;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return nullptr;
    }
}


bool HandleFile::WriteSavingCustomersArray(array<SavingCustomers^>^
    savingCustomers,
    String^ filePath) {
    try {
        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter ^ writer = gcnew BinaryWriter(fs);
        writer->Write(savingCustomers->Length);
        for each (SavingCustomers ^ savingCustomer in savingCustomers) {

            writer->Write(savingCustomer->Id);
            writer->Write(savingCustomer->UserAccountNumber);
            writer->Write(savingCustomer->Amount);
            writer->Write(savingCustomer->Type);
            writer->Write(savingCustomer->Term);
            writer->Write(savingCustomer->InterestRate);
            writer->Write(savingCustomer->DepositDate.ToString());
            writer->Write(savingCustomer->PaymentDate);
            writer->Write(savingCustomer->Status);

        }
        writer->Close();
        fs->Close();
        return true;
    } catch (Exception ^) {
        // MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
        // MessageBoxIcon::Warning);
        return false;
    }
}

array<SavingCustomers ^> ^
HandleFile::ReadSavingCustomersArray(String^ filePath) {
    try {
        if (!File::Exists(filePath)) {
            return gcnew array<SavingCustomers ^>(0);
        }

        FileStream ^ fs = gcnew FileStream(filePath, FileMode::OpenOrCreate);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        if (fs->Length == 0) {
            reader->Close();
            fs->Close();
            return gcnew array<SavingCustomers ^>(0);
        }

        int count = reader->ReadInt32();
        array<SavingCustomers ^> ^ savingCustomers =
            gcnew array<SavingCustomers ^>(count);

        for (int i = 0; i < count; i++) {

            String ^ _id = reader->ReadString();
            String ^ _userAccountNumber = reader->ReadString();
            double _amount = reader->ReadDouble();
            String ^ _type = reader->ReadString();
            int _term = reader->ReadInt32();
            float _rate = reader->ReadSingle();
            DateTime _depositDate = DateTime::Parse(reader->ReadString());
            String ^ _paymentDate = reader->ReadString();
            int _status = reader->ReadInt32();
            savingCustomers[i] = gcnew SavingCustomers(
                _id, _userAccountNumber, _amount, _type, _term, _rate,
                                      _depositDate, _paymentDate, _status);
        }
        reader->Close();
        fs->Close();
        return savingCustomers;
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);
        return nullptr;
    }
}