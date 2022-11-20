#ifndef RESRVATION_H
#define RESRVATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include <QDialog>





class Resrvation
{


public:
    Resrvation();
        Resrvation(int,int,int,QString,QString,QString);
        void setnum_res(int n);
        void setduree(int n);
        void setnombre(int n);
        void setid_c(QString n);
        void setdate(QString n);
        void setid_b(QString);

        int get_num_res();
        int get_duree();
        int get_nombre();
        QString get_id_c();
        QString get_date();
        QString get_id_b();

        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool modifier(int num_res,int duree, int nombre,QString id_c,QString date , QString id_b  );







private:

     int num_res,duree,nombre;
     QString date,id_c,id_b;
};

#endif // RESRVATION_H
