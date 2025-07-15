#include "inventory.h"

Inventory::Inventory(QList <Item*> items)
    :m_items(items)
{}

void Inventory::addItem(Item* item){
    m_items.append(item);
}

void Inventory::processTransaction(const Transaction& transaction){

}
