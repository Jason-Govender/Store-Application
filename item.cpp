#include "item.h"

Item::Item(const QString& name, const QString& type)
    :m_name(name), m_type(type)
{}

Item::~Item(){

}

Item::Item(const Item& i)
    :m_name(i.m_name), m_type(i.m_type)
{}
QString Item::getName() const{
    return m_name;
}

QString Item::getType() const{
    return m_type;
}


