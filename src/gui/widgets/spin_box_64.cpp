#include "spin_box_64.hpp"


namespace application
{
    CSpinBox64::CSpinBox64(QWidget* Parent_)
        : QAbstractSpinBox(Parent_)
    {
        connect(this, QOverload<qint64>::of(&CSpinBox64::valueChanged), this, &CSpinBox64::onValueChanged);
    }


    qint64 CSpinBox64::value() const
    {
        return m_value;
    }


    qint64 CSpinBox64::minimum() const
    {
        return m_minimum;
    }


    void CSpinBox64::setMinimum(qint64 Minimum_)
    {
        if (Minimum_ > m_maximum)
            setMaximum(Minimum_);

        m_minimum = Minimum_;

        if (m_value < m_minimum)
            setValue(m_minimum);
    }


    qint64 CSpinBox64::maximum() const
    {
        return m_maximum;
    }


    void CSpinBox64::setMaximum(qint64 Maximum_)
    {
        if (m_minimum > Maximum_)
            setMinimum(Maximum_);

        m_maximum = Maximum_;

        if (m_value > m_maximum)
            setValue(m_maximum);
    }


    void CSpinBox64::setValue(qint64 Value_)
    {
        m_value = std::max(Value_, m_minimum);
        m_value = std::min(m_value, m_maximum);
        Q_EMIT valueChanged(m_value);
    }


    void CSpinBox64::onValueChanged(qint64 Value_)
    {
        Q_EMIT valueChanged(QString().setNum(Value_));
    }

}
// Кириллица.
