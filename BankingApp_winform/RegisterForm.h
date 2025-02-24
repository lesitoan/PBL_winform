#pragma once
#include "User.h"

namespace BankingAppwinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form {
	public:
		RegisterForm(void) {
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm() {
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ userName;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ password;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ passwordConfirm;
	private: System::Windows::Forms::Button^ btnRegister;


	private: System::Windows::Forms::LinkLabel^ linkLabel1;

	private:
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ labelUser;

	private: array<User^>^ users;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->userName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->passwordConfirm = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->labelUser = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// userName
			// 
			this->userName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userName->Location = System::Drawing::Point(229, 95);
			this->userName->Name = L"userName";
			this->userName->Size = System::Drawing::Size(483, 31);
			this->userName->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(80, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Họ và tên";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(80, 155);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Mật khẩu";
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password->Location = System::Drawing::Point(229, 152);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(483, 31);
			this->password->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(80, 213);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Xn mật khẩu";
			// 
			// passwordConfirm
			// 
			this->passwordConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordConfirm->Location = System::Drawing::Point(229, 210);
			this->passwordConfirm->Name = L"passwordConfirm";
			this->passwordConfirm->Size = System::Drawing::Size(483, 31);
			this->passwordConfirm->TabIndex = 4;
			// 
			// btnRegister
			// 
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegister->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnRegister->Location = System::Drawing::Point(538, 270);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(174, 42);
			this->btnRegister->TabIndex = 6;
			this->btnRegister->Text = L"Đăng kí";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &RegisterForm::btnRegister_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->Location = System::Drawing::Point(358, 428);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(103, 24);
			this->linkLabel1->TabIndex = 7;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Đăng nhập";
			// 
			// labelUser
			// 
			this->labelUser->AutoSize = true;
			this->labelUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUser->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelUser->Location = System::Drawing::Point(89, 335);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(0, 25);
			this->labelUser->TabIndex = 8;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(784, 461);
			this->Controls->Add(this->labelUser);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->passwordConfirm);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->password);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->userName);
			this->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = userName->Text;
		String^ pass = password->Text;
		String^ passConfirm = passwordConfirm->Text;
		if (name == "" || pass == "" || passConfirm == "") {
			MessageBox::Show("Vui lòng nhập đầy đủ thông tin", "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (pass != passConfirm) {
			MessageBox::Show("Mật khẩu không khớp", "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			User^ user = gcnew User();
			user->userName = name;
			user->password = pass;
			users = user->ReadUserArray("users.dat");
			if (users == nullptr) {
				users = gcnew array<User^>(1);
				users[0] = user;
			}
			else {
				array<User^>^ temp = gcnew array<User^>(users->Length + 1);
				for (int i = 0; i < users->Length; i++) {
					temp[i] = users[i];
				}
				temp[users->Length] = user;
				users = temp;
			}
			user->WriteUserArray(users, "users.dat");
			MessageBox::Show("Đăng kí thành công", "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Information);
			userName->Text = "";
			password->Text = "";
			passwordConfirm->Text = "";
			for (int i = 0; i < users->Length; i++) {
				this->labelUser->Text = this->labelUser->Text + users[i]->userName + " - ";
			}
		}
	}
};
}
