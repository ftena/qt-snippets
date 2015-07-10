#include <iostream>
#include <string>
#include <QtWidgets>
#include <QDoubleSpinBox>
#include "testwidgets.h"
 
void TestWidgets::getDoubleValue_data()
{
	QTest::addColumn<double>("values");

	QTest::newRow("value 1") << (double)0;
	QTest::newRow("value 2") << (double)500.0;
	QTest::newRow("value 3") << (double)999.9;
}

void TestWidgets::getDoubleValue()
{
	QFETCH(double, values);

	int decimals = 2; // characters for the fractional part
	double minrange = 0;
	double maxrange = 999.9;

	QDoubleSpinBox sb;
	sb.setRange(minrange, maxrange);
	sb.setDecimals(decimals);
	sb.setValue(values);

	/*
	** Uncomment the next two lines to show the QDoubleSpinBox
	*/ 
	sb.show();
	QTest::qWait(1000);

	double value = sb.value();
	
	QCOMPARE(value, values);
}

/*
** The first list of events stores the value 0 and key return, the second
** event stores the value 500.0 and the key return and the last one
** the value 900.0 and the key return.
*/
 
void TestWidgets::testSignal_data()
{
	QTest::addColumn<QTestEventList>("events");
	QTest::addColumn<double>("values");

	int ms = 100;

	QTestEventList list1;
	list1.addKeyClick(Qt::Key_Delete);
	list1.addKeyClick(Qt::Key_Delete);
	list1.addKeyClick(Qt::Key_Delete);
	list1.addKeyClick(Qt::Key_Delete);
	list1.addKeyClick('0', Qt::NoModifier, ms);
	list1.addKeyClick(Qt::Key_Return);
	/*
	 ** Note: QTest::newRow returns a QTestData reference that can be used
	 ** to stream in data.
	 */
	QTest::newRow("Typing 0") << list1
				<< (double)0;

	QTestEventList list2;
	/*
	 ** We use addKeyClicks instead of addKeyClick, but the result
	 ** is the same.
	*/
	list2.addKeyClick(Qt::Key_Delete);
	list2.addKeyClick(Qt::Key_Delete);
	list2.addKeyClick(Qt::Key_Delete);
	list2.addKeyClick(Qt::Key_Delete);
	list2.addKeyClicks("499.9", Qt::NoModifier, ms);
	list2.addKeyClick(Qt::Key_Return);
	QTest::newRow("Typing 499.9") << list2
				<< (double)499.9;

	QTestEventList list3;
	list3.addKeyClick(Qt::Key_Delete);
	list3.addKeyClick(Qt::Key_Delete);
	list3.addKeyClick(Qt::Key_Delete);
	list3.addKeyClick(Qt::Key_Delete);
	list3.addKeyClick('9', Qt::NoModifier, ms);
	list3.addKeyClick('9', Qt::NoModifier, ms);
	list3.addKeyClick('9', Qt::NoModifier, ms);
	list3.addKeyClick('.', Qt::NoModifier, ms);
	list3.addKeyClick('9', Qt::NoModifier, ms);
	list3.addKeyClick(Qt::Key_Return);
	QTest::newRow("Typing 999.9") << list3
				<< (double)999.9;

}

void TestWidgets::testSignal()
{
	QFETCH(QTestEventList, events);
	QFETCH(double, values);

	int decimals = 2; // characters for the fractional part
	double minrange = 0;
	double maxrange = 500.0;

	QDoubleSpinBox sb;
	QSignalSpy spy(&sb,SIGNAL(valueChanged(double)));
	
	sb.show();
	sb.cleanText();
	sb.setRange(minrange, maxrange);	
	sb.setDecimals(decimals);

	QTest::qWait(1000);

	events.simulate(&sb);

	if (values <= maxrange) {
		QCOMPARE(spy.count(), QString::number(values).size()); 
		
	} else {
		QCOMPARE(spy.count(), QString::number(sb.value()).size()); 
	}
}

QTEST_MAIN(TestWidgets)
