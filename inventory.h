#ifndef INVENTORY_H
#define INVENTORY_H
#include <QMessageBox>
#include "transaction.h"

/* The main hub of interaction between all of our classes.
 * It is responsible for:
 * Generating a list of customers, transactions, and items.
 * Processing transactions to ensure that they are valid.
 * Generating a backup item list and restoring the current list-
 * if necessary.
*/
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


    void restoreItems();

    //Checks a transaction to see if the item requested is in stock.
    bool processTransaction(QDialog* w, const Transaction& transaction);

private:
    QList<Item*> m_items;

    /*Initializes our customer list.
     * This can be modified to allow customer names to
     * be input instead of using a predetermined list.
    */
    QList<Customer*> m_customers{
        new Customer("Jane"),
        new Customer("John"),
    };

    QList<Item*> m_backup;
    QList<Transaction*> m_transactions;
};

#endif // INVENTORY_H
