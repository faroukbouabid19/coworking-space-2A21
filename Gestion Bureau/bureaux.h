#ifndef BUREAUX_H
#define BUREAUX_H

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class Bureau
{

public:
    Bureau();
    Bureau(QString,QString,QString,QString);

    QString getnumbureau();
    QString getcapacitemax();
    QString getdisponibilite();
    QString gettypebureau();

    void setnumbureau(QString);
    void setcapacitemax(QString);
    void setdisponibilite(QString);
    void settypebureau(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();

    QSqlQueryModel * trieCapacite();
    QSqlQueryModel * trieNum();
    QSqlQueryModel * trieType();
    QSqlQueryModel * trieDisponibilite();

    void recherche(QTableView * table, QString);






private:

    QString numbureau,disponibilite,typebureau,capacitemax;
};


#endif // BUREAUX_H
