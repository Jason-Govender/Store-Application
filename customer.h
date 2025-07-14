#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

class Customer
{
public:
    Customer(const QString& name);
    QString getName() const;

private:
    QString m_name;
};

#endif // CUSTOMER_H
