#include "spin_box_64.hpp"

#include "QLineEdit"
#include "QDebug"


namespace application
{
    CSpinBox64::CSpinBox64(QWidget* Parent_)
        : QAbstractSpinBox(Parent_)
    {
        connect(this, QOverload<quint64>::of(&CSpinBox64::valueChanged), this, &CSpinBox64::onValueChanged);
        //connect(this, &CSpinBox64::editingFinished, this, &CSpinBox64::onEditingFinished);
    }


    quint64 CSpinBox64::value() const
    {
        return m_value;
    }


    quint64 CSpinBox64::minimum() const
    {
        return m_minimum;
    }


    void CSpinBox64::setMinimum(quint64 Minimum_)
    {
        if (Minimum_ > m_maximum)
            setMaximum(Minimum_);

        m_minimum = Minimum_;

        if (m_value < m_minimum)
            setValue(m_minimum);
    }


    quint64 CSpinBox64::maximum() const
    {
        return m_maximum;
    }


    void CSpinBox64::setMaximum(quint64 Maximum_)
    {
        if (m_minimum > Maximum_)
            setMinimum(Maximum_);

        m_maximum = Maximum_;

        if (m_value > m_maximum)
            setValue(m_maximum);
    }


    QString CSpinBox64::cleanText() const
    {
        return m_valueText;
    }


    int CSpinBox64::displayIntegerBase() const
    {
        return m_integerBase;
    }


    void CSpinBox64::setDisplayIntegerBase(int Base_)
    {
        m_integerBase = std::max(0, Base_);
    }


    QString CSpinBox64::prefix() const
    {
        return m_prefix;
    }


    void CSpinBox64::setPrefix(const QString& Prefix_)
    {
        m_prefix = Prefix_;
    }


    QString CSpinBox64::suffix() const
    {
        return m_suffix;
    }


    void CSpinBox64::setSuffix(const QString& Suffix_)
    {
        m_suffix = Suffix_;
    }


    quint64 CSpinBox64::singleStep() const
    {
        return m_singleStep;
    }


    void CSpinBox64::setSingleStep(quint64 Step_)
    {
        m_singleStep = Step_;
    }


    void CSpinBox64::setRange(quint64 Minimum_, quint64 Maximum_)
    {
        quint64 mi = std::min(Minimum_, Maximum_);
        quint64 ma = std::max(Minimum_, Maximum_);

        setMinimum(mi);
        setMaximum(ma);
    }


    void CSpinBox64::stepBy(int steps)
    {
        qulonglong val = 0;
        if (!textToValue(lineEdit()->text(), val))
            return;

        //lineEdit()->setText(valueToText(val + steps * m_singleStep));
        setValue(val + steps * m_singleStep);
    }


    void CSpinBox64::fixup(QString& input) const
    {
        qulonglong value = 0;
        textToValue(input, value);
        if (value < m_minimum)
            value = m_minimum;
        if (value > m_maximum)
            value = m_maximum;

        input.setNum(value, m_integerBase);
    }


    QValidator::State CSpinBox64::validate(QString& input, int& pos) const
    {
        if (input.isEmpty())
            return QValidator::Intermediate;

        qulonglong testValue = 0;
        if (!textToValue(input, testValue))
            return QValidator::Invalid;

        if (testValue > m_maximum)
            return QValidator::Invalid;

        if (testValue < m_minimum)
            return QValidator::Intermediate;

        // Incorrect, but designed for item editors...
        const_cast<CSpinBox64*>(this)->setValue(testValue);
        return QValidator::Acceptable;
    }


    void CSpinBox64::setValue(quint64 Value_)
    {
        m_value = std::max(Value_, m_minimum);
        m_value = std::min(m_value, m_maximum);

        Q_EMIT valueChanged(m_value);
    }


    QAbstractSpinBox::StepEnabled CSpinBox64::stepEnabled() const
    {
        if (wrapping())
            return StepUpEnabled | StepDownEnabled;

        StepEnabled res = StepNone;
        if (m_value > m_minimum)
            res |= StepDownEnabled;

        if (m_value < m_maximum)
            res |= StepUpEnabled;

        return res;
    }


    void CSpinBox64::onValueChanged(quint64 Value_)
    {
        m_valueText = valueToText(Value_);
        lineEdit()->setText(m_valueText);
        Q_EMIT valueChanged(m_valueText);
    }


    void CSpinBox64::onEditingFinished()
    {
        qulonglong newVal = 0;
        if (!textToValue(lineEdit()->text(), newVal))
            return;

        setValue(newVal);
    }


    bool CSpinBox64::textToValue(const QString& Text_, qulonglong& Value_) const
    {
        bool bOk = false;
        Value_ = Text_.toULongLong(&bOk, m_integerBase);
        return bOk;
    }


    QString CSpinBox64::valueToText(qulonglong Value_) const
    {
        return QString("%1%2%3").arg(m_prefix).arg(Value_, 0, m_integerBase).arg(m_suffix);
    }

}
// Кириллица.
