#pragma once

using namespace System::IO;

public interface class ISaveToFile {
  public:
    void WriteTo(BinaryWriter ^ writer);
    void ReadFrom(BinaryReader ^ reader);
};
