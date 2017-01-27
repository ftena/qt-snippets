#include <QApplication>
#include "myinputdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyInputDialog m;
    m.show();

    return a.exec();
}
