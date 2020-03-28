#include "bool_editor.hpp"


namespace application
{
    CBoolEditor::CBoolEditor(QWidget* Parent_)
        : QComboBox(Parent_)
    {
        addItem("false", false);
        addItem("true", true);
    }


    bool CBoolEditor::GetValue() const
    {
        return currentData().toBool();
    }


    void CBoolEditor::SetValue(bool Value_)
    {
        setCurrentIndex(findData(Value_));
    }
}
// Кириллица.
