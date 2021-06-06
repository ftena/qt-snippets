#include "tcpclient.h"

#include <QtNetwork>

MyTcpClient::MyTcpClient(QObject *parent) : QObject(parent) {}

void MyTcpClient::doConnect() {
  socket = new QTcpSocket(this);

  connect(socket, SIGNAL(connected()), this, SLOT(connected()));
  connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
  connect(socket, SIGNAL(bytesWritten(qint64)), this,
          SLOT(bytesWritten(qint64)));
  connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

  qDebug() << "connecting...";

  // this is not blocking call
  socket->connectToHost("192.168.1.112", 65001);

  // we need to wait...
  if (!socket->waitForConnected(5000)) {
    qDebug() << "Error: " << socket->errorString();
  }
}

void MyTcpClient::connected() {
  qDebug() << "connected...";

  // Hey server, tell me about you.
  socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void MyTcpClient::disconnected() { qDebug() << "disconnected..."; }

void MyTcpClient::bytesWritten(qint64 bytes) {
  qDebug() << bytes << " bytes written...";
}

void MyTcpClient::readyRead() {
  qDebug() << "reading...";

  // read the data from the socket
  qDebug() << socket->readAll();
}
