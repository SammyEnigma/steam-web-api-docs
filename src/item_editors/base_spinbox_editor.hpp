#pragma once
#include "gui/widgets/spin_box_64.hpp"


namespace application
{
    /// Base class for spinbox-running item editor.
    template<class T>
    class CBaseSpinBoxEditor : public CSpinBox64
    {
        Q_DISABLE_COPY(CBaseSpinBoxEditor);

    public:
        CBaseSpinBoxEditor(QWidget* Parent_) 
            : CSpinBox64(Parent_)
        {
            setMinimum(std::numeric_limits<T>::min());
            setMaximum(std::numeric_limits<T>::max());
        };

        ~CBaseSpinBoxEditor() = default;
        
        /// Get value from editor.
        virtual T GetValue() const = 0;

        /// Set value for editor.
        virtual void SetValue(T Value_) = 0;
    };
}
// Кириллица.

