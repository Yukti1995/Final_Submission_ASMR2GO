#include "asmr2go.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ASMR2Go w;
    w.show();

    return a.exec();
}
