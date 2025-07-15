#include "item.h"

Item::Item(const QString& name, const QString& type)
    :m_name(name), m_type(type)
{

}

QString Item::getName() const{
    return m_name;
}

QString Item::getType() const{
    return m_type;
}
