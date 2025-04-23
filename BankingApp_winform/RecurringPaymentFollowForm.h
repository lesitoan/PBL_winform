#pragma once
#include "CustomerCodes.h"
#include "GlobalData.h"
#include "HandleFile.h"
#include "RecurringPayments.h"
#include"RecurringPaymentServices.h"
#include "UserServices.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for RecurringPaymentFollowForm
/// </summary>
public
ref class RecurringPaymentFollowForm : public System::Windows::Forms::Form {
  public:
    RecurringPaymentFollowForm(void);

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~RecurringPaymentFollowForm();

  private:
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanelFollow;

  protected:
  private:
  protected:
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
        System::ComponentModel::ComponentResourceManager ^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RecurringPaymentFollowForm::typeid));
        this->flowLayoutPanelFollow = (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->SuspendLayout();
        //
        // flowLayoutPanelFollow
        //
        this->flowLayoutPanelFollow->Dock = System::Windows::Forms::DockStyle::Fill;
        this->flowLayoutPanelFollow->Location = System::Drawing::Point(0, 0);
        this->flowLayoutPanelFollow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->flowLayoutPanelFollow->Name = L"flowLayoutPanelFollow";
        this->flowLayoutPanelFollow->Size = System::Drawing::Size(671, 287);
        this->flowLayoutPanelFollow->TabIndex = 0;
        //
        // RecurringPaymentFollowForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(671, 287);
        this->Controls->Add(this->flowLayoutPanelFollow);
        this->ForeColor = System::Drawing::SystemColors::ControlText;
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
        this->Icon = (cli::safe_cast<System::Drawing::Icon ^>(resources->GetObject(L"$this.Icon")));
        this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
        this->MaximumSize = System::Drawing::Size(689, 334);
        this->MinimumSize = System::Drawing::Size(689, 334);
        this->Name = L"RecurringPaymentFollowForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"Thanh Toán Định Kỳ";
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    /// <summary>
  private:
    Void LoadRecurringPaymentFollow();

    System::Void
        labelFollow_Click(System::Object ^ sender, System::EventArgs ^ e);


};
} // namespace BankingAppwinform
