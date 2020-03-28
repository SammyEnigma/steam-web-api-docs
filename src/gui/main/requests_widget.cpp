#include "requests_widget.hpp"

#include "QMouseEvent"
#include "QTabBar"

#include "request_page.hpp"
#include "types/api_interface.hpp"
#include "types/api_method.hpp"


namespace application
{
    CRequestsWidget::CRequestsWidget(QWidget* Parent_)
        : CTabWidget(Parent_)
    {
        connect(this, &CRequestsWidget::tabCloseRequested, this, &CRequestsWidget::onCloseTab);
    }


    void CRequestsWidget::CloseAllPages()
    {
        while (count())
            onCloseTab(0);
    }


    void CRequestsWidget::AddPage(const CAPIInterface* Interface_, const CAPIMethod* Method_)
    {
        if (!Interface_ || !Method_)
            return;

        int idx = addTab(new CRequestPage(this, Interface_, Method_), QString("%1::%2").arg(Interface_->GetName()).arg(Method_->GetName()));
        setCurrentIndex(idx);
    }


    void CRequestsWidget::onCloseTab(int Index_)
    {
        QWidget* pPage = widget(Index_);
        if (!pPage)
            return;

        removeTab(Index_);
        pPage->deleteLater();
    }
}
// Кириллица.
