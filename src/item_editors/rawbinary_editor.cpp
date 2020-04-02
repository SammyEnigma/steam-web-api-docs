#include "rawbinary_editor.hpp"


using namespace std;

namespace application
{
    CRawBinaryEditor::CRawBinaryEditor(QWidget* Parent_)
        : CDlgHexEditor(Parent_)
    {
        setModal(true);
    }


    CRawBinaryEditor::~CRawBinaryEditor() = default;
}
// Кириллица.
