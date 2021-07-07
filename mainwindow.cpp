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
#include "ui_mainwindow.h"
#include "distancewidget.h"
#include "global.h"
#include "speed.h"
#include "temperaturewidget.h"
#include "weightwidget.h"
#include <QActionGroup>
#include <QMessageBox>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    distance(new DistanceWidget),
    speed(new Speed),
    temperature(new TemperatureWidget),
    weight(new WeightWidget)
{
    readSettings();
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setObjectName(QString::fromUtf8("stacked"));
    stackedWidget->addWidget(distance);
    stackedWidget->addWidget(speed);
    stackedWidget->addWidget(temperature);
    stackedWidget->addWidget(weight);
    setCentralWidget(stackedWidget);

    auto switchPages = new QActionGroup(this);
    switchPages->addAction(ui->actionDistance);
    switchPages->addAction(ui->actionSpeed);
    switchPages->addAction(ui->actionTemperature);
    switchPages->addAction(ui->actionWeight);

    auto distanceActions = new QActionGroup(this);
    distanceActions->addAction(ui->actionClear);
    distanceActions->setEnabled(true);

    auto speedActions = new QActionGroup(this);
    speedActions->addAction(ui->actionClear);
    speedActions->setEnabled(true);

    auto temperatureActions = new QActionGroup(this);
    temperatureActions->addAction(ui->actionClear);
    temperatureActions->setEnabled(true);

    auto weightActions = new QActionGroup(this);
    weightActions->addAction(ui->actionClear);
    weightActions->setEnabled(true);

    connect(ui->actionExit,        &QAction::triggered, this,        &MainWindow::close);
    connect(ui->actionDistance,    &QAction::triggered, this,        [this]() { stackedWidget->setCurrentWidget(distance); });
    connect(ui->actionSpeed,       &QAction::triggered, this,        [this]() { stackedWidget->setCurrentWidget(speed); });
    connect(ui->actionTemperature, &QAction::triggered, this,        [this]() { stackedWidget->setCurrentWidget(temperature); });
    connect(ui->actionWeight,      &QAction::triggered, this,        [this]() { stackedWidget->setCurrentWidget(weight); });
    connect(ui->actionClear,       &QAction::triggered, distance,    &DistanceWidget::clear);
    connect(ui->actionClear,       &QAction::triggered, speed,       &Speed::clear);
    connect(ui->actionClear,       &QAction::triggered, temperature, &TemperatureWidget::clear);
    connect(ui->actionClear,       &QAction::triggered, weight,      &WeightWidget::clear);
}

MainWindow::~MainWindow() {
    delete distance;
    delete temperature;
    delete weight;
    delete ui;
}

void MainWindow::readSettings() {
    QSettings settings;
    bool isMax = settings.value("isMaximized", false).toBool();
    if (isMax)
        showMaximized();
    else {
        const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
        restoreGeometry(geometry);
    }
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this,tr("Program Info"),
                       (QApplication::applicationName() + " " + QApplication::applicationVersion() + "<br/><br/>" +
                        APPINFO));
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QSettings settings;
    settings.setValue("isMaximized", isMaximized());
    if (!isMaximized())
        settings.setValue("geometry", saveGeometry());
    event->accept();
}

