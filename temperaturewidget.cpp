/**
 * Copyright 2020-2021 Dimitris Psathas <dimitrisinbox@gmail.com>
 *
 * This file is part of Units.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This program is using libraries by Qt under the LGPLv3 license.
 */


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
