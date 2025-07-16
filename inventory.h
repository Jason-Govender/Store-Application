#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"
class Inventory
{
public:
    Inventory();
    Inventory(QList<Item*> items, QList<Customer*> customers);
    ~Inventory();
    QList<Customer*> getCustomers();
    void addItem(Item* item);
    void processTransaction(const Transaction& transaction);

private:
    QList<Item*> m_items;
    QList<Customer*> m_customers{
        new Customer("Jane"),
        new Customer("John"),
    };
};

#endif // INVENTORY_H
