#include "response_page.hpp"

#include "QSettings"

#include "ui_ResponsePage.h"

using namespace std;

static const char* sGeometry = "geometry";

namespace application
{
    CResponsePage::CResponsePage(QWidget* Parent_)
        : QWidget(Parent_)
        , ui(make_unique<Ui::ResponsePage>())
    {
        ui->setupUi(this);

        QSettings s;
        s.beginGroup(objectName());
        if (s.contains(sGeometry))
            restoreGeometry(s.value(sGeometry).toByteArray());
        s.endGroup();
    }


    CResponsePage::~CResponsePage()
    {
        QSettings s;
        s.beginGroup(objectName());
        s.setValue(sGeometry, saveGeometry());
        s.endGroup();
    }
}
// Кириллица.

