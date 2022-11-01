#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include <string>
#include <QtDebug>

using namespace std;
class personnel
{
    QString id,prenom,nom,titre,date;
int age ;
public:
    personnel();
     personnel(QString nom,QString date,QString id,QString titre ,QString prenom,int age);
     QString getnom(){return nom;}
     QString getid(){return id;}
     QString getprenom(){return prenom;}
     QString gettitre(){return titre;}
     QString getdate(){return date;}
     int getage(){return age;}


     //Les fonctions
     bool ajouter();
     QSqlQueryModel * afficher();
     bool modifier();
     bool supprimer(QString);
};

#endif // PERSONNEL_H
