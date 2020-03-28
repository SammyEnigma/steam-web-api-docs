#pragma once
#include "QLabel"


namespace application
{
    /// Item editor for "rawbinary" (???) type.
    class CRawBinaryEditor : public QLabel
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CRawBinaryEditor);
        Q_PROPERTY(QByteArray value READ GetValue WRITE SetValue USER true);

    public:
        CRawBinaryEditor(QWidget* Parent_);
        ~CRawBinaryEditor() = default;
        
        QByteArray GetValue() const;
        void SetValue(const QByteArray& Value_);
    };
}
// Кириллица.

