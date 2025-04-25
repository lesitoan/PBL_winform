#pragma once

using namespace System;

ref class BaseEntity abstract {
 protected:
   String ^ id;
   DateTime createdAt;
   DateTime updatedAt;


   BaseEntity() {
       createdAt = DateTime::Now;
       updatedAt = DateTime::Now;
       id = Guid::NewGuid().ToString();
   }
   BaseEntity(String ^ _id, DateTime _createdAt, DateTime _updatedAt) {
       id = _id;
       createdAt = _createdAt;
       updatedAt = _updatedAt;
   }

 public:
   virtual void WriteTo(BinaryWriter ^ writer) {
       writer->Write(id);
       writer->Write(createdAt.ToBinary());
       writer->Write(updatedAt.ToBinary());
   }

   virtual void ReadFrom(BinaryReader ^ reader) {
       id = reader->ReadString();
       createdAt = DateTime::FromBinary(reader->ReadInt64());
       updatedAt = DateTime::FromBinary(reader->ReadInt64());
   }

   virtual property String ^ Id {
       String ^ get() { return id; }
   }

   virtual property DateTime CreatedAt {
       DateTime get() {
           return createdAt;
       }
       void set(DateTime value) {
           createdAt = value;
       }
   }

   virtual property DateTime UpdatedAt {
       DateTime get() {
           return updatedAt;
       }
       void set(DateTime value) {
           updatedAt = value;
       }
   }
};
