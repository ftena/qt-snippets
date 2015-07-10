#include <QtTest/QtTest>

/*
** Replaying GUI Events and testing a widget using
** QSignalSpy to test signals.
*/

class TestWidgets: public QObject
{
    Q_OBJECT

private slots:
    void getDoubleValue_data();
    void getDoubleValue();
    void testSignal_data();
    void testSignal();
};

