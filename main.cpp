#include "gausseidel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gausseidel w;
    w.show();

    return a.exec();
}
