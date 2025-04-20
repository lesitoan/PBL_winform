#include "ClientSavingMoneyForm.h"

namespace BankingAppwinform {
ClientSavingMoneyForm::ClientSavingMoneyForm(void) {
    InitializeComponent();
    loadSavingCustomers();

    GradientColorHelper::ApplyGradient(this);
    GradientColorHelper::ApplyGradient(this->flowLayoutSavingMoney);
    GradientColorHelper::ApplyRoundedCorners(this->btnTermDeposit, 8);
    GradientColorHelper::ApplyRoundedCorners(this->btnNonTermDeposit, 8);   
    GradientColorHelper::AttachHoverEffect(this->btnTermDeposit,
                                           Color::FromArgb(255,128,128));
    GradientColorHelper::AttachHoverEffect(this->btnNonTermDeposit,
                                           Color::FromArgb(255,128,128));
}

ClientSavingMoneyForm::~ClientSavingMoneyForm() {
    if (components) {
        delete components;
    }
}

System::Void
ClientSavingMoneyForm::btnTermDeposit_Click(System::Object ^ sender,
                                            System::EventArgs ^ e) {
    RegisterSavingForm ^ registerSavingForm =
        gcnew RegisterSavingForm("termDeposit");
    registerSavingForm->ShowDialog();
}

System::Void
ClientSavingMoneyForm::btnNonTermDeposit_Click(System::Object ^ sender,
                                               System::EventArgs ^ e) {
    RegisterSavingForm ^ registerSavingForm =
        gcnew RegisterSavingForm("nonTermDeposit");
    registerSavingForm->ShowDialog();
}

void ClientSavingMoneyForm::loadSavingCustomers() {

    try {
        flowLayoutSavingMoney->Controls->Clear();

        array<SavingCustomers ^> ^ savingItems = SavingCustomersRepository::GetAll();

        if (savingItems == nullptr || savingItems->Length == 0) {
            Label ^ noSavingLabel = gcnew Label();
            noSavingLabel->Text = L"Chưa có tiết kiệm nào";
            noSavingLabel->ForeColor = Color::White;
            noSavingLabel->Font = gcnew System::Drawing::Font(
                "Times New Roman", 12, FontStyle::Regular);
            noSavingLabel->AutoSize = true;
            flowLayoutSavingMoney->Controls->Add(noSavingLabel);
            return;
        }

        for each (SavingCustomers ^ saving in savingItems) {
            if (saving->UserAccountNumber == GlobalData::GetCurrentUser()->AccountNumber) {
                AddSavingItemToFlow(saving);
            }
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

void ClientSavingMoneyForm::AddSavingItemToFlow(SavingCustomers ^ saving) {
    // Panel đại diện cho 1 saving item
    Panel ^ itemPanel = gcnew Panel();
    itemPanel->BorderStyle = BorderStyle::FixedSingle;
    itemPanel->BackColor = Color::White;
    itemPanel->Width = flowLayoutSavingMoney->ClientSize.Width - 25;

    itemPanel->Height = 170; // đặt chiều cao cố định vừa đủ, có thể chỉnh
    itemPanel->Margin =
        System::Windows::Forms::Padding(0, 0, 0, 10); // cách giữa các item
    itemPanel->Dock =
        DockStyle::Top; // giúp fill ngang nếu flowLayoutPanel cho phép
    itemPanel->Anchor = AnchorStyles::Left | AnchorStyles::Right;

    // Label nội dung
    Label ^ label = gcnew Label();
    label->AutoSize = false;
    label->ForeColor = Color::Black;
    label->Font = gcnew System::Drawing::Font("Times New Roman", 12,
                                              FontStyle::Regular);
    label->TextAlign = ContentAlignment::TopLeft;
    label->Padding = System::Windows::Forms::Padding(5); // padding bên trong
    label->Dock = DockStyle::Top;
    label->Height = 140; // cố định chiều cao

    // Tính số tiền thực nhận

    String ^ endPriceMesage = "";
    if (saving->Status == 1) { // đã thanh toán
        endPriceMesage = L"Số tiền đã nhận: " + saving->InterestAmount;
    } else {
        TimeSpan duration = DateTime::Now - saving->DepositDate;
        double receivedAmount =
            saving->Amount +
            (saving->Amount * saving->InterestRate * duration.Days / 365.0);

        endPriceMesage = L"Số tiền thực nhận đến hiện tại: " + receivedAmount;
    }

    // Chuẩn bị nội dung
    String ^ statusMessage = "";
    if (saving->Status == 0) {
        statusMessage = L"Chưa thanh toán";
    } else if (saving->Status == 1) {
        statusMessage = L"Đã thanh toán";
    } else if (saving->Status == 2) {
        statusMessage = L"Đang yêu cầu";
    }

    String ^ content = String::Format(
        L"Loại tiết kiệm: {0}, {1}\n"
        L"Số tiền gửi: {2:N0}VNĐ\n"
        L"Ngày gửi: {3:dd/MM/yyyy}\n"
        L"Lãi suất hàng năm: {4}\n"
        L"{5:N0}VNĐ\n"
        L"Trạng thái: {6}",
        saving->Type == "nonTermDeposit" ? L"Không kì hạn" : L"Có kì hạn",
        saving->Term == 0 ? L"" : saving->Term + L" tháng", saving->Amount,
        saving->DepositDate, saving->InterestRate, endPriceMesage,
        statusMessage);

    label->Text = content;

    // Label kết thúc tiết kiệm
    Label ^ endLabel = gcnew Label();
    endLabel->Text =
        saving->Status == 0 ? L"Ấn vào đây để kết thúc tiết kiệm" : L"";
    endLabel->ForeColor = Color::LightYellow;
    endLabel->Font = gcnew System::Drawing::Font("Times New Roman", 12,
                                                 FontStyle::Regular);
    endLabel->AutoSize = false;
    endLabel->Dock = DockStyle::Bottom;
    endLabel->TextAlign = ContentAlignment::MiddleRight;
    endLabel->Padding = System::Windows::Forms::Padding(0, 0, 10, 5);
    endLabel->Height = 25;
    endLabel->Cursor = Cursors::Hand; // cho biết label có thể bấm
    endLabel->Click +=
        gcnew EventHandler(this, &ClientSavingMoneyForm::EndSaving_Click);
    itemPanel->Tag = saving; // Gán saving vào tag của panel để truy cập sau này

    // Add vào panel
    itemPanel->Controls->Add(endLabel);
    itemPanel->Controls->Add(label);

    // Thêm vào flowPanel
    flowLayoutSavingMoney->Controls->Add(itemPanel);
}

System::Void ClientSavingMoneyForm::EndSaving_Click(System::Object ^ sender,
                                                    System::EventArgs ^ e) {
    try {
        Label ^ clickedLabel = dynamic_cast<Label ^>(sender);
        if (clickedLabel != nullptr) {
            Panel ^ parentPanel = dynamic_cast<Panel ^>(clickedLabel->Parent);
            if (parentPanel == nullptr) return;
            SavingCustomers ^ saving = dynamic_cast<SavingCustomers ^>(parentPanel->Tag);
            if (saving == nullptr || saving->Status != 0)
                return;

            // Xử lý kết thúc tiết kiệm -> sửa status từ 0 thành 2;
            // 0: chưa thanh toán, 1: đã thanh toán, 2: đang yêu cầu
            saving->Status = 2;
            
            SavingService::UpdateStatusSaving(saving->Id, saving);

            MessageBox::Show(L"Đã gửi yêu cầu kết thúc tiết kiệm thành công, vui "
                             L"lòng chờ hoàn tất",
                             L"Thông báo", MessageBoxButtons::OK,
                             MessageBoxIcon::Information);
            loadSavingCustomers();
        }
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Thông báo", MessageBoxButtons::OK,
                         MessageBoxIcon::Error);
    }
}

} // namespace BankingAppwinform
