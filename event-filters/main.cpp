#include "mywindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWindow myWindow;
    myWindow.show();
    return app.exec();
}
