#include "message_editor.hpp"


namespace application
{
    CMessageEditor::CMessageEditor(QWidget* Parent_)
        : QLabel(Parent_)
    {
        setText(tr("Редактор {message} не реализован"));
    }


    QJsonObject CMessageEditor::GetValue() const
    {
        return {};
    }


    void CMessageEditor::SetValue(const QJsonObject& Value_)
    {
        Q_UNUSED(Value_);
    }
}
// Кириллица.
