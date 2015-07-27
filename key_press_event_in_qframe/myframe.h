#ifndef MYFRAME_H
#define MYFRAME_H

#include <QtWidgets/QFrame>

class MyFrame : public QFrame
{
    Q_OBJECT

public:
    MyFrame();

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif
