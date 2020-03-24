#pragma once
#include "QApplication"

#include "settings.hpp"
#include "network.hpp"
#include "types/item_editor_factory.hpp"


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
        CItemEditorFactory& ItemEditorFactory();

    private:
        CSettings m_Settings;
        CNetwork m_Network;
        CItemEditorFactory m_ItemEditorFactory;
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


inline application::CItemEditorFactory* ItemEditorFactory()
{
    application::CApplication* app = Application();
    return app ? &app->ItemEditorFactory() : nullptr;
}
// Кириллица.
