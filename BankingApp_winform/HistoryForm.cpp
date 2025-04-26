#include "HistoryForm.h"
#include"GradientHelper.h"

namespace BankingAppwinform {

HistoryForm::HistoryForm(void) { 
    InitializeComponent();
    GradientColorHelper::ApplyGradient(this->label1);
    GradientColorHelper::ApplyGradient(this->label2);
    this->loadTransactionsHistory();
}

HistoryForm::~HistoryForm() {
    if (components) {
        delete components;
    }
}

void HistoryForm::loadTransactionsHistory() {
    try {
        String ^ currUserId = GlobalData::GetCurrentUser()->Id;
        array<TransactionDTO ^> ^ transactions = TransactionServices::FindTransactionByUserId(currUserId);
        if (transactions == nullptr || transactions->Length == 0) {
            return;
        }

        leftContent->Controls->Clear();
        rightContent->Controls->Clear();
        
        for (int i = transactions->Length - 1; i >= 0; i--) {
            // lich su rut tien, gửi nhận tiết kiệm
            if (transactions[i]->FromUser == nullptr || transactions[i]->ToUser == nullptr) {
                AddTransactionPanel(rightContent, transactions[i]);
            } else {
                // lich su chuyen tien
                AddTransactionPanel(leftContent, transactions[i]);
            }
        }
        leftContent->PerformLayout();
        rightContent->PerformLayout();
    } catch (Exception ^ ex) {
        MessageBox::Show(ex->Message, L"Error", MessageBoxButtons::OK,
                         MessageBoxIcon::Information);
    }
}

void HistoryForm::AddTransactionPanel(FlowLayoutPanel ^ flowLayoutPanel,
                                      TransactionDTO ^ data) {
    Panel ^ panel = gcnew Panel();
    panel->BackColor = Color::White;
    panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    panel->Padding = System::Windows::Forms::Padding(10);
    panel->Margin = System::Windows::Forms::Padding(7, 5, 0, 5);
    panel->Width = flowLayoutPanel->ClientSize.Width - 15;

    // Điều chỉnh chiều cao dựa trên số dòng text
    int yOffset = 10;    // Khoảng cách giữa các dòng
    int lineHeight = 20; // Chiều cao trung bình của mỗi dòng

    // Tiêu đề
    Label ^ lblTitle = gcnew Label();
    lblTitle->Text = L"NGÂN HÀNG xin thông báo";
    lblTitle->ForeColor = Color::Black;
    lblTitle->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
    lblTitle->Location = Point(10, yOffset);
    lblTitle->AutoSize = true;
    panel->Controls->Add(lblTitle);
    yOffset += lineHeight;

    // Thời gian GD
    Label ^ lblTime = gcnew Label();
    lblTime->Text = L"Thời gian GD: " + data->ThisTransaction->CreatedAt;
    lblTime->Location = Point(10, yOffset);
    lblTime->AutoSize = true;
    panel->Controls->Add(lblTime);
    yOffset += lineHeight;

    // Tài khoản gửi
    if (data->FromUser) {
        Label ^ lblFromAccount = gcnew Label();
        lblFromAccount->Text = L"Người gửi: " + data->FromUser->FullName;
        lblFromAccount->Font =
            gcnew System::Drawing::Font("Arial", 9, FontStyle::Bold);
        lblFromAccount->Location = Point(10, yOffset);
        lblFromAccount->AutoSize = true;
        panel->Controls->Add(lblFromAccount);
        yOffset += lineHeight;
    }

    // Tài khoản nhận
    if (data->ToUser) {
        Label ^ lblToAccount = gcnew Label();
        lblToAccount->Text = L"Người nhận: " + data->ToUser->FullName;
        lblToAccount->Font =
            gcnew System::Drawing::Font("Arial", 9, FontStyle::Bold);
        lblToAccount->Location = Point(10, yOffset);
        lblToAccount->AutoSize = true;
        panel->Controls->Add(lblToAccount);
        yOffset += lineHeight;
    }

    // Số tiền GD
    Label ^ lblAmount = gcnew Label();
    if (data->FromUser && data->FromUser->Id ==
        GlobalData::GetCurrentUser()->Id){
        lblAmount->Text =
            L"Số tiền: -" + data->ThisTransaction->Amount.ToString() + " VND";
        lblAmount->ForeColor = Color::Red;
    } else {
        lblAmount->Text =
            L"Số tiền: +" + data->ThisTransaction->Amount.ToString() + " VND";
        lblAmount->ForeColor = Color::Green;
    }
    lblAmount->Font = gcnew System::Drawing::Font("Arial", 9, FontStyle::Bold);
    lblAmount->Location = Point(10, yOffset);
    lblAmount->AutoSize = true;
    panel->Controls->Add(lblAmount);
    yOffset += lineHeight;

    // Nội dung giao dịch
    Label ^ lblContent = gcnew Label();
    lblContent->Text = L"Nội dung giao dịch: " + data->ThisTransaction->Message;
    lblContent->ForeColor = Color::Black;
    lblContent->Font = gcnew System::Drawing::Font("Arial", 9);
    lblContent->Location = Point(10, yOffset);
    lblContent->AutoSize = true;
    lblContent->MaximumSize = System::Drawing::Size(panel->Width - 20, 0);
    lblContent->AutoEllipsis = true;
    panel->Controls->Add(lblContent);
    yOffset += lineHeight * 2; // Nội dung có thể dài hơn

    // Cập nhật chiều cao của panel
    panel->Height = yOffset + 10;

    // Thêm vào FlowLayoutPanel
    flowLayoutPanel->Controls->Add(panel);
}

// Cập nhật kích thước Panel khi Form thay đổi kích thước
void HistoryForm::OnResize(FlowLayoutPanel ^ flowLayoutPanel, Object ^ sender,
                           EventArgs ^ e) {
    int containerWidth = flowLayoutPanel->ClientSize.Width;
    for each (Control ^ panel in flowLayoutPanel->Controls) {
        panel->Width = containerWidth - 15;
    }
}

System::Void HistoryForm::fullContent_SizeChanged(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
    int parentWidth = fullContent->ClientSize.Width;

    int panelWidth = parentWidth / 2;

    this->leftContent->Width = panelWidth;
    this->leftContent->Left = 0;
    this->panelHeaderLeft->Width = panelWidth;
    this->panelHeaderLeft->Left = 0;

    this->rightContent->Width = panelWidth;
    this->rightContent->Left = panelWidth;
    this->panelHeaderRight->Width = panelWidth;
    this->panelHeaderRight->Left = panelWidth;
}

System::Void HistoryForm::leftContent_SizeChanged(System::Object ^ sender,
                                                  System::EventArgs ^ e) {
    OnResize(leftContent, sender, e);
}

System::Void HistoryForm::rightContent_SizeChanged(System::Object ^ sender,
                                                   System::EventArgs ^ e) {
    OnResize(rightContent, sender, e);
}

}; // namespace BankingAppwinform
