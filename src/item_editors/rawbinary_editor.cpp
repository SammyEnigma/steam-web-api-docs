#include "rawbinary_editor.hpp"


namespace application
{
    CRawBinaryEditor::CRawBinaryEditor(QWidget* Parent_)
        : QLabel(Parent_)
    {
        setText(tr("Редактор {rawbinary} не реализован"));
    }


    QByteArray CRawBinaryEditor::GetValue() const
    {
        return {};
    }


    void CRawBinaryEditor::SetValue(const QByteArray& Value_)
    {
        Q_UNUSED(Value_);
    }
}
// Кириллица.
