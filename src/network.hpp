#pragma once
#include "QJsonObject"
#include "QNetworkAccessManager"


namespace application { class CAPIInterface; }
namespace application { class CAPIMethod; }

namespace application
{
    /// Network related utilities.
    class CNetwork : protected QNetworkAccessManager
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CNetwork);

    public:
        CNetwork(QObject* Parent_);
        ~CNetwork() = default;
        
        QJsonObject ReloadAPI();
        QJsonObject MakeQuery(const CAPIInterface* Interface_, const CAPIMethod* Method_);

    private:
        QJsonObject makeQuery(const QString& InterfaceName_, const QString& MethodName_, quint32 Version_);
        QString formatRequest(const QString& InterfaceName_, const QString& MethodName_, quint32 Version_);

    private Q_SLOTS:
        QJsonObject onReadyRead(QNetworkReply* Reply_);
    };
}
// Кириллица.

