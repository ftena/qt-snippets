#include <QtXml>
#include <QtCore>
#include <vector>
#include <iostream>

int main()
{
    QFile file(":/myxml.xml");

    file.open(QFile::ReadOnly|QFile::Text);

    QDomDocument dom;
    QString error;

    int line, column;

    if(!dom.setContent(&file, &error, &line, &column)) {
        qDebug() << "Error:" << error << "in line " << line << "column" << column;
        return -1;
    }

    QDomNodeList nodes = dom.elementsByTagName("Size");
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            qDebug() << elm.toElement().tagName()
                     << " = "
                     <<  elm.toElement().text();
        }
    }

    nodes = dom.elementsByTagName("SizeMod");
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            qDebug() << elm.toElement().tagName()
                     << " = "
                     << elm.toElement().text();
        }
    }

    return 0;
}

