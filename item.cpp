#include "item.h"

Item::Item(const QString& name, ItemType type)
    :m_name(name), m_type(type)
{

}

QString Item::getName() const{
    return m_name;
}

Item::ItemType Item::getType() const{
    return m_type;
}

QString Item::convertToString() const{
    switch(m_type){
    case ItemType::Book:
        return "Book";
        break;
    case ItemType::Magazine:
        return "Magazine";
        break;
    //Can easily extend to more item types.
    }

}
