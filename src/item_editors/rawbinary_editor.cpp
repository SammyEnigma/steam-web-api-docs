#include "rawbinary_editor.hpp"

#include "gui/hex_editor/dlg_hex_editor.hpp"


using namespace std;

namespace application
{
    //CRawBinaryEditor::CRawBinaryEditor(QWidget* Parent_)
    //    : QLineEdit(Parent_)
    //    , m_editor(make_unique<CDlgHexEditor>(this))
    //{
    //    m_editor->setModal(true);
    //}


    //CRawBinaryEditor::~CRawBinaryEditor() = default;


    //QByteArray CRawBinaryEditor::GetValue() const
    //{
    //    if (m_EditorResult != QDialog::Accepted)
    //        return {};

    //    QByteArray arr;
    //    m_editor->GetData(arr);
    //    return arr;
    //}


    //void CRawBinaryEditor::SetValue(const QByteArray& Value_)
    //{
    //    m_Value = Value_;
    //    m_editor->SetData(m_Value);
    //}

    CRawBinaryEditor::CRawBinaryEditor(QWidget* Parent_)
        : CDlgHexEditor(Parent_)
    {
        setModal(true);
    }


    CRawBinaryEditor::~CRawBinaryEditor() = default;


    //QByteArray CRawBinaryEditor::GetValue() const
    //{
    //    if (m_EditorResult != QDialog::Accepted)
    //        return {};

    //    QByteArray arr;
    //    m_editor->GetData(arr);
    //    return arr;
    //}


    //void CRawBinaryEditor::SetValue(const QByteArray & Value_)
    //{
    //    SetData(m_Value);
    //}
}
// Кириллица.
