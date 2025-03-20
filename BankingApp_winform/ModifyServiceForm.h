#pragma once
#include "HandleFile.h"
#include "Services.h"
#include "User.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


public
ref class ModifyServiceForm : public System::Windows::Forms::Form {
  public:
    ModifyServiceForm(String^ type) {
        InitializeComponent();
        this->type = type;
        if (type == "") {
            this->Close();
        }else if (type == "insert") {
            this->panelAdd->Visible = true;
            header->Text = L"THÊM DỊCH VỤ";
            btnSubmit->Text = "THÊM";
        } else if (type == "delete") {
            this->panelDelete->Visible = true;
            loadServiceBox();
            header->Text = L"XÓA DỊCH VỤ";
            btnSubmit->Text = "XÓA";
        }
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~ModifyServiceForm() {
        if (components) {
            delete components;
        }
    }

  private:
    String ^ type;


  private:


  protected:
  private:
  private:


  private:
    System::Windows::Forms::Label ^ header;

  private:


  private:
    System::Windows::Forms::Button ^ btnSubmit;

  private:
    System::Windows::Forms::Button ^ btnClose;

  private:
    System::Windows::Forms::Panel ^ panelAdd;

  private:
    System::Windows::Forms::Panel ^ panel2;

  private:
    System::Windows::Forms::TextBox ^ serviceName;

  private:
    System::Windows::Forms::Label ^ labelAuth;

  private:
    System::Windows::Forms::Panel ^ panelDelete;

  private:
    System::Windows::Forms::Label ^ label5;

  private:
    System::Windows::Forms::Panel ^ panel4;

  private:
    System::Windows::Forms::ComboBox ^ selectServiceBox;

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
        this->header = (gcnew System::Windows::Forms::Label());
        this->btnSubmit = (gcnew System::Windows::Forms::Button());
        this->btnClose = (gcnew System::Windows::Forms::Button());
        this->panelAdd = (gcnew System::Windows::Forms::Panel());
        this->panel2 = (gcnew System::Windows::Forms::Panel());
        this->serviceName = (gcnew System::Windows::Forms::TextBox());
        this->labelAuth = (gcnew System::Windows::Forms::Label());
        this->panelDelete = (gcnew System::Windows::Forms::Panel());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->panel4 = (gcnew System::Windows::Forms::Panel());
        this->selectServiceBox = (gcnew System::Windows::Forms::ComboBox());
        this->panelAdd->SuspendLayout();
        this->panel2->SuspendLayout();
        this->panelDelete->SuspendLayout();
        this->panel4->SuspendLayout();
        this->SuspendLayout();
        //
        // header
        //
        this->header->AutoSize = true;
        this->header->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 22, System::Drawing::FontStyle::Bold));
        this->header->ForeColor = System::Drawing::Color::White;
        this->header->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->header->Location = System::Drawing::Point(231, 39);
        this->header->Name = L"header";
        this->header->Size = System::Drawing::Size(196, 40);
        this->header->TabIndex = 32;
        this->header->Text = L"THÊM DỊCH VỤ";
        this->header->TextAlign =
            System::Drawing::ContentAlignment::MiddleCenter;
        //
        // btnSubmit
        //
        this->btnSubmit->BackColor = System::Drawing::SystemColors::Info;
        this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnSubmit->FlatAppearance->BorderSize = 0;
        this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnSubmit->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnSubmit->ForeColor = System::Drawing::Color::Teal;
        this->btnSubmit->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnSubmit->Location = System::Drawing::Point(343, 201);
        this->btnSubmit->Name = L"btnSubmit";
        this->btnSubmit->Size = System::Drawing::Size(214, 42);
        this->btnSubmit->TabIndex = 31;
        this->btnSubmit->Text = L"THÊM";
        this->btnSubmit->UseVisualStyleBackColor = false;
        this->btnSubmit->Click += gcnew System::EventHandler(
            this, &ModifyServiceForm::btnSubmit_Click);
        //
        // btnClose
        //
        this->btnClose->BackColor = System::Drawing::SystemColors::HotTrack;
        this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnClose->FlatAppearance->BorderSize = 0;
        this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->btnClose->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnClose->ForeColor = System::Drawing::Color::White;
        this->btnClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->btnClose->Location = System::Drawing::Point(112, 201);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(206, 42);
        this->btnClose->TabIndex = 35;
        this->btnClose->Text = L"THOÁT";
        this->btnClose->UseVisualStyleBackColor = false;
        this->btnClose->Click += gcnew System::EventHandler(
            this, &ModifyServiceForm::btnClose_Click);
        //
        // panelAdd
        //
        this->panelAdd->Controls->Add(this->panel2);
        this->panelAdd->Controls->Add(this->labelAuth);
        this->panelAdd->Location = System::Drawing::Point(112, 96);
        this->panelAdd->Name = L"panelAdd";
        this->panelAdd->Size = System::Drawing::Size(445, 83);
        this->panelAdd->TabIndex = 36;
        this->panelAdd->Visible = false;
        //
        // panel2
        //
        this->panel2->BackColor = System::Drawing::Color::White;
        this->panel2->Controls->Add(this->serviceName);
        this->panel2->Location = System::Drawing::Point(3, 35);
        this->panel2->Name = L"panel2";
        this->panel2->Size = System::Drawing::Size(442, 37);
        this->panel2->TabIndex = 36;
        //
        // serviceName
        //
        this->serviceName->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top |
                   System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
        this->serviceName->BorderStyle =
            System::Windows::Forms::BorderStyle::None;
        this->serviceName->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 14));
        this->serviceName->Location = System::Drawing::Point(18, 6);
        this->serviceName->MaxLength = 30;
        this->serviceName->Multiline = true;
        this->serviceName->Name = L"serviceName";
        this->serviceName->Size = System::Drawing::Size(424, 28);
        this->serviceName->TabIndex = 29;
        //
        // labelAuth
        //
        this->labelAuth->AutoSize = true;
        this->labelAuth->Cursor = System::Windows::Forms::Cursors::Hand;
        this->labelAuth->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->labelAuth->ForeColor = System::Drawing::Color::Transparent;
        this->labelAuth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->labelAuth->Location = System::Drawing::Point(-1, 10);
        this->labelAuth->Name = L"labelAuth";
        this->labelAuth->Size = System::Drawing::Size(93, 22);
        this->labelAuth->TabIndex = 35;
        this->labelAuth->Text = L"Tên dịch vụ:";
        //
        // panelDelete
        //
        this->panelDelete->Controls->Add(this->label5);
        this->panelDelete->Controls->Add(this->panel4);
        this->panelDelete->Location = System::Drawing::Point(103, 82);
        this->panelDelete->Name = L"panelDelete";
        this->panelDelete->Size = System::Drawing::Size(511, 98);
        this->panelDelete->TabIndex = 37;
        this->panelDelete->Visible = false;
        //
        // label5
        //
        this->label5->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Left |
                 System::Windows::Forms::AnchorStyles::Right));
        this->label5->AutoSize = true;
        this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
        this->label5->Font =
            (gcnew System::Drawing::Font(L"UTM Daxline Medium", 12));
        this->label5->ForeColor = System::Drawing::Color::Transparent;
        this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->label5->Location = System::Drawing::Point(8, 14);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(157, 22);
        this->label5->TabIndex = 60;
        this->label5->Text = L"Chọn dịch vụ cần xóa:";
        //
        // panel4
        //
        this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Left;
        this->panel4->BackColor = System::Drawing::Color::White;
        this->panel4->Controls->Add(this->selectServiceBox);
        this->panel4->Location = System::Drawing::Point(12, 43);
        this->panel4->Name = L"panel4";
        this->panel4->Size = System::Drawing::Size(442, 37);
        this->panel4->TabIndex = 61;
        //
        // selectServiceBox
        //
        this->selectServiceBox->Anchor =
            System::Windows::Forms::AnchorStyles::Left;
        this->selectServiceBox->DropDownStyle =
            System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->selectServiceBox->FlatStyle =
            System::Windows::Forms::FlatStyle::Popup;
        this->selectServiceBox->Font =
            (gcnew System::Drawing::Font(L"UTM Facebook K&T", 12));
        this->selectServiceBox->ForeColor = System::Drawing::Color::Black;
        this->selectServiceBox->FormattingEnabled = true;
        this->selectServiceBox->Location = System::Drawing::Point(3, 6);
        this->selectServiceBox->Name = L"selectServiceBox";
        this->selectServiceBox->Size = System::Drawing::Size(439, 27);
        this->selectServiceBox->TabIndex = 3;
        //
        // ModifyServiceForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(659, 331);
        this->Controls->Add(this->panelDelete);
        this->Controls->Add(this->panelAdd);
        this->Controls->Add(this->btnClose);
        this->Controls->Add(this->header);
        this->Controls->Add(this->btnSubmit);
        this->MaximumSize = System::Drawing::Size(675, 370);
        this->MinimumSize = System::Drawing::Size(675, 370);
        this->Name = L"ModifyServiceForm";
        this->StartPosition =
            System::Windows::Forms::FormStartPosition::CenterParent;
        this->Text = L"ModifyServiceForm";
        this->panelAdd->ResumeLayout(false);
        this->panelAdd->PerformLayout();
        this->panel2->ResumeLayout(false);
        this->panel2->PerformLayout();
        this->panelDelete->ResumeLayout(false);
        this->panelDelete->PerformLayout();
        this->panel4->ResumeLayout(false);
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion
  private:

  private:
    System::Void btnClose_Click(System::Object ^ sender,
                                System::EventArgs ^ e) {
        this->Close();
    }

    void loadServiceBox() {
        array<Services ^> ^ services =
            HandleFile::ReadServicesArray("services.dat");
        if (services == nullptr) {
            return;
        }
        for (int i = 0; i < services->Length; i++) {
            selectServiceBox->Items->Add(services[i]->Name);
        }
    }


    public:
        event EventHandler ^ ModifyServiceSuccess;

  private:
        System::Void btnSubmit_Click(System::Object ^ sender,
                                     System::EventArgs ^ e) {

            array<Services ^> ^ services =
                HandleFile::ReadServicesArray("services.dat");

            // handle insert
            if (this->type == "insert") {
                String ^ name = serviceName->Text;
                if (name->Length == 0) {
                    MessageBox::Show(L"Tên dịch vụ không được để trống");
                    return;
                }

                // tạo id (fix lại sau)
                Random ^ rand = gcnew Random();
                int id = rand->Next(1, 701);
                //

                if (services == nullptr) {
                    services = gcnew array<Services ^>(1);
                    services[0] = gcnew Services(id, name);
                } else {
                    // check dịch vụ đã tồn tại chưa
                    for (int i = 0; i < services->Length; i++) {
                        if (services[i]->Name == name) {
                            MessageBox::Show(L"Dịch vụ đã tồn tại");
                            return;
                        }
                    }
                    array<Services ^> ^ newServices =
                        gcnew array<Services ^>(services->Length + 1);
                    for (int i = 0; i < services->Length; i++) {
                        newServices[i] = services[i];
                    }
                    newServices[services->Length] = gcnew Services(id, name);
                    services = newServices;
                }
                HandleFile::WriteServicesArray(services, "services.dat");
                MessageBox::Show(L"Thêm dịch vụ thành công");
            }

            // handle delete
            if (type == "delete") {
                System::Windows::Forms::DialogResult result;
                result = MessageBox::Show(
                    L"Bạn có chắc chắn muốn xóa dịch vụ này?", L"Xóa",
                    MessageBoxButtons::YesNo, MessageBoxIcon::Question);
                if (result == System::Windows::Forms::DialogResult::Yes) {
                    for (int i = 0; i < services->Length; i++) {
                        if (services[i]->Name == selectServiceBox->Text) {
                            // check dịch vụ có tồn tại công ty không, nếu có thì không được xóa
                            array<User ^> ^ users =
                                HandleFile::ReadUserArray("users.dat");
                            for (int j = 0; j < users->Length; j++) {
                                if (users[j]->getServiceId() ==
                                    services[i]->Id) {
                                    MessageBox::Show(L"Dịch vụ này đang được "
                                                     L"sử dụng, không thể xóa");
                                    return;
                                }
                            }

                            services[i] = services[services->Length - 1];
                            Array::Resize(services, services->Length - 1);
                            HandleFile::WriteServicesArray(services,
                                                           "services.dat");
                            MessageBox::Show(L"Xóa dịch vụ thành công");
                            break;
                        }
                    }
                } else {
                    return;
                }
            }
        
        ModifyServiceSuccess(this, EventArgs::Empty);
        this->Close();
    }
};
} // namespace BankingAppwinform
