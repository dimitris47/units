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
    connect(ui->actionDistance,    &QAction::triggered, this,        &MainWindow::showDistanceWidget);
    connect(ui->actionSpeed,       &QAction::triggered, this,        &MainWindow::showSpeedWidget);
    connect(ui->actionTemperature, &QAction::triggered, this,        &MainWindow::showTemperatureWidget);
    connect(ui->actionWeight,      &QAction::triggered, this,        &MainWindow::showWeightWidget);
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

void MainWindow::showDistanceWidget() {
    stackedWidget->setCurrentWidget(distance);
}

void MainWindow::showSpeedWidget() {
    stackedWidget->setCurrentWidget(speed);
}

void MainWindow::showTemperatureWidget() {
    stackedWidget->setCurrentWidget(temperature);
}

void MainWindow::showWeightWidget() {
    stackedWidget->setCurrentWidget(weight);
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

