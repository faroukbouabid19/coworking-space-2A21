#ifndef AJOUTBUREAU_H
#define AJOUTBUREAU_H

#include <QDialog>

namespace Ui {
class AjoutBureau;
}

class AjoutBureau : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutBureau(QWidget *parent = nullptr);
    ~AjoutBureau();

private:
    Ui::AjoutBureau *ui;
};

#endif // AJOUTBUREAU_H
