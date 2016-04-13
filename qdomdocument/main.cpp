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

    if(dom.setContent(&file, &error, &line, &column)) {
        qDebug() << "Content: " << dom.toString(4);
    } else {
        qDebug() << "Error:" << error << "in line " << line << "column" << column;
    }

    file.close();
    file.open(QFile::ReadOnly|QFile::Text);

    QTextStream in(&file);
    in.readAll();

    //This will fail because we have reached the end of file.
    if(dom.setContent(in.readAll(), &error, &line, &column)) {
        qDebug() << "Content: " << dom.toString(4);
    } else {        
        qDebug() << "Error:" << error << "in line " << line << "column" << column;
    }

    return 0;
}

