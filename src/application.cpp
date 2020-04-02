#include "application.hpp"


namespace application
{
    CApplication::CApplication(int Argc_, char** Argv_)
        : QApplication(Argc_, Argv_)
        , m_Network(this)
        , m_ItemEditorFactoryRef(new CItemEditorFactory(QItemEditorFactory::defaultFactory()))
    {
        setApplicationName("Steam Web API Docs");
        setOrganizationName("T-Max");

        m_Settings.LoadSettings();
        QItemEditorFactory::setDefaultFactory(m_ItemEditorFactoryRef);
    }


    CApplication::~CApplication()
    {
        m_Settings.SaveSettings();
    }


    CSettings& CApplication::Settings()
    {
        return m_Settings;
    }


    CNetwork& CApplication::Network()
    {
        return m_Network;
    }


    CItemEditorFactory* CApplication::ItemEditorFactory() const
    {
        return m_ItemEditorFactoryRef;
    }
}
// Кириллица.
