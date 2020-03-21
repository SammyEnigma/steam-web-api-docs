#include "dlg_settings.hpp"

#include "QSettings"

#include "ui_SettingsWindow.h"
#include "settings.hpp"
#include "application.hpp"


using namespace std;

static const char* sGeometry = "geometry";

namespace application
{
    CDlgSettings::CDlgSettings(QWidget* Parent_)
        : QDialog(Parent_)
        , ui(make_unique<Ui::SettingsWindow>())
    {
        ui->setupUi(this);
        connect(ui->lineApiUrl, &QLineEdit::textChanged, this, &CDlgSettings::onSomethingChanged);
        connect(ui->lineKey, &QLineEdit::textChanged, this, &CDlgSettings::onSomethingChanged);
        connect(ui->btnApply, &QPushButton::clicked, this, &CDlgSettings::onApplySettings);
        initFields();

        QSettings s;
        s.beginGroup(objectName());
        if (s.contains(sGeometry))
            restoreGeometry(s.value(sGeometry).toByteArray());
        s.endGroup();
    }


    CDlgSettings::~CDlgSettings()
    {
        QSettings s;
        s.beginGroup(objectName());
        s.setValue(sGeometry, saveGeometry());
        s.endGroup();
    }


    void CDlgSettings::initFields()
    {
        ui->btnApply->setEnabled(false);

        CSettings* pSettings = Settings();
        if (!pSettings)
        {
            ui->lineApiUrl->setEnabled(false);
            ui->lineKey->setEnabled(false);
            return;
        }

        ui->lineApiUrl->setText(pSettings->GetAPIUrl());
        ui->lineKey->setText(pSettings->GetAPIKey());
    }


    void CDlgSettings::onApplySettings()
    {
        CSettings* pSettings = Settings();
        if (!pSettings)
            return;

        pSettings->SetAPIKey(ui->lineKey->text());
        pSettings->SetAPIUrl(ui->lineApiUrl->text());
        pSettings->SaveSettings();
        accept();
    }


    void CDlgSettings::onSomethingChanged()
    {
        ui->btnApply->setEnabled(true);
    }
}
// Кириллица.
