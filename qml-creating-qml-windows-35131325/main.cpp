#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Using a single QQmlApplicationEngine and loading two qml files
    QQmlApplicationEngine qmlappengine;
    qmlappengine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    qmlappengine.load(QUrl(QStringLiteral("qrc:/main2.qml")));

    //Using two QQuickView. Each one with its own qml source file
    QQuickView view;
    view.setSource(QUrl("qrc:/main3.qml"));
    view.show();

    QQuickView view2;
    view2.setSource(QUrl("qrc:/main4.qml"));
    view2.show();

    //Using a single QQmlEngine and creating two components
    QQmlEngine qmlengine;
    QQmlComponent component(&qmlengine);
    component.loadUrl(QUrl(QStringLiteral("qrc:/main5.qml")));

    if ( component.isReady() )
        component.create();
    else
        qWarning() << component.errorString();

    component.loadUrl(QUrl(QStringLiteral("qrc:/main6.qml")));

    if ( component.isReady() )
        component.create();
    else
        qWarning() << component.errorString();

    return app.exec();
}

