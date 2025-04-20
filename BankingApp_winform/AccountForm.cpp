#include "AccountForm.h"
#include"GradientHelper.h"

namespace BankingAppwinform {
AccountForm::AccountForm(Form ^ parentForm) { 
    InitializeComponent();
    loadAvatar();
    this->parentForm = parentForm;
}

AccountForm::~AccountForm() {
    if (components) {
        delete components;
        axWindowsMediaPlayer2->Ctlcontrols->pause();
    }
}

System::Void AccountForm::AccountForm_Load(System::Object ^ sender,
                                           System::EventArgs ^ e) {
    if (!GlobalData::GetCurrentUser()->getPin()) {
        this->btnSetPin->Text = "Tao PIN";
    }
    this->labelFullName->Text = GlobalData::GetCurrentUser()->getFullName();
    this->labelAccountNumber->Text =
        GlobalData::GetCurrentUser()->getAccountNumber();
    this->labelBalance->Text =
        GlobalData::GetCurrentUser()->getBalance() + " VND";


    //load video
    axWindowsMediaPlayer2->uiMode = "none";
    axWindowsMediaPlayer2->settings->setMode("loop", true);
    String ^ projectPath =
        System::IO::Directory::GetParent(Application::StartupPath)
            ->Parent->FullName;
    String ^ correctPath = System::IO::Path::Combine(
        projectPath, "BankingApp_winform\\images\\TP.mp4");
    if (!System::IO::File::Exists(correctPath)) {
        return;
    }
    axWindowsMediaPlayer2->URL = correctPath;
    axWindowsMediaPlayer2->Ctlcontrols->play();


    GradientColorHelper::ApplyGradient(this->panel1);
    GradientColorHelper::ApplyGradient(this->panel2);
    //
}

System::Void AccountForm::btnChangePw_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew ChangePwForm());
    /*ChangeButtonColor(btnChangePw);*/
    axWindowsMediaPlayer2->Ctlcontrols->pause();
}

System::Void AccountForm::btnSetPin_Click(System::Object ^ sender,
                                          System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew SetPinForm());
    /*ChangeButtonColor(btnSetPin);*/
    axWindowsMediaPlayer2->Ctlcontrols->pause();
}

System::Void AccountForm::buttonSetAvatar_Click(System::Object ^ sender,
                                                System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew SetAvatarForm());
    /*ChangeButtonColor(buttonSetAvatar);*/
    axWindowsMediaPlayer2->Ctlcontrols->pause();
}

System::Void AccountForm::btnLockAccount_Click(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    //ChangeButtonColor(btnLockAccount);
    axWindowsMediaPlayer2->Ctlcontrols->pause();
    System::Windows::Forms::DialogResult result;
    result = MessageBox::Show(L"Bạn có chắc chắn muốn khóa tài khoản, sau khi khóa chỉ có thể đến NH để mở khóa !",
                              L"Lưu thay đổi", MessageBoxButtons::YesNo,
                              MessageBoxIcon::Question);
    if (result == System::Windows::Forms::DialogResult::No) {
        return;
    }

    User ^ userSelected = GlobalData::GetCurrentUser();

    AuthServices::LockAccount(userSelected->getPhoneNumber());

    MessageBox::Show(L"Tài khoản của bạn đã bị khóa !", L"Cảnh báo",
                     MessageBoxButtons::OK, MessageBoxIcon::Warning);
    GlobalData::SetCurrentUser(nullptr);
    parentForm->Hide();
    AuthForm ^ authForm = gcnew AuthForm();
    authForm->ShowDialog();
    parentForm->Close();
}

System::Void AccountForm::panelNav_SizeChanged(System::Object ^ sender,
                                               System::EventArgs ^ e) {
    int parentWidth =
        panelNav->ClientSize.Width;   // Lấy chiều rộng của panel cha
    int panelWidth = parentWidth / 4; // Chia đều thành 3 phần

    // Cập nhật kích thước và vị trí của 3 panel con
    panelBtn1->Width = panelWidth;
    panelBtn2->Width = panelWidth;
    panelBtn3->Width = panelWidth; // Panel cuối cùng nhận phần dư
    panelBtn4->Width = panelWidth; // Panel cuối cùng nhận phần dư

    panelBtn1->Left = 0;
    panelBtn2->Left = panelWidth;
    panelBtn3->Left = panelWidth * 2;
    panelBtn4->Left = panelWidth * 3;
}

void AccountForm::loadAvatar() {
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


}; // namespace BankingAppwinform