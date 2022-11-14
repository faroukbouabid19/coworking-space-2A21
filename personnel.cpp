#include "personnel.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QPdfWriter>
#include <QPainter>
personnel::personnel()
{
age=0;nom="" ;id="";titre="";date=""; prenom="" ;
}
personnel::personnel(QString id,QString nom,QString prenom,int age,QString titre ,QString date)
{
this->id=id;
this->nom=nom;
this->prenom=prenom;
this->age=age;
this->titre=titre;
this->date=date;

}

bool personnel::ajouter()
{

    QSqlQuery query;
  QString age_string=QString::number(age);

          query.prepare("INSERT INTO PERSONNELS (IDPERSONNEL,NOMPERSONNEL,PRENOMPERSONNEL,AGEPERSONNEL,TITREPROFESSIONNEL,DATEEMBAUCHE) "
                        "VALUES (:IDPERSONNEL, :NOMPERSONNEL ,:PRENOMPERSONNEL ,:AGEPERSONNEL ,:TITREPROFESSIONNEL ,:DATEEMBAUCHE)");
query.bindValue(":IDPERSONNEL", id);
  query.bindValue(":NOMPERSONNEL", nom);
query.bindValue(":PRENOMPERSONNEL", prenom);

            query.bindValue(":AGEPERSONNEL", age_string);
          query.bindValue(":TITREPROFESSIONNEL", titre);
          query.bindValue(":DATEEMBAUCHE", date);

          return query.exec();
}
QSqlQueryModel* personnel::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM PERSONNELS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPERSONNEL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGEPERSONNEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TITREPROFESSIONNEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    return model;
}
bool personnel::supprimer(QString id)
{
     QSqlQuery query;
     query.prepare("Delete from PERSONNELS where IDPERSONNEL=:IDPERSONNEL");
     query.bindValue(":IDPERSONNEL", id);

return   query.exec();

}
bool personnel ::modifier()
{
                       QSqlQuery query;
                        QString age_string=QString ::number (age);
    query.prepare("UPDATE PERSONNELS SET IDPERSONNEL=:IDPERSONNEL,NOMPERSONNEL=:NOMPERSONNEL,PRENOMPERSONNEL=:PRENOMPERSONNEL,AGEPERSONNEL=:AGEPERSONNEL,TITREPROFESSIONNEL=:TITREPROFESSIONNEL,DATEEMBAUCHE=:DATEEMBAUCHE WHERE IDPERSONNEL=:IDPERSONNEL");
                         query.bindValue(":IDPERSONNEL", id);
                         query.bindValue(":NOMPERSONNEL", nom);
                         query.bindValue(":PRENOMPERSONNEL", prenom);
                         query.bindValue(":AGEPERSONNEL",age_string);
                         query.bindValue(":TITREPROFESSIONNEL", titre);
                         query.bindValue(":DATEEMBAUCHE", date);

                     return query.exec();}

QSqlQueryModel * personnel::afficher_tri_age()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PERSONNELS order by AGEPERSONNEL");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));

    return model;
}

QSqlQueryModel * personnel::afficher_tri_prenom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PERSONNELS order by PRENOMPERSONNEL");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));

    return model;
}

QSqlQueryModel * personnel::afficher_tri_nom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PERSONNELS order by NOMPERSONNEL");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));

    return model;
}
QSqlQueryModel* personnel::recherchepardefaut(QString nom_recherche)
{
QSqlQueryModel *model = new QSqlQueryModel();
model->setQuery("SELECT* FROM PERSONNELS where NOMPERSONNEL like '"+nom_recherche+"%'");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));

return model;
}

QSqlQueryModel* personnel::rechercheparid(QString id_recherche)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM PERSONNELS where IDPERSONNEL like '"+id_recherche+"%'");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));
    return model;
}
QSqlQueryModel* personnel::recherchepartitre(QString titre_recherche)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM PERSONNELS where TITREPROFESSIONNEL like '"+titre_recherche+"%'");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));

    return model;

}


/*QSqlQueryModel * personnel::afficher_rech_emp(QString critere,QString val)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(critere == "nom")
       model->setQuery("select * from PERSONNELS where NOMPERSONNEL like '%"+val+"%'");
    if(critere == "titre")
       model->setQuery("select * from PERSONNELS where TITREPROFESSIONNEL like '%"+val+"%'");
if(critere == "id")
     model->setQuery("select * from PERSONNELS where IDPERSONNEL like '%"+val+"%'");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEEMBAUCHE"));

    return model;
}

QSqlQueryModel * personnel::afficher_rech_emp(int val)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(val);

       model->setQuery("select * from PERSONNELS where AGEPERSONNEL like '%"+res+"%");

       model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDPERSONNEL"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMPERSONNEL"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMPERSONNEL"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGEPERSONNEL"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("TITREPROFESSIONNEL"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATEEMBAUCHE"));

    return model;*/

void  personnel::telechargerPDF(){


                    QPdfWriter pdf("C:/Users/bouab/Desktop/PDF.pdf");

                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(1200,1700,"LISTES DES PERSONNELS");
                          painter.setPen(Qt::gray);
                          painter.setFont(QFont("Arial",20));
                          painter.drawRect(100,100,9250,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial",9));
                          painter.drawText(2000,3300,"id");
                          painter.drawText(3000,3300,"nom");
                          painter.drawText(4000,3300,"prenom");
                          painter.drawText(5000,3300,"age");
                          painter.drawText(6000,3300,"titre");
                          painter.drawText(7000,3300,"date");


                          QSqlQuery query;
                          query.prepare("select * from PERSONNELS");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(2000,i,query.value(0).toString());
                              painter.drawText(3000,i,query.value(1).toString());
                              painter.drawText(4000,i,query.value(2).toString());
                              painter.drawText(5000,i,query.value(3).toString());
                              painter.drawText(6000,i,query.value(4).toString());
                              painter.drawText(7000,i,query.value(5).toString());


                             i = i + 500;
                          }}


