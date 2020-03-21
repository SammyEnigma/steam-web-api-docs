#include "parameters_model.hpp"

#include "types/api_method.hpp"
#include "parameter.hpp"


namespace application
{
    CParametersModel::CParametersModel(QObject* Parent_)
        : QAbstractTableModel(Parent_)
    {}


    void CParametersModel::SetMethod(const CAPIMethod* Method_)
    {
        beginResetModel();
        m_vParameters.clear();
        if (Method_)
        {
            int methodsCount = Method_->GetParametersCount();
            m_vParameters.reserve(methodsCount);
            for (int i = 0; i < methodsCount; ++i)
                m_vParameters.push_back(CParameter(Method_->GetParameter(i)));
        }
        endResetModel();
    }


    int CParametersModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const
    {
        Q_UNUSED(parent);
        return m_vParameters.count();
    }


    int CParametersModel::columnCount(const QModelIndex& parent /*= QModelIndex()*/) const
    {
        return m_vParameters.isEmpty() ? 0 : Count;
    }


    QVariant CParametersModel::data(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
    {
        if (!index.isValid())
            return {};

        const CParameter* param = getParameter(index.row());
        int col = index.column();

        if (role == Qt::DisplayRole)
            return displayData(param, col);
        else if (role == Qt::TextAlignmentRole)
            return Qt::AlignCenter;
        else if (role == Qt::ToolTipRole)
            return toolTipData(param, col);

        return {};
    }


    QVariant CParametersModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
    {
        if (role == Qt::DisplayRole)
        {
            switch (section)
            {
            case Name:
                return tr("Название");

            case Optional:
                return tr("Обязателен?");

            case Value:
                return tr("Значение");

            default: break;
            }
        }
        
        return QAbstractTableModel::headerData(section, orientation, role);
    }


    QString CParametersModel::displayData(const CParameter* Parameter_, int Column_) const
    {
        if (!Parameter_)
            return {};

        switch (Column_)
        {
        case Name:
            return Parameter_->GetName();

        case Optional:
            return Parameter_->IsRequired() ? "+" : "-";

        case Value:
        {
            QVariant varValue = Parameter_->GetValue();
            if (varValue.canConvert<QString>())
            {
                varValue.convert(qMetaTypeId<QString>());
                return varValue.toString();
            }

            return tr("Нет визуализатора");
        }

        default:
            break;
        }

        return {};
    }


    QString CParametersModel::toolTipData(const CParameter* Parameter_, int Column_) const
    {
        if (!Parameter_)
            return {};

        switch (Column_)
        {
        case Name:
            return Parameter_->GetDescription();

        case Value:
            return Parameter_->GetType();

        default: break;
        }

        return {};
    }


    const CParameter* CParametersModel::getParameter(int Num_) const
    {
        return Num_ >= 0 && Num_ < m_vParameters.count() ? &m_vParameters.at(Num_) : nullptr;
    }


    CParameter* CParametersModel::getParameter(int Num_)
    {
        return Num_ >= 0 && Num_ < m_vParameters.count() ? &m_vParameters[Num_] : nullptr;
    }

}
// Кириллица.
