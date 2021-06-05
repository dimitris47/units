#include "temperaturewidget.h"
#include "ui_temperaturewidget.h"
#include <QDoubleValidator>
#include <QMainWindow>
#include <QMessageBox>

TemperatureWidget::TemperatureWidget(QWidget *parent) : QFrame(parent), ui(new Ui::TemperatureWidget) {
    ui->setupUi(this);
    ui->celcline->setValidator(new QDoubleValidator(-273.15, 999.9, 2, this));
    ui->fahrline->setValidator(new QDoubleValidator(-459.67, 999.9, 2, this));
}

TemperatureWidget::~TemperatureWidget() { delete ui; }

void TemperatureWidget::on_celcline_textEdited(const QString &value) {
    float C = value.toDouble();
    if (C < -273.15)
        QMessageBox::critical(this, tr("Invalid Temperature"),
                              ("Temperatures below -273.15ºC can't exist."));
    float F = (C) * 9 / 5 + 32;
    ui->fahrline->setText(QString::number(F, 'f', 1));
}

void TemperatureWidget::on_fahrline_textEdited(const QString &value) {
    float F = value.toDouble();
    if (F < -459.67)
        QMessageBox::critical(this, tr("Invalid Temperature"),
                              ("Temperatures below -459.67ºF can't exist."));
    float C = (F - 32) * 5 / 9;
    ui->celcline->setText(QString::number(C, 'f', 1));
}

void TemperatureWidget::clear() {
    ui->celcline->setText("");
    ui->fahrline->setText("");
}
