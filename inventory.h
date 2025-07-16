#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"
class Inventory
{
public:
    Inventory(QList<Item*> items);
    ~Inventory();
    QList<Customer*> getCustomers();
    void addItem(Item* item);
    void processTransaction(const Transaction& transaction);

private:
    QList<Item*> m_items;
    QList<Customer*> m_customers;
};

#endif // INVENTORY_H
