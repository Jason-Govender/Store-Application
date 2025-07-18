#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "customer.h"
#include "item.h"
#include <QDateTime>
class Transaction
{
public:
    Transaction(Customer* customer, Item* item, const QDateTime& dateTime, int quantity);
    Customer* getCustomer()const;
    Item* getItem()const;
    QDateTime getdateTime()const;
    int getQuantity()const;
    void setQuantity(int quantity);
    void setCustomer(const QString& customer);
    void setItem(const QString& item);
    void setDateTime(const QDateTime& datetime);

    //We can include more setters to make the software customizable.
private:
    Customer* m_customer;
    Item* m_item;
    QDateTime m_dateTime;
    int m_quantity;
};

#endif // TRANSACTION_H
