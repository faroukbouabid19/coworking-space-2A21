#ifndef GESTIONRESERVATION_H
#define GESTIONRESERVATION_H
#include"resrvation.h"
#include"history.h"

#include <QWidget>

namespace Ui {
class gestionreservation;
}

class gestionreservation : public QWidget
{
    Q_OBJECT

public:
    explicit gestionreservation(QWidget *parent = nullptr);
    ~gestionreservation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::gestionreservation *ui;
       Resrvation R ;
       history H;
};

#endif // GESTIONRESERVATION_H
