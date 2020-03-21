#pragma once
#include <memory>
#include "QWidget"


namespace Ui { class RequestPage; }
namespace application { class CAPIInterface; }
namespace application { class CAPIMethod; }

namespace application
{
    /// Template of API request page.
    class CRequestPage : public QWidget
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CRequestPage);

    public:
        CRequestPage(QWidget* Parent_, const CAPIInterface* Interface_, const CAPIMethod* Method_);
        ~CRequestPage();

    private:
        void initFields();
        void initParametersTable();
        
    private:
        std::shared_ptr<Ui::RequestPage> ui;
        const CAPIInterface* m_InterfaceRef = nullptr;
        const CAPIMethod* m_MethodRef = nullptr;
    };
}
// Кириллица.
