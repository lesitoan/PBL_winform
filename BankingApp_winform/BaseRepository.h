//#pragma once
//#include "HandleFile.h"
//#include "ISaveToFile.h"
//#include "BaseEntity.h"
//
//using namespace System;
//using namespace System::Collections::Generic;
//using namespace System::IO;
//
//
//
//generic<typename T> where T : BaseEntity, gcnew()
//
//ref class BaseRepository abstract {
//  protected:
//    static array<T> ^ cache;
//    static DateTime lastReadTime;
//    static String ^ fileName;
//
//  public:
//    static void InitializeRepository(String ^ file) {
//        fileName = file;
//        cache = nullptr;
//        lastReadTime = DateTime::MinValue;
//    }
//
//    static void CheckLastUpdateTime() {
//        try {
//            DateTime lastUpdateTime = HandleFile::GetLastUpdateTime(fileName);
//            if (lastUpdateTime >= lastReadTime) {
//                cache = HandleFile::ReadArrayFromFile<T>(fileName);
//                lastReadTime = lastUpdateTime;
//            }
//        } catch (Exception ^ ex) {
//            throw gcnew Exception("CheckLastUpdateTime error !!!", ex);
//        }
//    }
//
//    static array<T> ^ GetAll() {
//        try {
//            CheckLastUpdateTime();
//            return cache;
//        } catch (Exception ^ ex) {
//            throw gcnew Exception("GetAll error !!!", ex);
//        }
//    }
//
//    static void Insert(T item) {
//        try {
//            CheckLastUpdateTime();
//            if (cache == nullptr) {
//                cache = gcnew array<T>(1);
//                cache[0] = item;
//            } else {
//                array<T> ^ newCache = gcnew array<T>(cache->Length + 1);
//                for (int i = 0; i < cache->Length; i++) {
//                    newCache[i] = cache[i];
//                }
//                newCache[cache->Length] = item;
//                cache = newCache;
//            }
//            HandleFile::WriteArrayToFile<T>(cache, fileName);
//        } catch (Exception ^ ex) {
//            throw gcnew Exception("Insert error !!!", ex);
//        }
//    }
//
//    static void DeleteById(String ^ id) {
//        try {
//            CheckLastUpdateTime();
//            if (cache == nullptr) {
//                return;
//            }
//            List<T> ^ list = gcnew List<T>();
//            for (int i = 0; i < cache->Length; i++) {
//                if (cache[i]->Id != id) {
//                    list->Add(cache[i]);
//                }
//            }
//
//            if (list->Count == cache->Length) {
//                return;
//            }
//
//            cache = list->ToArray();
//            HandleFile::WriteArrayToFile<T>(cache, fileName);
//
//        } catch (Exception ^ ex) {
//            throw gcnew Exception("DeleteById error !!!", ex);
//        }
//    }
//
//    static void UpdatedById(String ^ id, T item) {
//        try {
//            CheckLastUpdateTime();
//            if (cache == nullptr) {
//                return;
//            }
//            for (int i = 0; i < cache->Length; i++) {
//                if (cache[i]->Id == id) {
//                    cache[i] = item;
//                    break;
//                }
//            }
//            HandleFile::WriteArrayToFile<T>(cache, fileName);
//        } catch (Exception ^ ex) {
//            throw gcnew Exception("UpdatedById error !!!", ex);
//        }
//    }
//
//    static T FindById(String ^ id) {
//        try {
//            CheckLastUpdateTime();
//            if (cache == nullptr) {
//                return nullptr;
//            }
//            for (int i = 0; i < cache->Length; i++) {
//                if (cache[i]->Id == id) {
//                    return cache[i];
//                }
//            }
//            return nullptr;
//        } catch (Exception ^ ex) {
//            throw gcnew Exception("FindById error !!!", ex);
//        }
//    }
//
//    static void DeleteCache() {
//        cache = nullptr;
//        lastReadTime = DateTime::MinValue;
//    }
//};
