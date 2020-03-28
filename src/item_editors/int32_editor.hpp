#pragma once
#include "base_spinbox_editor.hpp"


namespace application
{
    /// Item editor for "uint32" (quint32) type.
    class CInt32Editor final : public CBaseSpinBoxEditor<qint32>
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CInt32Editor);
        Q_PROPERTY(qint32 value READ GetValue WRITE SetValue USER true);

    public:
        CInt32Editor(QWidget* Parent_);
        ~CInt32Editor() = default;
        
        qint32 GetValue() const override final;
        void SetValue(qint32 Value_) override final;
    };
}
// Кириллица.

