#pragma once
#include "gui/widgets/tab_widget.hpp"


namespace application
{
    /// Widget to display Steam Web API responses' details.
    class CResponsesWidget : public CTabWidget
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CResponsesWidget);

    public:
        CResponsesWidget(QWidget* Parent_);
        ~CResponsesWidget() = default;
        
        void CloseAllPages();

    private Q_SLOTS:
        void onClosePage(int Index_);
    };
}
// Кириллица.

