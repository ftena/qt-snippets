#include <QtWidgets/QApplication>

#include "myframe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyFrame mf;
    mf.show();
    return a.exec();
}
