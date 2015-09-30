#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QFont>
#include <QDebug>
#include <QTextDocument>
#include <QTextBlock>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    QGraphicsView view(&scene);

    /* ITEM 1 */
    QGraphicsTextItem* item_1  = new QGraphicsTextItem("QGraphicsTextItem 1");
    item_1->setTextInteractionFlags(Qt::TextEditorInteraction);
    QFont f = item_1->font();
    f.setPointSize(30);
    item_1->setFont(f);

    qDebug() << "textCursor().position() (returns 0): " <<
                item_1->textCursor().position();
    qDebug() << "textCursor().charFormat().fontPointSize() (returns 0): " <<
                item_1->textCursor().charFormat().fontPointSize();
    qDebug() << "font().pointSize() (returns 30 - OK!): " <<
                item_1->font().pointSize();

    QTextDocument* doc = item_1->document();
    f = doc->defaultFont();
    qDebug() << "pointSize (returns 30 - OK!): " << f.pointSize();

    scene.addItem(item_1);

    /* ITEM 2 */
    QGraphicsTextItem* item_2  = new QGraphicsTextItem();
    item_2->setPos(0, 50);
    item_2->setHtml("<html><head/><body><p>"
                    "<span style=\"font-size:14pt; font-weight:600;\">QGraphics</span>"
                    "<span style=\"font-size:24pt; font-weight:600;\">TextItem 2</span>"
                    "</p></body></html>");

    qDebug() << "font().pointSize() (returns 8, the default value): "
             << item_2->font().pointSize();

    doc = item_2->document();
    f = doc->defaultFont();
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
    QTextBlock text_block = item_2->document()->findBlock(1);
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

    scene.addItem(item_2);

    view.setFixedSize(640, 480);
    view.show();
    return a.exec();
}
