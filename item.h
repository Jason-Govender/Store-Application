#ifndef ITEM_H
#define ITEM_H
#include <QString>

//Defines the name and type of an item.
class Item
{
public:
    //Can extend to different types when necessary.
    enum class ItemType {Book, Magazine};

    Item(const QString& name, const QString& type);

    //Copy Constructor for the backup list.
    Item(const Item& i);

    ~Item();
    QString getName()const;
    QString getType()const;

private:
    QString m_name;
    QString m_type;

};

#endif // ITEM_H
