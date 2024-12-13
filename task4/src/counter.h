#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY (int value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit Counter(QObject *parent = nullptr);
    Q_INVOKABLE int value() const { return m_value; }
    Q_INVOKABLE void clear();
    Q_INVOKABLE void increase();

private:
    int m_value;

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);
};

#endif // COUNTER_H
