#include "parameter.hpp"

#include "types/api_method_parameter.hpp"
#include "types/item_editor_factory.hpp"
#include "application.hpp"


namespace application
{
    CParameter::CParameter(const CAPIMethodParameter* Template_)
        : m_Parameter(Template_)
    {
        // TODO: Один из параметров - key, его сделать вычисляемым из настроек.
        CItemEditorFactory* ief = ItemEditorFactory();
        if (ief && m_Parameter)
            m_Value = ief->CreateVariant(GetType());
    }

    QString CParameter::GetName() const
    {
        if (m_Parameter && !m_Parameter->GetName().isEmpty())
            return m_Parameter->GetName();

        return QObject::tr("Без имени");
    }


    QString CParameter::GetDescription() const
    {
        if (m_Parameter && !m_Parameter->GetDescription().isEmpty())
            return m_Parameter->GetDescription();

        return QObject::tr("Без описания");
    }

    
    QString CParameter::GetType() const
    {
        if (m_Parameter && !m_Parameter->GetType().isEmpty())
            return m_Parameter->GetType();

        return QObject::tr("Неизвестный тип");
    }


    bool CParameter::IsRequired() const
    {
        return m_Parameter ? !m_Parameter->IsOptional() : true;
    }


    const QVariant& CParameter::GetValue() const
    {
        return m_Value;
    }


    void CParameter::SetValue(const QVariant& Value_)
    {
        // TODO: Проверка типа значения.
        m_Value = Value_;
    }
}
// Кириллица.
