#include "AuthForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String ^> ^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    BankingAppwinform::AuthForm authForm;
    authForm.ShowDialog();
}
