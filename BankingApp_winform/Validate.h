#pragma once
using namespace System;
using namespace System::Text::RegularExpressions;

ref class Validate {
  public:
    static bool isPin(String ^ str);
    static bool isAccountNumber(String ^ str);
    static bool isNumber(String ^ str);
};
