#pragma once

#include "ISaveToFile.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class HandleFile {
  public:
    generic<typename T> where T : ISaveToFile static bool
                                  WriteArrayToFile(array<T> ^ items, String ^ filePath) {
        try {
            FileStream ^ fs = gcnew FileStream(filePath, FileMode::Create);
            BinaryWriter ^ writer = gcnew BinaryWriter(fs);
            writer->Write(items->Length); // Ghi số lượng phần tử
            for each (T item in items) {
                item->WriteTo(writer); // Gọi WriteTo cho mỗi item
            }
            writer->Close();
            fs->Close();

            // Ghi lại thời gian cập nhật file
            HandleFile::UpdateFilehistoryUpdate(filePath);

            return true;
        } catch (Exception ^) {
            return false;
        }
    }

    generic<typename T> where T
        : ISaveToFile,
          gcnew() static array<T> ^ ReadArrayFromFile(String ^ filePath) {
              try {
                  if (!File::Exists(filePath)) {
                      return gcnew array<T>(0);
                  }

                  FileStream ^ fs =
                      gcnew FileStream(filePath, FileMode::OpenOrCreate);
                  BinaryReader ^ reader = gcnew BinaryReader(fs);

                  if (fs->Length == 0) {
                      reader->Close();
                      fs->Close();
                      return gcnew array<T>(0);
                  }

                  int count = reader->ReadInt32();
                  array<T> ^ items = gcnew array<T>(count);

                  for (int i = 0; i < count; i++) {
                      T item = gcnew T();     // yêu cầu có constructor mặc định
                      item->ReadFrom(reader); // đọc dữ liệu từ file
                      items[i] = item;
                  }

                  reader->Close();
                  fs->Close();
                  return items;
              } catch (Exception ^ ex) {
                  MessageBox::Show(ex->Message, "Lỗi đọc file",
                                   MessageBoxButtons::OK,
                                   MessageBoxIcon::Error);
                  return nullptr;
              }
          }

              static void UpdateFilehistoryUpdate(String ^ dataFileName) {
        try {
            String ^ logFilePath = "historyUpdateData.txt";
            DateTime time = DateTime::Now;

            List<String ^> ^ lines = gcnew List<String ^>();

            if (!File::Exists(logFilePath)) {
                // Tạo file mới nếu không tồn tại
                FileStream ^ fs = File::Create(logFilePath);
                fs->Close();
            }

            array<String ^> ^ existingLines = File::ReadAllLines(logFilePath);
            for each (String ^ line in existingLines) {
                // Nếu không phải dòng liên quan tới file cần cập nhật thì giữ lại
                if (!line->StartsWith(dataFileName + "|")) {
                    lines->Add(line);
                }
            }

            // Thêm dòng mới
            String ^ newLine = dataFileName + "|" + time.ToString("o"); // "o" = ISO 8601
            lines->Add(newLine);

            // Ghi lại toàn bộ file
            File::WriteAllLines(logFilePath, lines->ToArray());
        } catch (Exception ^ ex) {
            throw gcnew Exception("UpdateFilehistoryUpdate error !!!", ex);
        }
    }

    static DateTime GetLastUpdateTime(String ^ dataFileName) {
        try {
            String ^ logFilePath = "historyUpdateData.txt";
            if (!File::Exists(logFilePath)) {
                // Tạo file mới nếu không tồn tại
                FileStream ^ fs = File::Create(logFilePath);
                fs->Close();
            }

            array<String ^> ^ existingLines = File::ReadAllLines(logFilePath);
            for each (String ^ line in existingLines) {
                if (line->StartsWith(dataFileName + "|")) {
                    String ^ timeString = line->Substring(line->IndexOf("|") + 1);
                    DateTime time = DateTime::Parse(timeString);
                    return time;
                }
            }
            // Nếu không tìm thấy dòng liên quan đến file, trả về DateTime::MinValue
            return DateTime::MinValue;

        } catch (Exception ^ ex) {
            throw gcnew Exception("GetLastUpdateTime error !!!", ex);
        }
    }
};
