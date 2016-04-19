#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class RenderArea;
class QTextDocument;
class QTextEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    RenderArea* renderArea;
    QTextDocument *textDocument;
    QTextEdit* textEdit;
};

#endif // WIDGET_H
