#ifndef INVENTORY_H
#define INVENTORY_H
#include <QMessageBox>

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
    QList<Transaction*> getTransactions();
    void addTransaction(Transaction* t);
    void addItem(Item* item);
    bool processTransaction(QDialog* w, const Transaction& transaction);

private:
    QList<Item*> m_items;
    QList<Customer*> m_customers{
        new Customer("Jane"),
        new Customer("John"),
    };
    QList<Item*> m_backup;
    QList<Transaction*> m_transactions;
};

#endif // INVENTORY_H
