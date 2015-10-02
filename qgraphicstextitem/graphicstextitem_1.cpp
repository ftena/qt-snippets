#include "graphicstextitem_1.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTextCursor>
#include <QTextDocument>
#include <QDebug>

GraphicsTextItem_1::GraphicsTextItem_1(QMainWindow *parent) : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);

    item = new QGraphicsTextItem("QGraphics Text Item 1");
    item->setTextInteractionFlags(Qt::TextEditorInteraction);
    QFont f = item->font();
    f.setPointSize(30);
    item->setFont(f);

    qDebug() << "textCursor().position() (returns 0): " <<
                item->textCursor().position();
    qDebug() << "textCursor().charFormat().fontPointSize() (returns 0): " <<
                item->textCursor().charFormat().fontPointSize();
    qDebug() << "font().pointSize() (returns 30 - OK!): " <<
                item->font().pointSize();

    QTextDocument* doc = item->document();

    f = doc->defaultFont();
    qDebug() << "pointSize (returns 30 - OK!): " << f.pointSize();

    QTextCursor cursor(doc);
    cursor.beginEditBlock();
    cursor.insertText(" Hello ");
    cursor.insertText(" World ");
    cursor.endEditBlock();
    cursor.movePosition(QTextCursor::NextWord);
    cursor.select(QTextCursor::WordUnderCursor);
    cursor.removeSelectedText();

    scene->addItem(item);
    view->setFixedSize(640, 480);

    this->setCentralWidget(view);
}



