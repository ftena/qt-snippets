#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDebug>
#include <QObject>
#include <QTcpServer>

class MyTcpServer : public QObject {
  Q_OBJECT

public:
  explicit MyTcpServer(QObject *parent = 0);

  void doConnect();

public slots:
  void netConnection();

private:
  QTcpServer *server;
};

#endif // TCPSERVER_H
