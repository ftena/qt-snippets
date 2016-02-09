#include <QDebug>
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);

	QTranslator qtTranslator;
	if (qtTranslator.load(QLocale::system(),
				"qt", "_",
				QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	{
		qDebug() << "qtTranslator ok";
		app.installTranslator(&qtTranslator);
	}

	QTranslator qtBaseTranslator;
	if (qtBaseTranslator.load("qtbase_" + QLocale::system().name(),
				QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	{
		qDebug() << "qtBaseTranslator ok";
		app.installTranslator(&qtBaseTranslator);
	}

	QTranslator translator;
	translator.load("myapp_es", ":/");
	app.installTranslator(&translator);

	QMessageBox::question(0, QObject::tr("Sure want to quit?"),
				QObject::tr("Sure?"),
				QMessageBox::Yes | QMessageBox::No);

	return app.exec();
}
