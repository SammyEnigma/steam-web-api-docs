#pragma once
#include "base_spinbox_editor.hpp"


namespace application
{
    /// Item editor for "uint32" (quint32) type.
    class CUint64Editor final : public CBaseSpinBoxEditor<quint64>
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CUint64Editor);
        Q_PROPERTY(quint64 value READ GetValue WRITE SetValue USER true);

    public:
        CUint64Editor(QWidget* Parent_);
        ~CUint64Editor() = default;
        
        quint64 GetValue() const override final;
        void SetValue(quint64 Value_) override final;
    };
}
// Кириллица.

