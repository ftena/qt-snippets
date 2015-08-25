#include "mainwindow.h"

MainWindow::MainWindow()
{
    tabBar = new QTabBar();

    for (int i = 1; i < 10; ++i)
    {
         tabBar->addTab(QString("###") + QString::number(i) + QString("###"));
    }

    QObject::connect(tabBar, &QTabBar::currentChanged,
                     this, &MainWindow::onCurrentChanged);

    setCentralWidget(tabBar);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onCurrentChanged(int index)
{
    int currentIndex = tabBar->currentIndex();
    qDebug("currentChanged(%d), currentIndex() = %d", index, currentIndex);

    for (int i = index; i >= 0; --i)
    {
        tabBar->setTabText(i, QString::number(i+1));
    }
}
