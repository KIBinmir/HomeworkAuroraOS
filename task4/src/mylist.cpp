#include "mylist.h"

MyList::MyList(QObject *parent) : QObject(parent)
{
    _list = {};
    _listToString="";
}
void MyList::setListToString(QString str)
{
    _listToString = str;
}
void MyList::addItem(QString item)
{
    _list.append(item);
    _listToString = getItems();
    emit listChanged(item);
    emit listToStringChanged(item);
}
QString MyList::popItem()
{
    if (_list.count() == 0)
        return "";
    QString item = _list.takeLast();
    _listToString = getItems();
    emit listChanged(item);
    emit listToStringChanged(item);
    return item;
}
QString MyList::getItems()
{
    int len = _list.count();
    if (len == 0) {
        return "";
    }
    QString res = _list[0];
    res[0] = res[0].toUpper();
    for(int i=1; i < len; i++)
    {
        res += ", ";
        res += _list[i];
    }
    _listToString = res;
    return res;
}
