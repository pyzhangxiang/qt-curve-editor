#include "cetest.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cetest w;
    w.show();
    return a.exec();
}
