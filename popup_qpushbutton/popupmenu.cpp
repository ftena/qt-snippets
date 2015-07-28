#include <QPushButton>
#include <QDebug>
#include "popupmenu.h"

PopupMenu::PopupMenu(QPushButton* button, QWidget* parent) : QMenu(parent), b(button)
{
}

void PopupMenu::showEvent(QShowEvent* event)
{
    Q_UNUSED(event);
    QPoint p = this->pos();
    QRect geo = b->geometry();
    this->move(p.x()+geo.width()-this->geometry().width(), p.y());

    qDebug() << "position in PopupMenu::showEvent --- x: " <<  this->pos().x() << " y: " << this->pos().y();
}
