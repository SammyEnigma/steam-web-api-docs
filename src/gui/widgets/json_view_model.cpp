#include "json_view_model.hpp"
#include "QJsonArray"
#include "QJsonObject"


using namespace Qt;

namespace application
{
    namespace cols
    {
        enum
        {
            Key = 0,
            Value,

            Count
        };
    }


    CJsonViewModel::CJsonViewModel(QObject* Parent_)
        : QAbstractItemModel(Parent_)
    {}


    CJsonViewModel::~CJsonViewModel() = default;


    void CJsonViewModel::FromDocument(const QJsonDocument& Data_)
    {
        beginResetModel();
        m_Data = Data_;
        m_bRootIsObject = m_Data.isObject();
        endResetModel();
    }


    void CJsonViewModel::ToDocument(QJsonDocument& Document_) const
    {
        Document_ = QJsonDocument();

        int rc = rowCount();
        if (!rc)
            return;

        if (m_bRootIsObject)
        {
            QJsonObject obj;
            for (int r = 0; r < rc; ++r)
                ; //

            Document_.setObject(obj);
        }
        else // array
        {
            QJsonArray arr;
            for (int r = 0; r < rc; ++r)
                ; //

            Document_.setArray(arr);
        }
    }


    QModelIndex CJsonViewModel::index(int row, int column, const QModelIndex& parent /*= QModelIndex()*/) const
    {
        return {};
    }


    QModelIndex CJsonViewModel::parent(const QModelIndex& Index_) const
    {
        return {};
    }


    int CJsonViewModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const
    {
        return 0;
    }

    int CJsonViewModel::columnCount(const QModelIndex& parent /*= QModelIndex()*/) const
    {
        return cols::Count;
    }


    QVariant CJsonViewModel::data(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
    {
        return {};
    }


    QVariant CJsonViewModel::headerData(int section, Orientation orientation, int role /*= Qt::DisplayRole*/) const
    {
        if (orientation != Horizontal)
            return {};

        if (role == DisplayRole)
        {
            switch (section)
            {
            case cols::Key:
                return tr("Ключ");

            case cols::Value:
                return tr("Значение");

            default: break;
            }
        }
        return {};
    }


    Qt::ItemFlags CJsonViewModel::flags(const QModelIndex& index) const
    {
        return QAbstractItemModel::flags(index);
    }


    bool CJsonViewModel::setData(const QModelIndex& index, const QVariant& value, int role /*= Qt::EditRole*/)
    {
        return false;
    }
}
// Кириллица.
