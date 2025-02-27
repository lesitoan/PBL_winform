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
            writer->Write(user->getIsAdmin());
            writer->Write(user->getPin());
            writer->Write(user->getBankName());
        }
        writer->Close();
        return true;
    }
    catch (Exception^ ex)
    {
        //MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return false;
    }
}

array<User^>^ HandleFile::ReadUserArray(String^ filePath)
{
    try
    {
        FileStream^ fs = gcnew FileStream(filePath, FileMode::Open);
        BinaryReader^ reader = gcnew BinaryReader(fs);

        int count = reader->ReadInt32();
        array<User^>^ users = gcnew array<User^>(count);

        for (int i = 0; i < count; i++)
        {
            String^ _fullName = reader->ReadString();
            String ^ _password = reader->ReadString();
            String ^ _phoneNumber = reader->ReadString();
            int _accountNumber = reader->ReadInt32();
            double _balance = reader->ReadDouble();
            bool _isAdmin = reader->ReadBoolean();
            int _pin = reader->ReadInt32();
            String ^ _bankName = reader->ReadString();
            users[i] = gcnew User(_fullName, _password, _phoneNumber, _accountNumber,
                           _balance, _isAdmin, _pin, _bankName);
        }
        reader->Close();
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
        FileStream ^ fs = gcnew FileStream(filePath, FileMode::Open);
        BinaryReader ^ reader = gcnew BinaryReader(fs);

        int count = reader->ReadInt32();
        array<Transaction ^> ^ transactions = gcnew array<Transaction ^>(count);

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
        return true;
    } catch (Exception ^ ex) {
        /*MessageBox::Show(ex->Message, "Canh bao", MessageBoxButtons::OK,
                         MessageBoxIcon::Warning);*/
        return false;
    }
}