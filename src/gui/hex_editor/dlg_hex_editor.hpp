#pragma once
#include "QDialog"


namespace Ui { class DlgHexEditor; }

namespace application
{
    /// Dialog for QByteArray viewing/editing.
    class CDlgHexEditor : public QDialog
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CDlgHexEditor);

    public:
        CDlgHexEditor(QWidget* Parent_);
        ~CDlgHexEditor();
        
        /// Set source data array.
        void SetData(const QByteArray& Array_);

        /// Retrieve source data array.
        QByteArray GetData() const;


    private Q_SLOTS:
        void onAccept();

    private:
        std::unique_ptr<Ui::DlgHexEditor> ui;
        QByteArray m_Data;
    };
}
// Кириллица.

