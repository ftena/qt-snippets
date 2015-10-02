#ifndef GRAPHICSTEXTITEM_1_H
#define GRAPHICSTEXTITEM_1_H

#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsTextItem;

class GraphicsTextItem_1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit GraphicsTextItem_1(QMainWindow *parent = 0);

private:
     QGraphicsScene *scene;
     QGraphicsView *view;
     QGraphicsTextItem *item;

signals:

public slots:
};

#endif // GRAPHICSTEXTITEM_2_H
