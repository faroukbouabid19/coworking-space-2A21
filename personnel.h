#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QDateTime>


class personnel
{

public:
     personnel();
     personnel(QString id,QString nom,QString prenom, int age, QString titre , QString date);

    QString getid();
    int getage();
    QString getprenom();
    QString getdate();


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();
   // bool rechercher();

    QSqlQueryModel * afficher_tri_age();
    QSqlQueryModel * afficher_tri_prenom();
    QSqlQueryModel * afficher_tri_nom();
    //QSqlQueryModel * afficher_rech_emp(QString critere,QString val);
    //QSqlQueryModel * afficher_rech_emp(int val);

    QSqlQueryModel* recherchepardefaut(QString);
         QSqlQueryModel* rechercheparid(QString);
         QSqlQueryModel* recherchepartitre(QString);
         void  telechargerPDF();



private:
    int age;
    QString nom,prenom,date,titre,id;


};


#endif // PERSONNEL
