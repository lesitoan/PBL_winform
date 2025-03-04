#pragma once
#include "User.h"
using namespace System;

public
ref class GlobalData {
  private:
    static User ^ currentUser;

  public:
    static User ^ GetCurrentUser() { return currentUser; }

    static void SetCurrentUser(User ^ user) {
        currentUser = user;
    }
};