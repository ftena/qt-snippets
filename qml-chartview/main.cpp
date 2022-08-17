#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    /*
     * As Qt Charts utilizes Qt Graphics View Framework for drawing,
     * QApplication must be used. The project created with the wizard
     * is usable with Qt Charts after the QGuiApplication is replaced
     *  with QApplication.
    */
    // More info @ https://doc.qt.io/qt-5/qtcharts-qmlmodule.html

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

