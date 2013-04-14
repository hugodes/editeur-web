/**
 * \file leedit.cpp
 * \brief classe de l'interface graphique
 * \author Bryan Libourel
 * \version 0.2
 * \date 12 avril 2013
 *
 * Interface graphique de l'éditeur de texte
 *
 */

#include "leedit.h"
#include "ui_leedit.h"

LeEdit::LeEdit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LeEdit)
{
    ui->setupUi(this);

    QObject::connect(ui->actionDom, SIGNAL(triggered(bool)), this, SLOT(affichageDOM(bool)));
    QObject::connect(ui->actionHierarchie, SIGNAL(triggered(bool)), this, SLOT(affichageHIE(bool)));
    QObject::connect(ui->onglets, SIGNAL(currentChanged(int)), this, SLOT(affichageWID(int)));
    QObject::connect(ui->actionApercu, SIGNAL(triggered()), this, SLOT(affichageAPE()));
    QObject::connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(boiteOuvrir()));
    QObject::connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(modificationHIE()));
    QObject::connect(ui->actionNouveau, SIGNAL(triggered()), this, SLOT(nouveauFichier()));


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

void LeEdit::affichageWID(int i) {
    if(i == 1) {
        ui->apercu->setHtml(ui->code->toPlainText());
    }
}

void LeEdit::boiteOuvrir() {
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", "C:\\", "Fichier web (*.css *.js *.html *.php),*.css;*.js;*.html;*.php");
    QDir chemin = QFileInfo(fichier).absoluteDir();
    cheminFichier = chemin.absolutePath();
    //QMessageBox::information(this, "Fichier", "Vous avez sélectionné :"+cheminFichier+"\n");
    buff = new Buffer(fichier.toLatin1().data());
    //QMessageBox::information(this, "Fichier", buff);
    //ui->code->setText(buf.affiche(););
}

void LeEdit::nouveauFichier() {
    buff = new Buffer();
}

void LeEdit::modificationHIE() {
        QFileSystemModel *dirModele= new QFileSystemModel;
        dirModele->setRootPath(cheminFichier);

        ui->hierarchie->setModel(dirModele);
        ui->hierarchie->expandAll();
        ui->hierarchie->setColumnWidth(0,ui->hierarchie->width());

}
