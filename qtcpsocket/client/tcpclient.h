#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>

class MyTcpClient : public QObject {
  Q_OBJECT
public:
  explicit MyTcpClient(QObject *parent = 0);

  void doConnect();

signals:

public slots:
  void connected();
  void disconnected();
  void bytesWritten(qint64 bytes);
  void readyRead();

private:
  QTcpSocket *socket;
};

#endif // TCPCLIENT_H
