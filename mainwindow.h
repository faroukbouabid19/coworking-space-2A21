#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personnel.h"
#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QDateTime>
#include "statistique.h"
#include "arduino.h"
#include <QDebug>
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
    void on_btn_chat_emp_clicked();
    void on_signin_clicked();

    void on_signup_clicked();

    void on_remove_user_clicked();

    void on_show_users_clicked();

    void on_modifier_user_clicked();
    void chercherFromArduino();




    void on_stat_clicked();
private:
    Ui::MainWindow *ui;
    personnel p;
    QSqlQueryModel * afficher();
     statistique *s;
     Arduino a;
        QByteArray data;
};

#endif // MAINWINDOW_H


