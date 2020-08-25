#include "distancewidget.h"
#include "ui_distancewidget.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QValidator>

DistanceWidget::DistanceWidget(QWidget *parent) : QFrame(parent), ui(new Ui::DistanceWidget) {
    ui->setupUi(this);
    ui->cmline->setValidator(new QDoubleValidator(0.0, 999.0, 2, this));
    ui->ftline->setValidator(new QIntValidator(0, 999, this));
    ui->inchline->setValidator(new QDoubleValidator(0.0, 999.0, 2, this));
    ui->mLine->setValidator(new QDoubleValidator(0.0, 999.0, 2, this));
    ui->ydLine->setValidator(new QDoubleValidator(0.0, 999.0, 2, this));
    ui->kmline->setValidator(new QDoubleValidator(0.0, 999.0, 3, this));
    ui->mileline->setValidator(new QDoubleValidator(0.0, 999.0, 3, this));
    connect(ui->actionClear, &QAction::triggered, this, &DistanceWidget::clear);
}

DistanceWidget::~DistanceWidget() {
    delete ui;
}

void DistanceWidget::on_cmline_textEdited() {
    float cm = ui->cmline->text().toDouble();
    if (ui->cmline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    int feet = cm/30.48;
    float inches = (cm-feet*30.48)/2.54;
    QString ftRes = QString::number(feet);
    QString inchRes = QString::number(inches, 'f', 2);
    ui->ftline->setText(ftRes);
    ui->inchline->setText(inchRes);
}

void DistanceWidget::on_ftline_textEdited() {
    int feet = ui->ftline->text().toInt();
    float inches = ui->inchline->text().toDouble();
    if (ui->inchline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    float cm = feet*30.48+inches*2.54;
    QString cmRes = QString::number(cm, 'f', 2);
    ui->cmline->setText(cmRes);
}

void DistanceWidget::on_inchline_textEdited() {
    int feet = ui->ftline->text().toInt();
    float inches = ui->inchline->text().toDouble();
    float cm = feet*30.48+inches*2.54;
    QString cmRes = QString::number(cm, 'f', 2);
    ui->cmline->setText(cmRes);

    if (ui->inchline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
}

void DistanceWidget::on_inchline_editingFinished() {
    int feet = ui->ftline->text().toInt();
    float inches = ui->inchline->text().toDouble();
    if (inches >= 12) {
        int newInches = qRound(ui->inchline->text().toDouble());
        float intermInches = newInches % 12;
        float finalInches = intermInches + inches - newInches;
        ui->inchline->setText(QString::number(finalInches));
        int remInches = inches-finalInches;
        int newFeet = feet+remInches/12;
        ui->ftline->setText(QString::number(newFeet));
        float cm = newFeet*30.48+finalInches*2.54;
        QString cmRes = QString::number(cm, 'f', 2);
        ui->cmline->setText(cmRes);
    }
    if (ui->inchline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
}

void DistanceWidget::on_mLine_textEdited() {
    float meters = ui->mLine->text().toDouble();
    if (ui->mLine->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    float yards = meters*0.9144;
    QString ydRes = QString::number(yards, 'f', 3);
    ui->ydLine->setText(ydRes);
}

void DistanceWidget::on_ydLine_textEdited() {
    float yards = ui->ydLine->text().toDouble();
    if (ui->ydLine->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    float meters = yards/0.9144;
    QString mRes = QString::number(meters, 'f', 3);
    ui->mLine->setText(mRes);
}

void DistanceWidget::on_kmline_textEdited() {
    float km = ui->kmline->text().toDouble();
    if (ui->kmline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    float miles = km*0.6213712;
    QString mileRes = QString::number(miles, 'f', 3);
    ui->mileline->setText(mileRes);
}

void DistanceWidget::on_mileline_textEdited() {
    float miles = ui->mileline->text().toDouble();
    if (ui->mileline->text().contains(",")) {
        QMessageBox::critical(
                        this,
                        tr("Wrong decimal"),
                        ("In order to correctly type a decimal number,<br/>you must use \".\" instead of \",\"."));
    }
    float km = miles/0.6213712;
    QString kmRes = QString::number(km, 'f', 3);
    ui->kmline->setText(kmRes);
}

void DistanceWidget::clear() {
    ui->cmline->setText("");
    ui->ftline->setText("");
    ui->inchline->setText("");
    ui->mLine->setText("");
    ui->ydLine->setText("");
    ui->kmline->setText("");
    ui->mileline->setText("");
}
