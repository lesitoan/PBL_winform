#pragma once
#include "Companies.h"
#include "CompanyBillingForm.h"

ref class AdminForm;

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for CompanysForm
/// </summary>
public
ref class CompanyForm : public System::Windows::Forms::Form {
  public:
    CompanyForm(int serviceId);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~CompanyForm();

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanelContainer;

  protected:
  private:
  protected:
  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::Panel ^ panel3;

  private:
    System::Windows::Forms::Button ^ btnAccount;

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
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                CompanyForm::typeid));
        this->flowLayoutPanelContainer =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->panel3 = (gcnew System::Windows::Forms::Panel());
        this->btnAccount = (gcnew System::Windows::Forms::Button());
        this->flowLayoutPanelContainer->SuspendLayout();
        this->panel1->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panel3->SuspendLayout();
        this->SuspendLayout();
        //
        // flowLayoutPanelContainer
        //
        this->flowLayoutPanelContainer->BackColor =
            System::Drawing::SystemColors::ButtonFace;
        this->flowLayoutPanelContainer->Controls->Add(this->panel1);
        this->flowLayoutPanelContainer->Controls->Add(this->panel2);
        this->flowLayoutPanelContainer->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->flowLayoutPanelContainer->Location =
            System::Drawing::Point(0, 42);
        this->flowLayoutPanelContainer->Name = L"flowLayoutPanelContainer";
        this->flowLayoutPanelContainer->Size = System::Drawing::Size(1077, 669);
        this->flowLayoutPanelContainer->TabIndex = 1;
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)));
        this->panel1->Controls->Add(this->label1);
        this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panel1->Location = System::Drawing::Point(24, 12);
        this->panel1->Margin = System::Windows::Forms::Padding(24, 12, 0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(139, 147);
        this->panel1->TabIndex = 0;
        this->panel1->Visible = false;
        //
        // label1
        //
        this->label1->BackColor = System::Drawing::Color::Transparent;
        this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->label1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->label1->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label1->Location = System::Drawing::Point(0, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(139, 147);
        this->label1->TabIndex = 1;
        this->label1->Text = L"EVN";
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)));
        this->panel2->Controls->Add(this->label2);
        this->panel2->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panel2->Location = System::Drawing::Point(175, 12);
        this->panel2->Margin = System::Windows::Forms::Padding(12, 12, 0, 0);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(139, 147);
        this->panel2->TabIndex = 1;
        this->panel2->Visible = false;
        //
        // label2
        //
        this->label2->BackColor = System::Drawing::Color::Transparent;
        this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
        this->label2->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->label2->ForeColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->label2->Location = System::Drawing::Point(0, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(139, 147);
        this->label2->TabIndex = 3;
        this->label2->Text = L"ABC";
        this->label2->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // panel3
        //
        this->panel3->BackColor = System::Drawing::SystemColors::ButtonFace;
        this->panel3->Controls->Add(this->btnAccount);
        this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel3->Location = System::Drawing::Point(0, 0);
        this->panel3->Name = L"panel3";
        this->panel3->Size = System::Drawing::Size(1077, 42);
        this->panel3->TabIndex = 2;
        //
        // btnAccount
        //
        this->btnAccount->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top |
                  System::Windows::Forms::AnchorStyles::Bottom) |
                 System::Windows::Forms::AnchorStyles::Left));
        this->btnAccount->BackColor = System::Drawing::Color::Transparent;
        this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnAccount->FlatAppearance->BorderSize = 0;
        this->btnAccount->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::Teal;
        this->btnAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnAccount->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnAccount->ForeColor =
            System::Drawing::SystemColors::HighlightText;
        this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"btnAccount.Image")));
        this->btnAccount->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->Location = System::Drawing::Point(0, 0);
        this->btnAccount->Name = L"btnAccount";
        this->btnAccount->Size = System::Drawing::Size(73, 42);
        this->btnAccount->TabIndex = 2;
        this->btnAccount->TextAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnAccount->UseVisualStyleBackColor = false;
        this->btnAccount->Click +=
            gcnew System::EventHandler(this, &CompanyForm::btnAccount_Click);
        //
        // CompanyForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->flowLayoutPanelContainer);
        this->Controls->Add(this->panel3);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"CompanyForm";
        this->Text = L"CompanysForm";
        this->flowLayoutPanelContainer->ResumeLayout(false);
        this->panel1->ResumeLayout(false);
        this->panel2->ResumeLayout(false);
        this->panel3->ResumeLayout(false);
        this->ResumeLayout(false);
    }
#pragma endregion


  private:
    void LoadCompanies(int serviceId);
    void OnCompanyClick(Object ^ sender, EventArgs ^ e);
    void OnUndoClick(Object ^ sender, EventArgs ^ e);



    array<Companies ^> ^ GetFakeCompanies();
    
    private
      : System::Void
        btnAccount_Click(System::Object ^ sender, System::EventArgs ^ e);
};
} // namespace BankingAppwinform
