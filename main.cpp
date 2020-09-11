#include "mainwindow.h"
#include "global.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[]) {
    QLocale::setDefault(QLocale::C);
    QApplication a(argc, argv);
    QApplication::setOrganizationName("DP Software");
    QApplication::setApplicationName(APPNAME);
    QApplication::setApplicationVersion(VERSION);
    QApplication::setFont(QFont("Fira Sans, Segoe UI, Verdana, Ubuntu, Noto Sans, Arimo, Liberation Sans"));
    MainWindow w;
    w.show();
    return a.exec();
}

