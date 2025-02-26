#include "HandleFile.h"
#include "User.h"

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
        }
        writer->Close();
        return true;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
            users[i] = gcnew User(_fullName, _password, _phoneNumber);
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