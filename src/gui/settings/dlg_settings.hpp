#pragma once
#include <memory>

#include "QDialog"


namespace Ui { class SettingsWindow; }
namespace application
{
    /// Settings dialog.
    class CDlgSettings : public QDialog
    {
    public:
        CDlgSettings(QWidget* Parent_);
        ~CDlgSettings();
        
        void initFields();

    private Q_SLOTS:
        void onApplySettings();
        void onSomethingChanged();

    private:
        std::unique_ptr<Ui::SettingsWindow> ui;
    };
    
}
// Кириллица.

