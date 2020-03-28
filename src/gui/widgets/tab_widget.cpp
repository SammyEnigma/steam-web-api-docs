#include "tab_widget.hpp"

#include "tab_bar.hpp"


namespace application
{
    CTabWidget::CTabWidget(QWidget* Parent_)
        : QTabWidget(Parent_)
    {
        tabBar()->deleteLater();
        setTabBar(new CTabBar(this));
    }
}
// Кириллица.
