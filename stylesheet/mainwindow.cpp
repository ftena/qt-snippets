#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    ui.setupUi(this);

    loadStyleSheet("cool");

    connect(ui.comboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(loadStyleSheet(const QString &)));
}

void MainWindow::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/qss/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());

    qApp->setStyleSheet(styleSheet);
}
