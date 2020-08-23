#ifndef WEIGHTWIDGET_H
#define WEIGHTWIDGET_H

#include <QFrame>

namespace Ui {
class WeightWidget;
}

class WeightWidget : public QFrame {
    Q_OBJECT

public:
    explicit WeightWidget(QWidget *parent = nullptr);
    ~WeightWidget();

public slots:
    void clear();

private slots:
    void on_kgline_textEdited();
    void on_lbsline_textEdited();

private:
    Ui::WeightWidget *ui;
};

#endif // WEIGHT_H
