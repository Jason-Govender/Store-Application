#ifndef BROADCAST_H
#define BROADCAST_H
#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QString>

/*Broadcasts a UDP package containing an XML of the
  current transaction history.*/
class Broadcast : public QObject
{
    Q_OBJECT

public:
    explicit Broadcast(QObject* parent = nullptr);
    void broadcast(const QString& xml);

private:
    QUdpSocket* m_socket;
    quint16 m_port = 50000;
};

#endif
