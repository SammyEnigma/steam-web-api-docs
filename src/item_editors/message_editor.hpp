#pragma once
#include "QJsonDocument"

#include "gui/json_editor/dlg_json_editor.hpp"


namespace application
{
    /// Item editor for "{message}" (QJsonDocument) type.
    class CMessageEditor : public CDlgJsonEditor
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CMessageEditor);
        Q_PROPERTY(QJsonDocument value READ GetDocument WRITE SetDocument USER true);

    public:
        CMessageEditor(QWidget* Parent_);
        ~CMessageEditor();
    };
}
// Кириллица.

