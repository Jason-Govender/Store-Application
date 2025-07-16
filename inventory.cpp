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

void Inventory::addItem(Item* item){
    m_items.append(item);
}

void Inventory::processTransaction(const Transaction& transaction){
    int inStock = 0;
    for (Item* item : m_items){
        if(item == transaction.getItem())
        ++inStock;
    }

    if(inStock>=transaction.getQuantity()){
        for (int i=m_items.size(); i>=0 && inStock>0; --i){
            if (m_items[i] == transaction.getItem()){
                delete m_items[i];
                m_items.removeAt(i);
                --inStock;
            }
        }
    }

}
