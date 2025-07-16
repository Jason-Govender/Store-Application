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
    QList<Item*> getItems();
    QList<Item*> getBackup();
    void addItem(Item* item);
    void processTransaction(const Transaction& transaction);

private:
    QList<Item*> m_items;
    QList<Customer*> m_customers{
        new Customer("Jane"),
        new Customer("John"),
    };
    QList<Item*> m_backup;
};

#endif // INVENTORY_H
