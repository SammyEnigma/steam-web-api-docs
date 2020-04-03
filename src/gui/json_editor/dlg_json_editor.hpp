#pragma once
#include <memory>

#include "QDialog"
#include "QJsonDocument"


namespace Ui { class DlgJsonEditor; }

namespace application
{
    /// QJsonDocument editor dialog.
    class CDlgJsonEditor : public QDialog
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CDlgJsonEditor);

    public:
        CDlgJsonEditor(QWidget* Parent_);
        ~CDlgJsonEditor();

        /// Set source document for editor.
        void SetDocument(const QJsonDocument& Document_);

        /// Get document from an editor.
        QJsonDocument GetDocument() const;

    private Q_SLOTS:
        void onApply();
        
    private:
        std::unique_ptr<Ui::DlgJsonEditor> ui;
        QJsonDocument m_Document;
    };
}
// Кириллица.

