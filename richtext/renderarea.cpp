#include "renderarea.h"
#include <QPainter>
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{

}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QTextDocument td;
    td.setDefaultStyleSheet("p {"
                            "margin-top: 0em;"
                            "margin-bottom: 0em;"
                            "}"
                            ".firstcharacter {"
                            "color: #903;"
                            "font-size: 75px;"
                            "font-family: Georgia; }");
    td.setHtml("<p>"
               "<span class=\"firstcharacter\">L</span> ipsum dolor sit amet, consectetur adipiscing elit."
               "</p>"
               "<p>"
               "Mauris tristique lobortis orci ac lacinia. Fusce eu purus eget..."
               "</p>");

    td.drawContents(&painter);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}
