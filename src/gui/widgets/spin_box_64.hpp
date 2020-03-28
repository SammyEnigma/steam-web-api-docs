#pragma once
#include "QAbstractSpinBox"


namespace application
{
    /// Custom Spin Box that operates on 64 bit length values.
    class CSpinBox64 : public QAbstractSpinBox
    {
        Q_OBJECT;
        Q_DISABLE_COPY(CSpinBox64);
        Q_PROPERTY(qint64 value READ value WRITE setValue);
        Q_PROPERTY(qint64 minimum READ minimum WRITE setMinimum);
        Q_PROPERTY(qint64 maximum READ maximum WRITE setMaximum);

    public:
        CSpinBox64(QWidget* Parent_);
        ~CSpinBox64() = default;

    public:
        qint64 value() const;

        qint64 minimum() const;
        void setMinimum(qint64 Minimum_);

        qint64 maximum() const;
        void setMaximum(qint64 Maximum_);

    public Q_SLOTS:
        void setValue(qint64 Value_);

    Q_SIGNALS:
        void valueChanged(qint64 Value_);
        void valueChanged(const QString& NewValue_);

    private:
        void onValueChanged(qint64 Value_);

    //cleanText: const QString
    //    displayIntegerBase : int
    //    prefix : QString
    //    singleStep : int
    //    stepType : StepType
    //    suffix : QString

    //    Public Functions


    //    QSpinBox(QWidget* parent = nullptr)
    //    virtual
    //    ~QSpinBox()
    //    QString
    //    cleanText() const
    //    int
    //    displayIntegerBase() const
    //    QString
    //    prefix() const
    //    void
    //    setDisplayIntegerBase(int base)
    //    void
    //    setPrefix(const QString& prefix)
    //    void
    //    setRange(int minimum, int maximum)
    //    void
    //    setSingleStep(int val)
    //    void
    //    setStepType(QAbstractSpinBox::StepType stepType)
    //    void
    //    setSuffix(const QString& suffix)
    //    int
    //    singleStep() const
    //    QAbstractSpinBox::StepType
    //    stepType() const
    //    QString
    //    suffix() const

    //    Public Slots

    //    void
    //    setValue(int val)

    private:
        qint64 m_value;
        qint64 m_minimum;
        qint64 m_maximum;
    };
}
// Кириллица.

