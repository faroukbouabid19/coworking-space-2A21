#include "bureaux.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QPdfWriter>
#include <QPainter>
#include <QDate>
#include <QIntValidator>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QDesktopServices>
#include <QUrl>



Bureau::Bureau()
{

numbureau=" ";disponibilite=" ",typebureau=" ",capacitemax=" ";
}

Bureau::Bureau(QString numbureau,QString capacitemax,QString disponibilite,QString typebureau)
{this->numbureau=numbureau;this->capacitemax=capacitemax,this->disponibilite=disponibilite;this->typebureau=typebureau;}
QString Bureau::getnumbureau(){return numbureau;}
QString Bureau::getcapacitemax(){return capacitemax;}
QString Bureau::getdisponibilite(){return disponibilite;}
QString Bureau::gettypebureau(){return typebureau;}

void Bureau::setnumbureau(QString numbureau){this->numbureau=numbureau;}
void Bureau::setcapacitemax(QString capacitemax){this->capacitemax=capacitemax;}
void Bureau::setdisponibilite(QString disponibilite){this->disponibilite=disponibilite;}
void Bureau::settypebureau(QString typebureau){this->typebureau=typebureau;}
bool Bureau::ajouter()
{
            QSqlQuery query;



                 query.prepare("INSERT INTO bureaux (numbureau,capacitemax,disponibilite,typebureau) "
                               "VALUES (:numbureau, :capacitemax, :disponibilite,:typebureau)");
                 query.bindValue(":numbureau", numbureau);
                 query.bindValue(":capacitemax", capacitemax);
                 query.bindValue(":disponibilite", disponibilite);
                 query.bindValue(":typebureau", typebureau);



    return   query.exec();
}
bool Bureau::supprimer(QString numbureau)
{
     QSqlQuery query;
     query.prepare("Delete from bureaux where numbureau=:numbureau");
     query.bindValue(":numbureau",numbureau);

return   query.exec();

}

QSqlQueryModel* Bureau::afficher()
{
      QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM bureaux");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Numero Bureau"));
    model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Capacite Max"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Disponibilite"));
    model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Type Bureau"));


    return  model;
}
bool Bureau ::modifier()
{
                       QSqlQuery query;


    query.prepare("UPDATE bureaux SET numbureau=:numbureau,capacitemax=:capacitemax,disponibilite=:disponibilite,typebureau=:typebureau WHERE numbureau=:numbureau ");

    query.bindValue(":numbureau", numbureau);
    query.bindValue(":capacitemax", capacitemax);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":typebureau", typebureau);

                     return query.exec();}


QSqlQueryModel * Bureau::trieCapacite()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM BUREAUX ORDER BY CAPACITEMAX");
            model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Numero Bureau"));
            model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Capacite Max"));
            model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Disponibilite"));
            model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Type Bureau"));
            return model;
        }
        QSqlQueryModel * Bureau::trieNum()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM BUREAUX ORDER BY NUMBUREAU");
            model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Numero Bureau"));
            model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Capacite Max"));
            model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Disponibilite"));
            model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Type Bureau"));
            return model;
        }
        QSqlQueryModel * Bureau::trieType()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM BUREAUX ORDER BY TYPEBUREAU");
            model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Numero Bureau"));
            model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Capacite Max"));
            model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Disponibilite"));
            model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Type Bureau"));
            return model;
        }

        QSqlQueryModel * Bureau::trieDisponibilite()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM BUREAUX ORDER BY DISPONIBILITE");
            model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Numero Bureau"));
            model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Capacite Max"));
            model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Disponibilite"));
            model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Type Bureau"));
            return model;
        }

        void Bureau::recherche(QTableView * table, QString rech)
        {
            QSqlQueryModel *model= new QSqlQueryModel();

                QSqlQuery *query=new QSqlQuery;
                query->prepare("select * from Bureaux where numbureau like '%"+rech+"%' or typebureau like '%"+rech+"%' or disponibilite like '%"+rech+"%'or capacitemax like '%"+rech+"%';");
                query->exec();
                model->setQuery(*query);
                table->setModel(model);
                table->show();
        }


        void  Bureau::telechargerPDF(){



                            QPdfWriter pdf("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Export PDF/PDF.pdf");


                              QPainter painter(&pdf);
                             int i = 3500;

                                  QPixmap pixmapl("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/logoprojet4.png");
                                  QPixmap pixmapl2("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/logoesprit.png");

                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Century Gothic", 30,QFont::Bold));
                                  painter.drawText(2900,1400,"Liste des bureaux");
                                  painter.setPen(Qt::black);
                                  painter.drawLine(500,3000,9000,3000);
                                  painter.drawLine(3000,2500,3000,12000);
                                  painter.drawLine(5000,2500,5000,12000);
                                  painter.drawLine(7000,2500,7000,12000);
                                  painter.setFont(QFont("Calibri",14,QFont::Bold));
                                  painter.drawText(1000,2800,"Numéro Bureau");
                                  painter.drawText(3300,2800,"Capacité MAX");
                                  painter.drawText(5300,2800,"Disponibilité");
                                  painter.drawText(7300,2800,"Type Bureau");
                                  painter.drawPixmap(100,100,1600,500, pixmapl);
                                  painter.drawPixmap(7900,140,1500,500, pixmapl2);

                                  QString s = QDate::currentDate().toString();

                                  painter.setFont(QFont("Arial",10));

                                   painter.drawText(4200,1700,s);

                                  QSqlQuery query;
                                  query.prepare("select * from bureaux");
                                  query.exec();
                                  while (query.next())
                                  {
                                      painter.setFont(QFont("Calibri",14));
                                      painter.drawText(1200,i,query.value(0).toString());
                                      painter.drawText(3400,i,query.value(1).toString());
                                      painter.drawText(5300,i,query.value(2).toString());
                                      painter.drawText(7500,i,query.value(3).toString());


                                     i = i + 500;
                                  }


                                          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Export PDF/PDF.pdf"));

        }


