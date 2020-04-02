#include "dlg_hex_editor.hpp"

#include "QSettings"
#include "QByteArray"
#include "QBuffer"

#include "ui_DlgHexEditor.h"

#include "document/buffer/qmemorybuffer.h"


static const char* sGeometry = "geometry";

using namespace std;

namespace application
{
    CDlgHexEditor::CDlgHexEditor(QWidget* Parent_)
        : QDialog(Parent_)
        , ui(make_unique<Ui::DlgHexEditor>())
    {
        ui->setupUi(this);

        connect(ui->btnApply, &QPushButton::clicked, this, &CDlgHexEditor::onAccept);

        QTimer::singleShot(0, [this]()
        {
            QSettings s;
            s.beginGroup(objectName());
            if (s.contains(sGeometry))
                restoreGeometry(s.value(sGeometry).toByteArray());
            s.endGroup();
        });
    }


    void CDlgHexEditor::SetData(const QByteArray& Array_)
    {
        m_Data = Array_;
        ui->hexView->setDocument(QHexDocument::fromMemory<QMemoryBuffer>(m_Data));
    }


    QByteArray CDlgHexEditor::GetData() const
    {
        return m_Data;
    }


    void CDlgHexEditor::onAccept()
    {
        //QBuffer b(&m_Data);
        //b.open(QIODevice::WriteOnly);
        //ui->hexView->document()->saveTo(&b);
        //b.close();
        accept();
    }


    CDlgHexEditor::~CDlgHexEditor()
    {
        QSettings s;
        s.beginGroup(objectName());
        s.setValue(sGeometry, saveGeometry());
        s.endGroup();
    }
}
// Кириллица.
