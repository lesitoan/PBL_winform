#include "LoadChildForm.h"

void LoadChildForm::LoadForm(Panel ^ panelContent, Form ^ frm) {
    if (frm == nullptr || panelContent == nullptr)
        return;

    frm->TopLevel = false;
    frm->FormBorderStyle = FormBorderStyle::None;
    frm->Dock = DockStyle::Fill;

    panelContent->Controls->Clear();
    panelContent->Controls->Add(frm);

    frm->Show();
}
