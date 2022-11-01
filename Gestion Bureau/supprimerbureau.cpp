#include "supprimerbureau.h"
#include "ui_supprimerbureau.h"

SupprimerBureau::SupprimerBureau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupprimerBureau)
{
    ui->setupUi(this);
}

SupprimerBureau::~SupprimerBureau()
{
    delete ui;
}
