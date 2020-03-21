#pragma once
#include "QTabWidget"


namespace application { class CAPIInterface; }
namespace application { class CAPIMethod; }

namespace application
{
    /// Widget to display Steam Web API methods' details.
    class CRequestsWidget : public QTabWidget
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CRequestsWidget);

    public:
        CRequestsWidget(QWidget* Parent_);
        ~CRequestsWidget() = default;
        
        void CloseAllPages();

    public Q_SLOTS:
        void AddPage(const CAPIInterface* Interface_, const CAPIMethod* Method_);

    private Q_SLOTS:
        void onCloseTab(int Index_);
    };
}
// Кириллица.

