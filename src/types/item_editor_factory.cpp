#include "item_editor_factory.hpp"

#include <QDebug>

#include "item_editors/string_editor.hpp"
#include "item_editors/uint32_editor.hpp"
#include "item_editors/uint64_editor.hpp"
#include "item_editors/int32_editor.hpp"
#include "item_editors/bool_editor.hpp"
#include "item_editors/enum_editor.hpp"
#include "item_editors/rawbinary_editor.hpp"
#include "item_editors/message_editor.hpp"


namespace application
{
    QWidget* CItemEditorFactory::createEditor(int userType, QWidget* parent) const
    {
        QWidget* pCustomWidget = QItemEditorFactory::createEditor(userType, parent);
        return pCustomWidget ? pCustomWidget : (m_DefaultFactoryRef ? m_DefaultFactoryRef->createEditor(userType, parent) : nullptr);
    }


    CItemEditorFactory::CItemEditorFactory()
        : m_DefaultFactoryRef(defaultFactory())
    {
        setDefaultFactory(this);

        registerTypeAndEditor<QString, CStringEditor>("string");
        registerTypeAndEditor<quint32, CUint32Editor>("uint32");
        registerTypeAndEditor<quint64, CUint64Editor>("uint64");
        registerTypeAndEditor<qint32, CInt32Editor>("int32");
        registerTypeAndEditor<bool, CBoolEditor>("bool");
        registerTypeAndEditor<QByteArray, CRawBinaryEditor>("rawbinary");
        registerTypeAndEditor<QJsonObject, CMessageEditor>("{message}");
        registerTypeAndEditor<int, CEnumEditor>("{enum}");
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
