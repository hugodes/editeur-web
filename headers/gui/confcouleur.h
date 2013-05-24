/*!
 * \file confcouleur.h
 * \brief Fichier d'en-tête de la classe graphique de configuration des couleurs
 * \author Bryan Libourel & Nicolas Emeri
 */

#ifndef CONFCOULEUR_H
#define CONFCOULEUR_H

#include <QDialog>
#include <string>

using namespace std;

/*! \namespace Ui
 *  espace de nommage regroupant les outils composants de l'interface graphique
 */
namespace Ui {
    class confCouleur;
}

/**
 * \class confCouleur
 * \brief Classe gérant la configuration des couleurs
 */
class confCouleur : public QDialog
{
    Q_OBJECT
    
public:

    /*!
     * \brief Constructeur de la fenêtre graphique
     * \param parent Widget parent
     */
    explicit confCouleur(QWidget *parent = 0);

    /*!
     * \brief Destructeur de la fenêtre graphique
     */
    ~confCouleur();
public slots:

    /*!
     * \brief Modifier une couleur
     * \param jet jeton de la couleur a modifier
     * \param coul nouvelle couleur
     */
    void modifierConf(int jet, QString coul);

    /*!
     * \brief Modifier la couleur des balises
     */
    void modifierBalise();

    /*!
     * \brief Modifier la couleur des doctype
     */
    void modifierDoctype();

    /*!
     * \brief Modifier la couleur des balises php
     */
    void modifierPhp();

    /*!
     * \brief Modifier la couleur des mots cles php
     */
    void modifierMotscles();

    /*!
     * \brief Modifier la couleur des fonctions
     */
    void modifierFonction();

    /*!
     * \brief Modifier la couleur des caracteres
     */
    void modifierString();

    /*!
     * \brief Modifier la couleur des atributs html
     */
    void modifierAttribut();
    /*!
     * \brief modifierCommentaire Modifier la couleur des commentaires
     */
    void modifierCommentaire();
    /*!
     * \brief modifierTexte Modifier la couleur du Texte
     */
    void modifierTexte();
    /*!
     * \brief afficher les couleurs dans les line edit
     */
    void afficheCouleurs();
    
private:
    /*!
     * \brief ui Interface graphique QT
     */
    Ui::confCouleur *ui;
};

#endif // CONFCOULEUR_H
