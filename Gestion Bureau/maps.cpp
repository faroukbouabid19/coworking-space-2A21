#include "maps.h"
#include "ui_maps.h"

Maps::Maps(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Maps)
{
    ui->setupUi(this);
}

Maps::~Maps()
{
    delete ui;
}
