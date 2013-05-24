#include "headers/gui/recherche.h"
#include "ui_recherche.h"
#include <QDebug>

recherche::recherche(LeEdit *parent) : QDialog(parent), ui(new Ui::recherche)
{
    ui->setupUi(this);
    this->parent = parent;

    QObject::connect(ui->bouton_rechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
    QObject::connect(ui->bouton_remplacer,SIGNAL(clicked()),this,SLOT(remplacer()));
    QObject::connect(ui->bouton_annuler, SIGNAL(clicked()), this, SLOT(close()));
}

recherche::~recherche()
{
    delete ui;
    delete parent;
}

void recherche::rechercher()
{
    if(ui->texte_rechercher->text()!="")
    {
        this->close();
        this->parent->rechercher(ui->texte_rechercher->text());
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "La chaine de caractère est vide");
    }
}

void recherche::remplacer()
{
    if(ui->texte_rechercher->text()!="")
    {
        this->close();
        this->parent->remplacer(ui->texte_rechercher->text(), ui->texte_remplacer->text());
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "La chaine de caractère est vide");
    }
}
