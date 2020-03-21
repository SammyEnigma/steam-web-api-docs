#pragma once
#include "QString"


class QJsonObject;

namespace application
{
    /// Steam Web API Method parameter type.
    class CAPIMethodParameter
    {
    public:
        CAPIMethodParameter(const QJsonObject& ParameterData_);
        ~CAPIMethodParameter() = default;
        
        const QString& GetName() const;
        const QString& GetType() const;
        bool IsOptional() const;
        const QString& GetDescription() const;
        bool IsValid() const;

    private:
        QString m_Name;
        QString m_Type;
        QString m_Description;
        bool m_Optional = false;
    };
}
// Кириллица.

