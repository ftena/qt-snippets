#include <QtWidgets/QApplication>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog dia;
    return dia.exec();
}
