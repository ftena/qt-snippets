#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    ui.setupUi(this);

    loadStyleSheet("cool");

    connect(ui.comboBox, SIGNAL(currentTextChanged(QString)),
            this, SLOT(loadStyleSheet(QString)));
    /*
     * Install an event filter to set the style depending on
     * the kind of focus (QEvent::FocusIn or QEvent::FocusOut)
     */
    ui.plainTextEdit->installEventFilter(this);
}

void MainWindow::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/qss/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());

    qApp->setStyleSheet(styleSheet);
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui.plainTextEdit)
    {
        if (event->type() == QEvent::FocusOut)
        {
            ui.plainTextEdit->setStyleSheet("color: white; background-color: black;");
        } else if (event->type() == QEvent::FocusIn) {
            ui.plainTextEdit->setStyleSheet("color: red; background-color: white;");
        }
        return false;
    }    
    return false;
}
