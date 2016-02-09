#include <QtWidgets/QApplication>
#include <QDebug>

#include "myframe.h"

class QApplicationFilter: public QObject
{
    public:
        QApplicationFilter(): QObject() {}
        ~QApplicationFilter() {}

        bool eventFilter(QObject* obj, QEvent* event)
        {
            qDebug() << "QApplicationFilter: "
                     << obj->objectName()
                     << " - event type: "
                     << event->type();
	    return QObject::eventFilter(obj, event);
        };
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.installEventFilter(new QApplicationFilter());

    MyFrame mf;
    mf.show();
    return a.exec();
}
