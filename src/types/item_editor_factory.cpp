#include "item_editor_factory.hpp"

#include <QDebug>

#include "item_editors/string_editor.hpp"


namespace application
{
    QWidget* CItemEditorFactory::createEditor(int userType, QWidget* parent) const
    {
        QWidget* pDefaultWidget = m_DefaultFactoryRef ? m_DefaultFactoryRef->createEditor(userType, parent) : nullptr;
        return pDefaultWidget ? pDefaultWidget : QItemEditorFactory::createEditor(userType, parent);
    }


    CItemEditorFactory::CItemEditorFactory()
        : m_DefaultFactoryRef(defaultFactory())
    {
        setDefaultFactory(this);

        registerTypeAndEditor<QString, CStringEditor>("string");
    }


    QVariant CItemEditorFactory::CreateVariant(const QString& TypeName_) const
    {
        auto it = m_TypeNameToTypeId.find(TypeName_);
        if (it == m_TypeNameToTypeId.end())
        {
            qDebug() << "Nor type name" << TypeName_ << "nor item editor are not registered";
            return {};
        }

        return QVariant(it.value(), nullptr);
    }
}
// Кириллица.
