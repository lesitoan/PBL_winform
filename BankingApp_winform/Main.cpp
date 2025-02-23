#include "RegisterForm.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BankingAppwinform::RegisterForm registerForm;
	Application::Run(% registerForm);
}