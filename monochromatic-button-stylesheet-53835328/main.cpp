#include <QtWidgets>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(stylesheet);

    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
