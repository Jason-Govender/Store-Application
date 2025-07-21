#include "customer.h"

Customer::Customer(const QString& name)
    :m_name(name)
{}

Customer::~Customer(){}


QString Customer::getName() const{
    return m_name;
}
