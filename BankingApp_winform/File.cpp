#include "File.h"
#include "User.h"

void WriteUserArray(array<User^>^ users, String^ filePath) {
    try {
        FileStream^ fs = gcnew FileStream(filePath, FileMode::Create);
        BinaryWriter^ writer = gcnew BinaryWriter(fs);
        writer->Write(users->Length);
        for each (User ^ user in users) {
            writer->Write(user->userName);
            writer->Write(user->password);
            writer->Write(user->accountNumber);
            writer->Write(user->balance);
            writer->Write(user->isAdmin);
            writer->Write(user->pin);
        }
        writer->Close();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}

array<User^>^ ReadUserArray(String^ filePath)
{
    try
    {
        FileStream^ fs = gcnew FileStream(filePath, FileMode::Open);
        BinaryReader^ reader = gcnew BinaryReader(fs);

        int count = reader->ReadInt32();
        array<User^>^ users = gcnew array<User^>(count);

        for (int i = 0; i < count; i++)
        {
            String^ _userName = reader->ReadString();
            String^ _password = reader->ReadString();
            int _accountNumber = reader->ReadInt32();
            int _balance = reader->ReadInt32();
            bool _isAdmin = reader->ReadBoolean();
            int _pin = reader->ReadInt32();
            users[i] = gcnew User(_userName, _password);
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