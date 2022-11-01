#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "personnel.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixAcceuil("C:/Users/bouab/Desktop/logooo.png");
        ui->logobb->setPixmap(pixAcceuil);
       // QPixmap pixAcceuil1("‪C:/Users/bouab/Downloads/1.ico");
//            ui->rech->setPixmap(pixAcceuil1);

    ui->setupUi(this);
    ui->age->setValidator( new QIntValidator(0, 99999999, this));
   ui->affichage->setModel(p.afficher());
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_done_clicked() //clicked on done button after adding
{
    QString prenom=ui->prenom->text();
    QString nom=ui->nom->text();
    QString id=ui->id->text();
    QString titre=ui->titre->text();
    QString date=ui->date->text();
    int  age=ui->age->text().toInt() ;

    //option
    personnel p(prenom,nom,id,titre,date,age);
    bool test=p.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_ajouter_clicked()
{

}


void MainWindow::on_suprimer_clicked()
{
    QString id=ui->id->text();
         bool test=p.supprimer(id);

         if (test)
         {
             ui->affichage->setModel(p.afficher());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("suppression effectué.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
         QMessageBox::critical(nullptr, QObject::tr("not OK"),
                             QObject::tr("suppression failed.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_clicked()
{
    int age=ui->age->text().toInt();
        QString nom=ui->nom->text();
        QString prenom=ui->prenom->text();
        QString id=ui->id->text();
        QString date=ui->date->text();
        QString titre=ui->titre->text();
        personnel p(prenom,nom,id,titre,date,age);
        bool test=p.modifier();

            if(test){
              ui->affichage->setModel(p.afficher());
                        QMessageBox::information(nullptr, QObject::tr("OK"),
                                    QObject::tr("modification effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("not OK"),
                            QObject::tr("modification failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


