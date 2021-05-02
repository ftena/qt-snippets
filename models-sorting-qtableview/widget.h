#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>

class QSortFilterProxyModel;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_checkBox_toggled(bool checked);

private:
    Ui::Widget *ui;

    QStandardItemModel *model;
    QSortFilterProxyModel *proxy_model;
};

#endif // WIDGET_H
