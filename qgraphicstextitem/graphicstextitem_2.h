#ifndef GRAPHICSTEXTITEM_2_H
#define GRAPHICSTEXTITEM_2_H

#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsTextItem;

class GraphicsTextItem_2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit GraphicsTextItem_2(QMainWindow *parent = 0);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsTextItem *item;

signals:

public slots:
};

#endif // GRAPHICSTEXTITEM_2_H
