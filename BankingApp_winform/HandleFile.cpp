﻿#include "HandleFile.h"

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
            writer->Write(user->getServiceId());

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
            int _accountNumber = reader->ReadInt32();
            double _balance = reader->ReadDouble();
            String ^ _role = reader->ReadString();
            int _pin = reader->ReadInt32();
            String ^ _bankName = reader->ReadString();
            int _serviceId = reader->ReadInt32();
            users[i] = gcnew User(_fullName, _password, _phoneNumber, _accountNumber,
                           _balance, _role, _pin, _bankName, _serviceId);
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
            int _transactionId = reader->ReadInt32();
            int _fromAccountNumber = reader->ReadInt32();
            int _toAccountNumber = reader->ReadInt32();
            double _amount = reader->ReadDouble();
            String ^ _createdAt = reader->ReadString();
            transactions[i] =
                gcnew Transaction(_transactionId, _fromAccountNumber,
                                  _toAccountNumber, _amount, _createdAt);
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
            int _id = reader->ReadInt32();
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
            int _id = reader->ReadInt32();
            int _companyAccountNumber = reader->ReadInt32();
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
