#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString path = QDir::currentPath() + "/myfile.txt";

    QString fileName = QFileDialog::getSaveFileName(0, "Save file",
                                                    path,
                                                    "Music files(*.mp3;;Text files (*.txt)");

    return a.exec();
}
