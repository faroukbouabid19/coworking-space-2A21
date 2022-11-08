#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personnel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modif_clicked();
    void on_tri_age_emp_clicked();
    void on_tri_prenom_emp_clicked();
    void on_tri_nom_emp_clicked();
    //void on_line_rech_emp_textChanged(const QString &arg1);
    void on_Recherche_clicked();
    void on_PDF_clicked();
private:
    Ui::MainWindow *ui;
    personnel p;
};

#endif // MAINWINDOW_H


