#include "int32_editor.hpp"


namespace application
{
    CInt32Editor::CInt32Editor(QWidget* Parent_)
        : CBaseSpinBoxEditor(Parent_)
    {}


    qint32 CInt32Editor::GetValue() const
    {
        return static_cast<qint64>(value());
    }


    void CInt32Editor::SetValue(qint32 Value_)
    {
        setValue(static_cast<quint64>(Value_));
    }
}
// Кириллица.
