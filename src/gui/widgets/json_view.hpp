#pragma once
#include "QTreeView"


namespace application { class CJsonViewModel; }

namespace application
{
    /// View for QJsonDocument.
    class CJsonView : public QTreeView
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CJsonView);

    public:
        CJsonView(QWidget* Parent_);
        ~CJsonView();

        CJsonViewModel* jsonModel() const;

    public:
        void setModel(QAbstractItemModel* Model_) override final;
    };
}
// Кириллица.

