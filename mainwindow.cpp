#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "distancewidget.h"
#include "temperaturewidget.h"
#include "weightwidget.h"
#include <QActionGroup>
#include <QMessageBox>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    distance(new DistanceWidget),
    temperature(new TemperatureWidget),
    weight(new WeightWidget)
{
    QIcon::setThemeSearchPaths(QStringList() << ":icons" << QIcon::themeSearchPaths());
    QIcon::setThemeName("fallback");

    readSettings();
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setObjectName(QString::fromUtf8("stacked"));
    stackedWidget->addWidget(distance);
    stackedWidget->addWidget(temperature);
    stackedWidget->addWidget(weight);
    setCentralWidget(stackedWidget);

    auto switchPages = new QActionGroup(this);
    switchPages->addAction(ui->actionDistance);
    switchPages->addAction(ui->actionTemperature);
    switchPages->addAction(ui->actionWeight);

    auto distanceActions = new QActionGroup(this);
    distanceActions->addAction(ui->actionClear);
    distanceActions->setEnabled(true);

    auto temperatureActions = new QActionGroup(this);
    temperatureActions->addAction(ui->actionClear);
    temperatureActions->setEnabled(true);

    auto weightActions = new QActionGroup(this);
    weightActions->addAction(ui->actionClear);
    weightActions->setEnabled(true);

    connect(ui->actionExit,        &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionDistance,    &QAction::triggered, this, &MainWindow::showDistanceWidget);
    connect(ui->actionTemperature, &QAction::triggered, this, &MainWindow::showTemperatureWidget);
    connect(ui->actionWeight,      &QAction::triggered, this, &MainWindow::showWeightWidget);
    connect(ui->actionClear,       &QAction::triggered, distance, &DistanceWidget::clear);
    connect(ui->actionClear,       &QAction::triggered, temperature, &TemperatureWidget::clear);
    connect(ui->actionClear,       &QAction::triggered, weight, &WeightWidget::clear);
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

void MainWindow::showTemperatureWidget() {
    stackedWidget->setCurrentWidget(temperature);
}

void MainWindow::showWeightWidget() {
    stackedWidget->setCurrentWidget(weight);
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(
                    this,
                    tr("Program Info"),
                    (QApplication::applicationName() + " " + QApplication::applicationVersion() + "<br/><br/>" +
                    tr("Program created by Dimitris Psathas<br/><br/>"
                       "Written in C++, built against the Qt5 toolkit<br/><br/>"
                       "Published under the MIT License<br/>"
                       "&copy; 2020")));
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QSettings settings;
    settings.setValue("isMaximized", isMaximized());
    if (!isMaximized())
        settings.setValue("geometry", saveGeometry());
    event->accept();
}
