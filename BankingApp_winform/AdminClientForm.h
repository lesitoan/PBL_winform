#pragma once

namespace BankingAppwinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminClientForm
	/// </summary>
	public ref class AdminClientForm : public System::Windows::Forms::Form
	{
	public:
		AdminClientForm(void)
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
		~AdminClientForm()
		{
			if (components)
			{
				delete components;
			}
		}

              private:
                System::Windows::Forms::DataGridView ^ dataGridViewUsers;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column4;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column5;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ STK;

              protected: 

              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              private:


              protected:
              private:


              private:


              private:


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
                    this->dataGridViewUsers =
                        (gcnew System::Windows::Forms::DataGridView());
                    this->Column1 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column2 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column3 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column4 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column5 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->STK = (gcnew System::Windows::Forms::
                                     DataGridViewTextBoxColumn());
                    (cli::safe_cast<
                         System::ComponentModel::ISupportInitialize ^>(
                         this->dataGridViewUsers))
                        ->BeginInit();
                    this->SuspendLayout();
                    //
                    // dataGridViewUsers
                    //
                    this->dataGridViewUsers->ColumnHeadersHeightSizeMode =
                        System::Windows::Forms::
                            DataGridViewColumnHeadersHeightSizeMode::AutoSize;
                    this->dataGridViewUsers->Columns->AddRange(
                        gcnew cli::array<
                            System::Windows::Forms::DataGridViewColumn ^>(6){
                            this->Column1, this->Column2, this->Column3,
                            this->Column4, this->Column5, this->STK});
                    this->dataGridViewUsers->Dock =
                        System::Windows::Forms::DockStyle::Fill;
                    this->dataGridViewUsers->Location =
                        System::Drawing::Point(0, 0);
                    this->dataGridViewUsers->Name = L"dataGridViewUsers";
                    this->dataGridViewUsers->Size =
                        System::Drawing::Size(1077, 711);
                    this->dataGridViewUsers->TabIndex = 2;
                    this->dataGridViewUsers->CellContentClick += gcnew
                        System::Windows::Forms::DataGridViewCellEventHandler(
                            this,
                            &AdminClientForm::dataGridView1_CellContentClick);
                    //
                    // Column1
                    //
                    this->Column1->Frozen = true;
                    this->Column1->HeaderText = L"Họ và tên";
                    this->Column1->Name = L"Column1";
                    this->Column1->Width = 200;
                    //
                    // Column2
                    //
                    this->Column2->HeaderText = L"Số tài khoản";
                    this->Column2->Name = L"Column2";
                    this->Column2->Width = 150;
                    //
                    // Column3
                    //
                    this->Column3->HeaderText = L"Số dư";
                    this->Column3->Name = L"Column3";
                    this->Column3->Width = 150;
                    //
                    // Column4
                    //
                    this->Column4->HeaderText = L"Mã pin";
                    this->Column4->Name = L"Column4";
                    this->Column4->Width = 150;
                    //
                    // Column5
                    //
                    this->Column5->HeaderText = L"Trạng thái";
                    this->Column5->Name = L"Column5";
                    this->Column5->Width = 150;
                    //
                    // STK
                    //
                    this->STK->HeaderText = L"Tên ngân hàng";
                    this->STK->Name = L"STK";
                    this->STK->Width = 200;
                    //
                    // AdminClientForm
                    //
                    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                    this->AutoScaleMode =
                        System::Windows::Forms::AutoScaleMode::Font;
                    this->BackColor =
                        System::Drawing::SystemColors::ActiveCaption;
                    this->ClientSize = System::Drawing::Size(1077, 711);
                    this->Controls->Add(this->dataGridViewUsers);
                    this->FormBorderStyle =
                        System::Windows::Forms::FormBorderStyle::None;
                    this->Name = L"AdminClientForm";
                    this->Text = L"AdminClientForm";
                    this->Load += gcnew System::EventHandler(
                        this, &AdminClientForm::AdminClientForm_Load);
                    (cli::safe_cast<
                         System::ComponentModel::ISupportInitialize ^>(
                         this->dataGridViewUsers))
                        ->EndInit();
                    this->ResumeLayout(false);
                }
#pragma endregion
              private:
                System::Void dataGridView1_CellContentClick(
                    System::Object ^ sender,
                    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {}

              private:
                System::Void AdminClientForm_Load(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
                    for (int i = 1; i <= 30; i++) {
                        System::String ^ name = "User" + i;
                        System::String ^ phone = "09" + i.ToString("00000000");
                        int balance = 100000 + (i * 5000);
                        int accountNumber = 100000 + i;
                        System::String ^ status =
                            (i % 2 == 0) ? "active" : "inactive";
                        System::String ^ bank = (i % 3 == 0)   ? "Vietcombank"
                                                : (i % 3 == 1) ? "BIDV"
                                                               : "Techcombank";

                        dataGridViewUsers->Rows->Add(
                            name, phone, balance, accountNumber, status, bank);
                    }
                }
          };
          }
