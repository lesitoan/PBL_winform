#pragma once
#include "User.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

void WriteUserArray(array<User^>^ users, String^ filePath);

array<User^>^ ReadUserArray(String^ filePath);