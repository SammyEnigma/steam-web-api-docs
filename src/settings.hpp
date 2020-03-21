#pragma once
#include "QString"


namespace application
{
    /// Global per-application settings.
    class CSettings
    {
    public:
        CSettings();
        ~CSettings();

        void LoadSettings();
        void SaveSettings();

        const QString& GetAPIKey() const;
        void SetAPIKey(const QString& Key_);

        const QString& GetAPIUrl() const;
        void SetAPIUrl(const QString& Url_);

        bool IsInitialized() const;
        
    private:
        bool m_Changed = false;
        QString m_APIKey;
        QString m_APIUrl;
    };
}
// Кириллица.

