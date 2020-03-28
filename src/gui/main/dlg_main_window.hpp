#pragma once
#include <memory>

#include "QMainWindow"


namespace Ui { class MainWindow; }
namespace application { class CAPIInterface; }
namespace application { class CAPIMethod; }

namespace application
{
    /// Main window.
    class CDlgMainWindow : public QMainWindow
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CDlgMainWindow);

    public:
        CDlgMainWindow(QWidget* Parent_);
        ~CDlgMainWindow();

    private Q_SLOTS:
        void onReloadMethods();
        void onConnectionSettings();
        void onExit();
        void onMethodSelected(const CAPIInterface* Interface_, const CAPIMethod* Method_);
        
    private:
        std::unique_ptr<Ui::MainWindow> ui;
    };
    
}
// Кириллица.

