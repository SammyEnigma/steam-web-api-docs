#pragma once
#include "QAbstractSpinBox"


namespace application
{
    /// Custom Spin Box that operates on 64 bit length values.
    class CSpinBox64 : public QAbstractSpinBox
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CSpinBox64);
        Q_PROPERTY(quint64 value READ value WRITE setValue);
        Q_PROPERTY(quint64 minimum READ minimum WRITE setMinimum);
        Q_PROPERTY(quint64 maximum READ maximum WRITE setMaximum);
        Q_PROPERTY(QString cleanText READ cleanText);
        Q_PROPERTY(int displayIntegerBase READ displayIntegerBase WRITE setDisplayIntegerBase);
        Q_PROPERTY(QString prefix READ prefix WRITE setPrefix);
        Q_PROPERTY(QString suffix READ suffix WRITE setSuffix);
        Q_PROPERTY(quint64 singleStep READ singleStep WRITE setSingleStep);

    public:
        CSpinBox64(QWidget* Parent_);
        virtual ~CSpinBox64() = default;

    public:
        quint64 value() const;

        quint64 minimum() const;
        void setMinimum(quint64 Minimum_);

        quint64 maximum() const;
        void setMaximum(quint64 Maximum_);

        QString cleanText() const;

        int displayIntegerBase() const;
        void setDisplayIntegerBase(int Base_);

        QString prefix() const;
        void setPrefix(const QString& Prefix_);

        QString suffix() const;
        void setSuffix(const QString& Suffix_);

        quint64 singleStep() const;
        void setSingleStep(quint64 Step_);

        void setRange(quint64 Minimum_, quint64 Maximum_);

    public:
        void stepBy(int steps) override final;
        void fixup(QString& input) const override final;
        QValidator::State validate(QString& input, int& pos) const override final;

    public Q_SLOTS:
        void setValue(quint64 Value_);

    Q_SIGNALS:
        void valueChanged(quint64 Value_);
        void valueChanged(const QString& NewValue_);

    protected:
        StepEnabled stepEnabled() const override final;

    private:
        void onValueChanged(quint64 Value_);
        void onEditingFinished();
        bool textToValue(const QString& Text_, qulonglong& Value_) const;
        QString valueToText(qulonglong Value_) const;

    //    void
    //    setRange(int minimum, int maximum)


    private:
        QString m_valueText = "0";
        QString m_prefix;
        QString m_suffix;
        quint64 m_value = 0;
        quint64 m_minimum = std::numeric_limits<quint64>::min();
        quint64 m_maximum = std::numeric_limits<quint64>::max();;
        quint64 m_singleStep = 1;
        int m_integerBase = 10;
    };
}
// Кириллица.

