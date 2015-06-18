#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    Ui::MainWindow ui;

private slots:
    void loadStyleSheet(const QString &sheetName);
};

#endif
