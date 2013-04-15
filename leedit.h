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
#include <unistd.h>
#include <iostream>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QDirmodel>
#include <buffer.h>

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

private:
    Ui::LeEdit *ui; /*!< La classe elle même */
    QString cheminFichier; /*!< Chemin du fichier */
    Buffer * buff;
};

#endif // LEEDIT_H
