#ifndef BUREAUX_H
#define BUREAUX_H

#include <QString>
#include<QSqlQueryModel>

class Bureau
{
public:
    Bureau();
    Bureau(QString,int,QString,QString);

    QString getnumbureau();
    int getcapacitemax();
    QString getdisponibilite();
    QString gettypebureau();

    void setnumbureau(QString);
    void setcapacitemax(int);
    void setdisponibilite(QString);
    void settypebureau(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();




private:
    int capacitemax;
    QString numbureau,disponibilite,typebureau;
};


#endif // BUREAUX_H
