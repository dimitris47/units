#include "speed.h"
#include "ui_speed.h"
#include <QDoubleValidator>

Speed::Speed(QWidget *parent) : QFrame(parent), ui(new Ui::Speed) {
    ui->setupUi(this);
    auto lines = this->findChildren<QLineEdit *>();
    for (auto &&line : lines)
        line->setValidator(new QDoubleValidator(0.0, 99999.99, 2, this));
}

Speed::~Speed() { delete ui; }

void Speed::on_mpsline_textEdited(const QString &arg1) {
    double mps = arg1.toDouble();
    double kmh = mps * 3.6;
    double mph = mps * 2.236936;
    double kn = mps * 1.943844;
    double ftps = mps * 3.280840;
    ui->kmhline->setText(QString::number(kmh, 'f', 2));
    ui->mphline->setText(QString::number(mph, 'f', 2));
    ui->knline->setText(QString::number(kn, 'f', 2));
    ui->ftpsline->setText(QString::number(ftps, 'f', 2));
}

void Speed::on_kmhline_textEdited(const QString &arg1) {
    double kmh = arg1.toDouble();
    double mps = kmh * 0.277778;
    double mph = kmh * 0.621371;
    double kn = kmh * 0.539957;
    double ftps = kmh * 0.911344;
    ui->mpsline->setText(QString::number(mps, 'f', 2));
    ui->mphline->setText(QString::number(mph, 'f', 2));
    ui->knline->setText(QString::number(kn, 'f', 2));
    ui->ftpsline->setText(QString::number(ftps, 'f', 2));
}

void Speed::on_mphline_textEdited(const QString &arg1) {
    double mph = arg1.toDouble();
    double mps = mph * 0.44704;
    double kmh = mph * 1.609344;
    double kn = mph * 0.868976;
    double ftps = mph * 1.466667;
    ui->kmhline->setText(QString::number(kmh, 'f', 2));
    ui->mpsline->setText(QString::number(mps, 'f', 2));
    ui->knline->setText(QString::number(kn, 'f', 2));
    ui->ftpsline->setText(QString::number(ftps, 'f', 2));
}

void Speed::on_knline_textEdited(const QString &arg1) {
    double kn = arg1.toDouble();
    double mps = kn * 0.514444;
    double kmh = kn * 1.852;
    double mph = kn * 1.150779;
    double ftps = kn * 1.687810;
    ui->mpsline->setText(QString::number(mps, 'f', 2));
    ui->kmhline->setText(QString::number(kmh, 'f', 2));
    ui->mphline->setText(QString::number(mph, 'f', 2));
    ui->ftpsline->setText(QString::number(ftps, 'f', 2));
}

void Speed::on_ftpsline_textEdited(const QString &arg1) {
    double ftps = arg1.toDouble();
    double mps = ftps * 0.3048;
    double kmh = ftps * 1.09728;
    double mph = ftps * 0.681818;
    double kn = ftps * 0.592484;
    ui->mpsline->setText(QString::number(mps, 'f', 2));
    ui->kmhline->setText(QString::number(kmh, 'f', 2));
    ui->mphline->setText(QString::number(mph, 'f', 2));
    ui->knline->setText(QString::number(kn, 'f', 2));
}

void Speed::clear() {
    auto lines = findChildren<QLineEdit *>();
    for (auto &&line : lines)
        line->setText("");
}
