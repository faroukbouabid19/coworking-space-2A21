#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personnel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//private:
   // Ui::MainWindow *ui;
private slots:
    void on_ajouter_clicked();

    void on_done_clicked();

    void on_affichage_clicked(const QModelIndex &index);

    void on_suprimer_clicked();

    void on_modifier_clicked();


private:
    Ui::MainWindow *ui;
    personnel p;
};

#endif // MAINWINDOW_H
