#include "transaction.h"

Transaction::Transaction(Customer* customer, Item* item, const QDateTime& dateTime, int quantity)
    :m_customer(customer), m_item(item), m_dateTime(dateTime), m_quantity(quantity)
{}

Customer* Transaction::getCustomer()const{
    return m_customer;
}

Item* Transaction::getItem()const{
    return m_item;
}

QDateTime Transaction::getdateTime()const{
    return m_dateTime;
}

int Transaction::getQuantity()const{
    return m_quantity;
}

void Transaction::setQuantity(int quantity){
    m_quantity = quantity;
}

void Transaction::setCustomer(const QString& customer){
    m_customer->getName() = customer;
}

void Transaction::setItem(const QString& item){
    m_item->getName() = item;
}

void Transaction::setDateTime(const QDateTime& dateTime){
    m_dateTime = dateTime;
}
