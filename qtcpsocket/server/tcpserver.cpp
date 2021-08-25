#include "tcpserver.h"

#include <QTcpSocket>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) {}

void MyTcpServer::doConnect() {
  server = new QTcpServer(this);

  // This signal is emitted every time a new connection is available.
  connect(server, SIGNAL(newConnection()), this, SLOT(netConnection()));

  if (!server->listen(QHostAddress("192.168.1.112"), 65001)) {
    qDebug() << "Server could not start";
  } else {
    qDebug() << "Server started!";
  }
}

void MyTcpServer::netConnection() {
  // need to grab the socket
  QTcpSocket *socket = server->nextPendingConnection();

  socket->write("Hello client\r\n");
  socket->flush();

  socket->waitForBytesWritten(3000);

  socket->close();
}
