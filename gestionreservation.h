#ifndef GESTIONRESERVATION_H
#define GESTIONRESERVATION_H
#include"resrvation.h"

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

private:
    Ui::gestionreservation *ui;
       Resrvation R ;
};

#endif // GESTIONRESERVATION_H
