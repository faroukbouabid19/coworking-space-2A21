#include "gestionreservation.h"
#include "ui_gestionreservation.h"
#include"resrvation.h"
#include<QMessageBox>
#include<QTableWidget>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QChartView>
#include <QPieSlice>
#include <QtCharts/QPieSlice>
using namespace std ;



                                              ////////////////AFFICHER///////////
gestionreservation::gestionreservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestionreservation)
{
    /*ui->setupUi(this);

          ui->lineEdit_ID->setValidator(new QIntValidator(1000, 99999999, this));
          ui->lineEdit_Numcage->setValidator(new QIntValidator(1000, 99999999, this));

          ui->lineEdit_Espece->setMaxLength(15);

          ui->lineEdit_ID_3->setValidator(new QIntValidator(1000, 99999999, this));
          ui->lineEdit_Numcage_3->setValidator(new QIntValidator(1000, 99999999, this));

          ui->lineEdit_Espece_3->setMaxLength(15);




                          QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                        QRegularExpression::CaseInsensitiveOption);
                              ui->lineEdit_Espece->setValidator(new QRegularExpressionValidator(rx1, this));
        ui->lineEdit_Espece_3->setValidator(new QRegularExpressionValidator(rx1, this));*/

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
    QString dateh=QDateTime::currentDateTime().toString("dd/MM/yyyy");
    QString heureh=QDateTime::currentDateTime().toString("hh::mm");
         Resrvation R ;
         history h;
           h.addHISTORYAjout(R.get_num_res(),"supprimer",dateh,heureh);
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
    QString dateh=QDateTime::currentDateTime().toString("dd/MM/yyyy");
    QString heureh=QDateTime::currentDateTime().toString("hh::mm");

    int num_res=ui->lineEdit_15->text().toInt();
    int duree=ui->lineEdit_7->text().toInt();
    int nombre=ui->lineEdit_5->text().toInt();
    QString id_c=ui->lineEdit->text();
    QString date=ui->lineEdit_4->text();
    QString id_b=ui->lineEdit_6->text();


    history h;
      h.addHISTORYAjout(num_res,"ajouter",dateh,heureh);

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


    QString dateh=QDateTime::currentDateTime().toString("dd/MM/yyyy");
    QString heureh=QDateTime::currentDateTime().toString("hh::mm");

        int num_res=ui->lineEdit_17->text().toInt();
        int duree=ui->lineEdit_9->text().toInt();
        int nombre =ui->lineEdit_10->text().toInt();
        QString id_c=ui->lineEdit_2->text();
        QString id_b=ui->lineEdit_14->text();
        QString date=ui->lineEdit_11->text();

        history h;
          h.addHISTORYAjout(num_res,"modifier",dateh,heureh);


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


           /*else if (id_c==NULL)
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





              }*/
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


void gestionreservation::on_pushButton_6_clicked() //button tri
{

      ui->afficher->setModel(R.tricroissant_nombre());
}

void gestionreservation::on_pushButton_7_clicked()
{
    ui->afficher->setModel(R.tricroissant_date());
}

void gestionreservation::on_pushButton_8_clicked()
{
    ui->afficher->setModel(R.tricroissant_duree());
}
                          ///////////////////////////recherche///////////////////////

void gestionreservation::on_pushButton_9_clicked()
{
    QString cls = ui->lineEdit_8->text();
          ui->afficher->setModel(R.recherche(cls));

}
                        ////////////////////////////stat//////////////////////////////////
void gestionreservation::on_pushButton_10_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from RESERVATION where NOMBRE_DE_PERSONNE < 2 ");
                       float nombre1=model->rowCount();
                       model->setQuery("select * from RESERVATION where NOMBRE_DE_PERSONNE  between 2 and 5 ");
                       float nombre2=model->rowCount();
                       model->setQuery("select * from RESERVATION where NOMBRE_DE_PERSONNE >12 ");
                       float nombre3=model->rowCount();
                       float total=nombre1+nombre2+nombre3;
                       QString a=QString("moins de 2 personnes "+QString::number((nombre1*100)/total,'f',2)+"%" );
                       QString b=QString("entre 2 et 5 personnes"+QString::number((nombre2*100)/total,'f',2)+"%" );
                       QString c=QString("+12 personnes"+QString::number((nombre3*100)/total,'f',2)+"%" );
                       QPieSeries *series = new QPieSeries();
                       series->append(a,nombre1);
                       series->append(b,nombre2);
                       series->append(c,nombre3);
               if (nombre1!=0)
               {QPieSlice *slice = series->slices().at(0);
                slice->setLabelVisible();
                slice->setPen(QPen());}
               if ( nombre2!=0)
               {
                        // Add label, explode and define brush for 2nd slice
                        QPieSlice *slice1 = series->slices().at(1);
                        //slice1->setExploded();
                        slice1->setLabelVisible();
               }
               if(nombre3!=0)
               {
                        // Add labels to rest of slices
                        QPieSlice *slice2 = series->slices().at(2);
                        //slice1->setExploded();
                        slice2->setLabelVisible();
               }
                       // Create the chart widget
                       QChart *chart = new QChart();
                       // Add data to chart with title and hide legend
                       chart->addSeries(series);
                       chart->setTitle("Pourcentage Par nombre :Nombre Des personnes "+ QString::number(total));
                       chart->legend()->hide();
                       // Used to display the chart
                       QChartView *chartView = new QChartView(chart);
                       chartView->setRenderHint(QPainter::Antialiasing);
                       chartView->resize(1000,500);
                       chartView->show();
}
                 ///////////////////////////////////history/////////////////////////////
void gestionreservation::on_pushButton_11_clicked()
{
  ui->afficher_3->setModel(H.afficherh());
}
