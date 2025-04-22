#pragma once
#include "HandleFile.h"
#include "Transaction.h"
#include "User.h"
#include "SelectReceiverEventArgs.h"
#include "UserServices.h"

#include"GradientHelper.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


public
ref class SelectReceiverForm : public System::Windows::Forms::Form {
  public:
    SelectReceiverForm(User ^ user);

  protected:
    ~SelectReceiverForm();

  private:
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::Panel ^ panel4;
    System::Windows::Forms::ComboBox ^ selectAccHistory;
    System::Windows::Forms::Button ^ btnClose;
    System::Windows::Forms::Button ^ btnSubmit;
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                SelectReceiverForm::typeid));
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectAccHistory = (gcnew System::Windows::Forms::ComboBox());
        this->btnClose = (gcnew System::Windows::Forms::Button());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // label5
        //
        this->label5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->BackColor = System::Drawing::Color::Transparent;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::Color::White;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(47, 46);
        this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(205, 26);
        this->label5->TabIndex = 105;
        this->label5->Text = L"Select Recent Account";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->selectAccHistory);
        this->panel4->Location = System::Drawing::Point(52, 76);
        this->panel4->Margin = System::Windows::Forms::Padding(4);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(495, 46);
        this->panel4->TabIndex = 106;
        //
        // selectAccHistory
        //
        this->selectAccHistory->Anchor =
            System::Windows::Forms::AnchorStyles::Left;
        this->selectAccHistory->DropDownStyle =
            System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectAccHistory->FlatStyle =
            System::Windows::Forms::FlatStyle::Popup;
        this->selectAccHistory->Font =
            (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
        this->selectAccHistory->ForeColor = System::Drawing::Color::Black;
        this->selectAccHistory->FormattingEnabled = true;
        this->selectAccHistory->Location = System::Drawing::Point(1, 9);
        this->selectAccHistory->Margin = System::Windows::Forms::Padding(4);
        this->selectAccHistory->Name = L"selectAccHistory";
        this->selectAccHistory->Size = System::Drawing::Size(488, 33);
        this->selectAccHistory->TabIndex = 3;
        //
        // btnClose
        //
        this->btnClose->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnClose->BackColor = System::Drawing::Color::Firebrick;
        this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClose->FlatAppearance->BorderColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
        this->btnClose->FlatAppearance->CheckedBackColor =
            System::Drawing::Color::White;
        this->btnClose->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnClose->FlatAppearance->MouseOverBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClose->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnClose->ForeColor = System::Drawing::Color::White;
        this->btnClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnClose->Location = System::Drawing::Point(53, 154);
        this->btnClose->Margin = System::Windows::Forms::Padding(4);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(229, 59);
        this->btnClose->TabIndex = 104;
        this->btnClose->Text = L"Cancel";
        this->btnClose->UseVisualStyleBackColor = false;
        this->btnClose->Click += gcnew System::EventHandler(
            this, &SelectReceiverForm::btnClose_Click_1);
        //
        // btnSubmit
        //
        this->btnSubmit->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnSubmit->BackColor = System::Drawing::Color::Green;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
        this->btnSubmit->FlatAppearance->CheckedBackColor =
            System::Drawing::Color::White;
        this->btnSubmit->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnSubmit->FlatAppearance->MouseOverBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->btnSubmit->ForeColor = System::Drawing::Color::White;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(313, 154);
        this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(233, 59);
        this->btnSubmit->TabIndex = 103;
        this->btnSubmit->Text = L"OK";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(
            this, &SelectReceiverForm::btnSubmit_Click);
        //
        // SelectReceiverForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->ClientSize = System::Drawing::Size(596, 287);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->panel4);
        this->Controls->Add(this->btnClose);
        this->Controls->Add(this->btnSubmit);
        this->Icon = (cli::safe_cast<System::Drawing::Icon ^>(
            resources->GetObject(L"$this.Icon")));
        this->Margin = System::Windows::Forms::Padding(4);
        this->MaximumSize = System::Drawing::Size(614, 334);
        this->MinimumSize = System::Drawing::Size(614, 334);
        this->Name = L"SelectReceiverForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"SelectReceiverForm";
        this->panel4->ResumeLayout(false);
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion

    private:
    List<String ^> ^ accHistory = nullptr;
    public:
    event EventHandler<SelectReceiverEventArgs ^> ^ SelectReceiverSuccess;

    private:
    void loadAccHistory(User ^ user);
    
    System::Void btnSubmit_Click(System::Object ^ sender,
                                 System::EventArgs ^ e);

    System::Void btnClose_Click_1(System::Object ^ sender,
                                  System::EventArgs ^ e);

};
} // namespace BankingAppwinform


