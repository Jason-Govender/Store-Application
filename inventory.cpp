#include "inventory.h"

Inventory::Inventory(QList <Item*> items)
    :m_items(items)
{}

Inventory::~Inventory(){
    for(Item* item : m_items){
        delete item;
    }
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
    else
        qDebug() << "The item and/or quantity is not in stock.";
}
