#pragma once

namespace BankingAppwinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminTransactionForm
	/// </summary>
	public ref class AdminTransactionForm : public System::Windows::Forms::Form
	{
	public:
		AdminTransactionForm(void)
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
		~AdminTransactionForm()
		{
			if (components)
			{
				delete components;
			}
		}

              private:
                System::Windows::Forms::Button ^ btnSubmit;

              protected:
              private:
                System::Windows::Forms::Panel ^ panel1;

              private:
                System::Windows::Forms::TextBox ^ phoneNumber;

              private:
                System::Windows::Forms::DataGridView ^ dataGridViewTransactions;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column1;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column2;

              private:
                System::Windows::Forms::DataGridViewTextBoxColumn ^ Column3;

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
                    System::Windows::Forms::DataGridViewCellStyle ^
                        dataGridViewCellStyle1 =
                        (gcnew System::Windows::Forms::DataGridViewCellStyle());
                    System::Windows::Forms::DataGridViewCellStyle ^
                        dataGridViewCellStyle2 =
                        (gcnew System::Windows::Forms::DataGridViewCellStyle());
                    System::Windows::Forms::DataGridViewCellStyle ^
                        dataGridViewCellStyle3 =
                        (gcnew System::Windows::Forms::DataGridViewCellStyle());
                    this->btnSubmit = (gcnew System::Windows::Forms::Button());
                    this->panel1 = (gcnew System::Windows::Forms::Panel());
                    this->phoneNumber =
                        (gcnew System::Windows::Forms::TextBox());
                    this->dataGridViewTransactions =
                        (gcnew System::Windows::Forms::DataGridView());
                    this->Column1 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column2 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column3 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->panel1->SuspendLayout();
                    (cli::safe_cast<
                         System::ComponentModel::ISupportInitialize ^>(
                         this->dataGridViewTransactions))
                        ->BeginInit();
                    this->SuspendLayout();
                    //
                    // btnSubmit
                    //
                    this->btnSubmit->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            (System::Windows::Forms::AnchorStyles::Top |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->btnSubmit->BackColor =
                        System::Drawing::Color::DarkOrange;
                    this->btnSubmit->Cursor =
                        System::Windows::Forms::Cursors::Hand;
                    this->btnSubmit->FlatAppearance->BorderSize = 0;
                    this->btnSubmit->FlatStyle =
                        System::Windows::Forms::FlatStyle::Flat;
                    this->btnSubmit->Font = (gcnew System::Drawing::Font(
                        L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
                    this->btnSubmit->ForeColor = System::Drawing::Color::Black;
                    this->btnSubmit->ImeMode =
                        System::Windows::Forms::ImeMode::NoControl;
                    this->btnSubmit->Location = System::Drawing::Point(863, 13);
                    this->btnSubmit->Name = L"btnSubmit";
                    this->btnSubmit->Size = System::Drawing::Size(188, 37);
                    this->btnSubmit->TabIndex = 36;
                    this->btnSubmit->Text = L"SEARCH";
                    this->btnSubmit->UseVisualStyleBackColor = false;
                    //
                    // panel1
                    //
                    this->panel1->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            ((System::Windows::Forms::AnchorStyles::Top |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->panel1->BackColor = System::Drawing::Color::White;
                    this->panel1->BorderStyle =
                        System::Windows::Forms::BorderStyle::FixedSingle;
                    this->panel1->Controls->Add(this->phoneNumber);
                    this->panel1->Location = System::Drawing::Point(24, 12);
                    this->panel1->Name = L"panel1";
                    this->panel1->Size = System::Drawing::Size(822, 37);
                    this->panel1->TabIndex = 35;
                    //
                    // phoneNumber
                    //
                    this->phoneNumber->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            (((System::Windows::Forms::AnchorStyles::Top |
                               System::Windows::Forms::AnchorStyles::Bottom) |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->phoneNumber->BorderStyle =
                        System::Windows::Forms::BorderStyle::None;
                    this->phoneNumber->Font =
                        (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
                    this->phoneNumber->Location = System::Drawing::Point(18, 6);
                    this->phoneNumber->MaxLength = 40;
                    this->phoneNumber->Multiline = true;
                    this->phoneNumber->Name = L"phoneNumber";
                    this->phoneNumber->Size = System::Drawing::Size(802, 26);
                    this->phoneNumber->TabIndex = 29;
                    //
                    // dataGridViewTransactions
                    //
                    this->dataGridViewTransactions->AllowUserToAddRows = false;
                    this->dataGridViewTransactions->AllowUserToDeleteRows =
                        false;
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
                    this->dataGridViewTransactions
                        ->AlternatingRowsDefaultCellStyle =
                        dataGridViewCellStyle1;
                    this->dataGridViewTransactions->Anchor =
                        static_cast<System::Windows::Forms::AnchorStyles>(
                            (((System::Windows::Forms::AnchorStyles::Top |
                               System::Windows::Forms::AnchorStyles::Bottom) |
                              System::Windows::Forms::AnchorStyles::Left) |
                             System::Windows::Forms::AnchorStyles::Right));
                    this->dataGridViewTransactions->AutoSizeColumnsMode =
                        System::Windows::Forms::
                            DataGridViewAutoSizeColumnsMode::Fill;
                    this->dataGridViewTransactions->BackgroundColor =
                        System::Drawing::SystemColors::ButtonFace;
                    this->dataGridViewTransactions->CellBorderStyle =
                        System::Windows::Forms::DataGridViewCellBorderStyle::
                            SingleHorizontal;
                    this->dataGridViewTransactions->ColumnHeadersBorderStyle =
                        System::Windows::Forms::DataGridViewHeaderBorderStyle::
                            None;
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
                    this->dataGridViewTransactions
                        ->ColumnHeadersDefaultCellStyle =
                        dataGridViewCellStyle2;
                    this->dataGridViewTransactions->ColumnHeadersHeight = 40;
                    this->dataGridViewTransactions->Columns->AddRange(
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
                    this->dataGridViewTransactions->DefaultCellStyle =
                        dataGridViewCellStyle3;
                    this->dataGridViewTransactions->EnableHeadersVisualStyles =
                        false;
                    this->dataGridViewTransactions->GridColor =
                        System::Drawing::SystemColors::ActiveCaptionText;
                    this->dataGridViewTransactions->Location =
                        System::Drawing::Point(24, 65);
                    this->dataGridViewTransactions->Name =
                        L"dataGridViewTransactions";
                    this->dataGridViewTransactions->ReadOnly = true;
                    this->dataGridViewTransactions->RowHeadersBorderStyle =
                        System::Windows::Forms::DataGridViewHeaderBorderStyle::
                            Single;
                    this->dataGridViewTransactions->RowHeadersVisible = false;
                    this->dataGridViewTransactions->RowTemplate
                        ->DefaultCellStyle->BackColor =
                        System::Drawing::Color::White;
                    this->dataGridViewTransactions->RowTemplate
                        ->DefaultCellStyle->Font =
                        (gcnew System::Drawing::Font(L"UTM Daxline", 12));
                    this->dataGridViewTransactions->RowTemplate
                        ->DefaultCellStyle->ForeColor =
                        System::Drawing::Color::Black;
                    this->dataGridViewTransactions->RowTemplate
                        ->DefaultCellStyle->SelectionBackColor =
                        System::Drawing::Color::Cyan;
                    this->dataGridViewTransactions->RowTemplate
                        ->DefaultCellStyle->SelectionForeColor =
                        System::Drawing::Color::Black;
                    this->dataGridViewTransactions->RowTemplate->Height = 40;
                    this->dataGridViewTransactions->RowTemplate->ReadOnly =
                        true;
                    this->dataGridViewTransactions->RowTemplate->Resizable =
                        System::Windows::Forms::DataGridViewTriState::False;
                    this->dataGridViewTransactions->SelectionMode =
                        System::Windows::Forms::DataGridViewSelectionMode::
                            FullRowSelect;
                    this->dataGridViewTransactions->Size =
                        System::Drawing::Size(1027, 621);
                    this->dataGridViewTransactions->TabIndex = 34;
                    //
                    // Column1
                    //
                    this->Column1->HeaderText = L"Column1";
                    this->Column1->Name = L"Column1";
                    this->Column1->ReadOnly = true;
                    //
                    // Column2
                    //
                    this->Column2->HeaderText = L"Column2";
                    this->Column2->Name = L"Column2";
                    this->Column2->ReadOnly = true;
                    //
                    // Column3
                    //
                    this->Column3->HeaderText = L"Column3";
                    this->Column3->Name = L"Column3";
                    this->Column3->ReadOnly = true;
                    //
                    // AdminTransactionForm
                    //
                    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                    this->AutoScaleMode =
                        System::Windows::Forms::AutoScaleMode::Font;
                    this->BackColor = System::Drawing::SystemColors::ButtonFace;
                    this->ClientSize = System::Drawing::Size(1077, 711);
                    this->Controls->Add(this->btnSubmit);
                    this->Controls->Add(this->panel1);
                    this->Controls->Add(this->dataGridViewTransactions);
                    this->FormBorderStyle =
                        System::Windows::Forms::FormBorderStyle::None;
                    this->Name = L"AdminTransactionForm";
                    this->Text = L"AdminTransactionForm";
                    this->Load += gcnew System::EventHandler(
                        this, &AdminTransactionForm::AdminTransactionForm_Load);
                    this->panel1->ResumeLayout(false);
                    this->panel1->PerformLayout();
                    (cli::safe_cast<
                         System::ComponentModel::ISupportInitialize ^>(
                         this->dataGridViewTransactions))
                        ->EndInit();
                    this->ResumeLayout(false);
                }
#pragma endregion
              private:
                System::Void AdminTransactionForm_Load(System::Object ^ sender,
                                                       System::EventArgs ^ e) {

                    DataGridViewComboBoxColumn ^ comboColumn =
                        gcnew DataGridViewComboBoxColumn();
                    comboColumn->HeaderText = "Trạng thái";
                    comboColumn->Name = "Status";
                    comboColumn->Items->AddRange(
                        gcnew cli::array<System::Object ^>{"pending",
                                                           "complete"});
                    comboColumn->Width = 250; // Đặt chiều rộng
                    dataGridViewTransactions->Columns->Add(comboColumn);


                    for (int i = 1; i <= 30; i++) {
                        System::String ^ type =
                            (i % 2 == 0)
                                ? "transfer"
                                : "deposit"; // Chuyển khoản hoặc nạp tiền
                        System::String ^ account =
                            "09" + i.ToString("00000000"); // Số tài khoản giả
                        System::String ^ date =
                            "08/" + (i % 12 + 1).ToString("00") +
                            "/2025"; // Ngày tháng ngẫu nhiên từ 08/01 đến
                                     // 08/12/2025
                        System::String ^ status =
                            (i % 3 == 0) ? "pending"
                                         : "complete"; // Trạng thái: pending
                                                       // hoặc complete

                        dataGridViewTransactions->Rows->Add(type, account, date,
                                                            status);
                    }
                }

              private:
                System::Void dataGridViewTransactions_CellEndEdit(
                    System::Object ^ sender,
                    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {
                    //int rowIndex = e->RowIndex;
                    //int colIndex = e->ColumnIndex;

                    //// Lấy giá trị sau khi chỉnh sửa
                    //System::String ^ newValue =
                    //    dataGridViewTransactions->Rows[rowIndex]
                    //        ->Cells[colIndex]
                    //        ->Value->ToString();

                    //MessageBox::Show("Bạn đã sửa ô [" + rowIndex + ", " +
                    //                 colIndex + "] thành: " + newValue);
                }

              private:
                System::Void dataGridViewTransactions_CellValueChanged(
                    System::Object ^ sender,
                    System::Windows::Forms::DataGridViewCellEventArgs ^ e) {
                    if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
                        // Lấy ô hiện tại
                        DataGridViewCell ^ cell =
                            dataGridViewTransactions->Rows[e->RowIndex]
                                ->Cells[e->ColumnIndex];

                        // Kiểm tra cell có null không trước khi dùng
                        if (cell != nullptr && cell->Value != nullptr) {
                            System::String ^ selectedValue =
                                cell->Value->ToString();
                            MessageBox::Show("Bạn đã chọn: " + selectedValue);
                        } else {
                            MessageBox::Show("Ô này chưa có giá trị!");
                        }
                    }
                }
          };
          }
