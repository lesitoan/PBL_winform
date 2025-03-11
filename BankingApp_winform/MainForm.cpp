#include "MainForm.h"
#include "AuthForm.h"

namespace BankingAppwinform {

MainForm::MainForm() {
    InitializeComponent();
    InitLoad();
}
MainForm::~MainForm() {
    if (components) {
        delete components;
    }
}
void MainForm::ChangeButtonColor(Button ^ button) {
    if (selectedButton != nullptr) {
        selectedButton->BackColor = System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
    }
    selectedButton = button;
    selectedButton->BackColor = System::Drawing::Color::Teal;
}

void MainForm::InitLoad() {

    this->labelFullName->Text = GlobalData::GetCurrentUser()->getFullName();
    this->labelBalance->Text = "**********";
    LoadChildForm::LoadForm(this->panelContent, gcnew AccountForm());
    this->headerText->Text = L"DOASHBOARD";

    if (GlobalData::GetCurrentUser()->getRole() == "company") {
        this->btnCode->Visible = true;
    }

}

System::Void MainForm::MainForm_Load(System::Object ^ sender,
                                     System::EventArgs ^ e) {
    
}
System::Void MainForm::btnAccount_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew AccountForm());
    ChangeButtonColor(btnAccount);
    this->headerText->Text = L"TÀI KHOẢN";
}
System::Void MainForm::btnTransfer_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew TransferMoneyForm());
    ChangeButtonColor(btnTransfer);
    this->headerText->Text = L"CHUYỂN KHOẢN";
}
System::Void MainForm::btnWithdraw_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew WithdrawMoneyForm());
    ChangeButtonColor(btnWithdraw);
    this->headerText->Text = L"RÚT TIỀN";
}
System::Void MainForm::btnHistory_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew HistoryForm());
    ChangeButtonColor(btnHistory);
    this->headerText->Text = L"LỊCH SỬ";
}

System::Void MainForm::btnCode_Click(System::Object ^ sender,
                                     System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew CodeForm());
    ChangeButtonColor(btnCode);
    this->headerText->Text = L"QUẢN LÍ CODE";
}


System::Void MainForm::btnLogout_Click(System::Object ^ sender,
                                       System::EventArgs ^ e) {
    System::Windows::Forms::DialogResult result;
    result =
        MessageBox::Show(L"Bạn có chắc chắn muốn đăng xuất?", L"Đăng xuất",
                         MessageBoxButtons::YesNo, MessageBoxIcon::Question);
    if (result == System::Windows::Forms::DialogResult::Yes) {
        GlobalData::SetCurrentUser(nullptr);

        this->Hide();
        AuthForm ^ authForm = gcnew AuthForm();
        authForm->ShowDialog();
        this->Close();

    }
}
System::Void MainForm::timer1_Tick(System::Object ^ sender,
                                   System::EventArgs ^ e) {
    if (isOpenNav) {
        if (panelNav->Width <= 62) {
            timer1->Stop();
            isOpenNav = false;
        } else {
            panelNav->Width -= 20;
        }
    } else {
        if (panelNav->Width >= 200) {
            timer1->Stop();
            isOpenNav = true;
        } else {
            panelNav->Width += 20;
        }
    }
}
System::Void MainForm::btnMenu_Click(System::Object ^ sender,
                                     System::EventArgs ^ e) {
    timer1->Start();
}

System::Void MainForm::resizeEven(System::Object ^ sender,
                                  System::EventArgs ^ e) {
    // 📌 Lấy kích thước hiện tại của panelX (màu trắng)
    int parentWidth = panelx->ClientSize.Width;
    int parentHeight = panelx->ClientSize.Height;

    // 📌 Kích thước tối thiểu của panelContent (màu xanh)
    const int minWidth = 658;
    const int minHeight = 499;
    const float ratio =
        (float)minWidth / minHeight; // Tỷ lệ cố định giữa width & height

    // 📌 Kích thước tối đa của panelContent
    const int maxWidth = (int)(minWidth * 2.5f);   // 987px
    const int maxHeight = (int)(minHeight * 2.5f); // 748px

    // 📌 Tính toán kích thước panelContent nhưng không vượt quá panelX
    int availableWidth = Math::Min(maxWidth, parentWidth - 40);
    int availableHeight = Math::Min(maxHeight, parentHeight - 40);

    int newWidth = availableWidth;
    int newHeight = (int)(newWidth / ratio);

    // Nếu chiều cao vượt quá availableHeight, điều chỉnh lại
    if (newHeight > availableHeight) {
        newHeight = availableHeight;
        newWidth = (int)(newHeight * ratio);
    }

    // 📌 Đảm bảo kích thước không nhỏ hơn minSize
    newWidth = Math::Max(newWidth, minWidth);
    newHeight = Math::Max(newHeight, minHeight);

    // 📌 Đặt lại kích thước panelContent nếu nó chưa đạt maxSize
    if (panelContent->Width != newWidth || panelContent->Height != newHeight) {
        panelContent->Width = newWidth;
        panelContent->Height = newHeight;
    }

    // 📌 Luôn căn giữa panelContent ngay cả khi đã đạt maxSize
    panelContent->Left = (parentWidth - panelContent->Width) / 2;
    panelContent->Top = (parentHeight - panelContent->Height) / 2;
}

System::Void MainForm::btnShowBalance_CheckedChanged(System::Object ^ sender,
                                                     System::EventArgs ^ e) {
    if (btnShowBalance->Checked) {
        this->labelBalance->Text =
            GlobalData::GetCurrentUser()->getBalance() + " VND";
    } else {
        this->labelBalance->Text = "**********";
    }
}
}; // namespace BankingAppwinform
