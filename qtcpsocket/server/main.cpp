#include "tcpserver.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  MyTcpServer s;
  s.doConnect();

  return a.exec();
}
