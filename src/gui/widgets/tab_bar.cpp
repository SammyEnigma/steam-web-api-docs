#include "tab_bar.hpp"

#include "QMouseEvent"
#include "QDebug"


namespace application
{
    CTabBar::CTabBar(QWidget* Parent_)
        : QTabBar(Parent_)
    {}


    void CTabBar::mouseReleaseEvent(QMouseEvent* event)
    {
        QTabBar::mouseReleaseEvent(event);
        if (!event)
            return;

        if (event->button() == Qt::MiddleButton) // Request for closing tab by pressing MMB.
        {
            QPoint clickPos = mapFromGlobal(event->globalPos());
            for (int i = 0; i < count(); ++i)
                if (tabRect(i).contains(clickPos))
                {
                    Q_EMIT tabCloseRequested(i);
                    break;
                }
        }
    }
}
// Кириллица.
