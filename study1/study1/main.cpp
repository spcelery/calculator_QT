#include "calculator.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication::setStyle(QStyleFactory::create("Fusion"));

    Calculator w;
    w.show();
    return a.exec();
}
