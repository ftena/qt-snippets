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
                      "<span class=\"firstcharacter\">L</span> ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique lobortis orci ac lacinia. Fusce eu purus eget diam vehicula auctor nec eu elit. Morbi consequat facilisis orci vel malesuada. Donec ultrices molestie sollicitudin. Aliquam pharetra libero enim. Donec et suscipit massa. Donec dui odio, dignissim non sodales et, tincidunt a sapien. Phasellus elit nibh, adipiscing sed blandit vel, interdum et arcu."
                      "</p>");

    mainLayout->addWidget(renderArea);
    mainLayout->addWidget(textEdit);

    setLayout(mainLayout);
}

Widget::~Widget()
{

}
