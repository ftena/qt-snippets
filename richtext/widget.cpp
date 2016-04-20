#include "widget.h"
#include "renderarea.h"
#include <QTextDocument>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    renderArea = new RenderArea;

    textDocument = new QTextDocument(this);
    textDocument->setDefaultStyleSheet(".firstcharacter {"
                                       "float: left;"
                                       "color: #903;"
                                       "font-size: 75px;"
                                       "font-family: Georgia; }");

    textEdit  = new QTextEdit;
    textEdit->setDocument(textDocument);

    textEdit->setHtml("<p>"
                      "<table class=\"firstcharacter\"><tr><td>L</td></tr></table>"
                      "ipsum dolor sit amet, consectetur adipiscing elit. Mauris "
                      "tristique lobortis orci ac lacinia. Fusce eu purus eget "
                      "diam vehicula auctor nec eu elit. Morbi consequat facilisis "
                      "orci vel malesuada. Donec ultrices molestie sollicitudin. "
                      "Aliquam pharetra libero enim. Donec et suscipit massa. "
                      "Donec dui odio, dignissim non sodales et, tincidunt a sapien. "
                      "Phasellus elit nibh, adipiscing sed blandit vel, interdum et arcu."
                      "His ne illud legendos, debitis democritum no est. Ut vidit congue "
                      "molestiae per, ne mea oporteat deseruisse. Ius posse clita cu, ius "
                      "ut fugit debet debitis. No mel saperet feugait tibique, qui cu quas "
                      "delenit. An dictas commodo eleifend vis. Essent propriae duo ea."
                      "</p>");

    mainLayout->addWidget(renderArea);
    mainLayout->addWidget(textEdit);

    setLayout(mainLayout);
}

Widget::~Widget()
{

}
