#include "personnel.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QObject>
personnel::personnel()
{
age=0;nom="" ;id="";titre="";date=""; prenom="" ;
}
personnel::personnel(QString nom,QString date,QString id,QString titre ,QString prenom,int age)
{
this->nom=nom;
this->age=age;
this->date=date;
this->id=id;
this->titre=titre;
this->prenom=prenom;

}

bool personnel::ajouter()
{

    QSqlQuery query;
  QString age_string=QString::number(age);

          query.prepare("INSERT INTO PERSONNELS (prenom,nom,id,titre,date,age) "
                        "VALUES (:prenom, :nom ,:id ,:titre ,:date ,:age)");
          query.bindValue(":prenom", prenom);
          query.bindValue(":nom", nom);
          query.bindValue(":id", id);
          query.bindValue(":titre", titre);
          query.bindValue("date", date);
          query.bindValue("age", age_string);
          return query.exec();
}
QSqlQueryModel* personnel::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM PERSONNELS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date"));
    return model;
}
bool personnel::supprimer(QString id)
{
     QSqlQuery query;
     query.prepare("Delete from PERSONNELS where id=:id");
     query.bindValue(":id", id);

return   query.exec();

}
bool personnel ::modifier()
{
                       QSqlQuery query;
                        QString age_string=QString ::number (age);
    query.prepare("UPDATE PERSONNELS SET id=:id,nom=:nom,prenom=:prenom,age=:age,titre=:titre,date=:date");
                         query.bindValue(":age",age_string);
                         query.bindValue(":nom", nom);
                         query.bindValue(":prenom", prenom);
                         query.bindValue(":id", id);
                         query.bindValue(":titre", titre);
                         query.bindValue(":date", date);

                     return query.exec();}
