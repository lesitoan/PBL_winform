#pragma once
#include "AdminForm.h"
#include "LoadChildForm.h"
#include "User.h"
#include "HandleFile.h"
#include "AddUserForm.h"


ref class EditUserForm;

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::Text::RegularExpressions;

/// <summary>
/// Summary for AdminClientForm
/// </summary>
public
ref class TableUsersForm : public System::Windows::Forms::Form {
  public:
    TableUsersForm(void);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~TableUsersForm();

  private:


  protected:
  private:


  private:


  private:


  private:


  private:


  private:
    System::Windows::Forms::DataGridView ^ dataGridViewUsers;

  private:
  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::TextBox ^ findText;

  private:
    System::Windows::Forms::Button ^ btnFind;

  private:
    System::Windows::Forms::Button ^ btnAddUser;

  private:


  private:


  private:


  private:
    System::Windows::Forms::Button ^ btnModify;

  private:
    System::Windows::Forms::Button ^ btnLock;

  private:
  private:


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
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column6;

  private:
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Column7;

    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle1 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle2 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle ^ dataGridViewCellStyle3 =
            (gcnew System::Windows::Forms::DataGridViewCellStyle());
        this->dataGridViewUsers =
            (gcnew System::Windows::Forms::DataGridView());
        this->Column1 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column2 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column3 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column4 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column5 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column6 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column7 =
            (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->findText = (gcnew System::Windows::Forms::TextBox());
        this->btnFind = (gcnew System::Windows::Forms::Button());
        this->btnAddUser = (gcnew System::Windows::Forms::Button());
        this->btnModify = (gcnew System::Windows::Forms::Button());
        this->btnLock = (gcnew System::Windows::Forms::Button());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewUsers))
            ->BeginInit();
        this->panel1->SuspendLayout();
        this->SuspendLayout();
        //
        // dataGridViewUsers
        //
        this->dataGridViewUsers->AllowUserToAddRows = false;
        this->dataGridViewUsers->AllowUserToDeleteRows = false;
        dataGridViewCellStyle1->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle1->BackColor = System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
        dataGridViewCellStyle1->SelectionBackColor =
            System::Drawing::Color::Transparent;
        dataGridViewCellStyle1->SelectionForeColor =
            System::Drawing::Color::Transparent;
        this->dataGridViewUsers->AlternatingRowsDefaultCellStyle =
            dataGridViewCellStyle1;
        this->dataGridViewUsers->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->dataGridViewUsers->AutoSizeColumnsMode =
            System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewUsers->BackgroundColor =
            System::Drawing::SystemColors::ButtonFace;
        this->dataGridViewUsers->CellBorderStyle = System::Windows::Forms::
            DataGridViewCellBorderStyle::SingleHorizontal;
        this->dataGridViewUsers->ColumnHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
        dataGridViewCellStyle2->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle2->BackColor = System::Drawing::Color::Teal;
        dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
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
            gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(7){
                this->Column1, this->Column2, this->Column3, this->Column4,
                this->Column5, this->Column6, this->Column7});
        dataGridViewCellStyle3->Alignment =
            System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
        dataGridViewCellStyle3->BackColor = System::Drawing::Color::MintCream;
        dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(
            L"UTM Facebook K&T", 12, System::Drawing::FontStyle::Regular,
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
        this->dataGridViewUsers->DefaultCellStyle = dataGridViewCellStyle3;
        this->dataGridViewUsers->EnableHeadersVisualStyles = false;
        this->dataGridViewUsers->GridColor =
            System::Drawing::SystemColors::ActiveCaptionText;
        this->dataGridViewUsers->Location = System::Drawing::Point(26, 79);
        this->dataGridViewUsers->Name = L"dataGridViewUsers";
        this->dataGridViewUsers->ReadOnly = true;
        this->dataGridViewUsers->RowHeadersBorderStyle =
            System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        this->dataGridViewUsers->RowHeadersVisible = false;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle->BackColor =
            System::Drawing::Color::White;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline", 12));
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle->ForeColor =
            System::Drawing::Color::Black;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle
            ->SelectionBackColor = System::Drawing::Color::Cyan;
        this->dataGridViewUsers->RowTemplate->DefaultCellStyle
            ->SelectionForeColor = System::Drawing::Color::Black;
        this->dataGridViewUsers->RowTemplate->Height = 40;
        this->dataGridViewUsers->RowTemplate->ReadOnly = true;
        this->dataGridViewUsers->RowTemplate->Resizable =
            System::Windows::Forms::DataGridViewTriState::False;
        this->dataGridViewUsers->SelectionMode =
            System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridViewUsers->Size = System::Drawing::Size(929, 609);
        this->dataGridViewUsers->TabIndex = 2;
        this->dataGridViewUsers->CellContentClick +=
            gcnew System::Windows::Forms::DataGridViewCellEventHandler(
                this, &TableUsersForm::dataGridView1_CellContentClick);
        //
        // Column1
        //
        this->Column1->HeaderText = L"Tên";
        this->Column1->Name = L"Column1";
        this->Column1->ReadOnly = true;
        //
        // Column2
        //
        this->Column2->HeaderText = L"SĐT";
        this->Column2->Name = L"Column2";
        this->Column2->ReadOnly = true;
        //
        // Column3
        //
        this->Column3->HeaderText = L"STK";
        this->Column3->Name = L"Column3";
        this->Column3->ReadOnly = true;
        //
        // Column4
        //
        this->Column4->HeaderText = L"Số dư";
        this->Column4->Name = L"Column4";
        this->Column4->ReadOnly = true;
        //
        // Column5
        //
        this->Column5->HeaderText = L"Vài trò";
        this->Column5->Name = L"Column5";
        this->Column5->ReadOnly = true;
        //
        // Column6
        //
        this->Column6->HeaderText = L"Tên NH";
        this->Column6->Name = L"Column6";
        this->Column6->ReadOnly = true;
        //
        // Column7
        //
        this->Column7->HeaderText = L"Trạng thái";
        this->Column7->Name = L"Column7";
        this->Column7->ReadOnly = true;
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
        this->panel1->Controls->Add(this->findText);
        this->panel1->Location = System::Drawing::Point(26, 26);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(734, 37);
        this->panel1->TabIndex = 32;
        //
        // findText
        //
        this->findText->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->findText->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->findText->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->findText->Location = System::Drawing::Point(18, 6);
        this->findText->MaxLength = 40;
        this->findText->Multiline = true;
        this->findText->Name = L"findText";
        this->findText->Size = System::Drawing::Size(714, 26);
        this->findText->TabIndex = 29;
        //
        // btnFind
        //
        this->btnFind->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnFind->BackColor = System::Drawing::Color::DarkOrange;
        this->btnFind->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnFind->FlatAppearance->BorderSize = 0;
        this->btnFind->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnFind->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnFind->ForeColor = System::Drawing::Color::Black;
        this->btnFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnFind->Location = System::Drawing::Point(766, 26);
        this->btnFind->Name = L"btnFind";
        this->btnFind->Size = System::Drawing::Size(188, 37);
        this->btnFind->TabIndex = 33;
        this->btnFind->Text = L"TÌM";
        this->btnFind->UseVisualStyleBackColor = false;
        this->btnFind->Click +=
            gcnew System::EventHandler(this, &TableUsersForm::btnFind_Click);
        //
        // btnAddUser
        //
        this->btnAddUser->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnAddUser->BackColor = System::Drawing::Color::Green;
        this->btnAddUser->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAddUser->FlatAppearance->BorderSize = 0;
        this->btnAddUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAddUser->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnAddUser->ForeColor = System::Drawing::Color::Bisque;
        this->btnAddUser->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnAddUser->Location = System::Drawing::Point(961, 79);
        this->btnAddUser->Name = L"btnAddUser";
        this->btnAddUser->Size = System::Drawing::Size(90, 73);
        this->btnAddUser->TabIndex = 34;
        this->btnAddUser->Text = L"THÊM";
        this->btnAddUser->UseVisualStyleBackColor = false;
        this->btnAddUser->Click +=
            gcnew System::EventHandler(this, &TableUsersForm::btnAddUser_Click);
        //
        // btnModify
        //
        this->btnModify->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnModify->BackColor = System::Drawing::Color::RoyalBlue;
        this->btnModify->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnModify->FlatAppearance->BorderSize = 0;
        this->btnModify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnModify->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnModify->ForeColor = System::Drawing::Color::Bisque;
        this->btnModify->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnModify->Location = System::Drawing::Point(961, 158);
        this->btnModify->Name = L"btnModify";
        this->btnModify->Size = System::Drawing::Size(90, 73);
        this->btnModify->TabIndex = 35;
        this->btnModify->Text = L"SỬA";
        this->btnModify->UseVisualStyleBackColor = false;
        this->btnModify->Click +=
            gcnew System::EventHandler(this, &TableUsersForm::btnModify_Click);
        //
        // btnLock
        //
        this->btnLock->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnLock->BackColor = System::Drawing::Color::Red;
        this->btnLock->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnLock->FlatAppearance->BorderSize = 0;
        this->btnLock->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnLock->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnLock->ForeColor = System::Drawing::Color::Bisque;
        this->btnLock->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnLock->Location = System::Drawing::Point(961, 237);
        this->btnLock->Name = L"btnLock";
        this->btnLock->Size = System::Drawing::Size(90, 73);
        this->btnLock->TabIndex = 36;
        this->btnLock->Text = L"KHÓA";
        this->btnLock->UseVisualStyleBackColor = false;
        this->btnLock->Click +=
            gcnew System::EventHandler(this, &TableUsersForm::btnLock_Click);
        //
        // TableUsersForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::White;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->btnLock);
        this->Controls->Add(this->btnModify);
        this->Controls->Add(this->btnAddUser);
        this->Controls->Add(this->btnFind);
        this->Controls->Add(this->panel1);
        this->Controls->Add(this->dataGridViewUsers);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"TableUsersForm";
        this->Text = L"AdminClientForm";
        this->Load += gcnew System::EventHandler(
            this, &TableUsersForm::AdminClientForm_Load);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->dataGridViewUsers))
            ->EndInit();
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void dataGridView1_CellContentClick(
        System::Object ^ sender,
        System::Windows::Forms::DataGridViewCellEventArgs ^ e);

  private:
    System::Void AdminClientForm_Load(System::Object ^ sender,
                                      System::EventArgs ^ e);

  private:
    System::Void btnModify_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    private: 
    array<User ^> ^ users = nullptr;

 private:
    void loadUsers(array<User ^> ^ usersArr) {
      dataGridViewUsers->Rows->Clear();

        

        if (usersArr == nullptr) {
            usersArr = HandleFile::ReadUserArray("users.dat");
            this->users = usersArr;
        }
        if (usersArr == nullptr) {
          return;
        }
        for (int i = 0; i < usersArr->Length; i++) {

          if (usersArr[i]->getRole() == "admin") {
              continue;
          }
          String ^ status = usersArr[i]->Status == 1 ? L"Hoạt động" : L"Khóa";
          dataGridViewUsers->Rows->Add(
              usersArr[i]->getFullName(), usersArr[i]->getPhoneNumber(),
              usersArr[i]->getBalance(),
                
              usersArr[i]->getAccountNumber(), usersArr[i]->getRole(),
              usersArr[i]->getBankName(),
              status
          );

          int lastRow = dataGridViewUsers->Rows->Count - 1;
          dataGridViewUsers->Rows[lastRow]->Tag = usersArr[i];
      }
      this->dataGridViewUsers->CellClick += gcnew DataGridViewCellEventHandler(
            this, &TableUsersForm::handleUserRowClick);
    }

    private:
    User ^ userSelected = nullptr;

        
    System::Void handleUserRowClick(
        System::Object ^ sender,
        System::Windows::Forms::DataGridViewCellEventArgs ^ e) {
        if (e->RowIndex < 0) {
            return;
        }
        DataGridViewRow ^ row = dataGridViewUsers->Rows[e->RowIndex];
        this->userSelected = dynamic_cast<User ^>(row->Tag);

        if (userSelected->Status) {
            btnLock->Text = L"KHÓA";
            btnLock->BackColor = System::Drawing::Color::Red;
        } else {
            btnLock->Text = L"MỞ KHÓA";
            btnLock->BackColor = System::Drawing::Color::Green;
        }
    } 


private:
    System::Void btnLock_Click(System::Object ^ sender, System::EventArgs ^ e) {
        System::Windows::Forms::DialogResult result;
        if (userSelected == nullptr) {
            MessageBox::Show(L"Vui lòng chọn một tài khoản", L"Thông báo",
                             MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }
        result = MessageBox::Show(
            L"Bạn có chắc chắn muốn lưu lại thay đổi không ?", L"Lưu thay đổi",
            MessageBoxButtons::YesNo, MessageBoxIcon::Question);
        if (result == System::Windows::Forms::DialogResult::No) {
            return;
        }

        if (users == nullptr) {
            return;
        }
        for (int i = 0; i < users->Length; i++) {
            if (users[i]->getAccountNumber() == userSelected->getAccountNumber()) {
                users[i]->Status = 1 - users[i]->Status;
                break;
            }
        }
        HandleFile::WriteUserArray(users, "users.dat");
        MessageBox::Show(L"Thay đổi đã được lưu lại", L"Thành công",
                         MessageBoxButtons::OK, MessageBoxIcon::Information);
        loadUsers(nullptr);

    }

  private:
    void btnFind_Click(System::Object ^ sender, System::EventArgs ^ e) {
        String ^ find = this->findText->Text;
        if (find == "")
            users = HandleFile::ReadUserArray("users.dat");

        List<User ^> ^ matchedUsers = gcnew List<User ^>();

        for (int i = 0; i < users->Length; i++) {
            // Chuyển input thành regex pattern
            String ^ pattern = ".*" + Regex::Escape(find) + ".*";
            // Kiểm tra tên có chứa input không (không phân biệt hoa thường)
            bool isMatch = Regex::IsMatch(users[i]->getFullName(), pattern,
                                          RegexOptions::IgnoreCase);
            if (isMatch) { 
                matchedUsers->Add(users[i]);
            }
        }
        this->findText->Text = "";
        loadUsers(matchedUsers->ToArray());
    }

  private:
    System::Void btnAddUser_Click(System::Object ^ sender,
                                  System::EventArgs ^ e) {
        AddUserForm ^ addUserForm = gcnew AddUserForm();
        addUserForm->createUserSuccess +=
            gcnew EventHandler(this, &TableUsersForm::onCreateUserSuccess);
        addUserForm->ShowDialog();
    }

    System::Void TableUsersForm::onCreateUserSuccess(System::Object ^ sender,
                                           System::EventArgs ^ e) {
        loadUsers(nullptr);
    }


};
} // namespace BankingAppwinform
