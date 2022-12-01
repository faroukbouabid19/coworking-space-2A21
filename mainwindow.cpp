#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QDateTime>
#include <personnel.h>
#include <QIntValidator>
#include <QMessageBox>
#include <QPixmap>
#include <QTranslator>
#include <QInputDialog>
#include "arduino.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   ui->LEage->setValidator (new QIntValidator(0,60, this));
    ui->Tabperso->setModel(p.afficher());
    int ret=a.connect_arduino();
                switch(ret)
                {
                    case (0): qDebug() << "arduino is available and connected to : " << a.getarduino_port_name();
                    break;
                    case (1) :qDebug () << "arduino is available but not connected to :" << a.getarduino_port_name ();
                    break;
                    case (-1): qDebug() << "arduino is not available :" ;//<< a.getarduino_port_name ();
                    break;

                }

                   //QObject:: connect (a.getserial(),SIGNAL (readyRead()), this, SLOT (update_label ())); // permet de lancer //le slot update label suite à la reception du signal readyRead (reception des données).
                    QObject:: connect (a.getserial(),SIGNAL (readyRead()), this, SLOT ( chercherFromArduino()));



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





     personnel p(id,nom,prenom,age,titre,date);
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



   personnel p(id,nom,prenom,age,titre,date);



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

/*void MainWindow::on_btn_chat_emp_clicked()
{
    s = new ServerWindow(this);
    s->show();
    c = new ChatWindow(this);
    c->show();
}
*/
void MainWindow::on_signin_clicked()
{
    QString username_line = ui->line_username_signin->text();
    QString password_line = ui->line_password_signin->text();
    QString username,password;
    QSqlQuery q;

    q.prepare("select * from authentification where username=:username");
    q.bindValue(":username",username_line);
    q.exec();
    while(q.next())
    {
        username = q.value(0).toString();
        password =q.value(1).toString();
    }
    if(username == username_line && password != password_line)
        ui->statusbar->showMessage("password is incorrect");
    if(username != username_line)
        ui->statusbar->showMessage("username is incorrect");
    if(username == username_line && password == password_line && username_line != "" && password_line != "")
    {
        ui->stackedWidget->setCurrentIndex(1);
       // hide();
       /* QTranslator t;
        QApplication *A=qApp;
        QStringList languages;
        languages << "French" << "English";
        QString lang =QInputDialog::getItem(NULL,"Select a language","Language",languages);
        if(lang == "English")
            t.load(":/english.qm");
        if(lang != "French")
            A->installTranslator(&t);
         //ui = new person(this);
       // p1->show();

    }
*/
       // int index;
        //index =(index+1)%numStacked;

}
}
void MainWindow::on_signup_clicked()
{
    QSqlQuery q;
    QString username = ui->line_username_signup->text();
    QString password = ui->line_password_signup->text();
    if(ui->line_admin_password->text() == "123456")
    {
        q.prepare("insert into authentification(username,password) values(:username,:password)");
        q.bindValue(":username",username);
        q.bindValue(":password",password);
        if(q.exec()){
        ui->statusbar->showMessage("user added succesfully");
        ui->line_admin_password->clear();
        ui->line_username_signup->clear();
        ui->line_password_signup->clear();
        }else{
           ui->statusbar->showMessage("username already exists");
        }
    }else
    {
        ui->statusbar->showMessage("admin password is incorrect");
    }
}

QSqlQueryModel * MainWindow::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from authentification");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("username"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("password"));

    return model;
}
void MainWindow::on_remove_user_clicked()
{
    QSqlQuery q;
    QString username= ui->line_username_signup->text();

    q.prepare("Delete from authentification where username=:username");
    q.bindValue(":username",username);
    if(ui->line_admin_password->text() == "123456")
    {
        if(q.exec())
        {
        ui->statusbar->showMessage("user removed successfully");
        ui->line_admin_password->clear();
        ui->line_username_signup->clear();
        ui->line_password_signup->clear();
        }else
        {
        ui->statusbar->showMessage("user could not be removed. Not found in the database.");
        }
    }else
        ui->statusbar->showMessage("admin password is incorrect.");
}

void MainWindow::on_show_users_clicked()
{
    if(ui->line_admin_password->text() == "123456")
    {
        ui->users_table->setModel(afficher());
    }else
        ui->statusbar->showMessage("admin password is incorrect");
}

void MainWindow::on_modifier_user_clicked()
{
    QString username = ui->line_username_signup->text();
    QString password = ui->line_password_signup->text();
    QSqlQuery q;
    if(ui->line_admin_password->text() == "123456")
    {
        q.prepare("update authentification set password=:password where username=:username");
        q.bindValue(":password",password);
        q.bindValue(":username",username);
        if(q.exec())
        {
        ui->statusbar->showMessage("password modified successfully");
        ui->line_admin_password->clear();
        ui->line_username_signup->clear();
        ui->line_password_signup->clear();
        }else
        {
        ui->statusbar->showMessage("password could not be modified.Username not found in the database.");
        }
    }else
        ui->statusbar->showMessage("admin password is incorrect");
}


void MainWindow::on_stat_clicked()
{
    s = new statistique();

    s->setWindowTitle("Statistiques Bureaux");
    s->choix_bar();
    s->show();

}
void MainWindow::chercherFromArduino(){
QSqlQuery *query=new QSqlQuery;
query->prepare("SELECT * FROM BUREAUX WHERE NUMBUREAU like 'Bureau 3'");
query->exec();
while(query->next()){
    QString dispo=query->value(2).toString();
    QString bur=query->value(0).toString();


    if((dispo=="Non Disponible")&&(bur== "Bureau 3")){
   qDebug() << dispo;


        a.write_to_arduino("1");
}
    else if(dispo=="Disponible"){
        qDebug() << dispo;
        a.write_to_arduino("0");
    }
}
}

