#include "dlg_main_window.hpp"

#include "QSettings"
#include "QTimer"

#include "ui_MainWindow.h"
#include "application.hpp"
#include "gui/settings/dlg_settings.hpp"
#include "api_model.hpp"

#include "types/api_interface.hpp"
#include "types/api_method.hpp"
#include "requests_widget.hpp"


using namespace std;

static const char* sGeometry = "geometry";
static const char* sSplitterState = "splitterState";

namespace application
{
    CDlgMainWindow::CDlgMainWindow(QWidget* Parent_)
        : QMainWindow(Parent_)
        , ui(make_unique<Ui::MainWindow>())
    {
        ui->setupUi(this);

        connect(ui->actReloadAPI, &QAction::triggered, this, &CDlgMainWindow::onReloadMethods);
        connect(ui->actQuit, &QAction::triggered, this, &CDlgMainWindow::onExit);
        connect(ui->actConnectionSettings, &QAction::triggered, this, &CDlgMainWindow::onConnectionSettings);

        connect(ui->methodsTree, &CAPITree::MethodSelected, ui->tabRequests, &CRequestsWidget::AddPage);

        QSettings s;
        s.beginGroup(objectName());
        if (s.contains(sGeometry))
            restoreGeometry(s.value(sGeometry).toByteArray());
        if (s.contains(sSplitterState))
            ui->splitter->restoreState(s.value(sSplitterState).toByteArray());
        s.endGroup();

        QTimer::singleShot(0, [this]() 
        {
            CSettings* pSettings = Settings();
            if (pSettings && !pSettings->IsInitialized())
                ui->actConnectionSettings->trigger();

            ui->actReloadAPI->trigger();
        });
        
    }


    CDlgMainWindow::~CDlgMainWindow()
    {
        QSettings s;
        s.beginGroup(objectName());
        s.setValue(sGeometry, saveGeometry());
        s.setValue(sSplitterState, ui->splitter->saveState());
        s.endGroup();
    }

    
    void CDlgMainWindow::onReloadMethods()
    {
        statusBar()->showMessage(tr("Начат процесс перезагрузки доступных интерфейсов и методов..."));
        
        ui->tabRequests->CloseAllPages();
        ui->tabResponses->CloseAllPages();
        CAPIModel& model = ui->methodsTree->GetModel();
        model.Clear();
        QJsonObject apiData = Network()->ReloadAPI();

        statusBar()->showMessage(tr("Методы перезагружены, заполняю список..."));
        model.InitFromResponse(apiData);

        statusBar()->showMessage(tr("Готов"));
    }

    
    void CDlgMainWindow::onConnectionSettings()
    {
        if (QDialog::Accepted == CDlgSettings(this).exec())
            ui->actReloadAPI->trigger();
    }


    void CDlgMainWindow::onExit()
    {
        close();
    }
}
// Кириллица.

