#include "network.hpp"

#include "QNetworkReply"
#include "QJsonDocument"

#include "settings.hpp"
#include "application.hpp"
#include "types/api_interface.hpp"
#include "types/api_method.hpp"


namespace application
{
    CNetwork::CNetwork(QObject* Parent_)
        : QNetworkAccessManager(Parent_)
    {}


    QJsonObject CNetwork::ReloadAPI()
    {
        CSettings* pSettings = Settings();
        return makeQuery("ISteamWebAPIUtil", "GetSupportedAPIList", 1);
    }


    QJsonObject CNetwork::MakeQuery(const CAPIInterface* Interface_, const CAPIMethod* Method_)
    {
        if (!Interface_ || !Method_)
            return {};

        return makeQuery(Interface_->GetName(), Method_->GetName(), Method_->GetVersion());
    }


    QJsonObject CNetwork::makeQuery(const QString& InterfaceName_, const QString& MethodName_, quint32 Version_)
    {
        QNetworkRequest req;
        req.setUrl(formatRequest(InterfaceName_, MethodName_, Version_));

        QNetworkReply* pReply = get(req);

        bool bHandled = false;
        QJsonObject response;
        connect(pReply, &QNetworkReply::finished, [this, &response, &bHandled, pReply]()
        {
            response = onReadyRead(pReply);
            pReply->deleteLater();
            bHandled = true;
        });

        while (!bHandled)
        {
            Application()->processEvents();
            continue;
        }

        return response;
    }


    QString CNetwork::formatRequest(const QString& InterfaceName_, const QString& MethodName_, quint32 Version_)
    {
        CSettings* pSettings = Settings();
        if (!pSettings)
            return {};

        QString baseRequest = QString("%1/%2/%3/v%4").arg(pSettings->GetAPIUrl()).arg(InterfaceName_).arg(MethodName_).arg(Version_, 4, 10, QChar('0'));
        if (pSettings->GetAPIKey().isEmpty())
            return baseRequest;

        return baseRequest + QString("?key=%1").arg(pSettings->GetAPIKey());
    }


    QJsonObject CNetwork::onReadyRead(QNetworkReply* Reply_)
    {
        if (!Reply_)
        {
            qWarning() << "Nothing to read from network reply";
            return {};
        }

        QJsonParseError err;
        QJsonDocument d = QJsonDocument::fromJson(Reply_->readAll(), &err);
        if (err.error != QJsonParseError::NoError)
        {
            qWarning() << "Json parse error:" << err.errorString();
            return {};
        }
        
        if (!d.isObject())
        {
            qWarning() << "Steam Web API response is not a Json object";
            return {};
        }

        return d.object();
    }
}
// Кириллица.
