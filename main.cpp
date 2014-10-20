#include <QApplication>

#include "maingui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainGui mg;
    mg.show();

    return a.exec();
}
