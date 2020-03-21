#pragma once
#include "QAbstractItemModel"
#include "QVector"

namespace application { class CAPIInterface; }
namespace application { class CAPIMethod; }
class QJsonObject;

namespace application
{
    /// Steam Web API Interfaces tree model.
    class CAPIModel : public QAbstractItemModel
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CAPIModel);

    public:
        CAPIModel(QObject* Parent_);
        ~CAPIModel();

        void InitFromResponse(const QJsonObject& Response_);
        void Clear();
        const CAPIInterface* GetInterface(const QModelIndex& Index_) const;
        const CAPIMethod* GetMethod(const QModelIndex& Index_) const;
        
    public:
        QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override final;
        QModelIndex parent(const QModelIndex& child) const override final;
        int rowCount(const QModelIndex& parent = QModelIndex()) const override final;
        int columnCount(const QModelIndex& parent = QModelIndex()) const override final;
        QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override final;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override final;

    private:
        QVariant interfaceData(int Num_, int Role_) const;
        QVariant methodData(int InterfaceNum_, int MethodNum_, int Role_) const;

    private:
        QVector<CAPIInterface> m_vInterfaces;
    };
    
}
// Кириллица.

