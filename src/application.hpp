#pragma once
#include "QApplication"

#include "settings.hpp"
#include "network.hpp"


namespace application
{
    /// Main application class.
    class CApplication : public QApplication
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CApplication);

    public:
        CApplication(int Argc_, char** Argv_);
        ~CApplication();

        CSettings& Settings();
        CNetwork& Network();

    private:
        CSettings m_Settings;
        CNetwork m_Network;
    };
}


inline application::CApplication* Application()
{
    return qobject_cast<application::CApplication*>(application::CApplication::instance());
}


inline application::CSettings* Settings()
{
    application::CApplication* app = Application();
    return app ? &app->Settings() : nullptr;
}


inline application::CNetwork* Network()
{
    application::CApplication* app = Application();
    return app ? &app->Network() : nullptr;
}
// Кириллица.
