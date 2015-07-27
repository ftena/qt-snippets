#include <QDebug>
#include <QKeyEvent>
#include "myframe.h"

MyFrame::MyFrame()
{
   this->installEventFilter(this);
}

bool MyFrame::eventFilter(QObject *object, QEvent *event)
{
    if (object == this && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_W) {
            return true;
        } else {
            return false;
	}
    }
    return false;
}

void MyFrame::keyPressEvent(QKeyEvent *event)
{
    qDebug("At least came here");
    QString text = event->text();
    qDebug() << text;
}

