#include "headers/gui/affichageligne.h"
#include<QMessageBox>
#include<string>
#include <headers/gui/editeur.h>

affichageLigne::affichageLigne(QWidget *parent) : QPlainTextEdit(parent){
    this->setMaximumWidth(60);
    this->setReadOnly(true);
    this->textInteractionFlags();
    //QAbstractScrollArea::setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
}

void affichageLigne::genererLigne(int nombreLigne) {
    QString resultat = "";
    for(int i=1; i<=nombreLigne; i++) {
        QString ajout = QString::number(i)  + ".\n";
        resultat = resultat + ajout;
    }
    this->clear();
    this->setPlainText(resultat);
}
