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

#include "headers/gui/leedit.h"
#include "ui_leedit.h"
#include "headers/gui/affichageligne.h"
#include <headers/gui/editeur.h>
#include <headers/gui/affichageligne.h>
#include <stdio.h>
#include <headers/gui/recherche.h>
#include <QInputDialog>
#include <QDebug>
#include <QScrollBar>
#include <QVariant>
#include <QTextBlock>

LeEdit::LeEdit(QWidget *parent) : QMainWindow(parent), ui(new Ui::LeEdit)
{
    // Initialisation des objets
    lignes = new affichageLigne();
    edit = new editeur();
    webview = new QWebView();
    c = new configurationGenerale(this);
    coul = new confCouleur(this);
    a = new aPropos(this);

    // Initialisation variable environnement
    cheminFichier = "";
    ui->setupUi(this);

    // Option des widgets
    webview->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    ui->onglets->setCurrentIndex(0);
    this->changerLigne();

    // Intégration des widgets dynamique
    ui->ongletApercu->layout()->addWidget(webview);
    ui->ongletCode->layout()->addWidget(lignes);
    ui->ongletCode->layout()->addWidget(edit);

    // Signaux des menus
    QObject::connect(ui->actionDom, SIGNAL(triggered(bool)), this, SLOT(affichageDOM(bool)));
    QObject::connect(ui->actionHierarchie, SIGNAL(triggered(bool)), this, SLOT(affichageHIE(bool)));
    QObject::connect(ui->onglets, SIGNAL(currentChanged(int)), this, SLOT(affichageWID(int)));
    QObject::connect(ui->actionApercu, SIGNAL(triggered()), this, SLOT(affichageAPE()));
    QObject::connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(boiteOuvrir()));
    QObject::connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(modificationHIE()));
    QObject::connect(ui->actionNouveau, SIGNAL(triggered()), this, SLOT(nouveauFichier()));
    QObject::connect(ui->actionEnregistrer_sous, SIGNAL(triggered()), this, SLOT(enregistrerSous()));
    QObject::connect(ui->actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrer()));
    QObject::connect(ui->actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrer()));
    QObject::connect(ui->actionFermer, SIGNAL(triggered()), this, SLOT(close()));
    QObject::connect(ui->actionCopier, SIGNAL(triggered()), edit, SLOT(copy()));
    QObject::connect(ui->actionCouper, SIGNAL(triggered()), edit, SLOT(cut()));
    QObject::connect(ui->actionColler, SIGNAL(triggered()), edit, SLOT(paste()));
    QObject::connect(ui->actionEn_arriere, SIGNAL(triggered()), edit, SLOT(undo()));
    QObject::connect(ui->actionEn_avant, SIGNAL(triggered()), edit, SLOT(redo()));
    QObject::connect(ui->actionRechercher, SIGNAL(triggered()), this, SLOT(afficherRecherche()));
    QObject::connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(afficherAPropos()));
    QObject::connect(ui->actionConfiguration, SIGNAL(triggered()), this, SLOT(afficherConf()));
    QObject::connect(c, SIGNAL(finished(int)), this, SLOT(optionGenerale()));
    QObject::connect(ui->actionCouleur, SIGNAL(triggered()), this, SLOT(afficherConfCouleur()));

    // Signaux sur la zone d'édition
    QObject:connect(edit, SIGNAL(blockCountChanged(int)), this, SLOT(indentationAuto(int)));
    QObject::connect(edit, SIGNAL(blockCountChanged(int)), this, SLOT(changerLigne()));
    QObject::connect(edit, SIGNAL(cursorPositionChanged()), this, SLOT(enleverRecherche()));
    QObject::connect(edit->verticalScrollBar(), SIGNAL(valueChanged(int)), lignes->verticalScrollBar(), SLOT(setValue(int)));
    QObject::connect(edit->verticalScrollBar(), SIGNAL(sliderMoved(int)), lignes->verticalScrollBar(), SLOT(setValue(int)));
    QObject::connect(edit->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), lignes->verticalScrollBar(), SLOT(setRange(int,int)));


    // Signaux sur la zone de hiérarchie
    QObject::connect(ui->hierarchie, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(selection(QModelIndex)));

    // Raccourcis clavier
    ui->actionEnregistrer_sous->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_S);
    ui->actionEnregistrer->setShortcut(Qt::CTRL+Qt::Key_S);
    ui->actionNouveau->setShortcut(Qt::CTRL+Qt::Key_N);
    ui->actionOuvrir->setShortcut(Qt::CTRL+Qt::Key_O);
    ui->actionRechercher->setShortcut(Qt::CTRL+Qt::Key_F);

    c->getOption();
    if(c->getEcran()) {
        setWindowState(this->windowState() ^ Qt::WindowMaximized);
    }
    optionGenerale();
}

LeEdit::~LeEdit()
{
    delete ui;
    delete r;
    delete coul;
}

void LeEdit::optionGenerale() {
    if(c->getDom()) {
        ui->dom->show();
        ui->actionDom->setChecked(true);
    }else{
        ui->dom->hide();
        ui->actionDom->setChecked(false);
    }

    if(c->getHie()) {
        ui->hierarchie->show();
        ui->actionHierarchie->setChecked(true);
    }else{
        ui->hierarchie->hide();
        ui->actionHierarchie->setChecked(false);
    }
}

void LeEdit::indentationAuto(int a) {
    if(c->getIndent() && a > positionPrec) {
        edit ->moveCursor(QTextCursor::QTextCursor::Up);
        edit->moveCursor(QTextCursor::StartOfLine);
        QString lignePrec = edit->textCursor().block().text();
        int nb = 0;
        int i = 0;

        bool queDesTab = true;
        const char * tableau = lignePrec.toStdString().c_str();
        while(i < lignePrec.size() && queDesTab == true) {
            if(tableau[i] == '\t') {
                nb++;
            }else{
                queDesTab = false;
            }
            i++;
        }

        edit->moveCursor(QTextCursor::Down);
        for(int j=0; j<nb; j++){
            edit->textCursor().insertText("\t");
        }
    }
    positionPrec = a;

}

// Méthode de gestion du click sur la hierarchie

void LeEdit::selection(QModelIndex q) {
    ouvrir(cheminFichier + "/" +q.data(Qt::DisplayRole).toString());
}

// Méthode de gestion de l'affichages des lignes

void LeEdit::changerLigne() {
    lignes->genererLigne(edit->miseAJourLignes());
}

// Méthodes de gestion des affichages

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
        webview->setHtml(edit->toPlainText());
    }
}

void LeEdit::modificationHIE() {
    if(cheminFichier.length() != 0) {
        QFileSystemModel *dirModele= new QFileSystemModel;
        dirModele->setRootPath(cheminFichier);

        ui->hierarchie->setModel(dirModele);
        QModelIndex idx = dirModele->index(cheminFichier);
        ui->hierarchie->setRootIndex(idx);
        ui->hierarchie->expandAll();
        ui->hierarchie->setColumnWidth(0,ui->hierarchie->width());
    }
}

// Méthode nouveau, ouvrir, enregistrer, enregistrer sous (gestion de fichier)

char* LeEdit::contenuFichier() {
    QByteArray contenu = edit->toPlainText().toUtf8();
    return strdup(contenu.constData());
}

void LeEdit::boiteOuvrir() {
    fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", cheminFichier, "Fichier web (*.css *.js *.html *.php),*.css;*.js;*.html;*.php");
    QDir chemin = QFileInfo(fichier).absoluteDir();
    cheminFichier = chemin.absolutePath();
    ouvrir(fichier);
    //QMessageBox::information(this, "Fichier", buff);
    //edit->setText(buf.affiche(););
}

void LeEdit::ouvrir(QString f) {
    QMessageBox::information(this, "Fichier", "Vous avez sélectionné :"+f.toLatin1()+"\n");
    //buff = new Buffer(f.toLatin1().data());
}

void LeEdit::nouveauFichier() {
    cheminFichier = "";
   // buff = new Buffer();
}


void LeEdit::enregistrer() {
    this->sauvegarde(fichier);
}

void LeEdit::enregistrerSous() {
    QString fileName= QFileDialog::getSaveFileName(this, tr("Enregistrer votre fichier"), cheminFichier, "Fichier web (*.css *.js *.html *.php),*.css;*.js;*.html;*.php");
    this->sauvegarde(fileName);
}

void LeEdit::sauvegarde(QString monfichier) {
    if (!monfichier.isEmpty())
    {
        QFile file(monfichier);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            file.write(this->contenuFichier());
            QDataStream out(&file);
        }
    }
}

// Méthode d'affichage de la configuration couleur
void LeEdit::afficherConfCouleur(){
    coul->exec() ;
}

// Méthode d'affichage d'à propos

void LeEdit::afficherAPropos(){
    a->exec();
}

// Méthode d'affichage de la configuration de l'application

void LeEdit::afficherConf(){
    c->exec();
}

// Méthode de recherche et remplacement


void LeEdit::afficherRecherche(){
    r = new recherche(this);
    r->exec();
}

void LeEdit::rechercher(QString rech){
    QTextDocument *document = edit->document();
    QTextCharFormat plainFormat(edit->textCursor().charFormat());
    QTextCharFormat colorFormat = plainFormat;
    QColor lineColor = QColor(Qt::green).lighter(160);
    colorFormat.setBackground(lineColor);
    QTextCursor newCursor(document);
    while (!newCursor.isNull() && !newCursor.atEnd()) { // Tant qu'il existe des éléments
        newCursor = document->find(rech, newCursor, QTextDocument::FindCaseSensitively);
        // On stocke la position de l'élement
        if (!newCursor.isNull()) {
            for(int i=0; i<rech.length(); i++){ // Coloration de la recherche
                newCursor.movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor);
                newCursor.movePosition(QTextCursor::PreviousCharacter,QTextCursor::KeepAnchor);
                newCursor.mergeCharFormat(colorFormat); // On colore l'élement dans le QtextEdit
            }
        }
    }
    rechercheActive = true;
}

void LeEdit::remplacer(QString rech, QString remp){
    edit->textCursor();
    QString doctext = edit->document()->toPlainText();
    doctext.replace(rech, remp);
    edit->document()->setPlainText(doctext);
    this->rechercher(remp);
}

void LeEdit::enleverRecherche(){
    if (rechercheActive){
        //edit->document()->setPlainText(buff->affiche());
        rechercheActive = false ;
    }
}
