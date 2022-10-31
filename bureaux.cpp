#include "bureaux.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
Bureau::Bureau()
{
    capacitemax=0;
numbureau=" ";disponibilite=" ",typebureau=" ";
}

Bureau::Bureau(QString numbureau,int capacitemax,QString disponibilite,QString typebureau)
{this->numbureau=numbureau;this->capacitemax=capacitemax,this->disponibilite=disponibilite;this->typebureau=typebureau;}
QString Bureau::getnumbureau(){return numbureau;}
int Bureau::getcapacitemax(){return capacitemax;}
QString Bureau::getdisponibilite(){return disponibilite;}
QString Bureau::gettypebureau(){return typebureau;}

void Bureau::setnumbureau(QString numbureau){this->numbureau=numbureau;}
void Bureau::setcapacitemax(int capacitemax){this->capacitemax=capacitemax;}
void Bureau::setdisponibilite(QString disponibilite){this->disponibilite=disponibilite;}
void Bureau::settypebureau(QString typebureau){this->typebureau=typebureau;}
bool Bureau::ajouter()
{
            QSqlQuery query;

                 query.prepare("INSERT INTO bureau (numbureau,capacitemax,disponibilite,typebureau) "
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
     query.prepare("Delete from bureau where numbureau=:numbureau");
     query.bindValue(":numbureau",numbureau);

return   query.exec();

}

QSqlQueryModel* Bureau::afficher()
{
      QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM bureau");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Numero Bureau"));
    model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Capacite Max"));
    model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Disponibilite"));
    model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Type Bureau"));


    return  model;
}
bool Bureau ::modifier()
{
                       QSqlQuery query;


    query.prepare("UPDATE bureau SET numbureau=:numbureau,capacitemax=:capacitemax,disponibilite=:disponibilite,typebureau=:typebureau WHERE numbureau=:numbureau ");

    query.bindValue(":numbureau", numbureau);
    query.bindValue(":capacitemax", capacitemax);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":typebureau", typebureau);

                     return query.exec();}




