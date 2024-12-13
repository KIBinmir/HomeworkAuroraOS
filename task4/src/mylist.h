#ifndef MYLIST_H
#define MYLIST_H

#include <QObject>

class MyList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString listToString READ listToString  WRITE setListToString  NOTIFY listToStringChanged)
public:
    explicit MyList(QObject *parent = nullptr);
    Q_INVOKABLE QList<QString> list() const { return _list; }
    Q_INVOKABLE void addItem(QString item);
    Q_INVOKABLE QString popItem();
    Q_INVOKABLE QString listToString() const { return _listToString;}

private:
    QList<QString> _list;
    QString _listToString;

signals:
    void listChanged(QString item);
    void listToStringChanged(QString str);

public slots:
    Q_INVOKABLE QString getItems();
    void setListToString(QString str);
};

#endif // MYLIST_H
