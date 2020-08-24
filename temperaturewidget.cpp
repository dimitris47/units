#include "temperaturewidget.h"
#include "ui_temperaturewidget.h"
#include <QDoubleValidator>
#include <QMainWindow>

TemperatureWidget::TemperatureWidget(QWidget *parent) : QFrame(parent), ui(new Ui::TemperatureWidget) {
    ui->setupUi(this);

    ui->celcline->setAlignment(Qt::AlignCenter);
    ui->celcline->setValidator(new QDoubleValidator(-237, 1000, 1, this));
    ui->fahrline->setAlignment(Qt::AlignCenter);
    ui->fahrline->setValidator(new QDoubleValidator(-394.6, 1000, 1, this));
}

TemperatureWidget::~TemperatureWidget() {
    delete ui;
}

void TemperatureWidget::on_celcline_textEdited() {
    float C = ui->celcline->text().toFloat();
    float F = (C)*9/5+32;
    QString FRes = QString::number(F, 'f', 1);
    ui->fahrline->setText(FRes);
}

void TemperatureWidget::on_fahrline_textEdited() {
    float F = ui->fahrline->text().toFloat();
    float C = (F-32)*5/9;
    QString CRes = QString::number(C, 'f', 1);
    ui->celcline->setText(CRes);
}
void TemperatureWidget::clear() {
    ui->celcline->setText("");
    ui->fahrline->setText("");
}
