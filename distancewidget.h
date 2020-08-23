#ifndef DISTANCEWIDGET_H
#define DISTANCEWIDGET_H

#include <QFrame>

namespace Ui {
class DistanceWidget;
}

class DistanceWidget : public QFrame {
    Q_OBJECT

public:
    explicit DistanceWidget(QWidget *parent = nullptr);
    ~DistanceWidget();

public slots:
    void clear();

private slots:
    void on_cmline_textEdited();
    void on_ftline_textEdited();
    void on_inchline_textEdited();
    void on_kmline_textEdited();
    void on_mileline_textEdited();

private:
    Ui::DistanceWidget *ui;
};

#endif // DISTANCEWIDGET_H
