#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget q;
    q.show();
    q.play();

    return a.exec();
}
