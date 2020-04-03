#include "dlg_json_editor.hpp"

#include "QSettings"
#include "QTimer"

#include "ui_DlgJsonEditor.h"
#include "gui/widgets/json_view_model.hpp"


using namespace std;
using namespace Qt;

static const char* sGeometry = "geometry";

namespace application
{
    CDlgJsonEditor::CDlgJsonEditor(QWidget* Parent_)
        : QDialog(Parent_)
        , ui(make_unique<Ui::DlgJsonEditor>())
    {
        ui->setupUi(this);

        connect(ui->btnApply, &QPushButton::clicked, this, &CDlgJsonEditor::onApply);

        QTimer::singleShot(0, [this]()
        {
            QSettings s;
            s.beginGroup(objectName());
            if (s.contains(sGeometry))
                restoreGeometry(s.value(sGeometry).toByteArray());
            s.endGroup();
        });
    }


    CDlgJsonEditor::~CDlgJsonEditor()
    {
        QSettings s;
        s.beginGroup(objectName());
        s.setValue(sGeometry, saveGeometry());
        s.endGroup();
    }


    void CDlgJsonEditor::SetDocument(const QJsonDocument& Document_)
    {
        m_Document = Document_;
        CJsonViewModel* pModel = ui->treeJson->jsonModel();
        if (pModel)
            pModel->FromDocument(m_Document);
    }


    QJsonDocument CDlgJsonEditor::GetDocument() const
    {
        return m_Document;
    }


    void CDlgJsonEditor::onApply()
    {
        CJsonViewModel* pModel = ui->treeJson->jsonModel();
        if (pModel)
            pModel->ToDocument(m_Document);

        accept();
    }
}
// Кириллица.
