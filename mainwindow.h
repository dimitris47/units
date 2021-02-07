#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QMainWindow>
#include <QSettings>

class DistanceWidget;
class Speed;
class TemperatureWidget;
class WeightWidget;
class QStackedWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void readSettings();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_actionAbout_triggered();
    void showDistanceWidget();
    void showSpeedWidget();
    void showTemperatureWidget();
    void showWeightWidget();

private:
    Ui::MainWindow *ui;
    DistanceWidget *distance;
    Speed *speed;
    TemperatureWidget *temperature;
    WeightWidget *weight;
    QStackedWidget *stackedWidget;
};

#endif // MAINWINDOW_H
