#pragma once
#include "QLineEdit"


namespace application
{
    /// Item editor for "string" (QString) type.
    class CStringEditor : public QLineEdit
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CStringEditor);
        Q_PROPERTY(QString value READ GetValue WRITE SetValue USER true);

    public:
        CStringEditor(QWidget* Parent_);
        ~CStringEditor() = default;

        QString GetValue() const;
        void SetValue(const QString& Value_);
    };
}
// Кириллица.

