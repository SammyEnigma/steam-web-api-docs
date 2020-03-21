#include "api_interface.hpp"

#include "QJsonObject"
#include "QJsonArray"

#include "api_method.hpp"

static const char* sName = "name";
static const char* sMethods = "methods";

namespace application
{
    CAPIInterface::CAPIInterface(const QJsonObject& InterfaceData_)
    {
        m_Name = InterfaceData_[sName].toString();
        m_Service = m_Name.right(7) == "Service";

        QJsonArray arrMethods = InterfaceData_[sMethods].toArray();
        m_vMethods.reserve(arrMethods.count());
        for (const QJsonValue& v : arrMethods)
        {
            CAPIMethod m(v.toObject());
            m_vMethods.push_back(m);
        }
    }


    CAPIInterface::~CAPIInterface() = default;


    const QString& CAPIInterface::GetName() const
    {
        return m_Name;
    }


    int CAPIInterface::GetMethodsCount() const
    {
        return m_vMethods.count();
    }


    const CAPIMethod* CAPIInterface::GetMethod(int Num_) const
    {
        return Num_ >= 0 && Num_ < m_vMethods.count() ? &m_vMethods.at(Num_) : nullptr;
    }


    bool CAPIInterface::IsService() const
    {
        return m_Service;
    }
}
// Кириллица.
