#include "mainwindow.h"
#include "global.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QLocale::setDefault(QLocale::C);
    QApplication a(argc, argv);
    QApplication::setOrganizationName("DP Software");
    QApplication::setApplicationName(APPNAME);
    QApplication::setApplicationVersion(VERSION);
    MainWindow w;
    w.show();
    return a.exec();
}

