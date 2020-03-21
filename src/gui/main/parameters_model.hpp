#pragma once
#include "QAbstractTableModel"


namespace application { class CAPIMethod; }
namespace application { class CParameter; }

namespace application
{
    class CParametersModel : public QAbstractTableModel
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CParametersModel);

    public:
        CParametersModel(QObject* Parent_);
        ~CParametersModel() = default;

        enum Columns
        {
            Optional,
            Name,
            Value,

            Count
        };

        void SetMethod(const CAPIMethod* Method_);

    public:
        int rowCount(const QModelIndex& parent = QModelIndex()) const override final;
        int columnCount(const QModelIndex& parent = QModelIndex()) const override final;
        QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override final;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override final;

    private:
        QString displayData(const CParameter* Parameter_, int Column_) const;
        QString toolTipData(const CParameter* Parameter_, int Column_) const;
        const CParameter* getParameter(int Num_) const;
        CParameter* getParameter(int Num_);


    private:
        QVector<CParameter> m_vParameters;
    };
}
// Кириллица.

