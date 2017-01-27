#ifndef MYINPUTDIALOG_H
#define MYINPUTDIALOG_H

#include <QInputDialog>

class MyInputDialog : public QInputDialog
{
    Q_OBJECT

public:
    explicit MyInputDialog(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e) override;

signals:

public slots:
};

#endif // MYINPUTDIALOG_H
