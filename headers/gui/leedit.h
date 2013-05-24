#ifndef LEEDIT_H
#define LEEDIT_H

/*!
 * \file leedit.h
 * \brief Fichier gérant l'affichage de la fenêtre principale
 * \author Bryan Libourel & Nicolas Emeri
 */

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QDirmodel>
#include <headers/gui/editeur.h>
#include <headers/gui/affichageligne.h>
#include <QWebView>
#include <QModelIndex>
#include <headers/gui/apropos.h>
#include <headers/gui/configurationgenerale.h>
#include <headers/gui/confcouleur.h>

class recherche;
#include <headers/gui/recherche.h>

/*! \namespace Ui
 *
 *  espace de nommage regroupant les outils composants de l'interface graphique
 */
namespace Ui {
/**
 * \class LeEdit
 * \brief La classe permet l'intéraction entre l'utilisateur et le programme
 */
class LeEdit;
}

class LeEdit : public QMainWindow
{
    Q_OBJECT
    
public:
    /*!
     * \brief LeEdit Constructeur de la fenêtre graphique
     * \param parent Widget parent
     */
    explicit LeEdit(QWidget *parent = 0);
    ~LeEdit();

public slots:
    /*!
    * \brief affichageDOM Affiche ou cache la fenêtre DOM
    * \param visible Booléen de visibilité
    */
   void affichageDOM(bool visible);
   /*!
    * \brief affichageHIE Affiche ou cache la fenêtre hiérarchie
    * \param visible Booléen de visibilité
    */
   void affichageHIE(bool visible);
   /*!
    * \brief affichageAPE Met en avant la vue aperçu
    */
   void affichageAPE();
   /*!
    * \brief affichageWID Exécute l'action donné pour l'élément i
    * \param i numéro du widget
    */
   void affichageWID(int i);
   /*!
    * \brief boiteOuvrir Ouvre la boite de dialogue
    */
   void boiteOuvrir();
   /*!
    * \brief modificationHIE Modifie l'affichage de la vue hiérarchie
    */
   void modificationHIE();
   /*!
    * \brief nouveauFichier Instancie un Buffer pour un nouveau fichier
    */
   void nouveauFichier();
   /*!
    *\brief enregistrerSous Ouvre une boite de dialogue pour choisir ou enregistrer
    */
   void enregistrerSous();
   /*!
    *\brief contenuFichier Contenu écrit dans la zone d'édition
    * \return Retourne un tableau de caractères du contenu de la zone d'édition
    */
   char* contenuFichier();
   /*!
    * \brief enregistrer Enregistrer un fichier au même emplacement
    */
   void enregistrer();
   /*!
    * \brief sauvegarde Enregistre le fichier courant sur le disque en fonction de monfichier
    * \param monfichier chemin de sauvegarde
    */
   void sauvegarde(QString monfichier);
   /*!
    * \brief changerLigne Demande a l'affichageLigne de mettre à jour son nombre de ligne
    */
   void changerLigne();
   /*!
    * \brief afficherRecherche Affiche la fenêtre de recherche
    */
   void afficherRecherche();
   /*!
    * \brief rechercher Rechercher un mot dans le texte
    * \param rech Chaine que l'on recherche
    */
   void rechercher(QString rech);
   /*!
    * \brief remplacer Remplace rech par temp
    * \param rech Mot à rechercher
    * \param remp Mot à mettre à la place de rech
    */
   void remplacer(QString rech, QString remp);
   /*!
    * \brief enleverRecherche Enlève la colaration des mots précédemment recherchés
    */
   void enleverRecherche();
   /*!
    * \brief selection Ouvre le fichier de l'élément sous le focus
    * \param q Sélection dans la hiérarchie des fichiers
    */
   void selection(QModelIndex q);
   /*!
    * \brief ouvrir Ouvre le fichier
    * \param f chemin du fichier
    */
   void ouvrir(QString f);
   /*!
    * \brief afficherAPropos Affiche la fenêtre à propos
    */
   void afficherAPropos();
   /*!
    * \brief afficherConf Affiche la fenêtre de configuration générale
    */
   void afficherConf();
   /*!
    * \brief afficherConfCouleur Affiche la fenêtre de configuration des couleurs
    */
   void afficherConfCouleur();
   /*!
    * \brief indentationAuto Méthode de gestionde l'indentation utile
    * \param a numéro de la ligne à indenté
    */
   void indentationAuto(int a);
   /*!
    * \brief optionGenerale Met en place les options générales
    */
   void optionGenerale();

private:
    /*!
     * \brief ui Interface graphique QT
     */
    Ui::LeEdit *ui;
   /*!
     * \brief cheminFichier Chemin du fichier
     */
    QString cheminFichier;
    /*!
     * \brief chemin Chemin du dossier
     */
    QDir chemin;
    /*!
     * \brief fichier fichier à ouvrir
     */
    QString fichier;
    /*!
     * \brief edit Objet editeur
     */
    editeur * edit;
    /*!
     * \brief lignes Objet affichageLigne
     */
    affichageLigne *lignes;
    /*!
     * \brief webview Affichage de l'aperçu
     */
    QWebView *webview;
    /*!
     * \brief r Pointeur sur la fenêtre rechercher
     */
    recherche *r;
    /*!
     * \brief a Pointeur sur la fenêtre A propos
     */
    aPropos *a;
    /*!
     * \brief c Pointeur sur la fenêtre configuration générale
     */
    configurationGenerale *c;
    /*!
     * \brief coul Pointeur sur la fenêtre configuration des couleurs
     */
    confCouleur *coul;
    /*!
     * \brief rechercheActive Booléen pour déterminer si il y a eu une recherche récente
     */
    bool rechercheActive;
    /*!
     * \brief positionPrec Dernière ligne parcourue
     */
    int positionPrec;
};

#endif // LEEDIT_H
