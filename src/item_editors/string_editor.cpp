#include "string_editor.hpp"


namespace application
{
    CStringEditor::CStringEditor(QWidget* Parent_)
        : QLineEdit(Parent_)
    {}


    QString CStringEditor::GetValue() const
    {
        return text();
    }


    void CStringEditor::SetValue(const QString& Value_)
    {
        setText(Value_);
    }
}
// Кириллица.
