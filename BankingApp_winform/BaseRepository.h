#pragma once
#include "HandleFile.h"
#include "ISaveToFile.h"
#include "BaseEntity.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;



generic<typename T> where T : BaseEntity, gcnew()

public ref class BaseRepository abstract {
  protected:
    static array<T> ^ cache;
    static DateTime lastReadTime;
    static String ^ fileName;

    static void InitializeRepository(String ^ file) {
        fileName = file;
        cache = nullptr;
        lastReadTime = DateTime::MinValue;
    }

    static void CheckLastUpdateTime() {
        try {
            DateTime lastUpdateTime = HandleFile::GetLastUpdateTime(fileName);
            if (lastUpdateTime >= lastReadTime) {
                cache = safe_cast<array<T> ^>(HandleFile::ReadArrayFromFile<T>(fileName));

                lastReadTime = lastUpdateTime;
            }
        } catch (Exception ^ ex) {
            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
        }
    }

  public:
    static void DeleteCache() {
        cache = nullptr;
        lastReadTime = DateTime::MinValue;
        fileName = "";
    };
};
