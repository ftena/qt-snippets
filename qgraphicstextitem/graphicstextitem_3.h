#ifndef GRAPHICSTEXTITEM_3_H
#define GRAPHICSTEXTITEM_3_H

#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsTextItem;

class GraphicsTextItem_3 : public QMainWindow
{
    Q_OBJECT
public:
    explicit GraphicsTextItem_3(QMainWindow *parent = 0);

private:
     QGraphicsScene *scene;
     QGraphicsView *view;
     QGraphicsTextItem *item;

signals:

public slots:
};

#endif // GRAPHICSTEXTITEM_3_H
