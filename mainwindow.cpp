#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <personnel.h>
#include <QIntValidator>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LEage->setValidator (new QIntValidator(0,60, this));
    ui->Tabperso->setModel(p.afficher());



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
     QString id=ui->LEid->text();
     QString nom=ui->LEnom->text();
     QString prenom=ui->LEprenom->text();
     int age=ui->LEage->text().toInt();
     QString titre=ui->LEtitre->text();
     QString date=ui->LEdate->text();





     personnel p(prenom,nom,id,titre,date,age);
bool test=p.ajouter();
 if(test)
 {    ui->Tabperso->setModel(p.afficher());
     QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("ajout effectue.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("not ok"),
                 QObject::tr("ajout non effectue.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_supp_clicked()
{
    QString id=ui->LEid1->text();
     bool test=p.supprimer(id);
     if (test)
     {
         ui->Tabperso->setModel(p.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                         QObject::tr("suppression failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pb_modif_clicked()
{

    QString id=ui->LEid->text();

    QString nom=ui->LEnom->text();
    QString prenom=ui->LEprenom->text();
    int age=ui->LEage->text().toInt();
    QString titre=ui->LEtitre->text();
    QString date=ui->LEdate->text();



   personnel p(prenom,nom,id,titre,date,age);



    bool test=p.modifier();

        if(test){
            ui->Tabperso->setModel(p.afficher());
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("modification effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("modification failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tri_age_emp_clicked()
{
    ui->Tabperso->setModel(p.afficher_tri_age());
}

void MainWindow::on_tri_nom_emp_clicked()
{
    ui->Tabperso->setModel(p.afficher_tri_nom());
}

void MainWindow::on_tri_prenom_emp_clicked()
{
    ui->Tabperso->setModel(p.afficher_tri_prenom());
}
/*void MainWindow::on_line_rech_emp_textChanged(const QString &arg1)
{
    if(ui->comboBox_rech_emp->currentText() == "nom" || ui->comboBox_rech_emp->currentText() == "age")
        ui->Tabperso->setModel(p.afficher_rech_emp(ui->comboBox_rech_emp->currentText(),ui->line_rech_emp->text()));
    if(ui->comboBox_rech_emp->currentText() == "salaire ou id")
        ui->Tabperso->setModel(p.afficher_rech_emp(ui->line_rech_emp->text().toInt()));
}*/
void MainWindow::on_Recherche_clicked()//Chercher
{
QString chercherbox=ui->chercherbox->currentText();

if (chercherbox == "defaut")
 {
 QString nom_recherche=ui->recherche->text();
 ui->Tabperso->setModel(p.recherchepardefaut(nom_recherche));
 }
else if(chercherbox == "id")
 {
 QString id_recherche=ui->recherche->text();
 ui->Tabperso->setModel(p.rechercheparid(id_recherche));
 }
else if (chercherbox == "titre")
 {
 QString titre_recherche=ui->recherche->text();
 ui->Tabperso->setModel(p.recherchepartitre(titre_recherche));
 }

}

void MainWindow::on_PDF_clicked()
{
    QSqlQuery query;
    //QString val = ui->label_pdf->text();
   // query.prepare("select * from joueurs where id='"+val+"'");
query.prepare("select * from PERSONNELS where IDPERSONNEL");
 p.telechargerPDF();
    if(query.exec()){

        while(query.next())
        {

         //B.telechargerPDF(val);
        ui->LEid->setText(query.value(0).toString());
        ui->LEnom->setText(query.value(1).toString());
        ui->LEprenom->setText(query.value(2).toString());
        ui->LEage->setText(query.value(3).toString());
        ui->LEtitre->setText(query.value(4).toString());
        ui->LEdate->setText(query.value(5).toString());

        QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



  }
    }
    else
        QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}
