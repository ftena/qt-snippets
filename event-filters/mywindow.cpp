#include "mywindow.h"
#include <QPixmap>
#include <QEvent>
#include <QMouseEvent>

MyWindow::MyWindow()
{
    imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap(":icon"));
    imageLabel->resize(imageLabel->pixmap().size());
    qDebug() << imageLabel->pixmap().size();

    imageLabel->setMouseTracking(true);
    imageLabel->installEventFilter(this);
}

MyWindow::~MyWindow()
{
}

bool MyWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == imageLabel && event->type() == QEvent::MouseMove) {
        /*
         * We know the image is 60x60 px.
         */
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->position().x() >= 0 && mouseEvent->position().x() <=30 &&
            mouseEvent->position().y() >= 0 && mouseEvent->position().y() <= 30)
        {
            qDebug() << " >=0 x <= 30 && >= y <= 30 ";
        } else {
            qDebug() << " a diffrent path ";
        }
        return false;
    }

    return false;
}

