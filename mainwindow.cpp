#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

//Test

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QPixmap pixAcceuil("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/home.ico");
    ui->label_pic_Acceuil->setPixmap(pixAcceuil);
    ui->label_pic_Acceuil2->setPixmap(pixAcceuil);
    QPixmap pixChercher("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/1.ico");
    ui->label_pic_Chercher->setPixmap(pixChercher);
    ui->label_pic_Chercher1->setPixmap(pixChercher);
    ui->label_pic_Chercher2->setPixmap(pixChercher);
    QPixmap pixAjouter("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/2.ico");
    ui->label_pic_Ajouter->setPixmap(pixAjouter);
    ui->label_pic_Ajouter1->setPixmap(pixAjouter);
    //QPixmap pixTrier("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/3.ico");
   // ui->label_pic_Trier->setPixmap(pixTrier);

    QPixmap pixModifier("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/4.ico");
    ui->label_pic_Modifier->setPixmap(pixModifier);
    ui->label_pic_Modifier1->setPixmap(pixModifier);
    QPixmap pixAfficher("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/5.ico");
  //  ui->label_pic_Afficher->setPixmap(pixAfficher);
    ui->label_pic_Afficher1->setPixmap(pixAfficher);
    QPixmap pixSupprimer("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/6.ico");
    ui->label_pic_Supprimer->setPixmap(pixSupprimer);
    ui->label_pic_Supprimer1->setPixmap(pixSupprimer);
    QPixmap pixSatistiques("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/7.ico");
    ui->label_pic_Statistiques->setPixmap(pixSatistiques);
    ui->label_pic_Statistiques1->setPixmap(pixSatistiques);
    QPixmap pixQR("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Icons/qr.ico");
    ui->label_pic_QR->setPixmap(pixQR);
    ui->label_pic_QR1->setPixmap(pixQR);
}

MainWindow::~MainWindow()
{
    delete ui;
}

