#pragma once
#include "QTabWidget"


namespace application
{
    /// Widget to display Steam Web API responses' details.
    class CResponsesWidget : public QTabWidget
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

