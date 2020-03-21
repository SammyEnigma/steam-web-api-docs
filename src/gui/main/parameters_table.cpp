#include "parameters_table.hpp"

#include "QHeaderView"

#include "parameters_model.hpp"


namespace application
{
    CParametersTable::CParametersTable(QWidget* Parent_)
        : QTableView(Parent_)
        , m_ModelRef(new CParametersModel(this))
    {
        setModel(m_ModelRef);
        setAlternatingRowColors(true);
        verticalHeader()->hide();

        connect(m_ModelRef, &CParametersModel::modelReset, this, &CParametersTable::onModelReset);

        
    }


    CParametersModel& CParametersTable::GetModel() const
    {
        Q_ASSERT(m_ModelRef);
        return *m_ModelRef;
    }


    void CParametersTable::onModelReset()
    {
        if (m_ModelRef->columnCount())
        {
            QHeaderView* pHeader = horizontalHeader();
            pHeader->setSectionResizeMode(QHeaderView::ResizeToContents);
            pHeader->setSectionResizeMode(CParametersModel::Value, QHeaderView::Stretch);
        }
    }
}
// Кириллица.
