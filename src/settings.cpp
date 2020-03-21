#include "settings.hpp"

#include "QSettings"


static const char* sGlobals = "globals";
static const char* sAPIUrl = "api_url";
static const char* sAPIKey = "api_key";

namespace application
{
    CSettings::CSettings()
    {}


    CSettings::~CSettings()
    {}


    void CSettings::LoadSettings()
    {
        QSettings s;
        s.beginGroup(sGlobals);
        if (s.contains(sAPIUrl))
            m_APIUrl = s.value(sAPIUrl).toString();
        if (s.contains(sAPIKey))
            m_APIKey = s.value(sAPIKey).toString();

        s.endGroup();
    }


    void CSettings::SaveSettings()
    {
        if (!m_Changed)
            return;

        QSettings s;
        s.beginGroup(sGlobals);
        s.setValue(sAPIUrl, m_APIUrl);
        s.setValue(sAPIKey, m_APIKey);
        s.endGroup();
    }


    const QString& CSettings::GetAPIKey() const
    {
        return m_APIKey;
    }


    void CSettings::SetAPIKey(const QString& Key_)
    {
        m_Changed = true;
        m_APIKey = Key_;
    }


    const QString& CSettings::GetAPIUrl() const
    {
        return m_APIUrl;
    }


    void CSettings::SetAPIUrl(const QString& Url_)
    {
        m_Changed = true;
        m_APIUrl = Url_;
    }


    bool CSettings::IsInitialized() const
    {
        return !m_APIUrl.isEmpty();
    }
}
// Кириллица.
