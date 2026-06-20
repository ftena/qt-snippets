#include "receiver.h"

Receiver::Receiver(QWidget *parent)
    : QDialog(parent),
      groupAddress4(QStringLiteral("239.255.43.21"))
{
    udpSocket4.bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    udpSocket4.joinMulticastGroup(groupAddress4);

    QString msg = tr("Ready to read multicast datagrams from group %1 on port 45454").arg(groupAddress4.toString());
    statusLabel = new QLabel(msg);

    startButton = new QPushButton(tr("&Start"));
    auto quitButton = new QPushButton(tr("&Quit"));

    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(startButton, &QPushButton::clicked, this, &Receiver::startReceiving);
    connect(quitButton, &QPushButton::clicked, this, &Receiver::close);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Multicast Receiver"));
}

void Receiver::startReceiving()
{
    startButton->setEnabled(false);

    statusLabel->setText(tr("Super ready to read datagrams"));

    connect(&udpSocket4, &QUdpSocket::readyRead,
            this, &Receiver::readDatagrams);
}

void Receiver::readDatagrams()
{
    while (udpSocket4.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udpSocket4.receiveDatagram();

        //QByteArray receivedDatagram;
        //receivedDatagram.resize(int(datagram.data().size()));

        Data data;
        std::memcpy(&data, datagram.data().constData(), sizeof(Data));

        statusLabel->setText(tr("Reading datagram with size %1 and data: %2, %3, %4").arg(datagram.data().size()).arg(data.id).arg(data.type).arg(data.value));
    }
}
