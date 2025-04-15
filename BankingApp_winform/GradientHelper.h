#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Windows::Forms;

public
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
};
