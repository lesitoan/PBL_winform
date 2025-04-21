#include "NotificationForm.h"

namespace BankingAppwinform {

NotificationForm::NotificationForm(void) {
    InitializeComponent();
    loadNotifications();
    GradientColorHelper::ApplyGradient(this->flowLayoutContainer);
}

NotificationForm::~NotificationForm() {
    if (components) {
        delete components;
    }
}

void NotificationForm::loadNotifications() {
    try {
        flowLayoutContainer->Controls->Clear();

        String ^ accNumber = GlobalData::GetCurrentUser()->AccountNumber;
        array<Notifications ^> ^ notifications = NotificationsServices::GetNotificationsByUserAccNumber(accNumber);
        if (notifications == nullptr) {
            return;
        }

        for (int i = notifications->Length - 1; i >=  0; i--) {
            addNotificationPanel(flowLayoutContainer, notifications[i], i);
        }    
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Tải dữ liệu thông báo thất bại, thử lại sau.", L"Error", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void NotificationForm::addNotificationPanel(FlowLayoutPanel ^ flowLayoutPanel,
                          Notifications ^ notification, int index) {
    // Tạo một Panel mới chứa thông báo
    Panel ^ panel = gcnew Panel();
    panel->Size = System::Drawing::Size(flowLayoutPanel->Width - 20,
                                        90); // Tăng chiều cao để vừa 2 dòng
    panel->BorderStyle = BorderStyle::FixedSingle;

    if (notification->Status == 1) {
        panel->BackColor = System::Drawing::Color::White;
    }

    // Tạo nhãn tiêu đề thông báo
    Label ^ titleLabel = gcnew Label();
    titleLabel->Text = L"THÔNG BÁO";
    titleLabel->Font =
        gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
    titleLabel->Location = System::Drawing::Point(5, 5);

    // Tạo nhãn thời gian thông báo
    Label ^ timeLabel = gcnew Label();
    timeLabel->Text = notification->CreatedAt;
    timeLabel->Font =
        gcnew System::Drawing::Font("Arial", 9, FontStyle::Italic);
    timeLabel->Location = System::Drawing::Point(100, 5);

    // Tạo nhãn nội dung thông báo (đảm bảo luôn có 2 dòng)
    Label ^ contentLabel = gcnew Label();
    contentLabel->Text = notification->Content;
    contentLabel->Font =
        gcnew System::Drawing::Font("Arial", 9, FontStyle::Regular);
    contentLabel->Location = System::Drawing::Point(5, 25);
    contentLabel->Size =
        System::Drawing::Size(panel->Width - 10, 40); // Đảm bảo vừa 2 dòng
    contentLabel->AutoSize = false;
    contentLabel->MaximumSize =
        System::Drawing::Size(panel->Width - 10, 40); // Giới hạn chiều cao

    // Tạo Label đánh dấu đã đọc
    String ^ markReadText =
        notification->Status == 1 ? L"Đã đọc" : L"Đánh dấu đã đọc";
    Label ^ markReadLabel = gcnew Label();
    markReadLabel->Text = markReadText;
    markReadLabel->ForeColor = notification->Status == 0
                                   ? System::Drawing::Color::Blue
                                   : System::Drawing::Color::Gray;
    markReadLabel->Cursor = notification->Status == 0 ? Cursors::Hand : Cursors::No;

    markReadLabel->Location =
        System::Drawing::Point(panel->Width - 120, 70);
    markReadLabel->AutoSize = true;

    // Thêm các thành phần vào panel
    panel->Controls->Add(titleLabel);
    panel->Controls->Add(timeLabel);
    panel->Controls->Add(contentLabel);
    panel->Controls->Add(markReadLabel);

    // Gắn thông báo vào Label để xử lý sự kiện click
    markReadLabel->Tag = notification;

    // Thêm panel vào FlowLayoutPanel
    flowLayoutPanel->Controls->Add(panel);
    markReadLabel->Click += gcnew System::EventHandler(this, &NotificationForm::label1_Click);
}

System::Void NotificationForm::label1_Click(System::Object ^ sender, System::EventArgs ^ e) {
    try {
        Label ^ clickedLabel =
            dynamic_cast<Label ^>(sender); // Ép kiểu sender thành Label

        if (clickedLabel != nullptr && clickedLabel->Tag != nullptr) {
            Notifications ^ notification = dynamic_cast<Notifications ^>(
                clickedLabel->Tag); // Lấy lại đối tượng notification

            if (notification == nullptr) {
                return;
            }

            // Đánh dấu đã đọc
            clickedLabel->Text = L"Đã đọc";
            clickedLabel->ForeColor = System::Drawing::Color::Gray;
            clickedLabel->Cursor = Cursors::No;

            // Cập nhật trạng thái đã đọc
            NotificationsServices::UpdateNotificationStatus(notification->NotificationId, 1);

            this->loadNotifications();
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(L"Đánh dấu đã đọc thất bại, thử lại sau.", L"Error", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

}

