#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QMainWindow>
#include <QTabBar>
#include <QDebug>

class MainWindow: public QMainWindow {
    Q_OBJECT
    QTabBar *tabBar;

public:
    MainWindow();
    ~MainWindow();

private slots:
    void onCurrentChanged(int index);
};

#endif

