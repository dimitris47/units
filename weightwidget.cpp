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

WeightWidget::~WeightWidget() { delete ui; }

void WeightWidget::on_kgline_textEdited(const QString& value) {
    double kg = value.toDouble();
    double pounds = kg * 2.204623;
    ui->lbsline->setText(QString::number(pounds, 'f', 3));
}

void WeightWidget::on_lbsline_textEdited(const QString& value) {
    double pounds = value.toDouble();
    double kg = pounds / 2.204623;
    ui->kgline->setText(QString::number(kg, 'f', 3));
}

void WeightWidget::clear() {
    ui->kgline->setText("");
    ui->lbsline->setText("");
}
