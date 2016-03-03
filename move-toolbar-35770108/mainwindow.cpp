#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    toolBar= new QToolBar("Tool Bar");

    toolBar->addAction(QIcon(":/qt.png"), "FirstAction", this, SLOT(moveLeft()));
    toolBar->addAction(QIcon(":/qt.png"), "SecondAction", this, SLOT(moveRight()));

    addToolBar(Qt::RightToolBarArea, toolBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveLeft()
{
    addToolBar(Qt::LeftToolBarArea, toolBar);
}

void MainWindow::moveRight()
{
    addToolBar(Qt::RightToolBarArea, toolBar);
}
