#include "api_model.hpp"

#include "QJsonObject"
#include "QJsonArray"

#include "types/api_interface.hpp"
#include "types/api_method.hpp"


static const char* sAPIList = "apilist";
static const char* sInterfaces = "interfaces";

namespace application
{
    CAPIModel::CAPIModel(QObject* Parent_)
        : QAbstractItemModel(Parent_)
    {}


    CAPIModel::~CAPIModel() = default;


    void CAPIModel::InitFromResponse(const QJsonObject& Response_)
    {
        beginResetModel();

        m_vInterfaces.clear();
        QJsonObject objApiList = Response_[sAPIList].toObject();
        QJsonArray arrInterfaces = objApiList[sInterfaces].toArray();
        m_vInterfaces.reserve(arrInterfaces.count());
        for (const QJsonValue& v : arrInterfaces)
        {
            CAPIInterface ifc(v.toObject());
            m_vInterfaces.push_back(ifc);
        }

        endResetModel();
    }


    void CAPIModel::Clear()
    {
        beginResetModel();
        m_vInterfaces.clear();
        endResetModel();
    }


    const CAPIInterface* CAPIModel::GetInterface(const QModelIndex& Index_) const
    {
        if (!Index_.isValid())
            return nullptr;

        int parentRow = static_cast<int>(Index_.internalId());
        if (parentRow == -1)
            return &m_vInterfaces.at(Index_.row());

        return GetInterface(parent(Index_));
    }


    const CAPIMethod* CAPIModel::GetMethod(const QModelIndex& Index_) const
    {
        if (!Index_.isValid())
            return nullptr;

        int parentRow = static_cast<int>(Index_.internalId());
        if (parentRow == -1)
            return nullptr;

        const CAPIInterface* pIfc = GetInterface(Index_);
        return pIfc ? pIfc->GetMethod(Index_.row()) : nullptr;
    }


    QModelIndex CAPIModel::index(int row, int column, const QModelIndex& parent /*= QModelIndex()*/) const
    {
        Q_UNUSED(column);
        return createIndex(row, 0, parent.isValid() ? parent.row() : -1);
    }


    QModelIndex CAPIModel::parent(const QModelIndex& child) const
    {
        if (!child.isValid())
            return {};

        int r = static_cast<int>(child.internalId());
        if (r == -1) // Parent for interface?
            return {};

        return index(r, 0, {});
    }


    int CAPIModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const
    {
        if (!parent.isValid())
            return m_vInterfaces.count();

        int r = static_cast<int>(parent.internalId());
        if (r != -1) // Row count for method item
            return 0;

        r = parent.row();
        const CAPIInterface& ifc = m_vInterfaces.at(r);
        return ifc.GetMethodsCount();
    }


    int CAPIModel::columnCount(const QModelIndex& parent /*= QModelIndex()*/) const
    {
        return 1;
    }


    QVariant CAPIModel::data(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
    {
        if (!index.isValid())
            return -1;

        int parentRow = static_cast<int>(index.internalId());
        int row = index.row();

        return parentRow == -1 ? interfaceData(row, role) : methodData(parentRow, row, role);
    }


    QVariant CAPIModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
    {
        if (section == 0)
        {
            if (role == Qt::DisplayRole)
                return tr("Интерфейсы и методы Steam Web API");
        }

        return QAbstractItemModel::headerData(section, orientation, role);
    }


    QVariant CAPIModel::interfaceData(int Num_, int Role_) const
    {
        const CAPIInterface* ifc = Num_ >= 0 && Num_ < m_vInterfaces.count() ? &m_vInterfaces.at(Num_) : nullptr;
        if (!ifc)
            return {};

        switch (Role_)
        {
        case Qt::DisplayRole:
            return ifc->GetName();

        default: break;
        }

        return {};
    }


    QVariant CAPIModel::methodData(int InterfaceNum_, int MethodNum_, int Role_) const
    {
        const CAPIInterface* ifc = InterfaceNum_ >= 0 && InterfaceNum_ < m_vInterfaces.count() ? &m_vInterfaces.at(InterfaceNum_) : nullptr;
        const CAPIMethod* m = ifc ? ifc->GetMethod(MethodNum_) : nullptr;
        if (!m)
            return {};

        switch (Role_)
        {
        case Qt::DisplayRole:
            return m->GetName();

        default: break;
        }

        return {};
    }

}
// Кириллица.
