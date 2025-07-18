#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "customer.h"
#include "item.h"
#include <QDateTime>
class Transaction
{
public:
    Transaction(Customer* customer, Item* item, const QDateTime& dateTime, int quantity);
    Transaction();
    Customer* getCustomer()const;
    Item* getItem()const;
    QDateTime getdateTime()const;
    int getQuantity()const;
    void setQuantity(int quantity);
    void setCustomer(Customer* customer);
    void setItem(Item* item);
    void setDateTime(const QDateTime& datetime);

private:
    Customer* m_customer;
    Item* m_item;
    QDateTime m_dateTime;
    int m_quantity;
};

#endif // TRANSACTION_H
