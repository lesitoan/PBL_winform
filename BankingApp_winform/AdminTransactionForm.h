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
                    this->dataGridViewTransactions =
                        (gcnew System::Windows::Forms::DataGridView());
                    this->Column1 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column2 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    this->Column3 = (gcnew System::Windows::Forms::
                                         DataGridViewTextBoxColumn());
                    (cli::safe_cast<
                         System::ComponentModel::ISupportInitialize ^>(
                         this->dataGridViewTransactions))
                        ->BeginInit();
                    this->SuspendLayout();
                    //
                    // dataGridViewTransactions
                    //
                    this->dataGridViewTransactions
                        ->ColumnHeadersHeightSizeMode = System::Windows::Forms::
                        DataGridViewColumnHeadersHeightSizeMode::AutoSize;
                    this->dataGridViewTransactions->Columns->AddRange(
                        gcnew cli::array<
                            System::Windows::Forms::DataGridViewColumn ^>(3){
                            this->Column1, this->Column2, this->Column3});
                    this->dataGridViewTransactions->Dock =
                        System::Windows::Forms::DockStyle::Fill;
                    this->dataGridViewTransactions->Location =
                        System::Drawing::Point(0, 0);
                    this->dataGridViewTransactions->Name =
                        L"dataGridViewTransactions";
                    this->dataGridViewTransactions->Size =
                        System::Drawing::Size(1077, 711);
                    this->dataGridViewTransactions->TabIndex = 3;
                    this->dataGridViewTransactions->CellEndEdit += gcnew
                        System::Windows::Forms::DataGridViewCellEventHandler(
                            this, &AdminTransactionForm::
                                      dataGridViewTransactions_CellEndEdit);
                    this->dataGridViewTransactions->CellValueChanged += gcnew
                        System::Windows::Forms::DataGridViewCellEventHandler(
                            this,
                            &AdminTransactionForm::
                                dataGridViewTransactions_CellValueChanged);
                    //
                    // Column1
                    //
                    this->Column1->HeaderText = L"Loại giao dịch";
                    this->Column1->Name = L"Column1";
                    this->Column1->Width = 250;
                    //
                    // Column2
                    //
                    this->Column2->HeaderText = L"Tài khoản";
                    this->Column2->Name = L"Column2";
                    this->Column2->Width = 250;
                    //
                    // Column3
                    //
                    this->Column3->HeaderText = L"Ngày thực hiện";
                    this->Column3->Name = L"Column3";
                    this->Column3->Width = 250;
                    //
                    // AdminTransactionForm
                    //
                    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                    this->AutoScaleMode =
                        System::Windows::Forms::AutoScaleMode::Font;
                    this->BackColor =
                        System::Drawing::SystemColors::ActiveCaption;
                    this->ClientSize = System::Drawing::Size(1077, 711);
                    this->Controls->Add(this->dataGridViewTransactions);
                    this->FormBorderStyle =
                        System::Windows::Forms::FormBorderStyle::None;
                    this->Name = L"AdminTransactionForm";
                    this->Text = L"AdminTransactionForm";
                    this->Load += gcnew System::EventHandler(
                        this, &AdminTransactionForm::AdminTransactionForm_Load);
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
