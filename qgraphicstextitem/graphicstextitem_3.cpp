#include "graphicstextitem_3.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextBlock>
#include <QDebug>

GraphicsTextItem_3::GraphicsTextItem_3(QMainWindow *parent) : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);

    item = new QGraphicsTextItem("Block 0\n Block 1\n Block 2\n\n Block 4");
    item->setTextInteractionFlags(Qt::TextEditorInteraction);
    QFont f = item->font();
    f.setPointSize(30);
    item->setFont(f);

    QTextDocument* doc = item->document();

    for (QTextBlock it = doc->begin(); it != doc->end(); it = it.next())
    {
        QTextBlockFormat block_format = it.blockFormat();
        QTextCharFormat char_format = it.charFormat();

        qDebug() << "*** Block number: " << it.blockNumber()
                 << " with text: " << it.text();

        qDebug() << "* Block format info: "
                 << " leftMargin: " << block_format.leftMargin()
                 << " rightMargin: " << block_format.rightMargin()
                 << " topMargin: " << block_format.topMargin()
                 << " bottomMargin: " << block_format.bottomMargin()
                 << " lineHeight: " << block_format.lineHeight();

        qDebug() << "* Char format info: "
                 << " pointSize: " << char_format.font().pointSize()
                 << " fontFamily: " << char_format.font().family();

        QTextBlock::iterator tb_it = it.begin();

        if (tb_it.atEnd())
        {
            qDebug() << "it.begin() == tb_it.atEnd()";
            /* The application crashes if we get the fragment */
            // tb_it.fragment();
        }

        for (tb_it = it.begin(); !(tb_it.atEnd()); ++tb_it) {
            QTextFragment currentFragment = tb_it.fragment();

            if (currentFragment.isValid())
            {
                qDebug() << "I am a QTextBlock with text!"
                         << " Out of here empty QTextBlock!"
                         << " You - shall not - pass!";
            }
        }
    }

    scene->addItem(item);
    view->setFixedSize(640, 480);

    this->setCentralWidget(view);
}

