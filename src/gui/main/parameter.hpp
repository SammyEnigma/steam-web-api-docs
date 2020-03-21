#pragma once
#include "QString"
#include "QVariant"


namespace application { class CAPIMethodParameter; }

namespace application
{
    /// Single parameter for parameters table.
    class CParameter
    {
    public:
        CParameter(const CAPIMethodParameter* Template_);
        ~CParameter() = default;
        
        QString GetName() const;
        QString GetDescription() const;
        QString GetType() const;
        bool IsRequired() const;
        
        const QVariant& GetValue() const;
        void SetValue(const QVariant& Value_);


    private:
        const CAPIMethodParameter* m_Parameter = nullptr;
        QVariant m_Value;
    };
}
// Кириллица.

