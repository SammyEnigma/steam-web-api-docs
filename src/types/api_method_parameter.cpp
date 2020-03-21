#include "api_method_parameter.hpp"

#include "QJsonObject"
#include "QDebug"


static const char* sName = "name";
static const char* sType = "type";
static const char* sOptional = "optional";
static const char* sDescription = "description";

namespace application
{
    CAPIMethodParameter::CAPIMethodParameter(const QJsonObject& ParameterData_)
    {
        m_Name = ParameterData_[sName].toString();
        m_Type = ParameterData_[sType].toString();
        m_Description = ParameterData_[sDescription].toString();
        m_Optional = ParameterData_[sOptional].toBool();
    }


    const QString& CAPIMethodParameter::GetName() const
    {
        return m_Name;
    }


    const QString& CAPIMethodParameter::GetType() const
    {
        return m_Type;
    }


    bool CAPIMethodParameter::IsOptional() const
    {
        return m_Optional;
    }


    const QString& CAPIMethodParameter::GetDescription() const
    {
        return m_Description;
    }


    bool CAPIMethodParameter::IsValid() const
    {
        return !m_Type.isEmpty();
    }
}
// Кириллица.
