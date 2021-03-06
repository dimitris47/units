/**
 * Copyright 2020-2021 Dimitris Psathas <dimitrisinbox@gmail.com>
 *
 * This file is part of Units.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This program is using libraries by Qt under the LGPLv3 license.
 */


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

