#include "widget.h"
#include "ui_widget.h"
#include <QSortFilterProxyModel>

const int column_id = 1;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // New model
    model = new QStandardItemModel(5, 5, this);
    ui->tableView->setModel(model);

    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            QModelIndex index = model->index(row,col,QModelIndex());
            model->setData(index, row);
        }
    }

    proxy_model = new QSortFilterProxyModel();
    proxy_model ->setSourceModel(model);
    ui->tableView_2->setModel(proxy_model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_checkBox_toggled(bool checked)
{
    if (checked)
    {

        proxy_model->setFilterRegExp(QRegExp(ui->spinBox->text(), Qt::CaseInsensitive,
                                             QRegExp::FixedString));

        proxy_model->setFilterKeyColumn(column_id);
    }
    else
    {
        proxy_model->setFilterRegExp(QRegExp());
    }
}
