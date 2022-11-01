#include "ajouterbureau.h"
#include "ui_ajoutbureau.h"

AjoutBureau::AjoutBureau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutBureau)
{
    ui->setupUi(this);
}

AjoutBureau::~AjoutBureau()
{
    delete ui;
}
