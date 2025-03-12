#include "CompanyBillingForm.h"
#include "AdminForm.h"

namespace BankingAppwinform {

    CompanyBillingForm::CompanyBillingForm(int companyAccountNumber) {
        InitializeComponent();
        LoadPaymentCodes(companyAccountNumber);
        LoadRecurringPayments();
    }

    CompanyBillingForm::~CompanyBillingForm() {
        if (components) {
            delete components;
        }
    }

    System::Void CompanyBillingForm::btnAccount_Click(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
        if (adminForm != nullptr) {
            adminForm->UndoLastForm();
        }
    }
};
