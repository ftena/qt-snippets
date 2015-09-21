#include <QApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQuickView *view = new QQuickView;
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    return app.exec();
}
