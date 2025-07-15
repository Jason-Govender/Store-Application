#ifndef ITEM_H
#define ITEM_H
#include <QString>
class Item
{
public:
    enum class ItemType {Book, Magazine}; //Can extend to different types when necessary
    Item(const QString& name, ItemType type);
    QString getName()const;
    ItemType getType()const; //Used for input safety if the software is extended to include custom item types.
    QString convertToString()const;//Converts the item type to a string for UI display.

private:
    QString m_name;
    ItemType m_type;

};

#endif // ITEM_H
