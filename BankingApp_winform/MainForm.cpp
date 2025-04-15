#include "MainForm.h"
#include "AuthForm.h"
#include "AccountForm.h"

namespace BankingAppwinform {

MainForm::MainForm() {
    InitializeComponent();
    InitLoad();
    loadAvatar();
}
MainForm::~MainForm() {
    if (components) {
        delete components;
    }
}
void MainForm::ChangeButtonColor(Button ^ button) {

    for each (Control ^ ctrl in this->panelNav->Controls) {
        Button ^ btn = dynamic_cast<Button ^>(ctrl);
        if (btn != nullptr && btn != btnLogout) {
            btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btn->BackColor = System::Drawing::Color::Transparent;
            btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(255, 100, 100);
            btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(255, 100, 100);
        }
    }

    selectedButton = button;
    if (selectedButton != nullptr) {
        selectedButton->BackColor = System::Drawing::Color::FromArgb(255, 100, 100);
    }
    AccountForm::axWindowsMediaPlayer2->Ctlcontrols->pause();
}

void MainForm::InitLoad() {

    this->labelFullName->Text = GlobalData::GetCurrentUser()->getFullName();
    this->labelBalance->Text = "**********";
    LoadChildForm::LoadForm(this->panelContent, gcnew AccountForm(this));
    this->headerText->Text = L"DOASHBOARD";

    if (GlobalData::GetCurrentUser()->getRole() == "company") {
        this->btnCode->Visible = true;
        this->btnServicePayment->Visible = false;
        this->btnRecurringPayment->Visible = true;
    } else if (GlobalData::GetCurrentUser()->getRole() == "user") {
        this->btnCode->Visible = false;
        this->btnServicePayment->Visible = true;
        this->btnRecurringPayment->Visible = false;
        this->btnSaveMoney->Visible = true;
    }
}

System::Void MainForm::MainForm_Load(System::Object ^ sender,
                                     System::EventArgs ^ e) {}
System::Void MainForm::btnAccount_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    ChangeButtonColor(btnAccount);
    LoadChildForm::LoadForm(this->panelContent, gcnew AccountForm(this));
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
    this->headerText->Text = L"QUẢN LÍ MÃ KHÁCH HÀNG";
}

System::Void MainForm::btnServicePayment_Click(System::Object ^ sender,
                                               System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent, gcnew ServicePaymentForm());
    ChangeButtonColor(btnServicePayment);
    this->headerText->Text = L"THANH TOÁN DỊCH VỤ";
}

System::Void MainForm::btnRecurringPayment_Click(System::Object ^ sender,
                                                 System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent,
                            gcnew ClientRecurringPaymentForm());
    ChangeButtonColor(btnServicePayment);
    this->headerText->Text = L"DANH SÁCH ĐANG ĐĂNG KÍ TTĐK";
}

System::Void MainForm::btnSaveMoney_Click(System::Object ^ sender,
                                System::EventArgs ^ e) {
    LoadChildForm::LoadForm(this->panelContent,
                            gcnew ClientSavingMoneyForm());
    ChangeButtonColor(btnSaveMoney);
    this->headerText->Text = L"GỬI TIẾT KIỆM";
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

System::Void MainForm::btnNotification_Click(System::Object^ sender,
    System::EventArgs^ e) {

    Form^ notificationForm = gcnew NotificationForm();

    int mainFormX = this->Location.X;
    int mainFormY = this->Location.Y;
    int mainFormWidth = this->Width;
    int headerHeight = panelHeader->Height; // Chiều cao của header

    // Đặt vị trí của NotificationForm
    int notificationX =
        mainFormX + mainFormWidth - notificationForm->Width; // Căn sát lề phải
    int notificationY = mainFormY + headerHeight + 30; // Canh ngay dưới thanh header

    notificationForm->StartPosition = FormStartPosition::Manual;
    notificationForm->Location =
        System::Drawing::Point(notificationX, notificationY);


    notificationForm->ShowDialog();
}

void MainForm::loadAvatar() {
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

    System::Void MainForm::labelBalance_Click(System::Object ^ sender,
        System::EventArgs ^ e) {
        if (this->labelBalance->Text != "**********") {
            this->labelBalance->Text = "**********";
        } else {
            this->labelBalance->Text =
                GlobalData::GetCurrentUser()->getBalance() + " VND";
        }
    }

}; // namespace BankingAppwinform
