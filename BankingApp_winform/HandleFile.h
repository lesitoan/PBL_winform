#pragma once
#include "User.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;




ref class HandleFile {
  public:
    static bool WriteUserArray(array<User ^> ^ users, String ^ filePath);
    static array<User ^> ^ ReadUserArray(String ^ filePath);
};