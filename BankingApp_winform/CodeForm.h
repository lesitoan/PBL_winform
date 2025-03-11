#pragma once

namespace BankingAppwinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CodeForm
	/// </summary>
	public ref class CodeForm : public System::Windows::Forms::Form
	{
	public:
		CodeForm(void)
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
		~CodeForm()
		{
			if (components)
			{
				delete components;
			}
		}

              private:
                System::Windows::Forms::Panel ^ panel1;

              protected:
              private:
                System::Windows::Forms::Panel ^ panel2;

              private:
                System::Windows::Forms::Panel ^ panel3;

              private:
                System::Windows::Forms::TextBox ^ pin;

              private:
                System::Windows::Forms::Panel ^ panel4;

              private:
                System::Windows::Forms::TextBox ^ password;

              private:


              private:
                System::Windows::Forms::Label ^ label1;

              private:
                System::Windows::Forms::Button ^ button1;

              protected:
                System::Windows::Forms::Label ^ label7;

              private:
                System::Windows::Forms::Label ^ label2;

              private:
                System::Windows::Forms::DataGridView ^ dataGridViewUsers;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;

              private:


              private:


              private:


              protected: 

              private: 

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
                    System::Windows::Forms::DataGridViewCellStyle ^
                        dataGridViewCellStyle1 =
                        (gcnew System::Windows::Forms::DataGridViewCellStyle());
                    System::Windows::Forms::DataGridViewCellStyle ^
                        dataGridViewCellStyle2 =
                        (gcnew System::Windows::Forms::DataGridViewCellStyle());
                    System::Windows::Forms::DataGridViewCellStyle ^
                        dataGridViewCellStyle3 =
                        (gcnew System::Windows::Forms::DataGridViewCellStyle());
                    this->panel1 = (gcnew System::Windows::Forms::Panel());
                    this->panel2 = (gcnew System::Windows::Forms::Panel());
                    this->pin = (gcnew System::Windows::Forms::TextBox());
                    this->panel3 = (gcnew System::Windows::Forms::Panel());
                    this->password = (gcnew System::Windows::Forms::TextBox());
                    this->panel4 = (gcnew System::Windows::Forms::Panel());
                    this->label1 = (gcnew System::Windows::Forms::Label());
                    this->button1 = (gcnew System::Windows::Forms::Button());
                    this->label7 = (gcnew System::Windows::Forms::Label());
                    this->label2 = (gcnew System::Windows::Forms::Label());
                    this->dataGridViewUsers =
                        (gcnew System::Windows::Forms::DataGridView());
                    this->Column1 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column2 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column3 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->panel1->SuspendLayout();
                    this->panel2->SuspendLayout();
                    this->panel3->SuspendLayout();
                    this->panel4->SuspendLayout();
                    (cli::safe_cast<
                         System::ComponentModel::ISupportInitialize ^>(
                         this->dataGridViewUsers))
                        ->BeginInit();
                    this->SuspendLayout();
                    //
                    // panel1
                    //
                    this->panel1->BackColor = System::Drawing::Color::Teal;
                    this->panel1->Controls->Add(this->label2);
                    this->panel1->Controls->Add(this->button1);
                    this->panel1->Controls->Add(this->panel4);
                    this->panel1->Controls->Add(this->label1);
                    this->panel1->Controls->Add(this->label7);
                    this->panel1->Controls->Add(this->panel3);
                    this->panel1->Dock =
                        System::Windows::Forms::DockStyle::Left;
                    this->panel1->Location = System::Drawing::Point(0, 0);
                    this->panel1->Name = L"panel1";
                    this->panel1->Size = System::Drawing::Size(296, 499);
                    this->panel1->TabIndex = 0;
                    //
                    // panel2
                    //
                    this->panel2->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            (((System::Windows::Forms::AnchorStyles::Top |
                               System::Windows::Forms::AnchorStyles::Bottom) |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->panel2->BackColor = System::Drawing::Color::Teal;
                    this->panel2->Controls->Add(this->dataGridViewUsers);
                    this->panel2->Location = System::Drawing::Point(299, 0);
                    this->panel2->Margin =
                        System::Windows::Forms::Padding(20, 3, 3, 3);
                    this->panel2->Name = L"panel2";
                    this->panel2->Size = System::Drawing::Size(359, 499);
                    this->panel2->TabIndex = 1;
                    //
                    // pin
                    //
                    this->pin->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            (((System::Windows::Forms::AnchorStyles::Top |
                               System::Windows::Forms::AnchorStyles::Bottom) |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->pin->BorderStyle =
                        System::Windows::Forms::BorderStyle::None;
                    this->pin->Font =
                        (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
                    this->pin->Location = System::Drawing::Point(14, 12);
                    this->pin->MaxLength = 300;
                    this->pin->Multiline = true;
                    this->pin->Name = L"pin";
                    this->pin->Size = System::Drawing::Size(226, 179);
                    this->pin->TabIndex = 29;
                    //
                    // panel3
                    //
                    this->panel3->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            (((System::Windows::Forms::AnchorStyles::Top |
                               System::Windows::Forms::AnchorStyles::Bottom) |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->panel3->BackColor = System::Drawing::Color::White;
                    this->panel3->Controls->Add(this->pin);
                    this->panel3->Location = System::Drawing::Point(21, 103);
                    this->panel3->Name = L"panel3";
                    this->panel3->Size = System::Drawing::Size(252, 203);
                    this->panel3->TabIndex = 62;
                    //
                    // password
                    //
                    this->password->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            (((System::Windows::Forms::AnchorStyles::Top |
                               System::Windows::Forms::AnchorStyles::Bottom) |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->password->BorderStyle =
                        System::Windows::Forms::BorderStyle::None;
                    this->password->Font =
                        (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
                    this->password->Location = System::Drawing::Point(18, 6);
                    this->password->MaxLength = 15;
                    this->password->Multiline = true;
                    this->password->Name = L"password";
                    this->password->Size = System::Drawing::Size(231, 28);
                    this->password->TabIndex = 29;
                    //
                    // panel4
                    //
                    this->panel4->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            ((System::Windows::Forms::AnchorStyles::Bottom |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->panel4->BackColor = System::Drawing::Color::White;
                    this->panel4->Controls->Add(this->password);
                    this->panel4->Location = System::Drawing::Point(21, 334);
                    this->panel4->Name = L"panel4";
                    this->panel4->Size = System::Drawing::Size(252, 37);
                    this->panel4->TabIndex = 61;
                    //
                    // label1
                    //
                    this->label1->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            ((System::Windows::Forms::AnchorStyles::Bottom |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->label1->AutoSize = true;
                    this->label1->Cursor =
                        System::Windows::Forms::Cursors::Hand;
                    this->label1->Font = (gcnew System::Drawing::Font(
                        L"UTM Daxline Medium", 12));
                    this->label1->ForeColor =
                        System::Drawing::Color::Transparent;
                    this->label1->ImeMode =
                        System::Windows::Forms::ImeMode::NoControl;
                    this->label1->Location = System::Drawing::Point(17, 309);
                    this->label1->Name = L"label1";
                    this->label1->Size = System::Drawing::Size(76, 22);
                    this->label1->TabIndex = 59;
                    this->label1->Text = L"Nhập PIN:";
                    //
                    // button1
                    //
                    this->button1->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            ((System::Windows::Forms::AnchorStyles::Bottom |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->button1->BackColor =
                        System::Drawing::SystemColors::Info;
                    this->button1->Cursor =
                        System::Windows::Forms::Cursors::Hand;
                    this->button1->FlatAppearance->BorderSize = 0;
                    this->button1->FlatStyle =
                        System::Windows::Forms::FlatStyle::Flat;
                    this->button1->Font = (gcnew System::Drawing::Font(
                        L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
                    this->button1->ForeColor = System::Drawing::Color::Teal;
                    this->button1->ImeMode =
                        System::Windows::Forms::ImeMode::NoControl;
                    this->button1->Location = System::Drawing::Point(24, 396);
                    this->button1->Name = L"button1";
                    this->button1->Size = System::Drawing::Size(252, 40);
                    this->button1->TabIndex = 58;
                    this->button1->Text = L"OK";
                    this->button1->UseVisualStyleBackColor = false;
                    //
                    // label7
                    //
                    this->label7->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            ((System::Windows::Forms::AnchorStyles::Top |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->label7->AutoSize = true;
                    this->label7->Font = (gcnew System::Drawing::Font(
                        L"UTM Daxline", 17, System::Drawing::FontStyle::Bold));
                    this->label7->ForeColor = System::Drawing::Color::White;
                    this->label7->ImeMode =
                        System::Windows::Forms::ImeMode::NoControl;
                    this->label7->Location = System::Drawing::Point(77, 30);
                    this->label7->Name = L"label7";
                    this->label7->Size = System::Drawing::Size(123, 30);
                    this->label7->TabIndex = 63;
                    this->label7->Text = L"THÊM CODE";
                    this->label7->TextAlign =
                        System::Drawing::ContentAlignment::MiddleCenter;
                    //
                    // label2
                    //
                    this->label2->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            ((System::Windows::Forms::AnchorStyles::Top |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->label2->Cursor =
                        System::Windows::Forms::Cursors::Hand;
                    this->label2->Font =
                        (gcnew System::Drawing::Font(L"UTM Daxline Medium", 8));
                    this->label2->ForeColor =
                        System::Drawing::Color::Transparent;
                    this->label2->ImeMode =
                        System::Windows::Forms::ImeMode::NoControl;
                    this->label2->Location = System::Drawing::Point(21, 78);
                    this->label2->Name = L"label2";
                    this->label2->Size = System::Drawing::Size(249, 22);
                    this->label2->TabIndex = 64;
                    this->label2->Text =
                        L"Nhập CODE (Mỗi code 1 dòng, vd: ABCDEF,120000 )";
                    //
                    // dataGridViewUsers
                    //
                    this->dataGridViewUsers->AllowUserToAddRows = false;
                    this->dataGridViewUsers->AllowUserToDeleteRows = false;
                    dataGridViewCellStyle1->Alignment = System::Windows::Forms::
                        DataGridViewContentAlignment::MiddleCenter;
                    dataGridViewCellStyle1->BackColor =
                        System::Drawing::Color::Transparent;
                    dataGridViewCellStyle1->Font =
                        (gcnew System::Drawing::Font(L"UTM Daxline", 12));
                    dataGridViewCellStyle1->ForeColor =
                        System::Drawing::Color::Black;
                    dataGridViewCellStyle1->SelectionBackColor =
                        System::Drawing::Color::Transparent;
                    dataGridViewCellStyle1->SelectionForeColor =
                        System::Drawing::Color::Transparent;
                    this->dataGridViewUsers->AlternatingRowsDefaultCellStyle =
                        dataGridViewCellStyle1;
                    this->dataGridViewUsers->AutoSizeColumnsMode = System::
                        Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
                    this->dataGridViewUsers->BackgroundColor =
                        System::Drawing::SystemColors::ButtonFace;
                    this->dataGridViewUsers->CellBorderStyle = System::Windows::
                        Forms::DataGridViewCellBorderStyle::SingleHorizontal;
                    this->dataGridViewUsers->ColumnHeadersBorderStyle = System::
                        Windows::Forms::DataGridViewHeaderBorderStyle::None;
                    dataGridViewCellStyle2->Alignment = System::Windows::Forms::
                        DataGridViewContentAlignment::MiddleCenter;
                    dataGridViewCellStyle2->BackColor =
                        System::Drawing::Color::Teal;
                    dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(
                        L"UTM Daxline", 12, System::Drawing::FontStyle::Bold,
                        System::Drawing::GraphicsUnit::Point,
                        static_cast<System::Byte>(0)));
                    dataGridViewCellStyle2->ForeColor =
                        System::Drawing::Color::White;
                    dataGridViewCellStyle2->SelectionBackColor =
                        System::Drawing::Color::Transparent;
                    dataGridViewCellStyle2->SelectionForeColor =
                        System::Drawing::Color::White;
                    dataGridViewCellStyle2->WrapMode =
                        System::Windows::Forms::DataGridViewTriState::True;
                    this->dataGridViewUsers->ColumnHeadersDefaultCellStyle =
                        dataGridViewCellStyle2;
                    this->dataGridViewUsers->ColumnHeadersHeight = 40;
                    this->dataGridViewUsers->Columns->AddRange(
                        gcnew cli::array<
                            System::Windows::Forms::DataGridViewColumn ^>(3){
                            this->Column1, this->Column2, this->Column3});
                    dataGridViewCellStyle3->Alignment = System::Windows::Forms::
                        DataGridViewContentAlignment::MiddleCenter;
                    dataGridViewCellStyle3->BackColor =
                        System::Drawing::Color::MintCream;
                    dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(
                        L"UTM Facebook K&T", 12,
                        System::Drawing::FontStyle::Regular,
                        System::Drawing::GraphicsUnit::Point,
                        static_cast<System::Byte>(0)));
                    dataGridViewCellStyle3->ForeColor =
                        System::Drawing::SystemColors::ControlText;
                    dataGridViewCellStyle3->SelectionBackColor =
                        System::Drawing::Color::Cyan;
                    dataGridViewCellStyle3->SelectionForeColor =
                        System::Drawing::SystemColors::ControlText;
                    dataGridViewCellStyle3->WrapMode =
                        System::Windows::Forms::DataGridViewTriState::False;
                    this->dataGridViewUsers->DefaultCellStyle =
                        dataGridViewCellStyle3;
                    this->dataGridViewUsers->Dock =
                        System::Windows::Forms::DockStyle::Fill;
                    this->dataGridViewUsers->EnableHeadersVisualStyles = false;
                    this->dataGridViewUsers->GridColor =
                        System::Drawing::SystemColors::ActiveCaptionText;
                    this->dataGridViewUsers->Location =
                        System::Drawing::Point(0, 0);
                    this->dataGridViewUsers->Name = L"dataGridViewUsers";
                    this->dataGridViewUsers->ReadOnly = true;
                    this->dataGridViewUsers->RowHeadersBorderStyle = System::
                        Windows::Forms::DataGridViewHeaderBorderStyle::Single;
                    this->dataGridViewUsers->RowHeadersVisible = false;
                    this->dataGridViewUsers->RowTemplate->DefaultCellStyle
                        ->BackColor = System::Drawing::Color::White;
                    this->dataGridViewUsers->RowTemplate->DefaultCellStyle
                        ->Font =
                        (gcnew System::Drawing::Font(L"UTM Daxline", 12));
                    this->dataGridViewUsers->RowTemplate->DefaultCellStyle
                        ->ForeColor = System::Drawing::Color::Black;
                    this->dataGridViewUsers->RowTemplate->DefaultCellStyle
                        ->SelectionBackColor = System::Drawing::Color::Cyan;
                    this->dataGridViewUsers->RowTemplate->DefaultCellStyle
                        ->SelectionForeColor = System::Drawing::Color::Black;
                    this->dataGridViewUsers->RowTemplate->Height = 40;
                    this->dataGridViewUsers->RowTemplate->ReadOnly = true;
                    this->dataGridViewUsers->RowTemplate->Resizable =
                        System::Windows::Forms::DataGridViewTriState::False;
                    this->dataGridViewUsers->SelectionMode = System::Windows::
                        Forms::DataGridViewSelectionMode::FullRowSelect;
                    this->dataGridViewUsers->Size =
                        System::Drawing::Size(359, 499);
                    this->dataGridViewUsers->TabIndex = 3;
                    //
                    // Column1
                    //
                    this->Column1->HeaderText = L"CODE";
                    this->Column1->Name = L"Column1";
                    this->Column1->ReadOnly = true;
                    //
                    // Column2
                    //
                    this->Column2->HeaderText = L"SỐ TIỀN";
                    this->Column2->Name = L"Column2";
                    this->Column2->ReadOnly = true;
                    //
                    // Column3
                    //
                    this->Column3->HeaderText = L"TRẠNG THÁI";
                    this->Column3->Name = L"Column3";
                    this->Column3->ReadOnly = true;
                    //
                    // CodeForm
                    //
                    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                    this->AutoScaleMode =
                        System::Windows::Forms::AutoScaleMode::Font;
                    this->ClientSize = System::Drawing::Size(658, 499);
                    this->Controls->Add(this->panel2);
                    this->Controls->Add(this->panel1);
                    this->FormBorderStyle =
                        System::Windows::Forms::FormBorderStyle::None;
                    this->Name = L"CodeForm";
                    this->Text = L"CodeForm";
                    this->panel1->ResumeLayout(false);
                    this->panel1->PerformLayout();
                    this->panel2->ResumeLayout(false);
                    this->panel3->ResumeLayout(false);
                    this->panel3->PerformLayout();
                    this->panel4->ResumeLayout(false);
                    this->panel4->PerformLayout();
                    (cli::safe_cast<
                         System::ComponentModel::ISupportInitialize ^>(
                         this->dataGridViewUsers))
                        ->EndInit();
                    this->ResumeLayout(false);
                }
#pragma endregion
	};
}
