#ifndef TEMPERATUREWIDGET_H
#define TEMPERATUREWIDGET_H

#include <QFrame>

namespace Ui { class TemperatureWidget; }

class TemperatureWidget : public QFrame {
    Q_OBJECT

public:
    explicit TemperatureWidget(QWidget *parent = nullptr);
    ~TemperatureWidget();

public slots:
    void clear();

private slots:
    void on_celcline_textEdited(const QString &value);
    void on_fahrline_textEdited(const QString &value);

private:
    Ui::TemperatureWidget *ui;
};

#endif // TEMPERATUREWIDGET_H
