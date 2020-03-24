#pragma once
#include "QItemEditorFactory"


namespace application
{
    /// Custom factory for table/tree item editors.
    class CItemEditorFactory final : public QItemEditorFactory
    {
    public:
        CItemEditorFactory();
        ~CItemEditorFactory() = default;


    public:
        QWidget* createEditor(int userType, QWidget* parent) const override final;


    public:
        QVariant CreateVariant(const QString& TypeName_) const;


    private:
        template<class TType, class TEditor>
        void registerTypeAndEditor(const QString& TypeName_)
        {
            int qtTypeId = qMetaTypeId<TType>();
            m_TypeNameToTypeId[TypeName_] = qtTypeId;
            registerEditor(qtTypeId, new QStandardItemEditorCreator<TEditor>());
        }


    private:
        const QItemEditorFactory* m_DefaultFactoryRef = nullptr;
        QHash<QString, int> m_TypeNameToTypeId;
    };
}
// Кириллица.
