#ifndef LEEDIT_H
#define LEEDIT_H

/*!
 * \file leedit.h
 * \brief Fichier d'en-tête de ma classe graphique
 * \author Bryan Libourel
 * \version 0.2
 *
 */

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QDirmodel>
#include <editeur.h>
#include <affichageligne.h>
#include <QWebView>
#include <buffer.h>
#include <QModelIndex>
#include <apropos.h>
#include <configurationgenerale.h>
#include <confcouleur.h>

class recherche;
#include <recherche.h>

/*! \namespace Ui
 *
 *  espace de nommage regroupant les outils composants de l'interface graphique
 */
namespace Ui {
/**
 * \class LeEdit
 * \brief Classe gérant l'interface graphique
 *
 *  La classe permet l'intéraction entre l'utilisateur et le programme
 */
class LeEdit;
}

class LeEdit : public QMainWindow
{
    Q_OBJECT
    
public:
    /*!
     * \brief LeEdit
     *  Constructeur de la fenêtre graphique
     * \param parent : Widget
     */
    explicit LeEdit(QWidget *parent = 0);
    ~LeEdit();

public slots:
    /*!
    * \brief affichageDOM
    *   Affiche ou cache la fenêtre DOM
    * \param visible : Booléen de visibilité
    */
   void affichageDOM(bool visible);
   /*!
    * \brief affichageHIE
    * Affiche ou cache la fenêtre hiérarchie
    * \param visible: Booléen de visibilité
    */
   void affichageHIE(bool visible);
   /*!
    * \brief affichageAPE
    * Met en avant la vue aperçu
    */
   void affichageAPE();
   /*!
    * \brief affichageWID
    * Exécute l'action donné pour l'élément i
    * \param i : numéro du widget
    */
   void affichageWID(int i);
   /*!
    * \brief boiteOuvrir
    * Ouvre la boite de dialogue
    */
   void boiteOuvrir();
   /*!
    * \brief modificationHIE
    * Modifie l'affichage de la vue hiérarchie
    */
   void modificationHIE();
   /*!
    * \brief nouveauFichier
    * Instancie un Buffer pour un nouveau fichier
    */
   void nouveauFichier();
   void enregistrerSous();
   char* contenuFichier();
   void enregistrer();
   void sauvegarde(QString monfichier);
   void changerLigne();
   void afficherRecherche();
   void rechercher(QString rech);
   void remplacer(QString rech, QString remp);
   void enleverRecherche();
   void selection(QModelIndex q);
   void ouvrir(QString f);
   void afficherAPropos();
   void afficherConf();
   void afficherConfCouleur();
   void indentationAuto();
   void optionGenerale();

private:
    Ui::LeEdit *ui; /*!< La classe elle même */
    QString cheminFichier; /*!< Chemin du fichier */
    Buffer * buff;
    QDir chemin;
    QString fichier;
    editeur * edit;
    affichageLigne *lignes;
    QWebView *webview;
    recherche *r;
    aPropos *a;
    configurationGenerale *c;
    confCouleur *coul;
    bool rechercheActive;
};

#endif // LEEDIT_H
