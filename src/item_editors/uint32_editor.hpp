#pragma once
#include "base_spinbox_editor.hpp"


namespace application
{
    /// Item editor for "uint32" (quint32) type.
    class CUint32Editor final : public CBaseSpinBoxEditor<quint32>
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CUint32Editor);
        Q_PROPERTY(quint32 value READ GetValue WRITE SetValue USER true);

    public:
        CUint32Editor(QWidget* Parent_);
        ~CUint32Editor() = default;
        
        quint32 GetValue() const override final;
        void SetValue(quint32 Value_) override final;
    };
}
// Кириллица.

