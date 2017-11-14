#include "myapp.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    poly_widget dd;

    dd.show();


    return a.exec();
}
