#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bureaux.h"
#include "statistique.h"
#include "images.h"
#include "qrcodegen.hpp"


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

    void on_trieNum_clicked();

    void on_trieType_clicked();

    void on_trieCapacite_clicked();

    void on_trieDisponibilite_clicked();

    void on_TabBureau_clicked(const QModelIndex &index);

    void on_BaRecherche_textChanged(const QString &arg1);

    void on_PDF_clicked();

    void on_pb_stat_clicked();

    void on_pb_images_clicked();

private:

    Ui::MainWindow *ui;
    Bureau B;
    statistique *s;
    Images *i;

};

#endif // MAINWINDOW_H


