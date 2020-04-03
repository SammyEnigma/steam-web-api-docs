#pragma once
#include "QSpinBox"


namespace application
{
    /// Item editor for "{enum}" (int) type.
    class CEnumEditor : public QSpinBox
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

