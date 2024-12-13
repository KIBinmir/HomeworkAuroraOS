#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent)
{
    m_value = 0;
}
void Counter::setValue(int value)
{
    m_value = value;
    emit valueChanged(value);
}
void Counter::clear() {
    setValue(0);
}
void Counter::increase() {
     setValue(++m_value);
}
