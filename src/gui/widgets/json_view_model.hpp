#pragma once
#include "QAbstractItemModel"
#include "QJsonDocument"


namespace application
{
    /// Data model for QJsonObject.
    class CJsonViewModel final : public QAbstractItemModel
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CJsonViewModel);

    public:
        CJsonViewModel(QObject* Parent_);
        ~CJsonViewModel();

        void FromDocument(const QJsonDocument& Data_);
        void ToDocument(QJsonDocument& Document_) const;

    public:
        QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override final;
        QModelIndex parent(const QModelIndex& Index_) const override final;
        int rowCount(const QModelIndex& parent = QModelIndex()) const override final;
        int columnCount(const QModelIndex& parent = QModelIndex()) const override final;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override final;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override final;
        Qt::ItemFlags flags(const QModelIndex &index) const override final;
        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override final;

    private:
        QJsonDocument m_Data;
        bool m_bRootIsObject = false;
    };
}
// Кириллица.

