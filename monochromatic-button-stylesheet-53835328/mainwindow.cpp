#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout;
    QPushButton *pushButton = new QPushButton("PushButton");

    pushButton->setStyleSheet(
                            "QPushButton {"
                            " background-color: white;"
                            " border: 1px solid black;"
                            " color: black;"
                            " outline: none;"
                            "}"
                            "QPushButton:pressed {"
                            " background-color: black;"
                            " border: 1px solid white;"
                            " color: white;"
                            "}"
                    );

    layout->addWidget(pushButton);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
