#include <QMenu>
#include <QFile>
#include "dialog.h"

Dialog::Dialog()
{
    m_ui.setupUi(this);

    /* Instantiate the menu */
    QMenu* menu = new QMenu("menu", this);

    QAction *action = new QAction("action#1", this);
    menu->addAction(action);
    QAction *action2 = new QAction("action#2", this);
    menu->addAction(action2);
    QAction *action3 = new QAction("action#3", this);
    menu->addAction(action3);

    m_ui.pushButton->setMenu(menu);

    QFile file(":/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());

    /*
     * Two options to get round corners translucent
     */

    /* First option... */
    /*
        menu->setWindowFlags(menu->windowFlags() | Qt::FramelessWindowHint);
        menu->setAttribute(Qt::WA_TranslucentBackground);
    */

    /* Second option...
     * TODO: adjust region.
    */
    QRegion region (menu->x(),
                    menu->y(),
                    menu->sizeHint().width(),
                    menu->sizeHint().height(),
                    QRegion::Ellipse);
    menu->setMask(region);

    qApp->setStyleSheet(styleSheet);
}

