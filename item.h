#ifndef ITEM_H
#define ITEM_H
#include <QString>
class Item
{
public:
    enum class ItemType {Book, Magazine}; //Can extend to different types when necessary
    Item(const QString& name, const QString& type);
    Item(const Item& i);
    QString getName()const;
    QString getType()const;

private:
    QString m_name;
    QString m_type;

};

#endif // ITEM_H
