#include "leedit.h"
#include "ui_leedit.h"

LeEdit::LeEdit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LeEdit)
{
    ui->setupUi(this);

    QObject::connect(ui->actionDom, SIGNAL(triggered(bool)), this, SLOT(affichageDOM(bool)));
    QObject::connect(ui->actionHierarchie, SIGNAL(triggered(bool)), this, SLOT(affichageHIE(bool)));
    QObject::connect(ui->actionApercu, SIGNAL(triggered()), this, SLOT(affichageAPE()));

}

LeEdit::~LeEdit()
{
    delete ui;
}

void LeEdit::affichageDOM(bool visible) {
    if(!visible) {
        ui->dom->hide();
    }else{
        ui->dom->show();
    }
}

void LeEdit::affichageHIE(bool visible) {
    if(!visible) {
        ui->hierarchie->hide();
    }else{
        ui->hierarchie->show();
    }
}

void LeEdit::affichageAPE() {
    ui->onglets->setCurrentIndex(1);
}
