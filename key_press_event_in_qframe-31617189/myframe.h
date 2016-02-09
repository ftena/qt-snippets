#ifndef MYFRAME_H
#define MYFRAME_H

#include <QtWidgets/QFrame>

class MyFrame : public QFrame
{
    Q_OBJECT

public:
    MyFrame();
    bool eventFilter(QObject *object, QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif
