#pragma once
#include "Services.h"
#include "CompanyForm.h"
#include "HandleFile.h"

ref class AdminForm;
namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for AdminServiceForm
/// </summary>
public
ref class AdminServiceForm : public System::Windows::Forms::Form {
  public:
    AdminServiceForm(void);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~AdminServiceForm();

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanelContainer;

  protected:
  private:
  protected:
  private:
  protected:
  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Label ^ label1;

  private:
    System::Windows::Forms::PictureBox ^ pictureBox1;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::Label ^ label2;

  private:
    System::Windows::Forms::PictureBox ^ pictureBox2;

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
                AdminServiceForm::typeid));
        this->flowLayoutPanelContainer =
            (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
        this->flowLayoutPanelContainer->SuspendLayout();
        this->panel1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->BeginInit();
        this->panel2->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->BeginInit();
        this->SuspendLayout();
        //
        // flowLayoutPanelContainer
        //
        this->flowLayoutPanelContainer->AutoScroll = true;
        this->flowLayoutPanelContainer->BackColor =
            System::Drawing::SystemColors::ButtonFace;
        this->flowLayoutPanelContainer->Controls->Add(this->panel1);
        this->flowLayoutPanelContainer->Controls->Add(this->panel2);
        this->flowLayoutPanelContainer->Dock =
            System::Windows::Forms::DockStyle::Fill;
        this->flowLayoutPanelContainer->Location = System::Drawing::Point(0, 0);
        this->flowLayoutPanelContainer->Name = L"flowLayoutPanelContainer";
        this->flowLayoutPanelContainer->Size = System::Drawing::Size(1077, 711);
        this->flowLayoutPanelContainer->TabIndex = 0;
        //
        // panel1
        //
        this->panel1->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)));
        this->panel1->Controls->Add(this->label1);
        this->panel1->Controls->Add(this->pictureBox1);
        this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->panel1->Location = System::Drawing::Point(24, 12);
        this->panel1->Margin = System::Windows::Forms::Padding(24, 12, 0, 0);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(139, 147);
        this->panel1->TabIndex = 0;
        this->panel1->Visible = false;
        this->panel1->Click +=
            gcnew System::EventHandler(this, &AdminServiceForm::panel1_Click);
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
        this->label1->Location = System::Drawing::Point(0, 98);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(139, 49);
        this->label1->TabIndex = 1;
        this->label1->Text = L"Thanh toán điện";
        this->label1->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // pictureBox1
        //
        this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Top;
        this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox1.Image")));
        this->pictureBox1->Location = System::Drawing::Point(0, 0);
        this->pictureBox1->Name = L"pictureBox1";
        this->pictureBox1->Size = System::Drawing::Size(139, 98);
        this->pictureBox1->TabIndex = 0;
        this->pictureBox1->TabStop = false;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)));
        this->panel2->Controls->Add(this->label2);
        this->panel2->Controls->Add(this->pictureBox2);
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
        this->label2->Location = System::Drawing::Point(0, 98);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(139, 49);
        this->label2->TabIndex = 3;
        this->label2->Text = L"Thanh toán nước";
        this->label2->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // pictureBox2
        //
        this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Top;
        this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image ^>(
            resources->GetObject(L"pictureBox2.Image")));
        this->pictureBox2->Location = System::Drawing::Point(0, 0);
        this->pictureBox2->Name = L"pictureBox2";
        this->pictureBox2->Size = System::Drawing::Size(139, 98);
        this->pictureBox2->TabIndex = 2;
        this->pictureBox2->TabStop = false;
        //
        // AdminServiceForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(1077, 711);
        this->Controls->Add(this->flowLayoutPanelContainer);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"AdminServiceForm";
        this->Text = L"AdminServiceForm";
        this->flowLayoutPanelContainer->ResumeLayout(false);
        this->panel1->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox1))
            ->EndInit();
        this->panel2->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBox2))
            ->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion

    void LoadServices();
    void OnServiceClick(Object ^ sender, EventArgs ^ e);

private:
    System::Void panel1_Click(System::Object ^ sender, System::EventArgs ^ e);
};
} // namespace BankingAppwinform
