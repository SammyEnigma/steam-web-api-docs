#pragma once
#include "QString"
#include "QVector"


namespace application { class CAPIMethod; }
class QJsonObject;

namespace application
{
    /// Description of Steam API Interface.
    class CAPIInterface
    {
    public:
        CAPIInterface(const QJsonObject& InterfaceData_);
        ~CAPIInterface();
        
        const QString& GetName() const;

        int GetMethodsCount() const;
        const CAPIMethod* GetMethod(int Num_) const;

        bool IsService() const;

    private:
        QString m_Name;
        bool m_Service;
        QVector<CAPIMethod> m_vMethods;
    };
}
// Кириллица.

