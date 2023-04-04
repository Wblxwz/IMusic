#include "IMusic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMusic w;
    w.show();
    return a.exec();
}
