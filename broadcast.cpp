#include "broadcast.h"

Broadcast::Broadcast(QObject* parent)
    : QObject(parent)
{
    m_socket = new QUdpSocket(this);
}

void Broadcast::broadcast(const QString& xml)
{
    QByteArray data = xml.toUtf8();
    m_socket->writeDatagram(data, QHostAddress::Broadcast, m_port);
}

