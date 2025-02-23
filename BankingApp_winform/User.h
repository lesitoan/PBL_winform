#pragma once
using namespace System;

using namespace System::IO;
using namespace System::Collections::Generic;

public ref class User {
public:
	String^ userName;
	String^ password;
    void WriteUserArray(array<User^>^ users, String^ filePath)
    {
        try
        {
            FileStream^ fs = gcnew FileStream(filePath, FileMode::Create);
            BinaryWriter^ writer = gcnew BinaryWriter(fs);
            writer->Write(users->Length);
            for each (User ^ user in users)
            {
                writer->Write(user->userName);
                writer->Write(user->password);
            }

            writer->Close();
        }
        catch (Exception^ ex)
        {
            return;
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
                users[i] = gcnew User();
                users[i]->userName = reader->ReadString();
                users[i]->password = reader->ReadString();
            }
            reader->Close();
            return users;
        }
        catch (Exception^ ex)
        {
            return nullptr;
        }
    }

};