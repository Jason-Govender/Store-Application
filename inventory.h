#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"
class Inventory
{
public:
    Inventory(QList<Item*> items);
    void addItem(Item* item);
    void processTransaction(const Transaction& transaction);

private:
    QList<Item*> m_items;
};

#endif // INVENTORY_H
