#pragma once
#include "GlobalData.h"
#include "User.h"
#include "HandleFile.h"
#include"GradientHelper.h"

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
        GradientColorHelper::ApplyGradient(this);
       /* GradientColorHelper::ApplyGradient(this->panel1);
        GradientColorHelper::ApplyRoundedCorners(this->panel1, 20);
        GradientColorHelper::ApplyRoundedCorners(this->btnInsertAvatar, 10);
        GradientColorHelper::ApplyRoundedCorners(this->button1, 10);*/
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
    System::Windows::Forms::Button ^ button1;

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
        this->button1 = (gcnew System::Windows::Forms::Button());
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
        this->panel1->BackColor = System::Drawing::Color::Transparent;
        this->panel1->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->panel1->Controls->Add(this->button1);
        this->panel1->Controls->Add(this->btnInsertAvatar);
        this->panel1->Controls->Add(this->pictureBoxAvatar);
        this->panel1->Location = System::Drawing::Point(53, 40);
        this->panel1->Margin = System::Windows::Forms::Padding(4);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(748, 327);
        this->panel1->TabIndex = 0;
        //
        // button1
        //
        this->button1->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->button1->BackColor = System::Drawing::Color::Green;
        this->button1->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
        this->button1->FlatAppearance->BorderColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->button1->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->button1->FlatAppearance->MouseOverBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->button1->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->button1->ForeColor = System::Drawing::Color::Transparent;
        this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
        this->button1->Location = System::Drawing::Point(252, 229);
        this->button1->Margin = System::Windows::Forms::Padding(4);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(263, 50);
        this->button1->TabIndex = 39;
        this->button1->Text = L"View Image";
        this->button1->UseVisualStyleBackColor = false;
        //
        // btnInsertAvatar
        //
        this->btnInsertAvatar->Anchor =
            static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top |
                 System::Windows::Forms::AnchorStyles::Right));
        this->btnInsertAvatar->BackColor = System::Drawing::Color::Green;
        this->btnInsertAvatar->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->btnInsertAvatar->Cursor = System::Windows::Forms::Cursors::Hand;
        this->btnInsertAvatar->FlatAppearance->BorderColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->btnInsertAvatar->FlatAppearance->MouseDownBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnInsertAvatar->FlatAppearance->MouseOverBackColor =
            System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->btnInsertAvatar->FlatStyle =
            System::Windows::Forms::FlatStyle::Flat;
        this->btnInsertAvatar->Font = (gcnew System::Drawing::Font(
            L"UTM Daxline", 12, System::Drawing::FontStyle::Bold));
        this->btnInsertAvatar->ForeColor = System::Drawing::Color::Transparent;
        this->btnInsertAvatar->ImeMode =
            System::Windows::Forms::ImeMode::NoControl;
        this->btnInsertAvatar->Location = System::Drawing::Point(252, 161);
        this->btnInsertAvatar->Margin = System::Windows::Forms::Padding(4);
        this->btnInsertAvatar->Name = L"btnInsertAvatar";
        this->btnInsertAvatar->Size = System::Drawing::Size(263, 50);
        this->btnInsertAvatar->TabIndex = 38;
        this->btnInsertAvatar->Text = L"Change Avatar";
        this->btnInsertAvatar->UseVisualStyleBackColor = false;
        this->btnInsertAvatar->Click += gcnew System::EventHandler(
            this, &SetAvatarForm::btnInsertAvatar_Click);
        //
        // pictureBoxAvatar
        //
        this->pictureBoxAvatar->BackColor = System::Drawing::Color::Transparent;
        this->pictureBoxAvatar->Image =
            (cli::safe_cast<System::Drawing::Image ^>(
                resources->GetObject(L"pictureBoxAvatar.Image")));
        this->pictureBoxAvatar->Location = System::Drawing::Point(344, 42);
        this->pictureBoxAvatar->Margin = System::Windows::Forms::Padding(4);
        this->pictureBoxAvatar->Name = L"pictureBoxAvatar";
        this->pictureBoxAvatar->Size = System::Drawing::Size(95, 97);
        this->pictureBoxAvatar->SizeMode =
            System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->pictureBoxAvatar->TabIndex = 37;
        this->pictureBoxAvatar->TabStop = false;
        //
        // SetAvatarForm
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::SystemColors::ActiveCaption;
        this->BackgroundImageLayout =
            System::Windows::Forms::ImageLayout::Stretch;
        this->ClientSize = System::Drawing::Size(856, 407);
        this->Controls->Add(this->panel1);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
