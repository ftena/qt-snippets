#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");

    //Horizontal layout with two buttons
    QHBoxLayout *hblayout = new QHBoxLayout;
    hblayout->addWidget(button1);
    hblayout->addWidget(button2);

    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");

    //Vertical layout with two buttons
    QVBoxLayout *vblayout = new QVBoxLayout;
    vblayout->addWidget(button3);
    vblayout->addWidget(button4);

    //We add our two layouts (horizontal & vertical) to the
    //following vertical layout.
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(hblayout);
    mainLayout->addLayout(vblayout);

    this->setLayout(mainLayout);
}

Widget::~Widget()
{

}
