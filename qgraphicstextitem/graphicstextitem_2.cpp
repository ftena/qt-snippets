#include "graphicstextitem_2.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextFragment>
#include <QDebug>

GraphicsTextItem_2::GraphicsTextItem_2(QMainWindow *parent) : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);

    item = new QGraphicsTextItem();
    item->setPos(0, 50);
    item->setHtml("<html><head/><body><p>"
                    "<span style=\"font-size:14pt; font-weight:600;\">QGraphics</span>"
                    "<span style=\"font-size:24pt; font-weight:600;\">TextItem 2</span>"
                    "</p></body></html>");

    qDebug() << "font().pointSize() (returns 8, the default value): "
             << item->font().pointSize();

    QTextDocument* doc = item->document();
    doc = item->document();
    QFont f = doc->defaultFont();
    qDebug() << "pointSize (returns 8, the default value): " << f.pointSize();

    QVector<QTextFormat> formats = doc->allFormats();
    QVectorIterator<QTextFormat> i(formats);
    while (i.hasNext()) {
        QTextFormat format = i.next();
        if (format.property(QTextFormat::FontPointSize).isValid())
            qDebug() << "format.property (returns 14 or 24): " <<
                        format.property(QTextFormat::FontPointSize).toInt();
    }

    /*
     * Get the block of text. In this example, we only have one block, but
     * two text fragments (see below)
     */
    QTextBlock text_block = item->document()->findBlock(1);
    QTextBlock::iterator it;

    for (it = text_block.begin(); !(it.atEnd()); ++it) {
        QTextFragment currentFragment = it.fragment();
        if (currentFragment.isValid())
            qDebug() << "currentFragment.text(): " << currentFragment.text();
            qDebug() << "currentFragment.charFormat().font().pointSize() "
                        "(returns 14 or 24, depending on"
                        "the current text fragment): " <<
                        currentFragment.charFormat().font().pointSize();
    }

    scene->addItem(item);
    view->setFixedSize(640, 480);

    this->setCentralWidget(view);
}

