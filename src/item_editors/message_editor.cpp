#include "message_editor.hpp"


namespace application
{
    CMessageEditor::CMessageEditor(QWidget* Parent_)
        : CDlgJsonEditor(Parent_)
    {
        setModal(true);
    }


    CMessageEditor::~CMessageEditor() = default;
}
// Кириллица.
