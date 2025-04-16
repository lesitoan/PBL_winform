#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
#using < System.Core.dll>


public
ref struct HoverInfo {
    Color OriginalColor;
    Color HoverColor;
};
ref class GradientColorHelper {
  public:
    // Hàm áp dụng gradient background
    static void ApplyGradient(Control ^ ctrl) {
        ctrl->Paint -= gcnew PaintEventHandler(OnPaintGradient);
        ctrl->Paint += gcnew PaintEventHandler(OnPaintGradient);
        ctrl->Invalidate();
    }

    // Hàm bo góc
    static void ApplyRoundedCorners(Control ^ ctrl, int radius) {
        GraphicsPath ^ path = gcnew GraphicsPath();
        Rectangle bounds = ctrl->ClientRectangle;
        int arcSize = radius * 2;

        path->AddArc(bounds.X, bounds.Y, arcSize, arcSize, 180, 90);
        path->AddArc(bounds.Right - arcSize, bounds.Y, arcSize, arcSize, 270,
                     90);
        path->AddArc(bounds.Right - arcSize, bounds.Bottom - arcSize, arcSize,
                     arcSize, 0, 90);
        path->AddArc(bounds.X, bounds.Bottom - arcSize, arcSize, arcSize, 90,
                     90);
        path->CloseFigure();

        ctrl->Region = gcnew Region(path);
    }

  private:
    static void OnPaintGradient(Object ^ sender, PaintEventArgs ^ e) {
        Control ^ ctrl = dynamic_cast<Control ^>(sender);
        if (ctrl == nullptr || ctrl->ClientRectangle.Width == 0 ||
            ctrl->ClientRectangle.Height == 0)
            return;

        Rectangle rect = ctrl->ClientRectangle;

        ColorBlend ^ blend = gcnew ColorBlend();
        blend->Colors = gcnew array<Color>{
            Color::FromArgb(46, 47, 145),   // Tím đậm
            Color::FromArgb(213, 138, 182), // Hồng pastel
            Color::FromArgb(243, 234, 241)  // Trắng hồng nhạt
        };
        blend->Positions = gcnew array<float>{0.0f, 0.5f, 1.0f};

        LinearGradientBrush ^ brush =
            gcnew LinearGradientBrush(rect, Color::Black, Color::White,
                                      LinearGradientMode::ForwardDiagonal);
        brush->InterpolationColors = blend;

        e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;
        e->Graphics->FillRectangle(brush, rect);

        // Vẽ lại text cho Button hoặc Label
        Button ^ btn = dynamic_cast<Button ^>(ctrl);
        if (btn != nullptr) {
            TextRenderer::DrawText(e->Graphics, btn->Text, btn->Font, rect,
                                   btn->ForeColor,
                                   TextFormatFlags::HorizontalCenter |
                                       TextFormatFlags::VerticalCenter);
        }

        Label ^ lbl = dynamic_cast<Label ^>(ctrl);
        if (lbl != nullptr) {
            TextRenderer::DrawText(e->Graphics, lbl->Text, lbl->Font, rect,
                                   lbl->ForeColor,
                                   TextFormatFlags::HorizontalCenter |
                                       TextFormatFlags::VerticalCenter);
        }
    }

  private:
    static System::Collections::Generic::Dictionary<Control ^, HoverInfo ^> ^
        hoverMap = gcnew System::Collections::Generic::Dictionary < Control ^
        , HoverInfo ^ > ();

  public:
    static void AttachHoverEffect(Control ^ control, Color hoverColor) {
        if (!hoverMap->ContainsKey(control)) {
            HoverInfo ^ info = gcnew HoverInfo();
            info->OriginalColor = control->BackColor;
            info->HoverColor = hoverColor;
            hoverMap->Add(control, info);

            control->MouseEnter += gcnew EventHandler(OnMouseEnter);
            control->MouseLeave += gcnew EventHandler(OnMouseLeave);
        }
    }

  private:
    static void OnMouseEnter(Object ^ sender, EventArgs ^ e) {
        Control ^ ctrl = dynamic_cast<Control ^>(sender);
        if (ctrl != nullptr && hoverMap->ContainsKey(ctrl)) {
            ctrl->BackColor = hoverMap[ctrl]->HoverColor;
        }
    }

    static void OnMouseLeave(Object ^ sender, EventArgs ^ e) {
        Control ^ ctrl = dynamic_cast<Control ^>(sender);
        if (ctrl != nullptr && hoverMap->ContainsKey(ctrl)) {
            Panel ^ parentPanel = dynamic_cast<Panel ^>(ctrl->Parent);
            if (parentPanel != nullptr &&
                selectedPanels->Contains(parentPanel)) {
                return;
            }
            ctrl->BackColor = hoverMap[ctrl]->OriginalColor;
        }
    }

  public:
    // Gọi một lần khi form khởi tạo
    static void AttachPanelClickHandlers(Panel ^ parentPanel) {
        for each (Control ^ ctrl in parentPanel->Controls) {
            Panel ^ pnl = dynamic_cast<Panel ^>(ctrl);
            if (pnl != nullptr) {
                pnl->Cursor = Cursors::Hand;
                pnl->Click -= gcnew EventHandler(PanelOrLabel_Click);
                pnl->Click += gcnew EventHandler(PanelOrLabel_Click);

                for each (Control ^ child in pnl->Controls) {
                    if (dynamic_cast<Label ^>(child) != nullptr) {
                        child->Cursor = Cursors::Hand;
                        child->Click -= gcnew EventHandler(PanelOrLabel_Click);
                        child->Click += gcnew EventHandler(PanelOrLabel_Click);
                    }
                }
            }
        }
    }

    // Hàm public để kiểm tra panel có đang được chọn không
    static bool IsPanelSelected(Panel ^ panel) {
        return selectedPanels->Contains(panel);
    }

  private:
    // Tập hợp các panel đang được chọn
    static System::Collections::Generic::HashSet<Panel ^> ^ selectedPanels =
        gcnew System::Collections::Generic::HashSet<Panel ^>();


    static void PanelOrLabel_Click(Object ^ sender, EventArgs ^ e) {
        Control ^ clicked = dynamic_cast<Control ^>(sender);
        if (clicked == nullptr)
            return;

        Panel ^ selectedPanel = dynamic_cast<Panel ^>(clicked);
        if (selectedPanel == nullptr && clicked->Parent != nullptr) {
            selectedPanel = dynamic_cast<Panel ^>(clicked->Parent);
        }

        if (selectedPanel == nullptr)
            return;

        Panel ^ parentPanel = dynamic_cast<Panel ^>(selectedPanel->Parent);
        if (parentPanel == nullptr)
            return;

        // Clear trạng thái tất cả panel và label trong parent
        for each (Control ^ ctrl in parentPanel->Controls) {
            Panel ^ pnl = dynamic_cast<Panel ^>(ctrl);
            if (pnl != nullptr) {
                pnl->BackColor = Color::White;
                selectedPanels->Remove(pnl); // Gỡ khỏi danh sách chọn

                for each (Control ^ child in pnl->Controls) {
                    Label ^ lbl = dynamic_cast<Label ^>(child);
                    if (lbl != nullptr) {
                        lbl->BackColor = Color::White;
                        lbl->ForeColor = Color::Black;
                    }
                }
            }
        }

        // Chọn panel mới
        Color selectedColor = Color::FromArgb(255, 128, 128);
        selectedPanel->BackColor = selectedColor;
        selectedPanels->Add(selectedPanel); // Đánh dấu panel được chọn

        for each (Control ^ child in selectedPanel->Controls) {
            Label ^ lbl = dynamic_cast<Label ^>(child);
            if (lbl != nullptr) {
                lbl->BackColor = selectedColor;
                lbl->ForeColor = Color::White;
            }
        }
    }
};
