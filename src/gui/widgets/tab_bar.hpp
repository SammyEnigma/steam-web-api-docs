#pragma once
#include "QTabBar"

class QMouseEvent;

namespace application
{
    /// Extended tab widget bar.
    class CTabBar final : public QTabBar
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CTabBar);

    public:
        CTabBar(QWidget* Parent_);
        ~CTabBar() = default;
        

    protected:
        void mouseReleaseEvent(QMouseEvent* event) override final;
    };
}
// Кириллица.

