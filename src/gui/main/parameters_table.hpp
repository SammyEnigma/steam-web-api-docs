#pragma once
#include "QTableView"


namespace application { class CParametersModel; }

namespace application
{
    /// Steam Web API method parameters table widget.
    class CParametersTable : public QTableView
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CParametersTable);

    public:
        CParametersTable(QWidget* Parent_);
        ~CParametersTable() = default;

        CParametersModel& GetModel() const;
        
    private Q_SLOTS:
        void onModelReset();

    private:
        CParametersModel* m_ModelRef = nullptr;
    };
}
// Кириллица.

