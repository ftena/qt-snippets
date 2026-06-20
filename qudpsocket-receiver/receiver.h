#ifndef RECEIVER_H
#define RECEIVER_H

#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>

class Receiver : public QDialog
{
    Q_OBJECT

public:
    explicit Receiver(QWidget *parent = nullptr);

private slots:
    void startReceiving();
    void readDatagrams();

private:
    QLabel *statusLabel = nullptr;
    QPushButton *startButton = nullptr;
    QUdpSocket udpSocket4;
    QHostAddress groupAddress4;
    int messageNo = 1;
};

struct Data
{
    short id;
    short type;
    int value;
};

#endif
