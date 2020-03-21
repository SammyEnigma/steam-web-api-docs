#include "api_method.hpp"

#include "QJsonObject"
#include "QJsonArray"
#include "QDebug"

#include "api_method_parameter.hpp"


static const char* sName = "name";
static const char* sVersion = "version";
static const char* sHTTPMethod = "httpmethod";
static const char* sParameters = "parameters";

namespace application
{
    CAPIMethod::CAPIMethod(const QJsonObject& MethodData_)
    {
        m_Name = MethodData_[sName].toString();
        m_Version = MethodData_[sVersion].toInt();
        m_HTTPMethod = MethodData_[sHTTPMethod].toString();

        QJsonArray arrParameters = MethodData_[sParameters].toArray();
        m_vParameters.reserve(arrParameters.count());
        for (const QJsonValue& v : arrParameters)
        {
            CAPIMethodParameter par(v.toObject());
            m_vParameters.push_back(par);
        }
    }

    CAPIMethod::~CAPIMethod() = default;


    const QString& CAPIMethod::GetName() const
    {
        return m_Name;
    }


    quint32 CAPIMethod::GetVersion() const
    {
        return m_Version;
    }


    const QString& CAPIMethod::GetHTTPMethod() const
    {
        return m_HTTPMethod;
    }


    int CAPIMethod::GetParametersCount() const
    {
        return m_vParameters.count();
    }


    const CAPIMethodParameter* CAPIMethod::GetParameter(int Num_) const
    {
        return Num_ >= 0 && Num_ < m_vParameters.count() ? &m_vParameters.at(Num_) : nullptr;
    }


    bool CAPIMethod::IsValid() const
    {
        if (m_Name.isEmpty() || m_HTTPMethod.isEmpty())
            return false;

        for (const CAPIMethodParameter& p : m_vParameters)
            if (!p.IsValid())
                return false;

        return true;
    }
}
// Кириллица.
