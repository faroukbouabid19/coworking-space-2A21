#ifndef SUPPRIMERBUREAU_H
#define SUPPRIMERBUREAU_H

#include <QDialog>

namespace Ui {
class SupprimerBureau;
}

class SupprimerBureau : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerBureau(QWidget *parent = nullptr);
    ~SupprimerBureau();

private:
    Ui::SupprimerBureau *ui;
};

#endif // SUPPRIMERBUREAU_H
