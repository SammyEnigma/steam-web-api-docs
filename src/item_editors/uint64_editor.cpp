#include "uint64_editor.hpp"


namespace application
{
    CUint64Editor::CUint64Editor(QWidget* Parent_)
        : CBaseSpinBoxEditor(Parent_)
    {}


    quint64 CUint64Editor::GetValue() const
    {
        return static_cast<quint64>(value());
    }


    void CUint64Editor::SetValue(quint64 Value_)
    {
        setValue(static_cast<qint64>(Value_));
    }
}
// Кириллица.
