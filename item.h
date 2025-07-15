#ifndef ITEM_H
#define ITEM_H
#include <QString>
class Item
{
public:
    Item(const QString& name, const QString& type);
    QString getName()const;
    QString getType()const;
private:
    QString m_name;
    QString m_type;
};

#endif // ITEM_H
