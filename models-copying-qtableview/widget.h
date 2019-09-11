#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QStandardItemModel *model;
    QStandardItemModel *model_2;
    QStandardItemModel *model_3;
};

#endif // WIDGET_H
