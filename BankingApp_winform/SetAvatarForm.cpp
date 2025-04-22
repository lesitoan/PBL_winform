#include "SetAvatarForm.h"

namespace BankingAppwinform {
SetAvatarForm::SetAvatarForm(void) {
    InitializeComponent();
    loadAvatar();
    GradientColorHelper::ApplyGradient(this);
    /* GradientColorHelper::ApplyGradient(this->panel1);
     GradientColorHelper::ApplyRoundedCorners(this->panel1, 20);
     GradientColorHelper::ApplyRoundedCorners(this->btnInsertAvatar, 10);
     GradientColorHelper::ApplyRoundedCorners(this->button1, 10);*/
}
SetAvatarForm::~SetAvatarForm() {
    if (components) {
        delete components;
    }
}

void SetAvatarForm::loadAvatar() {
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

System::Void SetAvatarForm::btnInsertAvatar_Click(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
    try {
        String ^ destinationPath = UserService::SetAvatar();
        MessageBox::Show(L"Đã cập nhật ảnh đại diện thành công");
        // Hiển thị ảnh trên pictureBoxAvatar
        pictureBoxAvatar->Image = Image::FromFile(destinationPath);
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->ToString(), L"Lỗi", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
        throw ex;
    }
}
} // namespace BankingAppwinform
