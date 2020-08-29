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
    void on_cmline_textEdited(const QString &value);
    void on_ftline_textEdited(const QString &value);
    void on_inchline_editingFinished();
    void on_inchline_textEdited(const QString &value);
    void on_mLine_textEdited(const QString &value);
    void on_ydLine_textEdited(const QString &value);
    void on_kmline_textEdited(const QString &value);
    void on_mileline_textEdited(const QString &value);

private:
    Ui::DistanceWidget *ui;
};

#endif // DISTANCEWIDGET_H
