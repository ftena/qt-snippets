#include "widget.h"
#include "ui_widget.h"

void copy(QStandardItemModel* from, QStandardItemModel* to)
{
   to->removeRows(0, to->rowCount ());

   for (int i = 0 ; i < from->rowCount() ; i++)
   {
       QList<QStandardItem*> rowItems;
       for (int j = 0 ; j < from->columnCount() ; j++)
       {
           rowItems.append(from->item(i,j)->clone());
       }
       to->appendRow(rowItems);
   }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // New model
    model = new QStandardItemModel(5,5,this);
    ui->tableView->setModel(model);

    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            QModelIndex index = model->index(row,col,QModelIndex());
            model->setData(index, row);
        }
    }

    model_2 = new QStandardItemModel(this);
    copy(model, model_2);
    ui->tableView_2->setModel(model_2);
}

Widget::~Widget()
{
    delete ui;
}
