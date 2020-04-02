#pragma once
#include "gui/hex_editor/dlg_hex_editor.hpp"


namespace application
{
    /// Item editor for "rawbinary" (QByteArray) type.
    class CRawBinaryEditor : public CDlgHexEditor
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CRawBinaryEditor);
        Q_PROPERTY(QByteArray value READ GetData WRITE SetData USER true);

    public:
        CRawBinaryEditor(QWidget* Parent_);
        ~CRawBinaryEditor();
    };
}
// Кириллица.

