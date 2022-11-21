#include "resrvation.h"
#include "ui_resrvation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QString>
#include <QMessageBox>
#include <QDate>
#include <QObject>


Resrvation::Resrvation()
{
    num_res=0;
    duree=0;
    nombre=0;
    id_c="";
    date="";
    id_b="";


}


Resrvation::Resrvation(int num_res,int duree,int nombre,QString id_c,QString date,QString id_b)

{   this->num_res=num_res;
    this->duree=duree;
    this->nombre=nombre;
    this->id_c=id_c;
    this->date=date;
    this->id_b=id_b;


}


void Resrvation::setnum_res(int n)
{
    num_res = n;
}
void Resrvation::setduree(int n)
{
    duree = n;
}
void Resrvation::setnombre(int n)
{
    nombre = n;
}
void Resrvation::setid_c(QString n)
{
    id_c = n;
}
void Resrvation::setdate(QString n)
{
    date = n;
  }
void Resrvation::setid_b(QString n)
{
    id_b = n;
}




int Resrvation::get_num_res()
{
    return num_res;
}

int Resrvation::get_duree()
{return duree;}
int Resrvation::get_nombre()
{return nombre;}

QString Resrvation::get_id_c()
{return id_c;}

QString Resrvation::get_date()
{return date;}

QString Resrvation::get_id_b()
{return id_b ;}







bool Resrvation::ajouter()
{
    QSqlQuery query;

    QString res= QString::number(num_res);
    QString dur=QString::number(duree);
    QString num=QString::number(nombre);

    query.prepare("INSERT INTO RESERVATION (NUM_RESERVATION,DUREE,NOMBRE_DE_PERSONNE,CLIENTID,DATE_RESERVATION,NUMBUREAU)""VALUES(:num_res,:duree,:nombre,:id_c,:date,:id_b)");

query.bindValue(":num_res",res);
query.bindValue(":duree",dur);
query.bindValue(":nombre",num);
query.bindValue(":id_c",id_c);
query.bindValue(":date",date);
query.bindValue(":id_b",id_b);



return query.exec();//envoie la requette pour l'executer


}

QSqlQueryModel* Resrvation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM RESERVATION");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_res"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_c"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_b"));


    return model;
}



bool Resrvation::supprimer(int num_res)
{
    QSqlQuery query;
    QString res=QString::number(num_res);
    query.prepare("DELETE FROM RESERVATION WHERE NUM_RESERVATION=:num_res");
    //query.bindValue(":num_res",res);
 query.bindValue(0,res);
return query.exec();
}


bool Resrvation::modifier(int num_res,int duree,int nombre,QString id_c,QString date,QString id_b )
{
    QSqlQuery query;
    //QString id= QString::number(id_am);

    query.prepare("UPDATE RESERVATION SET DUREE=:duree,NOMBRE_DE_PERSONNE=:nombre,CLIENTID=:id_c,DATE_RESERVATION=:date,NUMBUREAU=:id_b, WHERE NUM_RESERVATION=:num_res");
    query.bindValue(":num_res",num_res);
    query.bindValue(":duree",duree);
    query.bindValue(":nombre",nombre);
    query.bindValue(":id_c",id_c);
    query.bindValue(":date",date);
    query.bindValue(":id_b",id_b);




    return query.exec();
}


QSqlQueryModel * Resrvation::tricroissant_nombre()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM RESERVATION ORDER BY NOMBRE_DE_PERSONNE ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_res"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_c"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_b"));


    return model;
}

QSqlQueryModel * Resrvation::tricroissant_date()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM RESERVATION ORDER BY DATE_RESERVATION ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_res"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_c"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_b"));


    return model;
}

QSqlQueryModel * Resrvation::tricroissant_duree()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM RESERVATION ORDER BY DATE_RESERVATION ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_res"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_c"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_b"));


    return model;
}


QSqlQueryModel * Resrvation::recherche(QString cls)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM RESERVATION WHERE NUM_RESERVATION LIKE '%"+cls+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_res"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_c"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_b"));

return model;
}



