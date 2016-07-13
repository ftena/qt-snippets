#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>

int main(int argc, char **argv) {
  QApplication application{argc, argv};

  QMainWindow *main_window = new QMainWindow();
  main_window->show();

  QPushButton *button = new QPushButton("Press me");
  main_window->setCentralWidget(button);

  QObject::connect(button, &QPushButton::clicked, [main_window]() {
    QTimer::singleShot(2000, [main_window]() {

        QObjectList list = main_window->children();

        while (!list.isEmpty())
        {
            QObject *object= list.takeFirst();

            if (qobject_cast<QFileDialog*>(object))
            {
                qDebug() << object->objectName();
                QFileDialog* fileDialog = qobject_cast<QFileDialog*>(object);
                fileDialog->close();
            }
        }

        main_window->close();
    });

    QFileDialog::getOpenFileName(main_window, "Close me fast or I will crash!");
  });

  application.exec();
  return 0;
}
