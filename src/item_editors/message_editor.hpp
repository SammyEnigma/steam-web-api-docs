#pragma once
#include "QLabel"
#include "QJsonObject"


namespace application
{
    /// Item editor for "{message}" (QJsonObject?) type.
    class CMessageEditor : public QLabel
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CMessageEditor);
        Q_PROPERTY(QJsonObject value READ GetValue WRITE SetValue USER true);

    public:
        CMessageEditor(QWidget* Parent_);
        ~CMessageEditor() = default;
        
        QJsonObject GetValue() const;
        void SetValue(const QJsonObject& Value_);
    };
}
// Кириллица.

