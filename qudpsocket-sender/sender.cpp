// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "sender.h"

Sender::Sender(QWidget *parent)
    : QDialog(parent),
      groupAddress4(QStringLiteral("239.255.43.21"))
{
    // force binding to their respective families
    udpSocket4.bind(QHostAddress(QHostAddress::AnyIPv4), 0);

    QString msg = tr("Ready to multicast datagrams to group %1 on port 45454").arg(groupAddress4.toString());
    statusLabel = new QLabel(msg);

    startButton = new QPushButton(tr("&Start"));
    auto quitButton = new QPushButton(tr("&Quit"));

    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(startButton, &QPushButton::clicked, this, &Sender::startSending);
    connect(quitButton, &QPushButton::clicked, this, &Sender::close);
    connect(&timer, &QTimer::timeout, this, &Sender::sendDatagram);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Multicast Sender"));
}

void Sender::startSending()
{
    startButton->setEnabled(false);
    timer.start(1000);
}

void Sender::sendDatagram()
{
    Data data {QRandomGenerator::global()->bounded(7),
              QRandomGenerator::global()->bounded(11),
              messageNo};

    QByteArray datagram(reinterpret_cast<const char*>(&data), sizeof(Data));

    statusLabel->setText(tr("Now sending datagram %1, %2, %3, size: %4").arg(data.id).arg(data.type).arg(data.value).arg(datagram.size()));
    //QByteArray datagram = "Multicast message " + QByteArray::number(messageNo);
    udpSocket4.writeDatagram(datagram, groupAddress4, 45454);
    ++messageNo;
}
