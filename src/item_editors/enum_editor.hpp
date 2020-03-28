#pragma once
#include "QLabel"


namespace application
{
    /// Item editor for "{enum}" (???) type.
    class CEnumEditor : public QLabel
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CEnumEditor);
        Q_PROPERTY(int value READ GetValue WRITE SetValue USER true);

    public:
        CEnumEditor(QWidget* Parent_);
        ~CEnumEditor() = default;
        
        int GetValue() const;
        void SetValue(int Value_);
    };
}
// Кириллица.

