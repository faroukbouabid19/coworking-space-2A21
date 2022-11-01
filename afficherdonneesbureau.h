#ifndef AFFICHERDONNEESBUREAU_H
#define AFFICHERDONNEESBUREAU_H

#include <QDialog>

namespace Ui {
class AfficherDonneesBureau;
}

class AfficherDonneesBureau : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherDonneesBureau(QWidget *parent = nullptr);
    ~AfficherDonneesBureau();

private:
    Ui::AfficherDonneesBureau *ui;
};

#endif // AFFICHERDONNEESBUREAU_H
