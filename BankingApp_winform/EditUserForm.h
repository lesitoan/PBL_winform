#pragma once
#include "AdminForm.h"
#include "TableUsersForm.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public
ref class EditUserForm : public System::Windows::Forms::Form {
  public:
    EditUserForm(void) { InitializeComponent(); }

  protected:
    ~EditUserForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Button ^ btnUndo;

  protected:
  private:
  protected:
  private:
    System::Windows::Forms::Button ^ button1;

  private:
    System::Windows::Forms::TextBox ^ phoneNumber;

  private:
  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Button ^ button3;

  private:
    System::Windows::Forms::TextBox ^ textBox1;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Button ^ button4;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::TextBox ^ textBox2;

  private:
    System::Windows::Forms::Button ^ button5;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::TextBox ^ textBox3;

  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        this->btnUndo = (gcnew System::Windows::Forms::Button());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->phoneNumber = (gcnew System::Windows::Forms::TextBox());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->button3 = (gcnew System::Windows::Forms::Button());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->button4 = (gcnew System::Windows::Forms::Button());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->textBox2 = (gcnew System::Windows::Forms::TextBox());
        this->button5 = (gcnew System::Windows::Forms::Button());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->textBox3 = (gcnew System::Windows::Forms::TextBox());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // btnUndo
        //
        this->btnUndo->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnUndo->BackColor = System::Drawing::Color::RoyalBlue;
        this->btnUndo->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnUndo->FlatAppearance->BorderSize = 0;
        this->btnUndo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnUndo->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnUndo->ForeColor = System::Drawing::Color::Bisque;
        this->btnUndo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnUndo->Location = System::Drawing::Point(329, 415);
        this->btnUndo->Name = L"btnUndo";
        this->btnUndo->Size = System::Drawing::Size(212, 48);
        this->btnUndo->TabIndex = 40;
        this->btnUndo->Text = L"QUAY LẠI";
        this->btnUndo->UseVisualStyleBackColor = false;
        this->btnUndo->Click +=
            gcnew System::EventHandler(this, &EditUserForm::btnUndo_Click);
        //
        // button1
        //
        this->button1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button1->BackColor = System::Drawing::Color::Green;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->BorderSize = 0;
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button1->ForeColor = System::Drawing::Color::Bisque;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(582, 415);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(212, 48);
        this->button1->TabIndex = 39;
        this->button1->Text = L"OK";
        this->button1->UseVisualStyleBackColor = false;
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
        this->phoneNumber->Size = System::Drawing::Size(714, 26);
        this->phoneNumber->TabIndex = 29;
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::Color::DarkOrange;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Black;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(817, 157);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(188, 37);
        this->btnSubmit->TabIndex = 38;
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
        this->panel1->Location = System::Drawing::Point(77, 157);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(734, 37);
        this->panel1->TabIndex = 37;
        //
        // button3
        //
        this->button3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button3->BackColor = System::Drawing::Color::DarkOrange;
        this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button3->FlatAppearance->BorderSize = 0;
        this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button3->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button3->ForeColor = System::Drawing::Color::Black;
        this->button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button3->Location = System::Drawing::Point(816, 219);
        this->button3->Name = L"button3";
        this->button3->Size = System::Drawing::Size(188, 37);
        this->button3->TabIndex = 40;
        this->button3->Text = L"SEARCH";
        this->button3->UseVisualStyleBackColor = false;
        //
        // textBox1
        //
        this->textBox1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->textBox1->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->textBox1->Location = System::Drawing::Point(18, 6);
        this->textBox1->MaxLength = 40;
        this->textBox1->Multiline = true;
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(714, 26);
        this->textBox1->TabIndex = 29;
        //
        // panel2
        //
        this->panel2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel2->Controls->Add(this->textBox1);
        this->panel2->Location = System::Drawing::Point(76, 219);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(734, 37);
        this->panel2->TabIndex = 39;
        //
        // button4
        //
        this->button4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button4->BackColor = System::Drawing::Color::DarkOrange;
        this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button4->FlatAppearance->BorderSize = 0;
        this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button4->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button4->ForeColor = System::Drawing::Color::Black;
        this->button4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button4->Location = System::Drawing::Point(817, 283);
        this->button4->Name = L"button4";
        this->button4->Size = System::Drawing::Size(188, 37);
        this->button4->TabIndex = 42;
        this->button4->Text = L"SEARCH";
        this->button4->UseVisualStyleBackColor = false;
        //
        // panel3
        //
        this->panel3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel3->BackColor = System::Drawing::Color::White;
        this->panel3->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel3->Controls->Add(this->textBox2);
        this->panel3->Location = System::Drawing::Point(77, 283);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(734, 37);
        this->panel3->TabIndex = 41;
        //
        // textBox2
        //
        this->textBox2->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->textBox2->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->textBox2->Location = System::Drawing::Point(18, 6);
        this->textBox2->MaxLength = 40;
        this->textBox2->Multiline = true;
        this->textBox2->Name = L"textBox2";
        this->textBox2->Size = System::Drawing::Size(714, 26);
        this->textBox2->TabIndex = 29;
        //
        // button5
        //
        this->button5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button5->BackColor = System::Drawing::Color::DarkOrange;
        this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button5->FlatAppearance->BorderSize = 0;
        this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button5->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button5->ForeColor = System::Drawing::Color::Black;
        this->button5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button5->Location = System::Drawing::Point(817, 344);
        this->button5->Name = L"button5";
        this->button5->Size = System::Drawing::Size(188, 37);
        this->button5->TabIndex = 44;
        this->button5->Text = L"SEARCH";
        this->button5->UseVisualStyleBackColor = false;
        //
        // panel4
        //
        this->panel4->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->BorderStyle =
            System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel4->Controls->Add(this->textBox3);
        this->panel4->Location = System::Drawing::Point(77, 344);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(734, 37);
        this->panel4->TabIndex = 43;
        //
        // textBox3
        //
        this->textBox3->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->textBox3->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->textBox3->Location = System::Drawing::Point(18, 6);
        this->textBox3->MaxLength = 40;
        this->textBox3->Multiline = true;
        this->textBox3->Name = L"textBox3";
        this->textBox3->Size = System::Drawing::Size(714, 26);
        this->textBox3->TabIndex = 29;
        //
        // EditUserForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->button5);
        this->Controls->Add(this->button4);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->button3);
        this->Controls->Add(this->panel3);
        this->Controls->Add(this->btnUndo);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->btnSubmit);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"EditUserForm";
        this->Text = L"EditUserForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panel3->ResumeLayout(false);
        this->panel3->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->panel4->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void btnUndo_Click(System::Object ^ sender, System::EventArgs ^ e) {
        TableUsersForm ^ tableUsersForm = gcnew TableUsersForm();
        AdminForm ^ adminForm = dynamic_cast<AdminForm ^>(this->ParentForm);
        if (adminForm != nullptr) {
            adminForm->LoadForm2(tableUsersForm);
        }
    }
};
} // namespace BankingAppwinform
