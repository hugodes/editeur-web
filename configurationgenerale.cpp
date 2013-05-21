#include "configurationgenerale.h"
#include "ui_configurationgenerale.h"

#include <string.h>
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QMessageBox>
#include <QtWidgets>
#include <leedit.h>

configurationGenerale::configurationGenerale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configurationGenerale)
{
    hie=true;
    ecran=true;
    dom=true;
    indent=true;

    ui->setupUi(this);
    getOption();

    if (dom==true){
        ui->optionDom->setCheckState(Qt::Checked);
    }else{
        ui->optionDom->setCheckState(Qt::Unchecked);
    }
    if (hie==true){
        ui->optionHie->setCheckState(Qt::Checked);
    }else{
        ui->optionHie->setCheckState(Qt::Unchecked);
    }
    if (ecran==true){
        ui->optionEcran->setCheckState(Qt::Checked);
    }else{
        ui->optionEcran->setCheckState(Qt::Unchecked);
    }
    if (indent==true){
        ui->optionIndent->setCheckState(Qt::Checked);
    }else{
        ui->optionIndent->setCheckState(Qt::Unchecked);
    }



    QObject::connect(ui->optionHie, SIGNAL(clicked(bool)), this, SLOT(modifierHie(bool)));
    QObject::connect(ui->optionEcran, SIGNAL(clicked(bool)), this, SLOT(modifierEcran(bool)));
    QObject::connect(ui->optionDom, SIGNAL(clicked(bool)), this, SLOT(modifierDom(bool)));
    QObject::connect(ui->optionIndent, SIGNAL(clicked(bool)), this, SLOT(modifierIndent(bool)));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

configurationGenerale::~configurationGenerale()
{
    delete ui;

}

void configurationGenerale::getOption() {
    ifstream fichier("../editeur-web/principal.conf");
    string ligne;
    if(fichier) {
        while(getline(fichier,ligne)) {
            string nom;
            string val;
            istringstream iss (ligne);
            iss >> nom >> val ;
            if (nom=="hie") {
                if (val=="oui") {
                    hie=true;
                } else {
                    hie=false;
                }
            }
            if (nom=="ecran"){
                if (val=="oui") {
                    ecran=true;
                } else {
                    ecran=false;
                }
            }
            if (nom=="dom") {
                if (val=="oui") {
                    dom=true;
                } else {
                    dom=false;
                }
            }
            if (nom=="indent") {
                if (val=="oui") {
                    indent=true;
                } else {
                    indent=false;
                }
            }
        }
        fichier.close();
    }
    else {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier de configuration !");
    }
}

void configurationGenerale::modifierHie(bool val) {
    this->modifierVal("hie",val);
    this->hie=val;
}

void configurationGenerale::modifierDom(bool val) {
    this->modifierVal("dom",val);
    this->dom=val;
}

void configurationGenerale::modifierEcran(bool val) {
    this->modifierVal("ecran",val);
    this->ecran=val;
}

void configurationGenerale::modifierIndent(bool val) {
    this->modifierVal("indent",val);
    this->indent=val;
}

bool configurationGenerale::getIndent(){
    return indent;
}

bool configurationGenerale::getDom(){
    return dom;
}

bool configurationGenerale::getHie(){
    return hie;
}

bool configurationGenerale::getEcran(){
    return ecran;
}

void configurationGenerale::modifierVal(string option, bool val)
{
        string nouVal;
        if (val==true){
            nouVal="oui" ;
        } else {
            nouVal="non";
        }
        ifstream fichier("../editeur-web/principal.conf");
        string ligne;
        if(fichier) {
            string buffer = "";
            while(getline(fichier,ligne)) {
                string nom;
                string valeur;
                istringstream iss (ligne);
                iss >> nom >> valeur ;
                if (option==nom){
                    buffer += nom +" " +nouVal +"\n";
                } else {
                    buffer += ligne + "\n";
                }
            }
            fichier.close();
            ofstream fichierOut ("../editeur-web/principal.conf");
            fichierOut << buffer;
            fichierOut.close();
        }
        else {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier de configuration !");
        }
}
