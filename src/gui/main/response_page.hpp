#pragma once
#include <memory>

#include "QWidget"


namespace Ui { class ResponsePage; }

namespace application
{
    /// Template for API response page.
    class CResponsePage : public QWidget
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CResponsePage);

    public:
        CResponsePage(QWidget* Parent_);
        ~CResponsePage();
        
    private:
        std::unique_ptr<Ui::ResponsePage> ui;
    };
}
// Кириллица.

