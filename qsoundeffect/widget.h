#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSoundEffect>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void play();

private:
    QSoundEffect effect;
};

#endif // WIDGET_H
