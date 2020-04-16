#include "asmr.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ASMR w;
    w.show();

    return a.exec();
}
