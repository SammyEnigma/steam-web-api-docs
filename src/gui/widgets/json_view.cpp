#include "json_view.hpp"

#include "QDebug"

#include "json_view_model.hpp"


namespace application
{
    CJsonView::CJsonView(QWidget* Parent_)
        : QTreeView(Parent_)
    {
        setModel(new CJsonViewModel(this));
        setAlternatingRowColors(true);
    }


    CJsonView::~CJsonView() = default;


    CJsonViewModel* CJsonView::jsonModel() const
    {
        return qobject_cast<CJsonViewModel*>(model());
    }


    void CJsonView::setModel(QAbstractItemModel* Model_)
    {
        CJsonViewModel* pModel = qobject_cast<CJsonViewModel*>(Model_);
        QTreeView::setModel(pModel);

        if (!pModel)
            qDebug() << "CJsonView accepts only CJsonModel!";
    }
}
// Кириллица.
