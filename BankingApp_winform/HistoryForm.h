#pragma once

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for HistoryForm
/// </summary>
public
ref class HistoryForm : public System::Windows::Forms::Form {
  public:
    HistoryForm(void) {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~HistoryForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::Panel ^ panel1;

  protected:
  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Label ^ label7;

  private:
    System::Windows::Forms::Label ^ label6;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Label ^ label4;

  private:
    System::Windows::Forms::Label ^ label3;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Label ^ label8;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Label ^ label9;

  private:
    System::Windows::Forms::Label ^ label11;

  private:
    System::Windows::Forms::Label ^ label10;

  private:
    System::Windows::Forms::Label ^ label13;

  private:
    System::Windows::Forms::Label ^ label12;

  private:
  private:
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
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->label8 = (gcnew System::Windows::Forms::Label());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->label10 = (gcnew System::Windows::Forms::Label());
        this->label11 = (gcnew System::Windows::Forms::Label());
        this->label12 = (gcnew System::Windows::Forms::Label());
        this->label13 = (gcnew System::Windows::Forms::Label());
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->SuspendLayout();
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel1->Controls->Add(this->label7);
        this->panel1->Controls->Add(this->label6);
        this->panel1->Controls->Add(this->label5);
        this->panel1->Controls->Add(this->label4);
        this->panel1->Controls->Add(this->label3);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Location = System::Drawing::Point(22, 13);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(254, 368);
        this->panel1->TabIndex = 0;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->panel2->Controls->Add(this->label13);
        this->panel2->Controls->Add(this->label12);
        this->panel2->Controls->Add(this->label8);
        this->panel2->Controls->Add(this->label2);
        this->panel2->Controls->Add(this->label9);
        this->panel2->Controls->Add(this->label11);
        this->panel2->Controls->Add(this->label10);
        this->panel2->Location = System::Drawing::Point(298, 13);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(254, 368);
        this->panel2->TabIndex = 1;
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(53, 11);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(150, 21);
        this->label1->TabIndex = 8;
        this->label1->Text = L"L?ch su chuyen tien";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(74, 11);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(117, 21);
        this->label2->TabIndex = 9;
        this->label2->Text = L"L?ch su rut tien";
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label3->ForeColor = System::Drawing::Color::Green;
        this->label3->Location = System::Drawing::Point(39, 50);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(175, 21);
        this->label3->TabIndex = 9;
        this->label3->Text = L"+435.000? 20/02/2025";
        this->label3->Click +=
            gcnew System::EventHandler(this, &HistoryForm::label3_Click);
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label4->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label4->Location = System::Drawing::Point(39, 83);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(175, 21);
        this->label4->TabIndex = 10;
        this->label4->Text = L"-435.000? 20/02/2025";
        this->label4->Click +=
            gcnew System::EventHandler(this, &HistoryForm::label4_Click);
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::Color::Green;
        this->label5->Location = System::Drawing::Point(39, 118);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(175, 21);
        this->label5->TabIndex = 11;
        this->label5->Text = L"+435.000? 20/02/2025";
        this->label5->Click +=
            gcnew System::EventHandler(this, &HistoryForm::label5_Click);
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label6->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label6->Location = System::Drawing::Point(39, 152);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(175, 21);
        this->label6->TabIndex = 12;
        this->label6->Text = L"-435.000? 20/02/2025";
        this->label6->Click +=
            gcnew System::EventHandler(this, &HistoryForm::label6_Click);
        //
        // label7
        //
        this->label7->AutoSize = true;
        this->label7->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label7->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label7->Location = System::Drawing::Point(39, 186);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(175, 21);
        this->label7->TabIndex = 13;
        this->label7->Text = L"-435.000? 20/02/2025";
        this->label7->Click +=
            gcnew System::EventHandler(this, &HistoryForm::label7_Click);
        //
        // label8
        //
        this->label8->AutoSize = true;
        this->label8->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label8->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label8->Location = System::Drawing::Point(45, 50);
        this->label8->Name = L"label8";
        this->label8->Size = System::Drawing::Size(175, 21);
        this->label8->TabIndex = 18;
        this->label8->Text = L"-435.000? 20/02/2025";
        //
        // label9
        //
        this->label9->AutoSize = true;
        this->label9->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label9->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label9->Location = System::Drawing::Point(45, 152);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(175, 21);
        this->label9->TabIndex = 17;
        this->label9->Text = L"-435.000? 20/02/2025";
        //
        // label10
        //
        this->label10->AutoSize = true;
        this->label10->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label10->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label10->Location = System::Drawing::Point(45, 118);
        this->label10->Name = L"label10";
        this->label10->Size = System::Drawing::Size(0, 21);
        this->label10->TabIndex = 16;
        //
        // label11
        //
        this->label11->AutoSize = true;
        this->label11->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label11->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label11->Location = System::Drawing::Point(45, 83);
        this->label11->Name = L"label11";
        this->label11->Size = System::Drawing::Size(175, 21);
        this->label11->TabIndex = 15;
        this->label11->Text = L"-435.000? 20/02/2025";
        //
        // label12
        //
        this->label12->AutoSize = true;
        this->label12->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label12->ForeColor = System::Drawing::Color::Green;
        this->label12->Location = System::Drawing::Point(45, 118);
        this->label12->Name = L"label12";
        this->label12->Size = System::Drawing::Size(175, 21);
        this->label12->TabIndex = 14;
        this->label12->Text = L"+435.000? 20/02/2025";
        //
        // label13
        //
        this->label13->AutoSize = true;
        this->label13->Font =
            (gcnew System::Drawing::Font(L"#9Slide03 SVN-Kelson Sans Bold", 12,
                                         System::Drawing::FontStyle::Bold,
                                         System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(0)));
        this->label13->ForeColor = System::Drawing::Color::Green;
        this->label13->Location = System::Drawing::Point(45, 186);
        this->label13->Name = L"label13";
        this->label13->Size = System::Drawing::Size(175, 21);
        this->label13->TabIndex = 14;
        this->label13->Text = L"+435.000? 20/02/2025";
        //
        // HistoryForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(573, 393);
        this->Controls->Add(this->panel2);
        this->Controls->Add(this->panel1);
        this->Name = L"HistoryForm";
        this->Text = L"HistoryForm";
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void label4_Click(System::Object ^ sender, System::EventArgs ^ e) {}

  private:
    System::Void label6_Click(System::Object ^ sender, System::EventArgs ^ e) {}

  private:
    System::Void label5_Click(System::Object ^ sender, System::EventArgs ^ e) {}

  private:
    System::Void label3_Click(System::Object ^ sender, System::EventArgs ^ e) {}

  private:
    System::Void label7_Click(System::Object ^ sender, System::EventArgs ^ e) {}
};
} // namespace BankingAppwinform
