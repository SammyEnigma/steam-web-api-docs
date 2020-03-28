#pragma once
#include "QComboBox"


namespace application
{
    /// Item editor for "bool" (bool) type.
    class CBoolEditor : public QComboBox
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CBoolEditor);
        Q_PROPERTY(bool value READ GetValue WRITE SetValue USER true);

    public:
        CBoolEditor(QWidget* Parent_);
        ~CBoolEditor() = default;
        
        bool GetValue() const;
        void SetValue(bool Value_);
    };
}
// Кириллица.

