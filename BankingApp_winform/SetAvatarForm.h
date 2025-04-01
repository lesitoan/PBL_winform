#pragma once
#include "GlobalData.h"
#include "User.h"
#include "HandleFile.h"

namespace BankingAppwinform {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

/// <summary>
/// Summary for SetAvatarForm
/// </summary>
public
ref class SetAvatarForm : public System::Windows::Forms::Form {
  public:
    SetAvatarForm(void) {
        InitializeComponent();
        loadAvatar();
    }

  protected:
    ~SetAvatarForm() {
        if (components) {
            delete components;
        }
    }

  private:
    System::Windows::Forms::OpenFileDialog ^ openFileDialog;

  protected:
  private:
    System::Windows::Forms::Panel ^ panel1;

  private:
    System::Windows::Forms::Button ^ btnInsertAvatar;

  private:
    System::Windows::Forms::PictureBox ^ pictureBoxAvatar;

  private:
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager ^ resources =
            (gcnew System::ComponentModel::ComponentResourceManager(
                SetAvatarForm::typeid));
        this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->btnInsertAvatar = (gcnew System::Windows::Forms::Button());
        this->pictureBoxAvatar = (gcnew System::Windows::Forms::PictureBox());
        this->panel1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBoxAvatar))
            ->BeginInit();
        this->SuspendLayout();
        //
        // openFileDialog
        //
        this->openFileDialog->FileName = L"openFileDialog1";
        //
        // panel1
        //
        this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
        this->panel1->Controls->Add(this->btnInsertAvatar);
        this->panel1->Controls->Add(this->pictureBoxAvatar);
        this->panel1->Location = System::Drawing::Point(157, 83);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(344, 131);
        this->panel1->TabIndex = 0;
        //
        // btnInsertAvatar
        //
        this->btnInsertAvatar->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnInsertAvatar->BackColor = System::Drawing::Color::Green;
        this->btnInsertAvatar->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnInsertAvatar->FlatAppearance->BorderSize = 0;
        this->btnInsertAvatar->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnInsertAvatar->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnInsertAvatar->ForeColor = System::Drawing::Color::Transparent;
        this->btnInsertAvatar->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"btnInsertAvatar.Image")));
        this->btnInsertAvatar->ImageAlign =
            System::Drawing::ContentAlignment::MiddleLeft;
        this->btnInsertAvatar->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->btnInsertAvatar->Location = System::Drawing::Point(138, 53);
        this->btnInsertAvatar->Name = L"btnInsertAvatar";
        this->btnInsertAvatar->Size = System::Drawing::Size(197, 37);
        this->btnInsertAvatar->TabIndex = 38;
        this->btnInsertAvatar->Text = L"        Chọn ảnh đại diện";
        this->btnInsertAvatar->UseVisualStyleBackColor = false;
        this->btnInsertAvatar->Click += gcnew System::EventHandler(
            this, &SetAvatarForm::btnInsertAvatar_Click);
        //
        // pictureBoxAvatar
        //
        this->pictureBoxAvatar->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"pictureBoxAvatar.Image")));
        this->pictureBoxAvatar->Location = System::Drawing::Point(13, 22);
        this->pictureBoxAvatar->Name = L"pictureBoxAvatar";
        this->pictureBoxAvatar->Size = System::Drawing::Size(96, 87);
        this->pictureBoxAvatar->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->pictureBoxAvatar->TabIndex = 37;
        this->pictureBoxAvatar->TabStop = false;
        //
        // SetAvatarForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Teal;
        this->ClientSize = System::Drawing::Size(642, 331);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(2);
        this->Name = L"SetAvatarForm";
        this->Text = L"SetAvatarForm";
        this->panel1->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(
             this->pictureBoxAvatar))
            ->EndInit();
        this->ResumeLayout(false);
    }
#pragma endregion
  private:
    System::Void btnInsertAvatar_Click(System::Object ^ sender,
                                       System::EventArgs ^ e){
        openFileDialog->Filter =
            "Hình ảnh (*.jpg;*.jpeg;*.png)|*.jpg;*.jpeg;*.png";

        if (openFileDialog->ShowDialog() ==
            System::Windows::Forms::DialogResult::OK) {

            String ^ projectPath =
                System::IO::Directory::GetParent(Application::StartupPath)->Parent->FullName;
            String ^ avatarFolder = System::IO::Path::Combine(
                projectPath, "BankingApp_winform\\images\\avatars\\");
            // Lấy đường dẫn ảnh gốc
            String ^ originalPath = openFileDialog->FileName;

            String ^ extension = Path::GetExtension(originalPath);
            String ^ newFileName =
                "avatar_" + GlobalData::GetCurrentUser()->AccountNumber + extension;

            String ^ destinationPath = Path::Combine(avatarFolder, newFileName);

             //Tạo thư mục Images nếu chưa có
            if (!Directory::Exists(avatarFolder)) {
                Directory::CreateDirectory(avatarFolder);
            }
            
            // Xóa ảnh cũ nếu có
            /*if (GlobalData::GetCurrentUser()->UrlAvatar !=
                "BankingApp_winform\\images\\avatars\\default_avatar.png") {
                String ^ oldFilePath = System::IO::Path::Combine(
                    projectPath, GlobalData::GetCurrentUser()->UrlAvatar);
                if (File::Exists(oldFilePath)) {
                    File::Delete(oldFilePath);
                }
            }*/

            File::Copy(originalPath, destinationPath);


            // Lưu đường dẫn ảnh vào file users.dat
            GlobalData::GetCurrentUser()->UrlAvatar =
                "BankingApp_winform\\images\\avatars\\" + newFileName;
            array<User ^> ^ users = HandleFile::ReadUserArray("users.dat");
            for (int i = 0; i < users->Length; i++) {
                if (users[i]->getAccountNumber() ==
                    GlobalData::GetCurrentUser()->getAccountNumber()) {
                    users[i]->UrlAvatar =
                        GlobalData::GetCurrentUser()->UrlAvatar;
                    break;
                }
            }
            HandleFile::WriteUserArray(users, "users.dat");

            MessageBox::Show(L"Đã cập nhật ảnh đại diện thành công");
            

            // Hiển thị ảnh trên pictureBoxAvatar
            pictureBoxAvatar->Image = Image::FromFile(destinationPath);
        }
    
    }

    void loadAvatar() {
        String ^ filePath = GlobalData::GetCurrentUser()->UrlAvatar;

        String ^ projectPath =
            System::IO::Directory::GetParent(Application::StartupPath)
                ->Parent->FullName;
        String ^ correctPath = System::IO::Path::Combine(projectPath, filePath);

        if (!System::IO::File::Exists(correctPath)) {
            return;
        }

        this->pictureBoxAvatar->Image = Image::FromFile(correctPath);
    }


};
} // namespace BankingAppwinform
