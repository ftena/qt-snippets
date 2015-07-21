#include "dialog.h"
#include <iostream>

Dialog::Dialog()
{
    m_ui.setupUi(this);

    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)),
        this, SLOT(focusChanged(QWidget*,QWidget*)));
}

void Dialog::focusChanged(QWidget *, QWidget *now)
{
    qDebug("Dialog::focusChanged");
}

