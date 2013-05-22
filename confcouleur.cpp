/*!
 * \file confcouleur.cpp
 * \brief Fichier de la classe de configuration des couleurs
 * \author Nicolas Emeri
 * \version 0.1
 */

#include "confcouleur.h"
#include "ui_confcouleur.h"
#include "string.h"
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>

confCouleur::confCouleur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confCouleur)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_balise, SIGNAL(clicked()), this, SLOT(modifierBalise()));
    QObject::connect(ui->pushButton_doctype, SIGNAL(clicked()), this, SLOT(modifierDoctype()));
    QObject::connect(ui->pushButton_php, SIGNAL(clicked()), this, SLOT(modifierPhp()));
    QObject::connect(ui->pushButton_motscles, SIGNAL(clicked()), this, SLOT(modifierMotscles()));
    QObject::connect(ui->pushButton_fonction, SIGNAL(clicked()), this, SLOT(modifierFonction()));
    QObject::connect(ui->pushButton_string, SIGNAL(clicked()), this, SLOT(modifierString()));
    QObject::connect(ui->pushButton_attribut, SIGNAL(clicked()), this, SLOT(modifierAttribut()));
    QObject::connect(ui->pushButton_commentaire, SIGNAL(clicked()), this, SLOT(modifierCommentaire()));
    QObject::connect(ui->pushButton_texte, SIGNAL(clicked()), this, SLOT(modifierTexte()));

    this->afficheCouleurs();
}

void confCouleur::afficheCouleurs(){
    ifstream fichier("../editeur-web/couleur.conf");
    string ligne;
    if(fichier) {
        while(getline(fichier,ligne)) {
            string nom;
            string val;
            string couleur;
            istringstream iss (ligne);
            iss >> nom >> val >> couleur ;
            int valeur = atoi(val.c_str());
            switch (valeur)
            {
                case 320 : {ui->lineEdit_balise->setText(QString(couleur.c_str()));break;}
                case 321 : {ui->lineEdit_doctype->setText(QString(couleur.c_str()));break;}
                case 322 : {ui->lineEdit_php->setText(QString(couleur.c_str()));break;}
                case 323 : {ui->lineEdit_motscles->setText(QString(couleur.c_str()));break;}
                case 324 : {ui->lineEdit_fonctions->setText(QString(couleur.c_str()));break;}
                case 326 : {ui->lineEdit_caractere->setText(QString(couleur.c_str()));break;}
                case 327 : {ui->lineEdit_attributs->setText(QString(couleur.c_str()));break;}
                case 334 : {ui->lineEdit_commentaire->setText(QString(couleur.c_str()));break;}
                case 333 : {ui->lineEdit_texte->setText(QString(couleur.c_str()));break;}
            }
        }
        fichier.close();
    }
    else {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier de configuration !");
    }


}

void confCouleur::modifierBalise()
{
    this->modifierConf(320,ui->lineEdit_balise->text());
    this->modifierConf(325,ui->lineEdit_balise->text());
    this->modifierConf(331,ui->lineEdit_balise->text());
    this->modifierConf(332,ui->lineEdit_balise->text());
}

void confCouleur::modifierDoctype()
{
    this->modifierConf(321,ui->lineEdit_doctype->text());
}

void confCouleur::modifierPhp()
{
    this->modifierConf(322,ui->lineEdit_php->text());
}

void confCouleur::modifierMotscles()
{
    this->modifierConf(323,ui->lineEdit_motscles->text());
}

void confCouleur::modifierFonction()
{
    this->modifierConf(324,ui->lineEdit_fonctions->text());
}

void confCouleur::modifierString()
{
    this->modifierConf(326,ui->lineEdit_caractere->text());
}

void confCouleur::modifierAttribut()
{
    this->modifierConf(327,ui->lineEdit_attributs->text());
}

void confCouleur::modifierCommentaire()
{
    this->modifierConf(334,ui->lineEdit_commentaire->text());
}

void confCouleur::modifierTexte()
{
    this->modifierConf(333,ui->lineEdit_texte->text());
    this->modifierConf(328,ui->lineEdit_texte->text());
    this->modifierConf(329,ui->lineEdit_texte->text());
    this->modifierConf(330,ui->lineEdit_texte->text());
}

confCouleur::~confCouleur()
{
    delete ui;
}

void confCouleur::modifierConf(int jet, QString coul)
{
    QRegExp re("^#(?:[0-9a-fA-F]{3}){1,2}$");
    if (re.exactMatch(coul))
    {
        string jeton;
        stringstream tmp;
        tmp << jet;
        jeton = tmp.str();
        ifstream fichier("../editeur-web/couleur.conf");
        string ligne;
        if(fichier) {
            string buffer = "";
            while(getline(fichier,ligne)) {
                string nom;
                string val;
                string couleur;
                istringstream iss (ligne);
                iss >> nom >> val >> couleur ;
                if (val!=jeton){
                    buffer += ligne + "\n";
                } else {
                    buffer += nom +" " +jeton +" " +coul.toStdString() +"\n";
                }
            }
            fichier.close();
            ofstream fichierOut ("../editeur-web/couleur.conf");
            fichierOut << buffer;
            fichierOut.close();
        }
        else {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier de configuration !");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une couleur hexadecimale valide !");
    }
}
