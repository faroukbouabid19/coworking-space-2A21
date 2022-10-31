#ifndef BUREAUX_H
#define BUREAUX_H

#include <QDialog>

namespace Ui {
class Bureaux;
}

class Bureaux : public QDialog
{
    Q_OBJECT

public:
    explicit Bureaux(QWidget *parent = nullptr);
    ~Bureaux();

private slots:
    void on_pushButton_38_clicked();

private:
    Ui::Bureaux *ui;
};

#endif // BUREAUX_H
