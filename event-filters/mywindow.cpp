#include "mywindow.h"
#include <QPixmap>
#include <QEvent>
#include <QMouseEvent>

MyWindow::MyWindow()
{
    imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap(":icon"));
    imageLabel->resize(imageLabel->pixmap()->size());
    qDebug() << imageLabel->pixmap()->size();

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
        if(mouseEvent->x() >= 0 && mouseEvent->x() <=30 &&
           mouseEvent->y() >= 0 && mouseEvent->y() <= 30)
        {
            qDebug() << "drawFrame()";
        } else {
            qDebug() << "!drawFrame()";
        }
        return false;
    }

    return false;
}

