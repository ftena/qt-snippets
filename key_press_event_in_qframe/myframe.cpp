#include <QDebug>
#include <QKeyEvent>
#include "myframe.h"

MyFrame::MyFrame()
{
}

void MyFrame::keyPressEvent(QKeyEvent *event)
{
    qDebug("At least came here");
    QString text = event->text();
    qDebug() << text;
}

