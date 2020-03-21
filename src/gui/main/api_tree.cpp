#include "api_tree.hpp"

#include "api_model.hpp"


namespace application
{
    CAPITree::CAPITree(QWidget* Parent_)
        : QTreeView(Parent_)
        , m_ModelRef(new CAPIModel(this))
    {
        setModel(m_ModelRef);
        setAlternatingRowColors(true);

        connect(this, &CAPITree::doubleClicked, this, &CAPITree::onItemDoubleClicked);
    }


    CAPIModel& CAPITree::GetModel() const
    {
        return *m_ModelRef;
    }


    void CAPITree::onItemDoubleClicked(const QModelIndex& Index_)
    {
        const CAPIInterface* pIfc = m_ModelRef->GetInterface(Index_);
        const CAPIMethod* pMethod = m_ModelRef->GetMethod(Index_);

        if (pIfc && pMethod)
            Q_EMIT MethodSelected(pIfc, pMethod);
    }

}
// Кириллица.
