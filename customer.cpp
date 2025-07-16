#include "customer.h"

Customer::Customer(const QString& name)
    :m_name(name)
{}


QString Customer::getName() const{
    return m_name;
}
