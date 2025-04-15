#include "LoadChildForm.h"

void LoadChildForm::LoadForm(Panel ^ panelContent, Form ^ frm) {
    if (frm == nullptr || panelContent == nullptr)
        return;

    if (panelContent->Controls->Count > 0) {
        Form ^ oldForm = dynamic_cast<Form ^>(panelContent->Controls[0]);
        if (oldForm != nullptr) {
            oldForm->Close(); // Gọi hàm FormClosed của form cũ (nếu có)
        }
        panelContent->Controls->Clear(); // Dọn sạch controls cũ
    }

    frm->TopLevel = false;
    frm->FormBorderStyle = FormBorderStyle::None;
    frm->Dock = DockStyle::Fill;

    panelContent->Controls->Clear();
    panelContent->Controls->Add(frm);

    frm->Show();
}
