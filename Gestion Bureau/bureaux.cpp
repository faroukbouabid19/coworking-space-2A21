#include "bureaux.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
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





