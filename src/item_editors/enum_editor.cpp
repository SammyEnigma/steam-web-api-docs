#include "enum_editor.hpp"


namespace application
{
    CEnumEditor::CEnumEditor(QWidget* Parent_)
        : QLabel(Parent_)
    {
        setText("Редактор {enum} не реализован");
    }


    int CEnumEditor::GetValue() const
    {
        return 0;
    }


    void CEnumEditor::SetValue(int Value_)
    {
        // TODO.
        Q_UNUSED(Value_);
    }

}
// Кириллица.
