#include "gestionreservation.h"
#include "ui_gestionreservation.h"
#include"resrvation.h"
#include<QMessageBox>
#include<QTableWidget>
using namespace std ;

                                              ////////////////AFFICHER///////////
gestionreservation::gestionreservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestionreservation)
{
    ui->setupUi(this);
   ui->afficher->setModel(R.afficher());
}

gestionreservation::~gestionreservation()
{
    delete ui;
}
                  ////////////////////////////////////////////SUPPRTIMER /////////////////////
void gestionreservation::on_pushButton_clicked()
{
         Resrvation R ;

       R.setnum_res(ui->lineEdit_3->text().toInt());
        bool test=R.supprimer(R.get_num_res());


        if(test )
        {

            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression effectue\n""click cancel to exit."),
                                     QMessageBox::Cancel);
            ui->afficher->setModel(R.afficher());

        }

        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                     QObject::tr("suppression non effectue\n""click cancel to exit."),
                                     QMessageBox::Cancel);


}
                             ////////////////////////////AJOUTER////////////

void gestionreservation::on_pushButton_5_clicked()
{

    int num_res=ui->lineEdit_15->text().toInt();
    int duree=ui->lineEdit_7->text().toInt();
    int nombre=ui->lineEdit_5->text().toInt();
    QString id_c=ui->lineEdit->text();
    QString date=ui->lineEdit_4->text();
    QString id_b=ui->lineEdit_6->text();

    Resrvation R (num_res,duree,nombre,id_c,date,id_b);
    bool test=R.ajouter();

    if(test)
    {


        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n""click cancel to exit."),
                                 QMessageBox::Cancel);
        ui->afficher_2->setModel(R.afficher());


    }

else
         QMessageBox:: critical (nullptr , QObject::tr("not OK"),
                QObject::tr("ajout non effectue\n"
                            "click cancel to exit."),
                QMessageBox::Cancel);
    ui->afficher->setModel(R.afficher());



}

//////////////////////////////////MODIFIER////////////////////////

void gestionreservation::on_pushButton_3_clicked()
{



        int num_res=ui->lineEdit_17->text().toInt();
        int duree=ui->spinBox_4->text().toInt();
        int nombre =ui->spinBox_3->text().toInt();
        QString id_c=ui->lineEdit_2->text();
        QString id_b=ui->lineEdit_14->text();
        QString date=ui->dateTimeEdit_2->text();



        Resrvation a;
        bool test=a.modifier(num_res,duree,nombre,id_c,date,id_b);

        if (num_res==NULL)
                 {
                     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP num_res!!!!") ;
                     QMessageBox::critical(0, qApp->tr("Ajout"),

                                     qApp->tr("Probleme de modification"), QMessageBox::Cancel);




                 }

              else if (duree==NULL)
               {

                   QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP duree!!!!") ;
                   QMessageBox::critical(0, qApp->tr("Ajout"),

                                   qApp->tr("Probleme de modification"), QMessageBox::Cancel);



               }
            else if (nombre==NULL)
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nombre!!!!") ;
                 QMessageBox::critical(0, qApp->tr("Ajout"),

                                 qApp->tr("Probleme de modification"), QMessageBox::Cancel);



             }


           else if (id_c==NULL)
                 {

                     QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id_c!!!!") ;
                     QMessageBox::critical(0, qApp->tr("Ajout"),

                                     qApp->tr("Probleme de modification"), QMessageBox::Cancel);




                 }
        else if (id_b==NULL)
              {

                  QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id_b!!!!") ;
                  QMessageBox::critical(0, qApp->tr("Ajout"),

                                  qApp->tr("Probleme de modification"), QMessageBox::Cancel);





              }
        else if (date==NULL)
              {

                  QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP date!!!!") ;
                  QMessageBox::critical(0, qApp->tr("Ajout"),

                                  qApp->tr("Probleme de modification"), QMessageBox::Cancel);

              }




        else if(test)
        {

            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("midification effectue\n""click cancel to exit."),
                                     QMessageBox::Cancel);
                                   ui->afficher_2->setModel(R.afficher());

        }

        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                     QObject::tr("modification non effectue\n""click cancel to exit."),
                                     QMessageBox::Cancel);

}

