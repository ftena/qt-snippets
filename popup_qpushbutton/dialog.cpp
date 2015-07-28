#include <QMenu>
#include <QDebug>
#include "dialog.h"
#include "popupmenu.h"

Dialog::Dialog()
{
    m_ui.setupUi(this);

    /* Instantiate both menus */
    QMenu* menu = new QMenu("menu", this);
    PopupMenu* popup_menu = new PopupMenu(m_ui.pushButton, this);

    QAction *action = new QAction("action#1", this);
    menu->addAction(action);
    popup_menu->addAction(action);
    
    /* Change menu position using an event filer */
    // menu->installEventFilter(this);
    m_ui.pushButton->setMenu(menu);

    /* Change menu position subclassing QMenu */    
    m_ui.pushButton->setMenu(popup_menu);  
}

bool Dialog::eventFilter(QObject * obj, QEvent *event)
{
    if (event->type() == QEvent::Show && obj == m_ui.pushButton->menu())
    {
	int menu_x_pos = m_ui.pushButton->menu()->pos().x();
	int menu_width = m_ui.pushButton->menu()->size().width();
	int button_width = m_ui.pushButton->size().width();

        QPoint pos = QPoint(menu_x_pos - menu_width + button_width,
                            m_ui.pushButton->menu()->pos().y());

	qDebug() << "position in Dialog::eventFilter --- x: " <<  pos.x() << " y: " << pos.y();

	m_ui.pushButton->menu()->move(pos);
	return true;
    }
    return false;
}
