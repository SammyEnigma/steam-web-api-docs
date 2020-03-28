#include "responses_widget.hpp"


namespace application
{
    CResponsesWidget::CResponsesWidget(QWidget* Parent_)
        : CTabWidget(Parent_)
    {
        connect(this, &CResponsesWidget::tabCloseRequested, this, &CResponsesWidget::onClosePage);
    }


    void CResponsesWidget::CloseAllPages()
    {
        while (count())
            onClosePage(0);
    }


    void CResponsesWidget::onClosePage(int Index_)
    {
        QWidget* pPage = widget(Index_);
        if (!pPage)
            return;

        removeTab(Index_);
        pPage->deleteLater();
    }

}
// Кириллица.
