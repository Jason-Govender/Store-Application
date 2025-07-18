#include "transaction.h"

Transaction::Transaction(Customer* customer, Item* item, const QDateTime& dateTime, int quantity)
    :m_customer(customer), m_item(item), m_dateTime(dateTime), m_quantity(quantity)
{}

Transaction::Transaction()
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

void Transaction::setCustomer(Customer*customer){
    m_customer = customer;
}

void Transaction::setItem(Item* item){
    m_item = item;
}

void Transaction::setDateTime(const QDateTime& dateTime){
    m_dateTime = dateTime;
}
