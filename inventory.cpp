#include "inventory.h"

Inventory::Inventory()
{}
Inventory::Inventory(QList <Item*> items, QList <Customer*> customers)
    :m_items(items), m_customers(customers)
{}

Inventory::~Inventory(){
    for(Item* item : m_items){
        delete item;
    }
    for(Customer* c : m_customers){
        delete c;
    }
    for(Transaction* t : m_transactions){
        delete t;
    }
}

QList<Customer*> Inventory::getCustomers(){
    return m_customers;
}

QList<Item*> Inventory::getItems(){
    return m_items;
}

QList<Item*> Inventory::getBackup(){
    return m_backup;
}

QList<Transaction*> Inventory::getTransactions(){
    return m_transactions;
}

void Inventory::addTransaction(Transaction* t) {
    m_transactions.append(t);
}

void Inventory::addItem(Item* item){
    m_items.append(item);
}

bool Inventory::processTransaction(QDialog* w, const Transaction& transaction){
    int inStock = 0;

    //Increase the counter for every item currently in stock
    for (Item* item : m_items){
        if(item == transaction.getItem())
        ++inStock;
    }

    //If there are more items requested than are in stock.
    if (inStock < transaction.getQuantity()) {
        QMessageBox::warning(w, "Error", "Insufficient Stock");
        return false;
    }

    //If there is enough stock, remove those items from the stock list.
    if(inStock>=transaction.getQuantity()){
        for (int i=m_items.size() - 1; i>=0 && inStock>0; --i){
            if (m_items[i] == transaction.getItem()){
                delete m_items[i];
                m_items.removeAt(i);
                --inStock;
            }
        }
    }


    return true;

}

void Inventory::restoreItems(){
    for (Item* item : m_items)
        delete item;

    m_items.clear();

    for (Item* b : m_backup)
        m_items.append(new Item(*b));
}
