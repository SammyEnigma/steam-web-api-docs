#include "request_page.hpp"

#include "QSettings"
#include "QHeaderView"

#include "ui_RequestPage.h"
#include "types/api_interface.hpp"
#include "types/api_method.hpp"
#include "parameters_model.hpp"


using namespace std;

static const char* sGeometry = "geometry";

namespace application
{
    CRequestPage::CRequestPage(QWidget* Parent_, const CAPIInterface* Interface_, const CAPIMethod* Method_)
        : QWidget(Parent_)
        , ui(make_unique<Ui::RequestPage>())
        , m_InterfaceRef(Interface_)
        , m_MethodRef(Method_)
    {
        ui->setupUi(this);
        initFields();
        initParametersTable();

        QSettings s;
        s.beginGroup(objectName());
        if (s.contains(sGeometry))
            restoreGeometry(s.value(sGeometry).toByteArray());
        s.endGroup();
    }


    CRequestPage::~CRequestPage()
    {
        QSettings s;
        s.beginGroup(objectName());
        s.setValue(sGeometry, saveGeometry());
        s.endGroup();
    }


    void CRequestPage::initFields()
    {
        if (!m_InterfaceRef || !m_MethodRef)
            return;

        ui->interfaceName->setText(m_InterfaceRef->GetName());
        ui->methodName->setText(m_MethodRef->GetName());
        ui->version->setText(QString().setNum(m_MethodRef->GetVersion()));
        ui->httpMethod->setText(m_MethodRef->GetHTTPMethod());
        ui->paramsCount->setText(QString().setNum(m_MethodRef->GetParametersCount()));
    }


    void CRequestPage::initParametersTable()
    {
        ui->parametersTable->GetModel().SetMethod(m_MethodRef);
    }
}
// Кириллица.

