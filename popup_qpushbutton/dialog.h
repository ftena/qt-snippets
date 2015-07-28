#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QDialog>
#include "ui_dialog.h"

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog();

protected:
    bool eventFilter(QObject * obj, QEvent *event);

private:
    Ui::Dialog m_ui;
};

#endif
