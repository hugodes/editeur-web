#include "headers/gui/apropos.h"
#include "ui_apropos.h"

aPropos::aPropos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aPropos)
{
    ui->setupUi(this);
    QPixmap *pixmap_img = new QPixmap("../editeur-web/image/leedit.png");
    ui->logo->setPixmap(*pixmap_img);
}

aPropos::~aPropos()
{
    delete ui;
}
