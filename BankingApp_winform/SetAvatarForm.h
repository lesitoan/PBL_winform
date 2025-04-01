#pragma once

namespace BankingAppwinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SetAvatarForm
	/// </summary>
	public ref class SetAvatarForm : public System::Windows::Forms::Form
	{
	public:
		SetAvatarForm(void)
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
		~SetAvatarForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
                    this->SuspendLayout();
                    //
                    // SetAvatarForm
                    //
                    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
                    this->AutoScaleMode =
                        System::Windows::Forms::AutoScaleMode::Font;
                    this->BackColor = System::Drawing::Color::Teal;
                    this->ClientSize = System::Drawing::Size(856, 407);
                    this->FormBorderStyle =
                        System::Windows::Forms::FormBorderStyle::None;
                    this->Name = L"SetAvatarForm";
                    this->Text = L"SetAvatarForm";
                    this->ResumeLayout(false);
                }
#pragma endregion
	};
}
