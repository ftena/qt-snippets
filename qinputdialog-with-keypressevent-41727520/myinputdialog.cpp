#include "myinputdialog.h"
#include <QKeyEvent>
#include <QDebug>

MyInputDialog::MyInputDialog(QWidget *parent) : QInputDialog(parent)
{
    setOptions(QInputDialog::UsePlainTextEditForTextInput);
}

void MyInputDialog::keyPressEvent(QKeyEvent *e)
{
    qDebug() << Q_FUNC_INFO;

    if ( e->key() == Qt::Key_S
         && e->modifiers() & Qt::ControlModifier )
    {
        qDebug() << Q_FUNC_INFO << "CTRL + S";
        done(1);
        e->accept();
        return;
    }

    e->ignore();
}
