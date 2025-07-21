#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

/* Defines the details of a given customer.
 * Note: This could have been done in inventory.h
 * but having a separate customer class allows
 * for more customer attributes like age, gender, etc
 * to be implemented in the future.
*/
class Customer
{
public:
    Customer(const QString& name);
    ~Customer();
    QString getName() const;

private:
    QString m_name;
};

#endif // CUSTOMER_H
