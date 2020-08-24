#include "weightwidget.h"
#include "ui_weightwidget.h"
#include <QDoubleValidator>
#include <QMainWindow>
#include <QMessageBox>

WeightWidget::WeightWidget(QWidget *parent) : QFrame(parent), ui(new Ui::WeightWidget) {
    ui->setupUi(this);

    ui->kgline->setAlignment(Qt::AlignCenter);
    ui->kgline->setValidator(new QDoubleValidator(0, 1000, 1, this));
    ui->lbsline->setAlignment(Qt::AlignCenter);
    ui->lbsline->setValidator(new QDoubleValidator(0, 1000, 1, this));
}

WeightWidget::~WeightWidget() {
    delete ui;
}

void WeightWidget::on_kgline_textEdited()
{
    float kg = ui->kgline->text().toFloat();
    if (ui->kgline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    float pounds = kg*2.204623;
    QString poundsRes = QString::number(pounds, 'f', 2);
    ui->lbsline->setText(poundsRes);
}

void WeightWidget::on_lbsline_textEdited() {
    float pounds = ui->lbsline->text().toFloat();
    if (ui->lbsline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    float kg = pounds/2.204623;
    QString kgRes = QString::number(kg, 'f', 2);
    ui->kgline->setText(kgRes);
}

void WeightWidget::clear() {
    ui->kgline->setText("");
    ui->lbsline->setText("");
}
