#ifndef SPEED_H
#define SPEED_H

#include <QFrame>

namespace Ui { class Speed; }

class Speed : public QFrame
{
    Q_OBJECT

public:
    explicit Speed(QWidget *parent = nullptr);
    ~Speed();

public slots:
    void clear();

private slots:
    void on_ftpsline_textEdited(const QString &arg1);
    void on_kmhline_textEdited(const QString &arg1);
    void on_knline_textEdited(const QString &arg1);
    void on_mphline_textEdited(const QString &arg1);
    void on_mpsline_textEdited(const QString &arg1);

private:
    Ui::Speed *ui;
};

#endif // SPEED_H
