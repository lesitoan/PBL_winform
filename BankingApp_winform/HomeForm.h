#pragma once
#include "User.h"
#include "File.h"

namespace BankingAppwinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HomeForm
	/// </summary>
	public ref class HomeForm : public System::Windows::Forms::Form
	{
	public:
		HomeForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HomeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ infoLabel;
	private: array<User^>^ users;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// infoLabel
			// 
			this->infoLabel->AutoSize = true;
			this->infoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infoLabel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->infoLabel->Location = System::Drawing::Point(309, 92);
			this->infoLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(0, 31);
			this->infoLabel->TabIndex = 2;
			// 
			// HomeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 491);
			this->Controls->Add(this->infoLabel);
			this->Name = L"HomeForm";
			this->Text = L"HomeForm";
			this->Load += gcnew System::EventHandler(this, &HomeForm::HomeForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    private: System::Void HomeForm_Load(System::Object^ sender, System::EventArgs^ e) {
			users = ReadUserArray("users.dat");
			if (users == nullptr) {
				infoLabel->Text = "No user found";
			}
			else {
				for (int i = 0; i < users->Length; i++) {
					infoLabel->Text += users[i]->userName + "\n";
				}
			}
    }
	};
}
