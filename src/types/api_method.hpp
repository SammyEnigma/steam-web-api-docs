#pragma once
#include "QString"
#include "QVector"

#include "api_method_parameter.hpp"

namespace application { class CAPIMethodParameter; }
class QJsonObject;

namespace application
{
    /// Single Steam Web API method parameter description.
    class CAPIMethod
    {
    public:
        CAPIMethod(const QJsonObject& MethodData_);
        ~CAPIMethod();
        
        const QString& GetName() const;
        quint32 GetVersion() const;
        const QString& GetHTTPMethod() const;
        int GetParametersCount() const;
        const CAPIMethodParameter* GetParameter(int Num_) const;
        bool IsValid() const;

    private:
        QString m_Name;
        QString m_HTTPMethod;
        quint32 m_Version = 0;
        QVector<CAPIMethodParameter> m_vParameters;
    };
    
}
// Кириллица.

