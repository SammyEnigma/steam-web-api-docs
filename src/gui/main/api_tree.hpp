#pragma once
#include "QTreeView"


namespace application { class CAPIModel; }
namespace application { class CAPIInterface; }
namespace application { class CAPIMethod; }

namespace application
{
    /// Steam Web API Methods tree widget.
    class CAPITree : public QTreeView
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CAPITree);

    public:
        CAPITree(QWidget* Parent_);
        ~CAPITree() = default;
        
        CAPIModel& GetModel() const;

    Q_SIGNALS:
        void MethodSelected(const CAPIInterface* Interface_, const CAPIMethod* Method_);

    private Q_SLOTS:
        void onItemDoubleClicked(const QModelIndex& Index_);

    private:
        CAPIModel* m_ModelRef = nullptr;
    };
}
// Кириллица.

