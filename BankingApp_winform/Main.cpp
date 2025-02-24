#include "RegisterForm.h"
#include "HomeForm.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BankingAppwinform::RegisterForm registerForm;
	BankingAppwinform::HomeForm homeForm;

	Application::Run(% registerForm);
	if (registerForm.showHome) {
		Application::Run(% homeForm);
	}

}