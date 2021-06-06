#include "tcpclient.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  MyTcpClient s;
  s.doConnect();

  return a.exec();
}
