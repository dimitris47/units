#include "weightwidget.h"
#include "ui_weightwidget.h"
#include <QDoubleValidator>
#include <QLocale>
#include <QMainWindow>

WeightWidget::WeightWidget(QWidget *parent) : QFrame(parent), ui(new Ui::WeightWidget) {
    ui->setupUi(this);
    ui->kgline->setValidator(new QDoubleValidator(0.0, 99999.999, 3, this));
    ui->lbsline->setValidator(new QDoubleValidator(0.0, 99999.999, 3, this));
}

WeightWidget::~WeightWidget() {
    delete ui;
}

void WeightWidget::on_kgline_textEdited(const QString& value)
{
    float kg = value.toDouble();
    float pounds = kg*2.204623;
    QString poundsRes = QString::number(pounds, 'f', 3);
    ui->lbsline->setText(poundsRes);
}

void WeightWidget::on_lbsline_textEdited(const QString& value) {
    float pounds = value.toDouble();
    float kg = pounds/2.204623;
    QString kgRes = QString::number(kg, 'f', 3);
    ui->kgline->setText(kgRes);
}

void WeightWidget::clear() {
    ui->kgline->setText("");
    ui->lbsline->setText("");
}
