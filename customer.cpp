#include "customer.h"

Customer::Customer(const QString& name) {
    m_name = name;
}

QString getName() const{
    return m_name;
}
