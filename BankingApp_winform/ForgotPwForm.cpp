#include "ForgotPwForm.h"

#pragma once

namespace BankingAppwinform {

    ForgotPwForm::ForgotPwForm(void) {
        InitializeComponent();
    }

    ForgotPwForm::~ForgotPwForm() {
        if (components) {
            delete components;
        }
    }

};
