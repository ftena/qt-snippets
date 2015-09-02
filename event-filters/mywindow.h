#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>

class MyWindow: public QWidget {
    Q_OBJECT    

public:
    MyWindow();
    ~MyWindow();
    bool eventFilter(QObject *object, QEvent *event);

private:
    QLabel *imageLabel;
};

#endif

