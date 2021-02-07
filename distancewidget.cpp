#include "distancewidget.h"
#include "ui_distancewidget.h"
#include <QMainWindow>
#include <QValidator>

DistanceWidget::DistanceWidget(QWidget *parent) : QFrame(parent), ui(new Ui::DistanceWidget) {
    ui->setupUi(this);
    auto lines = this->findChildren<QLineEdit *>();
    for (auto &&line : lines)
        line->setValidator(new QDoubleValidator(0.0, 99999.999, 3, this));
}

DistanceWidget::~DistanceWidget() { delete ui; }

void DistanceWidget::on_cmline_textEdited(const QString& value) {
    double cm = value.toDouble();
    int feet = cm / 30.48;
    double inches = (cm - feet * 30.48) / 2.54;
    ui->ftline->setText(QString::number(feet));
    ui->inchline->setText(QString::number(inches, 'f', 2));
}

void DistanceWidget::on_ftline_textEdited(const QString& value) {
    int feet = value.toInt();
    double inches = ui->inchline->text().toDouble();
    double cm = feet * 30.48 + inches * 2.54;
    ui->cmline->setText(QString::number(cm, 'f', 2));
}

void DistanceWidget::on_inchline_textEdited(const QString& value) {
    double inches = value.toDouble();
    int feet = ui->ftline->text().toInt();
    double cm = feet * 30.48 + inches * 2.54;
    ui->cmline->setText(QString::number(cm, 'f', 2));
}

void DistanceWidget::on_inchline_editingFinished() {
    int feet = ui->ftline->text().toInt();
    double inches = ui->inchline->text().toDouble();
    if (inches >= 12) {
        int newInches = qRound(ui->inchline->text().toDouble());
        double intermInches = newInches % 12;
        double finalInches = intermInches + inches - newInches;
        ui->inchline->setText(QString::number(finalInches));
        int remInches = inches - finalInches;
        int newFeet = feet + remInches / 12;
        ui->ftline->setText(QString::number(newFeet));
        double cm = newFeet * 30.48 + finalInches * 2.54;
        ui->cmline->setText(QString::number(cm, 'f', 2));
    }
}

void DistanceWidget::on_mLine_textEdited(const QString& value) {
    double meters = value.toDouble();
    double yards = meters / 0.9144;
    ui->ydLine->setText(QString::number(yards, 'f', 3));
}

void DistanceWidget::on_ydLine_textEdited(const QString& value) {
    double yards = value.toDouble();
    double meters = yards * 0.9144;
    ui->mLine->setText(QString::number(meters, 'f', 3));
}

void DistanceWidget::on_kmline_textEdited(const QString &value) {
    double km = value.toDouble();
    double miles = km * 0.6213712;
    ui->mileline->setText(QString::number(miles, 'f', 3));
}

void DistanceWidget::on_mileline_textEdited(const QString& value) {
    double miles = value.toDouble();
    double km = miles / 0.6213712;
    ui->kmline->setText(QString::number(km, 'f', 3));
}

void DistanceWidget::clear() {
    auto lines = this->findChildren<QLineEdit *>();
    for (auto &&line : lines)
        line->setText("");
}
