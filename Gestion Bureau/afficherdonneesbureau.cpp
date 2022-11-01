#include "afficherdonneesbureau.h"
#include "ui_afficherdonneesbureau.h"

AfficherDonneesBureau::AfficherDonneesBureau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherDonneesBureau)
{
    ui->setupUi(this);
}

AfficherDonneesBureau::~AfficherDonneesBureau()
{
    delete ui;
}
