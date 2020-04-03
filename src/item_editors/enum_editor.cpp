#include "enum_editor.hpp"


using namespace std;

namespace application
{
    CEnumEditor::CEnumEditor(QWidget* Parent_)
        : QSpinBox(Parent_)
    {
        setRange(numeric_limits<int>::min(), numeric_limits<int>::max());
    }


    int CEnumEditor::GetValue() const
    {
        return value();
    }


    void CEnumEditor::SetValue(int Value_)
    {
        setValue(Value_);
    }
}
// Кириллица.
