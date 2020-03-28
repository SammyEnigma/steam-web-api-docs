#pragma once
#include "QTabWidget"


namespace application
{
    /// QTabWidget with extra functionality.
    class CTabWidget : public QTabWidget
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CTabWidget);

    public:
        CTabWidget(QWidget* Parent_);
        ~CTabWidget() = default;
    };
}
// Кириллица.

