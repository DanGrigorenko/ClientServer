#include "autentificationwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto w = new Admin;
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    return a.exec();
}

