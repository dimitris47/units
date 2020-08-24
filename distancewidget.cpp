#include "distancewidget.h"
#include "ui_distancewidget.h"
#include <QDoubleValidator>
#include <QIntValidator>
#include <QMainWindow>

DistanceWidget::DistanceWidget(QWidget *parent) : QFrame(parent), ui(new Ui::DistanceWidget) {
    ui->setupUi(this);

    ui->cmline->setAlignment(Qt::AlignCenter);
    ui->cmline->setValidator(new QDoubleValidator(0, 1000, 1, this));
    ui->ftline->setAlignment(Qt::AlignCenter);
    ui->ftline->setValidator(new QIntValidator(0, 1000, this));
    ui->inchline->setAlignment(Qt::AlignCenter);
    ui->inchline->setValidator(new QDoubleValidator(0, 1000, 1, this));
    ui->mLine->setAlignment(Qt::AlignCenter);
    ui->mLine->setValidator(new QDoubleValidator(0, 1000, 1, this));
    ui->ydLine->setAlignment(Qt::AlignCenter);
    ui->ydLine->setValidator(new QDoubleValidator(0, 1000, 1, this));
    ui->kmline->setAlignment(Qt::AlignCenter);
    ui->kmline->setValidator(new QDoubleValidator(0, 1000, 1, this));
    ui->mileline->setAlignment(Qt::AlignCenter);
    ui->mileline->setValidator(new QDoubleValidator(0, 1000, 1, this));

    connect(ui->actionClear, &QAction::triggered, this, &DistanceWidget::clear);
}

DistanceWidget::~DistanceWidget() {
    delete ui;
}

void DistanceWidget::on_cmline_textEdited() {
    float cm = ui->cmline->text().toFloat();
    int feet = cm/30.48;
    float inches = (cm-feet*30.48)/2.54;
    QString ftRes = QString::number(feet);
    QString inchRes = QString::number(inches, 'f', 1);
    ui->ftline->setText(ftRes);
    ui->inchline->setText(inchRes);
}

void DistanceWidget::on_ftline_textEdited() {
    int feet = ui->ftline->text().toInt();
    float inches = ui->inchline->text().toInt();
    float cm = feet*30.48+inches*2.54;
    QString cmRes = QString::number(cm, 'f', 1);
    ui->cmline->setText(cmRes);
}

void DistanceWidget::on_inchline_textEdited() {
    int feet = ui->ftline->text().toInt();
    float inches = ui->inchline->text().toInt();
    float cm = feet*30.48+inches*2.54;
    QString cmRes = QString::number(cm, 'f', 1);
    ui->cmline->setText(cmRes);
}

void DistanceWidget::on_mLine_textEdited() {
    float meters = ui->mLine->text().toFloat();
    float yards = meters*0.9144;
    QString ydRes = QString::number(yards, 'f', 2);
    ui->ydLine->setText(ydRes);
}

void DistanceWidget::on_ydLine_textEdited() {
    float yards = ui->ydLine->text().toFloat();
    float meters = yards/0.9144;
    QString mRes = QString::number(meters, 'f', 2);
    ui->mLine->setText(mRes);
}

void DistanceWidget::on_kmline_textEdited() {
    float km = ui->kmline->text().toFloat();
    float miles = km*0.6213712;
    QString mileRes = QString::number(miles, 'f', 2);
    ui->mileline->setText(mileRes);
}

void DistanceWidget::on_mileline_textEdited() {
    float miles = ui->mileline->text().toFloat();
    float km = miles/0.6213712;
    QString kmRes = QString::number(km, 'f', 2);
    ui->kmline->setText(kmRes);
}

void DistanceWidget::clear() {
    ui->cmline->setText("");
    ui->ftline->setText("");
    ui->inchline->setText("");
    ui->kmline->setText("");
    ui->mileline->setText("");
}
