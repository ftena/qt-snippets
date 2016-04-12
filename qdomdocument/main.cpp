#include <QtXml>
#include <QtCore>

int main()
{
    QFile file(":/myxml_error.xml");

    qDebug() << "File path:" << QFileInfo(file).absoluteFilePath();
    qDebug() << "File exists:" << file.exists();

    file.open(QFile::ReadOnly|QFile::Text);

    qDebug() << "File open:" << file.isOpen();

    QDomDocument dom;
    QString error;

    int line, column;

    if(dom.setContent(&file, &error, &line, &column)){
        qDebug() << dom.toString(4);
    } else {
        qDebug() << "Error:" << error << "in line " << line << "column" << column;
    }
    return 0;
}

