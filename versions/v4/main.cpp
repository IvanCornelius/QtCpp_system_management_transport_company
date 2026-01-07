//объявление заголовочных файлов
#include "MainWindow.h"
#include <QApplication>

//главная программа
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
