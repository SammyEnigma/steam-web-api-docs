#include "uint32_editor.hpp"


namespace application
{
    CUint32Editor::CUint32Editor(QWidget* Parent_)
        : CBaseSpinBoxEditor(Parent_)
    {
    }


    quint32 CUint32Editor::GetValue() const
    {
        return static_cast<quint32>(value());
    }


    void CUint32Editor::SetValue(quint32 Value_)
    {
        setValue(static_cast<quint64>(Value_));
    }
}
// Кириллица.
