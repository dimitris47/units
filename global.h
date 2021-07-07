#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>

const QString br("<br/>");
const QString APPNAME("Units");
const QString VERSION("2.0.3");
const QString CONTRIBUTORS("Dimitris Psathas");

const QString APPINFO("Program created by Dimitris Psathas" + br.repeated(2) +
                      "Written in C++, built against Qt 5.15.2" + br.repeated(2) +
                      "Published under the MIT License" + br +
                      "Qt libraries used under (L)GPL3" + br +
                      "Application icon by <a href='https://icons8.com'>icons8.com</a>" + br +
                      "In-app icons by <a href='https://icons8.com'>icons8.com</a>" + br +
                      "and the Ubuntu Yaru theme" + br.repeated(2) +
                      "&copy; 2020-2021 Dimitris Psathas");

#endif // GLOBAL_H
