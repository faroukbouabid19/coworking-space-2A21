#include "images.h"
#include "ui_images.h"
#include "bureaux.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPagedPaintDevice>
#include<QPixmap>
#include<QString>
#include<QSqlQuery>
#include<QPainter>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QSqlDatabase>


Images::Images(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Images)
{
    ui->setupUi(this);
}

Images::~Images()
{
    delete ui;
}

void Images::on_images_clicked()
{
    QString num_bureau = ui->LENum->text();


                    QSqlQuery query;
                    query.prepare("select * from bureaux where numbureau='"+num_bureau+"'");

                    if(query.exec()){

                        while(query.next())
                        { ui->textEdit->setText(query.value(3).toString());


                            if  (ui->textEdit->toPlainText()== "Architecture")
                                        {ui->label_2->clear();

                                  QPixmap pix("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Images Bureaux/Bureau 1.png");
                                 int w = ui->label_2->width();
                                 int h = ui->label_2->height();
                                  ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
                                         }
                            else if(ui->textEdit->toPlainText()=="Informatique")
                              { ui->label_2->clear();
                                  QPixmap pix("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Images Bureaux/Bureau 2.jpg");
                                  int w = ui->label_2->width();
                                  int h = ui->label_2->height();
                                   ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                              }
                              else if(ui->textEdit->toPlainText()=="Autres")
                                 {ui->label_2->clear();
                                      QPixmap pix("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Images Bureaux/Bureau 3.png");
                                     int w = ui->label_2->width();
                                     int h = ui->label_2->height();
                                      ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

                                 }
                              else if(ui->textEdit->toPlainText()=="Autres")
                                 {ui->label_2->clear();
                                      QPixmap pix("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Images Bureaux/Bureau 4.jpeg");
                                     int w = ui->label_2->width();
                                     int h = ui->label_2->height();
                                      ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Autres")
                                 {ui->label_2->clear();
                                      QPixmap pix("C:/Users/MSI/OneDrive/Documents/Esprit 2/Projet/Images Bureaux/Bureau 5.jpg");
                                     int w = ui->label_2->width();
                                     int h = ui->label_2->height();
                                      ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }



                          }
}
}
