#include <QApplication>
#include "graphicstextitem_1.h"
#include "graphicstextitem_2.h"
#include "graphicstextitem_3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "g1...";
    GraphicsTextItem_1 g1;
    g1.show();

    qDebug() << "g2...";
    GraphicsTextItem_2 g2;
    g2.show();

    qDebug() << "g3...";
    GraphicsTextItem_3 g3;
    g3.show();

    return a.exec();
}
